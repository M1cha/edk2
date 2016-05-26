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

DEFINE GCC46_IA32_CC_FLAGS           = DEF(GCC45_IA32_CC_FLAGS) -Wno-address
DEFINE GCC46_X64_CC_FLAGS            = DEF(GCC45_X64_CC_FLAGS) -Wno-address
DEFINE GCC46_IA32_X64_DLINK_COMMON   = DEF(GCC45_IA32_X64_DLINK_COMMON)
DEFINE GCC46_IA32_X64_ASLDLINK_FLAGS = DEF(GCC45_IA32_X64_ASLDLINK_FLAGS)
DEFINE GCC46_IA32_X64_DLINK_FLAGS    = DEF(GCC45_IA32_X64_DLINK_FLAGS)
DEFINE GCC46_IA32_DLINK2_FLAGS       = DEF(GCC45_IA32_DLINK2_FLAGS)
DEFINE GCC46_X64_DLINK_FLAGS         = DEF(GCC45_X64_DLINK_FLAGS)
DEFINE GCC46_X64_DLINK2_FLAGS        = DEF(GCC45_X64_DLINK2_FLAGS)
DEFINE GCC46_ASM_FLAGS               = DEF(GCC45_ASM_FLAGS)
DEFINE GCC46_ARM_ASM_FLAGS           = $(ARCHASM_FLAGS) $(PLATFORM_FLAGS) DEF(GCC_ASM_FLAGS) -mlittle-endian
DEFINE GCC46_ARM_CC_FLAGS            = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) DEF(GCC44_ALL_CC_FLAGS) DEF(GCC_ARM_CC_FLAGS) -fstack-protector -mword-relocations
DEFINE GCC46_ARM_DLINK_FLAGS         = DEF(GCC_ARM_DLINK_FLAGS) --oformat=elf32-littlearm
DEFINE GCC46_ARM_DLINK2_FLAGS        = DEF(GCC_DLINK2_FLAGS_COMMON) --defsym=PECOFF_HEADER_SIZE=0x220
DEFINE GCC46_ARM_ASLDLINK_FLAGS      = DEF(GCC_ARM_ASLDLINK_FLAGS) --oformat=elf32-littlearm

####################################################################################
#
# GCC 4.6 - This configuration is used to compile under Linux to produce
#           PE/COFF binaries using GCC 4.6.
#
####################################################################################
*_GCC46_*_*_FAMILY               = GCC

*_GCC46_*_MAKE_PATH                    = DEF(GCC46_IA32_PREFIX)make
*_GCC46_*_*_DLL                        = ENV(GCC46_DLL)
*_GCC46_*_ASL_PATH                     = DEF(UNIX_IASL_BIN)

*_GCC46_*_PP_FLAGS                     = DEF(GCC_PP_FLAGS)
*_GCC46_*_ASLPP_FLAGS                  = DEF(GCC_ASLPP_FLAGS)
*_GCC46_*_ASLCC_FLAGS                  = DEF(GCC_ASLCC_FLAGS)
*_GCC46_*_VFRPP_FLAGS                  = DEF(GCC_VFRPP_FLAGS)
*_GCC46_*_APP_FLAGS                    =
*_GCC46_*_ASL_FLAGS                    = DEF(IASL_FLAGS)
*_GCC46_*_ASL_OUTFLAGS                 = DEF(IASL_OUTFLAGS)

##################
# GCC46 IA32 definitions
##################
*_GCC46_IA32_OBJCOPY_PATH         = DEF(GCC46_IA32_PREFIX)objcopy
*_GCC46_IA32_CC_PATH              = DEF(GCC46_IA32_PREFIX)gcc
*_GCC46_IA32_SLINK_PATH           = DEF(GCC46_IA32_PREFIX)ar
*_GCC46_IA32_DLINK_PATH           = DEF(GCC46_IA32_PREFIX)ld
*_GCC46_IA32_ASLDLINK_PATH        = DEF(GCC46_IA32_PREFIX)ld
*_GCC46_IA32_ASM_PATH             = DEF(GCC46_IA32_PREFIX)gcc
*_GCC46_IA32_PP_PATH              = DEF(GCC46_IA32_PREFIX)gcc
*_GCC46_IA32_VFRPP_PATH           = DEF(GCC46_IA32_PREFIX)gcc
*_GCC46_IA32_ASLCC_PATH           = DEF(GCC46_IA32_PREFIX)gcc
*_GCC46_IA32_ASLPP_PATH           = DEF(GCC46_IA32_PREFIX)gcc
*_GCC46_IA32_RC_PATH              = DEF(GCC46_IA32_PREFIX)objcopy

*_GCC46_IA32_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS) -m32
*_GCC46_IA32_ASLDLINK_FLAGS       = DEF(GCC46_IA32_X64_ASLDLINK_FLAGS) -m elf_i386
*_GCC46_IA32_ASM_FLAGS            = DEF(GCC46_ASM_FLAGS) -m32 -march=i386
*_GCC46_IA32_DLINK_FLAGS          = DEF(GCC46_IA32_X64_DLINK_FLAGS) -m elf_i386 --oformat=elf32-i386
*_GCC46_IA32_DLINK2_FLAGS         = DEF(GCC46_IA32_DLINK2_FLAGS)
*_GCC46_IA32_RC_FLAGS             = DEF(GCC_IA32_RC_FLAGS)
*_GCC46_IA32_OBJCOPY_FLAGS        = 
*_GCC46_IA32_NASM_FLAGS           = -f elf32

  DEBUG_GCC46_IA32_CC_FLAGS       = DEF(GCC46_IA32_CC_FLAGS) -Os
