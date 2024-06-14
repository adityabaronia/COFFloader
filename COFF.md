

# C file
```C
#include <Windows.h>


void example(){
	MessageBox(NULL, "lodu", "ludo",0);
	LoadLibraryA("kernel32.exe");

}

int GO(){
	
	MessageBox(NULL, "ludo", "lodu",0);
	example();
    CreateFileA("C:\\Users\\Public\\merabaapcoff.txt",
		GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
    return 0;
}
```

# Compilation
```bash
cl.exe \c CreateFile.c
```

# COFF Header
```asm
C:\Users\smoke.REDTEAMER\Desktop\COFFLoader>dumpbin /HEADERS CreateFile.obj
Microsoft (R) COFF/PE Dumper Version 14.38.33133.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file CreateFile.obj

File Type: COFF OBJECT

FILE HEADER VALUES
            8664 machine (x64)
               7 number of sections
        666ADB8E time date stamp Thu Jun 13 17:14:14 2024
             412 file pointer to symbol table
              22 number of symbols
               0 size of optional header
               0 characteristics

SECTION HEADER #1
.drectve name
       0 physical address
       0 virtual address
      5D size of raw data
     12C file pointer to raw data (0000012C to 00000188)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
  100A00 flags
         Info
         Remove
         1 byte align

SECTION HEADER #2
.debug$S name
       0 physical address
       0 virtual address
      94 size of raw data
     189 file pointer to raw data (00000189 to 0000021C)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
42100040 flags
         Initialized Data
         Discardable
         1 byte align
         Read Only

SECTION HEADER #3
.text$mn name
       0 physical address
       0 virtual address
      9A size of raw data
     21D file pointer to raw data (0000021D to 000002B6)
     2B7 file pointer to relocation table
       0 file pointer to line numbers
       B number of relocations
       0 number of line numbers
60500020 flags
         Code
         16 byte align
         Execute Read

SECTION HEADER #4
  .xdata name
       0 physical address
       0 virtual address
      10 size of raw data
     325 file pointer to raw data (00000325 to 00000334)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
40300040 flags
         Initialized Data
         4 byte align
         Read Only

SECTION HEADER #5
  .pdata name
       0 physical address
       0 virtual address
      18 size of raw data
     335 file pointer to raw data (00000335 to 0000034C)
     34D file pointer to relocation table
       0 file pointer to line numbers
       6 number of relocations
       0 number of line numbers
40300040 flags
         Initialized Data
         4 byte align
         Read Only

SECTION HEADER #6
   .data name
       0 physical address
       0 virtual address
      51 size of raw data
     389 file pointer to raw data (00000389 to 000003D9)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
C0400040 flags
         Initialized Data
         8 byte align
         Read Write

SECTION HEADER #7
 .chks64 name
       0 physical address
       0 virtual address
      38 size of raw data
     3DA file pointer to raw data (000003DA to 00000411)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
     A00 flags
         Info
         Remove
         (no align specified)

  Summary

          38 .chks64
          51 .data
          94 .debug$S
          5D .drectve
          18 .pdata
          9A .text$mn
          10 .xdata
```


