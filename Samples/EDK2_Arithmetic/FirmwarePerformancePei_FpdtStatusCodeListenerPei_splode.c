// This file was generated from /home/klee/ and config file /home/klee/


#include <klee/klee.h>

// Ansatz file
extern void __assert_fail(const char *__assertion, const char *__file, unsigned int __line, const char *__function);
extern void __assert_perror_fail(int __errnum, const char *__file, unsigned int __line, const char *__function);
extern void __assert(const char *__assertion, const char *__file, int __line);
typedef long unsigned int size_t;
extern void *memcpy(void *__dest, const void *__src, size_t __n);
extern void *memmove(void *__dest, const void *__src, size_t __n);
extern void *memccpy(void *__dest, const void *__src, int __c, size_t __n);
extern void *memset(void *__s, int __c, size_t __n);
extern int memcmp(const void *__s1, const void *__s2, size_t __n);
extern int __memcmpeq(const void *__s1, const void *__s2, size_t __n);
extern void *memchr(const void *__s, int __c, size_t __n);
extern char *strcpy(char *__dest, const char *__src);
extern char *strncpy(char *__dest, const char *__src, size_t __n);
extern char *strcat(char *__dest, const char *__src);
extern char *strncat(char *__dest, const char *__src, size_t __n);
extern int strcmp(const char *__s1, const char *__s2);
extern int strncmp(const char *__s1, const char *__s2, size_t __n);
extern int strcoll(const char *__s1, const char *__s2);
extern size_t strxfrm(char *__dest, const char *__src, size_t __n);
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l(const char *__s1, const char *__s2, locale_t __l);
extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n, locale_t __l);
extern char *strdup(const char *__s);
extern char *strndup(const char *__string, size_t __n);
extern char *strchr(const char *__s, int __c);
extern char *strrchr(const char *__s, int __c);
extern size_t strcspn(const char *__s, const char *__reject);
extern size_t strspn(const char *__s, const char *__accept);
extern char *strpbrk(const char *__s, const char *__accept);
extern char *strstr(const char *__haystack, const char *__needle);
extern char *strtok(char *__s, const char *__delim);
extern char *__strtok_r(char *__s, const char *__delim, char **__save_ptr);
extern char *strtok_r(char *__s, const char *__delim, char **__save_ptr);
extern size_t strlen(const char *__s);
extern size_t strnlen(const char *__string, size_t __maxlen);
extern char *strerror(int __errnum);
extern int strerror_r(int __errnum, char *__buf, size_t __buflen);
extern char *strerror_l(int __errnum, locale_t __l);
extern int bcmp(const void *__s1, const void *__s2, size_t __n);
extern void bcopy(const void *__src, void *__dest, size_t __n);
extern void bzero(void *__s, size_t __n);
extern char *index(const char *__s, int __c);
extern char *rindex(const char *__s, int __c);
extern int ffs(int __i);
extern int ffsl(long int __l);
extern int ffsll(long long int __ll);
extern int strcasecmp(const char *__s1, const char *__s2);
extern int strncasecmp(const char *__s1, const char *__s2, size_t __n);
extern int strcasecmp_l(const char *__s1, const char *__s2, locale_t __loc);
extern int strncasecmp_l(const char *__s1, const char *__s2, size_t __n, locale_t __loc);
extern void explicit_bzero(void *__s, size_t __n);
extern char *strsep(char **__stringp, const char *__delim);
extern char *strsignal(int __sig);
extern char *__stpcpy(char *__dest, const char *__src);
extern char *stpcpy(char *__dest, const char *__src);
extern char *__stpncpy(char *__dest, const char *__src, size_t __n);
extern char *stpncpy(char *__dest, const char *__src, size_t __n);
typedef unsigned long long UINT64;
typedef long long INT64;
typedef unsigned int UINT32;
typedef int INT32;
typedef unsigned short UINT16;
typedef unsigned short CHAR16;
typedef short INT16;
typedef unsigned char BOOLEAN;
typedef unsigned char UINT8;
typedef char CHAR8;
typedef signed char INT8;
typedef UINT64 UINTN;
typedef INT64 INTN;
typedef struct 
{
  UINT32 Data1;
  UINT16 Data2;
  UINT16 Data3;
  UINT8 Data4[8];
} GUID;
typedef struct 
{
  UINT8 Addr[4];
} IPv4_ADDRESS;
typedef struct 
{
  UINT8 Addr[16];
} IPv6_ADDRESS;
typedef UINT64 PHYSICAL_ADDRESS;
typedef struct _LIST_ENTRY LIST_ENTRY;
struct _LIST_ENTRY
{
  LIST_ENTRY *ForwardLink;
  LIST_ENTRY *BackLink;
};
typedef int VA_LIST;
typedef UINTN *BASE_LIST;
_Static_assert((sizeof(BOOLEAN)) == 1,"sizeof (BOOLEAN) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(INT8)) == 1,"sizeof (INT8) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(UINT8)) == 1,"sizeof (UINT8) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(INT16)) == 2,"sizeof (INT16) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(UINT16)) == 2,"sizeof (UINT16) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(INT32)) == 4,"sizeof (INT32) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(UINT32)) == 4,"sizeof (UINT32) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(INT64)) == 8,"sizeof (INT64) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(UINT64)) == 8,"sizeof (UINT64) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(CHAR8)) == 1,"sizeof (CHAR8) does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(CHAR16)) == 2,"sizeof (CHAR16) does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(BOOLEAN)) == (sizeof(BOOLEAN)),"Alignment of BOOLEAN does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(INT8)) == (sizeof(INT8)),"Alignment of INT8 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(UINT8)) == (sizeof(UINT8)),"Alignment of INT16 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(INT16)) == (sizeof(INT16)),"Alignment of INT16 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(UINT16)) == (sizeof(UINT16)),"Alignment of UINT16 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(INT32)) == (sizeof(INT32)),"Alignment of INT32 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(UINT32)) == (sizeof(UINT32)),"Alignment of UINT32 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(INT64)) == (sizeof(INT64)),"Alignment of INT64 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(UINT64)) == (sizeof(UINT64)),"Alignment of UINT64 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(CHAR8)) == (sizeof(CHAR8)),"Alignment of CHAR8 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(CHAR16)) == (sizeof(CHAR16)),"Alignment of CHAR16 does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(INTN)) == (sizeof(INTN)),"Alignment of INTN does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(UINTN)) == (sizeof(UINTN)),"Alignment of UINTN does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(void *)) == (sizeof(void *)),"Alignment of VOID * does not meet UEFI Specification Data Type requirements");
typedef enum 
{
  __VerifyUint8EnumValue = 0xff
} __VERIFY_UINT8_ENUM_SIZE;
typedef enum 
{
  __VerifyUint16EnumValue = 0xffff
} __VERIFY_UINT16_ENUM_SIZE;
typedef enum 
{
  __VerifyInt32EnumValue = 0x7fffffff
} __VERIFY_INT32_ENUM_SIZE;
_Static_assert((sizeof(__VERIFY_UINT8_ENUM_SIZE)) == 4,"Size of enum does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(__VERIFY_UINT16_ENUM_SIZE)) == 4,"Size of enum does not meet UEFI Specification Data Type requirements");
_Static_assert((sizeof(__VERIFY_INT32_ENUM_SIZE)) == 4,"Size of enum does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(__VERIFY_UINT8_ENUM_SIZE)) == (sizeof(__VERIFY_UINT8_ENUM_SIZE)),"Alignment of enum does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(__VERIFY_UINT16_ENUM_SIZE)) == (sizeof(__VERIFY_UINT16_ENUM_SIZE)),"Alignment of enum does not meet UEFI Specification Data Type requirements");
_Static_assert((_Alignof(__VERIFY_INT32_ENUM_SIZE)) == (sizeof(__VERIFY_INT32_ENUM_SIZE)),"Alignment of enum does not meet UEFI Specification Data Type requirements");
typedef UINTN RETURN_STATUS;
typedef GUID EFI_GUID;
typedef RETURN_STATUS EFI_STATUS;
typedef void *EFI_HANDLE;
typedef void *EFI_EVENT;
typedef UINTN EFI_TPL;
typedef UINT64 EFI_LBA;
typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;
typedef struct 
{
  UINT16 Year;
  UINT8 Month;
  UINT8 Day;
  UINT8 Hour;
  UINT8 Minute;
  UINT8 Second;
  UINT8 Pad1;
  UINT32 Nanosecond;
  INT16 TimeZone;
  UINT8 Daylight;
  UINT8 Pad2;
} EFI_TIME;
typedef IPv4_ADDRESS EFI_IPv4_ADDRESS;
typedef IPv6_ADDRESS EFI_IPv6_ADDRESS;
typedef struct 
{
  UINT8 Addr[32];
} EFI_MAC_ADDRESS;
typedef union 
{
  UINT32 Addr[4];
  EFI_IPv4_ADDRESS v4;
  EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;
typedef struct 
{
  UINT32 dwLength;
  UINT16 wRevision;
  UINT16 wCertificateType;
} WIN_CERTIFICATE;
typedef struct 
{
  EFI_GUID HashType;
  UINT8 PublicKey[256];
  UINT8 Signature[256];
} EFI_CERT_BLOCK_RSA_2048_SHA256;
typedef struct 
{
  WIN_CERTIFICATE Hdr;
  EFI_GUID CertType;
  UINT8 CertData[1];
} WIN_CERTIFICATE_UEFI_GUID;
typedef struct 
{
  WIN_CERTIFICATE Hdr;
  EFI_GUID HashAlgorithm;
} WIN_CERTIFICATE_EFI_PKCS1_15;
extern EFI_GUID gEfiCertTypeRsa2048Sha256Guid;
typedef enum 
{
  EfiReservedMemoryType,
  EfiLoaderCode,
  EfiLoaderData,
  EfiBootServicesCode,
  EfiBootServicesData,
  EfiRuntimeServicesCode,
  EfiRuntimeServicesData,
  EfiConventionalMemory,
  EfiUnusableMemory,
  EfiACPIReclaimMemory,
  EfiACPIMemoryNVS,
  EfiMemoryMappedIO,
  EfiMemoryMappedIOPortSpace,
  EfiPalCode,
  EfiPersistentMemory,
  EfiUnacceptedMemoryType,
  EfiMaxMemoryType,
  MEMORY_TYPE_OEM_RESERVED_MIN = 0x70000000,
  MEMORY_TYPE_OEM_RESERVED_MAX = 0x7FFFFFFF,
  MEMORY_TYPE_OS_RESERVED_MIN = 0x80000000,
  MEMORY_TYPE_OS_RESERVED_MAX = 0xFFFFFFFF
} EFI_MEMORY_TYPE;
typedef enum 
{
  EfiResetCold,
  EfiResetWarm,
  EfiResetShutdown,
  EfiResetPlatformSpecific
} EFI_RESET_TYPE;
typedef struct 
{
  UINT64 Signature;
  UINT32 Revision;
  UINT32 HeaderSize;
  UINT32 CRC32;
  UINT32 Reserved;
} EFI_TABLE_HEADER;
typedef struct 
{
  UINT64 MonotonicCount;
  WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_VARIABLE_AUTHENTICATION;
typedef struct 
{
  EFI_TIME TimeStamp;
  WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_VARIABLE_AUTHENTICATION_2;
typedef UINT32 EFI_FV_FILE_ATTRIBUTES;
typedef UINT32 EFI_FVB_ATTRIBUTES_2;
typedef struct 
{
  UINT32 NumBlocks;
  UINT32 Length;
} EFI_FV_BLOCK_MAP_ENTRY;
typedef struct 
{
  UINT8 ZeroVector[16];
  EFI_GUID FileSystemGuid;
  UINT64 FvLength;
  UINT32 Signature;
  EFI_FVB_ATTRIBUTES_2 Attributes;
  UINT16 HeaderLength;
  UINT16 Checksum;
  UINT16 ExtHeaderOffset;
  UINT8 Reserved[1];
  UINT8 Revision;
  EFI_FV_BLOCK_MAP_ENTRY BlockMap[1];
} EFI_FIRMWARE_VOLUME_HEADER;
typedef struct 
{
  EFI_GUID FvName;
  UINT32 ExtHeaderSize;
} EFI_FIRMWARE_VOLUME_EXT_HEADER;
typedef struct 
{
  UINT16 ExtEntrySize;
  UINT16 ExtEntryType;
} EFI_FIRMWARE_VOLUME_EXT_ENTRY;
typedef struct 
{
  EFI_FIRMWARE_VOLUME_EXT_ENTRY Hdr;
  UINT32 TypeMask;
} EFI_FIRMWARE_VOLUME_EXT_ENTRY_OEM_TYPE;
typedef struct 
{
  EFI_FIRMWARE_VOLUME_EXT_ENTRY Hdr;
  EFI_GUID FormatType;
} EFI_FIRMWARE_VOLUME_EXT_ENTRY_GUID_TYPE;
typedef struct 
{
  EFI_FIRMWARE_VOLUME_EXT_ENTRY Hdr;
  UINT32 UsedSize;
} EFI_FIRMWARE_VOLUME_EXT_ENTRY_USED_SIZE_TYPE;
#pragma pack(1)
typedef union 
{
  struct 
  {
    UINT8 Header;
    UINT8 File;
  } Checksum;
  UINT16 Checksum16;
} EFI_FFS_INTEGRITY_CHECK;
typedef UINT8 EFI_FV_FILETYPE;
typedef UINT8 EFI_FFS_FILE_ATTRIBUTES;
typedef UINT8 EFI_FFS_FILE_STATE;
typedef struct 
{
  EFI_GUID Name;
  EFI_FFS_INTEGRITY_CHECK IntegrityCheck;
  EFI_FV_FILETYPE Type;
  EFI_FFS_FILE_ATTRIBUTES Attributes;
  UINT8 Size[3];
  EFI_FFS_FILE_STATE State;
} EFI_FFS_FILE_HEADER;
typedef struct 
{
  EFI_GUID Name;
  EFI_FFS_INTEGRITY_CHECK IntegrityCheck;
  EFI_FV_FILETYPE Type;
  EFI_FFS_FILE_ATTRIBUTES Attributes;
  UINT8 Size[3];
  EFI_FFS_FILE_STATE State;
  UINT64 ExtendedSize;
} EFI_FFS_FILE_HEADER2;
typedef UINT8 EFI_SECTION_TYPE;
typedef struct 
{
  UINT8 Size[3];
  EFI_SECTION_TYPE Type;
} EFI_COMMON_SECTION_HEADER;
typedef struct 
{
  UINT8 Size[3];
  EFI_SECTION_TYPE Type;
  UINT32 ExtendedSize;
} EFI_COMMON_SECTION_HEADER2;
typedef EFI_COMMON_SECTION_HEADER EFI_COMPATIBILITY16_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_COMPATIBILITY16_SECTION2;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER CommonHeader;
  UINT32 UncompressedLength;
  UINT8 CompressionType;
} EFI_COMPRESSION_SECTION;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER2 CommonHeader;
  UINT32 UncompressedLength;
  UINT8 CompressionType;
} EFI_COMPRESSION_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_DISPOSABLE_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_DISPOSABLE_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_DXE_DEPEX_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_DXE_DEPEX_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_FIRMWARE_VOLUME_IMAGE_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_FIRMWARE_VOLUME_IMAGE_SECTION2;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER CommonHeader;
  EFI_GUID SubTypeGuid;
} EFI_FREEFORM_SUBTYPE_GUID_SECTION;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER2 CommonHeader;
  EFI_GUID SubTypeGuid;
} EFI_FREEFORM_SUBTYPE_GUID_SECTION2;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER CommonHeader;
  EFI_GUID SectionDefinitionGuid;
  UINT16 DataOffset;
  UINT16 Attributes;
} EFI_GUID_DEFINED_SECTION;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER2 CommonHeader;
  EFI_GUID SectionDefinitionGuid;
  UINT16 DataOffset;
  UINT16 Attributes;
} EFI_GUID_DEFINED_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_PE32_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_PE32_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_PEI_DEPEX_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_PEI_DEPEX_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_PIC_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_PIC_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_TE_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_TE_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_RAW_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_RAW_SECTION2;
typedef EFI_COMMON_SECTION_HEADER EFI_SMM_DEPEX_SECTION;
typedef EFI_COMMON_SECTION_HEADER2 EFI_SMM_DEPEX_SECTION2;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER CommonHeader;
  CHAR16 FileNameString[1];
} EFI_USER_INTERFACE_SECTION;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER2 CommonHeader;
  CHAR16 FileNameString[1];
} EFI_USER_INTERFACE_SECTION2;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER CommonHeader;
  UINT16 BuildNumber;
  CHAR16 VersionString[1];
} EFI_VERSION_SECTION;
typedef struct 
{
  EFI_COMMON_SECTION_HEADER2 CommonHeader;
  UINT16 BuildNumber;
  CHAR16 VersionString[1];
} EFI_VERSION_SECTION2;
#pragma pack()
typedef UINT32 EFI_BOOT_MODE;
typedef struct 
{
  UINT16 HobType;
  UINT16 HobLength;
  UINT32 Reserved;
} EFI_HOB_GENERIC_HEADER;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  UINT32 Version;
  EFI_BOOT_MODE BootMode;
  EFI_PHYSICAL_ADDRESS EfiMemoryTop;
  EFI_PHYSICAL_ADDRESS EfiMemoryBottom;
  EFI_PHYSICAL_ADDRESS EfiFreeMemoryTop;
  EFI_PHYSICAL_ADDRESS EfiFreeMemoryBottom;
  EFI_PHYSICAL_ADDRESS EfiEndOfHobList;
} EFI_HOB_HANDOFF_INFO_TABLE;
typedef struct 
{
  EFI_GUID Name;
  EFI_PHYSICAL_ADDRESS MemoryBaseAddress;
  UINT64 MemoryLength;
  EFI_MEMORY_TYPE MemoryType;
  UINT8 Reserved[4];
} EFI_HOB_MEMORY_ALLOCATION_HEADER;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_HOB_MEMORY_ALLOCATION_HEADER AllocDescriptor;
} EFI_HOB_MEMORY_ALLOCATION;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_HOB_MEMORY_ALLOCATION_HEADER AllocDescriptor;
} EFI_HOB_MEMORY_ALLOCATION_STACK;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_HOB_MEMORY_ALLOCATION_HEADER AllocDescriptor;
} EFI_HOB_MEMORY_ALLOCATION_BSP_STORE;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_HOB_MEMORY_ALLOCATION_HEADER MemoryAllocationHeader;
  EFI_GUID ModuleName;
  EFI_PHYSICAL_ADDRESS EntryPoint;
} EFI_HOB_MEMORY_ALLOCATION_MODULE;
typedef UINT32 EFI_RESOURCE_TYPE;
typedef UINT32 EFI_RESOURCE_ATTRIBUTE_TYPE;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_GUID Owner;
  EFI_RESOURCE_TYPE ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE ResourceAttribute;
  EFI_PHYSICAL_ADDRESS PhysicalStart;
  UINT64 ResourceLength;
} EFI_HOB_RESOURCE_DESCRIPTOR;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_GUID Name;
} EFI_HOB_GUID_TYPE;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_PHYSICAL_ADDRESS BaseAddress;
  UINT64 Length;
} EFI_HOB_FIRMWARE_VOLUME;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_PHYSICAL_ADDRESS BaseAddress;
  UINT64 Length;
  EFI_GUID FvName;
  EFI_GUID FileName;
} EFI_HOB_FIRMWARE_VOLUME2;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_PHYSICAL_ADDRESS BaseAddress;
  UINT64 Length;
  UINT32 AuthenticationStatus;
  BOOLEAN ExtractedFv;
  EFI_GUID FvName;
  EFI_GUID FileName;
} EFI_HOB_FIRMWARE_VOLUME3;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  UINT8 SizeOfMemorySpace;
  UINT8 SizeOfIoSpace;
  UINT8 Reserved[6];
} EFI_HOB_CPU;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
} EFI_HOB_MEMORY_POOL;
typedef struct 
{
  EFI_HOB_GENERIC_HEADER Header;
  EFI_PHYSICAL_ADDRESS BaseAddress;
  UINT64 Length;
} EFI_HOB_UEFI_CAPSULE;
typedef union 
{
  EFI_HOB_GENERIC_HEADER *Header;
  EFI_HOB_HANDOFF_INFO_TABLE *HandoffInformationTable;
  EFI_HOB_MEMORY_ALLOCATION *MemoryAllocation;
  EFI_HOB_MEMORY_ALLOCATION_BSP_STORE *MemoryAllocationBspStore;
  EFI_HOB_MEMORY_ALLOCATION_STACK *MemoryAllocationStack;
  EFI_HOB_MEMORY_ALLOCATION_MODULE *MemoryAllocationModule;
  EFI_HOB_RESOURCE_DESCRIPTOR *ResourceDescriptor;
  EFI_HOB_GUID_TYPE *Guid;
  EFI_HOB_FIRMWARE_VOLUME *FirmwareVolume;
  EFI_HOB_FIRMWARE_VOLUME2 *FirmwareVolume2;
  EFI_HOB_FIRMWARE_VOLUME3 *FirmwareVolume3;
  EFI_HOB_CPU *Cpu;
  EFI_HOB_MEMORY_POOL *Pool;
  EFI_HOB_UEFI_CAPSULE *Capsule;
  UINT8 *Raw;
} EFI_PEI_HOB_POINTERS;
typedef struct 
{
  UINT16 e_magic;
  UINT16 e_cblp;
  UINT16 e_cp;
  UINT16 e_crlc;
  UINT16 e_cparhdr;
  UINT16 e_minalloc;
  UINT16 e_maxalloc;
  UINT16 e_ss;
  UINT16 e_sp;
  UINT16 e_csum;
  UINT16 e_ip;
  UINT16 e_cs;
  UINT16 e_lfarlc;
  UINT16 e_ovno;
  UINT16 e_res[4];
  UINT16 e_oemid;
  UINT16 e_oeminfo;
  UINT16 e_res2[10];
  UINT32 e_lfanew;
} EFI_IMAGE_DOS_HEADER;
typedef struct 
{
  UINT16 Machine;
  UINT16 NumberOfSections;
  UINT32 TimeDateStamp;
  UINT32 PointerToSymbolTable;
  UINT32 NumberOfSymbols;
  UINT16 SizeOfOptionalHeader;
  UINT16 Characteristics;
} EFI_IMAGE_FILE_HEADER;
typedef struct 
{
  UINT32 VirtualAddress;
  UINT32 Size;
} EFI_IMAGE_DATA_DIRECTORY;
typedef struct 
{
  UINT16 Magic;
  UINT8 MajorLinkerVersion;
  UINT8 MinorLinkerVersion;
  UINT32 SizeOfCode;
  UINT32 SizeOfInitializedData;
  UINT32 SizeOfUninitializedData;
  UINT32 AddressOfEntryPoint;
  UINT32 BaseOfCode;
  UINT32 BaseOfData;
  UINT32 ImageBase;
  UINT32 SectionAlignment;
  UINT32 FileAlignment;
  UINT16 MajorOperatingSystemVersion;
  UINT16 MinorOperatingSystemVersion;
  UINT16 MajorImageVersion;
  UINT16 MinorImageVersion;
  UINT16 MajorSubsystemVersion;
  UINT16 MinorSubsystemVersion;
  UINT32 Win32VersionValue;
  UINT32 SizeOfImage;
  UINT32 SizeOfHeaders;
  UINT32 CheckSum;
  UINT16 Subsystem;
  UINT16 DllCharacteristics;
  UINT32 SizeOfStackReserve;
  UINT32 SizeOfStackCommit;
  UINT32 SizeOfHeapReserve;
  UINT32 SizeOfHeapCommit;
  UINT32 LoaderFlags;
  UINT32 NumberOfRvaAndSizes;
  EFI_IMAGE_DATA_DIRECTORY DataDirectory[16];
} EFI_IMAGE_OPTIONAL_HEADER32;
typedef struct 
{
  UINT16 Magic;
  UINT8 MajorLinkerVersion;
  UINT8 MinorLinkerVersion;
  UINT32 SizeOfCode;
  UINT32 SizeOfInitializedData;
  UINT32 SizeOfUninitializedData;
  UINT32 AddressOfEntryPoint;
  UINT32 BaseOfCode;
  UINT64 ImageBase;
  UINT32 SectionAlignment;
  UINT32 FileAlignment;
  UINT16 MajorOperatingSystemVersion;
  UINT16 MinorOperatingSystemVersion;
  UINT16 MajorImageVersion;
  UINT16 MinorImageVersion;
  UINT16 MajorSubsystemVersion;
  UINT16 MinorSubsystemVersion;
  UINT32 Win32VersionValue;
  UINT32 SizeOfImage;
  UINT32 SizeOfHeaders;
  UINT32 CheckSum;
  UINT16 Subsystem;
  UINT16 DllCharacteristics;
  UINT64 SizeOfStackReserve;
  UINT64 SizeOfStackCommit;
  UINT64 SizeOfHeapReserve;
  UINT64 SizeOfHeapCommit;
  UINT32 LoaderFlags;
  UINT32 NumberOfRvaAndSizes;
  EFI_IMAGE_DATA_DIRECTORY DataDirectory[16];
} EFI_IMAGE_OPTIONAL_HEADER64;
typedef struct 
{
  UINT32 Signature;
  EFI_IMAGE_FILE_HEADER FileHeader;
  EFI_IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} EFI_IMAGE_NT_HEADERS32;
typedef struct 
{
  UINT32 Signature;
  EFI_IMAGE_FILE_HEADER FileHeader;
  EFI_IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} EFI_IMAGE_NT_HEADERS64;
