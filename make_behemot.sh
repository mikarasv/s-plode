#!/bin/bash
temp_file=$(mktemp /tmp/temp_XXXXXX.c)

# Change includes as needed
cat << EOF > "$temp_file"
#include "macros_behemot.h"
#include <PiPei.h>

#include <Ppi/ReportStatusCodeHandler.h>
#include <Ppi/ReadOnlyVariable2.h>

#include <Guid/FirmwarePerformance.h>
#include <Guid/Performance.h>
#include <Guid/ExtendedFirmwarePerformance.h>

#include <Base.h>
#include <Library/PeiServicesLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/TimerLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/LockBoxLib.h>
#include <Library/PcdLib.h>
#include <Library/HobLib.h>


EOF

# Change include paths as needed
clang -E -dD -I ./edk2/MdePkg/Include \
-I ./ \
-I ./edk2/MdePkg/Include/Ppi \
-I ./edk2/MdePkg/Include/Protocol \
-I ./edk2/MdePkg/Include/X64 \
-I ./edk2/MdePkg/Include/Uefi \
-I ./edk2/MdeModulePkg/Include \
-I ./edk2/MdeModulePkg/Include/Guid \
-I ./edk2/MdePkg/Include/Library \
-I ./edk2/MdePkg/Include/Uefi \
-I ./edk2/BaseTools/Source/C/Include/Common \
-I ./edk2/MdeModulePkg/Universal/DisplayEngineDxe  "$temp_file" > edk2_behemot.h

rm "$temp_file"
