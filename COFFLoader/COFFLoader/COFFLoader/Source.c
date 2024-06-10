#include <Windows.h>
#include <stdio.h>

#pragma pack(push, 1) // Set the alignment to 1 byte

// these are #defines for type of relocations
#define IMAGE_REL_AMD64_ABSOLUTE  0x0000 // The relocation is ignored.
#define IMAGE_REL_AMD64_ADDR64    0x0001 // The 64-bit VA of the relocation target.
#define IMAGE_REL_AMD64_ADDR32    0x0002 // The 32-bit VA of the relocation target.
#define IMAGE_REL_AMD64_ADDR32NB  0x0003 // The 32-bit address without an image base (RVA).
#define IMAGE_REL_AMD64_REL32     0x0004 // The 32-bit relative address from the byte following the relocation.
#define IMAGE_REL_AMD64_REL32_1   0x0005 // The 32-bit address relative to byte distance 1 from the relocation.
#define IMAGE_REL_AMD64_REL32_2   0x0006 // The 32-bit address relative to byte distance 2 from the relocation.
#define IMAGE_REL_AMD64_REL32_3   0x0007 // The 32-bit address relative to byte distance 3 from the relocation.
#define IMAGE_REL_AMD64_REL32_4   0x0008 // The 32-bit address relative to byte distance 4 from the relocation.
#define IMAGE_REL_AMD64_REL32_5   0x0009 // The 32-bit address relative to byte distance 5 from the relocation.
#define IMAGE_REL_AMD64_SECTION   0x000A // The 16-bit section index of the section that contains the target. This is used to support debugging information.
#define IMAGE_REL_AMD64_SECREL    0x000B // The 32-bit offset of the target from the beginning of its section. This is used to support debugging information and static thread local storage.
#define IMAGE_REL_AMD64_SECREL7   0x000C // A 7-bit unsigned offset from the base of the section that contains the target.
#define IMAGE_REL_AMD64_TOKEN     0x000D // CLR tokens.
#define IMAGE_REL_AMD64_SREL32    0x000E // A 32-bit signed span-dependent value emitted into the object.
#define IMAGE_REL_AMD64_PAIR      0x000F // A pair that must immediately follow every span-dependent value.
#define IMAGE_REL_AMD64_SSPAN32   0x0010 // A 32-bit signed span-dependent value emitted into the object.


// file header structure
typedef struct {
	UINT16 machine; //uint16_t
	UINT16 numberOfSection; //uint16_t
	UINT32 timeStamp; //uint32_t
	UINT32 filePtrSmblTbl; // file pointer to symbol table //uint32_t
	UINT32 noOfSymbols; //uint16_t
	UINT16 sizeOfOptionalHeader;  //uint16_t
	UINT16 characteristics; //uint16_t
}fileHeader;

// Section header structure
typedef struct {
	char	Name[8];
	UINT32 VirtualSize;
	UINT32 VirtualAddress;
	UINT32 SizeOfRawData;
	UINT32 PointerToRawData;
	UINT32 PointerToRelocations;
	UINT32 PointerToLinenumbers;
	UINT16 NumberOfRelocations;
	UINT16 NumberOfLinenumbers;
	UINT32 Characteristics;
}sectionHeader;


// Symbol table structure
typedef struct {
	union
	{
		char	Name[8];
		UINT32	value[2]; // index 0 is zeros and index 1 is offset
	}first;
	UINT32 Value;
	UINT16 SectionNumber;
	UINT16 Type;
	BYTE StorageClass;
	BYTE NumberOfAuxSymbols;
}symbolTable;


typedef struct {
	UINT32 VirtualAddress;
	UINT32 SymbolTableIndex;
	UINT16 Type;

}relocationTable;