# Disassembly 
```asm
C:\Users\smoke.REDTEAMER\Desktop\COFFLoader>dumpbin /DISASM CreateFile.obj
Microsoft (R) COFF/PE Dumper Version 14.38.33133.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file CreateFile.obj

File Type: COFF OBJECT

example:
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 45 33 C9           xor         r9d,r9d
  0000000000000007: 4C 8D 05 00 00 00  lea         r8,[$SG74579]
                    00
  000000000000000E: 48 8D 15 00 00 00  lea         rdx,[$SG74580]
                    00
  0000000000000015: 33 C9              xor         ecx,ecx
  0000000000000017: FF 15 00 00 00 00  call        qword ptr [__imp_MessageBoxA]
  000000000000001D: 48 8D 0D 00 00 00  lea         rcx,[$SG74581]
                    00
  0000000000000024: FF 15 00 00 00 00  call        qword ptr [__imp_LoadLibraryA]
  000000000000002A: 48 83 C4 28        add         rsp,28h
  000000000000002E: C3                 ret
  000000000000002F: CC                 int         3
  0000000000000030: CC                 int         3
  0000000000000031: CC                 int         3
  0000000000000032: CC                 int         3
  0000000000000033: CC                 int         3
  0000000000000034: CC                 int         3
  0000000000000035: CC                 int         3
  0000000000000036: CC                 int         3
  0000000000000037: CC                 int         3
  0000000000000038: CC                 int         3
  0000000000000039: CC                 int         3
  000000000000003A: CC                 int         3
  000000000000003B: CC                 int         3
  000000000000003C: CC                 int         3
  000000000000003D: CC                 int         3
  000000000000003E: CC                 int         3
  000000000000003F: CC                 int         3
GO:
  0000000000000040: 48 83 EC 48        sub         rsp,48h
  0000000000000044: 45 33 C9           xor         r9d,r9d
  0000000000000047: 4C 8D 05 00 00 00  lea         r8,[$SG74587]
                    00
  000000000000004E: 48 8D 15 00 00 00  lea         rdx,[$SG74588]
                    00
  0000000000000055: 33 C9              xor         ecx,ecx
  0000000000000057: FF 15 00 00 00 00  call        qword ptr [__imp_MessageBoxA]
  000000000000005D: E8 00 00 00 00     call        example
  0000000000000062: 48 C7 44 24 30 00  mov         qword ptr [rsp+30h],0
                    00 00 00
  000000000000006B: C7 44 24 28 80 00  mov         dword ptr [rsp+28h],80h
                    00 00
  0000000000000073: C7 44 24 20 04 00  mov         dword ptr [rsp+20h],4
                    00 00
  000000000000007B: 45 33 C9           xor         r9d,r9d
  000000000000007E: 45 33 C0           xor         r8d,r8d
  0000000000000081: BA 00 00 00 80     mov         edx,80000000h
  0000000000000086: 48 8D 0D 00 00 00  lea         rcx,[$SG74589]
                    00
  000000000000008D: FF 15 00 00 00 00  call        qword ptr [__imp_CreateFileA]
  0000000000000093: 33 C0              xor         eax,eax
  0000000000000095: 48 83 C4 48        add         rsp,48h
  0000000000000099: C3                 ret

  Summary

          38 .chks64
          51 .data
          94 .debug$S
          5D .drectve
          18 .pdata
          9A .text$mn
          10 .xdata

```

# Important structures in COFF

## COFF file header and its structure
| Offset | Size | Field                 | Description                                                                                                                                                                             |
|--------|------|-----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0      | 2    | Machine               | The number that identifies the type of target machine. For more information, see Machine Types.                                                                                          |
| 2      | 2    | NumberOfSections      | The number of sections. This indicates the size of the section table, which immediately follows the headers.                                                                             |
| 4      | 4    | TimeDateStamp         | The low 32 bits of the number of seconds since 00:00 January 1, 1970 (a C run-time time_t value), which indicates when the file was created.                                              |
| 8      | 4    | PointerToSymbolTable  | The file offset of the COFF symbol table, or zero if no COFF symbol table is present. This value should be zero for an image because COFF debugging information is deprecated.            |
| 12     | 4    | NumberOfSymbols       | The number of entries in the symbol table. This data can be used to locate the string table, which immediately follows the symbol table. This value should be zero for an image because COFF debugging information is deprecated. |
| 16     | 2    | SizeOfOptionalHeader  | The size of the optional header, which is required for executable files but not for object files. This value should be zero for an object file. For a description of the header format, see Optional Header (Image Only).      |
| 18     | 2    | Characteristics       | The flags that indicate the attributes of the file. For specific flag values, see Characteristics.                                                                                       |

