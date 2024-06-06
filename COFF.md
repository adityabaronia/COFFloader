

# C file
```C
#include <stdio.h>
#include <Windows.h>

int main(){

    printf("hello world\n");
    return 0;
}
```

# Compilation
```bash
cl.exe \c hellowworld.c
```

# COFF Header
```asm
C:\Users\smoke.REDTEAMER\Desktop\COFFLoader>dumpbin /headers helloworld.obj
Microsoft (R) COFF/PE Dumper Version 14.36.32532.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file helloworld.obj

File Type: COFF OBJECT

FILE HEADER VALUES
            8664 machine (x64)
               E number of sections
        6661E3A9 time date stamp Thu Jun  6 21:58:25 2024
             53F file pointer to symbol table
              30 number of symbols
               0 size of optional header
               0 characteristics

SECTION HEADER #1
.drectve name
       0 physical address
       0 virtual address
      5D size of raw data
     244 file pointer to raw data (00000244 to 000002A0)
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
      8C size of raw data
     2A1 file pointer to raw data (000002A1 to 0000032C)
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
      17 size of raw data
     32D file pointer to raw data (0000032D to 00000343)
     344 file pointer to relocation table
       0 file pointer to line numbers
       2 number of relocations
       0 number of line numbers
60500020 flags
         Code
         16 byte align
         Execute Read

SECTION HEADER #4
.text$mn name
       0 physical address
       0 virtual address
       8 size of raw data
     358 file pointer to raw data (00000358 to 0000035F)
     360 file pointer to relocation table
       0 file pointer to line numbers
       1 number of relocations
       0 number of line numbers
60501020 flags
         Code
         COMDAT; sym= __local_stdio_printf_options
         16 byte align
         Execute Read

SECTION HEADER #5
.text$mn name
       0 physical address
       0 virtual address
      43 size of raw data
     36A file pointer to raw data (0000036A to 000003AC)
     3AD file pointer to relocation table
       0 file pointer to line numbers
       2 number of relocations
       0 number of line numbers
60501020 flags
         Code
         COMDAT; sym= _vfprintf_l
         16 byte align
         Execute Read

SECTION HEADER #6
.text$mn name
       0 physical address
       0 virtual address
      57 size of raw data
     3C1 file pointer to raw data (000003C1 to 00000417)
     418 file pointer to relocation table
       0 file pointer to line numbers
       2 number of relocations
       0 number of line numbers
60501020 flags
         Code
         COMDAT; sym= printf
         16 byte align
         Execute Read

SECTION HEADER #7
  .xdata name
       0 physical address
       0 virtual address
       8 size of raw data
     42C file pointer to raw data (0000042C to 00000433)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
40301040 flags
         Initialized Data
         COMDAT; sym= $unwind$_vfprintf_l
         4 byte align
         Read Only

SECTION HEADER #8
  .pdata name
       0 physical address
       0 virtual address
       C size of raw data
     434 file pointer to raw data (00000434 to 0000043F)
     440 file pointer to relocation table
       0 file pointer to line numbers
       3 number of relocations
       0 number of line numbers
40301040 flags
         Initialized Data
         COMDAT; sym= $pdata$_vfprintf_l
         4 byte align
         Read Only

SECTION HEADER #9
  .xdata name
       0 physical address
       0 virtual address
       8 size of raw data
     45E file pointer to raw data (0000045E to 00000465)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
40301040 flags
         Initialized Data
         COMDAT; sym= $unwind$printf
         4 byte align
         Read Only

SECTION HEADER #A
  .pdata name
       0 physical address
       0 virtual address
       C size of raw data
     466 file pointer to raw data (00000466 to 00000471)
     472 file pointer to relocation table
       0 file pointer to line numbers
       3 number of relocations
       0 number of line numbers
40301040 flags
         Initialized Data
         COMDAT; sym= $pdata$printf
         4 byte align
         Read Only

SECTION HEADER #B
  .xdata name
       0 physical address
       0 virtual address
       8 size of raw data
     490 file pointer to raw data (00000490 to 00000497)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
40300040 flags
         Initialized Data
         4 byte align
         Read Only

SECTION HEADER #C
  .pdata name
       0 physical address
       0 virtual address
       C size of raw data
     498 file pointer to raw data (00000498 to 000004A3)
     4A4 file pointer to relocation table
       0 file pointer to line numbers
       3 number of relocations
       0 number of line numbers
40300040 flags
         Initialized Data
         4 byte align
         Read Only

SECTION HEADER #D
   .data name
       0 physical address
       0 virtual address
       D size of raw data
     4C2 file pointer to raw data (000004C2 to 000004CE)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
C0400040 flags
         Initialized Data
         8 byte align
         Read Write

SECTION HEADER #E
 .chks64 name
       0 physical address
       0 virtual address
      70 size of raw data
     4CF file pointer to raw data (000004CF to 0000053E)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
     A00 flags
         Info
         Remove
         (no align specified)

  Summary

          70 .chks64
           D .data
          8C .debug$S
          5D .drectve
          24 .pdata
          B9 .text$mn
          18 .xdata
```


