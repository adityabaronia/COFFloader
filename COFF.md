

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
