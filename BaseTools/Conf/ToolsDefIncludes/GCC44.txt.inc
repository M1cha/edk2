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

DEFINE GCC44_ALL_CC_FLAGS            = -g -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-array-bounds -ffunction-sections -fdata-sections -c -include AutoGen.h -fno-common -DSTRING_ARRAY_NAME=$(BASE_NAME)Strings
DEFINE GCC44_IA32_CC_FLAGS           = DEF(GCC44_ALL_CC_FLAGS) -m32 -march=i586 -malign-double -fno-stack-protector -D EFI32 -fno-asynchronous-unwind-tables
DEFINE GCC44_X64_CC_FLAGS            = DEF(GCC44_ALL_CC_FLAGS) -m64 -fno-stack-protector "-DEFIAPI=__attribute__((ms_abi))" -DNO_BUILTIN_VA_FUNCS -mno-red-zone -Wno-address -mcmodel=large -fno-asynchronous-unwind-tables
DEFINE GCC44_IA32_X64_DLINK_COMMON   = -nostdlib -n -q --gc-sections -z common-page-size=0x20
DEFINE GCC44_IA32_X64_ASLDLINK_FLAGS = DEF(GCC44_IA32_X64_DLINK_COMMON) --entry ReferenceAcpiTable -u ReferenceAcpiTable
DEFINE GCC44_IA32_X64_DLINK_FLAGS    = DEF(GCC44_IA32_X64_DLINK_COMMON) --entry $(IMAGE_ENTRY_POINT) -u $(IMAGE_ENTRY_POINT) -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
DEFINE GCC44_IA32_DLINK2_FLAGS       = --defsym=PECOFF_HEADER_SIZE=0x220 DEF(GCC_DLINK2_FLAGS_COMMON)
DEFINE GCC44_X64_DLINK_FLAGS         = DEF(GCC44_IA32_X64_DLINK_FLAGS)  -melf_x86_64 --oformat=elf64-x86-64
DEFINE GCC44_X64_DLINK2_FLAGS        = --defsym=PECOFF_HEADER_SIZE=0x228 DEF(GCC_DLINK2_FLAGS_COMMON)
DEFINE GCC44_ASM_FLAGS               = DEF(GCC_ASM_FLAGS)

####################################################################################
#
# GCC 4.4 - This configuration is used to compile under Linux to produce
#           PE/COFF binaries using GCC 4.4.
#
####################################################################################
*_GCC44_*_*_FAMILY               = GCC

*_GCC44_*_MAKE_PATH                    = DEF(GCC44_IA32_PREFIX)make
*_GCC44_*_*_DLL                        = ENV(GCC44_DLL)
*_GCC44_*_ASL_PATH                     = DEF(UNIX_IASL_BIN)

*_GCC44_*_PP_FLAGS                     = DEF(GCC_PP_FLAGS)
*_GCC44_*_ASLPP_FLAGS                  = DEF(GCC_ASLPP_FLAGS)
*_GCC44_*_ASLCC_FLAGS                  = DEF(GCC_ASLCC_FLAGS)
*_GCC44_*_VFRPP_FLAGS                  = DEF(GCC_VFRPP_FLAGS)
*_GCC44_*_APP_FLAGS                    = DEF(GCC_PP_FLAGS)
*_GCC44_*_ASL_FLAGS                    = DEF(IASL_FLAGS)
*_GCC44_*_ASL_OUTFLAGS                 = DEF(IASL_OUTFLAGS)