RELEASE_GCC46_IA32_CC_FLAGS       = DEF(GCC46_IA32_CC_FLAGS) -Os -Wno-unused-but-set-variable

##################
# GCC46 X64 definitions
##################
*_GCC46_X64_OBJCOPY_PATH         = DEF(GCC46_X64_PREFIX)objcopy
*_GCC46_X64_CC_PATH              = DEF(GCC46_X64_PREFIX)gcc
*_GCC46_X64_SLINK_PATH           = DEF(GCC46_X64_PREFIX)ar
*_GCC46_X64_DLINK_PATH           = DEF(GCC46_X64_PREFIX)ld
*_GCC46_X64_ASLDLINK_PATH        = DEF(GCC46_X64_PREFIX)ld
*_GCC46_X64_ASM_PATH             = DEF(GCC46_X64_PREFIX)gcc
*_GCC46_X64_PP_PATH              = DEF(GCC46_X64_PREFIX)gcc
*_GCC46_X64_VFRPP_PATH           = DEF(GCC46_X64_PREFIX)gcc
*_GCC46_X64_ASLCC_PATH           = DEF(GCC46_X64_PREFIX)gcc
*_GCC46_X64_ASLPP_PATH           = DEF(GCC46_X64_PREFIX)gcc
*_GCC46_X64_RC_PATH              = DEF(GCC46_X64_PREFIX)objcopy

*_GCC46_X64_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS) -m64
*_GCC46_X64_ASLDLINK_FLAGS       = DEF(GCC46_IA32_X64_ASLDLINK_FLAGS) -m elf_x86_64
*_GCC46_X64_ASM_FLAGS            = DEF(GCC46_ASM_FLAGS) -m64 -melf_x86_64
*_GCC46_X64_DLINK_FLAGS          = DEF(GCC46_X64_DLINK_FLAGS)
*_GCC46_X64_DLINK2_FLAGS         = DEF(GCC46_X64_DLINK2_FLAGS)
*_GCC46_X64_RC_FLAGS             = DEF(GCC_X64_RC_FLAGS)
*_GCC46_X64_OBJCOPY_FLAGS        = 
*_GCC46_X64_NASM_FLAGS           = -f elf64

  DEBUG_GCC46_X64_CC_FLAGS       = DEF(GCC46_X64_CC_FLAGS)
RELEASE_GCC46_X64_CC_FLAGS       = DEF(GCC46_X64_CC_FLAGS) -Wno-unused-but-set-variable

##################
# GCC46 ARM definitions
##################
*_GCC46_ARM_OBJCOPY_PATH         = echo
*_GCC46_ARM_CC_PATH              = ENV(GCC46_ARM_PREFIX)gcc
*_GCC46_ARM_SLINK_PATH           = ENV(GCC46_ARM_PREFIX)ar
*_GCC46_ARM_DLINK_PATH           = ENV(GCC46_ARM_PREFIX)ld
*_GCC46_ARM_ASLDLINK_PATH        = ENV(GCC46_ARM_PREFIX)ld
*_GCC46_ARM_ASM_PATH             = ENV(GCC46_ARM_PREFIX)gcc
*_GCC46_ARM_PP_PATH              = ENV(GCC46_ARM_PREFIX)gcc
*_GCC46_ARM_VFRPP_PATH           = ENV(GCC46_ARM_PREFIX)gcc
*_GCC46_ARM_ASLCC_PATH           = ENV(GCC46_ARM_PREFIX)gcc
*_GCC46_ARM_ASLPP_PATH           = ENV(GCC46_ARM_PREFIX)gcc
*_GCC46_ARM_RC_PATH              = ENV(GCC46_ARM_PREFIX)objcopy

*_GCC46_ARM_ARCHCC_FLAGS         =
*_GCC46_ARM_PLATFORM_FLAGS       = -march=armv7-a

*_GCC46_ARM_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS)
*_GCC46_ARM_ASLDLINK_FLAGS       = DEF(GCC46_ARM_ASLDLINK_FLAGS)
*_GCC46_ARM_ASM_FLAGS            = DEF(GCC46_ARM_ASM_FLAGS)
*_GCC46_ARM_DLINK_FLAGS          = DEF(GCC46_ARM_DLINK_FLAGS)
*_GCC46_ARM_DLINK2_FLAGS         = DEF(GCC46_ARM_DLINK2_FLAGS)
*_GCC46_ARM_PLATFORM_FLAGS       = -march=armv7-a
*_GCC46_ARM_PP_FLAGS             = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) DEF(GCC_PP_FLAGS)
*_GCC46_ARM_RC_FLAGS             = DEF(GCC_ARM_RC_FLAGS)
*_GCC46_ARM_VFRPP_FLAGS          = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) DEF(GCC_VFRPP_FLAGS)

  DEBUG_GCC46_ARM_CC_FLAGS       = DEF(GCC46_ARM_CC_FLAGS) -D__ARM_FEATURE_UNALIGNED=0 -O0
RELEASE_GCC46_ARM_CC_FLAGS       = DEF(GCC46_ARM_CC_FLAGS) -D__ARM_FEATURE_UNALIGNED=0 -Wno-unused-but-set-variable