typedef struct 
{
  UINT8 Name[8];
  union 
  {
    UINT32 PhysicalAddress;
    UINT32 VirtualSize;
  } Misc;
  UINT32 VirtualAddress;
  UINT32 SizeOfRawData;
  UINT32 PointerToRawData;
  UINT32 PointerToRelocations;
  UINT32 PointerToLinenumbers;
  UINT16 NumberOfRelocations;
  UINT16 NumberOfLinenumbers;
  UINT32 Characteristics;
} EFI_IMAGE_SECTION_HEADER;
typedef struct 
{
  UINT32 VirtualAddress;
  UINT32 SymbolTableIndex;
  UINT16 Type;
} EFI_IMAGE_RELOCATION;
typedef struct 
{
  UINT32 VirtualAddress;
  UINT32 SizeOfBlock;
} EFI_IMAGE_BASE_RELOCATION;
typedef struct 
{
  union 
  {
    UINT32 SymbolTableIndex;
    UINT32 VirtualAddress;
  } Type;
  UINT16 Linenumber;
} EFI_IMAGE_LINENUMBER;
typedef struct 
{
  UINT8 Name[16];
  UINT8 Date[12];
  UINT8 UserID[6];
  UINT8 GroupID[6];
  UINT8 Mode[8];
  UINT8 Size[10];
  UINT8 EndHeader[2];
} EFI_IMAGE_ARCHIVE_MEMBER_HEADER;
typedef struct 
{
  UINT32 Characteristics;
  UINT32 TimeDateStamp;
  UINT16 MajorVersion;
  UINT16 MinorVersion;
  UINT32 Name;
  UINT32 Base;
  UINT32 NumberOfFunctions;
  UINT32 NumberOfNames;
  UINT32 AddressOfFunctions;
  UINT32 AddressOfNames;
  UINT32 AddressOfNameOrdinals;
} EFI_IMAGE_EXPORT_DIRECTORY;
typedef struct 
{
  UINT16 Hint;
  UINT8 Name[1];
} EFI_IMAGE_IMPORT_BY_NAME;
typedef struct 
{
  union 
  {
    UINT32 Function;
    UINT32 Ordinal;
    EFI_IMAGE_IMPORT_BY_NAME *AddressOfData;
  } u1;
} EFI_IMAGE_THUNK_DATA;
typedef struct 
{
  UINT32 Characteristics;
  UINT32 TimeDateStamp;
  UINT32 ForwarderChain;
  UINT32 Name;
  EFI_IMAGE_THUNK_DATA *FirstThunk;
} EFI_IMAGE_IMPORT_DESCRIPTOR;
typedef struct 
{
  UINT32 Characteristics;
  UINT32 TimeDateStamp;
  UINT16 MajorVersion;
  UINT16 MinorVersion;
  UINT32 Type;
  UINT32 SizeOfData;
  UINT32 RVA;
  UINT32 FileOffset;
} EFI_IMAGE_DEBUG_DIRECTORY_ENTRY;
typedef struct 
{
  UINT32 Signature;
  UINT32 Unknown;
  UINT32 Unknown2;
  UINT32 Unknown3;
} EFI_IMAGE_DEBUG_CODEVIEW_NB10_ENTRY;
typedef struct 
{
  UINT32 Signature;
  UINT32 Unknown;
  UINT32 Unknown2;
  UINT32 Unknown3;
  UINT32 Unknown4;
  UINT32 Unknown5;
} EFI_IMAGE_DEBUG_CODEVIEW_RSDS_ENTRY;
typedef struct 
{
  UINT32 Signature;
  GUID MachOUuid;
} EFI_IMAGE_DEBUG_CODEVIEW_MTOC_ENTRY;
typedef struct 
{
  UINT32 FunctionStartAddress;
  UINT32 FunctionEndAddress;
  UINT32 UnwindInfoAddress;
} RUNTIME_FUNCTION;
typedef struct 
{
  UINT8 Version : 3;
  UINT8 Flags : 5;
  UINT8 SizeOfProlog;
  UINT8 CountOfUnwindCodes;
  UINT8 FrameRegister : 4;
  UINT8 FrameRegisterOffset : 4;
} UNWIND_INFO;
typedef struct 
{
  UINT32 DllCharacteristicsEx;
} EFI_IMAGE_DEBUG_EX_DLLCHARACTERISTICS_ENTRY;
typedef struct 
{
  UINT32 Characteristics;
  UINT32 TimeDateStamp;
  UINT16 MajorVersion;
  UINT16 MinorVersion;
  UINT16 NumberOfNamedEntries;
  UINT16 NumberOfIdEntries;
} EFI_IMAGE_RESOURCE_DIRECTORY;
typedef struct 
{
  union 
  {
    struct 
    {
      UINT32 NameOffset : 31;
      UINT32 NameIsString : 1;
    } s;
    UINT32 Id;
  } u1;
  union 
  {
    UINT32 OffsetToData;
    struct 
    {
      UINT32 OffsetToDirectory : 31;
      UINT32 DataIsDirectory : 1;
    } s;
  } u2;
} EFI_IMAGE_RESOURCE_DIRECTORY_ENTRY;
typedef struct 
{
  UINT16 Length;
  CHAR16 String[1];
} EFI_IMAGE_RESOURCE_DIRECTORY_STRING;
typedef struct 
{
  UINT32 OffsetToData;
  UINT32 Size;
  UINT32 CodePage;
  UINT32 Reserved;
} EFI_IMAGE_RESOURCE_DATA_ENTRY;
typedef struct 
{
  UINT16 Signature;
  UINT16 Machine;
  UINT8 NumberOfSections;
  UINT8 Subsystem;
  UINT16 StrippedSize;
  UINT32 AddressOfEntryPoint;
  UINT32 BaseOfCode;
  UINT64 ImageBase;
  EFI_IMAGE_DATA_DIRECTORY DataDirectory[2];
} EFI_TE_IMAGE_HEADER;
typedef union 
{
  EFI_IMAGE_NT_HEADERS32 Pe32;
  EFI_IMAGE_NT_HEADERS64 Pe32Plus;
  EFI_TE_IMAGE_HEADER Te;
} EFI_IMAGE_OPTIONAL_HEADER_UNION;
typedef union 
{
  EFI_IMAGE_NT_HEADERS32 *Pe32;
  EFI_IMAGE_NT_HEADERS64 *Pe32Plus;
  EFI_TE_IMAGE_HEADER *Te;
  EFI_IMAGE_OPTIONAL_HEADER_UNION *Union;
} EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION;
typedef struct _EFI_DEBUG_SUPPORT_PROTOCOL EFI_DEBUG_SUPPORT_PROTOCOL;
typedef INTN EFI_EXCEPTION_TYPE;
typedef struct 
{
  UINT16 Fcw;
  UINT16 Fsw;
  UINT16 Ftw;
  UINT16 Opcode;
  UINT32 Eip;
  UINT16 Cs;
  UINT16 Reserved1;
  UINT32 DataOffset;
  UINT16 Ds;
  UINT8 Reserved2[10];
  UINT8 St0Mm0[10];
  UINT8 Reserved3[6];
  UINT8 St1Mm1[10];
  UINT8 Reserved4[6];
  UINT8 St2Mm2[10];
  UINT8 Reserved5[6];
  UINT8 St3Mm3[10];
  UINT8 Reserved6[6];
  UINT8 St4Mm4[10];
  UINT8 Reserved7[6];
  UINT8 St5Mm5[10];
  UINT8 Reserved8[6];
  UINT8 St6Mm6[10];
  UINT8 Reserved9[6];
  UINT8 St7Mm7[10];
  UINT8 Reserved10[6];
  UINT8 Xmm0[16];
  UINT8 Xmm1[16];
  UINT8 Xmm2[16];
  UINT8 Xmm3[16];
  UINT8 Xmm4[16];
  UINT8 Xmm5[16];
  UINT8 Xmm6[16];
  UINT8 Xmm7[16];
  UINT8 Reserved11[14 * 16];
} EFI_FX_SAVE_STATE_IA32;
typedef struct 
{
  UINT32 ExceptionData;
  EFI_FX_SAVE_STATE_IA32 FxSaveState;
  UINT32 Dr0;
  UINT32 Dr1;
  UINT32 Dr2;
  UINT32 Dr3;
  UINT32 Dr6;
  UINT32 Dr7;
  UINT32 Cr0;
  UINT32 Cr1;
  UINT32 Cr2;
  UINT32 Cr3;
  UINT32 Cr4;
  UINT32 Eflags;
  UINT32 Ldtr;
  UINT32 Tr;
  UINT32 Gdtr[2];
  UINT32 Idtr[2];
  UINT32 Eip;
  UINT32 Gs;
  UINT32 Fs;
  UINT32 Es;
  UINT32 Ds;
  UINT32 Cs;
  UINT32 Ss;
  UINT32 Edi;
  UINT32 Esi;
  UINT32 Ebp;
  UINT32 Esp;
  UINT32 Ebx;
  UINT32 Edx;
  UINT32 Ecx;
  UINT32 Eax;
} EFI_SYSTEM_CONTEXT_IA32;
typedef struct 
{
  UINT16 Fcw;
  UINT16 Fsw;
  UINT16 Ftw;
  UINT16 Opcode;
  UINT64 Rip;
  UINT64 DataOffset;
  UINT8 Reserved1[8];
  UINT8 St0Mm0[10];
  UINT8 Reserved2[6];
  UINT8 St1Mm1[10];
  UINT8 Reserved3[6];
  UINT8 St2Mm2[10];
  UINT8 Reserved4[6];
  UINT8 St3Mm3[10];
  UINT8 Reserved5[6];
  UINT8 St4Mm4[10];
  UINT8 Reserved6[6];
  UINT8 St5Mm5[10];
  UINT8 Reserved7[6];
  UINT8 St6Mm6[10];
  UINT8 Reserved8[6];
  UINT8 St7Mm7[10];
  UINT8 Reserved9[6];
  UINT8 Xmm0[16];
  UINT8 Xmm1[16];
  UINT8 Xmm2[16];
  UINT8 Xmm3[16];
  UINT8 Xmm4[16];
  UINT8 Xmm5[16];
  UINT8 Xmm6[16];
  UINT8 Xmm7[16];
  UINT8 Reserved11[14 * 16];
} EFI_FX_SAVE_STATE_X64;
typedef struct 
{
  UINT64 ExceptionData;
  EFI_FX_SAVE_STATE_X64 FxSaveState;
  UINT64 Dr0;
  UINT64 Dr1;
  UINT64 Dr2;
  UINT64 Dr3;
  UINT64 Dr6;
  UINT64 Dr7;
  UINT64 Cr0;
  UINT64 Cr1;
  UINT64 Cr2;
  UINT64 Cr3;
  UINT64 Cr4;
  UINT64 Cr8;
  UINT64 Rflags;
  UINT64 Ldtr;
  UINT64 Tr;
  UINT64 Gdtr[2];
  UINT64 Idtr[2];
  UINT64 Rip;
  UINT64 Gs;
  UINT64 Fs;
  UINT64 Es;
  UINT64 Ds;
  UINT64 Cs;
  UINT64 Ss;
  UINT64 Rdi;
  UINT64 Rsi;
  UINT64 Rbp;
  UINT64 Rsp;
  UINT64 Rbx;
  UINT64 Rdx;
  UINT64 Rcx;
  UINT64 Rax;
  UINT64 R8;
  UINT64 R9;
  UINT64 R10;
  UINT64 R11;
  UINT64 R12;
  UINT64 R13;
  UINT64 R14;
  UINT64 R15;
} EFI_SYSTEM_CONTEXT_X64;
typedef struct 
{
  UINT64 Reserved;
  UINT64 R1;
  UINT64 R2;
  UINT64 R3;
  UINT64 R4;
  UINT64 R5;
  UINT64 R6;
  UINT64 R7;
  UINT64 R8;
  UINT64 R9;
  UINT64 R10;
  UINT64 R11;
  UINT64 R12;
  UINT64 R13;
  UINT64 R14;
  UINT64 R15;
  UINT64 R16;
  UINT64 R17;
  UINT64 R18;
  UINT64 R19;
  UINT64 R20;
  UINT64 R21;
  UINT64 R22;
  UINT64 R23;
  UINT64 R24;
  UINT64 R25;
  UINT64 R26;
  UINT64 R27;
  UINT64 R28;
  UINT64 R29;
  UINT64 R30;
  UINT64 R31;
  UINT64 F2[2];
  UINT64 F3[2];
  UINT64 F4[2];
  UINT64 F5[2];
  UINT64 F6[2];
  UINT64 F7[2];
  UINT64 F8[2];
  UINT64 F9[2];
  UINT64 F10[2];
  UINT64 F11[2];
  UINT64 F12[2];
  UINT64 F13[2];
  UINT64 F14[2];
  UINT64 F15[2];
  UINT64 F16[2];
  UINT64 F17[2];
  UINT64 F18[2];
  UINT64 F19[2];
  UINT64 F20[2];
  UINT64 F21[2];
  UINT64 F22[2];
  UINT64 F23[2];
  UINT64 F24[2];
  UINT64 F25[2];
  UINT64 F26[2];
  UINT64 F27[2];
  UINT64 F28[2];
  UINT64 F29[2];
  UINT64 F30[2];
  UINT64 F31[2];
  UINT64 Pr;
  UINT64 B0;
  UINT64 B1;
  UINT64 B2;
  UINT64 B3;
  UINT64 B4;
  UINT64 B5;
  UINT64 B6;
  UINT64 B7;
  UINT64 ArRsc;
  UINT64 ArBsp;
  UINT64 ArBspstore;
  UINT64 ArRnat;
  UINT64 ArFcr;
  UINT64 ArEflag;
  UINT64 ArCsd;
  UINT64 ArSsd;
  UINT64 ArCflg;
  UINT64 ArFsr;
  UINT64 ArFir;
  UINT64 ArFdr;
  UINT64 ArCcv;
  UINT64 ArUnat;
  UINT64 ArFpsr;
  UINT64 ArPfs;
  UINT64 ArLc;
  UINT64 ArEc;
  UINT64 CrDcr;
  UINT64 CrItm;
  UINT64 CrIva;
  UINT64 CrPta;
  UINT64 CrIpsr;
  UINT64 CrIsr;
  UINT64 CrIip;
  UINT64 CrIfa;
  UINT64 CrItir;
  UINT64 CrIipa;
  UINT64 CrIfs;
  UINT64 CrIim;
  UINT64 CrIha;
  UINT64 Dbr0;
  UINT64 Dbr1;
  UINT64 Dbr2;
  UINT64 Dbr3;
  UINT64 Dbr4;
  UINT64 Dbr5;
  UINT64 Dbr6;
  UINT64 Dbr7;
  UINT64 Ibr0;
  UINT64 Ibr1;
  UINT64 Ibr2;
  UINT64 Ibr3;
  UINT64 Ibr4;
  UINT64 Ibr5;
  UINT64 Ibr6;
  UINT64 Ibr7;
  UINT64 IntNat;
} EFI_SYSTEM_CONTEXT_IPF;
typedef struct 
{
  UINT64 R0;
  UINT64 R1;
  UINT64 R2;
  UINT64 R3;
  UINT64 R4;
  UINT64 R5;
  UINT64 R6;
  UINT64 R7;
  UINT64 Flags;
  UINT64 ControlFlags;
  UINT64 Ip;
} EFI_SYSTEM_CONTEXT_EBC;
typedef struct 
{
  UINT32 R0;
  UINT32 R1;
  UINT32 R2;
  UINT32 R3;
  UINT32 R4;
  UINT32 R5;
  UINT32 R6;
  UINT32 R7;
  UINT32 R8;
  UINT32 R9;
  UINT32 R10;
  UINT32 R11;
  UINT32 R12;
  UINT32 SP;
  UINT32 LR;
  UINT32 PC;
  UINT32 CPSR;
  UINT32 DFSR;
  UINT32 DFAR;
  UINT32 IFSR;
  UINT32 IFAR;
} EFI_SYSTEM_CONTEXT_ARM;
typedef struct 
{
  UINT64 X0;
  UINT64 X1;
  UINT64 X2;
  UINT64 X3;
  UINT64 X4;
  UINT64 X5;
  UINT64 X6;
  UINT64 X7;
  UINT64 X8;
  UINT64 X9;
  UINT64 X10;
  UINT64 X11;
  UINT64 X12;
  UINT64 X13;
  UINT64 X14;
  UINT64 X15;
  UINT64 X16;
  UINT64 X17;
  UINT64 X18;
  UINT64 X19;
  UINT64 X20;
  UINT64 X21;
  UINT64 X22;
  UINT64 X23;
  UINT64 X24;
  UINT64 X25;
  UINT64 X26;
  UINT64 X27;
  UINT64 X28;
  UINT64 FP;
  UINT64 LR;
  UINT64 SP;
  UINT64 V0[2];
  UINT64 V1[2];
  UINT64 V2[2];
  UINT64 V3[2];
  UINT64 V4[2];
  UINT64 V5[2];
  UINT64 V6[2];
  UINT64 V7[2];
  UINT64 V8[2];
  UINT64 V9[2];
  UINT64 V10[2];
  UINT64 V11[2];
  UINT64 V12[2];
  UINT64 V13[2];
  UINT64 V14[2];
  UINT64 V15[2];
  UINT64 V16[2];
  UINT64 V17[2];
  UINT64 V18[2];
  UINT64 V19[2];
  UINT64 V20[2];
  UINT64 V21[2];
  UINT64 V22[2];
  UINT64 V23[2];
  UINT64 V24[2];
  UINT64 V25[2];
  UINT64 V26[2];
  UINT64 V27[2];
  UINT64 V28[2];
  UINT64 V29[2];
  UINT64 V30[2];
  UINT64 V31[2];
  UINT64 ELR;
  UINT64 SPSR;
  UINT64 FPSR;
  UINT64 ESR;
  UINT64 FAR;
} EFI_SYSTEM_CONTEXT_AARCH64;
typedef struct 
{
  UINT64 X0;
  UINT64 X1;
  UINT64 X2;
  UINT64 X3;
  UINT64 X4;
  UINT64 X5;
  UINT64 X6;
  UINT64 X7;
  UINT64 X8;
  UINT64 X9;
  UINT64 X10;
  UINT64 X11;
  UINT64 X12;
  UINT64 X13;
  UINT64 X14;
  UINT64 X15;
  UINT64 X16;
  UINT64 X17;
  UINT64 X18;
  UINT64 X19;
  UINT64 X20;
  UINT64 X21;
  UINT64 X22;
  UINT64 X23;
  UINT64 X24;
  UINT64 X25;
  UINT64 X26;
  UINT64 X27;
  UINT64 X28;
  UINT64 X29;
  UINT64 X30;
  UINT64 X31;
  UINT64 SEPC;
  UINT32 SSTATUS;
  UINT32 STVAL;
} EFI_SYSTEM_CONTEXT_RISCV64;
typedef struct 
{
  UINT64 R0;
  UINT64 R1;
  UINT64 R2;
  UINT64 R3;
  UINT64 R4;
  UINT64 R5;
  UINT64 R6;
  UINT64 R7;
  UINT64 R8;
  UINT64 R9;
  UINT64 R10;
  UINT64 R11;
  UINT64 R12;
  UINT64 R13;
  UINT64 R14;
  UINT64 R15;
  UINT64 R16;
  UINT64 R17;
  UINT64 R18;
  UINT64 R19;
  UINT64 R20;
  UINT64 R21;
  UINT64 R22;
  UINT64 R23;
  UINT64 R24;
  UINT64 R25;
  UINT64 R26;
  UINT64 R27;
  UINT64 R28;
  UINT64 R29;
  UINT64 R30;
  UINT64 R31;
  UINT64 CRMD;
  UINT64 PRMD;
  UINT64 EUEN;
  UINT64 MISC;
  UINT64 ECFG;
  UINT64 ESTAT;
  UINT64 ERA;
  UINT64 BADV;
  UINT64 BADI;
} EFI_SYSTEM_CONTEXT_LOONGARCH64;
typedef union 
{
  EFI_SYSTEM_CONTEXT_EBC *SystemContextEbc;
  EFI_SYSTEM_CONTEXT_IA32 *SystemContextIa32;
  EFI_SYSTEM_CONTEXT_X64 *SystemContextX64;
  EFI_SYSTEM_CONTEXT_IPF *SystemContextIpf;
  EFI_SYSTEM_CONTEXT_ARM *SystemContextArm;
  EFI_SYSTEM_CONTEXT_AARCH64 *SystemContextAArch64;
  EFI_SYSTEM_CONTEXT_RISCV64 *SystemContextRiscV64;
  EFI_SYSTEM_CONTEXT_LOONGARCH64 *SystemContextLoongArch64;
} EFI_SYSTEM_CONTEXT;
typedef void (*EFI_EXCEPTION_CALLBACK)(EFI_EXCEPTION_TYPE ExceptionType, EFI_SYSTEM_CONTEXT SystemContext);
typedef void (*EFI_PERIODIC_CALLBACK)(EFI_SYSTEM_CONTEXT SystemContext);
typedef enum 
{
  IsaIa32 = 0x014c,
  IsaX64 = 0x8664,
  IsaIpf = 0x0200,
  IsaEbc = 0x0EBC,
  IsaArm = 0x01c2,
  IsaAArch64 = 0xAA64
} EFI_INSTRUCTION_SET_ARCHITECTURE;
typedef EFI_STATUS (*EFI_GET_MAXIMUM_PROCESSOR_INDEX)(EFI_DEBUG_SUPPORT_PROTOCOL *This, UINTN *MaxProcessorIndex);
typedef EFI_STATUS (*EFI_REGISTER_PERIODIC_CALLBACK)(EFI_DEBUG_SUPPORT_PROTOCOL *This, UINTN ProcessorIndex, EFI_PERIODIC_CALLBACK PeriodicCallback);
typedef EFI_STATUS (*EFI_REGISTER_EXCEPTION_CALLBACK)(EFI_DEBUG_SUPPORT_PROTOCOL *This, UINTN ProcessorIndex, EFI_EXCEPTION_CALLBACK ExceptionCallback, EFI_EXCEPTION_TYPE ExceptionType);
typedef EFI_STATUS (*EFI_INVALIDATE_INSTRUCTION_CACHE)(EFI_DEBUG_SUPPORT_PROTOCOL *This, UINTN ProcessorIndex, void *Start, UINT64 Length);
struct _EFI_DEBUG_SUPPORT_PROTOCOL
{
  EFI_INSTRUCTION_SET_ARCHITECTURE Isa;
  EFI_GET_MAXIMUM_PROCESSOR_INDEX GetMaximumProcessorIndex;
  EFI_REGISTER_PERIODIC_CALLBACK RegisterPeriodicCallback;
  EFI_REGISTER_EXCEPTION_CALLBACK RegisterExceptionCallback;
  EFI_INVALIDATE_INSTRUCTION_CACHE InvalidateInstructionCache;
};
extern EFI_GUID gEfiDebugSupportProtocolGuid;
typedef UINT32 EFI_STATUS_CODE_TYPE;
typedef UINT32 EFI_STATUS_CODE_VALUE;
typedef struct 
{
  UINT16 HeaderSize;
  UINT16 Size;
  EFI_GUID Type;
} EFI_STATUS_CODE_DATA;
typedef enum 
{
  EfiBootScriptWidthUint8,
  EfiBootScriptWidthUint16,
  EfiBootScriptWidthUint32,
  EfiBootScriptWidthUint64,
  EfiBootScriptWidthFifoUint8,
  EfiBootScriptWidthFifoUint16,
  EfiBootScriptWidthFifoUint32,
  EfiBootScriptWidthFifoUint64,
  EfiBootScriptWidthFillUint8,
  EfiBootScriptWidthFillUint16,
  EfiBootScriptWidthFillUint32,
  EfiBootScriptWidthFillUint64,
  EfiBootScriptWidthMaximum
} EFI_BOOT_SCRIPT_WIDTH;
typedef struct 
{
  EFI_PHYSICAL_ADDRESS PhysicalStart;
  EFI_PHYSICAL_ADDRESS CpuStart;
  UINT64 PhysicalSize;
  UINT64 RegionState;
} EFI_MMRAM_DESCRIPTOR;
typedef EFI_MMRAM_DESCRIPTOR EFI_SMRAM_DESCRIPTOR;
typedef struct _EFI_MM_RESERVED_MMRAM_REGION
{
  EFI_PHYSICAL_ADDRESS MmramReservedStart;
  UINT64 MmramReservedSize;
} EFI_MM_RESERVED_MMRAM_REGION;
typedef enum 
{
  EFI_PCD_TYPE_8,
  EFI_PCD_TYPE_16,
  EFI_PCD_TYPE_32,
  EFI_PCD_TYPE_64,
  EFI_PCD_TYPE_BOOL,
  EFI_PCD_TYPE_PTR
} EFI_PCD_TYPE;
typedef struct 
{
  EFI_PCD_TYPE PcdType;
  UINTN PcdSize;
  CHAR8 *PcdName;
} EFI_PCD_INFO;
typedef void (*EFI_AP_PROCEDURE)(void *Buffer);
typedef EFI_STATUS (*EFI_AP_PROCEDURE2)(void *ProcedureArgument);
typedef void *EFI_PEI_FV_HANDLE;
typedef void *EFI_PEI_FILE_HANDLE;
typedef struct _EFI_PEI_SERVICES EFI_PEI_SERVICES;
typedef struct _EFI_PEI_NOTIFY_DESCRIPTOR EFI_PEI_NOTIFY_DESCRIPTOR;
typedef struct _EFI_PEI_CPU_IO_PPI EFI_PEI_CPU_IO_PPI;
typedef enum 
{
  EfiPeiCpuIoWidthUint8,
  EfiPeiCpuIoWidthUint16,
  EfiPeiCpuIoWidthUint32,
  EfiPeiCpuIoWidthUint64,
  EfiPeiCpuIoWidthFifoUint8,
  EfiPeiCpuIoWidthFifoUint16,
  EfiPeiCpuIoWidthFifoUint32,
  EfiPeiCpuIoWidthFifoUint64,
  EfiPeiCpuIoWidthFillUint8,
  EfiPeiCpuIoWidthFillUint16,
  EfiPeiCpuIoWidthFillUint32,
  EfiPeiCpuIoWidthFillUint64,
  EfiPeiCpuIoWidthMaximum
} EFI_PEI_CPU_IO_PPI_WIDTH;
typedef EFI_STATUS (*EFI_PEI_CPU_IO_PPI_IO_MEM)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, EFI_PEI_CPU_IO_PPI_WIDTH Width, UINT64 Address, UINTN Count, void *Buffer);
typedef struct 
{
  EFI_PEI_CPU_IO_PPI_IO_MEM Read;
  EFI_PEI_CPU_IO_PPI_IO_MEM Write;
} EFI_PEI_CPU_IO_PPI_ACCESS;
typedef UINT8 (*EFI_PEI_CPU_IO_PPI_IO_READ8)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef UINT16 (*EFI_PEI_CPU_IO_PPI_IO_READ16)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef UINT32 (*EFI_PEI_CPU_IO_PPI_IO_READ32)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef UINT64 (*EFI_PEI_CPU_IO_PPI_IO_READ64)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef void (*EFI_PEI_CPU_IO_PPI_IO_WRITE8)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT8 Data);
typedef void (*EFI_PEI_CPU_IO_PPI_IO_WRITE16)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT16 Data);
typedef void (*EFI_PEI_CPU_IO_PPI_IO_WRITE32)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT32 Data);
typedef void (*EFI_PEI_CPU_IO_PPI_IO_WRITE64)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT64 Data);
typedef UINT8 (*EFI_PEI_CPU_IO_PPI_MEM_READ8)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef UINT16 (*EFI_PEI_CPU_IO_PPI_MEM_READ16)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef UINT32 (*EFI_PEI_CPU_IO_PPI_MEM_READ32)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef UINT64 (*EFI_PEI_CPU_IO_PPI_MEM_READ64)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address);
typedef void (*EFI_PEI_CPU_IO_PPI_MEM_WRITE8)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT8 Data);
typedef void (*EFI_PEI_CPU_IO_PPI_MEM_WRITE16)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT16 Data);
typedef void (*EFI_PEI_CPU_IO_PPI_MEM_WRITE32)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT32 Data);
typedef void (*EFI_PEI_CPU_IO_PPI_MEM_WRITE64)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_CPU_IO_PPI *This, UINT64 Address, UINT64 Data);
struct _EFI_PEI_CPU_IO_PPI
{
  EFI_PEI_CPU_IO_PPI_ACCESS Mem;
  EFI_PEI_CPU_IO_PPI_ACCESS Io;
  EFI_PEI_CPU_IO_PPI_IO_READ8 IoRead8;
  EFI_PEI_CPU_IO_PPI_IO_READ16 IoRead16;
  EFI_PEI_CPU_IO_PPI_IO_READ32 IoRead32;
  EFI_PEI_CPU_IO_PPI_IO_READ64 IoRead64;
  EFI_PEI_CPU_IO_PPI_IO_WRITE8 IoWrite8;
  EFI_PEI_CPU_IO_PPI_IO_WRITE16 IoWrite16;
  EFI_PEI_CPU_IO_PPI_IO_WRITE32 IoWrite32;
  EFI_PEI_CPU_IO_PPI_IO_WRITE64 IoWrite64;
  EFI_PEI_CPU_IO_PPI_MEM_READ8 MemRead8;
  EFI_PEI_CPU_IO_PPI_MEM_READ16 MemRead16;
  EFI_PEI_CPU_IO_PPI_MEM_READ32 MemRead32;
  EFI_PEI_CPU_IO_PPI_MEM_READ64 MemRead64;
  EFI_PEI_CPU_IO_PPI_MEM_WRITE8 MemWrite8;
  EFI_PEI_CPU_IO_PPI_MEM_WRITE16 MemWrite16;
  EFI_PEI_CPU_IO_PPI_MEM_WRITE32 MemWrite32;
  EFI_PEI_CPU_IO_PPI_MEM_WRITE64 MemWrite64;
};
extern EFI_GUID gEfiPeiCpuIoPpiInstalledGuid;
typedef struct 
{
  UINT64 Rbx;
  UINT64 Rsp;
  UINT64 Rbp;
  UINT64 Rdi;
  UINT64 Rsi;
  UINT64 R12;
  UINT64 R13;
  UINT64 R14;
  UINT64 R15;
  UINT64 Rip;
  UINT64 MxCsr;
  UINT8 XmmBuffer[160];
  UINT64 Ssp;
} BASE_LIBRARY_JUMP_BUFFER;
UINTN StrnLenS(const CHAR16 *String, UINTN MaxSize);
UINTN StrnSizeS(const CHAR16 *String, UINTN MaxSize);
RETURN_STATUS StrCpyS(CHAR16 *Destination, UINTN DestMax, const CHAR16 *Source);
RETURN_STATUS StrnCpyS(CHAR16 *Destination, UINTN DestMax, const CHAR16 *Source, UINTN Length);
RETURN_STATUS StrCatS(CHAR16 *Destination, UINTN DestMax, const CHAR16 *Source);
RETURN_STATUS StrnCatS(CHAR16 *Destination, UINTN DestMax, const CHAR16 *Source, UINTN Length);
RETURN_STATUS StrDecimalToUintnS(const CHAR16 *String, CHAR16 **EndPointer, UINTN *Data);
RETURN_STATUS StrDecimalToUint64S(const CHAR16 *String, CHAR16 **EndPointer, UINT64 *Data);
RETURN_STATUS StrHexToUintnS(const CHAR16 *String, CHAR16 **EndPointer, UINTN *Data);
RETURN_STATUS StrHexToUint64S(const CHAR16 *String, CHAR16 **EndPointer, UINT64 *Data);
UINTN AsciiStrnLenS(const CHAR8 *String, UINTN MaxSize);
UINTN AsciiStrnSizeS(const CHAR8 *String, UINTN MaxSize);
RETURN_STATUS AsciiStrCpyS(CHAR8 *Destination, UINTN DestMax, const CHAR8 *Source);
RETURN_STATUS AsciiStrnCpyS(CHAR8 *Destination, UINTN DestMax, const CHAR8 *Source, UINTN Length);
RETURN_STATUS AsciiStrCatS(CHAR8 *Destination, UINTN DestMax, const CHAR8 *Source);
RETURN_STATUS AsciiStrnCatS(CHAR8 *Destination, UINTN DestMax, const CHAR8 *Source, UINTN Length);
RETURN_STATUS AsciiStrDecimalToUintnS(const CHAR8 *String, CHAR8 **EndPointer, UINTN *Data);
RETURN_STATUS AsciiStrDecimalToUint64S(const CHAR8 *String, CHAR8 **EndPointer, UINT64 *Data);
RETURN_STATUS AsciiStrHexToUintnS(const CHAR8 *String, CHAR8 **EndPointer, UINTN *Data);
RETURN_STATUS AsciiStrHexToUint64S(const CHAR8 *String, CHAR8 **EndPointer, UINT64 *Data);
UINTN StrLen(const CHAR16 *String);
UINTN StrSize(const CHAR16 *String);
INTN StrCmp(const CHAR16 *FirstString, const CHAR16 *SecondString);
INTN StrnCmp(const CHAR16 *FirstString, const CHAR16 *SecondString, UINTN Length);
CHAR16 *StrStr(const CHAR16 *String, const CHAR16 *SearchString);
UINTN StrDecimalToUintn(const CHAR16 *String);
UINT64 StrDecimalToUint64(const CHAR16 *String);
UINTN StrHexToUintn(const CHAR16 *String);
UINT64 StrHexToUint64(const CHAR16 *String);
RETURN_STATUS StrToIpv6Address(const CHAR16 *String, CHAR16 **EndPointer, IPv6_ADDRESS *Address, UINT8 *PrefixLength);
RETURN_STATUS StrToIpv4Address(const CHAR16 *String, CHAR16 **EndPointer, IPv4_ADDRESS *Address, UINT8 *PrefixLength);
RETURN_STATUS StrToGuid(const CHAR16 *String, GUID *Guid);
RETURN_STATUS StrHexToBytes(const CHAR16 *String, UINTN Length, UINT8 *Buffer, UINTN MaxBufferSize);
RETURN_STATUS UnicodeStrToAsciiStrS(const CHAR16 *Source, CHAR8 *Destination, UINTN DestMax);
RETURN_STATUS UnicodeStrnToAsciiStrS(const CHAR16 *Source, UINTN Length, CHAR8 *Destination, UINTN DestMax, UINTN *DestinationLength);
UINTN AsciiStrLen(const CHAR8 *String);
UINTN AsciiStrSize(const CHAR8 *String);
INTN AsciiStrCmp(const CHAR8 *FirstString, const CHAR8 *SecondString);
INTN AsciiStriCmp(const CHAR8 *FirstString, const CHAR8 *SecondString);
INTN AsciiStrnCmp(const CHAR8 *FirstString, const CHAR8 *SecondString, UINTN Length);
CHAR8 *AsciiStrStr(const CHAR8 *String, const CHAR8 *SearchString);
UINTN AsciiStrDecimalToUintn(const CHAR8 *String);
UINT64 AsciiStrDecimalToUint64(const CHAR8 *String);
UINTN AsciiStrHexToUintn(const CHAR8 *String);
UINT64 AsciiStrHexToUint64(const CHAR8 *String);
RETURN_STATUS AsciiStrToIpv6Address(const CHAR8 *String, CHAR8 **EndPointer, IPv6_ADDRESS *Address, UINT8 *PrefixLength);
RETURN_STATUS AsciiStrToIpv4Address(const CHAR8 *String, CHAR8 **EndPointer, IPv4_ADDRESS *Address, UINT8 *PrefixLength);
RETURN_STATUS AsciiStrToGuid(const CHAR8 *String, GUID *Guid);
RETURN_STATUS AsciiStrHexToBytes(const CHAR8 *String, UINTN Length, UINT8 *Buffer, UINTN MaxBufferSize);
RETURN_STATUS AsciiStrToUnicodeStrS(const CHAR8 *Source, CHAR16 *Destination, UINTN DestMax);
RETURN_STATUS AsciiStrnToUnicodeStrS(const CHAR8 *Source, UINTN Length, CHAR16 *Destination, UINTN DestMax, UINTN *DestinationLength);
CHAR16 CharToUpper(CHAR16 Char);
CHAR8 AsciiCharToUpper(CHAR8 Chr);
RETURN_STATUS Base64Encode(const UINT8 *Source, UINTN SourceLength, CHAR8 *Destination, UINTN *DestinationSize);
RETURN_STATUS Base64Decode(const CHAR8 *Source, UINTN SourceSize, UINT8 *Destination, UINTN *DestinationSize);
UINT8 DecimalToBcd8(UINT8 Value);
UINT8 BcdToDecimal8(UINT8 Value);
BOOLEAN PathRemoveLastItem(CHAR16 *Path);
CHAR16 *PathCleanUpDirectories(CHAR16 *Path);
BOOLEAN IsNodeInList(const LIST_ENTRY *FirstEntry, const LIST_ENTRY *SecondEntry);
LIST_ENTRY *InitializeListHead(LIST_ENTRY *ListHead);
LIST_ENTRY *InsertHeadList(LIST_ENTRY *ListHead, LIST_ENTRY *Entry);
LIST_ENTRY *InsertTailList(LIST_ENTRY *ListHead, LIST_ENTRY *Entry);
LIST_ENTRY *GetFirstNode(const LIST_ENTRY *List);
LIST_ENTRY *GetNextNode(const LIST_ENTRY *List, const LIST_ENTRY *Node);
LIST_ENTRY *GetPreviousNode(const LIST_ENTRY *List, const LIST_ENTRY *Node);
BOOLEAN IsListEmpty(const LIST_ENTRY *ListHead);
BOOLEAN IsNull(const LIST_ENTRY *List, const LIST_ENTRY *Node);
BOOLEAN IsNodeAtEnd(const LIST_ENTRY *List, const LIST_ENTRY *Node);
LIST_ENTRY *SwapListEntries(LIST_ENTRY *FirstEntry, LIST_ENTRY *SecondEntry);
LIST_ENTRY *RemoveEntryList(const LIST_ENTRY *Entry);
typedef INTN (*BASE_SORT_COMPARE)(const void *Buffer1, const void *Buffer2);
void QuickSort(void *BufferToSort, const UINTN Count, const UINTN ElementSize, BASE_SORT_COMPARE CompareFunction, void *BufferOneElement);
UINT64 LShiftU64(UINT64 Operand, UINTN Count);
UINT64 RShiftU64(UINT64 Operand, UINTN Count);
UINT64 ARShiftU64(UINT64 Operand, UINTN Count);
UINT32 LRotU32(UINT32 Operand, UINTN Count);
UINT32 RRotU32(UINT32 Operand, UINTN Count);
UINT64 LRotU64(UINT64 Operand, UINTN Count);
UINT64 RRotU64(UINT64 Operand, UINTN Count);
INTN LowBitSet32(UINT32 Operand);
INTN LowBitSet64(UINT64 Operand);
INTN HighBitSet32(UINT32 Operand);
INTN HighBitSet64(UINT64 Operand);
UINT32 GetPowerOfTwo32(UINT32 Operand);
UINT64 GetPowerOfTwo64(UINT64 Operand);
UINT16 SwapBytes16(UINT16 Value);
UINT32 SwapBytes32(UINT32 Value);
UINT64 SwapBytes64(UINT64 Value);
UINT64 MultU64x32(UINT64 Multiplicand, UINT32 Multiplier);
UINT64 MultU64x64(UINT64 Multiplicand, UINT64 Multiplier);
INT64 MultS64x64(INT64 Multiplicand, INT64 Multiplier);
UINT64 DivU64x32(UINT64 Dividend, UINT32 Divisor);
UINT32 ModU64x32(UINT64 Dividend, UINT32 Divisor);
UINT64 DivU64x32Remainder(UINT64 Dividend, UINT32 Divisor, UINT32 *Remainder);
UINT64 DivU64x64Remainder(UINT64 Dividend, UINT64 Divisor, UINT64 *Remainder);
INT64 DivS64x64Remainder(INT64 Dividend, INT64 Divisor, INT64 *Remainder);
UINT16 ReadUnaligned16(const UINT16 *Buffer);
UINT16 WriteUnaligned16(UINT16 *Buffer, UINT16 Value);
UINT32 ReadUnaligned24(const UINT32 *Buffer);
UINT32 WriteUnaligned24(UINT32 *Buffer, UINT32 Value);
UINT32 ReadUnaligned32(const UINT32 *Buffer);
UINT32 WriteUnaligned32(UINT32 *Buffer, UINT32 Value);
UINT64 ReadUnaligned64(const UINT64 *Buffer);
UINT64 WriteUnaligned64(UINT64 *Buffer, UINT64 Value);
UINT8 BitFieldRead8(UINT8 Operand, UINTN StartBit, UINTN EndBit);
UINT8 BitFieldWrite8(UINT8 Operand, UINTN StartBit, UINTN EndBit, UINT8 Value);
UINT8 BitFieldOr8(UINT8 Operand, UINTN StartBit, UINTN EndBit, UINT8 OrData);
UINT8 BitFieldAnd8(UINT8 Operand, UINTN StartBit, UINTN EndBit, UINT8 AndData);
UINT8 BitFieldAndThenOr8(UINT8 Operand, UINTN StartBit, UINTN EndBit, UINT8 AndData, UINT8 OrData);
UINT16 BitFieldRead16(UINT16 Operand, UINTN StartBit, UINTN EndBit);
UINT16 BitFieldWrite16(UINT16 Operand, UINTN StartBit, UINTN EndBit, UINT16 Value);
UINT16 BitFieldOr16(UINT16 Operand, UINTN StartBit, UINTN EndBit, UINT16 OrData);
UINT16 BitFieldAnd16(UINT16 Operand, UINTN StartBit, UINTN EndBit, UINT16 AndData);
UINT16 BitFieldAndThenOr16(UINT16 Operand, UINTN StartBit, UINTN EndBit, UINT16 AndData, UINT16 OrData);
UINT32 BitFieldRead32(UINT32 Operand, UINTN StartBit, UINTN EndBit);
UINT32 BitFieldWrite32(UINT32 Operand, UINTN StartBit, UINTN EndBit, UINT32 Value);
UINT32 BitFieldOr32(UINT32 Operand, UINTN StartBit, UINTN EndBit, UINT32 OrData);
UINT32 BitFieldAnd32(UINT32 Operand, UINTN StartBit, UINTN EndBit, UINT32 AndData);
UINT32 BitFieldAndThenOr32(UINT32 Operand, UINTN StartBit, UINTN EndBit, UINT32 AndData, UINT32 OrData);
UINT64 BitFieldRead64(UINT64 Operand, UINTN StartBit, UINTN EndBit);
UINT64 BitFieldWrite64(UINT64 Operand, UINTN StartBit, UINTN EndBit, UINT64 Value);
UINT64 BitFieldOr64(UINT64 Operand, UINTN StartBit, UINTN EndBit, UINT64 OrData);
UINT64 BitFieldAnd64(UINT64 Operand, UINTN StartBit, UINTN EndBit, UINT64 AndData);
UINT64 BitFieldAndThenOr64(UINT64 Operand, UINTN StartBit, UINTN EndBit, UINT64 AndData, UINT64 OrData);
UINT8 BitFieldCountOnes32(UINT32 Operand, UINTN StartBit, UINTN EndBit);
UINT8 BitFieldCountOnes64(UINT64 Operand, UINTN StartBit, UINTN EndBit);
UINT8 CalculateSum8(const UINT8 *Buffer, UINTN Length);
UINT8 CalculateCheckSum8(const UINT8 *Buffer, UINTN Length);
UINT16 CalculateSum16(const UINT16 *Buffer, UINTN Length);
UINT16 CalculateCheckSum16(const UINT16 *Buffer, UINTN Length);
UINT32 CalculateSum32(const UINT32 *Buffer, UINTN Length);
UINT32 CalculateCheckSum32(const UINT32 *Buffer, UINTN Length);
UINT64 CalculateSum64(const UINT64 *Buffer, UINTN Length);
UINT64 CalculateCheckSum64(const UINT64 *Buffer, UINTN Length);
UINT32 CalculateCrc32(void *Buffer, UINTN Length);
UINT16 CalculateCrc16Ansi(const void *Buffer, UINTN Length, UINT16 InitialValue);
UINT32 CalculateCrc32c(const void *Buffer, UINTN Length, UINT32 InitialValue);
UINT16 CalculateCrc16CcittF(const void *Buffer, UINTN Length, UINT16 InitialValue);
typedef void (*SWITCH_STACK_ENTRY_POINT)(void *Context1, void *Context2);
void MemoryFence(void);
UINTN SetJump(BASE_LIBRARY_JUMP_BUFFER *JumpBuffer);
void LongJump(BASE_LIBRARY_JUMP_BUFFER *JumpBuffer, UINTN Value);
void EnableInterrupts(void);
void DisableInterrupts(void);
BOOLEAN SaveAndDisableInterrupts(void);
void EnableDisableInterrupts(void);
BOOLEAN GetInterruptState(void);
BOOLEAN SetInterruptState(BOOLEAN InterruptState);
void CpuPause(void);
void SwitchStack(SWITCH_STACK_ENTRY_POINT EntryPoint, void *Context1, void *Context2, void *NewStack, ...);
void CpuBreakpoint(void);
void CpuDeadLoop(void);
void SpeculationBarrier(void);
UINTN TdCall(UINT64 Leaf, UINT64 Arg1, UINT64 Arg2, UINT64 Arg3, void *Results);
UINTN TdVmCall(UINT64 Leaf, UINT64 Arg1, UINT64 Arg2, UINT64 Arg3, UINT64 Arg4, void *Results);
BOOLEAN TdIsEnabled(void);
typedef enum 
{
  PvalidatePageSize4K = 0,
  PvalidatePageSize2MB
} PVALIDATE_PAGE_SIZE;
UINT32 AsmPvalidate(PVALIDATE_PAGE_SIZE PageSize, BOOLEAN Validate, PHYSICAL_ADDRESS Address);
UINT32 AsmRmpAdjust(UINT64 Rax, UINT64 Rcx, UINT64 Rdx);
typedef union 
{
  struct 
  {
    UINT32 CF : 1;
    UINT32 Reserved_0 : 1;
    UINT32 PF : 1;
    UINT32 Reserved_1 : 1;
    UINT32 AF : 1;
    UINT32 Reserved_2 : 1;
    UINT32 ZF : 1;
    UINT32 SF : 1;
    UINT32 TF : 1;
    UINT32 IF : 1;
    UINT32 DF : 1;
    UINT32 OF : 1;
    UINT32 IOPL : 2;
    UINT32 NT : 1;
    UINT32 Reserved_3 : 1;
  } Bits;
  UINT16 Uint16;
} IA32_FLAGS16;
typedef union 
{
  struct 
  {
    UINT32 CF : 1;
    UINT32 Reserved_0 : 1;
    UINT32 PF : 1;
    UINT32 Reserved_1 : 1;
    UINT32 AF : 1;
    UINT32 Reserved_2 : 1;
    UINT32 ZF : 1;
    UINT32 SF : 1;
    UINT32 TF : 1;
    UINT32 IF : 1;
    UINT32 DF : 1;
    UINT32 OF : 1;
    UINT32 IOPL : 2;
    UINT32 NT : 1;
    UINT32 Reserved_3 : 1;
    UINT32 RF : 1;
    UINT32 VM : 1;
    UINT32 AC : 1;
    UINT32 VIF : 1;
    UINT32 VIP : 1;
    UINT32 ID : 1;
    UINT32 Reserved_4 : 10;
  } Bits;
  UINTN UintN;
} IA32_EFLAGS32;
typedef union 
{
  struct 
  {
    UINT32 PE : 1;
    UINT32 MP : 1;
    UINT32 EM : 1;
    UINT32 TS : 1;
    UINT32 ET : 1;
    UINT32 NE : 1;
    UINT32 Reserved_0 : 10;
    UINT32 WP : 1;
    UINT32 Reserved_1 : 1;
    UINT32 AM : 1;
    UINT32 Reserved_2 : 10;
    UINT32 NW : 1;
    UINT32 CD : 1;
    UINT32 PG : 1;
  } Bits;
  UINTN UintN;
} IA32_CR0;
typedef union 
{
  struct 
  {
    UINT32 VME : 1;
    UINT32 PVI : 1;
    UINT32 TSD : 1;
    UINT32 DE : 1;
    UINT32 PSE : 1;
    UINT32 PAE : 1;
    UINT32 MCE : 1;
    UINT32 PGE : 1;
    UINT32 PCE : 1;
    UINT32 OSFXSR : 1;
    UINT32 OSXMMEXCPT : 1;
    UINT32 UMIP : 1;
    UINT32 LA57 : 1;
    UINT32 VMXE : 1;
    UINT32 SMXE : 1;
    UINT32 Reserved_3 : 1;
    UINT32 FSGSBASE : 1;
    UINT32 PCIDE : 1;
    UINT32 OSXSAVE : 1;
    UINT32 Reserved_4 : 1;
    UINT32 SMEP : 1;
    UINT32 SMAP : 1;
    UINT32 PKE : 1;
    UINT32 Reserved_5 : 9;
  } Bits;
  UINTN UintN;
} IA32_CR4;
typedef union 
{
  struct 
  {
    UINT32 LimitLow : 16;
    UINT32 BaseLow : 16;
    UINT32 BaseMid : 8;
    UINT32 Type : 4;
    UINT32 S : 1;
    UINT32 DPL : 2;
    UINT32 P : 1;
    UINT32 LimitHigh : 4;
    UINT32 AVL : 1;
    UINT32 L : 1;
    UINT32 DB : 1;
    UINT32 G : 1;
    UINT32 BaseHigh : 8;
  } Bits;
  UINT64 Uint64;
} IA32_SEGMENT_DESCRIPTOR;
#pragma pack (1)
typedef struct 
{
  UINT16 Limit;
  UINTN Base;
} IA32_DESCRIPTOR;
#pragma pack ()
typedef union 
{
  struct 
  {
    UINT32 OffsetLow : 16;
    UINT32 Selector : 16;
    UINT32 Reserved_0 : 8;
    UINT32 GateType : 8;
    UINT32 OffsetHigh : 16;
    UINT32 OffsetUpper : 32;
    UINT32 Reserved_1 : 32;
  } Bits;
  struct 
  {
    UINT64 Uint64;
    UINT64 Uint64_1;
  } Uint128;
} IA32_IDT_GATE_DESCRIPTOR;
#pragma pack (1)
typedef struct 
{
  UINT32 Reserved_0;
  UINT64 RSP0;
  UINT64 RSP1;
  UINT64 RSP2;
  UINT64 Reserved_28;
  UINT64 IST[7];
  UINT64 Reserved_92;
  UINT16 Reserved_100;
  UINT16 IOMapBaseAddress;
} IA32_TASK_STATE_SEGMENT;
typedef union 
{
  struct 
  {
    UINT32 LimitLow : 16;
    UINT32 BaseLow : 16;
    UINT32 BaseMidl : 8;
    UINT32 Type : 4;
    UINT32 Reserved_43 : 1;
    UINT32 DPL : 2;
    UINT32 P : 1;
    UINT32 LimitHigh : 4;
    UINT32 AVL : 1;
    UINT32 Reserved_52 : 2;
    UINT32 G : 1;
    UINT32 BaseMidh : 8;
    UINT32 BaseHigh : 32;
    UINT32 Reserved_96 : 32;
  } Bits;
  struct 
  {
    UINT64 Uint64;
    UINT64 Uint64_1;
  } Uint128;
} IA32_TSS_DESCRIPTOR;
#pragma pack ()
typedef struct 
{
  UINT8 Buffer[512];
} IA32_FX_BUFFER;
typedef struct 
{
  UINT32 Reserved1;
  UINT32 Reserved2;
  UINT32 Reserved3;
  UINT32 Reserved4;
  UINT8 BL;
  UINT8 BH;
  UINT16 Reserved5;
  UINT8 DL;
  UINT8 DH;
  UINT16 Reserved6;
  UINT8 CL;
  UINT8 CH;
  UINT16 Reserved7;
  UINT8 AL;
  UINT8 AH;
  UINT16 Reserved8;
} IA32_BYTE_REGS;
typedef struct 
{
  UINT16 DI;
  UINT16 Reserved1;
  UINT16 SI;
  UINT16 Reserved2;
  UINT16 BP;
  UINT16 Reserved3;
  UINT16 SP;
  UINT16 Reserved4;
  UINT16 BX;
  UINT16 Reserved5;
  UINT16 DX;
  UINT16 Reserved6;
  UINT16 CX;
  UINT16 Reserved7;
  UINT16 AX;
  UINT16 Reserved8;
} IA32_WORD_REGS;
typedef struct 
{
  UINT32 EDI;
  UINT32 ESI;
  UINT32 EBP;
  UINT32 ESP;
  UINT32 EBX;
  UINT32 EDX;
  UINT32 ECX;
  UINT32 EAX;
  UINT16 DS;
  UINT16 ES;
  UINT16 FS;
  UINT16 GS;
  IA32_EFLAGS32 EFLAGS;
  UINT32 Eip;
  UINT16 CS;
  UINT16 SS;
} IA32_DWORD_REGS;
typedef union 
{
  IA32_DWORD_REGS E;
  IA32_WORD_REGS X;
  IA32_BYTE_REGS H;
} IA32_REGISTER_SET;
typedef struct 
{
  IA32_REGISTER_SET *RealModeState;
  void *RealModeBuffer;
  UINT32 RealModeBufferSize;
  UINT32 ThunkAttributes;
} THUNK_CONTEXT;
typedef void X86_ASSEMBLY_PATCH_LABEL(void);
UINT32 AsmCpuid(UINT32 Index, UINT32 *Eax, UINT32 *Ebx, UINT32 *Ecx, UINT32 *Edx);
UINT32 AsmCpuidEx(UINT32 Index, UINT32 SubIndex, UINT32 *Eax, UINT32 *Ebx, UINT32 *Ecx, UINT32 *Edx);
void AsmDisableCache(void);
void AsmEnableCache(void);
UINT32 AsmReadMsr32(UINT32 Index);
UINT32 AsmWriteMsr32(UINT32 Index, UINT32 Value);
UINT32 AsmMsrOr32(UINT32 Index, UINT32 OrData);
UINT32 AsmMsrAnd32(UINT32 Index, UINT32 AndData);
UINT32 AsmMsrAndThenOr32(UINT32 Index, UINT32 AndData, UINT32 OrData);
UINT32 AsmMsrBitFieldRead32(UINT32 Index, UINTN StartBit, UINTN EndBit);
UINT32 AsmMsrBitFieldWrite32(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT32 Value);
UINT32 AsmMsrBitFieldOr32(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT32 OrData);
UINT32 AsmMsrBitFieldAnd32(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT32 AndData);
UINT32 AsmMsrBitFieldAndThenOr32(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT32 AndData, UINT32 OrData);
UINT64 AsmReadMsr64(UINT32 Index);
UINT64 AsmWriteMsr64(UINT32 Index, UINT64 Value);
UINT64 AsmMsrOr64(UINT32 Index, UINT64 OrData);
UINT64 AsmMsrAnd64(UINT32 Index, UINT64 AndData);
UINT64 AsmMsrAndThenOr64(UINT32 Index, UINT64 AndData, UINT64 OrData);
UINT64 AsmMsrBitFieldRead64(UINT32 Index, UINTN StartBit, UINTN EndBit);
UINT64 AsmMsrBitFieldWrite64(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT64 Value);
UINT64 AsmMsrBitFieldOr64(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT64 OrData);
UINT64 AsmMsrBitFieldAnd64(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT64 AndData);
UINT64 AsmMsrBitFieldAndThenOr64(UINT32 Index, UINTN StartBit, UINTN EndBit, UINT64 AndData, UINT64 OrData);
UINTN AsmReadEflags(void);
UINTN AsmReadCr0(void);
UINTN AsmReadCr2(void);
UINTN AsmReadCr3(void);
UINTN AsmReadCr4(void);
UINTN AsmWriteCr0(UINTN Cr0);
UINTN AsmWriteCr2(UINTN Cr2);
UINTN AsmWriteCr3(UINTN Cr3);
UINTN AsmWriteCr4(UINTN Cr4);
UINTN AsmReadDr0(void);
UINTN AsmReadDr1(void);
UINTN AsmReadDr2(void);
UINTN AsmReadDr3(void);
UINTN AsmReadDr4(void);
UINTN AsmReadDr5(void);
UINTN AsmReadDr6(void);
UINTN AsmReadDr7(void);
UINTN AsmWriteDr0(UINTN Dr0);
UINTN AsmWriteDr1(UINTN Dr1);
UINTN AsmWriteDr2(UINTN Dr2);
UINTN AsmWriteDr3(UINTN Dr3);
UINTN AsmWriteDr4(UINTN Dr4);
UINTN AsmWriteDr5(UINTN Dr5);
UINTN AsmWriteDr6(UINTN Dr6);
UINTN AsmWriteDr7(UINTN Dr7);
UINT16 AsmReadCs(void);
UINT16 AsmReadDs(void);
UINT16 AsmReadEs(void);
UINT16 AsmReadFs(void);
UINT16 AsmReadGs(void);
UINT16 AsmReadSs(void);
UINT16 AsmReadTr(void);
void AsmReadGdtr(IA32_DESCRIPTOR *Gdtr);
void AsmWriteGdtr(const IA32_DESCRIPTOR *Gdtr);
void AsmReadIdtr(IA32_DESCRIPTOR *Idtr);
void AsmWriteIdtr(const IA32_DESCRIPTOR *Idtr);
UINT16 AsmReadLdtr(void);
void AsmWriteLdtr(UINT16 Ldtr);
void AsmFxSave(IA32_FX_BUFFER *Buffer);
void AsmFxRestore(const IA32_FX_BUFFER *Buffer);
UINT64 AsmReadMm0(void);
UINT64 AsmReadMm1(void);
UINT64 AsmReadMm2(void);
UINT64 AsmReadMm3(void);
UINT64 AsmReadMm4(void);
UINT64 AsmReadMm5(void);
UINT64 AsmReadMm6(void);
UINT64 AsmReadMm7(void);
void AsmWriteMm0(UINT64 Value);
void AsmWriteMm1(UINT64 Value);
void AsmWriteMm2(UINT64 Value);
void AsmWriteMm3(UINT64 Value);
void AsmWriteMm4(UINT64 Value);
void AsmWriteMm5(UINT64 Value);
void AsmWriteMm6(UINT64 Value);
void AsmWriteMm7(UINT64 Value);
UINT64 AsmReadTsc(void);
UINT64 AsmReadPmc(UINT32 Index);
UINTN AsmMonitor(UINTN Eax, UINTN Ecx, UINTN Edx);
UINTN AsmMwait(UINTN Eax, UINTN Ecx);
void AsmWbinvd(void);
void AsmInvd(void);
void *AsmFlushCacheLine(void *LinearAddress);
void AsmEnablePaging32(SWITCH_STACK_ENTRY_POINT EntryPoint, void *Context1, void *Context2, void *NewStack);
void AsmDisablePaging32(SWITCH_STACK_ENTRY_POINT EntryPoint, void *Context1, void *Context2, void *NewStack);
void AsmEnablePaging64(UINT16 Cs, UINT64 EntryPoint, UINT64 Context1, UINT64 Context2, UINT64 NewStack);
void AsmDisablePaging64(UINT16 Cs, UINT32 EntryPoint, UINT32 Context1, UINT32 Context2, UINT32 NewStack);
void AsmGetThunk16Properties(UINT32 *RealModeBufferSize, UINT32 *ExtraStackSize);
void AsmPrepareThunk16(THUNK_CONTEXT *ThunkContext);
void AsmThunk16(THUNK_CONTEXT *ThunkContext);
void AsmPrepareAndThunk16(THUNK_CONTEXT *ThunkContext);
BOOLEAN AsmRdRand16(UINT16 *Rand);
BOOLEAN AsmRdRand32(UINT32 *Rand);
BOOLEAN AsmRdRand64(UINT64 *Rand);
void AsmWriteTr(UINT16 Selector);
void AsmLfence(void);
UINT64 AsmXGetBv(UINT32 Index);
UINT64 AsmXSetBv(UINT32 Index, UINT64 Value);
void AsmVmgExit(void);
typedef struct 
{
  void *Caa;
  UINT64 RaxIn;
  UINT64 RcxIn;
  UINT64 RdxIn;
  UINT64 R8In;
  UINT64 R9In;
  UINT64 RaxOut;
  UINT64 RcxOut;
  UINT64 RdxOut;
  UINT64 R8Out;
  UINT64 R9Out;
  UINT8 *CallPending;
} SVSM_CALL_DATA;
UINT32 AsmVmgExitSvsm(SVSM_CALL_DATA *SvsmCallData);
void PatchInstructionX86(X86_ASSEMBLY_PATCH_LABEL *InstructionEnd, UINT64 PatchValue, UINTN ValueSize);
typedef struct _EFI_PEI_PCI_CFG2_PPI EFI_PEI_PCI_CFG2_PPI;
typedef enum 
{
  EfiPeiPciCfgWidthUint8 = 0,
  EfiPeiPciCfgWidthUint16 = 1,
  EfiPeiPciCfgWidthUint32 = 2,
  EfiPeiPciCfgWidthUint64 = 3,
  EfiPeiPciCfgWidthMaximum
} EFI_PEI_PCI_CFG_PPI_WIDTH;
typedef struct 
{
  UINT8 Register;
  UINT8 Function;
  UINT8 Device;
  UINT8 Bus;
  UINT32 ExtendedRegister;
} EFI_PEI_PCI_CFG_PPI_PCI_ADDRESS;
typedef EFI_STATUS (*EFI_PEI_PCI_CFG2_PPI_IO)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_PCI_CFG2_PPI *This, EFI_PEI_PCI_CFG_PPI_WIDTH Width, UINT64 Address, void *Buffer);
typedef EFI_STATUS (*EFI_PEI_PCI_CFG2_PPI_RW)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_PCI_CFG2_PPI *This, EFI_PEI_PCI_CFG_PPI_WIDTH Width, UINT64 Address, void *SetBits, void *ClearBits);
struct _EFI_PEI_PCI_CFG2_PPI
{
  EFI_PEI_PCI_CFG2_PPI_IO Read;
  EFI_PEI_PCI_CFG2_PPI_IO Write;
  EFI_PEI_PCI_CFG2_PPI_RW Modify;
  UINT16 Segment;
};
extern EFI_GUID gEfiPciCfg2PpiGuid;
typedef EFI_STATUS (*EFI_PEIM_ENTRY_POINT2)(EFI_PEI_FILE_HANDLE FileHandle, const EFI_PEI_SERVICES **PeiServices);
typedef EFI_STATUS (*EFI_PEIM_NOTIFY_ENTRY_POINT)(EFI_PEI_SERVICES **PeiServices, EFI_PEI_NOTIFY_DESCRIPTOR *NotifyDescriptor, void *Ppi);
typedef struct 
{
  UINTN Flags;
  EFI_GUID *Guid;
  void *Ppi;
} EFI_PEI_PPI_DESCRIPTOR;
struct _EFI_PEI_NOTIFY_DESCRIPTOR
{
  UINTN Flags;
  EFI_GUID *Guid;
  EFI_PEIM_NOTIFY_ENTRY_POINT Notify;
};
typedef union 
{
  EFI_PEI_NOTIFY_DESCRIPTOR Notify;
  EFI_PEI_PPI_DESCRIPTOR Ppi;
} EFI_PEI_DESCRIPTOR;
typedef EFI_STATUS (*EFI_PEI_INSTALL_PPI)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_PPI_DESCRIPTOR *PpiList);
typedef EFI_STATUS (*EFI_PEI_REINSTALL_PPI)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_PPI_DESCRIPTOR *OldPpi, const EFI_PEI_PPI_DESCRIPTOR *NewPpi);
typedef EFI_STATUS (*EFI_PEI_LOCATE_PPI)(const EFI_PEI_SERVICES **PeiServices, const EFI_GUID *Guid, UINTN Instance, EFI_PEI_PPI_DESCRIPTOR **PpiDescriptor, void **Ppi);
typedef EFI_STATUS (*EFI_PEI_NOTIFY_PPI)(const EFI_PEI_SERVICES **PeiServices, const EFI_PEI_NOTIFY_DESCRIPTOR *NotifyList);
typedef EFI_STATUS (*EFI_PEI_GET_BOOT_MODE)(const EFI_PEI_SERVICES **PeiServices, EFI_BOOT_MODE *BootMode);
typedef EFI_STATUS (*EFI_PEI_SET_BOOT_MODE)(const EFI_PEI_SERVICES **PeiServices, EFI_BOOT_MODE BootMode);
typedef EFI_STATUS (*EFI_PEI_GET_HOB_LIST)(const EFI_PEI_SERVICES **PeiServices, void **HobList);
typedef EFI_STATUS (*EFI_PEI_CREATE_HOB)(const EFI_PEI_SERVICES **PeiServices, UINT16 Type, UINT16 Length, void **Hob);
typedef EFI_STATUS (*EFI_PEI_FFS_FIND_NEXT_VOLUME2)(const EFI_PEI_SERVICES **PeiServices, UINTN Instance, EFI_PEI_FV_HANDLE *VolumeHandle);
typedef EFI_STATUS (*EFI_PEI_FFS_FIND_NEXT_FILE2)(const EFI_PEI_SERVICES **PeiServices, EFI_FV_FILETYPE SearchType, const EFI_PEI_FV_HANDLE FvHandle, EFI_PEI_FILE_HANDLE *FileHandle);
typedef EFI_STATUS (*EFI_PEI_FFS_FIND_SECTION_DATA2)(const EFI_PEI_SERVICES **PeiServices, EFI_SECTION_TYPE SectionType, EFI_PEI_FILE_HANDLE FileHandle, void **SectionData);
typedef EFI_STATUS (*EFI_PEI_FFS_FIND_SECTION_DATA3)(const EFI_PEI_SERVICES **PeiServices, EFI_SECTION_TYPE SectionType, UINTN SectionInstance, EFI_PEI_FILE_HANDLE FileHandle, void **SectionData, UINT32 *AuthenticationStatus);
typedef EFI_STATUS (*EFI_PEI_INSTALL_PEI_MEMORY)(const EFI_PEI_SERVICES **PeiServices, EFI_PHYSICAL_ADDRESS MemoryBegin, UINT64 MemoryLength);
typedef EFI_STATUS (*EFI_PEI_ALLOCATE_PAGES)(const EFI_PEI_SERVICES **PeiServices, EFI_MEMORY_TYPE MemoryType, UINTN Pages, EFI_PHYSICAL_ADDRESS *Memory);
typedef EFI_STATUS (*EFI_PEI_FREE_PAGES)(const EFI_PEI_SERVICES **PeiServices, EFI_PHYSICAL_ADDRESS Memory, UINTN Pages);
typedef EFI_STATUS (*EFI_PEI_ALLOCATE_POOL)(const EFI_PEI_SERVICES **PeiServices, UINTN Size, void **Buffer);
typedef void (*EFI_PEI_COPY_MEM)(void *Destination, void *Source, UINTN Length);
typedef void (*EFI_PEI_SET_MEM)(void *Buffer, UINTN Size, UINT8 Value);
typedef EFI_STATUS (*EFI_PEI_REPORT_STATUS_CODE)(const EFI_PEI_SERVICES **PeiServices, EFI_STATUS_CODE_TYPE Type, EFI_STATUS_CODE_VALUE Value, UINT32 Instance, const EFI_GUID *CallerId, const EFI_STATUS_CODE_DATA *Data);
typedef EFI_STATUS (*EFI_PEI_RESET_SYSTEM)(const EFI_PEI_SERVICES **PeiServices);
typedef void (*EFI_PEI_RESET2_SYSTEM)(EFI_RESET_TYPE ResetType, EFI_STATUS ResetStatus, UINTN DataSize, void *ResetData);
typedef EFI_STATUS (*EFI_PEI_FFS_FIND_BY_NAME)(const EFI_GUID *FileName, EFI_PEI_FV_HANDLE VolumeHandle, EFI_PEI_FILE_HANDLE *FileHandle);
typedef struct 
{
  EFI_GUID FileName;
  EFI_FV_FILETYPE FileType;
  EFI_FV_FILE_ATTRIBUTES FileAttributes;
  void *Buffer;
  UINT32 BufferSize;
} EFI_FV_FILE_INFO;
typedef struct 
{
  EFI_GUID FileName;
  EFI_FV_FILETYPE FileType;
  EFI_FV_FILE_ATTRIBUTES FileAttributes;
  void *Buffer;
  UINT32 BufferSize;
  UINT32 AuthenticationStatus;
} EFI_FV_FILE_INFO2;
typedef EFI_STATUS (*EFI_PEI_FFS_GET_FILE_INFO)(EFI_PEI_FILE_HANDLE FileHandle, EFI_FV_FILE_INFO *FileInfo);
typedef EFI_STATUS (*EFI_PEI_FFS_GET_FILE_INFO2)(EFI_PEI_FILE_HANDLE FileHandle, EFI_FV_FILE_INFO2 *FileInfo);
typedef struct 
{
  EFI_FVB_ATTRIBUTES_2 FvAttributes;
  EFI_GUID FvFormat;
  EFI_GUID FvName;
  void *FvStart;
  UINT64 FvSize;
} EFI_FV_INFO;
typedef EFI_STATUS (*EFI_PEI_FFS_GET_VOLUME_INFO)(EFI_PEI_FV_HANDLE VolumeHandle, EFI_FV_INFO *VolumeInfo);
typedef EFI_STATUS (*EFI_PEI_REGISTER_FOR_SHADOW)(EFI_PEI_FILE_HANDLE FileHandle);
struct _EFI_PEI_SERVICES
{
  EFI_TABLE_HEADER Hdr;
  EFI_PEI_INSTALL_PPI InstallPpi;
  EFI_PEI_REINSTALL_PPI ReInstallPpi;
  EFI_PEI_LOCATE_PPI LocatePpi;
  EFI_PEI_NOTIFY_PPI NotifyPpi;
  EFI_PEI_GET_BOOT_MODE GetBootMode;
  EFI_PEI_SET_BOOT_MODE SetBootMode;
  EFI_PEI_GET_HOB_LIST GetHobList;
  EFI_PEI_CREATE_HOB CreateHob;
  EFI_PEI_FFS_FIND_NEXT_VOLUME2 FfsFindNextVolume;
  EFI_PEI_FFS_FIND_NEXT_FILE2 FfsFindNextFile;
  EFI_PEI_FFS_FIND_SECTION_DATA2 FfsFindSectionData;
  EFI_PEI_INSTALL_PEI_MEMORY InstallPeiMemory;
  EFI_PEI_ALLOCATE_PAGES AllocatePages;
  EFI_PEI_ALLOCATE_POOL AllocatePool;
  EFI_PEI_COPY_MEM CopyMem;
  EFI_PEI_SET_MEM SetMem;
  EFI_PEI_REPORT_STATUS_CODE ReportStatusCode;
  EFI_PEI_RESET_SYSTEM ResetSystem;
  EFI_PEI_CPU_IO_PPI *CpuIo;
  EFI_PEI_PCI_CFG2_PPI *PciCfg;
  EFI_PEI_FFS_FIND_BY_NAME FfsFindFileByName;
  EFI_PEI_FFS_GET_FILE_INFO FfsGetFileInfo;
  EFI_PEI_FFS_GET_VOLUME_INFO FfsGetVolumeInfo;
  EFI_PEI_REGISTER_FOR_SHADOW RegisterForShadow;
  EFI_PEI_FFS_FIND_SECTION_DATA3 FindSectionData3;
  EFI_PEI_FFS_GET_FILE_INFO2 FfsGetFileInfo2;
  EFI_PEI_RESET2_SYSTEM ResetSystem2;
  EFI_PEI_FREE_PAGES FreePages;
};
typedef struct _EFI_SEC_PEI_HAND_OFF
{
  UINT16 DataSize;
  void *BootFirmwareVolumeBase;
  UINTN BootFirmwareVolumeSize;
  void *TemporaryRamBase;
  UINTN TemporaryRamSize;
  void *PeiTemporaryRamBase;
  UINTN PeiTemporaryRamSize;
  void *StackBase;
  UINTN StackSize;
} EFI_SEC_PEI_HAND_OFF;
typedef void (*EFI_PEI_CORE_ENTRY_POINT)(const EFI_SEC_PEI_HAND_OFF *SecCoreData, const EFI_PEI_PPI_DESCRIPTOR *PpiList);
typedef EFI_STATUS (*EFI_PEI_RSC_HANDLER_CALLBACK)(const EFI_PEI_SERVICES **PeiServices, EFI_STATUS_CODE_TYPE Type, EFI_STATUS_CODE_VALUE Value, UINT32 Instance, const EFI_GUID *CallerId, const EFI_STATUS_CODE_DATA *Data);
typedef EFI_STATUS (*EFI_PEI_RSC_HANDLER_REGISTER)(EFI_PEI_RSC_HANDLER_CALLBACK Callback);
typedef EFI_STATUS (*EFI_PEI_RSC_HANDLER_UNREGISTER)(EFI_PEI_RSC_HANDLER_CALLBACK Callback);
typedef struct _EFI_PEI_RSC_HANDLER_PPI
{
  EFI_PEI_RSC_HANDLER_REGISTER Register;
  EFI_PEI_RSC_HANDLER_UNREGISTER Unregister;
} EFI_PEI_RSC_HANDLER_PPI;
extern EFI_GUID gEfiPeiRscHandlerPpiGuid;
typedef struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI EFI_PEI_READ_ONLY_VARIABLE2_PPI;
typedef EFI_STATUS (*EFI_PEI_GET_VARIABLE2)(const EFI_PEI_READ_ONLY_VARIABLE2_PPI *This, const CHAR16 *VariableName, const EFI_GUID *VariableGuid, UINT32 *Attributes, UINTN *DataSize, void *Data);
typedef EFI_STATUS (*EFI_PEI_GET_NEXT_VARIABLE_NAME2)(const EFI_PEI_READ_ONLY_VARIABLE2_PPI *This, UINTN *VariableNameSize, CHAR16 *VariableName, EFI_GUID *VariableGuid);
struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI
{
  EFI_PEI_GET_VARIABLE2 GetVariable;
  EFI_PEI_GET_NEXT_VARIABLE_NAME2 NextVariableName;
};
extern EFI_GUID gEfiPeiReadOnlyVariable2PpiGuid;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_COMMON_HEADER;
#pragma pack(1)
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT8 Revision;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT64 OemTableId;
  UINT32 OemRevision;
  UINT32 CreatorId;
  UINT32 CreatorRevision;
} EFI_ACPI_DESCRIPTION_HEADER;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 Desc;
  UINT16 Len;
  UINT8 ResType;
  UINT8 GenFlag;
  UINT8 SpecificFlag;
  UINT64 AddrSpaceGranularity;
  UINT64 AddrRangeMin;
  UINT64 AddrRangeMax;
  UINT64 AddrTranslationOffset;
  UINT64 AddrLen;
} EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR;
typedef union 
{
  UINT8 Byte;
  struct 
  {
    UINT8 Length : 3;
    UINT8 Name : 4;
    UINT8 Type : 1;
  } Bits;
} ACPI_SMALL_RESOURCE_HEADER;
typedef struct 
{
  union 
  {
    UINT8 Byte;
    struct 
    {
      UINT8 Name : 7;
      UINT8 Type : 1;
    } Bits;
  } Header;
  UINT16 Length;
} ACPI_LARGE_RESOURCE_HEADER;
typedef struct 
{
  ACPI_SMALL_RESOURCE_HEADER Header;
  UINT16 Mask;
} EFI_ACPI_IRQ_NOFLAG_DESCRIPTOR;
typedef struct 
{
  ACPI_SMALL_RESOURCE_HEADER Header;
  UINT16 Mask;
  UINT8 Information;
} EFI_ACPI_IRQ_DESCRIPTOR;
typedef struct 
{
  ACPI_SMALL_RESOURCE_HEADER Header;
  UINT8 ChannelMask;
  UINT8 Information;
} EFI_ACPI_DMA_DESCRIPTOR;
typedef struct 
{
  ACPI_SMALL_RESOURCE_HEADER Header;
  UINT8 Information;
  UINT16 BaseAddressMin;
  UINT16 BaseAddressMax;
  UINT8 Alignment;
  UINT8 Length;
} EFI_ACPI_IO_PORT_DESCRIPTOR;
typedef struct 
{
  ACPI_SMALL_RESOURCE_HEADER Header;
  UINT16 BaseAddress;
  UINT8 Length;
} EFI_ACPI_FIXED_LOCATION_IO_PORT_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 Information;
  UINT16 BaseAddressMin;
  UINT16 BaseAddressMax;
  UINT16 Alignment;
  UINT16 Length;
} EFI_ACPI_24_BIT_MEMORY_RANGE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 Information;
  UINT32 BaseAddressMin;
  UINT32 BaseAddressMax;
  UINT32 Alignment;
  UINT32 Length;
} EFI_ACPI_32_BIT_MEMORY_RANGE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 Information;
  UINT32 BaseAddress;
  UINT32 Length;
} EFI_ACPI_32_BIT_FIXED_MEMORY_RANGE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 ResType;
  UINT8 GenFlag;
  UINT8 SpecificFlag;
  UINT64 AddrSpaceGranularity;
  UINT64 AddrRangeMin;
  UINT64 AddrRangeMax;
  UINT64 AddrTranslationOffset;
  UINT64 AddrLen;
} EFI_ACPI_QWORD_ADDRESS_SPACE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 ResType;
  UINT8 GenFlag;
  UINT8 SpecificFlag;
  UINT32 AddrSpaceGranularity;
  UINT32 AddrRangeMin;
  UINT32 AddrRangeMax;
  UINT32 AddrTranslationOffset;
  UINT32 AddrLen;
} EFI_ACPI_DWORD_ADDRESS_SPACE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 ResType;
  UINT8 GenFlag;
  UINT8 SpecificFlag;
  UINT16 AddrSpaceGranularity;
  UINT16 AddrRangeMin;
  UINT16 AddrRangeMax;
  UINT16 AddrTranslationOffset;
  UINT16 AddrLen;
} EFI_ACPI_WORD_ADDRESS_SPACE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 InterruptVectorFlags;
  UINT8 InterruptTableLength;
  UINT32 InterruptNumber[1];
} EFI_ACPI_EXTENDED_INTERRUPT_DESCRIPTOR;
#pragma pack()
typedef struct 
{
  UINT8 Desc;
  UINT8 Checksum;
} EFI_ACPI_END_TAG_DESCRIPTOR;
#pragma pack(1)
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Reserved;
  UINT32 RsdtAddress;
} EFI_ACPI_1_0_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 IntModel;
  UINT8 Reserved1;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 Reserved2;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 Reserved3;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT8 Reserved4;
  UINT8 Reserved5;
  UINT8 Reserved6;
  UINT32 Flags;
} EFI_ACPI_1_0_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT8 Reserved[40];
} EFI_ACPI_1_0_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_1_0_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 SystemVectorBase;
} EFI_ACPI_1_0_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterruptVector;
  UINT16 Flags;
} EFI_ACPI_1_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterruptVector;
} EFI_ACPI_1_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT16 Flags;
  UINT8 LocalApicInti;
} EFI_ACPI_1_0_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_1_0_SMART_BATTERY_DESCRIPTION_TABLE;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AddressSize;
  UINT64 RegisterAddress;
} EFI_ACPI_GENERIC_REGISTER_DESCRIPTOR;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 Reserved;
  UINT64 Address;
} EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_2_0_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_2_0_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT8 Reserved2[3];
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
} EFI_ACPI_2_0_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved[31];
} EFI_ACPI_2_0_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_2_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_2_0_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_2_0_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_2_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_2_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_2_0_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_2_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_2_0_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
} EFI_ACPI_2_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 Reserved;
} EFI_ACPI_2_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_2_0_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_2_0_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_2_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 ResType;
  UINT8 GenFlag;
  UINT8 SpecificFlag;
  UINT8 RevisionId;
  UINT8 Reserved;
  UINT64 AddrSpaceGranularity;
  UINT64 AddrRangeMin;
  UINT64 AddrRangeMax;
  UINT64 AddrTranslationOffset;
  UINT64 AddrLen;
  UINT64 TypeSpecificAttribute;
} EFI_ACPI_EXTENDED_ADDRESS_SPACE_DESCRIPTOR;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_3_0_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT8 Reserved2[3];
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
} EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved[31];
} EFI_ACPI_3_0_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_3_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_3_0_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_3_0_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_3_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_3_0_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_3_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_3_0_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_3_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_3_0_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_3_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_3_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_3_0_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_3_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_3_0_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT8 Reserved[4];
} EFI_ACPI_3_0_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_3_0_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_3_0_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_4_0_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_4_0_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT8 Reserved2[3];
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
} EFI_ACPI_4_0_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_4_0_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_4_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_4_0_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_4_0_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_4_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_4_0_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_4_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_4_0_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_4_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_4_0_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_4_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_4_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_4_0_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_4_0_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_4_0_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_4_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_4_0_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_4_0_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_4_0_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_4_0_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_4_0_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_4_0_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_4_0_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_4_0_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_4_0_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_4_0_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_4_0_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_4_0_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_4_0_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
} EFI_ACPI_4_0_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_4_0_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_4_0_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_4_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_4_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_4_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_4_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_4_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_4_0_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_4_0_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_4_0_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_4_0_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_4_0_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_4_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_4_0_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_4_0_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_4_0_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_4_0_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_4_0_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_4_0_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_4_0_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_4_0_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_4_0_EINJ_TRIGGER_ACTION_TABLE;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  ACPI_SMALL_RESOURCE_HEADER Header;
  UINT16 DmaRequestLine;
  UINT16 DmaChannel;
  UINT8 DmaTransferWidth;
} EFI_ACPI_FIXED_DMA_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT8 ConnectionType;
  UINT16 GeneralFlags;
  UINT16 InterruptFlags;
  UINT8 PinConfiguration;
  UINT16 OutputDriveStrength;
  UINT16 DebounceTimeout;
  UINT16 PinTableOffset;
  UINT8 ResourceSourceIndex;
  UINT16 ResourceSourceNameOffset;
  UINT16 VendorDataOffset;
  UINT16 VendorDataLength;
} EFI_ACPI_GPIO_CONNECTION_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT8 ResourceSourceIndex;
  UINT8 SerialBusType;
  UINT8 GeneralFlags;
  UINT16 TypeSpecificFlags;
  UINT8 TypeSpecificRevisionId;
  UINT16 TypeDataLength;
} EFI_ACPI_SERIAL_BUS_RESOURCE_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT8 ResourceSourceIndex;
  UINT8 SerialBusType;
  UINT8 GeneralFlags;
  UINT16 TypeSpecificFlags;
  UINT8 TypeSpecificRevisionId;
  UINT16 TypeDataLength;
  UINT32 ConnectionSpeed;
  UINT16 SlaveAddress;
} EFI_ACPI_SERIAL_BUS_RESOURCE_I2C_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT8 ResourceSourceIndex;
  UINT8 SerialBusType;
  UINT8 GeneralFlags;
  UINT16 TypeSpecificFlags;
  UINT8 TypeSpecificRevisionId;
  UINT16 TypeDataLength;
  UINT32 ConnectionSpeed;
  UINT8 DataBitLength;
  UINT8 Phase;
  UINT8 Polarity;
  UINT16 DeviceSelection;
} EFI_ACPI_SERIAL_BUS_RESOURCE_SPI_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT8 ResourceSourceIndex;
  UINT8 SerialBusType;
  UINT8 GeneralFlags;
  UINT16 TypeSpecificFlags;
  UINT8 TypeSpecificRevisionId;
  UINT16 TypeDataLength;
  UINT32 DefaultBaudRate;
  UINT16 RxFIFO;
  UINT16 TxFIFO;
  UINT8 Parity;
  UINT8 SerialLinesEnabled;
} EFI_ACPI_SERIAL_BUS_RESOURCE_UART_DESCRIPTOR;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_5_0_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_5_0_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT8 Reserved2[3];
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
} EFI_ACPI_5_0_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_5_0_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_5_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_5_0_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_5_0_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_5_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_5_0_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_5_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_5_0_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_5_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_5_0_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_5_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_5_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_5_0_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_5_0_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicId;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
} EFI_ACPI_5_0_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT32 Reserved2;
} EFI_ACPI_5_0_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_5_0_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_5_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_5_0_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_5_0_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_5_0_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_5_0_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_5_0_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_5_0_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_5_0_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_5_0_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_5_0_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_5_0_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_5_0_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_5_0_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_5_0_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_5_0_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_5_0_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_5_0_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_5_0_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_5_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_5_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_5_0_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
} EFI_ACPI_5_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_5_0_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT32 ReadLatency;
  UINT32 WriteLatency;
  UINT32 ReadBandwidth;
  UINT32 WriteBandwidth;
  UINT16 OptimalAccessUnit;
  UINT16 OptimalAccessAlignment;
  UINT16 Reserved;
  UINT16 NumberOfProximityDomains;
} EFI_ACPI_5_0_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 PhysicalComponentIdentifier;
  UINT16 Reserved;
  UINT32 SizeOfDimm;
  UINT32 SmbiosHandle;
} EFI_ACPI_5_0_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_5_0_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_5_0_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_5_0_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_5_0_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_5_0_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_5_0_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_5_0_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_5_0_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 PhysicalAddress;
  UINT32 GlobalFlags;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
} EFI_ACPI_5_0_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_5_0_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_5_0_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_5_0_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_5_0_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
} EFI_ACPI_5_0_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_5_0_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_5_0_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_5_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_5_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_5_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_5_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_5_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_5_0_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_5_0_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_5_0_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_5_0_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_5_0_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_5_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_5_0_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_0_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_5_0_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_5_0_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_5_0_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_5_0_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_5_0_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_5_0_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_5_0_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_5_0_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_5_0_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_5_0_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 GenerateSci : 1;
} EFI_ACPI_5_0_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 SciDoorbell : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_5_0_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_5_0_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_5_0_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_5_0_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_5_1_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_5_1_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
} EFI_ACPI_5_1_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_5_1_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_5_1_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_5_1_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_5_1_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_5_1_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_5_1_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_5_1_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_5_1_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_5_1_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_5_1_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_5_1_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_5_1_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_5_1_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_5_1_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
} EFI_ACPI_5_1_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_5_1_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_5_1_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_5_1_GICR_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_5_1_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_5_1_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_5_1_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_5_1_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_5_1_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_5_1_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_5_1_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_5_1_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_5_1_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_5_1_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_5_1_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_5_1_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_5_1_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_5_1_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_5_1_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_5_1_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_5_1_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_5_1_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_5_1_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_5_1_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_5_1_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_5_1_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_5_1_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
} EFI_ACPI_5_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_5_1_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT32 ReadLatency;
  UINT32 WriteLatency;
  UINT32 ReadBandwidth;
  UINT32 WriteBandwidth;
  UINT16 OptimalAccessUnit;
  UINT16 OptimalAccessAlignment;
  UINT16 Reserved;
  UINT16 NumberOfProximityDomains;
} EFI_ACPI_5_1_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 PhysicalComponentIdentifier;
  UINT16 Reserved;
  UINT32 SizeOfDimm;
  UINT32 SmbiosHandle;
} EFI_ACPI_5_1_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_5_1_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_5_1_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_5_1_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_5_1_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_5_1_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_5_1_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_5_1_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_5_1_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_5_1_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_5_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_5_1_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_5_1_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
} EFI_ACPI_5_1_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_5_1_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_5_1_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_5_1_GTDT_SBSA_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_5_1_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_5_1_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_5_1_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_5_1_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
} EFI_ACPI_5_1_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_5_1_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_5_1_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_5_1_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_5_1_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_5_1_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_5_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_5_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_5_1_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_5_1_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_5_1_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_5_1_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_5_1_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_5_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_5_1_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_5_1_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_5_1_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_5_1_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_5_1_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_5_1_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_5_1_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_5_1_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_5_1_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_5_1_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_5_1_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_5_1_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 GenerateSci : 1;
} EFI_ACPI_5_1_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 SciDoorbell : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_5_1_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_5_1_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_5_1_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_5_1_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_6_0_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_0_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
  UINT64 HypervisorVendorIdentity;
} EFI_ACPI_6_0_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_6_0_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_6_0_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_6_0_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_6_0_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_6_0_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_6_0_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_6_0_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_6_0_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_6_0_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_6_0_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_6_0_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_6_0_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_6_0_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
  UINT8 ProcessorPowerEfficiencyClass;
  UINT8 Reserved2[3];
} EFI_ACPI_6_0_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_6_0_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_6_0_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_6_0_GICR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicItsId;
  UINT64 PhysicalBaseAddress;
  UINT32 Reserved2;
} EFI_ACPI_6_0_GIC_ITS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_6_0_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_6_0_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_6_0_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_6_0_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_6_0_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_6_0_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_6_0_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_6_0_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_6_0_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_6_0_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_6_0_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_6_0_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_6_0_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_6_0_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_6_0_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_6_0_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_6_0_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_6_0_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_0_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_0_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_0_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
} EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_0_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT32 ReadLatency;
  UINT32 WriteLatency;
  UINT32 ReadBandwidth;
  UINT32 WriteBandwidth;
  UINT16 OptimalAccessUnit;
  UINT16 OptimalAccessAlignment;
  UINT16 Reserved;
  UINT16 NumberOfProximityDomains;
} EFI_ACPI_6_0_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_0_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 PhysicalComponentIdentifier;
  UINT16 Reserved;
  UINT32 SizeOfDimm;
  UINT32 SmbiosHandle;
} EFI_ACPI_6_0_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_6_0_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_0_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_6_0_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_6_0_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_6_0_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_0_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_0_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_6_0_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_6_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_6_0_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_0_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
} EFI_ACPI_6_0_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_6_0_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_6_0_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_6_0_GTDT_SBSA_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_0_NVDIMM_FIRMWARE_INTERFACE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
} EFI_ACPI_6_0_NFIT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 SPARangeStructureIndex;
  UINT16 Flags;
  UINT32 Reserved_8;
  UINT32 ProximityDomain;
  GUID AddressRangeTypeGUID;
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
  UINT64 AddressRangeMemoryMappingAttribute;
} EFI_ACPI_6_0_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE;
typedef struct 
{
  UINT32 DIMMNumber : 4;
  UINT32 MemoryChannelNumber : 4;
  UINT32 MemoryControllerID : 4;
  UINT32 SocketID : 4;
  UINT32 NodeControllerID : 12;
  UINT32 Reserved_28 : 4;
} EFI_ACPI_6_0_NFIT_DEVICE_HANDLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_0_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 MemoryDevicePhysicalID;
  UINT16 MemoryDeviceRegionID;
  UINT16 SPARangeStructureIndex;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT64 MemoryDeviceRegionSize;
  UINT64 RegionOffset;
  UINT64 MemoryDevicePhysicalAddressRegionBase;
  UINT16 InterleaveStructureIndex;
  UINT16 InterleaveWays;
  UINT16 MemoryDeviceStateFlags;
  UINT16 Reserved_46;
} EFI_ACPI_6_0_NFIT_MEMORY_DEVICE_TO_SYSTEM_ADDRESS_RANGE_MAP_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 InterleaveStructureIndex;
  UINT16 Reserved_6;
  UINT32 NumberOfLines;
  UINT32 LineSize;
} EFI_ACPI_6_0_NFIT_INTERLEAVE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT32 Reserved_4;
} EFI_ACPI_6_0_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 VendorID;
  UINT16 DeviceID;
  UINT16 RevisionID;
  UINT16 SubsystemVendorID;
  UINT16 SubsystemDeviceID;
  UINT16 SubsystemRevisionID;
  UINT8 Reserved_18[6];
  UINT32 SerialNumber;
  UINT16 RegionFormatInterfaceCode;
  UINT16 NumberOfBlockControlWindows;
  UINT64 SizeOfBlockControlWindow;
  UINT64 CommandRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfCommandRegisterInBlockControlWindows;
  UINT64 StatusRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfStatusRegisterInBlockControlWindows;
  UINT16 NVDIMMControlRegionFlag;
  UINT8 Reserved_74[6];
} EFI_ACPI_6_0_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 NumberOfBlockDataWindows;
  UINT64 BlockDataWindowStartOffset;
  UINT64 SizeOfBlockDataWindow;
  UINT64 BlockAccessibleMemoryCapacity;
  UINT64 BeginningAddressOfFirstBlockInBlockAccessibleMemory;
} EFI_ACPI_6_0_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_0_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NumberOfFlushHintAddresses;
  UINT8 Reserved_10[6];
} EFI_ACPI_6_0_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_6_0_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_6_0_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_0_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
} EFI_ACPI_6_0_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_6_0_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_6_0_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_0_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_6_0_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_6_0_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_0_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_0_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_0_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_6_0_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_0_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_0_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_6_0_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_0_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_6_0_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_0_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_6_0_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_6_0_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_6_0_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_0_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 GenerateSci : 1;
} EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 SciDoorbell : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_6_0_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 DoorbellInterrupt;
  UINT8 DoorbellInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_0_PCCT_SUBSPACE_1_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 DoorbellInterrupt;
  UINT8 DoorbellInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_0_GENERIC_ADDRESS_STRUCTURE DoorbellAckRegister;
  UINT64 DoorbellAckPreserve;
  UINT64 DoorbellAckWrite;
} EFI_ACPI_6_0_PCCT_SUBSPACE_2_HW_REDUCED_COMMUNICATIONS;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_6_1_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_1_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
  UINT64 HypervisorVendorIdentity;
} EFI_ACPI_6_1_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_6_1_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_6_1_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_6_1_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_6_1_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_6_1_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_6_1_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_6_1_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_6_1_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_6_1_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_6_1_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_6_1_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_6_1_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_6_1_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_6_1_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
  UINT8 ProcessorPowerEfficiencyClass;
  UINT8 Reserved2[3];
} EFI_ACPI_6_1_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_6_1_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_6_1_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_6_1_GICR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicItsId;
  UINT64 PhysicalBaseAddress;
  UINT32 Reserved2;
} EFI_ACPI_6_1_GIC_ITS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_6_1_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_6_1_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_6_1_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_6_1_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_6_1_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_6_1_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_6_1_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_6_1_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_6_1_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_6_1_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_6_1_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_6_1_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_6_1_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_6_1_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_6_1_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_6_1_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_6_1_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_6_1_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_6_1_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_1_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_6_1_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_1_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_1_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
} EFI_ACPI_6_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_1_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT32 ReadLatency;
  UINT32 WriteLatency;
  UINT32 ReadBandwidth;
  UINT32 WriteBandwidth;
  UINT16 OptimalAccessUnit;
  UINT16 OptimalAccessAlignment;
  UINT16 Reserved;
  UINT16 NumberOfProximityDomains;
} EFI_ACPI_6_1_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_1_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 PhysicalComponentIdentifier;
  UINT16 Reserved;
  UINT32 SizeOfDimm;
  UINT32 SmbiosHandle;
} EFI_ACPI_6_1_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_6_1_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_6_1_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_1_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_6_1_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_6_1_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_6_1_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_1_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_1_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_6_1_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_6_1_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_6_1_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_1_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
} EFI_ACPI_6_1_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_6_1_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_6_1_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_6_1_GTDT_SBSA_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_1_NVDIMM_FIRMWARE_INTERFACE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
} EFI_ACPI_6_1_NFIT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 SPARangeStructureIndex;
  UINT16 Flags;
  UINT32 Reserved_8;
  UINT32 ProximityDomain;
  GUID AddressRangeTypeGUID;
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
  UINT64 AddressRangeMemoryMappingAttribute;
} EFI_ACPI_6_1_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE;
typedef struct 
{
  UINT32 DIMMNumber : 4;
  UINT32 MemoryChannelNumber : 4;
  UINT32 MemoryControllerID : 4;
  UINT32 SocketID : 4;
  UINT32 NodeControllerID : 12;
  UINT32 Reserved_28 : 4;
} EFI_ACPI_6_1_NFIT_DEVICE_HANDLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_1_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NVDIMMPhysicalID;
  UINT16 NVDIMMRegionID;
  UINT16 SPARangeStructureIndex;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT64 NVDIMMRegionSize;
  UINT64 RegionOffset;
  UINT64 NVDIMMPhysicalAddressRegionBase;
  UINT16 InterleaveStructureIndex;
  UINT16 InterleaveWays;
  UINT16 NVDIMMStateFlags;
  UINT16 Reserved_46;
} EFI_ACPI_6_1_NFIT_NVDIMM_REGION_MAPPING_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 InterleaveStructureIndex;
  UINT16 Reserved_6;
  UINT32 NumberOfLines;
  UINT32 LineSize;
} EFI_ACPI_6_1_NFIT_INTERLEAVE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT32 Reserved_4;
} EFI_ACPI_6_1_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 VendorID;
  UINT16 DeviceID;
  UINT16 RevisionID;
  UINT16 SubsystemVendorID;
  UINT16 SubsystemDeviceID;
  UINT16 SubsystemRevisionID;
  UINT8 ValidFields;
  UINT8 ManufacturingLocation;
  UINT16 ManufacturingDate;
  UINT8 Reserved_22[2];
  UINT32 SerialNumber;
  UINT16 RegionFormatInterfaceCode;
  UINT16 NumberOfBlockControlWindows;
  UINT64 SizeOfBlockControlWindow;
  UINT64 CommandRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfCommandRegisterInBlockControlWindows;
  UINT64 StatusRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfStatusRegisterInBlockControlWindows;
  UINT16 NVDIMMControlRegionFlag;
  UINT8 Reserved_74[6];
} EFI_ACPI_6_1_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 NumberOfBlockDataWindows;
  UINT64 BlockDataWindowStartOffset;
  UINT64 SizeOfBlockDataWindow;
  UINT64 BlockAccessibleMemoryCapacity;
  UINT64 BeginningAddressOfFirstBlockInBlockAccessibleMemory;
} EFI_ACPI_6_1_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_1_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NumberOfFlushHintAddresses;
  UINT8 Reserved_10[6];
} EFI_ACPI_6_1_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_6_1_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_6_1_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_6_1_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_1_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
  UINT8 Timestamp[8];
} EFI_ACPI_6_1_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_6_1_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_6_1_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_6_1_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_6_1_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_6_1_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_6_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_1_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_6_1_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_6_1_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_1_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_1_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_6_1_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_1_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE ReadAckRegister;
  UINT64 ReadAckPreserve;
  UINT64 ReadAckWrite;
} EFI_ACPI_6_1_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_1_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_1_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_6_1_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_1_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_6_1_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_1_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_6_1_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_6_1_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_6_1_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_1_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 GenerateSci : 1;
} EFI_ACPI_6_1_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 SciDoorbell : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_6_1_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_6_1_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_6_1_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_6_1_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 DoorbellInterrupt;
  UINT8 DoorbellInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_1_PCCT_SUBSPACE_1_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 DoorbellInterrupt;
  UINT8 DoorbellInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_1_GENERIC_ADDRESS_STRUCTURE DoorbellAckRegister;
  UINT64 DoorbellAckPreserve;
  UINT64 DoorbellAckWrite;
} EFI_ACPI_6_1_PCCT_SUBSPACE_2_HW_REDUCED_COMMUNICATIONS;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT16 Flags;
  UINT8 PinPullConfiguration;
  UINT16 FunctionNumber;
  UINT16 PinTableOffset;
  UINT8 ResourceSourceIndex;
  UINT16 ResourceSourceNameOffset;
  UINT16 VendorDataOffset;
  UINT16 VendorDataLength;
} EFI_ACPI_PIN_FUNCTION_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT16 Flags;
  UINT8 PinConfigurationType;
  UINT32 PinConfigurationValue;
  UINT16 PinTableOffset;
  UINT8 ResourceSourceIndex;
  UINT16 ResourceSourceNameOffset;
  UINT16 VendorDataOffset;
  UINT16 VendorDataLength;
} EFI_ACPI_PIN_CONFIGURATION_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT16 Flags;
  UINT16 PinTableOffset;
  UINT16 ResourceLabelOffset;
  UINT16 VendorDataOffset;
  UINT16 VendorDataLength;
} EFI_ACPI_PIN_GROUP_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT16 Flags;
  UINT16 FunctionNumber;
  UINT8 ResourceSourceIndex;
  UINT16 ResourceSourceNameOffset;
  UINT16 ResourceSourceLabelOffset;
  UINT16 VendorDataOffset;
  UINT16 VendorDataLength;
} EFI_ACPI_PIN_GROUP_FUNCTION_DESCRIPTOR;
typedef struct 
{
  ACPI_LARGE_RESOURCE_HEADER Header;
  UINT8 RevisionId;
  UINT16 Flags;
  UINT8 PinConfigurationType;
  UINT32 PinConfigurationValue;
  UINT8 ResourceSourceIndex;
  UINT16 ResourceSourceNameOffset;
  UINT16 ResourceSourceLabelOffset;
  UINT16 VendorDataOffset;
  UINT16 VendorDataLength;
} EFI_ACPI_PIN_GROUP_CONFIGURATION_DESCRIPTOR;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_6_2_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_2_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
  UINT64 HypervisorVendorIdentity;
} EFI_ACPI_6_2_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_6_2_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_6_2_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_6_2_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_6_2_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_6_2_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_6_2_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_6_2_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_6_2_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_6_2_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_6_2_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_6_2_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_6_2_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_6_2_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_6_2_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
  UINT8 ProcessorPowerEfficiencyClass;
  UINT8 Reserved2[3];
} EFI_ACPI_6_2_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_6_2_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_6_2_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_6_2_GICR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicItsId;
  UINT64 PhysicalBaseAddress;
  UINT32 Reserved2;
} EFI_ACPI_6_2_GIC_ITS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_6_2_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_6_2_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_6_2_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_6_2_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_6_2_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_6_2_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_6_2_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT8 Reserved[2];
  UINT32 ItsId;
} EFI_ACPI_6_2_GIC_ITS_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_6_2_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_6_2_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_6_2_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_6_2_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_6_2_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_6_2_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_6_2_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_6_2_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_6_2_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_6_2_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_6_2_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_6_2_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_2_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_6_2_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_2_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_2_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
} EFI_ACPI_6_2_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_2_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_2_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_2_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT32 ReadLatency;
  UINT32 WriteLatency;
  UINT32 ReadBandwidth;
  UINT32 WriteBandwidth;
  UINT16 OptimalAccessUnit;
  UINT16 OptimalAccessAlignment;
  UINT16 Reserved;
  UINT16 NumberOfProximityDomains;
} EFI_ACPI_6_2_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_2_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 PhysicalComponentIdentifier;
  UINT16 Reserved;
  UINT32 SizeOfDimm;
  UINT32 SmbiosHandle;
} EFI_ACPI_6_2_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_6_2_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_6_2_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_2_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_6_2_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_6_2_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_6_2_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_2_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_2_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_6_2_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_6_2_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_6_2_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_2_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
} EFI_ACPI_6_2_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_6_2_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_6_2_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_6_2_GTDT_SBSA_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_2_NVDIMM_FIRMWARE_INTERFACE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
} EFI_ACPI_6_2_NFIT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 SPARangeStructureIndex;
  UINT16 Flags;
  UINT32 Reserved_8;
  UINT32 ProximityDomain;
  GUID AddressRangeTypeGUID;
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
  UINT64 AddressRangeMemoryMappingAttribute;
} EFI_ACPI_6_2_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE;
typedef struct 
{
  UINT32 DIMMNumber : 4;
  UINT32 MemoryChannelNumber : 4;
  UINT32 MemoryControllerID : 4;
  UINT32 SocketID : 4;
  UINT32 NodeControllerID : 12;
  UINT32 Reserved_28 : 4;
} EFI_ACPI_6_2_NFIT_DEVICE_HANDLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_2_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NVDIMMPhysicalID;
  UINT16 NVDIMMRegionID;
  UINT16 SPARangeStructureIndex;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT64 NVDIMMRegionSize;
  UINT64 RegionOffset;
  UINT64 NVDIMMPhysicalAddressRegionBase;
  UINT16 InterleaveStructureIndex;
  UINT16 InterleaveWays;
  UINT16 NVDIMMStateFlags;
  UINT16 Reserved_46;
} EFI_ACPI_6_2_NFIT_NVDIMM_REGION_MAPPING_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 InterleaveStructureIndex;
  UINT16 Reserved_6;
  UINT32 NumberOfLines;
  UINT32 LineSize;
} EFI_ACPI_6_2_NFIT_INTERLEAVE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT32 Reserved_4;
} EFI_ACPI_6_2_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 VendorID;
  UINT16 DeviceID;
  UINT16 RevisionID;
  UINT16 SubsystemVendorID;
  UINT16 SubsystemDeviceID;
  UINT16 SubsystemRevisionID;
  UINT8 ValidFields;
  UINT8 ManufacturingLocation;
  UINT16 ManufacturingDate;
  UINT8 Reserved_22[2];
  UINT32 SerialNumber;
  UINT16 RegionFormatInterfaceCode;
  UINT16 NumberOfBlockControlWindows;
  UINT64 SizeOfBlockControlWindow;
  UINT64 CommandRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfCommandRegisterInBlockControlWindows;
  UINT64 StatusRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfStatusRegisterInBlockControlWindows;
  UINT16 NVDIMMControlRegionFlag;
  UINT8 Reserved_74[6];
} EFI_ACPI_6_2_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 NumberOfBlockDataWindows;
  UINT64 BlockDataWindowStartOffset;
  UINT64 SizeOfBlockDataWindow;
  UINT64 BlockAccessibleMemoryCapacity;
  UINT64 BeginningAddressOfFirstBlockInBlockAccessibleMemory;
} EFI_ACPI_6_2_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_2_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NumberOfFlushHintAddresses;
  UINT8 Reserved_10[6];
} EFI_ACPI_6_2_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT8 HighestValidCapability;
  UINT8 Reserved_5[3];
  UINT32 Capabilities;
  UINT8 Reserved_12[4];
} EFI_ACPI_6_2_NFIT_PLATFORM_CAPABILITIES_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_2_SECURE_DEVICES_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
} EFI_ACPI_6_2_SDEV_STRUCTURE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
  UINT16 PciSegmentNumber;
  UINT16 StartBusNumber;
  UINT16 PciPathOffset;
  UINT16 PciPathLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
} EFI_ACPI_6_2_SDEV_STRUCTURE_PCIE_ENDPOINT_DEVICE;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
  UINT16 DeviceIdentifierOffset;
  UINT16 DeviceIdentifierLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
} EFI_ACPI_6_2_SDEV_STRUCTURE_ACPI_NAMESPACE_DEVICE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_6_2_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_6_2_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_6_2_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_2_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
  UINT8 Timestamp[8];
} EFI_ACPI_6_2_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_6_2_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_6_2_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_6_2_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_2_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_6_2_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_6_2_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_2_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_2_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_6_2_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE ReadAckRegister;
  UINT64 ReadAckPreserve;
  UINT64 ReadAckWrite;
} EFI_ACPI_6_2_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_2_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_2_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_2_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_2_IA32_ARCHITECTURE_DEFERRED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[4];
} EFI_ACPI_6_2_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
} EFI_ACPI_6_2_HMAT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 ProcessorProximityDomainValid : 1;
  UINT16 MemoryProximityDomainValid : 1;
  UINT16 ReservationHint : 1;
  UINT16 Reserved : 13;
} EFI_ACPI_6_2_HMAT_STRUCTURE_MEMORY_SUBSYSTEM_ADDRESS_RANGE_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_2_HMAT_STRUCTURE_MEMORY_SUBSYSTEM_ADDRESS_RANGE_FLAGS Flags;
  UINT8 Reserved1[2];
  UINT32 ProcessorProximityDomain;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved2[4];
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
} EFI_ACPI_6_2_HMAT_STRUCTURE_MEMORY_SUBSYSTEM_ADDRESS_RANGE;
typedef struct 
{
  UINT8 MemoryHierarchy : 5;
  UINT8 Reserved : 3;
} EFI_ACPI_6_2_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_2_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS Flags;
  UINT8 DataType;
  UINT8 Reserved1[2];
  UINT32 NumberOfInitiatorProximityDomains;
  UINT32 NumberOfTargetProximityDomains;
  UINT8 Reserved2[4];
  UINT64 EntryBaseUnit;
} EFI_ACPI_6_2_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO;
typedef struct 
{
  UINT32 TotalCacheLevels : 4;
  UINT32 CacheLevel : 4;
  UINT32 CacheAssociativity : 4;
  UINT32 WritePolicy : 4;
  UINT32 CacheLineSize : 16;
} EFI_ACPI_6_2_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved1[4];
  UINT64 MemorySideCacheSize;
  EFI_ACPI_6_2_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES CacheAttributes;
  UINT8 Reserved2[2];
  UINT16 NumberOfSmbiosHandles;
} EFI_ACPI_6_2_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_6_2_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_2_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_6_2_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_2_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_6_2_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_6_2_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_6_2_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_2_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 NotifyOnCompletion : 1;
} EFI_ACPI_6_2_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 PlatformInterrupt : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_6_2_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_6_2_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_6_2_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_6_2_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_2_PCCT_SUBSPACE_1_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckWrite;
} EFI_ACPI_6_2_PCCT_SUBSPACE_2_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT32 AddressLength;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT32 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckSet;
  UINT8 Reserved1[8];
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE CommandCompleteCheckRegister;
  UINT64 CommandCompleteCheckMask;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE CommandCompleteUpdateRegister;
  UINT64 CommandCompleteUpdatePreserve;
  UINT64 CommandCompleteUpdateSet;
  EFI_ACPI_6_2_GENERIC_ADDRESS_STRUCTURE ErrorStatusRegister;
  UINT64 ErrorStatusMask;
} EFI_ACPI_6_2_PCCT_SUBSPACE_3_EXTENDED_PCC;
typedef EFI_ACPI_6_2_PCCT_SUBSPACE_3_EXTENDED_PCC EFI_ACPI_6_2_PCCT_SUBSPACE_4_EXTENDED_PCC;
typedef struct 
{
  UINT32 Signature;
  UINT32 Flags;
  UINT32 Length;
  UINT32 Command;
} EFI_ACPI_6_2_PCCT_EXTENDED_PCC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 TriggerCount;
  UINT8 Reserved[3];
  UINT32 TriggerIdentifierArrayOffset;
} EFI_ACPI_6_2_PLATFORM_DEBUG_TRIGGER_TABLE_HEADER;
typedef struct 
{
  UINT16 SubChannelIdentifer : 8;
  UINT16 Runtime : 1;
  UINT16 WaitForCompletion : 1;
  UINT16 Reserved : 6;
} EFI_ACPI_6_2_PDTT_PCC_IDENTIFIER;
typedef EFI_ACPI_6_2_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER EFI_ACPI_6_2_PDTT_PCC;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
} EFI_ACPI_6_2_PPTT_STRUCTURE_HEADER;
typedef struct 
{
  UINT32 PhysicalPackage : 1;
  UINT32 AcpiProcessorIdValid : 1;
  UINT32 Reserved : 30;
} EFI_ACPI_6_2_PPTT_STRUCTURE_PROCESSOR_FLAGS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_2_PPTT_STRUCTURE_PROCESSOR_FLAGS Flags;
  UINT32 Parent;
  UINT32 AcpiProcessorId;
  UINT32 NumberOfPrivateResources;
} EFI_ACPI_6_2_PPTT_STRUCTURE_PROCESSOR;
typedef struct 
{
  UINT32 SizePropertyValid : 1;
  UINT32 NumberOfSetsValid : 1;
  UINT32 AssociativityValid : 1;
  UINT32 AllocationTypeValid : 1;
  UINT32 CacheTypeValid : 1;
  UINT32 WritePolicyValid : 1;
  UINT32 LineSizeValid : 1;
  UINT32 Reserved : 25;
} EFI_ACPI_6_2_PPTT_STRUCTURE_CACHE_FLAGS;
typedef struct 
{
  UINT8 AllocationType : 2;
  UINT8 CacheType : 2;
  UINT8 WritePolicy : 1;
  UINT8 Reserved : 3;
} EFI_ACPI_6_2_PPTT_STRUCTURE_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_2_PPTT_STRUCTURE_CACHE_FLAGS Flags;
  UINT32 NextLevelOfCache;
  UINT32 Size;
  UINT32 NumberOfSets;
  UINT8 Associativity;
  EFI_ACPI_6_2_PPTT_STRUCTURE_CACHE_ATTRIBUTES Attributes;
  UINT16 LineSize;
} EFI_ACPI_6_2_PPTT_STRUCTURE_CACHE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 VendorId;
  UINT64 Level1Id;
  UINT64 Level2Id;
  UINT16 MajorRev;
  UINT16 MinorRev;
  UINT16 SpinRev;
} EFI_ACPI_6_2_PPTT_STRUCTURE_ID;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_6_3_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_3_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
  UINT64 HypervisorVendorIdentity;
} EFI_ACPI_6_3_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_6_3_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_6_3_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_6_3_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_6_3_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_6_3_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_6_3_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_6_3_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_6_3_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_6_3_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_6_3_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_6_3_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_6_3_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_6_3_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_6_3_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
  UINT8 ProcessorPowerEfficiencyClass;
  UINT8 Reserved2;
  UINT16 SpeOverflowInterrupt;
} EFI_ACPI_6_3_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_6_3_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_6_3_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_6_3_GICR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicItsId;
  UINT64 PhysicalBaseAddress;
  UINT32 Reserved2;
} EFI_ACPI_6_3_GIC_ITS_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_6_3_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_6_3_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_6_3_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_6_3_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_6_3_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_6_3_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_6_3_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT8 Reserved[2];
  UINT32 ItsId;
} EFI_ACPI_6_3_GIC_ITS_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT64 AcpiHid;
  UINT32 AcpiUid;
  UINT8 Reserved[4];
} EFI_ACPI_6_3_DEVICE_HANDLE_ACPI;
typedef struct 
{
  UINT16 PciSegment;
  UINT16 PciBdfNumber;
  UINT8 Reserved[12];
} EFI_ACPI_6_3_DEVICE_HANDLE_PCI;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1;
  UINT8 DeviceHandleType;
  UINT32 ProximityDomain;
  union 
  {
    EFI_ACPI_6_3_DEVICE_HANDLE_ACPI Acpi;
    EFI_ACPI_6_3_DEVICE_HANDLE_PCI Pci;
  } DeviceHandle;
  UINT32 Flags;
  UINT8 Reserved2[4];
} EFI_ACPI_6_3_GENERIC_INITIATOR_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_6_3_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_6_3_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_6_3_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_6_3_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_6_3_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_6_3_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_6_3_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_6_3_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_6_3_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_6_3_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_6_3_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_6_3_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_3_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_6_3_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_3_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_3_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
} EFI_ACPI_6_3_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_3_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_3_PMMT_SOCKET_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_3_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT32 ReadLatency;
  UINT32 WriteLatency;
  UINT32 ReadBandwidth;
  UINT32 WriteBandwidth;
  UINT16 OptimalAccessUnit;
  UINT16 OptimalAccessAlignment;
  UINT16 Reserved;
  UINT16 NumberOfProximityDomains;
} EFI_ACPI_6_3_PMMT_MEMORY_CONTROLLER_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_3_PMMT_COMMON_MEMORY_AGGREGATOR_DEVICE_STRUCTURE Header;
  UINT16 PhysicalComponentIdentifier;
  UINT16 Reserved;
  UINT32 SizeOfDimm;
  UINT32 SmbiosHandle;
} EFI_ACPI_6_3_PMMT_DIMM_MEMORY_AGGREGATOR_DEVICE_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_6_3_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_6_3_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_3_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_6_3_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_6_3_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_6_3_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_3_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_3_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_6_3_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_6_3_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_6_3_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_3_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
  UINT32 VirtualPL2TimerGSIV;
  UINT32 VirtualPL2TimerFlags;
} EFI_ACPI_6_3_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_6_3_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_6_3_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_6_3_GTDT_SBSA_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_3_NVDIMM_FIRMWARE_INTERFACE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
} EFI_ACPI_6_3_NFIT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 SPARangeStructureIndex;
  UINT16 Flags;
  UINT32 Reserved_8;
  UINT32 ProximityDomain;
  GUID AddressRangeTypeGUID;
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
  UINT64 AddressRangeMemoryMappingAttribute;
} EFI_ACPI_6_3_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE;
typedef struct 
{
  UINT32 DIMMNumber : 4;
  UINT32 MemoryChannelNumber : 4;
  UINT32 MemoryControllerID : 4;
  UINT32 SocketID : 4;
  UINT32 NodeControllerID : 12;
  UINT32 Reserved_28 : 4;
} EFI_ACPI_6_3_NFIT_DEVICE_HANDLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_3_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NVDIMMPhysicalID;
  UINT16 NVDIMMRegionID;
  UINT16 SPARangeStructureIndex;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT64 NVDIMMRegionSize;
  UINT64 RegionOffset;
  UINT64 NVDIMMPhysicalAddressRegionBase;
  UINT16 InterleaveStructureIndex;
  UINT16 InterleaveWays;
  UINT16 NVDIMMStateFlags;
  UINT16 Reserved_46;
} EFI_ACPI_6_3_NFIT_NVDIMM_REGION_MAPPING_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 InterleaveStructureIndex;
  UINT16 Reserved_6;
  UINT32 NumberOfLines;
  UINT32 LineSize;
} EFI_ACPI_6_3_NFIT_INTERLEAVE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT32 Reserved_4;
} EFI_ACPI_6_3_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 VendorID;
  UINT16 DeviceID;
  UINT16 RevisionID;
  UINT16 SubsystemVendorID;
  UINT16 SubsystemDeviceID;
  UINT16 SubsystemRevisionID;
  UINT8 ValidFields;
  UINT8 ManufacturingLocation;
  UINT16 ManufacturingDate;
  UINT8 Reserved_22[2];
  UINT32 SerialNumber;
  UINT16 RegionFormatInterfaceCode;
  UINT16 NumberOfBlockControlWindows;
  UINT64 SizeOfBlockControlWindow;
  UINT64 CommandRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfCommandRegisterInBlockControlWindows;
  UINT64 StatusRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfStatusRegisterInBlockControlWindows;
  UINT16 NVDIMMControlRegionFlag;
  UINT8 Reserved_74[6];
} EFI_ACPI_6_3_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 NumberOfBlockDataWindows;
  UINT64 BlockDataWindowStartOffset;
  UINT64 SizeOfBlockDataWindow;
  UINT64 BlockAccessibleMemoryCapacity;
  UINT64 BeginningAddressOfFirstBlockInBlockAccessibleMemory;
} EFI_ACPI_6_3_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_3_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NumberOfFlushHintAddresses;
  UINT8 Reserved_10[6];
} EFI_ACPI_6_3_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT8 HighestValidCapability;
  UINT8 Reserved_5[3];
  UINT32 Capabilities;
  UINT8 Reserved_12[4];
} EFI_ACPI_6_3_NFIT_PLATFORM_CAPABILITIES_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_3_SECURE_DEVICES_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
} EFI_ACPI_6_3_SDEV_STRUCTURE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
  UINT16 PciSegmentNumber;
  UINT16 StartBusNumber;
  UINT16 PciPathOffset;
  UINT16 PciPathLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
} EFI_ACPI_6_3_SDEV_STRUCTURE_PCIE_ENDPOINT_DEVICE;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
  UINT16 DeviceIdentifierOffset;
  UINT16 DeviceIdentifierLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
} EFI_ACPI_6_3_SDEV_STRUCTURE_ACPI_NAMESPACE_DEVICE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_6_3_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_6_3_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_6_3_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_3_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
  UINT8 Timestamp[8];
} EFI_ACPI_6_3_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_6_3_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_6_3_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_6_3_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_3_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_6_3_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_6_3_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_3_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_3_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_6_3_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE ReadAckRegister;
  UINT64 ReadAckPreserve;
  UINT64 ReadAckWrite;
} EFI_ACPI_6_3_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_3_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_3_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_3_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_3_IA32_ARCHITECTURE_DEFERRED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[4];
} EFI_ACPI_6_3_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
} EFI_ACPI_6_3_HMAT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 InitiatorProximityDomainValid : 1;
  UINT16 Reserved : 15;
} EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_FLAGS Flags;
  UINT8 Reserved1[2];
  UINT32 InitiatorProximityDomain;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved2[20];
} EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES;
typedef struct 
{
  UINT8 MemoryHierarchy : 4;
  UINT8 Reserved : 4;
} EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS Flags;
  UINT8 DataType;
  UINT8 Reserved1[2];
  UINT32 NumberOfInitiatorProximityDomains;
  UINT32 NumberOfTargetProximityDomains;
  UINT8 Reserved2[4];
  UINT64 EntryBaseUnit;
} EFI_ACPI_6_3_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO;
typedef struct 
{
  UINT32 TotalCacheLevels : 4;
  UINT32 CacheLevel : 4;
  UINT32 CacheAssociativity : 4;
  UINT32 WritePolicy : 4;
  UINT32 CacheLineSize : 16;
} EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved1[4];
  UINT64 MemorySideCacheSize;
  EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES CacheAttributes;
  UINT8 Reserved2[2];
  UINT16 NumberOfSmbiosHandles;
} EFI_ACPI_6_3_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_6_3_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_3_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_6_3_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_3_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_6_3_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_6_3_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_6_3_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_3_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 NotifyOnCompletion : 1;
} EFI_ACPI_6_3_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 PlatformInterrupt : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_6_3_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_6_3_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_6_3_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_6_3_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_3_PCCT_SUBSPACE_1_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckWrite;
} EFI_ACPI_6_3_PCCT_SUBSPACE_2_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT32 AddressLength;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT32 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckSet;
  UINT8 Reserved1[8];
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE CommandCompleteCheckRegister;
  UINT64 CommandCompleteCheckMask;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE CommandCompleteUpdateRegister;
  UINT64 CommandCompleteUpdatePreserve;
  UINT64 CommandCompleteUpdateSet;
  EFI_ACPI_6_3_GENERIC_ADDRESS_STRUCTURE ErrorStatusRegister;
  UINT64 ErrorStatusMask;
} EFI_ACPI_6_3_PCCT_SUBSPACE_3_EXTENDED_PCC;
typedef EFI_ACPI_6_3_PCCT_SUBSPACE_3_EXTENDED_PCC EFI_ACPI_6_3_PCCT_SUBSPACE_4_EXTENDED_PCC;
typedef struct 
{
  UINT32 Signature;
  UINT32 Flags;
  UINT32 Length;
  UINT32 Command;
} EFI_ACPI_6_3_PCCT_EXTENDED_PCC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 TriggerCount;
  UINT8 Reserved[3];
  UINT32 TriggerIdentifierArrayOffset;
} EFI_ACPI_6_3_PLATFORM_DEBUG_TRIGGER_TABLE_HEADER;
typedef struct 
{
  UINT16 SubChannelIdentifer : 8;
  UINT16 Runtime : 1;
  UINT16 WaitForCompletion : 1;
  UINT16 TriggerOrder : 1;
  UINT16 Reserved : 5;
} EFI_ACPI_6_3_PDTT_PCC_IDENTIFIER;
typedef EFI_ACPI_6_3_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER EFI_ACPI_6_3_PDTT_PCC;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_3_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
} EFI_ACPI_6_3_PPTT_STRUCTURE_HEADER;
typedef struct 
{
  UINT32 PhysicalPackage : 1;
  UINT32 AcpiProcessorIdValid : 1;
  UINT32 ProcessorIsAThread : 1;
  UINT32 NodeIsALeaf : 1;
  UINT32 IdenticalImplementation : 1;
  UINT32 Reserved : 27;
} EFI_ACPI_6_3_PPTT_STRUCTURE_PROCESSOR_FLAGS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_3_PPTT_STRUCTURE_PROCESSOR_FLAGS Flags;
  UINT32 Parent;
  UINT32 AcpiProcessorId;
  UINT32 NumberOfPrivateResources;
} EFI_ACPI_6_3_PPTT_STRUCTURE_PROCESSOR;
typedef struct 
{
  UINT32 SizePropertyValid : 1;
  UINT32 NumberOfSetsValid : 1;
  UINT32 AssociativityValid : 1;
  UINT32 AllocationTypeValid : 1;
  UINT32 CacheTypeValid : 1;
  UINT32 WritePolicyValid : 1;
  UINT32 LineSizeValid : 1;
  UINT32 Reserved : 25;
} EFI_ACPI_6_3_PPTT_STRUCTURE_CACHE_FLAGS;
typedef struct 
{
  UINT8 AllocationType : 2;
  UINT8 CacheType : 2;
  UINT8 WritePolicy : 1;
  UINT8 Reserved : 3;
} EFI_ACPI_6_3_PPTT_STRUCTURE_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_3_PPTT_STRUCTURE_CACHE_FLAGS Flags;
  UINT32 NextLevelOfCache;
  UINT32 Size;
  UINT32 NumberOfSets;
  UINT8 Associativity;
  EFI_ACPI_6_3_PPTT_STRUCTURE_CACHE_ATTRIBUTES Attributes;
  UINT16 LineSize;
} EFI_ACPI_6_3_PPTT_STRUCTURE_CACHE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 VendorId;
  UINT64 Level1Id;
  UINT64 Level2Id;
  UINT16 MajorRev;
  UINT16 MinorRev;
  UINT16 SpinRev;
} EFI_ACPI_6_3_PPTT_STRUCTURE_ID;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_6_4_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_4_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
  UINT64 HypervisorVendorIdentity;
} EFI_ACPI_6_4_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_6_4_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_6_4_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_6_4_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_6_4_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_6_4_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_6_4_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_6_4_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_6_4_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_6_4_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_6_4_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_6_4_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_6_4_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_6_4_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_6_4_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
  UINT8 ProcessorPowerEfficiencyClass;
  UINT8 Reserved2;
  UINT16 SpeOverflowInterrupt;
} EFI_ACPI_6_4_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_6_4_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_6_4_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_6_4_GICR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicItsId;
  UINT64 PhysicalBaseAddress;
  UINT32 Reserved2;
} EFI_ACPI_6_4_GIC_ITS_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 MailBoxVersion;
  UINT32 Reserved;
  UINT64 MailBoxAddress;
} EFI_ACPI_6_4_MULTIPROCESSOR_WAKEUP_STRUCTURE;
typedef struct 
{
  UINT16 Command;
  UINT16 Reserved;
  UINT32 AcpiId;
  UINT64 WakeupVector;
  UINT8 ReservedForOs[2032];
  UINT8 ReservedForFirmware[2048];
} EFI_ACPI_6_4_MULTIPROCESSOR_WAKEUP_MAILBOX_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_6_4_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_6_4_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_6_4_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_6_4_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_6_4_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_6_4_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_6_4_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT8 Reserved[2];
  UINT32 ItsId;
} EFI_ACPI_6_4_GIC_ITS_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT64 AcpiHid;
  UINT32 AcpiUid;
  UINT8 Reserved[4];
} EFI_ACPI_6_4_DEVICE_HANDLE_ACPI;
typedef struct 
{
  UINT16 PciSegment;
  UINT16 PciBdfNumber;
  UINT8 Reserved[12];
} EFI_ACPI_6_4_DEVICE_HANDLE_PCI;
typedef union 
{
  EFI_ACPI_6_4_DEVICE_HANDLE_ACPI Acpi;
  EFI_ACPI_6_4_DEVICE_HANDLE_PCI Pci;
} EFI_ACPI_6_4_DEVICE_HANDLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1;
  UINT8 DeviceHandleType;
  UINT32 ProximityDomain;
  EFI_ACPI_6_4_DEVICE_HANDLE DeviceHandle;
  UINT32 Flags;
  UINT8 Reserved2[4];
} EFI_ACPI_6_4_GENERIC_INITIATOR_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_6_4_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_6_4_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_6_4_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_6_4_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_6_4_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_6_4_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_6_4_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_6_4_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_6_4_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_6_4_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_6_4_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_6_4_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_4_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_6_4_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_4_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 NumberOfMemoryDevices;
} EFI_ACPI_6_4_PLATFORM_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
  UINT32 NumberOfMemoryDevices;
} EFI_ACPI_6_4_PMTT_COMMON_MEMORY_DEVICE;
typedef struct 
{
  EFI_ACPI_6_4_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_4_PMTT_SOCKET_TYPE_DATA;
typedef struct 
{
  EFI_ACPI_6_4_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT16 MemoryControllerIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_4_PMTT_MEMORY_CONTROLLER_TYPE_DATA;
typedef struct 
{
  EFI_ACPI_6_4_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT32 SmbiosHandle;
} EFI_ACPI_6_4_PMTT_DIMM_TYPE_SPECIFIC_DATA;
typedef struct 
{
  EFI_ACPI_6_4_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT8 TypeUuid[16];
} EFI_ACPI_6_4_PMTT_VENDOR_SPECIFIC_TYPE_DATA;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_6_4_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_6_4_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_4_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_6_4_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_6_4_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_6_4_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_4_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_4_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_6_4_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_6_4_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_6_4_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_4_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
  UINT32 VirtualPL2TimerGSIV;
  UINT32 VirtualPL2TimerFlags;
} EFI_ACPI_6_4_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_6_4_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_6_4_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_6_4_GTDT_ARM_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_4_NVDIMM_FIRMWARE_INTERFACE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
} EFI_ACPI_6_4_NFIT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 SPARangeStructureIndex;
  UINT16 Flags;
  UINT32 Reserved_8;
  UINT32 ProximityDomain;
  GUID AddressRangeTypeGUID;
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
  UINT64 AddressRangeMemoryMappingAttribute;
  UINT64 SPALocationCookie;
} EFI_ACPI_6_4_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE;
typedef struct 
{
  UINT32 DIMMNumber : 4;
  UINT32 MemoryChannelNumber : 4;
  UINT32 MemoryControllerID : 4;
  UINT32 SocketID : 4;
  UINT32 NodeControllerID : 12;
  UINT32 Reserved_28 : 4;
} EFI_ACPI_6_4_NFIT_DEVICE_HANDLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_4_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NVDIMMPhysicalID;
  UINT16 NVDIMMRegionID;
  UINT16 SPARangeStructureIndex;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT64 NVDIMMRegionSize;
  UINT64 RegionOffset;
  UINT64 NVDIMMPhysicalAddressRegionBase;
  UINT16 InterleaveStructureIndex;
  UINT16 InterleaveWays;
  UINT16 NVDIMMStateFlags;
  UINT16 Reserved_46;
} EFI_ACPI_6_4_NFIT_NVDIMM_REGION_MAPPING_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 InterleaveStructureIndex;
  UINT16 Reserved_6;
  UINT32 NumberOfLines;
  UINT32 LineSize;
} EFI_ACPI_6_4_NFIT_INTERLEAVE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT32 Reserved_4;
} EFI_ACPI_6_4_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 VendorID;
  UINT16 DeviceID;
  UINT16 RevisionID;
  UINT16 SubsystemVendorID;
  UINT16 SubsystemDeviceID;
  UINT16 SubsystemRevisionID;
  UINT8 ValidFields;
  UINT8 ManufacturingLocation;
  UINT16 ManufacturingDate;
  UINT8 Reserved_22[2];
  UINT32 SerialNumber;
  UINT16 RegionFormatInterfaceCode;
  UINT16 NumberOfBlockControlWindows;
  UINT64 SizeOfBlockControlWindow;
  UINT64 CommandRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfCommandRegisterInBlockControlWindows;
  UINT64 StatusRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfStatusRegisterInBlockControlWindows;
  UINT16 NVDIMMControlRegionFlag;
  UINT8 Reserved_74[6];
} EFI_ACPI_6_4_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 NumberOfBlockDataWindows;
  UINT64 BlockDataWindowStartOffset;
  UINT64 SizeOfBlockDataWindow;
  UINT64 BlockAccessibleMemoryCapacity;
  UINT64 BeginningAddressOfFirstBlockInBlockAccessibleMemory;
} EFI_ACPI_6_4_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_4_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NumberOfFlushHintAddresses;
  UINT8 Reserved_10[6];
} EFI_ACPI_6_4_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT8 HighestValidCapability;
  UINT8 Reserved_5[3];
  UINT32 Capabilities;
  UINT8 Reserved_12[4];
} EFI_ACPI_6_4_NFIT_PLATFORM_CAPABILITIES_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_4_SECURE_DEVICES_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
} EFI_ACPI_6_4_SDEV_STRUCTURE_HEADER;
typedef struct 
{
  EFI_ACPI_6_4_SDEV_STRUCTURE_HEADER Header;
  UINT16 DeviceIdentifierOffset;
  UINT16 DeviceIdentifierLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
  UINT16 SecureAccessComponentsOffset;
  UINT16 SecureAccessComponentsLength;
} EFI_ACPI_6_4_SDEV_STRUCTURE_ACPI_NAMESPACE_DEVICE;
typedef struct 
{
  EFI_ACPI_6_4_SDEV_STRUCTURE_HEADER Header;
  UINT16 HardwareIdentifierOffset;
  UINT16 HardwareIdentifierLength;
  UINT16 SubsystemIdentifierOffset;
  UINT16 SubsystemIdentifierLength;
  UINT16 HardwareRevision;
  UINT8 HardwareRevisionPresent;
  UINT8 ClassCodePresent;
  UINT8 PciCompatibleBaseClass;
  UINT8 PciCompatibleSubClass;
  UINT8 PciCompatibleProgrammingInterface;
} EFI_ACPI_6_4_SDEV_SECURE_ACCESS_COMPONENT_IDENTIFICATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_4_SDEV_STRUCTURE_HEADER Header;
  UINT32 Reserved;
  UINT64 MemoryAddressBase;
  UINT64 MemoryLength;
} EFI_ACPI_6_4_SDEV_SECURE_ACCESS_COMPONENT_MEMORY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_4_SDEV_STRUCTURE_HEADER Header;
  UINT16 PciSegmentNumber;
  UINT16 StartBusNumber;
  UINT16 PciPathOffset;
  UINT16 PciPathLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
} EFI_ACPI_6_4_SDEV_STRUCTURE_PCIE_ENDPOINT_DEVICE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_6_4_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_6_4_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_6_4_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_4_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
  UINT8 Timestamp[8];
} EFI_ACPI_6_4_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_6_4_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_6_4_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_6_4_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_4_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_6_4_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_6_4_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_4_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_4_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_6_4_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE ReadAckRegister;
  UINT64 ReadAckPreserve;
  UINT64 ReadAckWrite;
} EFI_ACPI_6_4_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_4_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_4_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_4_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_4_IA32_ARCHITECTURE_DEFERRED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[4];
} EFI_ACPI_6_4_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
} EFI_ACPI_6_4_HMAT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 InitiatorProximityDomainValid : 1;
  UINT16 Reserved : 15;
} EFI_ACPI_6_4_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_4_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_FLAGS Flags;
  UINT8 Reserved1[2];
  UINT32 InitiatorProximityDomain;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved2[20];
} EFI_ACPI_6_4_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES;
typedef struct 
{
  UINT8 MemoryHierarchy : 4;
  UINT8 AccessAttributes : 2;
  UINT8 Reserved : 2;
} EFI_ACPI_6_4_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_4_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS Flags;
  UINT8 DataType;
  UINT8 MinTransferSize;
  UINT8 Reserved1;
  UINT32 NumberOfInitiatorProximityDomains;
  UINT32 NumberOfTargetProximityDomains;
  UINT8 Reserved2[4];
  UINT64 EntryBaseUnit;
} EFI_ACPI_6_4_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO;
typedef struct 
{
  UINT32 TotalCacheLevels : 4;
  UINT32 CacheLevel : 4;
  UINT32 CacheAssociativity : 4;
  UINT32 WritePolicy : 4;
  UINT32 CacheLineSize : 16;
} EFI_ACPI_6_4_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved1[4];
  UINT64 MemorySideCacheSize;
  EFI_ACPI_6_4_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES CacheAttributes;
  UINT8 Reserved2[2];
  UINT16 NumberOfSmbiosHandles;
} EFI_ACPI_6_4_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_6_4_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_4_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_6_4_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_4_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_6_4_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_6_4_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_6_4_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_4_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 NotifyOnCompletion : 1;
} EFI_ACPI_6_4_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 PlatformInterrupt : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_6_4_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_6_4_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_6_4_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_6_4_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_4_PCCT_SUBSPACE_1_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckWrite;
} EFI_ACPI_6_4_PCCT_SUBSPACE_2_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT32 AddressLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT32 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckSet;
  UINT8 Reserved1[8];
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE CommandCompleteCheckRegister;
  UINT64 CommandCompleteCheckMask;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE CommandCompleteUpdateRegister;
  UINT64 CommandCompleteUpdatePreserve;
  UINT64 CommandCompleteUpdateSet;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE ErrorStatusRegister;
  UINT64 ErrorStatusMask;
} EFI_ACPI_6_4_PCCT_SUBSPACE_3_EXTENDED_PCC;
typedef EFI_ACPI_6_4_PCCT_SUBSPACE_3_EXTENDED_PCC EFI_ACPI_6_4_PCCT_SUBSPACE_4_EXTENDED_PCC;
typedef struct 
{
  UINT32 Signature;
  UINT32 Flags;
  UINT32 Length;
  UINT32 Command;
} EFI_ACPI_6_4_PCCT_EXTENDED_PCC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Version;
  UINT64 BaseAddress;
  UINT64 SharedMemoryRangeLength;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE CommandCompleteCheckRegister;
  UINT64 CommandCompleteCheckMask;
  EFI_ACPI_6_4_GENERIC_ADDRESS_STRUCTURE ErrorStatusRegister;
  UINT64 ErrorStatusMask;
  UINT32 NominalLatency;
  UINT32 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_4_PCCT_SUBSPACE_5_HW_REGISTERS_COMMUNICATIONS;
