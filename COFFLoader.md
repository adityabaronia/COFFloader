# COFFloader
- COFF Loader is more or less a mini-linker that will perform in-memory linking and execution.
- The COFF loader is a critical component in the execution of programs that are in the COFF format. It performs the necessary steps to load, link, relocate, and execute these programs, ensuring that all dependencies are resolved and that the program can run correctly in its target environment.



## What is COFF file format(Common object file format) ?
***Object Files*: Intermediate files produced by compilers that contain code and data not yet linked into an executable.**

The Common Object File Format (COFF) is a file format for executable, object code, and debugging information. Originally developed for Unix System V, COFF has been widely adopted in various Unix and Unix-like operating systems, as well as in some versions of Microsoft Windows. It provides a standardized way to store and organize the machine code and associated data needed for programs to be executed.
### Key Features of COFF
- **Standardization**: COFF provides a consistent structure for object files, making it easier for tools like compilers, linkers, and debuggers to work together.
- **Modularity**: COFF supports modular programming by allowing multiple object files to be linked together into a single executable.
- **Flexibility**: The format includes sections for different types of data (code, initialized data, uninitialized data, etc.) and supports relocation and symbol resolution.

### Structure of a COFF File
A COFF file typically consists of the following parts:

1. **File Header**: Contains metadata about the file.
2. **Optional Header**: Provides additional information for executable files, such as the entry point and memory layout.
3. **Section Headers**: Describe the different sections of the file.
4. **Sections**: Contain the actual code, data, and other information.

### File Header
The file header contains essential information about the object file:

- Machine: The target machine type (e.g., x86, x86_64).
- Number of Sections: The number of sections in the file.
- Time Stamp: The time the file was created.
- Pointer to Symbol Table: The file offset of the symbol table.
- Number of Symbols: The number of entries in the symbol table.
- Size of Optional Header: The size of the optional header.
- Characteristics: Flags indicating attributes of the file (e.g., if it is relocatable, executable, etc.).

### Optional Header
The optional header, which is included in executable files, provides additional information such as:

- Entry Point: The address of the first instruction to execute.
- Code Size: The size of the code section.
- Initialized Data Size: The size of the initialized data section.
- Uninitialized Data Size: The size of the uninitialized data section (BSS).
- Base of Code/Data: The preferred load addresses for code and data sections.

### Section Headers
Each section header provides details about a section, including:

- Name: The name of the section (e.g., .text, .data).
- Virtual Size: The size of the section when loaded into memory.
- Virtual Address: The address where the section should be loaded.
- Size of Raw Data: The size of the section's data in the file.
- Pointer to Raw Data: The file offset of the section's data.
- Relocation Entries: Information about relocations needed for the section.
- Line Numbers: Information for debugging.
- Characteristics: Flags indicating attributes of the section (e.g., executable, readable, writable).

### Sections
Common sections in a COFF file include:

- .text: Contains the executable code.
- .data: Contains initialized data.
- .bss: Contains uninitialized data.
- .rdata: Contains read-only data.
- .edata: Contains export information (functions and variables that can be used by other modules).
- .idata: Contains import information (functions and variables imported from other modules).
- .debug: Contains debugging information.

### Symbol Table
The symbol table provides information about symbols (variables, functions, etc.) used in the file:

- Name: The name of the symbol.
- Value: The value associated with the symbol (e.g., an address).
- Section Number: The section where the symbol is defined.
- Type: The type of symbol (e.g., function, data).
- Storage Class: The storage class of the symbol (e.g., external, static).
- Number of Auxiliary Symbols: The number of auxiliary symbol table entries.

### Relocation Entries
Relocation entries are used to adjust addresses in the code and data sections when the file is loaded into memory. Each entry specifies:

- Virtual Address: The address that needs to be adjusted.
- Symbol Index: The index of the symbol in the symbol table.
- Type: The type of relocation (e.g., relative, absolute).


## What is Difference between COFF and PE file?

The Common Object File Format (COFF) and the Portable Executable (PE) file format are both used for executable files, object code, and related data. However, they serve different purposes and have different structures. Here’s a detailed comparison between COFF and PE file formats:

### Common Object File Format (COFF)
Origin and Use:

COFF was originally developed for Unix System V and is used primarily in Unix and Unix-like operating systems.
It is a standard format for object files, which are intermediate files generated by compilers before linking into executables.
#### Structure:

- File Header: Contains metadata about the file, such as target machine, number of sections, and pointers to other parts of the file.
- Optional Header: Additional information, usually for executable files, like entry point, code size, etc.
- Section Headers: Information about each section (e.g., .text, .data, .bss).
- Sections: Contains the actual code, data, and other information.
- Symbol Table: Information about symbols (variables, functions) used in the file.
- Relocation Entries: Details about addresses that need adjustment when the file is loaded.
**Use Cases:**

*Primarily used for object files during the compilation process.*
*Suitable for modular programming and linking multiple object files into a single executable.*

### Portable Executable (PE)
Origin and Use:

PE format was developed by Microsoft and is used in Windows operating systems.
*It is an extension of the COFF format* and is used for executable files (EXE), dynamic link libraries (DLL), and other types of files in Windows.
#### Structure:

- DOS Header: Ensures compatibility with older DOS systems and contains a pointer to the PE header.
- PE Header: Contains the COFF file header and additional fields specific to Windows executables.
- Optional Header: Provides important information for the loader, such as entry point, image base, section alignment, and subsystem requirements.
- Section Table: Information about each section in the file (e.g., .text, .data, .rdata, .rsrc, .reloc).
- Sections: Contains the actual code, data, resources, import/export tables, and other information.
- Data Directories: Array of data directory entries that point to other structures (e.g., import/export tables, resource table, exception table).
- Import/Export Tables: Lists of functions and variables imported from or exported to other modules.
Use Cases:

Used for all types of executables and libraries in Windows.
Supports advanced features like dynamic linking, structured exception handling, and resource management.

#### Key Differences

1. Compatibility:
  - COFF: Primarily used in Unix and Unix-like systems.
  - PE: Specifically designed for Windows and includes additional structures for Windows-specific features.

3. Headers:
  - COFF: *Has a simpler structure with a focus on object files.*
  - PE: *Includes a DOS header for backward compatibility*, a rich PE header, and extensive optional headers for Windows-specific functionality.

4. Data Directories:
  - PE: Contains an array of data directories for additional features like import/export tables, resources, and debugging information, which are not present in standard COFF files.

5. Sections:
  - COFF: Sections are simpler and mainly focused on code and data.
  - PE: Sections include additional types like resources, relocation information, and debug data.

6. Relocation and Linking:
  - COFF: Focuses on modularity and linking multiple object files.
  - PE: Supports dynamic linking and includes complex relocation mechanisms for loaded modules.

#### Summary
  - COFF: A simpler, older format used mainly for object files in Unix systems. Focuses on modular programming and linking.
  - PE: An extension of COFF used in Windows. It includes additional headers and structures to support Windows-specific features like dynamic linking, structured exception handling, and resource management.



## What is COFF(Common object file format) loader? 
The Common Object File Format (COFF) loader is a component in operating systems or development environments responsible for loading and executing object files that are in the COFF format.

### Key Functions of a COFF Loader
1. **Loading Executable Files:** The COFF loader reads the COFF object files, which contain machine code, data, and metadata necessary for the execution of a program.

2. **Relocation:** The COFF loader handles the relocation of addresses within the object file. Relocation is necessary because the object file might be loaded at a different memory address than originally expected.

3. **Symbol Resolution:** The COFF loader resolves symbols, which are references to variables, functions, or other entities that are defined in other object files or libraries.

4. **Dynamic Linking:** If the executable depends on shared libraries (dynamic link libraries or DLLs), the COFF loader will link these dynamically at runtime.

5. **Initialization and Execution:** Once all the necessary linking and relocation are done, the COFF loader transfers control to the program’s entry point to begin execution.


### Example of COFF Loader Usage
*When a program is compiled, it is converted into an object file in the COFF format. The following is a simplified example of how a COFF loader might process this file:*

1. **Read the COFF Header:** The loader reads the header to understand the file's structure and metadata.   

3. **Load Sections into Memory:** The loader reads each section (e.g., code, data) and loads(maps) them into appropriate memory locations.

4. **Perform Relocation:** If the object file has relocation entries, the loader adjusts addresses based on the actual load address.

5. **Resolve Symbols:** The loader resolves any external symbols(functions) *such as printf* by linking with other object files or libraries.

6. **Transfer Control:** The loader sets up the initial program stack and registers, then transfers control to the program’s entry point.



### Blueprint
In order to develop the COFF Loader , the following tasks must be tackled down:

- Parse the COFF file according to the COFF specification
- Retrieve the COFF sections and map them in memory
- Resolve symbols and modify the sections to set the right reference address in the sections
- Resolve the external functions (such as printf) to set the right address in the sections
- Retrieve the section containing the executable code
- Run the code