```c
typedef struct {
	UINT16 machine; //uint16_t
	UINT16 numberOfSection; //uint16_t
	UINT32 timeStamp; //uint32_t
	UINT32 pointerToSymbolTable; // file pointer to symbol table //uint32_t
	UINT32 noOfSymbols; //uint16_t
	UINT16 sizeOfOptionalHeader;  //uint16_t
	UINT16 characteristics; //uint16_t
}fileHeader;
```

## COFF section header and its structure

| Offset | Size | Field                | Description                                                                                                                                                                                                                                                                                                                                                                                  |
|--------|------|----------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0      | 8    | Name                 | An 8-byte, null-padded UTF-8 encoded string. If the string is exactly 8 characters long, there is no terminating null. For longer names, this field contains a slash (/) that is followed by an ASCII representation of a decimal number that is an offset into the string table. Executable images do not use a string table and do not support section names longer than 8 characters. Long names in object files are truncated if they are emitted to an executable file. |
| 8      | 4    | VirtualSize          | The total size of the section when loaded into memory. If this value is greater than SizeOfRawData, the section is zero-padded. This field is valid only for executable images and should be set to zero for object files.                                                                                                                                                                                                          |
| 12     | 4    | VirtualAddress       | For executable images, the address of the first byte of the section relative to the image base when the section is loaded into memory. For object files, this field is the address of the first byte before relocation is applied; for simplicity, compilers should set this to zero. Otherwise, it is an arbitrary value that is subtracted from offsets during relocation.                                                        |
| 16     | 4    | SizeOfRawData        | The size of the section (for object files) or the size of the initialized data on disk (for image files). For executable images, this must be a multiple of FileAlignment from the optional header. If this is less than VirtualSize, the remainder of the section is zero-filled. Because the SizeOfRawData field is rounded but the VirtualSize field is not, it is possible for SizeOfRawData to be greater than VirtualSize as well. When a section contains only uninitialized data, this field should be zero.              |
| 20     | 4    | PointerToRawData     | The file pointer to the first page of the section within the COFF file. For executable images, this must be a multiple of FileAlignment from the optional header. For object files, the value should be aligned on a 4-byte boundary for best performance. When a section contains only uninitialized data, this field should be zero.                                                                                             |
| 24     | 4    | PointerToRelocations | The file pointer to the beginning of relocation entries for the section. This is set to zero for executable images or if there are no relocations.                                                                                                                                                                                                                                            |
| 28     | 4    | PointerToLinenumbers | The file pointer to the beginning of line-number entries for the section. This is set to zero if there are no COFF line numbers. This value should be zero for an image because COFF debugging information is deprecated.                                                                                                                                                                    |
| 32     | 2    | NumberOfRelocations  | The number of relocation entries for the section. This is set to zero for executable images.                                                                                                                                                                                                                                                                                                 |
| 34     | 2    | NumberOfLinenumbers  | The number of line-number entries for the section. This value should be zero for an image because COFF debugging information is deprecated.                                                                                                                                                                                                                                                  |
| 36     | 4    | Characteristics      | The flags that describe the characteristics of the section. For more information, see Section Flags.                                                                                                                                                                                                                                                                                         |
```c
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
```
## COFF symbol table and its structure

| Offset | Size | Field               | Description                                                                                                                                                                                                                                           |
|--------|------|---------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0      | 8    | Name (*)            | The name of the symbol, represented by a union of three structures. An array of 8 bytes is used if the name is not more than 8 bytes long. For more information, see Symbol Name Representation.                                                       |
| 8      | 4    | Value               | The value that is associated with the symbol. The interpretation of this field depends on SectionNumber and StorageClass. A typical meaning is the relocatable address.                                                                                |
| 12     | 2    | SectionNumber       | The signed integer that identifies the section, using a one-based index into the section table. Some values have special meaning, as defined in section 5.4.2, "Section Number Values."                                                                |
| 14     | 2    | Type                | A number that represents type. Microsoft tools set this field to 0x20 (function) or 0x0 (not a function). For more information, see Type Representation.                                                                                                |
| 16     | 1    | StorageClass        | An enumerated value that represents storage class. For more information, see Storage Class.                                                                                                                                                           |
| 17     | 1    | NumberOfAuxSymbols  | The number of auxiliary symbol table entries that follow this record.                                                                                                                                                                                 |


