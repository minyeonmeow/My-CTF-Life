#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>
#include "PEB32.h"

PVOID myGetModule(wchar_t *name)
{
    PEB *peb = (PEB *)__readfsdword(0x30);

    LIST_ENTRY32 *listHead = &(peb->Ldr->InMemoryOrderModuleList);
    for (LIST_ENTRY32 *work = listHead->Flink; work != listHead; work = work->Flink)
    {
        LDR_DATA_TABLE_ENTRY *entry = CONTAINING_RECORD(work, LDR_DATA_TABLE_ENTRY, InMemoryOrderModuleList);
        //printf("Module %ls was loaded, baseaddress is %p\n", entry->BaseDllName.Buffer,entry->DllBase);
        if (!wcsicmp(name, entry->BaseDllName.Buffer))
            return entry->DllBase;
    }
    return 0;
}

PVOID myGetProc(char *hmodule, char *function_want)
{
    ULONG peoffset = ((IMAGE_DOS_HEADER *)hmodule)->e_lfanew;
    IMAGE_NT_HEADERS32 *nt_headers = (hmodule + peoffset);
    IMAGE_DATA_DIRECTORY *exportDataDirectory = &nt_headers->OptionalHeader.DataDirectory[0];
    IMAGE_EXPORT_DIRECTORY *exportDirectory = hmodule + exportDataDirectory->VirtualAddress;
    DWORD *AddresOfFunction_array = hmodule + exportDirectory->AddressOfFunctions;
    DWORD *AddressOfNames_array = hmodule + exportDirectory->AddressOfNames;
    WORD *AddressOfNameOrdinals_array = hmodule + exportDirectory->AddressOfNameOrdinals;

    DWORD *nameLookup = AddressOfNames_array;
    for (int idx = 0; idx < exportDirectory->NumberOfNames; idx += 1)
    {
        DWORD function_name_RVA = *nameLookup;
        char *function_name = hmodule + function_name_RVA;
        //printf("export function ordinal %hd\n", AddressOfNameOrdinals_array[idx]);
        //printf("export function name %s\n", function_name);
        //puts("---------");
        if (!strcmp(function_name, function_want))
        {
            WORD function_ordinal = AddressOfNameOrdinals_array[idx];
            DWORD function_RVA = AddresOfFunction_array[function_ordinal];
            return hmodule + function_RVA;
        }
        nameLookup++;
    }
    return 0;
}

int main()
{
    wchar_t *targetDll = L"kernel32.dll";
    char *targetFunction = "CreateThread";
    HMODULE hTarget = myGetModule(targetDll);
    printf("Dll %S is at %p\n", targetDll, hTarget);
    printf("function %s is at %p\n", targetFunction, myGetProc(hTarget, targetFunction));
    system("pause");
    return 0;
}