# Disassembly 
```asm
C:\Users\smoke.REDTEAMER\Desktop\COFFLoader>dumpbin /disasm helloworld.obj
Microsoft (R) COFF/PE Dumper Version 14.36.32532.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file helloworld.obj

File Type: COFF OBJECT

main:
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[$SG100994]
                    00
  000000000000000B: E8 00 00 00 00     call        printf
  0000000000000010: 33 C0              xor         eax,eax
  0000000000000012: 48 83 C4 28        add         rsp,28h
  0000000000000016: C3                 ret

__local_stdio_printf_options:
  0000000000000000: 48 8D 05 00 00 00  lea         rax,[?_OptionsStorage@?1??__local_stdio_printf_options@@9@9]
                    00
  0000000000000007: C3                 ret

_vfprintf_l:
  0000000000000000: 4C 89 4C 24 20     mov         qword ptr [rsp+20h],r9
  0000000000000005: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  000000000000000A: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000F: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: E8 00 00 00 00     call        __local_stdio_printf_options
  000000000000001D: 48 8B 4C 24 58     mov         rcx,qword ptr [rsp+58h]
  0000000000000022: 48 89 4C 24 20     mov         qword ptr [rsp+20h],rcx
  0000000000000027: 4C 8B 4C 24 50     mov         r9,qword ptr [rsp+50h]
  000000000000002C: 4C 8B 44 24 48     mov         r8,qword ptr [rsp+48h]
  0000000000000031: 48 8B 54 24 40     mov         rdx,qword ptr [rsp+40h]
  0000000000000036: 48 8B 08           mov         rcx,qword ptr [rax]
  0000000000000039: E8 00 00 00 00     call        __stdio_common_vfprintf
  000000000000003E: 48 83 C4 38        add         rsp,38h
  0000000000000042: C3                 ret

printf:
  0000000000000000: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  000000000000000F: 4C 89 4C 24 20     mov         qword ptr [rsp+20h],r9
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 8D 44 24 48     lea         rax,[rsp+48h]
  000000000000001D: 48 89 44 24 28     mov         qword ptr [rsp+28h],rax
  0000000000000022: B9 01 00 00 00     mov         ecx,1
  0000000000000027: E8 00 00 00 00     call        __acrt_iob_func
  000000000000002C: 4C 8B 4C 24 28     mov         r9,qword ptr [rsp+28h]
  0000000000000031: 45 33 C0           xor         r8d,r8d
  0000000000000034: 48 8B 54 24 40     mov         rdx,qword ptr [rsp+40h]
  0000000000000039: 48 8B C8           mov         rcx,rax
  000000000000003C: E8 00 00 00 00     call        _vfprintf_l
  0000000000000041: 89 44 24 20        mov         dword ptr [rsp+20h],eax
  0000000000000045: 48 C7 44 24 28 00  mov         qword ptr [rsp+28h],0
                    00 00 00
  000000000000004E: 8B 44 24 20        mov         eax,dword ptr [rsp+20h]
  0000000000000052: 48 83 C4 38        add         rsp,38h
  0000000000000056: C3                 ret

  Summary

          70 .chks64
           D .data
          8C .debug$S
          5D .drectve
          24 .pdata
          B9 .text$mn
          18 .xdata

```