```c
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
```

## COFF relocations table in object files and its structure
| Offset | Size | Field             | Description                                                                                                                                                                                                                       |
|--------|------|-------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0      | 4    | VirtualAddress    | The address of the item to which relocation is applied. This is the offset from the beginning of the section, plus the value of the section's RVA/Offset field. For example, if the first byte of the section has an address of 0x10, the third byte has an address of 0x12. |
| 4      | 4    | SymbolTableIndex  | A zero-based index into the symbol table. This symbol gives the address that is to be used for the relocation. If the specified symbol has section storage class, then the symbol's address is the address with the first section of the same name.                    |
| 8      | 2    | Type              | A value that indicates the kind of relocation that should be performed. Valid relocation types depend on machine type. See Type Indicators.                                                                                        |
```c
typedef struct {
	UINT32 VirtualAddress;
	UINT32 SymbolTableIndex;
	UINT16 Type;
}relocationTable;
```


# Some important definitions
| Name | Description | 
|---------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| linker | A reference to the linker that is provided with Microsoft Visual Studio. |
| object file | A file that is given as input to the linker. The linker produces an image file, which in turn is used as input by the loader. The term "object file" does not necessarily imply any connection to object-oriented programming. |
| section | The basic unit of code or data within a PE or COFF file. For example, all code in an object file can be combined within a single section or (depending on compiler behavior) each function can occupy its own section. With more sections, there is more file overhead, but the linker is able to link in code more selectively. A section is similar to a segment in Intel 8086 architecture. All the raw data in a section must be loaded contiguously. In addition, an image file can contain a number of sections, such as .tls or .reloc , which have special purposes. |
| file pointer | The location of an item within the file itself, before being processed by the linker (in the case of object files) or the loader (in the case of image files). In other words, this is a position within the file as stored on disk. |
| Relative virtual address (RVA) | In an image file, this is the address of an item after it is loaded into memory, with the base address of the image file subtracted from it. The RVA of an item almost always differs from its position within the file on disk (file pointer). In an object file, an RVA is less meaningful because memory locations are not assigned. In this case, an RVA would be an address within a section (described later in this table), to which a relocation is later applied during linking. For simplicity, a compiler should just set the first RVA in each section to zero. |
| Virtual Address (VA) | Same as RVA, except that the base address of the image file is not subtracted. The address is called a VA because Windows creates a distinct VA space for each process, independent of physical memory. For almost all purposes, a VA should be considered just an address. A VA is not as predictable as an RVA because the loader might not load the image at its preferred location. |


# Dive into development of COFF loader
- Read the ``.obj`` file into memory.
- Use the ``fileHeader`` structure to parse the data into memory to know about ``numberOfSection``, ``pointerToSymbolTable``, ``noOfSymbols`` and save them in variables.
	-	```
		fileHeader* fheader;
		fheader = (fileHeader*)objFileInMem; //objFileInMem this is were object file can be read
		```
- Now each of the section needs to be copied in memory ; there should be a pointer to pointers variable that can hold the address of all the newly allocated sections.
	- ```c
		char** sectionMapping;
   		sectionMapping = calloc(fheader->numberOfSection, 8); // because size of address in 64-bit machine is 8
   	```