typedef struct 
{
  UINT32 Signature;
} EFI_6_4_PCCT_REDUCED_PCC_SUBSPACE_SHARED_MEMORY_REGION;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 TriggerCount;
  UINT8 Reserved[3];
  UINT32 TriggerIdentifierArrayOffset;
} EFI_ACPI_6_4_PLATFORM_DEBUG_TRIGGER_TABLE_HEADER;
typedef struct 
{
  UINT16 SubChannelIdentifer : 8;
  UINT16 Runtime : 1;
  UINT16 WaitForCompletion : 1;
  UINT16 TriggerOrder : 1;
  UINT16 Reserved : 5;
} EFI_ACPI_6_4_PDTT_PCC_IDENTIFIER;
typedef EFI_ACPI_6_4_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER EFI_ACPI_6_4_PDTT_PCC;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_4_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
} EFI_ACPI_6_4_PPTT_STRUCTURE_HEADER;
typedef struct 
{
  UINT32 PhysicalPackage : 1;
  UINT32 AcpiProcessorIdValid : 1;
  UINT32 ProcessorIsAThread : 1;
  UINT32 NodeIsALeaf : 1;
  UINT32 IdenticalImplementation : 1;
  UINT32 Reserved : 27;
} EFI_ACPI_6_4_PPTT_STRUCTURE_PROCESSOR_FLAGS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_4_PPTT_STRUCTURE_PROCESSOR_FLAGS Flags;
  UINT32 Parent;
  UINT32 AcpiProcessorId;
  UINT32 NumberOfPrivateResources;
} EFI_ACPI_6_4_PPTT_STRUCTURE_PROCESSOR;
typedef struct 
{
  UINT32 SizePropertyValid : 1;
  UINT32 NumberOfSetsValid : 1;
  UINT32 AssociativityValid : 1;
  UINT32 AllocationTypeValid : 1;
  UINT32 CacheTypeValid : 1;
  UINT32 WritePolicyValid : 1;
  UINT32 LineSizeValid : 1;
  UINT32 CacheIdValid : 1;
  UINT32 Reserved : 24;
} EFI_ACPI_6_4_PPTT_STRUCTURE_CACHE_FLAGS;
typedef struct 
{
  UINT8 AllocationType : 2;
  UINT8 CacheType : 2;
  UINT8 WritePolicy : 1;
  UINT8 Reserved : 3;
} EFI_ACPI_6_4_PPTT_STRUCTURE_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_4_PPTT_STRUCTURE_CACHE_FLAGS Flags;
  UINT32 NextLevelOfCache;
  UINT32 Size;
  UINT32 NumberOfSets;
  UINT8 Associativity;
  EFI_ACPI_6_4_PPTT_STRUCTURE_CACHE_ATTRIBUTES Attributes;
  UINT16 LineSize;
  UINT32 CacheId;
} EFI_ACPI_6_4_PPTT_STRUCTURE_CACHE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_4_PLATFORM_HEALTH_ASSESSMENT_TABLE;
typedef struct 
{
  UINT16 PlatformHealthAssessmentRecordType;
  UINT16 RecordLength;
  UINT8 Revision;
} EFI_ACPI_6_4_PHAT_RECORD;
typedef struct 
{
  GUID ComponentId;
  UINT64 VersionValue;
  UINT32 ProducerId;
} EFI_ACPI_6_4_PHAT_VERSION_ELEMENT;
typedef struct 
{
  UINT16 PlatformRecordType;
  UINT16 RecordLength;
  UINT8 Revision;
  UINT8 Reserved[3];
  UINT32 RecordCount;
} EFI_ACPI_6_4_PHAT_FIRMWARE_VERISON_DATA_RECORD;
typedef struct 
{
  UINT16 PlatformRecordType;
  UINT16 RecordLength;
  UINT8 Revision;
  UINT16 Reserved;
  UINT8 AmHealthy;
  GUID DeviceSignature;
  UINT32 DeviceSpecificDataOffset;
} EFI_ACPI_6_4_PHAT_FIRMWARE_HEALTH_DATA_RECORD_STRUCTURE;
#pragma pack()
#pragma pack(1)
typedef struct 
{
  UINT8 AddressSpaceId;
  UINT8 RegisterBitWidth;
  UINT8 RegisterBitOffset;
  UINT8 AccessSize;
  UINT64 Address;
} EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT64 Signature;
  UINT8 Checksum;
  UINT8 OemId[6];
  UINT8 Revision;
  UINT32 RsdtAddress;
  UINT32 Length;
  UINT64 XsdtAddress;
  UINT8 ExtendedChecksum;
  UINT8 Reserved[3];
} EFI_ACPI_6_5_ROOT_SYSTEM_DESCRIPTION_POINTER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_5_COMMON_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 FirmwareCtrl;
  UINT32 Dsdt;
  UINT8 Reserved0;
  UINT8 PreferredPmProfile;
  UINT16 SciInt;
  UINT32 SmiCmd;
  UINT8 AcpiEnable;
  UINT8 AcpiDisable;
  UINT8 S4BiosReq;
  UINT8 PstateCnt;
  UINT32 Pm1aEvtBlk;
  UINT32 Pm1bEvtBlk;
  UINT32 Pm1aCntBlk;
  UINT32 Pm1bCntBlk;
  UINT32 Pm2CntBlk;
  UINT32 PmTmrBlk;
  UINT32 Gpe0Blk;
  UINT32 Gpe1Blk;
  UINT8 Pm1EvtLen;
  UINT8 Pm1CntLen;
  UINT8 Pm2CntLen;
  UINT8 PmTmrLen;
  UINT8 Gpe0BlkLen;
  UINT8 Gpe1BlkLen;
  UINT8 Gpe1Base;
  UINT8 CstCnt;
  UINT16 PLvl2Lat;
  UINT16 PLvl3Lat;
  UINT16 FlushSize;
  UINT16 FlushStride;
  UINT8 DutyOffset;
  UINT8 DutyWidth;
  UINT8 DayAlrm;
  UINT8 MonAlrm;
  UINT8 Century;
  UINT16 IaPcBootArch;
  UINT8 Reserved1;
  UINT32 Flags;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE ResetReg;
  UINT8 ResetValue;
  UINT16 ArmBootArch;
  UINT8 MinorVersion;
  UINT64 XFirmwareCtrl;
  UINT64 XDsdt;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XPm1aEvtBlk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XPm1bEvtBlk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XPm1aCntBlk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XPm1bCntBlk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XPm2CntBlk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XPmTmrBlk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XGpe0Blk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE XGpe1Blk;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE SleepControlReg;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE SleepStatusReg;
  UINT64 HypervisorVendorIdentity;
} EFI_ACPI_6_5_FIXED_ACPI_DESCRIPTION_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
  UINT32 HardwareSignature;
  UINT32 FirmwareWakingVector;
  UINT32 GlobalLock;
  UINT32 Flags;
  UINT64 XFirmwareWakingVector;
  UINT8 Version;
  UINT8 Reserved0[3];
  UINT32 OspmFlags;
  UINT8 Reserved1[24];
} EFI_ACPI_6_5_FIRMWARE_ACPI_CONTROL_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 LocalApicAddress;
  UINT32 Flags;
} EFI_ACPI_6_5_MULTIPLE_APIC_DESCRIPTION_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT8 ApicId;
  UINT32 Flags;
} EFI_ACPI_6_5_PROCESSOR_LOCAL_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 IoApicAddress;
  UINT32 GlobalSystemInterruptBase;
} EFI_ACPI_6_5_IO_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Bus;
  UINT8 Source;
  UINT32 GlobalSystemInterrupt;
  UINT16 Flags;
} EFI_ACPI_6_5_INTERRUPT_SOURCE_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
  UINT8 CpeiProcessorOverride;
  UINT8 Reserved[31];
} EFI_ACPI_6_5_PLATFORM_INTERRUPT_APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 GlobalSystemInterrupt;
} EFI_ACPI_6_5_NON_MASKABLE_INTERRUPT_SOURCE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorUid;
  UINT16 Flags;
  UINT8 LocalApicLint;
} EFI_ACPI_6_5_LOCAL_APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 LocalApicAddress;
} EFI_ACPI_6_5_LOCAL_APIC_ADDRESS_OVERRIDE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 IoApicId;
  UINT8 Reserved;
  UINT32 GlobalSystemInterruptBase;
  UINT64 IoSapicAddress;
} EFI_ACPI_6_5_IO_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 AcpiProcessorId;
  UINT8 LocalSapicId;
  UINT8 LocalSapicEid;
  UINT8 Reserved[3];
  UINT32 Flags;
  UINT32 ACPIProcessorUIDValue;
} EFI_ACPI_6_5_PROCESSOR_LOCAL_SAPIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT8 InterruptType;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT8 IoSapicVector;
  UINT32 GlobalSystemInterrupt;
  UINT32 PlatformInterruptSourceFlags;
} EFI_ACPI_6_5_PLATFORM_INTERRUPT_SOURCES_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 AcpiProcessorUid;
} EFI_ACPI_6_5_PROCESSOR_LOCAL_X2APIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Flags;
  UINT32 AcpiProcessorUid;
  UINT8 LocalX2ApicLint;
  UINT8 Reserved[3];
} EFI_ACPI_6_5_LOCAL_X2APIC_NMI_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 CPUInterfaceNumber;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ParkingProtocolVersion;
  UINT32 PerformanceInterruptGsiv;
  UINT64 ParkedAddress;
  UINT64 PhysicalBaseAddress;
  UINT64 GICV;
  UINT64 GICH;
  UINT32 VGICMaintenanceInterrupt;
  UINT64 GICRBaseAddress;
  UINT64 MPIDR;
  UINT8 ProcessorPowerEfficiencyClass;
  UINT8 Reserved2;
  UINT16 SpeOverflowInterrupt;
  UINT16 TrbeInterrupt;
} EFI_ACPI_6_5_GIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicId;
  UINT64 PhysicalBaseAddress;
  UINT32 SystemVectorBase;
  UINT8 GicVersion;
  UINT8 Reserved2[3];
} EFI_ACPI_6_5_GIC_DISTRIBUTOR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved1;
  UINT32 GicMsiFrameId;
  UINT64 PhysicalBaseAddress;
  UINT32 Flags;
  UINT16 SPICount;
  UINT16 SPIBase;
} EFI_ACPI_6_5_GIC_MSI_FRAME_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT64 DiscoveryRangeBaseAddress;
  UINT32 DiscoveryRangeLength;
} EFI_ACPI_6_5_GICR_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Reserved;
  UINT32 GicItsId;
  UINT64 PhysicalBaseAddress;
  UINT32 Reserved2;
} EFI_ACPI_6_5_GIC_ITS_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 MailBoxVersion;
  UINT32 Reserved;
  UINT64 MailBoxAddress;
} EFI_ACPI_6_5_MULTIPROCESSOR_WAKEUP_STRUCTURE;
typedef struct 
{
  UINT16 Command;
  UINT16 Reserved;
  UINT32 AcpiId;
  UINT64 WakeupVector;
  UINT8 ReservedForOs[2032];
  UINT8 ReservedForFirmware[2048];
} EFI_ACPI_6_5_MULTIPROCESSOR_WAKEUP_MAILBOX_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT32 ProcessorId;
  UINT32 CoreId;
  UINT32 Flags;
} EFI_ACPI_6_5_CORE_PIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT64 Address;
  UINT16 Size;
  UINT8 Cascade[2];
  UINT32 CascadeMap[2];
} EFI_ACPI_6_5_LIO_PIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT64 Address;
  UINT16 Size;
  UINT8 Cascade[8];
} EFI_ACPI_6_5_HT_PIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT8 Cascade;
  UINT8 Node;
  UINT64 NodeMap;
} EFI_ACPI_6_5_EIO_PIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT64 MsgAddress;
  UINT32 Start;
  UINT32 Count;
} EFI_ACPI_6_5_MSI_PIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT64 Address;
  UINT16 Size;
  UINT16 Id;
  UINT16 GsiBase;
} EFI_ACPI_6_5_BIO_PIC_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Version;
  UINT64 Address;
  UINT16 Size;
  UINT8 Cascade;
} EFI_ACPI_6_5_LPC_PIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 WarningEnergyLevel;
  UINT32 LowEnergyLevel;
  UINT32 CriticalEnergyLevel;
} EFI_ACPI_6_5_SMART_BATTERY_DESCRIPTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE EcControl;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE EcData;
  UINT32 Uid;
  UINT8 GpeBit;
} EFI_ACPI_6_5_EMBEDDED_CONTROLLER_BOOT_RESOURCES_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved1;
  UINT64 Reserved2;
} EFI_ACPI_6_5_SYSTEM_RESOURCE_AFFINITY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProximityDomain7To0;
  UINT8 ApicId;
  UINT32 Flags;
  UINT8 LocalSapicEid;
  UINT8 ProximityDomain31To8[3];
  UINT32 ClockDomain;
} EFI_ACPI_6_5_PROCESSOR_LOCAL_APIC_SAPIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT16 Reserved1;
  UINT32 AddressBaseLow;
  UINT32 AddressBaseHigh;
  UINT32 LengthLow;
  UINT32 LengthHigh;
  UINT32 Reserved2;
  UINT32 Flags;
  UINT64 Reserved3;
} EFI_ACPI_6_5_MEMORY_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1[2];
  UINT32 ProximityDomain;
  UINT32 X2ApicId;
  UINT32 Flags;
  UINT32 ClockDomain;
  UINT8 Reserved2[4];
} EFI_ACPI_6_5_PROCESSOR_LOCAL_X2APIC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT32 AcpiProcessorUid;
  UINT32 Flags;
  UINT32 ClockDomain;
} EFI_ACPI_6_5_GICC_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 ProximityDomain;
  UINT8 Reserved[2];
  UINT32 ItsId;
} EFI_ACPI_6_5_GIC_ITS_AFFINITY_STRUCTURE;
typedef struct 
{
  UINT64 AcpiHid;
  UINT32 AcpiUid;
  UINT8 Reserved[4];
} EFI_ACPI_6_5_DEVICE_HANDLE_ACPI;
typedef struct 
{
  UINT16 PciSegment;
  UINT16 PciBdfNumber;
  UINT8 Reserved[12];
} EFI_ACPI_6_5_DEVICE_HANDLE_PCI;
typedef union 
{
  EFI_ACPI_6_5_DEVICE_HANDLE_ACPI Acpi;
  EFI_ACPI_6_5_DEVICE_HANDLE_PCI Pci;
} EFI_ACPI_6_5_DEVICE_HANDLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved1;
  UINT8 DeviceHandleType;
  UINT32 ProximityDomain;
  EFI_ACPI_6_5_DEVICE_HANDLE DeviceHandle;
  UINT32 Flags;
  UINT8 Reserved2[4];
} EFI_ACPI_6_5_GENERIC_INITIATOR_AFFINITY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 NumberOfSystemLocalities;
} EFI_ACPI_6_5_SYSTEM_LOCALITY_DISTANCE_INFORMATION_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[8];
} EFI_ACPI_6_5_CORRECTED_PLATFORM_ERROR_POLLING_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 ProcessorId;
  UINT8 ProcessorEid;
  UINT32 PollingInterval;
} EFI_ACPI_6_5_CPEP_PROCESSOR_APIC_SAPIC_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 OffsetProxDomInfo;
  UINT32 MaximumNumberOfProximityDomains;
  UINT32 MaximumNumberOfClockDomains;
  UINT64 MaximumPhysicalAddress;
} EFI_ACPI_6_5_MAXIMUM_SYSTEM_CHARACTERISTICS_TABLE_HEADER;
typedef struct 
{
  UINT8 Revision;
  UINT8 Length;
  UINT32 ProximityDomainRangeLow;
  UINT32 ProximityDomainRangeHigh;
  UINT32 MaximumProcessorCapacity;
  UINT64 MaximumMemoryCapacity;
} EFI_ACPI_6_5_MAXIMUM_PROXIMITY_DOMAIN_INFORMATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier[12];
} EFI_ACPI_6_5_RAS_FEATURE_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT16 Version;
  UINT8 RASCapabilities[16];
  UINT8 SetRASCapabilities[16];
  UINT16 NumberOfRASFParameterBlocks;
  UINT32 SetRASCapabilitiesStatus;
} EFI_ACPI_6_5_RASF_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT16 Type;
  UINT16 Version;
  UINT16 Length;
  UINT16 PatrolScrubCommand;
  UINT64 RequestedAddressRange[2];
  UINT64 ActualAddressRange[2];
  UINT16 Flags;
  UINT8 RequestedSpeed;
} EFI_ACPI_6_5_RASF_PATROL_SCRUB_PLATFORM_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 PccId;
  UINT8 Reserved[2];
  UINT8 RasFeatureType;
  UINT32 Instance;
} EFI_ACPI_RAS2_PCC_DESCRIPTOR;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Reserved;
  UINT16 PccCount;
} EFI_ACPI_6_5_RAS2_FEATURE_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 PlatformCommunicationChannelIdentifier;
  UINT8 Reserved[3];
} EFI_ACPI_6_5_MEMORY_POWER_STATUS_TABLE;
typedef struct 
{
  UINT32 Signature;
  UINT16 Command;
  UINT16 Status;
  UINT32 MemoryPowerCommandRegister;
  UINT32 MemoryPowerStatusRegister;
  UINT32 PowerStateId;
  UINT32 MemoryPowerNodeId;
  UINT64 MemoryEnergyConsumed;
  UINT64 ExpectedAveragePowerComsuned;
} EFI_ACPI_6_5_MPST_PLATFORM_COMMUNICATION_CHANNEL_SHARED_MEMORY_REGION;
typedef struct 
{
  UINT8 PowerStateValue;
  UINT8 PowerStateInformationIndex;
} EFI_ACPI_6_5_MPST_MEMORY_POWER_STATE;
typedef struct 
{
  UINT8 Flag;
  UINT8 Reserved;
  UINT16 MemoryPowerNodeId;
  UINT32 Length;
  UINT64 AddressBase;
  UINT64 AddressLength;
  UINT32 NumberOfPowerStates;
  UINT32 NumberOfPhysicalComponents;
} EFI_ACPI_6_5_MPST_MEMORY_POWER_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerNodeCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_5_MPST_MEMORY_POWER_NODE_TABLE;
typedef struct 
{
  UINT8 PowerStateStructureID;
  UINT8 Flag;
  UINT16 Reserved;
  UINT32 AveragePowerConsumedInMPS0;
  UINT32 RelativePowerSavingToMPS0;
  UINT64 ExitLatencyToMPS0;
} EFI_ACPI_6_5_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_STRUCTURE;
typedef struct 
{
  UINT16 MemoryPowerStateCharacteristicsCount;
  UINT8 Reserved[2];
} EFI_ACPI_6_5_MPST_MEMORY_POWER_STATE_CHARACTERISTICS_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 NumberOfMemoryDevices;
} EFI_ACPI_6_5_PLATFORM_MEMORY_TOPOLOGY_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT8 Reserved;
  UINT16 Length;
  UINT16 Flags;
  UINT16 Reserved1;
  UINT32 NumberOfMemoryDevices;
} EFI_ACPI_6_5_PMTT_COMMON_MEMORY_DEVICE;
typedef struct 
{
  EFI_ACPI_6_5_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT16 SocketIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_5_PMTT_SOCKET_TYPE_DATA;
typedef struct 
{
  EFI_ACPI_6_5_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT16 MemoryControllerIdentifier;
  UINT16 Reserved;
} EFI_ACPI_6_5_PMTT_MEMORY_CONTROLLER_TYPE_DATA;
typedef struct 
{
  EFI_ACPI_6_5_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT32 SmbiosHandle;
} EFI_ACPI_6_5_PMTT_DIMM_TYPE_SPECIFIC_DATA;
typedef struct 
{
  EFI_ACPI_6_5_PMTT_COMMON_MEMORY_DEVICE CommonMemoryDeviceHeader;
  UINT8 TypeUuid[16];
} EFI_ACPI_6_5_PMTT_VENDOR_SPECIFIC_TYPE_DATA;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT16 Version;
  UINT8 Status;
  UINT8 ImageType;
  UINT64 ImageAddress;
  UINT32 ImageOffsetX;
  UINT32 ImageOffsetY;
} EFI_ACPI_6_5_BOOT_GRAPHICS_RESOURCE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT8 Length;
  UINT8 Revision;
} EFI_ACPI_6_5_FPDT_PERFORMANCE_RECORD_HEADER;
typedef struct 
{
  UINT32 Signature;
  UINT32 Length;
} EFI_ACPI_6_5_FPDT_PERFORMANCE_TABLE_HEADER;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 BootPerformanceTablePointer;
} EFI_ACPI_6_5_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 S3PerformanceTablePointer;
} EFI_ACPI_6_5_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 Reserved;
  UINT64 ResetEnd;
  UINT64 OsLoaderLoadImageStart;
  UINT64 OsLoaderStartImageStart;
  UINT64 ExitBootServicesEntry;
  UINT64 ExitBootServicesExit;
} EFI_ACPI_6_5_FPDT_FIRMWARE_BASIC_BOOT_RECORD;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_5_FPDT_FIRMWARE_BASIC_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_TABLE_HEADER Header;
} EFI_ACPI_6_5_FPDT_FIRMWARE_S3_BOOT_TABLE;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT32 ResumeCount;
  UINT64 FullResume;
  UINT64 AverageResume;
} EFI_ACPI_6_5_FPDT_S3_RESUME_RECORD;
typedef struct 
{
  EFI_ACPI_6_5_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT64 SuspendStart;
  UINT64 SuspendEnd;
} EFI_ACPI_6_5_FPDT_S3_SUSPEND_RECORD;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_5_FIRMWARE_PERFORMANCE_RECORD_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT64 CntControlBasePhysicalAddress;
  UINT32 Reserved;
  UINT32 SecurePL1TimerGSIV;
  UINT32 SecurePL1TimerFlags;
  UINT32 NonSecurePL1TimerGSIV;
  UINT32 NonSecurePL1TimerFlags;
  UINT32 VirtualTimerGSIV;
  UINT32 VirtualTimerFlags;
  UINT32 NonSecurePL2TimerGSIV;
  UINT32 NonSecurePL2TimerFlags;
  UINT64 CntReadBasePhysicalAddress;
  UINT32 PlatformTimerCount;
  UINT32 PlatformTimerOffset;
  UINT32 VirtualPL2TimerGSIV;
  UINT32 VirtualPL2TimerFlags;
} EFI_ACPI_6_5_GENERIC_TIMER_DESCRIPTION_TABLE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 CntCtlBase;
  UINT32 GTBlockTimerCount;
  UINT32 GTBlockTimerOffset;
} EFI_ACPI_6_5_GTDT_GT_BLOCK_STRUCTURE;
typedef struct 
{
  UINT8 GTFrameNumber;
  UINT8 Reserved[3];
  UINT64 CntBaseX;
  UINT64 CntEL0BaseX;
  UINT32 GTxPhysicalTimerGSIV;
  UINT32 GTxPhysicalTimerFlags;
  UINT32 GTxVirtualTimerGSIV;
  UINT32 GTxVirtualTimerFlags;
  UINT32 GTxCommonFlags;
} EFI_ACPI_6_5_GTDT_GT_BLOCK_TIMER_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT16 Length;
  UINT8 Reserved;
  UINT64 RefreshFramePhysicalAddress;
  UINT64 WatchdogControlFramePhysicalAddress;
  UINT32 WatchdogTimerGSIV;
  UINT32 WatchdogTimerFlags;
} EFI_ACPI_6_5_GTDT_ARM_GENERIC_WATCHDOG_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Reserved;
} EFI_ACPI_6_5_NVDIMM_FIRMWARE_INTERFACE_TABLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
} EFI_ACPI_6_5_NFIT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 SPARangeStructureIndex;
  UINT16 Flags;
  UINT32 Reserved_8;
  UINT32 ProximityDomain;
  GUID AddressRangeTypeGUID;
  UINT64 SystemPhysicalAddressRangeBase;
  UINT64 SystemPhysicalAddressRangeLength;
  UINT64 AddressRangeMemoryMappingAttribute;
  UINT64 SPALocationCookie;
} EFI_ACPI_6_5_NFIT_SYSTEM_PHYSICAL_ADDRESS_RANGE_STRUCTURE;
typedef struct 
{
  UINT32 DIMMNumber : 4;
  UINT32 MemoryChannelNumber : 4;
  UINT32 MemoryControllerID : 4;
  UINT32 SocketID : 4;
  UINT32 NodeControllerID : 12;
  UINT32 Reserved_28 : 4;
} EFI_ACPI_6_5_NFIT_DEVICE_HANDLE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_5_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NVDIMMPhysicalID;
  UINT16 NVDIMMRegionID;
  UINT16 SPARangeStructureIndex;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT64 NVDIMMRegionSize;
  UINT64 RegionOffset;
  UINT64 NVDIMMPhysicalAddressRegionBase;
  UINT16 InterleaveStructureIndex;
  UINT16 InterleaveWays;
  UINT16 NVDIMMStateFlags;
  UINT16 Reserved_46;
} EFI_ACPI_6_5_NFIT_NVDIMM_REGION_MAPPING_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 InterleaveStructureIndex;
  UINT16 Reserved_6;
  UINT32 NumberOfLines;
  UINT32 LineSize;
} EFI_ACPI_6_5_NFIT_INTERLEAVE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT32 Reserved_4;
} EFI_ACPI_6_5_NFIT_SMBIOS_MANAGEMENT_INFORMATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 VendorID;
  UINT16 DeviceID;
  UINT16 RevisionID;
  UINT16 SubsystemVendorID;
  UINT16 SubsystemDeviceID;
  UINT16 SubsystemRevisionID;
  UINT8 ValidFields;
  UINT8 ManufacturingLocation;
  UINT16 ManufacturingDate;
  UINT8 Reserved_22[2];
  UINT32 SerialNumber;
  UINT16 RegionFormatInterfaceCode;
  UINT16 NumberOfBlockControlWindows;
  UINT64 SizeOfBlockControlWindow;
  UINT64 CommandRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfCommandRegisterInBlockControlWindows;
  UINT64 StatusRegisterOffsetInBlockControlWindow;
  UINT64 SizeOfStatusRegisterInBlockControlWindows;
  UINT16 NVDIMMControlRegionFlag;
  UINT8 Reserved_74[6];
} EFI_ACPI_6_5_NFIT_NVDIMM_CONTROL_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT16 NVDIMMControlRegionStructureIndex;
  UINT16 NumberOfBlockDataWindows;
  UINT64 BlockDataWindowStartOffset;
  UINT64 SizeOfBlockDataWindow;
  UINT64 BlockAccessibleMemoryCapacity;
  UINT64 BeginningAddressOfFirstBlockInBlockAccessibleMemory;
} EFI_ACPI_6_5_NFIT_NVDIMM_BLOCK_DATA_WINDOW_REGION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  EFI_ACPI_6_5_NFIT_DEVICE_HANDLE NFITDeviceHandle;
  UINT16 NumberOfFlushHintAddresses;
  UINT8 Reserved_10[6];
} EFI_ACPI_6_5_NFIT_FLUSH_HINT_ADDRESS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 Length;
  UINT8 HighestValidCapability;
  UINT8 Reserved_5[3];
  UINT32 Capabilities;
  UINT8 Reserved_12[4];
} EFI_ACPI_6_5_NFIT_PLATFORM_CAPABILITIES_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_5_SECURE_DEVICES_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Flags;
  UINT16 Length;
} EFI_ACPI_6_5_SDEV_STRUCTURE_HEADER;
typedef struct 
{
  EFI_ACPI_6_5_SDEV_STRUCTURE_HEADER Header;
  UINT16 DeviceIdentifierOffset;
  UINT16 DeviceIdentifierLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
  UINT16 SecureAccessComponentsOffset;
  UINT16 SecureAccessComponentsLength;
} EFI_ACPI_6_5_SDEV_STRUCTURE_ACPI_NAMESPACE_DEVICE;
typedef struct 
{
  EFI_ACPI_6_5_SDEV_STRUCTURE_HEADER Header;
  UINT16 HardwareIdentifierOffset;
  UINT16 HardwareIdentifierLength;
  UINT16 SubsystemIdentifierOffset;
  UINT16 SubsystemIdentifierLength;
  UINT16 HardwareRevision;
  UINT8 HardwareRevisionPresent;
  UINT8 ClassCodePresent;
  UINT8 PciCompatibleBaseClass;
  UINT8 PciCompatibleSubClass;
  UINT8 PciCompatibleProgrammingInterface;
} EFI_ACPI_6_5_SDEV_SECURE_ACCESS_COMPONENT_IDENTIFICATION_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_5_SDEV_STRUCTURE_HEADER Header;
  UINT32 Reserved;
  UINT64 MemoryAddressBase;
  UINT64 MemoryLength;
} EFI_ACPI_6_5_SDEV_SECURE_ACCESS_COMPONENT_MEMORY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_5_SDEV_STRUCTURE_HEADER Header;
  UINT16 PciSegmentNumber;
  UINT16 StartBusNumber;
  UINT16 PciPathOffset;
  UINT16 PciPathLength;
  UINT16 VendorSpecificDataOffset;
  UINT16 VendorSpecificDataLength;
} EFI_ACPI_6_5_SDEV_STRUCTURE_PCIE_ENDPOINT_DEVICE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 BootErrorRegionLength;
  UINT64 BootErrorRegion;
} EFI_ACPI_6_5_BOOT_ERROR_RECORD_TABLE_HEADER;
typedef struct 
{
  UINT32 UncorrectableErrorValid : 1;
  UINT32 CorrectableErrorValid : 1;
  UINT32 MultipleUncorrectableErrors : 1;
  UINT32 MultipleCorrectableErrors : 1;
  UINT32 ErrorDataEntryCount : 10;
  UINT32 Reserved : 18;
} EFI_ACPI_6_5_ERROR_BLOCK_STATUS;
typedef struct 
{
  EFI_ACPI_6_5_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_5_BOOT_ERROR_REGION_STRUCTURE;
typedef struct 
{
  UINT8 SectionType[16];
  UINT32 ErrorSeverity;
  UINT16 Revision;
  UINT8 ValidationBits;
  UINT8 Flags;
  UINT32 ErrorDataLength;
  UINT8 FruId[16];
  UINT8 FruText[20];
  UINT8 Timestamp[8];
} EFI_ACPI_6_5_GENERIC_ERROR_DATA_ENTRY_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 ErrorSourceCount;
} EFI_ACPI_6_5_HARDWARE_ERROR_SOURCE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT64 GlobalCapabilityInitData;
  UINT64 GlobalControlInitData;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[7];
} EFI_ACPI_6_5_IA32_ARCHITECTURE_MACHINE_CHECK_EXCEPTION_STRUCTURE;
typedef struct 
{
  UINT8 BankNumber;
  UINT8 ClearStatusOnInitialization;
  UINT8 StatusDataFormat;
  UINT8 Reserved0;
  UINT32 ControlRegisterMsrAddress;
  UINT64 ControlInitData;
  UINT32 StatusRegisterMsrAddress;
  UINT32 AddressRegisterMsrAddress;
  UINT32 MiscRegisterMsrAddress;
} EFI_ACPI_6_5_IA32_ARCHITECTURE_MACHINE_CHECK_ERROR_BANK_STRUCTURE;
typedef struct 
{
  UINT16 Type : 1;
  UINT16 PollInterval : 1;
  UINT16 SwitchToPollingThresholdValue : 1;
  UINT16 SwitchToPollingThresholdWindow : 1;
  UINT16 ErrorThresholdValue : 1;
  UINT16 ErrorThresholdWindow : 1;
  UINT16 Reserved : 10;
} EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_CONFIGURATION_WRITE_ENABLE_STRUCTURE ConfigurationWriteEnable;
  UINT32 PollInterval;
  UINT32 Vector;
  UINT32 SwitchToPollingThresholdValue;
  UINT32 SwitchToPollingThresholdWindow;
  UINT32 ErrorThresholdValue;
  UINT32 ErrorThresholdWindow;
} EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_5_IA32_ARCHITECTURE_CORRECTED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
} EFI_ACPI_6_5_IA32_ARCHITECTURE_NMI_ERROR_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 RootErrorCommand;
} EFI_ACPI_6_5_PCI_EXPRESS_ROOT_PORT_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_5_PCI_EXPRESS_DEVICE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 Bus;
  UINT16 Device;
  UINT16 Function;
  UINT16 DeviceControl;
  UINT8 Reserved1[2];
  UINT32 UncorrectableErrorMask;
  UINT32 UncorrectableErrorSeverity;
  UINT32 CorrectableErrorMask;
  UINT32 AdvancedErrorCapabilitiesAndControl;
  UINT32 SecondaryUncorrectableErrorMask;
  UINT32 SecondaryUncorrectableErrorSeverity;
  UINT32 SecondaryAdvancedErrorCapabilitiesAndControl;
} EFI_ACPI_6_5_PCI_EXPRESS_BRIDGE_AER_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
} EFI_ACPI_6_5_GENERIC_HARDWARE_ERROR_SOURCE_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT16 RelatedSourceId;
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  UINT32 MaxRawDataLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE ErrorStatusAddress;
  EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT32 ErrorStatusBlockLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE ReadAckRegister;
  UINT64 ReadAckPreserve;
  UINT64 ReadAckWrite;
} EFI_ACPI_6_5_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE;
typedef struct 
{
  EFI_ACPI_6_5_ERROR_BLOCK_STATUS BlockStatus;
  UINT32 RawDataOffset;
  UINT32 RawDataLength;
  UINT32 DataLength;
  UINT32 ErrorSeverity;
} EFI_ACPI_6_5_GENERIC_ERROR_STATUS_STRUCTURE;
typedef struct 
{
  UINT16 Type;
  UINT16 SourceId;
  UINT8 Reserved0[2];
  UINT8 Flags;
  UINT8 Enabled;
  UINT32 NumberOfRecordsToPreAllocate;
  UINT32 MaxSectionsPerRecord;
  EFI_ACPI_6_5_HARDWARE_ERROR_NOTIFICATION_STRUCTURE NotificationStructure;
  UINT8 NumberOfHardwareBanks;
  UINT8 Reserved1[3];
} EFI_ACPI_6_5_IA32_ARCHITECTURE_DEFERRED_MACHINE_CHECK_STRUCTURE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 Reserved[4];
} EFI_ACPI_6_5_HETEROGENEOUS_MEMORY_ATTRIBUTE_TABLE_HEADER;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
} EFI_ACPI_6_5_HMAT_STRUCTURE_HEADER;
typedef struct 
{
  UINT16 InitiatorProximityDomainValid : 1;
  UINT16 Reserved : 15;
} EFI_ACPI_6_5_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_5_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES_FLAGS Flags;
  UINT8 Reserved1[2];
  UINT32 InitiatorProximityDomain;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved2[20];
} EFI_ACPI_6_5_HMAT_STRUCTURE_MEMORY_PROXIMITY_DOMAIN_ATTRIBUTES;
typedef struct 
{
  UINT8 MemoryHierarchy : 4;
  UINT8 AccessAttributes : 2;
  UINT8 Reserved : 2;
} EFI_ACPI_6_5_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  EFI_ACPI_6_5_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO_FLAGS Flags;
  UINT8 DataType;
  UINT8 MinTransferSize;
  UINT8 Reserved1;
  UINT32 NumberOfInitiatorProximityDomains;
  UINT32 NumberOfTargetProximityDomains;
  UINT8 Reserved2[4];
  UINT64 EntryBaseUnit;
} EFI_ACPI_6_5_HMAT_STRUCTURE_SYSTEM_LOCALITY_LATENCY_AND_BANDWIDTH_INFO;
typedef struct 
{
  UINT32 TotalCacheLevels : 4;
  UINT32 CacheLevel : 4;
  UINT32 CacheAssociativity : 4;
  UINT32 WritePolicy : 4;
  UINT32 CacheLineSize : 16;
} EFI_ACPI_6_5_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT16 Type;
  UINT8 Reserved[2];
  UINT32 Length;
  UINT32 MemoryProximityDomain;
  UINT8 Reserved1[4];
  UINT64 MemorySideCacheSize;
  EFI_ACPI_6_5_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO_CACHE_ATTRIBUTES CacheAttributes;
  UINT8 Reserved2[2];
  UINT16 NumberOfSmbiosHandles;
} EFI_ACPI_6_5_HMAT_STRUCTURE_MEMORY_SIDE_CACHE_INFO;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 SerializationHeaderSize;
  UINT8 Reserved0[4];
  UINT32 InstructionEntryCount;
} EFI_ACPI_6_5_ERROR_RECORD_SERIALIZATION_TABLE_HEADER;
typedef struct 
{
  UINT8 SerializationAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_5_ERST_SERIALIZATION_INSTRUCTION_ENTRY;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 InjectionHeaderSize;
  UINT8 InjectionFlags;
  UINT8 Reserved0[3];
  UINT32 InjectionEntryCount;
} EFI_ACPI_6_5_ERROR_INJECTION_TABLE_HEADER;
typedef struct 
{
  UINT8 InjectionAction;
  UINT8 Instruction;
  UINT8 Flags;
  UINT8 Reserved0;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE RegisterRegion;
  UINT64 Value;
  UINT64 Mask;
} EFI_ACPI_6_5_EINJ_INJECTION_INSTRUCTION_ENTRY;
typedef struct 
{
  UINT32 HeaderSize;
  UINT32 Revision;
  UINT32 TableSize;
  UINT32 EntryCount;
} EFI_ACPI_6_5_EINJ_TRIGGER_ACTION_TABLE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT32 Flags;
  UINT64 Reserved;
} EFI_ACPI_6_5_PLATFORM_COMMUNICATION_CHANNEL_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
} EFI_ACPI_6_5_PCCT_SUBSPACE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[6];
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_5_PCCT_SUBSPACE_GENERIC;
typedef struct 
{
  UINT8 Command;
  UINT8 Reserved : 7;
  UINT8 NotifyOnCompletion : 1;
} EFI_ACPI_6_5_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND;
typedef struct 
{
  UINT8 CommandComplete : 1;
  UINT8 PlatformInterrupt : 1;
  UINT8 Error : 1;
  UINT8 PlatformNotification : 1;
  UINT8 Reserved : 4;
  UINT8 Reserved1;
} EFI_ACPI_6_5_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS;
typedef struct 
{
  UINT32 Signature;
  EFI_ACPI_6_5_PCCT_GENERIC_SHARED_MEMORY_REGION_COMMAND Command;
  EFI_ACPI_6_5_PCCT_GENERIC_SHARED_MEMORY_REGION_STATUS Status;
} EFI_ACPI_6_5_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_5_PCCT_SUBSPACE_1_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT64 AddressLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT16 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckWrite;
} EFI_ACPI_6_5_PCCT_SUBSPACE_2_HW_REDUCED_COMMUNICATIONS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT32 PlatformInterrupt;
  UINT8 PlatformInterruptFlags;
  UINT8 Reserved;
  UINT64 BaseAddress;
  UINT32 AddressLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  UINT32 NominalLatency;
  UINT32 MaximumPeriodicAccessRate;
  UINT32 MinimumRequestTurnaroundTime;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE PlatformInterruptAckRegister;
  UINT64 PlatformInterruptAckPreserve;
  UINT64 PlatformInterruptAckSet;
  UINT8 Reserved1[8];
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE CommandCompleteCheckRegister;
  UINT64 CommandCompleteCheckMask;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE CommandCompleteUpdateRegister;
  UINT64 CommandCompleteUpdatePreserve;
  UINT64 CommandCompleteUpdateSet;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE ErrorStatusRegister;
  UINT64 ErrorStatusMask;
} EFI_ACPI_6_5_PCCT_SUBSPACE_3_EXTENDED_PCC;
typedef EFI_ACPI_6_5_PCCT_SUBSPACE_3_EXTENDED_PCC EFI_ACPI_6_5_PCCT_SUBSPACE_4_EXTENDED_PCC;
typedef struct 
{
  UINT32 Signature;
  UINT32 Flags;
  UINT32 Length;
  UINT32 Command;
} EFI_ACPI_6_5_PCCT_EXTENDED_PCC_SHARED_MEMORY_REGION_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT16 Version;
  UINT64 BaseAddress;
  UINT64 SharedMemoryRangeLength;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE DoorbellRegister;
  UINT64 DoorbellPreserve;
  UINT64 DoorbellWrite;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE CommandCompleteCheckRegister;
  UINT64 CommandCompleteCheckMask;
  EFI_ACPI_6_5_GENERIC_ADDRESS_STRUCTURE ErrorStatusRegister;
  UINT64 ErrorStatusMask;
  UINT32 NominalLatency;
  UINT32 MinimumRequestTurnaroundTime;
} EFI_ACPI_6_5_PCCT_SUBSPACE_5_HW_REGISTERS_COMMUNICATIONS;
typedef struct 
{
  UINT32 Signature;
} EFI_6_5_PCCT_REDUCED_PCC_SUBSPACE_SHARED_MEMORY_REGION;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  UINT8 TriggerCount;
  UINT8 Reserved[3];
  UINT32 TriggerIdentifierArrayOffset;
} EFI_ACPI_6_5_PLATFORM_DEBUG_TRIGGER_TABLE_HEADER;
typedef struct 
{
  UINT16 SubChannelIdentifer : 8;
  UINT16 Runtime : 1;
  UINT16 WaitForCompletion : 1;
  UINT16 TriggerOrder : 1;
  UINT16 Reserved : 5;
} EFI_ACPI_6_5_PDTT_PCC_IDENTIFIER;
typedef EFI_ACPI_6_5_PCCT_GENERIC_SHARED_MEMORY_REGION_HEADER EFI_ACPI_6_5_PDTT_PCC;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_5_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_HEADER;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
} EFI_ACPI_6_5_PPTT_STRUCTURE_HEADER;
typedef struct 
{
  UINT32 PhysicalPackage : 1;
  UINT32 AcpiProcessorIdValid : 1;
  UINT32 ProcessorIsAThread : 1;
  UINT32 NodeIsALeaf : 1;
  UINT32 IdenticalImplementation : 1;
  UINT32 Reserved : 27;
} EFI_ACPI_6_5_PPTT_STRUCTURE_PROCESSOR_FLAGS;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_5_PPTT_STRUCTURE_PROCESSOR_FLAGS Flags;
  UINT32 Parent;
  UINT32 AcpiProcessorId;
  UINT32 NumberOfPrivateResources;
} EFI_ACPI_6_5_PPTT_STRUCTURE_PROCESSOR;
typedef struct 
{
  UINT32 SizePropertyValid : 1;
  UINT32 NumberOfSetsValid : 1;
  UINT32 AssociativityValid : 1;
  UINT32 AllocationTypeValid : 1;
  UINT32 CacheTypeValid : 1;
  UINT32 WritePolicyValid : 1;
  UINT32 LineSizeValid : 1;
  UINT32 CacheIdValid : 1;
  UINT32 Reserved : 24;
} EFI_ACPI_6_5_PPTT_STRUCTURE_CACHE_FLAGS;
typedef struct 
{
  UINT8 AllocationType : 2;
  UINT8 CacheType : 2;
  UINT8 WritePolicy : 1;
  UINT8 Reserved : 3;
} EFI_ACPI_6_5_PPTT_STRUCTURE_CACHE_ATTRIBUTES;
typedef struct 
{
  UINT8 Type;
  UINT8 Length;
  UINT8 Reserved[2];
  EFI_ACPI_6_5_PPTT_STRUCTURE_CACHE_FLAGS Flags;
  UINT32 NextLevelOfCache;
  UINT32 Size;
  UINT32 NumberOfSets;
  UINT8 Associativity;
  EFI_ACPI_6_5_PPTT_STRUCTURE_CACHE_ATTRIBUTES Attributes;
  UINT16 LineSize;
  UINT32 CacheId;
} EFI_ACPI_6_5_PPTT_STRUCTURE_CACHE;
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
} EFI_ACPI_6_5_PLATFORM_HEALTH_ASSESSMENT_TABLE;
typedef struct 
{
  UINT16 PlatformHealthAssessmentRecordType;
  UINT16 RecordLength;
  UINT8 Revision;
} EFI_ACPI_6_5_PHAT_RECORD;
typedef struct 
{
  GUID ComponentId;
  UINT64 VersionValue;
  UINT32 ProducerId;
} EFI_ACPI_6_5_PHAT_VERSION_ELEMENT;
typedef struct 
{
  UINT16 PlatformRecordType;
  UINT16 RecordLength;
  UINT8 Revision;
  UINT8 Reserved[3];
  UINT32 RecordCount;
} EFI_ACPI_6_5_PHAT_FIRMWARE_VERISON_DATA_RECORD;
typedef struct 
{
  UINT16 PlatformRecordType;
  UINT16 RecordLength;
  UINT8 Revision;
  UINT16 Reserved;
  UINT8 AmHealthy;
  GUID DeviceSignature;
  UINT32 DeviceSpecificDataOffset;
} EFI_ACPI_6_5_PHAT_FIRMWARE_HEALTH_DATA_RECORD_STRUCTURE;
typedef struct 
{
  GUID VendorDataID;
  UINT16 Length;
  UINT16 Revision;
} EFI_ACPI_6_5_PHAT_RESET_REASON_HEALTH_RECORD_VENDOR_DATA_ENTRY;
typedef struct 
{
  UINT8 SupportedSources;
  UINT8 Source;
  UINT8 SubSource;
  UINT8 Reason;
  UINT16 VendorCount;
} EFI_ACPI_6_5_PHAT_RESET_REASON_HEALTH_RECORD_STRUCTURE;
#pragma pack()
typedef struct _PEI_SEC_PERFORMANCE_PPI PEI_SEC_PERFORMANCE_PPI;
typedef struct 
{
  UINT64 ResetEnd;
} FIRMWARE_SEC_PERFORMANCE;
typedef EFI_STATUS (*GET_SEC_PERFORMANCE)(const EFI_PEI_SERVICES **PeiServices, PEI_SEC_PERFORMANCE_PPI *This, FIRMWARE_SEC_PERFORMANCE *Performance);
struct _PEI_SEC_PERFORMANCE_PPI
{
  GET_SEC_PERFORMANCE GetPerformance;
};
extern EFI_GUID gPeiSecPerformancePpiGuid;
#pragma pack(1)
typedef struct 
{
  EFI_ACPI_DESCRIPTION_HEADER Header;
  EFI_ACPI_5_0_FPDT_BOOT_PERFORMANCE_TABLE_POINTER_RECORD BootPointerRecord;
  EFI_ACPI_5_0_FPDT_S3_PERFORMANCE_TABLE_POINTER_RECORD S3PointerRecord;
} FIRMWARE_PERFORMANCE_TABLE;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
  EFI_ACPI_5_0_FPDT_S3_RESUME_RECORD S3Resume;
  EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD S3Suspend;
} S3_PERFORMANCE_TABLE;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
  EFI_ACPI_5_0_FPDT_FIRMWARE_BASIC_BOOT_RECORD BasicBoot;
} BOOT_PERFORMANCE_TABLE;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER Header;
} SMM_BOOT_PERFORMANCE_TABLE;
typedef struct 
{
  BOOT_PERFORMANCE_TABLE BootPerformance;
  S3_PERFORMANCE_TABLE S3Performance;
} FIRMWARE_PERFORMANCE_RUNTIME_DATA;
typedef struct 
{
  EFI_PHYSICAL_ADDRESS BootPerformanceTablePointer;
  EFI_PHYSICAL_ADDRESS S3PerformanceTablePointer;
} FIRMWARE_PERFORMANCE_VARIABLE;
#pragma pack()
typedef struct 
{
  UINTN Function;
  EFI_STATUS ReturnStatus;
  UINTN BootRecordSize;
  void *BootRecordData;
  UINTN BootRecordOffset;
} SMM_BOOT_RECORD_COMMUNICATE;
extern EFI_GUID gEfiFirmwarePerformanceGuid;
extern EFI_GUID gFirmwarePerformanceS3PointerGuid;
typedef struct 
{
  UINT32 Revision;
  UINT32 Reserved;
  UINT64 Frequency;
  UINT64 TimerStartValue;
  UINT64 TimerEndValue;
} PERFORMANCE_PROPERTY;
typedef struct 
{
  EFI_PHYSICAL_ADDRESS Handle;
  CHAR8 Token[8];
  CHAR8 Module[8];
  UINT64 StartTimeStamp;
  UINT64 EndTimeStamp;
} PEI_PERFORMANCE_LOG_ENTRY;
typedef struct 
{
  UINT32 NumberOfEntries;
  UINT32 Reserved;
} PEI_PERFORMANCE_LOG_HEADER;
typedef struct _PERFORMANCE_PROTOCOL PERFORMANCE_PROTOCOL;
typedef struct _PERFORMANCE_EX_PROTOCOL PERFORMANCE_EX_PROTOCOL;
typedef struct 
{
  EFI_PHYSICAL_ADDRESS Handle;
  CHAR8 Token[32];
  CHAR8 Module[32];
  UINT64 StartTimeStamp;
  UINT64 EndTimeStamp;
} GAUGE_DATA_ENTRY;
typedef struct 
{
  EFI_PHYSICAL_ADDRESS Handle;
  CHAR8 Token[32];
  CHAR8 Module[32];
  UINT64 StartTimeStamp;
  UINT64 EndTimeStamp;
  UINT32 Identifier;
} GAUGE_DATA_ENTRY_EX;
typedef struct 
{
  UINT32 NumberOfEntries;
  UINT32 Reserved;
} GAUGE_DATA_HEADER;
typedef struct 
{
  UINTN Function;
  EFI_STATUS ReturnStatus;
  UINTN NumberOfEntries;
  UINTN LogEntryKey;
  GAUGE_DATA_ENTRY *GaugeData;
} SMM_PERF_COMMUNICATE;
typedef struct 
{
  UINTN Function;
  EFI_STATUS ReturnStatus;
  UINTN NumberOfEntries;
  UINTN LogEntryKey;
  GAUGE_DATA_ENTRY_EX *GaugeDataEx;
} SMM_PERF_COMMUNICATE_EX;
typedef EFI_STATUS (*PERFORMANCE_START_GAUGE)(const void *Handle, const CHAR8 *Token, const CHAR8 *Module, UINT64 TimeStamp);
typedef EFI_STATUS (*PERFORMANCE_END_GAUGE)(const void *Handle, const CHAR8 *Token, const CHAR8 *Module, UINT64 TimeStamp);
typedef EFI_STATUS (*PERFORMANCE_GET_GAUGE)(UINTN LogEntryKey, GAUGE_DATA_ENTRY **GaugeDataEntry);
typedef EFI_STATUS (*PERFORMANCE_START_GAUGE_EX)(const void *Handle, const CHAR8 *Token, const CHAR8 *Module, UINT64 TimeStamp, UINT32 Identifier);
typedef EFI_STATUS (*PERFORMANCE_END_GAUGE_EX)(const void *Handle, const CHAR8 *Token, const CHAR8 *Module, UINT64 TimeStamp, UINT32 Identifier);
typedef EFI_STATUS (*PERFORMANCE_GET_GAUGE_EX)(UINTN LogEntryKey, GAUGE_DATA_ENTRY_EX **GaugeDataEntryEx);
struct _PERFORMANCE_PROTOCOL
{
  PERFORMANCE_START_GAUGE StartGauge;
  PERFORMANCE_END_GAUGE EndGauge;
  PERFORMANCE_GET_GAUGE GetGauge;
};
struct _PERFORMANCE_EX_PROTOCOL
{
  PERFORMANCE_START_GAUGE_EX StartGaugeEx;
  PERFORMANCE_END_GAUGE_EX EndGaugeEx;
  PERFORMANCE_GET_GAUGE_EX GetGaugeEx;
};
extern EFI_GUID gPerformanceProtocolGuid;
extern EFI_GUID gSmmPerformanceProtocolGuid;
extern EFI_GUID gPerformanceExProtocolGuid;
extern EFI_GUID gSmmPerformanceExProtocolGuid;
#pragma pack(1)
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT16 ProgressID;
  UINT32 ApicID;
  UINT64 Timestamp;
  EFI_GUID Guid;
} FPDT_GUID_EVENT_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT16 ProgressID;
  UINT32 ApicID;
  UINT64 Timestamp;
  EFI_GUID Guid;
  CHAR8 String[0];
} FPDT_DYNAMIC_STRING_EVENT_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT16 ProgressID;
  UINT32 ApicID;
  UINT64 Timestamp;
  EFI_GUID Guid1;
  EFI_GUID Guid2;
  CHAR8 String[0];
} FPDT_DUAL_GUID_STRING_EVENT_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT16 ProgressID;
  UINT32 ApicID;
  UINT64 Timestamp;
  EFI_GUID Guid;
  UINT64 Qword;
} FPDT_GUID_QWORD_EVENT_RECORD;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER Header;
  UINT16 ProgressID;
  UINT32 ApicID;
  UINT64 Timestamp;
  EFI_GUID Guid;
  UINT64 Qword;
  CHAR8 String[0];
} FPDT_GUID_QWORD_STRING_EVENT_RECORD;
#pragma pack()
typedef union 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER RecordHeader;
  FPDT_GUID_EVENT_RECORD GuidEvent;
  FPDT_DYNAMIC_STRING_EVENT_RECORD DynamicStringEvent;
  FPDT_DUAL_GUID_STRING_EVENT_RECORD DualGuidStringEvent;
  FPDT_GUID_QWORD_EVENT_RECORD GuidQwordEvent;
  FPDT_GUID_QWORD_STRING_EVENT_RECORD GuidQwordStringEvent;
} FPDT_RECORD;
typedef union 
{
  EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER *RecordHeader;
  FPDT_GUID_EVENT_RECORD *GuidEvent;
  FPDT_DYNAMIC_STRING_EVENT_RECORD *DynamicStringEvent;
  FPDT_DUAL_GUID_STRING_EVENT_RECORD *DualGuidStringEvent;
  FPDT_GUID_QWORD_EVENT_RECORD *GuidQwordEvent;
  FPDT_GUID_QWORD_STRING_EVENT_RECORD *GuidQwordStringEvent;
} FPDT_RECORD_PTR;
typedef struct 
{
  UINT32 SizeOfAllEntries;
  UINT32 LoadImageCount;
  UINT32 HobIsFull;
} FPDT_PEI_EXT_PERF_HEADER;
extern EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid;
EFI_STATUS PeiServicesInstallPpi(const EFI_PEI_PPI_DESCRIPTOR *PpiList);
EFI_STATUS PeiServicesReInstallPpi(const EFI_PEI_PPI_DESCRIPTOR *OldPpi, const EFI_PEI_PPI_DESCRIPTOR *NewPpi);
EFI_STATUS PeiServicesLocatePpi(const EFI_GUID *Guid, UINTN Instance, EFI_PEI_PPI_DESCRIPTOR **PpiDescriptor, void **Ppi);
EFI_STATUS PeiServicesNotifyPpi(const EFI_PEI_NOTIFY_DESCRIPTOR *NotifyList);
EFI_STATUS PeiServicesGetBootMode(EFI_BOOT_MODE *BootMode);
EFI_STATUS PeiServicesSetBootMode(EFI_BOOT_MODE BootMode);
EFI_STATUS PeiServicesGetHobList(void **HobList);
EFI_STATUS PeiServicesCreateHob(UINT16 Type, UINT16 Length, void **Hob);
EFI_STATUS PeiServicesFfsFindNextVolume(UINTN Instance, EFI_PEI_FV_HANDLE *VolumeHandle);
EFI_STATUS PeiServicesFfsFindNextFile(EFI_FV_FILETYPE SearchType, EFI_PEI_FV_HANDLE VolumeHandle, EFI_PEI_FILE_HANDLE *FileHandle);
EFI_STATUS PeiServicesFfsFindSectionData(EFI_SECTION_TYPE SectionType, EFI_PEI_FILE_HANDLE FileHandle, void **SectionData);
EFI_STATUS PeiServicesFfsFindSectionData3(EFI_SECTION_TYPE SectionType, UINTN SectionInstance, EFI_PEI_FILE_HANDLE FileHandle, void **SectionData, UINT32 *AuthenticationStatus);
EFI_STATUS PeiServicesInstallPeiMemory(EFI_PHYSICAL_ADDRESS MemoryBegin, UINT64 MemoryLength);
EFI_STATUS PeiServicesAllocatePages(EFI_MEMORY_TYPE MemoryType, UINTN Pages, EFI_PHYSICAL_ADDRESS *Memory);
EFI_STATUS PeiServicesFreePages(EFI_PHYSICAL_ADDRESS Memory, UINTN Pages);
EFI_STATUS PeiServicesAllocatePool(UINTN Size, void **Buffer);
EFI_STATUS PeiServicesResetSystem(void);
EFI_STATUS PeiServicesFfsFindFileByName(const EFI_GUID *FileName, const EFI_PEI_FV_HANDLE VolumeHandle, EFI_PEI_FILE_HANDLE *FileHandle);
EFI_STATUS PeiServicesFfsGetFileInfo(const EFI_PEI_FILE_HANDLE FileHandle, EFI_FV_FILE_INFO *FileInfo);
EFI_STATUS PeiServicesFfsGetFileInfo2(const EFI_PEI_FILE_HANDLE FileHandle, EFI_FV_FILE_INFO2 *FileInfo);
EFI_STATUS PeiServicesFfsGetVolumeInfo(EFI_PEI_FV_HANDLE VolumeHandle, EFI_FV_INFO *VolumeInfo);
EFI_STATUS PeiServicesRegisterForShadow(EFI_PEI_FILE_HANDLE FileHandle);
void PeiServicesInstallFvInfoPpi(const EFI_GUID *FvFormat, const void *FvInfo, UINT32 FvInfoSize, const EFI_GUID *ParentFvName, const EFI_GUID *ParentFileName);
void PeiServicesInstallFvInfo2Ppi(const EFI_GUID *FvFormat, const void *FvInfo, UINT32 FvInfoSize, const EFI_GUID *ParentFvName, const EFI_GUID *ParentFileName, UINT32 AuthenticationStatus);
void PeiServicesResetSystem2(EFI_RESET_TYPE ResetType, EFI_STATUS ResetStatus, UINTN DataSize, void *ResetData);
void DebugPrint(UINTN ErrorLevel, const CHAR8 *Format, ...);
void DebugVPrint(UINTN ErrorLevel, const CHAR8 *Format, VA_LIST VaListMarker);
void DebugBPrint(UINTN ErrorLevel, const CHAR8 *Format, BASE_LIST BaseListMarker);
void DebugAssert(const CHAR8 *FileName, UINTN LineNumber, const CHAR8 *Description);
void *DebugClearMemory(void *Buffer, UINTN Length);
BOOLEAN DebugAssertEnabled(void);
BOOLEAN DebugPrintEnabled(void);
BOOLEAN DebugCodeEnabled(void);
BOOLEAN DebugClearMemoryEnabled(void);
BOOLEAN DebugPrintLevelEnabled(const UINTN ErrorLevel);
UINTN MicroSecondDelay(UINTN MicroSeconds);
UINTN NanoSecondDelay(UINTN NanoSeconds);
UINT64 GetPerformanceCounter(void);
UINT64 GetPerformanceCounterProperties(UINT64 *StartValue, UINT64 *EndValue);
UINT64 GetTimeInNanoSecond(UINT64 Ticks);
void *CopyMem(void *DestinationBuffer, const void *SourceBuffer, UINTN Length);
void *SetMem(void *Buffer, UINTN Length, UINT8 Value);
void *SetMem16(void *Buffer, UINTN Length, UINT16 Value);
void *SetMem32(void *Buffer, UINTN Length, UINT32 Value);
void *SetMem64(void *Buffer, UINTN Length, UINT64 Value);
void *SetMemN(void *Buffer, UINTN Length, UINTN Value);
void *ZeroMem(void *Buffer, UINTN Length);
INTN CompareMem(const void *DestinationBuffer, const void *SourceBuffer, UINTN Length);
void *ScanMem8(const void *Buffer, UINTN Length, UINT8 Value);
void *ScanMem16(const void *Buffer, UINTN Length, UINT16 Value);
void *ScanMem32(const void *Buffer, UINTN Length, UINT32 Value);
void *ScanMem64(const void *Buffer, UINTN Length, UINT64 Value);
void *ScanMemN(const void *Buffer, UINTN Length, UINTN Value);
GUID *CopyGuid(GUID *DestinationGuid, const GUID *SourceGuid);
BOOLEAN CompareGuid(const GUID *Guid1, const GUID *Guid2);
void *ScanGuid(const void *Buffer, UINTN Length, const GUID *Guid);
BOOLEAN IsZeroGuid(const GUID *Guid);
BOOLEAN IsZeroBuffer(const void *Buffer, UINTN Length);
RETURN_STATUS SaveLockBox(GUID *Guid, void *Buffer, UINTN Length);
RETURN_STATUS SetLockBoxAttributes(GUID *Guid, UINT64 Attributes);
RETURN_STATUS UpdateLockBox(GUID *Guid, UINTN Offset, void *Buffer, UINTN Length);
RETURN_STATUS RestoreLockBox(GUID *Guid, void *Buffer, UINTN *Length);
RETURN_STATUS RestoreAllLockBoxInPlace(void);
UINTN LibPcdSetSku(UINTN SkuId);
UINT8 LibPcdGet8(UINTN TokenNumber);
UINT16 LibPcdGet16(UINTN TokenNumber);
UINT32 LibPcdGet32(UINTN TokenNumber);
UINT64 LibPcdGet64(UINTN TokenNumber);
void *LibPcdGetPtr(UINTN TokenNumber);
BOOLEAN LibPcdGetBool(UINTN TokenNumber);
UINTN LibPcdGetSize(UINTN TokenNumber);
UINT8 LibPcdGetEx8(const GUID *Guid, UINTN TokenNumber);
UINT16 LibPcdGetEx16(const GUID *Guid, UINTN TokenNumber);
UINT32 LibPcdGetEx32(const GUID *Guid, UINTN TokenNumber);
UINT64 LibPcdGetEx64(const GUID *Guid, UINTN TokenNumber);
void *LibPcdGetExPtr(const GUID *Guid, UINTN TokenNumber);
BOOLEAN LibPcdGetExBool(const GUID *Guid, UINTN TokenNumber);
UINTN LibPcdGetExSize(const GUID *Guid, UINTN TokenNumber);
RETURN_STATUS LibPcdSet8S(UINTN TokenNumber, UINT8 Value);
RETURN_STATUS LibPcdSet16S(UINTN TokenNumber, UINT16 Value);
RETURN_STATUS LibPcdSet32S(UINTN TokenNumber, UINT32 Value);
RETURN_STATUS LibPcdSet64S(UINTN TokenNumber, UINT64 Value);
RETURN_STATUS LibPcdSetPtrS(UINTN TokenNumber, UINTN *SizeOfBuffer, const void *Buffer);
RETURN_STATUS LibPcdSetBoolS(UINTN TokenNumber, BOOLEAN Value);
RETURN_STATUS LibPcdSetEx8S(const GUID *Guid, UINTN TokenNumber, UINT8 Value);
RETURN_STATUS LibPcdSetEx16S(const GUID *Guid, UINTN TokenNumber, UINT16 Value);
RETURN_STATUS LibPcdSetEx32S(const GUID *Guid, UINTN TokenNumber, UINT32 Value);
RETURN_STATUS LibPcdSetEx64S(const GUID *Guid, UINTN TokenNumber, UINT64 Value);
RETURN_STATUS LibPcdSetExPtrS(const GUID *Guid, UINTN TokenNumber, UINTN *SizeOfBuffer, void *Buffer);
RETURN_STATUS LibPcdSetExBoolS(const GUID *Guid, UINTN TokenNumber, BOOLEAN Value);
typedef void (*PCD_CALLBACK)(const GUID *CallBackGuid, UINTN CallBackToken, void *TokenData, UINTN TokenDataSize);
void LibPcdCallbackOnSet(const GUID *Guid, UINTN TokenNumber, PCD_CALLBACK NotificationFunction);
void LibPcdCancelCallback(const GUID *Guid, UINTN TokenNumber, PCD_CALLBACK NotificationFunction);
UINTN LibPcdGetNextToken(const GUID *Guid, UINTN TokenNumber);
GUID *LibPcdGetNextTokenSpace(const GUID *TokenSpaceGuid);
void *LibPatchPcdSetPtr(void *PatchVariable, UINTN MaximumDatumSize, UINTN *SizeOfBuffer, const void *Buffer);
RETURN_STATUS LibPatchPcdSetPtrS(void *PatchVariable, UINTN MaximumDatumSize, UINTN *SizeOfBuffer, const void *Buffer);
void *LibPatchPcdSetPtrAndSize(void *PatchVariable, UINTN *SizeOfPatchVariable, UINTN MaximumDatumSize, UINTN *SizeOfBuffer, const void *Buffer);
RETURN_STATUS LibPatchPcdSetPtrAndSizeS(void *PatchVariable, UINTN *SizeOfPatchVariable, UINTN MaximumDatumSize, UINTN *SizeOfBuffer, const void *Buffer);
typedef enum 
{
  PCD_TYPE_8,
  PCD_TYPE_16,
  PCD_TYPE_32,
  PCD_TYPE_64,
  PCD_TYPE_BOOL,
  PCD_TYPE_PTR
} PCD_TYPE;
typedef struct 
{
  PCD_TYPE PcdType;
  UINTN PcdSize;
  CHAR8 *PcdName;
} PCD_INFO;
void LibPcdGetInfo(UINTN TokenNumber, PCD_INFO *PcdInfo);
void LibPcdGetInfoEx(const GUID *Guid, UINTN TokenNumber, PCD_INFO *PcdInfo);
UINTN LibPcdGetSku(void);
void *GetHobList(void);
void *GetNextHob(UINT16 Type, const void *HobStart);
void *GetFirstHob(UINT16 Type);
void *GetNextGuidHob(const EFI_GUID *Guid, const void *HobStart);
void *GetFirstGuidHob(const EFI_GUID *Guid);
EFI_BOOT_MODE GetBootModeHob(void);
void BuildModuleHob(const EFI_GUID *ModuleName, EFI_PHYSICAL_ADDRESS MemoryAllocationModule, UINT64 ModuleLength, EFI_PHYSICAL_ADDRESS EntryPoint);
void BuildResourceDescriptorWithOwnerHob(EFI_RESOURCE_TYPE ResourceType, EFI_RESOURCE_ATTRIBUTE_TYPE ResourceAttribute, EFI_PHYSICAL_ADDRESS PhysicalStart, UINT64 NumberOfBytes, EFI_GUID *OwnerGUID);
void BuildResourceDescriptorHob(EFI_RESOURCE_TYPE ResourceType, EFI_RESOURCE_ATTRIBUTE_TYPE ResourceAttribute, EFI_PHYSICAL_ADDRESS PhysicalStart, UINT64 NumberOfBytes);
void *BuildGuidHob(const EFI_GUID *Guid, UINTN DataLength);
void *BuildGuidDataHob(const EFI_GUID *Guid, void *Data, UINTN DataLength);
void BuildFvHob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length);
void BuildFv2Hob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length, const EFI_GUID *FvName, const EFI_GUID *FileName);
void BuildFv3Hob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length, UINT32 AuthenticationStatus, BOOLEAN ExtractedFv, const EFI_GUID *FvName, const EFI_GUID *FileName);
void BuildCvHob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length);
void BuildCpuHob(UINT8 SizeOfMemorySpace, UINT8 SizeOfIoSpace);
void BuildStackHob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length);
void BuildBspStoreHob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length, EFI_MEMORY_TYPE MemoryType);
void BuildMemoryAllocationHob(EFI_PHYSICAL_ADDRESS BaseAddress, UINT64 Length, EFI_MEMORY_TYPE MemoryType);
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
typedef EFI_STATUS (*EFI_PEI_GET_VARIABLE2)(const struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This, const CHAR16 *VariableName, const EFI_GUID *VariableGuid, UINT32 *Attributes, UINTN *DataSize, void *Data);
static BOOT_PERFORMANCE_TABLE SimulatedPerformanceVariable = {.Header.Length = 10};
EFI_STATUS myGetVariable(const struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This, const CHAR16 *VariableName, const EFI_GUID *VariableGuid, UINT32 *Attributes, UINTN *DataSize, void *Data)
{
  *((BOOT_PERFORMANCE_TABLE **) Data) = &SimulatedPerformanceVariable;
  return 0;
}

