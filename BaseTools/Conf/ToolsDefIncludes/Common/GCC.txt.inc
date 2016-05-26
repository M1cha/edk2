#
#  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>
#  Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>
#  Portions copyright (c) 2011 - 2014, ARM Ltd. All rights reserved.<BR>
#  Copyright (c) 2015, Hewlett-Packard Development Company, L.P.<BR>
#  (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>
#
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#

####################################################################################
# GCC Common
####################################################################################

*_*_*_OBJCOPY_PATH              = echo
*_*_*_OBJCOPY_FLAGS             = objcopy not needed for
*_*_*_SYMRENAME_PATH            = echo
*_*_*_SYMRENAME_FLAGS           = Symbol renaming not needed for
DEBUG_*_*_OBJCOPY_ADDDEBUGFLAG     = --add-gnu-debuglink=$(DEBUG_DIR)/$(MODULE_NAME).debug
RELEASE_*_*_OBJCOPY_ADDDEBUGFLAG   =

DEFINE GCC_ALL_CC_FLAGS            = -g -Os -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-array-bounds -c -include AutoGen.h -fno-common
DEFINE GCC_IA32_CC_FLAGS           = DEF(GCC_ALL_CC_FLAGS) -m32 -malign-double -freorder-blocks -freorder-blocks-and-partition -O2 -mno-stack-arg-probe
DEFINE GCC_X64_CC_FLAGS            = DEF(GCC_ALL_CC_FLAGS) -mno-red-zone -Wno-address -mno-stack-arg-probe
DEFINE GCC_IPF_CC_FLAGS            = DEF(GCC_ALL_CC_FLAGS) -minline-int-divide-min-latency
DEFINE GCC_ARM_CC_FLAGS            = DEF(GCC_ALL_CC_FLAGS) -mlittle-endian -mabi=aapcs -fno-short-enums -save-temps -funsigned-char -ffunction-sections -fdata-sections -fomit-frame-pointer -Wno-address -mthumb -mfloat-abi=soft
DEFINE GCC_AARCH64_CC_FLAGS        = DEF(GCC_ALL_CC_FLAGS) -mlittle-endian -fno-short-enums -save-temps -fverbose-asm -funsigned-char  -ffunction-sections -fdata-sections -fomit-frame-pointer -fno-builtin -Wno-address -fno-asynchronous-unwind-tables
DEFINE GCC_AARCH64_CC_XIPFLAGS     = -mstrict-align
DEFINE GCC_DLINK_FLAGS_COMMON      = -nostdlib --pie
DEFINE GCC_DLINK2_FLAGS_COMMON     = --script=$(EDK_TOOLS_PATH)/Scripts/GccBase.lds
DEFINE GCC_IA32_X64_DLINK_COMMON   = DEF(GCC_DLINK_FLAGS_COMMON) --gc-sections
DEFINE GCC_ARM_AARCH64_DLINK_COMMON= --emit-relocs -nostdlib --gc-sections -u $(IMAGE_ENTRY_POINT) -e $(IMAGE_ENTRY_POINT) -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
DEFINE GCC_ARM_DLINK_FLAGS         = DEF(GCC_ARM_AARCH64_DLINK_COMMON) -z common-page-size=0x20
DEFINE GCC_AARCH64_DLINK_FLAGS     = DEF(GCC_ARM_AARCH64_DLINK_COMMON) -z common-page-size=0x20
DEFINE GCC_IA32_X64_ASLDLINK_FLAGS = DEF(GCC_IA32_X64_DLINK_COMMON) --entry _ReferenceAcpiTable -u $(IMAGE_ENTRY_POINT)
DEFINE GCC_ARM_ASLDLINK_FLAGS      = DEF(GCC_ARM_DLINK_FLAGS) --entry ReferenceAcpiTable -u $(IMAGE_ENTRY_POINT)
DEFINE GCC_AARCH64_ASLDLINK_FLAGS  = DEF(GCC_AARCH64_DLINK_FLAGS) --entry ReferenceAcpiTable -u $(IMAGE_ENTRY_POINT)
DEFINE GCC_IA32_X64_DLINK_FLAGS    = DEF(GCC_IA32_X64_DLINK_COMMON) --entry _$(IMAGE_ENTRY_POINT) --file-alignment 0x20 --section-alignment 0x20 -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
DEFINE GCC_IPF_DLINK_FLAGS         = -nostdlib -O2 --gc-sections --dll -static --entry $(IMAGE_ENTRY_POINT) --undefined $(IMAGE_ENTRY_POINT) -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
DEFINE GCC_IPF_OBJCOPY_FLAGS       = -I elf64-ia64-little -O efi-bsdrv-ia64
DEFINE GCC_IPF_SYMRENAME_FLAGS     = --redefine-sym memcpy=CopyMem
DEFINE GCC_ASM_FLAGS               = -c -x assembler -imacros $(DEST_DIR_DEBUG)/AutoGen.h
DEFINE GCC_PP_FLAGS                = -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
DEFINE GCC_VFRPP_FLAGS             = -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h
DEFINE GCC_ASLPP_FLAGS             = -x c -E -P
DEFINE GCC_ASLCC_FLAGS             = -x c
DEFINE GCC_WINDRES_FLAGS           = -J rc -O coff
DEFINE GCC_IA32_RC_FLAGS           = -I binary -O elf32-i386          -B i386    --rename-section .data=.hii
DEFINE GCC_X64_RC_FLAGS            = -I binary -O elf64-x86-64        -B i386    --rename-section .data=.hii
DEFINE GCC_IPF_RC_FLAGS            = -I binary -O elf64-ia64-little   -B ia64    --rename-section .data=.hii
DEFINE GCC_ARM_RC_FLAGS            = -I binary -O elf32-littlearm     -B arm     --rename-section .data=.hii
DEFINE GCC_AARCH64_RC_FLAGS        = -I binary -O elf64-littleaarch64 -B aarch64 --rename-section .data=.hii