void printFileHeader(fileHeader* fheader) {
	printf("FILEHEADER:\n");
	printf("machine: 0x%x\n", fheader->machine);
	printf("Number of section: 0x%x\n", fheader->numberOfSection);
	printf("Time and date stamp: 0x%x\n", fheader->timeStamp);
	printf("filepointer to symbol table: 0x%x\n", fheader->filePtrSmblTbl);
	printf("number of symbols: 0x%x\n", fheader->noOfSymbols);
	printf("size of optionl header: 0x%x\n", fheader->sizeOfOptionalHeader);
	printf("charactersctics: 0x%x\n", fheader->characteristics);
	printf("\n");
}

void printSectionHeader(sectionHeader* section_n) {
	printf("Name of section header: %s\n", (section_n->Name));
	printf("Virtual size of section header is 0x%x\n", section_n->VirtualSize);
	printf("virtual address is 0x%x\n", section_n->VirtualAddress);
	printf("size of raw raw data is 0x%x\n", section_n->SizeOfRawData);
	printf("pointer to raw data is 0x%x\n", section_n->PointerToRawData);
	printf("Pointer to relocations is 0x%x\n", section_n->PointerToRelocations);
	printf("Pointer to linenumbers is 0x%x\n", section_n->PointerToLinenumbers);
	printf("Number of relocations is 0x%x\n", section_n->NumberOfRelocations);
	printf("Number of linenumbers is 0x%x\n", section_n->NumberOfLinenumbers);
	printf("Characteristics is 0x%x\n", section_n->Characteristics);
	printf("\n");
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("Usage: COFFloader.exe <path\\of\\obj\\file.obj>\n");
		exit(1);
	}
	printf("File to parse: %s\n\n", argv[1]);

	HANDLE hFile = NULL;
	size_t objFileSize = 0;
	LPVOID objFileInMem = NULL;
	LPDWORD bytesRead = NULL;
	fileHeader* fheader;
	sectionHeader* section_n;
	symbolTable* sTable;
	UINT64 symStrTableValueOffset = 0;
	UINT16 totalRelocation = 0;
	relocationTable* relocTable;
	char** sectionMapping = NULL;
	UINT64 symOffset;

	hFile = CreateFileA(argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("error in opening object file: %d\n", GetLastError());
		exit(1);
	}
	objFileSize = GetFileSize(hFile, NULL);
	if (objFileSize == INVALID_FILE_SIZE) {
		printf("Could not get file size: %d\n", GetLastError());
		exit(1);
	}
	printf("Object file size is %lld\n", objFileSize);

	//Allocating virtual memory
	objFileInMem = VirtualAlloc(NULL,
		objFileSize,
		MEM_COMMIT | MEM_RESERVE,
		PAGE_READWRITE);

	if (objFileInMem == NULL) {
		printf("Error in allocating virtual memory: %d\n", GetLastError());
		exit(1);
	}

	if (FALSE == ReadFile(hFile, objFileInMem, objFileSize, &bytesRead, NULL)) {
		printf("Error in reading file: %d\n", GetLastError());
	}
	if (objFileSize != bytesRead) {
		printf("Bytes read is %ulld .Error in reading complete file\n", bytesRead);
		exit(1);
	}


	printf("----------------------------FILE HEADER--------------------------\n");

	fheader = (fileHeader*)objFileInMem;
	printFileHeader(fheader);

	sectionMapping = calloc(fheader->numberOfSection, 8); // since we can't make a dynamic array so we asked for
	// virtual memory of numberOfSection*(sizeOf(Address));
	if (sectionMapping == NULL) {
		printf("Failed to allocate Section Mapping pointer to pointers\n");
		exit(1);
	}

	printf("--------------------------SECTION HEADERS-------------------------\n");
	for (int i = 0; i < fheader->numberOfSection; i++) {
		section_n = (size_t)objFileInMem
			+ (size_t)sizeof(fileHeader) + i * (size_t)sizeof(sectionHeader);;
		printf("SECTION HEADER: %x\n", i + 1);
		sectionMapping[i] = VirtualAlloc(NULL, section_n->SizeOfRawData, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (sectionMapping[i] == NULL) {
			printf("Can't find allocation of section mapping. :(\n");
			exit(1);
		}
		if (section_n->SizeOfRawData != NULL) {
			memcpy(sectionMapping[i], (size_t)objFileInMem + section_n->PointerToRawData, section_n->SizeOfRawData);
		}
		else { memcpy(sectionMapping[i], 0, section_n->SizeOfRawData); }
		totalRelocation += section_n->NumberOfRelocations;
		printSectionHeader(section_n);
	}

	

	printf("total number of reloationa are : %d\n", totalRelocation);

	printf("-----------------------SYMBOL TABLE CONTENT-----------------------\n");

	for (int i = 0; i < fheader->noOfSymbols; i++) {
		sTable = (UINT64)objFileInMem + fheader->filePtrSmblTbl + i * sizeof(symbolTable);

		if (/*sTable->Value == 0 && sTable->first.value[0] && sTable->first.value[0]*/sTable->first.Name[0] == '.') {
			printf("\n%x. Name: %s\n", i, sTable->first.Name);
			i++;
			sTable = (UINT64)objFileInMem + fheader->filePtrSmblTbl + i * sizeof(symbolTable);
			printf("size of raw data of section: %x\n", sTable->first.value[0]);
			continue;
		}


		if (!(sTable->first.value[0]))
		{
			// Symbol string is more that 8 bytes; we are finding string in symbol string table. relocation 
			// just after end of symboltable. We are adding offset of string location.
			symStrTableValueOffset = ((UINT64)objFileInMem +
				fheader->filePtrSmblTbl +
				sizeof(symbolTable) * fheader->noOfSymbols +
				sTable->first.value[1]);

			printf("\n%x. Name: %s\n", i, symStrTableValueOffset);
			printf("string table offset: %d\n", sTable->first.value[1]);
		}
		else { printf("\n%x. Name: %s\n", i, sTable->first.Name); }

		printf("value associated with symbol: 0x%x\n", sTable->Value);
		printf("Section number 0x%x\n", sTable->SectionNumber);
		printf("type is 0x%x\n", sTable->Type);
		if (sTable->Type == 0x20) {
			printf("This symbol is of function\n");
		}
		else if (sTable->Type == 0x00) {
			printf("This symbol is not a function \n");
		}

		else { printf("This symbol is something else\n"); }

		printf("StorageClass is 0x%x\n", sTable->StorageClass);
		if (sTable->StorageClass == 3) {
			printf("Symbol is static and The offset of the symbol is within the section. If the Value field is zero, then the symbol represents a section name.\n ");
		}

		else if (sTable->StorageClass == 2) {
			printf("A value that Microsoft tools use for external symbols\n");
		}

		else if (sTable->StorageClass == 1) {
			printf("The automatic (stack) variable. The Value field specifies the stack frame offset\n");
		}
		printf("Number of Aux symbols are 0x%x\n", sTable->NumberOfAuxSymbols);



	}


	printf("\n-----------------------------RELOCATION DATA----------------------------------\n");


	//// looking into relocation data
	section_n = 0;
	sTable = (UINT64)objFileInMem + fheader->filePtrSmblTbl;
	for (UINT32 i = 0; i < fheader->numberOfSection; i++) {
		section_n = (size_t)objFileInMem
			+ (size_t)sizeof(fileHeader)
			+ i * (size_t)sizeof(sectionHeader);;
		printf("---------------------------------------------------------------------\n");
		printf("\n%d SECTION HEADER: %s\n", i + 1, section_n->Name);
		printf("Number of relocation in section: 0x%x\n ", section_n->NumberOfRelocations);
		
		for (UINT32 j = 0; j < section_n->NumberOfRelocations; j++) {
			relocTable = (size_t)objFileInMem + section_n->PointerToRelocations + j * sizeof(relocationTable);
			printf("\nRelocation number: % d\n", j + 1);
			printf("Symbol table index, address that is to be used for reloc: 0x%x\n", relocTable->SymbolTableIndex);

			if (!sTable[relocTable->SymbolTableIndex].first.value[0]) {

				printf("offset: %d\n", sTable[relocTable->SymbolTableIndex].first.value[1]);
				symStrTableValueOffset = ((UINT64)objFileInMem +
					fheader->filePtrSmblTbl +
					sizeof(symbolTable) * fheader->noOfSymbols +
					sTable[relocTable->SymbolTableIndex].first.value[1]);

				printf("Symbol name: %s\n", symStrTableValueOffset);
			}
			else { printf("Symbol name: %s\n", sTable[relocTable->SymbolTableIndex].first.Name); }

			printf("Symbol table index, address that is to be used for reloc: 0x%x\n", relocTable->SymbolTableIndex); // SymbolTableIndex is 0 based
			printf("Address\offset of item to which reloc is appiled: 0x%x\n", relocTable->VirtualAddress);
			printf("Type of reloc 0x%x\n", relocTable->Type);



			/* Type == 1 relocation is the 64-bit VA of the relocation target IMAGE_REL_AMD64_ADDR64*/
			if (relocTable->Type == 1) {
				printf("The 64-bit VA of the relocation target.\n");
				symOffset = sectionMapping[i] /*current section in which we are parsing for symbol used*/ +
				relocTable->VirtualAddress;/*This virtual address is offset from the section where symbol is used*/
				printf("symbol address from the newly allocated section: %x", symOffset);
			}
			else if (relocTable->Type == 2) { printf("The 32-bit VA of the relocation target.\n"); }
			else if (relocTable->Type == 3) { 
				printf("The 32-bit address without an image base (RVA).\n"); 
				symOffset = sectionMapping[i] /*current section in which we are parsing for symbol used*/ +
					relocTable->VirtualAddress;/*This virtual address is offset from the section where symbol is used*/
				printf("symbol address from the newly allocated section: %x", symOffset);
			}
			else if (relocTable->Type == 4) { 
				printf("The 32-bit relative address from the byte following the relocation. needed to make global variables to work correctly\n");
				symOffset = sectionMapping[i] /*current section in which we are parsing for symbol used*/ +
					relocTable->VirtualAddress;/*This virtual address is offset from the section where symbol is used*/
				printf("symbol address from the newly allocated section: %x", symOffset);
			}
			else if (relocTable->Type == 5) { printf("The 32-bit address relative to byte distance 1 from the relocation.\n"); }
			else if (relocTable->Type == 6) { printf("The 32-bit address relative to byte distance 2 from the relocation.\n"); }
			else if (relocTable->Type == 7) { printf("The 32-bit address relative to byte distance 3 from the relocation.\n"); }
			else if (relocTable->Type == 8) { printf("The 32-bit address relative to byte distance 4 from the relocation.\n"); }
			else if (relocTable->Type == 9) { printf("The 32-bit address relative to byte distance 5 from the relocation.\n"); }
			else if (relocTable->Type == 10) { printf("The 16-bit section index of the section that contains the target. This is used to support debugging information.\n"); }
			else if (relocTable->Type == 11) { printf("The 32-bit offset of the target from the beginning of its section. This is used to support debugging information and static thread local storage.\n"); }
			else if (relocTable->Type == 12) { printf("A 7-bit unsigned offset from the base of the section that contains the target.\n"); }
			else if (relocTable->Type == 13) { printf("CLR tokens.\n"); }
			else if (relocTable->Type == 14) { printf("A 32-bit signed span-dependent value emitted into the object.\n"); }
			else if (relocTable->Type == 15) { printf("A pair that must immediately follow every span-dependent value.\n"); }
			else if (relocTable->Type == 16) { printf("A 32-bit signed span-dependent value that is applied at link time.\n"); }
			/* This is Type == 3 relocation code */
			/* This is Type == 4 relocation code, needed to make global variables to work correctly */

			/* This is Type == IMAGE_REL_I386_DIR32 relocation code */


		}

	}

	return 0;
}