typedef EFI_STATUS (*EFI_PEI_GET_NEXT_VARIABLE_NAME2)(const struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This, UINTN *VariableNameSize, CHAR16 *VariableName, EFI_GUID *VariableGuid);
EFI_STATUS myNextVariable(const struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This, UINTN *VariableNameSize, CHAR16 *VariableName, EFI_GUID *VariableGuid)
{
  return 0;
}

typedef struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI EFI_PEI_READ_ONLY_VARIABLE2_PPI;
EFI_PEI_READ_ONLY_VARIABLE2_PPI vars = {.GetVariable = &myGetVariable, .NextVariableName = &myNextVariable};
typedef struct 
{
  UINT32 Signature;
} EFI_ACPI_5_0_FPDT_HEADER;
typedef struct 
{
  EFI_ACPI_5_0_FPDT_HEADER Header;
  UINT64 FullResume;
  UINT64 AverageResume;
  UINT32 ResumeCount;
} S3_RESUME_RECORD;
void *CopyMem(void *DestinationBuffer, const void *SourceBuffer, UINTN Length)
{
  return memcpy(DestinationBuffer, SourceBuffer, Length);
}

void DebugAssert(const CHAR8 *FileName, UINTN LineNumber, const CHAR8 *Description)
{
}

UINT64 DivU64x32(UINT64 Dividend, UINT32 Divisor)
{
  return Dividend / Divisor;
}

