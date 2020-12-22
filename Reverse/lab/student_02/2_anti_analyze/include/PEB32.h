#include <windef.h>
#include <stdint.h>
#include <winnt.h>

typedef struct _UNICODE_STRING
{
  unsigned __int16 Length;
  unsigned __int16 MaximumLength;
  wchar_t *Buffer;
}UNICODE_STRING;

typedef struct 
{
  BYTE Reserved1[8];
  PVOID Reserved2[3];
  LIST_ENTRY32 InMemoryOrderModuleList;
}_PEB_LDR_DATA;

#pragma pack(push, 8)
typedef struct
{
  BYTE Reserved1[16];
  PVOID Reserved2[10];
  UNICODE_STRING ImagePathName;
  UNICODE_STRING CommandLine;
} _RTL_USER_PROCESS_PARAMETERS;
#pragma pack(pop)

typedef struct _PEB
{
  uint8_t InheritedAddressSpace;
  uint8_t ReadImageFileExecOptions;
  uint8_t BeingDebugged;
  uint8_t BitField;
  void *Mutant;
  void *ImageBaseAddress;
  _PEB_LDR_DATA *Ldr;
  _RTL_USER_PROCESS_PARAMETERS *ProcessParameters;
  void *SubSystemData;
  void *ProcessHeap;
  RTL_CRITICAL_SECTION *FastPebLock;
  void *AtlThunkSListPtr;
  void *IFEOKey;
  unsigned int CrossProcessFlags;
  union
  {
    void *KernelCallbackTable;
    void *UserSharedInfoPtr;
  };
  unsigned int SystemReserved[1];
  unsigned int AtlThunkSListPtr32;
  void *ApiSetMap;
  unsigned int TlsExpansionCounter;
  void *TlsBitmap;
  unsigned int TlsBitmapBits[2];
  void *ReadOnlySharedMemoryBase;
  void *HotpatchInformation;
  void **ReadOnlyStaticServerData;
  void *AnsiCodePageData;
  void *OemCodePageData;
  void *UnicodeCaseTableData;
  unsigned int NumberOfProcessors;
  unsigned int NtGlobalFlag;
  LARGE_INTEGER CriticalSectionTimeout;
  unsigned int HeapSegmentReserve;
  unsigned int HeapSegmentCommit;
  unsigned int HeapDeCommitTotalFreeThreshold;
  unsigned int HeapDeCommitFreeBlockThreshold;
  unsigned int NumberOfHeaps;
  unsigned int MaximumNumberOfHeaps;
  void **ProcessHeaps;
  void *GdiSharedHandleTable;
  void *ProcessStarterHelper;
  unsigned int GdiDCAttributeList;
  RTL_CRITICAL_SECTION *LoaderLock;
  unsigned int OSMajorVersion;
  unsigned int OSMinorVersion;
  uint16_t OSBuildNumber;
  uint16_t OSCSDVersion;
  unsigned int OSPlatformId;
  unsigned int ImageSubsystem;
  unsigned int ImageSubsystemMajorVersion;
  unsigned int ImageSubsystemMinorVersion;
  unsigned int ActiveProcessAffinityMask;
  unsigned int GdiHandleBuffer[34];
  void *PostProcessInitRoutine;
  void *TlsExpansionBitmap;
  unsigned int TlsExpansionBitmapBits[32];
  unsigned int SessionId;
  ULARGE_INTEGER AppCompatFlags;
  ULARGE_INTEGER AppCompatFlagsUser;
  void *pShimData;
  void *AppCompatInfo;
  UNICODE_STRING CSDVersion;
  const struct _ACTIVATION_CONTEXT_DATA *ActivationContextData;
  struct _ASSEMBLY_STORAGE_MAP *ProcessAssemblyStorageMap;
  const struct _ACTIVATION_CONTEXT_DATA *SystemDefaultActivationContextData;
  struct _ASSEMBLY_STORAGE_MAP *SystemAssemblyStorageMap;
  unsigned int MinimumStackCommit;
  struct _FLS_CALLBACK_INFO *FlsCallback;
  LIST_ENTRY32 FlsListHead;
  void *FlsBitmap;
  unsigned int FlsBitmapBits[4];
  unsigned int FlsHighIndex;
  void *WerRegistrationData;
  void *WerShipAssertPtr;
  void *pContextData;
  void *pImageHeaderHash;
  unsigned int TracingFlags;
}PEB;

typedef struct _LDR_DATA_TABLE_ENTRY
{
     LIST_ENTRY32 InLoadOrderModuleList;
     LIST_ENTRY32 InMemoryOrderModuleList;
     LIST_ENTRY32 InInitializationOrderModuleList;
     PVOID DllBase;
     PVOID EntryPoint;
     ULONG SizeOfImage;
     UNICODE_STRING FullDllName;
     UNICODE_STRING BaseDllName;
     ULONG Flags;
     WORD LoadCount;
     WORD TlsIndex;
     union
     {
          LIST_ENTRY32 HashLinks;
          struct
          {
               PVOID SectionPointer;
               ULONG CheckSum;
          };
     };
     union
     {
          ULONG TimeDateStamp;
          PVOID LoadedImports;
     };
     void* EntryPointActivationContext;
     PVOID PatchInformation;
     LIST_ENTRY32 ForwarderLinks;
     LIST_ENTRY32 ServiceTagLinks;
     LIST_ENTRY32 StaticLinks;
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;