##################
# GCC44 IA32 definitions
##################
*_GCC44_IA32_OBJCOPY_PATH         = DEF(GCC44_IA32_PREFIX)objcopy
*_GCC44_IA32_CC_PATH              = DEF(GCC44_IA32_PREFIX)gcc
*_GCC44_IA32_SLINK_PATH           = DEF(GCC44_IA32_PREFIX)ar
*_GCC44_IA32_DLINK_PATH           = DEF(GCC44_IA32_PREFIX)ld
*_GCC44_IA32_ASLDLINK_PATH        = DEF(GCC44_IA32_PREFIX)ld
*_GCC44_IA32_ASM_PATH             = DEF(GCC44_IA32_PREFIX)gcc
*_GCC44_IA32_PP_PATH              = DEF(GCC44_IA32_PREFIX)gcc
*_GCC44_IA32_VFRPP_PATH           = DEF(GCC44_IA32_PREFIX)gcc
*_GCC44_IA32_ASLCC_PATH           = DEF(GCC44_IA32_PREFIX)gcc
*_GCC44_IA32_ASLPP_PATH           = DEF(GCC44_IA32_PREFIX)gcc
*_GCC44_IA32_RC_PATH              = DEF(GCC44_IA32_PREFIX)objcopy

*_GCC44_IA32_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS) -m32
*_GCC44_IA32_ASLDLINK_FLAGS       = DEF(GCC44_IA32_X64_ASLDLINK_FLAGS) -m elf_i386
*_GCC44_IA32_ASM_FLAGS            = DEF(GCC44_ASM_FLAGS) -m32 --32 -march=i386
*_GCC44_IA32_CC_FLAGS             = DEF(GCC44_IA32_CC_FLAGS) -Os
*_GCC44_IA32_DLINK_FLAGS          = DEF(GCC44_IA32_X64_DLINK_FLAGS) -m elf_i386 --oformat=elf32-i386
*_GCC44_IA32_DLINK2_FLAGS         = DEF(GCC44_IA32_DLINK2_FLAGS)
*_GCC44_IA32_RC_FLAGS             = DEF(GCC_IA32_RC_FLAGS)
*_GCC44_IA32_OBJCOPY_FLAGS        = 
*_GCC44_IA32_NASM_FLAGS           = -f elf32

##################
# GCC44 X64 definitions
##################
*_GCC44_X64_OBJCOPY_PATH         = DEF(GCC44_X64_PREFIX)objcopy
*_GCC44_X64_CC_PATH              = DEF(GCC44_X64_PREFIX)gcc
*_GCC44_X64_SLINK_PATH           = DEF(GCC44_X64_PREFIX)ar
*_GCC44_X64_DLINK_PATH           = DEF(GCC44_X64_PREFIX)ld
*_GCC44_X64_ASLDLINK_PATH        = DEF(GCC44_X64_PREFIX)ld
*_GCC44_X64_ASM_PATH             = DEF(GCC44_X64_PREFIX)gcc
*_GCC44_X64_PP_PATH              = DEF(GCC44_X64_PREFIX)gcc
*_GCC44_X64_VFRPP_PATH           = DEF(GCC44_X64_PREFIX)gcc
*_GCC44_X64_ASLCC_PATH           = DEF(GCC44_X64_PREFIX)gcc
*_GCC44_X64_ASLPP_PATH           = DEF(GCC44_X64_PREFIX)gcc
*_GCC44_X64_RC_PATH              = DEF(GCC44_X64_PREFIX)objcopy

*_GCC44_X64_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS) -m64
*_GCC44_X64_ASLDLINK_FLAGS       = DEF(GCC44_IA32_X64_ASLDLINK_FLAGS) -m elf_x86_64
*_GCC44_X64_ASM_FLAGS            = DEF(GCC44_ASM_FLAGS) -m64 --64 -melf_x86_64
*_GCC44_X64_CC_FLAGS             = DEF(GCC44_X64_CC_FLAGS)
*_GCC44_X64_DLINK_FLAGS          = DEF(GCC44_X64_DLINK_FLAGS)
*_GCC44_X64_DLINK2_FLAGS         = DEF(GCC44_X64_DLINK2_FLAGS)
*_GCC44_X64_RC_FLAGS             = DEF(GCC_X64_RC_FLAGS)
*_GCC44_X64_OBJCOPY_FLAGS        = 
*_GCC44_X64_NASM_FLAGS           = -f elf64