void *ZeroMem(void *Buffer, UINTN Length)
{
  return memset(Buffer, 0, Length);
}

BOOLEAN DebugAssertEnabled(void)
{
  return 0 == 0;
}

void DebugPrint(UINTN ErrorLevel, const CHAR8 *Format, ...)
{
}

BOOLEAN DebugPrintEnabled(void)
{
  return 0 == 0;
}

BOOLEAN DebugPrintLevelEnabled(const UINTN ErrorLevel)
{
  return 0 == 0;
}

void *GetFirstGuidHob(const EFI_GUID *Guid)
{
  return (void *) 0;
}

void *GetNextGuidHob(const EFI_GUID *Guid, const void *HobStart)
{
  return (void *) 0;
}

UINT64 GetPerformanceCounter(void)
{
  return 10;
}

UINT64 GetTimeInNanoSecond(UINT64 Ticks)
{
  return 20;
}

UINT64 MultU64x32(UINT64 Multiplicand, UINT32 Multiplier)
{
  return Multiplicand * Multiplier;
}

EFI_STATUS PeiServicesLocatePpi(const EFI_GUID *Guid, UINTN Instance, EFI_PEI_PPI_DESCRIPTOR **PpiDescriptor, void **Ppi)
{
  *((void **) Ppi) = &vars;
  return 0;
}