- Section header falls right after the file header. This means if size of fileheader is 20 bytes then the first section header will be at 21st offset and next section header will be right after 1st section header . If size of each section header is 40 bytes then next section will be at ``size of 1st section header + size of file header``
- Make a for loop for number of section to iterate all the section present in COFF.
	- Find the address of the .text section because this where the function to execute will be present.
 	- Each section will have some relocation in it so make sure to know total numner of relocation in whole COFF.  
	- ```c
   		for (int i = 0; i < fheader->numberOfSection; i++) {
			section_n = (size_t)objFileInMem + (size_t)sizeof(fileHeader) + i * (size_t)sizeof(sectionHeader);;
			sectionMapping[i] = VirtualAlloc(NULL, section_n->SizeOfRawData, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (sectionMapping[i] == NULL) {
				exit(1); // exiting because VirtualAlloc function failed 
			}
			if (section_n->SizeOfRawData != NULL) {
				memcpy(sectionMapping[i], (size_t)objFileInMem + section_n->PointerToRawData, section_n->SizeOfRawData);
			}
			else { memcpy(sectionMapping[i], 0, section_n->SizeOfRawData); }
			totalRelocation += section_n->NumberOfRelocations;
			if (StrStrIA(section_n->Name, ".text") != 0) {
				AddressOfTextSection = sectionMapping[i]; 
			}
			printSectionHeader(section_n);
		}
   	 ```
- Next in line is Symbol table. ``Total numbers of symbols`` and ``pointer to symbol table`` in COFF can be found in ``file header``.
- Symbol table will have information of all the symbols. For example: ``MessageBox(NULL, "lodu", "ludo",0);`` MessageBox function uses 2 strings. These strings are used in .text section but these strings are stored in .data section(can be find after iterating symbol table). Assembly of this MessageBox function will look like:
	- ```asm
   	 		  45 33 C9           xor         r9d,r9d
			  0000000000000007: 4C 8D 05 00 00 00  lea         r8,[$SG74579] // lodu
			                    00
			  000000000000000E: 48 8D 15 00 00 00  lea         rdx,[$SG74580] // ludo
			                    00
			  0000000000000015: 33 C9              xor         ecx,ecx
			  0000000000000017: FF 15 00 00 00 00  call        qword ptr [__imp_MessageBoxA]```
   	- So the symbol table will store the information about ``$SG74579``, ``$SG74580``. This information will be section number where the associated string for each symbol is stored. (Here we are taking only about strings that is why .data section is used. If there is any user defined function in symbol table then its associated data is also present here)
   	- Now it can be said that symbol ``$SG74579``, ``$SG74580`` or ``example`` is defined somewhere and is used somewhere else. **Symbol table will about where the symbol is defined**
   
	- Each symbol is stored in symbol pointer table, this means each symbol table will have a fixed size. Also total number of symbol tables will be equal to total number of symbols.
   	- 1st symbol can be found at the pointer to symbol table but to find the next symbol table:
   		-  ```c
			symbolTable* sTable;
	   	    	sTable = (UINT64)objFileInMem + fheader->pointerToSymbolTable + i * sizeof(symbolTable); // here i is number of symbol pointer whose info is required
   	          ```
	- Symbols in COFF are represented by string. If the symbol name string is of size 8 bytes or less, then symbol name can be found at ``sTable->first.Name`` else there is ``symbol string table`` where the strings are present. This ``symbol string table`` is located right after all symbol tables.
 	- There can be n number of string present in ``symbol string table``. So to find the offset of string in ``symbol string table`` ``sTable->first.value[1]`` is used.
  	- To know if the ``symbol name`` size is less than or equal to 8 bytes, look for ``sTable->first.value[1]``. If this value is ``0`` then the name of symbol is more than 8 bytes and the symbol name can be found at ``sTable->first.value[1]`` offset inside the ``symbol string table``.
  	- ```c
  	  for (int i = 0; i < fheader->noOfSymbols; i++) {
		sTable = (UINT64)objFileInMem + fheader->pointerToSymbolTable + i * sizeof(symbolTable);
  	  	if (!(sTable->first.value[0]))
		{
			// Symbol string is more that 8 bytes; finding string in symbol string table.  
			// just after end of symbol table. adding offset of string location.
			symStrTableValueOffset = ((UINT64)objFileInMem + fheader->pointerToSymbolTable + sizeof(symbolTable) * fheader->noOfSymbols + sTable->first.value[1]);
			functionName = symStrTableValueOffset;
		}
		else { 
			functionName = sTable->first.Name;
		}
  	  ```
	- Other interesting member of ``symbolTable`` structures are ``Value``, ``SectionNumber``, ``Type``, ``StorageClass``. Information about these members can be found at ``https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#coff-symbol-table``
 	- At the end COFF loader is required to execute the entry point function of object file. This entry point function and other locally defined function can be found with this:
  		- ```c
			if (sTable->StorageClass == 2 && sTable->SectionNumber != 0) {
				printf("internal function\n");
				if (strcmp(functionName, argv[2]) == 0) { //argv[2] is the name of function that is required to execute
					offsetOfEntryPoint = sTable->Value;
				}
			}
       		```
        - All the external functions(WINAPIs) can be found with this condition. It is required to note the ``total number of external functions`` used in object file.
        	- ```c
				if (sTable->StorageClass == 2 && sTable->SectionNumber == 0) {
					printf("A value that Microsoft tools use for external symbols\n");
					externalFuncCount += 1;
				}
          		 ```     
