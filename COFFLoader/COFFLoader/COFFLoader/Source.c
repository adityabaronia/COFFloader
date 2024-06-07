#include <Windows.h>
#include <stdio.h>

typedef struct{
	UINT16 machine; //uint16_t
	UINT8 numberOfSection; //uint16_t
	UINT32 timeStamp; //uint32_t
	UINT32 filePtrSmblTbl; // file pointer to symbol table //uint32_t
	UINT16 noOfSymbols; //uint16_t
	UINT16 sizeOfOptionalHeader;  //uint16_t
	UINT16 characteristics; //uint16_t
}fileHeader;


typedef struct {
	char Name[8];
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
	//opening file hadle
	
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
	
	fheader = (fileHeader*)objFileInMem;
	printFileHeader(fheader);
	
	
	for (int i = 0; i < fheader->numberOfSection; i++) {
		sectionHeader* section_n = (size_t)objFileInMem
			+ (size_t)sizeof(fileHeader) +  i * (size_t)sizeof(sectionHeader);;
		printf("SECTION HEADER: %x\n", i+1);
		printSectionHeader(section_n);
	}
	return 0;
}
