#include "FpdtStatusCodeListenerPei_mocks.c"

#include <klee/klee.h>

// Ansatz
EFI_STATUS
EFIAPI
FpdtStatusCodeListenerPei(
    IN CONST EFI_PEI_SERVICES **PeiServices,
    IN EFI_STATUS_CODE_TYPE CodeType,
    IN EFI_STATUS_CODE_VALUE Value,
    IN UINT32 Instance,
    IN CONST EFI_GUID *CallerId,
    IN CONST EFI_STATUS_CODE_DATA *Data)
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

  //
  // Check whether status code is what we are interested in.
  //
  if (((CodeType & EFI_STATUS_CODE_TYPE_MASK) != EFI_PROGRESS_CODE) ||
      (Value != (EFI_SOFTWARE_PEI_MODULE | EFI_SW_PEI_PC_OS_WAKE)))
  {
    return EFI_UNSUPPORTED;
  }

  //
  // Retrieve current time as early as possible.
  //
  CurrentTime = GetTimeInNanoSecond(GetPerformanceCounter());

  //
  // Update S3 Resume Performance Record.
  //
  S3PerformanceTablePointer = 0;
  VarSize = sizeof(EFI_PHYSICAL_ADDRESS);
  Status = RestoreLockBox(&gFirmwarePerformanceS3PointerGuid, &S3PerformanceTablePointer, &VarSize);
  ASSERT_EFI_ERROR(Status);

  AcpiS3PerformanceTable = (S3_PERFORMANCE_TABLE *)(UINTN)S3PerformanceTablePointer;
  ASSERT(AcpiS3PerformanceTable != NULL);
  if (AcpiS3PerformanceTable->Header.Signature != EFI_ACPI_5_0_FPDT_S3_PERFORMANCE_TABLE_SIGNATURE)
  {
    DEBUG((DEBUG_ERROR, "FPDT S3 performance data in ACPI memory get corrupted\n"));
    return EFI_ABORTED;
  }

  AcpiS3ResumeRecord = &AcpiS3PerformanceTable->S3Resume;
  AcpiS3ResumeRecord->FullResume = CurrentTime;
  //
  // Calculate average S3 resume time.
  //
  S3ResumeTotal = MultU64x32(AcpiS3ResumeRecord->AverageResume, AcpiS3ResumeRecord->ResumeCount);
  AcpiS3ResumeRecord->ResumeCount++;
  AcpiS3ResumeRecord->AverageResume = DivU64x32(S3ResumeTotal + AcpiS3ResumeRecord->FullResume, AcpiS3ResumeRecord->ResumeCount);

  DEBUG((DEBUG_INFO, "FPDT: S3 Resume Performance - ResumeCount   = 0x%x\n", AcpiS3ResumeRecord->ResumeCount));
  DEBUG((DEBUG_INFO, "FPDT: S3 Resume Performance - FullResume    = 0x%x\n", AcpiS3ResumeRecord->FullResume));

  //
  // Update S3 Suspend Performance Record.
  //
  AcpiS3SuspendRecord = &AcpiS3PerformanceTable->S3Suspend;
  VarSize = sizeof(EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD);
  ZeroMem(&S3SuspendRecord, sizeof(EFI_ACPI_5_0_FPDT_S3_SUSPEND_RECORD));
  Status = RestoreLockBox(
      &gEfiFirmwarePerformanceGuid,
      &S3SuspendRecord,
      &VarSize);
  ASSERT_EFI_ERROR(Status);

  AcpiS3SuspendRecord->SuspendStart = S3SuspendRecord.SuspendStart;
  AcpiS3SuspendRecord->SuspendEnd = S3SuspendRecord.SuspendEnd;

  DEBUG((DEBUG_INFO, "FPDT: S3 Suspend Performance - SuspendStart = %ld\n", AcpiS3SuspendRecord->SuspendStart));
  DEBUG((DEBUG_INFO, "FPDT: S3 Suspend Performance - SuspendEnd   = %ld\n", AcpiS3SuspendRecord->SuspendEnd));

  Status = PeiServicesLocatePpi(
      &gEfiPeiReadOnlyVariable2PpiGuid,
      0,
      NULL,
      (VOID **)&VariableServices);
  ASSERT_EFI_ERROR(Status);

  //
  // Update S3 boot records into the basic boot performance table.
  //
  VarSize = sizeof(PerformanceVariable);
  Status = VariableServices->GetVariable(
      VariableServices,
      EFI_FIRMWARE_PERFORMANCE_VARIABLE_NAME,
      &gEfiFirmwarePerformanceGuid,
      NULL,
      &VarSize,
      &PerformanceVariable);
  if (EFI_ERROR(Status))
  {
    return Status;
  }

  BootPerformanceTable = (UINT8 *)(UINTN)PerformanceVariable.BootPerformanceTablePointer;

  //
  // Dump PEI boot records
  //
  FirmwarePerformanceTablePtr = (BootPerformanceTable + sizeof(BOOT_PERFORMANCE_TABLE));
  GuidHob = GetFirstGuidHob(&gEdkiiFpdtExtendedFirmwarePerformanceGuid);
  while (GuidHob != NULL)
  {
    FirmwarePerformanceData = GET_GUID_HOB_DATA(GuidHob);
    PeiPerformanceLogHeader = (FPDT_PEI_EXT_PERF_HEADER *)FirmwarePerformanceData;

    CopyMem(FirmwarePerformanceTablePtr, FirmwarePerformanceData + sizeof(FPDT_PEI_EXT_PERF_HEADER), (UINTN)(PeiPerformanceLogHeader->SizeOfAllEntries));

    GuidHob = GetNextGuidHob(&gEdkiiFpdtExtendedFirmwarePerformanceGuid, GET_NEXT_HOB(GuidHob));

    FirmwarePerformanceTablePtr += (UINTN)(PeiPerformanceLogHeader->SizeOfAllEntries);
  }

  //
  // Update Table length.
  //
  ((BOOT_PERFORMANCE_TABLE *)BootPerformanceTable)->Header.Length = (UINT32)((UINTN)FirmwarePerformanceTablePtr - (UINTN)BootPerformanceTable);

  return EFI_SUCCESS;
}











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