- One of the important table in COFF is ``relocation table``. While interating through the relcoation table all the symbols required by COFF loader to execute object file will be resolved and the reference will be applied.
- As discussed while parsing symbol table, symbols are defined somewhere but used somewhere else(mostly test section). **relocation table will tell about where the symbol is used**.
- Reference to all the imported function are required to make a successful COFF loader. To this a seperate GOT(Global offset table) is required, where address of all the imported functions(exteernal function) will be saved. To do this again a pointer to pointers valrialbe is required or say an array that can store addresses ``got = calloc(externalFuncCount, 8);``.
- Each section will have some relocation. To find the relocation in each e\section again in\terate through each section and find number of relocation in it, Then iterate through those relocations.
	- ```c
			for (UINT32 i = 0; i < fheader->numberOfSection; i++) {
   				section_n = (size_t)objFileInMem + (size_t)sizeof(fileHeader) + i * (size_t)sizeof(sectionHeader);
   				for (UINT32 j = 0; j < section_n->NumberOfRelocations; j++) {
   					relocTable = (size_t)objFileInMem + section_n->PointerToRelocations + j * sizeof(relocationTable);
  				}
  			}
  		 ```
   	- This is for parsing through relocation table
- To resolve all the relocation sybol table is also required. Both of the table will provide the data required to resolve the relocations. **relocation table will provide information where the symbols are used** and **symbol table will provide where the symbols are defined**.
- The code for resolving relocation will look like:
	- ```c
		   section_n = 0;
		got = calloc(externalFuncCount, 8);
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
					functionSymbolName = symStrTableValueOffset;
					
					printf("Symbol name: %s\n", symStrTableValueOffset);
				}
				else { 
					printf("Symbol name: %s\n", sTable[relocTable->SymbolTableIndex].first.Name);
					functionSymbolName = sTable[relocTable->SymbolTableIndex].first.Name;
					
				}
		
				printf("Symbol table index, address that is to be used for reloc: 0x%x\n", relocTable->SymbolTableIndex); // SymbolTableIndex is 0 based
				printf("Address\offset of item to which reloc is appiled: 0x%x\n", relocTable->VirtualAddress);
				printf("Type of reloc 0x%x\n", relocTable->Type);
		
		
		
				/*relocTable->Type
				To know more about relocation type go through https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#x64-processors
		  		*/
				if (relocTable->Type == 1) { printf("The 64-bit VA of the relocation target.\n"); }
				else if (relocTable->Type == 2) { printf("The 32-bit VA of the relocation target.\n"); }
		  
				else if (relocTable->Type == 3) { 
					printf("The 32-bit address without an image base (RVA).\n"); 
					symOffsetUsed = sectionMapping[i] /*current section in which we are parsing for symbol used*/ +
						relocTable->VirtualAddress;/*This virtual address is offset from the section where symbol is used*/
					printf("symbol address from the newly allocated section: %x\n", symOffsetUsed);
				}
		
				else if (relocTable->Type == 4) { 
					// relocation table will hold the details of symbol where it is used.
					// but symbol table will hold the details of where details of the symbol is stored.
					// For ex.  there is a symbol for string "hello world" that is used in assembly. The assembly is present in .txt section
					// where as the "hello world" will be present in .data section.
					// so, symbol table will hold the info of .data where as relocation table will hold the info of .text
					printf("The 32-bit relative address from the byte following the relocation. needed to make global variables to work correctly\n");
					
					symOffsetUsed = sectionMapping[i] /*current section in which we are parsing for symbol used*/ +
						relocTable->VirtualAddress;/*This virtual address is offset from the section where symbol is used*/
					
					printf("symbol address from the newly allocated section: %x\n", symOffsetUsed);
					printf("section number: %d\n", sTable[relocTable->SymbolTableIndex].SectionNumber);
					printf("Storage class of Symbol: 0x%x. \n", sTable[relocTable->SymbolTableIndex].StorageClass);
					printf("Type of symbol: 0x%x\n", sTable[relocTable->SymbolTableIndex].Type);
		
					// THIS IS EXTERNAL FUNCTION HAS TO BE DYNAMICALLY LINKED
					if (sTable[relocTable->SymbolTableIndex].SectionNumber == 0 && sTable[relocTable->SymbolTableIndex].StorageClass == 2) {
						printf("THIS IS EXTERNAL FUNCTION HAS TO BE DYNAMICALLY LINKED\n");
						got[gotIndex] = VirtualAlloc(NULL, 8, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
						functionAddr = functionFinder(functionSymbolName);
						printf("Actual memory address of the function used in symbol: 0x%x\n", functionAddr);
						
						if(functionAddr)
						memcpy(got[gotIndex], &functionAddr, 8);
						rip = symOffsetUsed + 4;
						UINT64 final = *(got + gotIndex);
						offset = final - rip;
						memcpy(symOffsetUsed, &offset, sizeof(UINT32));
						gotIndex += 1;
					}
		
		  			// This type of symbols are functions as of now and are located in same section means .text section
					else if (sTable[relocTable->SymbolTableIndex].SectionNumber != 0 && sTable[relocTable->SymbolTableIndex].StorageClass == 2 && sTable[relocTable->SymbolTableIndex].Type == 0x20) {
						printf("This type of symbols are functions as of now and are located in same section means .text section\n");
						symOffsetDef = sectionMapping[sTable[relocTable->SymbolTableIndex].SectionNumber - 1] + sTable[relocTable->SymbolTableIndex].Value;
						printf("symOffsetUsed: 0x%x\n", symOffsetUsed);
						symOffsetDef -= (symOffsetUsed + 4);
						memcpy(symOffsetUsed, &symOffsetDef, sizeof(UINT32));
					}
		
		  			// These are generally variables that are locally defined. I have not yet worked for global variable and many other thing. 
					else if (sTable[relocTable->SymbolTableIndex].StorageClass == 3) {
						symOffsetDef = sectionMapping[sTable[relocTable->SymbolTableIndex].SectionNumber - 1] + sTable[relocTable->SymbolTableIndex].Value;
						printf("symOffsetUsed: 0x%x\n", symOffsetUsed);
						printf("symOffsetDef: 0x%x \n", symOffsetDef);
						symOffsetDef -= (symOffsetUsed + 4);
						memcpy(symOffsetUsed, &symOffsetDef, sizeof(UINT32));
					}
					else {}
					
					
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
				else continue;
			}
   		}
   		```

- Once done with relocation, find the address of function to be executed. For this starting address of newly allocated .text is saved in a variable and also the offset of the function to execute is also stored in a variable(while parsing symbol table).
	- ```c
		typedef void (*EntryPoint)(void);
		EntryPoint ePoint;
		ePoint = AddressOfTextSection + offsetOfEntryPoint;
		ePoint(); 
 		``` 

# Reference
1. https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
2. https://github.com/trustedsec/COFFLoader/blob/main/COFFLoader.c






   