S3_PERFORMANCE_TABLE myTable = {.Header = (EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER){.Signature = 0, .Length = 20}, .S3Resume = (EFI_ACPI_5_0_FPDT_S3_RESUME_RECORD){.Header = (EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER){.Type = 10, .Length = 20, .Revision = 30}, .ResumeCount = 123, .FullResume = 10, .AverageResume = 10}, .S3Suspend = (EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD){.Header = (EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER){.Type = 10, .Length = 20, .Revision = 30}, .SuspendStart = 10, .SuspendEnd = 10}};
RETURN_STATUS RestoreLockBox(GUID *Guid, void *Buffer, UINTN *Length)
{
  *((S3_PERFORMANCE_TABLE **) Buffer) = &myTable;
  *Length = sizeof(&myTable);
  return 1;
}

GUID gFirmwarePerformanceS3PointerGuid = {.Data1 = 4, .Data2 = 5, .Data3 = 6, .Data4 = {120}};
GUID gEfiFirmwarePerformanceGuid = {.Data1 = 4, .Data2 = 5, .Data3 = 6, .Data4 = {120}};
EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid = {0, 0, 0};
EFI_GUID gEfiPeiReadOnlyVariable2PpiGuid = {0, 0, 0};
EFI_STATUS FpdtStatusCodeListenerPei(const EFI_PEI_SERVICES **PeiServices, EFI_STATUS_CODE_TYPE CodeType, EFI_STATUS_CODE_VALUE Value, UINT32 Instance, const EFI_GUID *CallerId, const EFI_STATUS_CODE_DATA *Data)
{
  EFI_STATUS Status;
  UINT64 CurrentTime;
  UINTN VarSize;
  EFI_PHYSICAL_ADDRESS S3PerformanceTablePointer;
  S3_PERFORMANCE_TABLE *AcpiS3PerformanceTable;
  EFI_ACPI_5_0_FPDT_S3_RESUME_RECORD *AcpiS3ResumeRecord;
  UINT64 S3ResumeTotal;
  EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD S3SuspendRecord;
  EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD *AcpiS3SuspendRecord;
  EFI_PEI_READ_ONLY_VARIABLE2_PPI *VariableServices;
  UINT8 *BootPerformanceTable;
  FIRMWARE_PERFORMANCE_VARIABLE PerformanceVariable;
  EFI_HOB_GUID_TYPE *GuidHob;
  FPDT_PEI_EXT_PERF_HEADER *PeiPerformanceLogHeader;
  UINT8 *FirmwarePerformanceData;
  UINT8 *FirmwarePerformanceTablePtr;
  if (((CodeType & 0x000000FF) != 0x00000001) || (Value != ((0x03000000 | 0x00030000) | (0x1000 | 0x00000006))))
  {
    return (RETURN_STATUS) (0x8000000000000000ULL | 3);
  }
  CurrentTime = GetTimeInNanoSecond(GetPerformanceCounter());
  S3PerformanceTablePointer = 0;
  VarSize = sizeof(EFI_PHYSICAL_ADDRESS);
  Status = RestoreLockBox(&gFirmwarePerformanceS3PointerGuid, &S3PerformanceTablePointer, &VarSize);
  do
  {
    if (DebugAssertEnabled())
    {
      if (((RETURN_STATUS) Status) >= 0x8000000000000000ULL)
      {
        do
        {
          if (DebugPrintEnabled())
          {
            do
            {
              if (DebugPrintLevelEnabled(0x80000000))
              {
                DebugPrint(0x80000000, "\nASSERT_EFI_ERROR (Status = %r)\n", Status);
              }
            }
            while ((BOOLEAN) (0 == 1));
          }
        }
        while ((BOOLEAN) (0 == 1));
        DebugAssert("FirmwarePerformancePei.c", 100, "!(((RETURN_STATUS)(Status)) >= 0x8000000000000000ULL)");
      }
    }
  }
  while ((BOOLEAN) (0 == 1));
  AcpiS3PerformanceTable = (S3_PERFORMANCE_TABLE *) ((UINTN) S3PerformanceTablePointer);
  do
  {
    if (DebugAssertEnabled())
    {
      if (!(AcpiS3PerformanceTable != ((void *) 0)))
      {
        DebugAssert("FirmwarePerformancePei.c", 103, "AcpiS3PerformanceTable != ((void*)0)");
        ;
      }
    }
  }
  while ((BOOLEAN) (0 == 1));
  if (AcpiS3PerformanceTable->Header.Signature != (('S' | ('3' << 8)) | (('P' | ('T' << 8)) << 16)))
  {
    do
    {
      if (DebugPrintEnabled())
      {
        do
        {
          if (DebugPrintLevelEnabled(0x80000000))
          {
            DebugPrint(0x80000000, "FPDT S3 performance data in ACPI memory get corrupted\n");
          }
        }
        while ((BOOLEAN) (0 == 1));
      }
    }
    while ((BOOLEAN) (0 == 1));
    return (RETURN_STATUS) (0x8000000000000000ULL | 21);
  }
  AcpiS3ResumeRecord = &AcpiS3PerformanceTable->S3Resume;
  AcpiS3ResumeRecord->FullResume = CurrentTime;
  S3ResumeTotal = MultU64x32(AcpiS3ResumeRecord->AverageResume, AcpiS3ResumeRecord->ResumeCount);
  AcpiS3ResumeRecord->ResumeCount++;
  AcpiS3ResumeRecord->AverageResume = DivU64x32(S3ResumeTotal + AcpiS3ResumeRecord->FullResume, AcpiS3ResumeRecord->ResumeCount);
  do
  {
    if (DebugPrintEnabled())
    {
      do
      {
        if (DebugPrintLevelEnabled(0x00000040))
        {
          DebugPrint(0x00000040, "FPDT: S3 Resume Performance - ResumeCount   = 0x%x\n", AcpiS3ResumeRecord->ResumeCount);
        }
      }
      while ((BOOLEAN) (0 == 1));
    }
  }
  while ((BOOLEAN) (0 == 1));
  do
  {
    if (DebugPrintEnabled())
    {
      do
      {
        if (DebugPrintLevelEnabled(0x00000040))
        {
          DebugPrint(0x00000040, "FPDT: S3 Resume Performance - FullResume    = 0x%x\n", AcpiS3ResumeRecord->FullResume);
        }
      }
      while ((BOOLEAN) (0 == 1));
    }
  }
  while ((BOOLEAN) (0 == 1));
  AcpiS3SuspendRecord = &AcpiS3PerformanceTable->S3Suspend;
  VarSize = sizeof(EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD);
  ZeroMem(&S3SuspendRecord, sizeof(EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD));
  Status = RestoreLockBox(&gEfiFirmwarePerformanceGuid, &S3SuspendRecord, &VarSize);
  do
  {
    if (DebugAssertEnabled())
    {
      if (((RETURN_STATUS) Status) >= 0x8000000000000000ULL)
      {
        do
        {
          if (DebugPrintEnabled())
          {
            do
            {
              if (DebugPrintLevelEnabled(0x80000000))
              {
                DebugPrint(0x80000000, "\nASSERT_EFI_ERROR (Status = %r)\n", Status);
              }
            }
            while ((BOOLEAN) (0 == 1));
          }
        }
        while ((BOOLEAN) (0 == 1));
        DebugAssert("FirmwarePerformancePei.c", 132, "!(((RETURN_STATUS)(Status)) >= 0x8000000000000000ULL)");
      }
    }
  }
  while ((BOOLEAN) (0 == 1));
  AcpiS3SuspendRecord->SuspendStart = S3SuspendRecord.SuspendStart;
  AcpiS3SuspendRecord->SuspendEnd = S3SuspendRecord.SuspendEnd;
  do
  {
    if (DebugPrintEnabled())
    {
      do
      {
        if (DebugPrintLevelEnabled(0x00000040))
        {
          DebugPrint(0x00000040, "FPDT: S3 Suspend Performance - SuspendStart = %ld\n", AcpiS3SuspendRecord->SuspendStart);
        }
      }
      while ((BOOLEAN) (0 == 1));
    }
  }
  while ((BOOLEAN) (0 == 1));
  do
  {
    if (DebugPrintEnabled())
    {
      do
      {
        if (DebugPrintLevelEnabled(0x00000040))
        {
          DebugPrint(0x00000040, "FPDT: S3 Suspend Performance - SuspendEnd   = %ld\n", AcpiS3SuspendRecord->SuspendEnd);
        }
      }
      while ((BOOLEAN) (0 == 1));
    }
  }
  while ((BOOLEAN) (0 == 1));
  Status = PeiServicesLocatePpi(&gEfiPeiReadOnlyVariable2PpiGuid, 0, (void *) 0, (void **) (&VariableServices));
  do
  {
    if (DebugAssertEnabled())
    {
      if (((RETURN_STATUS) Status) >= 0x8000000000000000ULL)
      {
        do
        {
          if (DebugPrintEnabled())
          {
            do
            {
              if (DebugPrintLevelEnabled(0x80000000))
              {
                DebugPrint(0x80000000, "\nASSERT_EFI_ERROR (Status = %r)\n", Status);
              }
            }
            while ((BOOLEAN) (0 == 1));
          }
        }
        while ((BOOLEAN) (0 == 1));
        DebugAssert("FirmwarePerformancePei.c", 145, "!(((RETURN_STATUS)(Status)) >= 0x8000000000000000ULL)");
      }
    }
  }
  while ((BOOLEAN) (0 == 1));
  VarSize = sizeof(PerformanceVariable);
  Status = VariableServices->GetVariable(VariableServices, L"FirmwarePerformance", &gEfiFirmwarePerformanceGuid, (void *) 0, &VarSize, &PerformanceVariable);
  if (((RETURN_STATUS) Status) >= 0x8000000000000000ULL)
  {
    return Status;
  }
  BootPerformanceTable = (UINT8 *) ((UINTN) PerformanceVariable.BootPerformanceTablePointer);
  FirmwarePerformanceTablePtr = BootPerformanceTable + (sizeof(BOOT_PERFORMANCE_TABLE));
  GuidHob = GetFirstGuidHob(&gEdkiiFpdtExtendedFirmwarePerformanceGuid);
  while (GuidHob != ((void *) 0))
  {
    FirmwarePerformanceData = (void *) ((*((UINT8 **) (&GuidHob))) + (sizeof(EFI_HOB_GUID_TYPE)));
    PeiPerformanceLogHeader = (FPDT_PEI_EXT_PERF_HEADER *) FirmwarePerformanceData;
    CopyMem(FirmwarePerformanceTablePtr, FirmwarePerformanceData + (sizeof(FPDT_PEI_EXT_PERF_HEADER)), (UINTN) PeiPerformanceLogHeader->SizeOfAllEntries);
    GuidHob = GetNextGuidHob(&gEdkiiFpdtExtendedFirmwarePerformanceGuid, (void *) ((*((UINT8 **) (&GuidHob))) + (*((EFI_HOB_GENERIC_HEADER **) (&GuidHob)))->HobLength));
    FirmwarePerformanceTablePtr += (UINTN) PeiPerformanceLogHeader->SizeOfAllEntries;
  }

  ((BOOT_PERFORMANCE_TABLE *) BootPerformanceTable)->Header.Length = (UINT32) (((UINTN) FirmwarePerformanceTablePtr) - ((UINTN) BootPerformanceTable));
  return (RETURN_STATUS) 0;
}


