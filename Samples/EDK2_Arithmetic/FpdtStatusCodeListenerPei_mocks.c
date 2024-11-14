#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "edk2_behemot.h"

#define EFIAPI
#define IN
#define OUT
#define OPTIONAL
#define CONST const
#define VOID void

typedef EFI_STATUS(EFIAPI *EFI_PEI_GET_VARIABLE2)(
    IN CONST struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This,
    IN CONST CHAR16 *VariableName,
    IN CONST EFI_GUID *VariableGuid,
    OUT UINT32 *Attributes,
    IN OUT UINTN *DataSize,
    OUT VOID *Data OPTIONAL);

static BOOT_PERFORMANCE_TABLE SimulatedPerformanceVariable = {.Header.Length = 10};

EFI_STATUS
myGetVariable(
    IN CONST struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This,
    IN CONST CHAR16 *VariableName,
    IN CONST EFI_GUID *VariableGuid,
    OUT UINT32 *Attributes,
    IN OUT UINTN *DataSize,
    OUT VOID *Data OPTIONAL)
{
  *(BOOT_PERFORMANCE_TABLE **)Data = &SimulatedPerformanceVariable;
  return 0;
}

typedef EFI_STATUS(EFIAPI *EFI_PEI_GET_NEXT_VARIABLE_NAME2)(
    IN CONST struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This,
    IN OUT UINTN *VariableNameSize,
    IN OUT CHAR16 *VariableName,
    IN OUT EFI_GUID *VariableGuid);

EFI_STATUS
myNextVariable(
    IN CONST struct _EFI_PEI_READ_ONLY_VARIABLE2_PPI *This,
    IN OUT UINTN *VariableNameSize,
    IN OUT CHAR16 *VariableName,
    IN OUT EFI_GUID *VariableGuid)
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

void *CopyMem(void *DestinationBuffer,
              const void *SourceBuffer,
              UINTN Length)
{
  return memcpy(DestinationBuffer, SourceBuffer, Length);
}

void DebugAssert(
    const CHAR8 *FileName,
    UINTN LineNumber,
    const CHAR8 *Description) {}

UINT64 DivU64x32(
    UINT64 Dividend,
    UINT32 Divisor)
{
  return Dividend / Divisor;
}

void *ZeroMem(
    void *Buffer,
    UINTN Length)
{
  return memset(Buffer, 0, Length);
}

BOOLEAN DebugAssertEnabled(void) { return 0 == 0; }
void DebugPrint(UINTN ErrorLevel,
                const CHAR8 *Format,
                ...) {}
BOOLEAN DebugPrintEnabled(void) { return 0 == 0; }
BOOLEAN DebugPrintLevelEnabled(const UINTN ErrorLevel) { return 0 == 0; }

void *GetFirstGuidHob(const EFI_GUID *Guid) { return NULL; }

void *GetNextGuidHob(
    const EFI_GUID *Guid,
    const void *HobStart) { return NULL; }

UINT64 GetPerformanceCounter(void) { return 10; }
UINT64 GetTimeInNanoSecond(UINT64 Ticks) { return 20; }
UINT64 MultU64x32(
    UINT64 Multiplicand,
    UINT32 Multiplier)
{
  return Multiplicand * Multiplier;
}

EFI_STATUS PeiServicesLocatePpi(
    const EFI_GUID *Guid,
    UINTN Instance,
    EFI_PEI_PPI_DESCRIPTOR **PpiDescriptor,
    void **Ppi)
{
  *(void **)Ppi = &vars;
  return 0;
}

S3_PERFORMANCE_TABLE myTable = {
    .Header = (EFI_ACPI_5_0_FPDT_PERFORMANCE_TABLE_HEADER){
        .Signature = 0,
        .Length = 20},
    .S3Resume = (EFI_ACPI_5_0_FPDT_S3_RESUME_RECORD){
        .Header = (EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER){
            .Type = 10,
            .Length = 20,
            .Revision = 30,
        },
        .ResumeCount = 123, // ! Symbolic
        .FullResume = 10,
        .AverageResume = 10,
    },
    .S3Suspend = (EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD){
        .Header = (EFI_ACPI_5_0_FPDT_PERFORMANCE_RECORD_HEADER){
            .Type = 10,
            .Length = 20,
            .Revision = 30,
        },
        .SuspendStart = 10,
        .SuspendEnd = 10,
    }};

RETURN_STATUS
RestoreLockBox(GUID *Guid, void *Buffer, UINTN *Length)
{
  *(S3_PERFORMANCE_TABLE **)Buffer = &myTable;
  *Length = sizeof(&myTable);

  return 1;
}

GUID gFirmwarePerformanceS3PointerGuid = {.Data1 = 4, .Data2 = 5, .Data3 = 6, .Data4 = {120}};
GUID gEfiFirmwarePerformanceGuid = {.Data1 = 4, .Data2 = 5, .Data3 = 6, .Data4 = {120}};

EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid = {
    0,
    0,
    0};

EFI_GUID gEfiPeiReadOnlyVariable2PpiGuid = {
    0,
    0,
    0};