## COFF loader in depth

- the COFF file is a book and is segmented in different sections. Among these sections there are the .text, .data, .rdata etc... with the same definition as those for the PE. However, the data contained in each section header is quite different. Moreover, other new parts are added.
- The COFF specification for Object File contains a Symbol Table that summarizes all symbols used and a Symbol String Table that contains the name of each symbol.
- Likewise, there is not any .reloc section in COFF file but there is a Relocation Table that contains all the information needed to resolve symbols, compute their address and modify the sections' code to fix symbols references.

### COFF Header
The COFF header specification can be found here(https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#coff-file-header-object-and-image) in the Microsoft documentation.

The file header starts at the offset 0. The following C structure can be used to handle the COFF header:
```C
typedef struct _CoffHeader {
    uint16_t    machine;
    uint16_t    numberOfSections;
    uint32_t    timeDateStamp;
    uint32_t    pointerToSymbolTable;
    uint32_t    numberOfSymbols;
    uint16_t    sizeOfOptionalHeader;
    uint16_t    characteristics;
} CoffHeader;
```

The ```machine``` value is a number defining for which architecture the COFF file have been compiled. For example, the value ```0x8664``` represents an x64 architecture.

The value ```pointerToSymbolTable``` is the offset of the symbol table. Thus, the header can be used to directly jump to the Symbol Table :
```C
// pseudo code
// void *data : address of the first COFF byte

CoffSymbol* firstSymbol = data + coffHeader.pointerToSymbolTable;
```
The optional headers are empty on a File Object COFF structure.

The characteristic value represents the COFF type and its possible values are resumed in the Microsoft documentation(https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#characteristics).

### Sections Header
Right after the **file header**, there are the section headers. These headers contains all the information needed to access the data contained in the different sections. The specification about section headers can be found here in the Microsoft documentation.

The following C structure can be used to handle the sections header :
```C
typedef struct _CoffSection {
    char        name[8];
    uint32_t    virtualSize;
    uint32_t    virtualAddress;
    uint32_t    sizeOfRawData;
    uint32_t    pointerToRawData;
    uint32_t    pointerToRelocations;
    uint32_t    pointerToLinenumber;
    uint16_t    numberOfRelocations;
    uint16_t    numberOfLinenumber;
    uint32_t    characteristics;
} CoffSection;
```
- The ```name``` value is the section name (.text, .data, etc...). Not so much to say about it.

- The ```virtualSize``` and ``virtualAddress`` values are always set to ``0`` in COFF file as they are meant to contains the data once the PE is loaded in memory.

- The ```pointerToRawData``` data is the ```offset``` used to access to the data contained in the section. For example, **if the section is the ``.text`` section, ```pointerToRawData``` data will point to the first executable bit.** The value is absolute (ie from the byte 0 of the file) and not relative from the section (ie from the section address).

- The ``pointerToRelocations`` data is the ``offset`` used to access to the ``Relocation Table`` linked to the section (see the next part about relocation). As for the **``pointerToRawData``, the offset is absolute and not relative.**

- The ``pointerToLinenumber`` is usually 0 or can be ignored as this field is deprecated in COFF compilation.


### Navigate into sections (.text, .bss, .data , etc)
During the COFF file parsing, it will be needed to navigate through the different sections. This can easily be done by leveraging the following facts :

- The total number of sections is given in the file header
- The first section header is located right after the file header
- The size of the file and section headers are constant and known
- The different section headers are stored in a continuous way
- Thus, to access to the section i the following pseudo-code can be used:
```C
// pseudo code
// void *data : address of the first COFF byte
CoffSection* section_i = data + HEADER_SIZE + i * SECTION_SIZE
```

### Relocations Table
**This table contains all the information needed to resolve symbols and modify the segment code to inject the symbol address.**

Once again, as an example, the following code is used:
```C
int main(void){
    printf("Hello World !\n");
}
```
The decompiled code stored in the Object File .text section is the following:
```asm
.text
  000000000000001B: 48 8D 0D 00 00 00 00 lea         rcx,[??_C@_0M@KPLPPDAC@Hello?5World@]
  0000000000000022: E8 00 00 00 00       call        __imp_printf
```
- The addresses contained in the section are 0x00000000. If the .text section is loaded in memory as-is and run, the program will try to access to the address 0x00000000 and will crash.
- Thus, a relocation must be performed to replace the fake symbol address by the real one.
- On this example, two relocations must be performed : the ??_C@_0M@KPLPPDAC@Hello?5World@ and the __imp_printf.
- Thus, two entries will be present in the .text section relocation table.

The following C structure can be used to handle each relocation entry:
```C
typedef struct _CoffReloc {
    uint32_t    virtualAddress;
    uint32_t    symbolTableIndex;
    uint16_t    type;
} CoffReloc;
```
- The ```virtualAddress``` value is the relative offset from the section start to the first byte of the address to modify.

If the .text section contains only these two lines :
```asm
  000000000000001B: 48 8D 0D 00 00 00 00 lea         rcx,[??_C@_0M@KPLPPDAC@Hello?5World@]
  0000000000000022: E8 00 00 00 00       call        __imp_printf
```
The virtual address for the relocations will be 0x03 and 0x08.
- The ```symbolTableIndex``` value contains the index of the symbol in the Symbol Table. This value is used to retrieve information about the symbol that must be relocated in the section.

The ```type``` value is the relocation type i.e; the way the symbol address must be given in the section. These codes are dependent of the architecture. Only the interesting codes for x64 will be explained.

| Name                    | Value | Description                                                                                       |
|-------------------------|-------|---------------------------------------------------------------------------------------------------|
| IMAGE_REL_AMD64_ABSOLUTE| 0x0000| The relocation is ignored                                                                         |
| IMAGE_REL_AMD64_ADDR32  | 0x0001| The symbol reference address in the section must be replaced by the 64bits absolute address of the symbol. |
| IMAGE_REL_AMD64_ADDR64  | 0x0002| The symbol reference address in the section must be replaced by the 32bits absolute address of the symbol. |
| IMAGE_REL_AMD64_ADDR32NB| 0x0003| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section |
| IMAGE_REL_AMD64_REL32   | 0x0004| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section minus an offset of 0 bits |
| IMAGE_REL_AMD64_REL32_1 | 0x0005| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section minus an offset of 1 bits |
| IMAGE_REL_AMD64_REL32_2 | 0x0006| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section minus an offset of 2 bits |
| IMAGE_REL_AMD64_REL32_3 | 0x0007| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section minus an offset of 3 bits |
| IMAGE_REL_AMD64_REL32_4 | 0x0008| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section minus an offset of 4 bits |
| IMAGE_REL_AMD64_REL32_5 | 0x0009| The symbol reference address in the section must be replaced by the 32bits relative address of the symbol from the current section minus an offset of 5 bits |

Other relocation types exist and are referenced in the Microsoft documentation(https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#section-table-section-headers) but they are hardly ever used or only for debugging purpose.

Thus only these relocation types will be handled here.


### Absolute and Relative address
- THE symbol absolute address is its address from the file start. A symbol relative address is its address from a given position in the file (the relocation address for example).
```C
// Compute the relative address of a symbol from a given section
RelativeAddress(Symbol) = AbsoluteAddress(Symbol) - AbsoluteAddress(Section)
  ```
- **Relative address is relative to the section address and Absolute address starts from the first address of COFF**
- In the relocation description, the term absolute and relative address is used. Depending on the relocation type, one or the other must be computed.

- This part aims to explain the difference between absolute and relative address.

- The following example could help to see the difference between these two address types.

##### Example:
Michel TheHacker lives in a very small city with only one street. The street is one way and Michel lives in the 50th house.
When he gives his address to a stranger, he always count the number of houses between his and the beginning of the street. His address is then 50. This is called absolute address.

However, when he gives his address to one of his friends living in the same street, he always gives the number of houses between his house and his friend house. Thus, for Robert, a Michel friend, living in the house 12, Michel’s address is 38 as there are 38 houses between his and Michel one's. This is called relative address.

- Knowing that, when a relative address is needed, the following formula can be used to compute the symbol relative address of a symbol from a section start:
```C
// Compute the relative address of a symbol from a given section
RelativeAddress(Symbol) = AbsoluteAddress(Symbol) - AbsoluteAddress(Section)
```
- The absolute address can be easily computed with the following formula:
```C
AbsoluteAddress(Symbol) = AbsoluteAddress(SymbolTable) + Offset(Symbol in SymbolTable)
```
These addresses can then be written in the corresponding section.

### Symbol Table
This table contains all the data related to the symbols. It includes their name, type and storage addresses. The following C structure can be used to handle each symbol entry:

```C
typedef struct _CoffSymbol {
    union {
        char        name[8];
        uint32_t    value[2];
    } first;
    uint32_t    value;
    uint16_t    sectionNumber;
    uint16_t    type;
    uint8_t        storageClass;
    uint8_t        numberOfAuxSymbols;

} CoffSymbol;
```
- The first value is a union. It can handle two types of data depending on the symbol:
  - The symbol name is fewer than 8 characters : the first.name value will contain the name of the symbol
  - The symbol name is greater than 8 characters : the first.name[0] will be equal to 0 and the first.value will contains the offset of the symbol name in the Symbol Sting Table.
- When the name is greater than 8 characters, the full-symbol name can be retrieved with the following code:
```C
// pseudo code
char *name = symbolStringTable + coffSymbol.first.value
```
- The ```value``` value is the symbol value. This entry can have different meanings depending on the symbol storage class.
- The ``sectionNumber`` value is the section index where the symbol data is stored.
- The ``type`` value is the type of the symbol ie the type of the value it represents. For example, it could be ``DT_CHAR``, ``DT_INT``, ``DT_FUNCTION``. Usually, this field is not really used and is either DT_FUNCTION or 0.

- The ``storageClass`` value represents how the data is actually stored in this symbol. The following table contains the main possible values and their specificities:

| Name                    | Value | Description                                                                                       |
|-------------------------|-------|---------------------------------------------------------------------------------------------------|
| IMAGE_SYM_CLASS_NULL    | 0x0   | No storage type                                                                                   |
| IMAGE_SYM_CLASS_NULL_AUTO | 0x01 | auto type. It is usually used for auto-allocated values stored in the stack                       |
| IMAGE_SYM_CLASS_EXTERNAL | 0x02 | The symbol is defined in another COFF object. If the section number is 0, the symbol's value represent the symbol size, otherwise it represents the symbol offset within its section |
| IMAGE_SYM_CLASS_STATIC  | 0x03  | The symbol defined a static value. If the symbol's value is not 0, it represents the symbol offset within its section |


- Thus, if the symbol storage class is either ``IMAGE_SYM_CLASS_STATIC`` or ``IMAGE_SYM_CLASS_EXTERNAL`` with a non 0 section index, the symbol address can be computed as follows:
```C
// pseudo code
void *symbolAddress = sections[coffSymbol.sectionIndex].pointerToRawData + coffSymbol.value;
```



Finally, the numberOfAuxSymbols represents the number of auxiliary symbols that are contained right after the symbol record.
These auxiliary symbols are usually linker specific and thus can be ignored for now as the COFFLoader does not link different object files to one another. They give additional information about the linked symbol. For example, in case of a symbol defining a function, the additional symbol can contain information about the total size of the function.

This additional information is not really needed for the COFFLoader.

### Symbol Table String
- This table just contains the name of the symbols
- This table is used to resolve symbols' name whose size is greater than 8 characters (see previous section about Symbol Table)




## COFF relocation
- Object file contain relocation COFF relocations, which **specify how the section data should be modified** when placed in the image file and subsequently loaded into memory.
- Image file(PE/EXE) do not contain COFF relocations, because all referenced symbols hahve already been assigned address in a flat address space.
- An image contains relocation in the form of base relocation (.reloc) section.
- **For each section in object file, an array of fixed-length records holds the section's COFF relocations**
- The position and length of the array are specified in the section header.

| Offset | Size | Field            | Description |
|--------|------|------------------|-------------|
| 0      | 4    | VirtualAddress   | The address of the item to which relocation is applied. This is the offset from the beginning of the section, plus the value of the section's RVA/Offset field. See Section Table (Section Headers). For example, if the first byte of the section has an address of 0x10, the third byte has an address of 0x12. |
| 4      | 4    | SymbolTableIndex | A zero-based index into the symbol table. This symbol gives the address that is to be used for the relocation. If the specified symbol has section storage class, then the symbol's address is the address with the first section of the same name.                                                           |
| 8      | 2    | Type             | A value that indicates the kind of relocation that should be performed. Valid relocation types depend on machine type. See Type Indicators.  |


- if the symbol referred to by the SymbolTableIndex field has the storage class ```IMAGE_SYM_CLASS_SECTION```, the symbol's address is the beginning of the section. The section is usually in the same file, except when the object file is part of an archive(library)












## Reference
1. CHATGPT
2. https://otterhacker.github.io/Malware/CoffLoader.html#hands-on--coff-loader
3. COFF header specification in MSDN https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#coff-file-header-object-and-image
4. https://0xpat.github.io/Malware_development_part_8/ (better for leraning parsing)
5. https://github.com/maxDcb/C2Core/blob/8f58367eeacbe2c4b481b3fee5f75c75007dd25d/modules/CoffLoader/CoffLoader.cpp