// End ansatz file


void set_globals(UINT32 global_1,UINT32 global_2) {

  myTable.Header.Signature = global_1;
  myTable.S3Resume.ResumeCount = global_2;
}


int main() {

  UINT32 global_1;
  klee_make_symbolic(&global_1, sizeof(global_1), "global_1");

  UINT32 global_2;
  klee_make_symbolic(&global_2, sizeof(global_2), "global_2");

  set_globals(global_1,global_2);

  EFI_PEI_SERVICES *pei_services = (EFI_PEI_SERVICES *)malloc(sizeof(EFI_PEI_SERVICES));
  EFI_GUID CallerId = {
      10,
      10,
      10};
  EFI_STATUS_CODE_DATA Data = {.HeaderSize = 4, .Size = 6, .Type = 1};
  UINT32 Instance = 0;
  extern GUID gEfiFirmwarePerformanceGuid;


  EFI_STATUS_CODE_TYPE CodeType;
  klee_make_symbolic(&CodeType, sizeof(CodeType), "CodeType");

  EFI_STATUS_CODE_VALUE Value;
  klee_make_symbolic(&Value, sizeof(Value), "Value");



  FpdtStatusCodeListenerPei((void *)pei_services,CodeType,Value,Instance,&CallerId,&Data);

  free(pei_services);


  return 0;
}
