#include "PEB32.h"
#include <stdio.h>

void ListAllModule()
{
    PEB *peb = (PEB *)__readfsdword(0x30);

    LIST_ENTRY32 *listHead = &(peb->Ldr->InMemoryOrderModuleList);

    for (LIST_ENTRY32 *work = listHead->Flink; work != listHead; work = work->Flink)
    {
        LDR_DATA_TABLE_ENTRY *entry = CONTAINING_RECORD(work, LDR_DATA_TABLE_ENTRY, InMemoryOrderModuleList);
        printf("Module %ls was loaded, baseaddress is %p\n", entry->BaseDllName.Buffer, entry->DllBase);
    }
}

int main()
{
    ListAllModule();
    return 0;
}
