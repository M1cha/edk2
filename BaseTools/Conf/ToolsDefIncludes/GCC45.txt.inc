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

DEFINE GCC45_IA32_CC_FLAGS           = DEF(GCC44_IA32_CC_FLAGS)
DEFINE GCC45_X64_CC_FLAGS            = DEF(GCC44_X64_CC_FLAGS)
DEFINE GCC45_IA32_X64_DLINK_COMMON   = DEF(GCC44_IA32_X64_DLINK_COMMON)
DEFINE GCC45_IA32_X64_ASLDLINK_FLAGS = DEF(GCC44_IA32_X64_ASLDLINK_FLAGS)
DEFINE GCC45_IA32_X64_DLINK_FLAGS    = DEF(GCC44_IA32_X64_DLINK_FLAGS)
DEFINE GCC45_IA32_DLINK2_FLAGS       = DEF(GCC44_IA32_DLINK2_FLAGS)
DEFINE GCC45_X64_DLINK_FLAGS         = DEF(GCC44_X64_DLINK_FLAGS)
DEFINE GCC45_X64_DLINK2_FLAGS        = DEF(GCC44_X64_DLINK2_FLAGS)
DEFINE GCC45_ASM_FLAGS               = DEF(GCC44_ASM_FLAGS)

####################################################################################
#
# GCC 4.5 - This configuration is used to compile under Linux to produce
#           PE/COFF binaries using GCC 4.5.
#
####################################################################################
*_GCC45_*_*_FAMILY               = GCC

*_GCC45_*_MAKE_PATH                    = DEF(GCC45_IA32_PREFIX)make
*_GCC45_*_*_DLL                        = ENV(GCC45_DLL)
*_GCC45_*_ASL_PATH                     = DEF(UNIX_IASL_BIN)

*_GCC45_*_PP_FLAGS                     = DEF(GCC_PP_FLAGS)
*_GCC45_*_ASLPP_FLAGS                  = DEF(GCC_ASLPP_FLAGS)
*_GCC45_*_ASLCC_FLAGS                  = DEF(GCC_ASLCC_FLAGS)
*_GCC45_*_VFRPP_FLAGS                  = DEF(GCC_VFRPP_FLAGS)
*_GCC45_*_APP_FLAGS                    =
*_GCC45_*_ASL_FLAGS                    = DEF(IASL_FLAGS)
*_GCC45_*_ASL_OUTFLAGS                 = DEF(IASL_OUTFLAGS)

##################
# GCC45 IA32 definitions
##################
*_GCC45_IA32_OBJCOPY_PATH         = DEF(GCC45_IA32_PREFIX)objcopy
*_GCC45_IA32_CC_PATH              = DEF(GCC45_IA32_PREFIX)gcc
*_GCC45_IA32_SLINK_PATH           = DEF(GCC45_IA32_PREFIX)ar
*_GCC45_IA32_DLINK_PATH           = DEF(GCC45_IA32_PREFIX)ld
*_GCC45_IA32_ASLDLINK_PATH        = DEF(GCC45_IA32_PREFIX)ld
*_GCC45_IA32_ASM_PATH             = DEF(GCC45_IA32_PREFIX)gcc
*_GCC45_IA32_PP_PATH              = DEF(GCC45_IA32_PREFIX)gcc
*_GCC45_IA32_VFRPP_PATH           = DEF(GCC45_IA32_PREFIX)gcc
*_GCC45_IA32_ASLCC_PATH           = DEF(GCC45_IA32_PREFIX)gcc
*_GCC45_IA32_ASLPP_PATH           = DEF(GCC45_IA32_PREFIX)gcc
*_GCC45_IA32_RC_PATH              = DEF(GCC45_IA32_PREFIX)objcopy

*_GCC45_IA32_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS) -m32
*_GCC45_IA32_ASLDLINK_FLAGS       = DEF(GCC45_IA32_X64_ASLDLINK_FLAGS) -m elf_i386
*_GCC45_IA32_ASM_FLAGS            = DEF(GCC45_ASM_FLAGS) -m32 --32 -march=i386
*_GCC45_IA32_CC_FLAGS             = DEF(GCC45_IA32_CC_FLAGS) -Os
*_GCC45_IA32_DLINK_FLAGS          = DEF(GCC45_IA32_X64_DLINK_FLAGS) -m elf_i386 --oformat=elf32-i386
*_GCC45_IA32_DLINK2_FLAGS         = DEF(GCC45_IA32_DLINK2_FLAGS)
*_GCC45_IA32_RC_FLAGS             = DEF(GCC_IA32_RC_FLAGS)
*_GCC45_IA32_OBJCOPY_FLAGS        = 
*_GCC45_IA32_NASM_FLAGS           = -f elf32

##################
# GCC45 X64 definitions
##################
*_GCC45_X64_OBJCOPY_PATH         = DEF(GCC45_X64_PREFIX)objcopy
*_GCC45_X64_CC_PATH              = DEF(GCC45_X64_PREFIX)gcc
*_GCC45_X64_SLINK_PATH           = DEF(GCC45_X64_PREFIX)ar
*_GCC45_X64_DLINK_PATH           = DEF(GCC45_X64_PREFIX)ld
*_GCC45_X64_ASLDLINK_PATH        = DEF(GCC45_X64_PREFIX)ld
*_GCC45_X64_ASM_PATH             = DEF(GCC45_X64_PREFIX)gcc
*_GCC45_X64_PP_PATH              = DEF(GCC45_X64_PREFIX)gcc
*_GCC45_X64_VFRPP_PATH           = DEF(GCC45_X64_PREFIX)gcc
*_GCC45_X64_ASLCC_PATH           = DEF(GCC45_X64_PREFIX)gcc
*_GCC45_X64_ASLPP_PATH           = DEF(GCC45_X64_PREFIX)gcc
*_GCC45_X64_RC_PATH              = DEF(GCC45_X64_PREFIX)objcopy

*_GCC45_X64_ASLCC_FLAGS          = DEF(GCC_ASLCC_FLAGS) -m64
*_GCC45_X64_ASLDLINK_FLAGS       = DEF(GCC45_IA32_X64_ASLDLINK_FLAGS) -m elf_x86_64
*_GCC45_X64_ASM_FLAGS            = DEF(GCC45_ASM_FLAGS) -m64 --64 -melf_x86_64
*_GCC45_X64_CC_FLAGS             = DEF(GCC45_X64_CC_FLAGS)
*_GCC45_X64_DLINK_FLAGS          = DEF(GCC45_X64_DLINK_FLAGS)
*_GCC45_X64_DLINK2_FLAGS         = DEF(GCC45_X64_DLINK2_FLAGS)
*_GCC45_X64_RC_FLAGS             = DEF(GCC_X64_RC_FLAGS)
*_GCC45_X64_OBJCOPY_FLAGS        = 
*_GCC45_X64_NASM_FLAGS           = -f elf64

