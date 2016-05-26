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
#
# Unix GCC And Intel Linux ACPI Compiler
#
####################################################################################
#   UNIXGCC         - UNIX GCC
#   ASL             - Intel Linux ACPI Source Language Compiler (iasl)
*_UNIXGCC_*_*_FAMILY               = GCC

*_UNIXGCC_*_MAKE_PATH                    = make
*_UNIXGCC_*_ASL_PATH                     = DEF(UNIX_IASL_BIN)

*_UNIXGCC_IA32_DLINK_FLAGS               = DEF(GCC_IA32_X64_DLINK_FLAGS) --image-base=0
*_UNIXGCC_X64_DLINK_FLAGS                = DEF(GCC_IA32_X64_DLINK_FLAGS) --image-base=0
*_UNIXGCC_IA32_ASLDLINK_FLAGS            = DEF(GCC_IA32_X64_ASLDLINK_FLAGS)
*_UNIXGCC_X64_ASLDLINK_FLAGS             = DEF(GCC_IA32_X64_ASLDLINK_FLAGS)
*_UNIXGCC_*_ASM_FLAGS                    = DEF(GCC_ASM_FLAGS)
*_UNIXGCC_*_PP_FLAGS                     = DEF(GCC_PP_FLAGS)
*_UNIXGCC_*_ASLPP_FLAGS                  = DEF(GCC_ASLPP_FLAGS)
*_UNIXGCC_*_ASLCC_FLAGS                  = DEF(GCC_ASLCC_FLAGS)
*_UNIXGCC_*_VFRPP_FLAGS                  = DEF(GCC_VFRPP_FLAGS)
*_UNIXGCC_*_APP_FLAGS                    =
*_UNIXGCC_*_ASL_FLAGS                    = DEF(IASL_FLAGS)
*_UNIXGCC_*_ASL_OUTFLAGS                 = DEF(IASL_OUTFLAGS)

##################
# IA32 definitions
##################
*_UNIXGCC_IA32_OBJCOPY_PATH         = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)objcopy
*_UNIXGCC_IA32_PP_PATH              = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)gcc
*_UNIXGCC_IA32_CC_PATH              = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)gcc
*_UNIXGCC_IA32_SLINK_PATH           = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)ar
*_UNIXGCC_IA32_DLINK_PATH           = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)ld
*_UNIXGCC_IA32_ASLPP_PATH           = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)gcc
*_UNIXGCC_IA32_ASLCC_PATH           = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)gcc
*_UNIXGCC_IA32_ASLDLINK_PATH        = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)ld
*_UNIXGCC_IA32_ASM_PATH             = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)gcc
*_UNIXGCC_IA32_VFRPP_PATH           = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)gcc
*_UNIXGCC_IA32_RC_PATH              = DEF(UNIXGCC_IA32_PETOOLS_PREFIX)objcopy

*_UNIXGCC_IA32_CC_FLAGS             = DEF(GCC_IA32_CC_FLAGS)
*_UNIXGCC_IA32_RC_FLAGS             = DEF(GCC_IA32_RC_FLAGS)
*_UNIXGCC_IA32_OBJCOPY_FLAGS        =
*_UNIXGCC_IA32_NASM_FLAGS           = -f win32

##################
# X64 definitions
##################
*_UNIXGCC_X64_CC_PATH               = DEF(UNIXGCC_X64_PETOOLS_PREFIX)gcc
*_UNIXGCC_X64_ASLCC_PATH            = DEF(UNIXGCC_X64_PETOOLS_PREFIX)gcc
*_UNIXGCC_X64_SLINK_PATH            = DEF(UNIXGCC_X64_PETOOLS_PREFIX)ar
*_UNIXGCC_X64_DLINK_PATH            = DEF(UNIXGCC_X64_PETOOLS_PREFIX)ld
*_UNIXGCC_X64_ASLDLINK_PATH         = DEF(UNIXGCC_X64_PETOOLS_PREFIX)ld
*_UNIXGCC_X64_ASM_PATH              = DEF(UNIXGCC_X64_PETOOLS_PREFIX)gcc
*_UNIXGCC_X64_PP_PATH               = DEF(UNIXGCC_X64_PETOOLS_PREFIX)gcc
*_UNIXGCC_X64_ASLPP_PATH            = DEF(UNIXGCC_X64_PETOOLS_PREFIX)gcc
*_UNIXGCC_X64_VFRPP_PATH            = DEF(UNIXGCC_X64_PETOOLS_PREFIX)gcc
*_UNIXGCC_X64_RC_PATH               = DEF(UNIXGCC_X64_PETOOLS_PREFIX)objcopy
*_UNIXGCC_X64_OBJCOPY_PATH          = DEF(UNIXGCC_X64_PETOOLS_PREFIX)objcopy

*_UNIXGCC_X64_CC_FLAGS              = DEF(GCC_X64_CC_FLAGS)
*_UNIXGCC_X64_RC_FLAGS              = DEF(GCC_X64_RC_FLAGS)
*_UNIXGCC_X64_OBJCOPY_FLAGS         =
*_UNIXGCC_X64_NASM_FLAGS            = -f win64

##################
# IPF definitions
##################
*_UNIXGCC_IPF_CC_PATH              = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)gcc
*_UNIXGCC_IPF_ASLCC_PATH           = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)gcc
*_UNIXGCC_IPF_SLINK_PATH           = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)ar
*_UNIXGCC_IPF_DLINK_PATH           = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)ld
*_UNIXGCC_IPF_ASLDLINK_PATH        = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)ld
*_UNIXGCC_IPF_ASM_PATH             = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)gcc
*_UNIXGCC_IPF_PP_PATH              = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)gcc
*_UNIXGCC_IPF_ASLPP_PATH           = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)gcc
*_UNIXGCC_IPF_VFRPP_PATH           = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)gcc
*_UNIXGCC_IPF_OBJCOPY_PATH         = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)objcopy
*_UNIXGCC_IPF_SYMRENAME_PATH       = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)objcopy
*_UNIXGCC_IPF_RC_PATH              = DEF(UNIXGCC_IPF_PETOOLS_PREFIX)objcopy

*_UNIXGCC_IPF_CC_FLAGS             = DEF(GCC_IPF_CC_FLAGS)
*_UNIXGCC_IPF_DLINK_FLAGS          = DEF(GCC_IPF_DLINK_FLAGS)
*_UNIXGCC_IPF_OBJCOPY_FLAGS        = DEF(GCC_IPF_OBJCOPY_FLAGS)
*_UNIXGCC_IPF_SYMRENAME_FLAGS      = DEF(GCC_IPF_SYMRENAME_FLAGS)
*_UNIXGCC_IPF_RC_FLAGS             = DEF(GCC_IPF_RC_FLAGS)

