#include <Windows.h>
#include <stdio.h>

typedef struct{
	WORD machine; //uint16_t
	BYTE numberOfSection; //uint16_t
	DWORD timeStamp; //uint32_t
	DWORD filePtrSmblTbl; // file pointer to symbol table //uint32_t
	WORD sizeOfOptionalHeader;  //uint16_t
	WORD characteristics; //uint16_t
};




int main() {
	HANDLE hFile = NULL;
	LPDWORD objFileSize = 0;
	LPVOID objFileInMem = NULL;
	LPDWORD bytesRead = NULL;
	//opening file hadle
	hFile = CreateFileA("C:\\Users\\smoke.REDTEAMER\\Desktop\\COFFLoader\\helloworld.obj", 
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
	
	if (!GetFileSize(hFile, objFileSize)) {
		printf("Could not get file size: %d\n", GetLastError());
		exit(1);
	}

	//Allocating virtual memory
	objFileInMem = VirtualAlloc(0,
		objFileSize, 
		MEM_COMMIT | MEM_RESERVE, 
		PAGE_READWRITE);

	if (objFileInMem == NULL) {
		printf("Error in allocating virtual memory: %d\n", GetLastError());
		exit(1);
	}

	if (!ReadFile(hFile, objFileInMem, objFileSize, bytesRead, NULL)) {
		printf("Error in reading file: %d\n", GetLastError());
	}
	if (objFileSize != bytesRead) {
		printf("Error in reading complete file\n");
		exit(1);
	}





	return 0;
}