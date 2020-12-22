#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>
#include "PEB32.h"

PVOID myGetModule(wchar_t *name) {
    PEB* peb = (PEB*)__readfsdword(0x30);

    LIST_ENTRY32 *listHead = &(peb->Ldr->InMemoryOrderModuleList);
    for(LIST_ENTRY32 *work = listHead->Flink ; work != listHead ; work = work->Flink){
        LDR_DATA_TABLE_ENTRY *entry = CONTAINING_RECORD(work, LDR_DATA_TABLE_ENTRY, InMemoryOrderModuleList);
        //printf("Module %ls was loaded, baseaddress is %p\n", entry->BaseDllName.Buffer,entry->DllBase);
		if(!wcsicmp(name, entry->BaseDllName.Buffer))
			return entry->DllBase;
    }
    return 0;
}

int main() {
    wchar_t *target = L"kernel32.dll";
	HMODULE hTarget = myGetModule(target);
	printf("Dll %S is at %p\n", target, hTarget);
	system("pause");
	return 0;
}
