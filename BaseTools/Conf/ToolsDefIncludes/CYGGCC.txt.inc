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
# Cygwin GCC And Intel ACPI Compiler
#
####################################################################################
#   CYGGCC        - CygWin GCC
#   ASL           - Intel ACPI Source Language Compiler (iasl.exe)
*_CYGGCC_*_*_FAMILY              = GCC

*_CYGGCC_*_*_DLL                 = DEF(CYGWIN_BIN)
*_CYGGCC_*_MAKE_PATH             = DEF(MS_VS_BIN)\nmake.exe
*_CYGGCC_*_ASL_PATH              = DEF(DEFAULT_WIN_ASL_BIN)

*_CYGGCC_IA32_DLINK_FLAGS               = DEF(GCC_IA32_X64_DLINK_FLAGS) --image-base=0
*_CYGGCC_X64_DLINK_FLAGS                = DEF(GCC_IA32_X64_DLINK_FLAGS) --image-base=0
*_CYGGCC_IA32_ASLDLINK_FLAGS            = DEF(GCC_IA32_X64_ASLDLINK_FLAGS)
*_CYGGCC_X64_ASLDLINK_FLAGS             = DEF(GCC_IA32_X64_ASLDLINK_FLAGS)
*_CYGGCC_*_MAKE_FLAGS                   = /nologo
*_CYGGCC_*_ASM_FLAGS                    = DEF(GCC_ASM_FLAGS)
*_CYGGCC_*_PP_FLAGS                     = DEF(GCC_PP_FLAGS)
*_CYGGCC_*_ASLPP_FLAGS                  = DEF(GCC_ASLPP_FLAGS)
*_CYGGCC_*_ASLCC_FLAGS                  = DEF(GCC_ASLCC_FLAGS)
*_CYGGCC_*_VFRPP_FLAGS                  = DEF(GCC_VFRPP_FLAGS)
*_CYGGCC_*_APP_FLAGS                    =
*_CYGGCC_*_ASL_FLAGS                    = DEF(DEFAULT_WIN_ASL_FLAGS)
*_CYGGCC_*_ASL_OUTFLAGS                 = DEF(DEFAULT_WIN_ASL_OUTFLAGS)

##################
# IA32 definitions
##################
*_CYGGCC_IA32_CC_PATH            = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_SLINK_PATH         = DEF(CYGWIN_BINIA32)ar
*_CYGGCC_IA32_DLINK_PATH         = DEF(CYGWIN_BINIA32)ld
*_CYGGCC_IA32_ASM_PATH           = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_PP_PATH            = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_APP_PATH           = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_VFRPP_PATH         = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_ASLCC_PATH         = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_ASLPP_PATH         = DEF(CYGWIN_BINIA32)gcc
*_CYGGCC_IA32_ASLDLINK_PATH      = DEF(CYGWIN_BINIA32)ld
*_CYGGCC_IA32_RC_PATH            = DEF(CYGWIN_BINIA32)objcopy
*_CYGGCC_IA32_OBJCOPY_PATH       = DEF(CYGWIN_BINIA32)objcopy

*_CYGGCC_IA32_CC_FLAGS           = DEF(GCC_IA32_CC_FLAGS)
*_CYGGCC_IA32_RC_FLAGS           = DEF(GCC_IA32_RC_FLAGS)
*_CYGGCC_IA32_OBJCOPY_FLAGS      =
*_CYGGCC_IA32_NASM_FLAGS         = -f win32

##################
# X64 definitions
##################
*_CYGGCC_X64_CC_PATH             = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_SLINK_PATH          = DEF(CYGWIN_BINX64)ar
*_CYGGCC_X64_DLINK_PATH          = DEF(CYGWIN_BINX64)ld
*_CYGGCC_X64_ASM_PATH            = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_PP_PATH             = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_APP_PATH            = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_VFRPP_PATH          = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_ASLCC_PATH          = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_ASLPP_PATH          = DEF(CYGWIN_BINX64)gcc
*_CYGGCC_X64_ASLDLINK_PATH       = DEF(CYGWIN_BINX64)ld
*_CYGGCC_X64_RC_PATH             = DEF(CYGWIN_BINX64)objcopy
*_CYGGCC_X64_OBJCOPY_PATH        = DEF(CYGWIN_BINX64)objcopy

*_CYGGCC_X64_CC_FLAGS            = DEF(GCC_X64_CC_FLAGS)
*_CYGGCC_X64_RC_FLAGS            = DEF(GCC_X64_RC_FLAGS)
*_CYGGCC_X64_OBJCOPY_FLAGS       =
*_CYGGCC_X64_NASM_FLAGS          = -f win64

##################
# IPF definitions
##################
*_CYGGCC_IPF_CC_PATH             = DEF(CYGWIN_BINIPF)gcc
*_CYGGCC_IPF_SLINK_PATH          = DEF(CYGWIN_BINIPF)ar
*_CYGGCC_IPF_DLINK_PATH          = DEF(CYGWIN_BINIPF)ld
*_CYGGCC_IPF_ASLDLINK_PATH       = DEF(CYGWIN_BINIPF)ld
*_CYGGCC_IPF_ASM_PATH            = DEF(CYGWIN_BINIPF)gcc
*_CYGGCC_IPF_PP_PATH             = DEF(CYGWIN_BINIPF)gcc
*_CYGGCC_IPF_VFRPP_PATH          = DEF(CYGWIN_BINIPF)gcc
*_CYGGCC_IPF_ASLCC_PATH          = DEF(CYGWIN_BINIPF)gcc
*_CYGGCC_IPF_ASLPP_PATH          = DEF(CYGWIN_BINIPF)gcc
*_CYGGCC_IPF_OBJCOPY_PATH        = DEF(CYGWIN_BINIPF)objcopy
*_CYGGCC_IPF_SYMRENAME_PATH      = DEF(CYGWIN_BINIPF)objcopy
*_CYGGCC_IPF_RC_PATH             = DEF(CYGWIN_BINIPF)objcopy

*_CYGGCC_IPF_CC_FLAGS             = DEF(GCC_IPF_CC_FLAGS)
*_CYGGCC_IPF_DLINK_FLAGS          = DEF(GCC_IPF_DLINK_FLAGS)
*_CYGGCC_IPF_OBJCOPY_FLAGS        = DEF(GCC_IPF_OBJCOPY_FLAGS)
*_CYGGCC_IPF_SYMRENAME_FLAGS      = DEF(GCC_IPF_SYMRENAME_FLAGS)
*_CYGGCC_IPF_RC_FLAGS             = DEF(GCC_IPF_RC_FLAGS)

##################
# EBC definitions
##################
*_CYGGCC_EBC_*_FAMILY      = INTEL

*_CYGGCC_EBC_PP_PATH       = DEF(EBC_BIN)\iec.exe
*_CYGGCC_EBC_CC_PATH       = DEF(EBC_BIN)\iec.exe
*_CYGGCC_EBC_DLINK_PATH    = DEF(EBC_BIN)\link.exe
*_CYGGCC_EBC_SLINK_PATH    = DEF(EBC_BIN)\link.exe
*_CYGGCC_EBC_VFRPP_PATH    = DEF(EBC_BIN)\iec.exe
*_CYGGCC_EBC_RC_PATH       = DEF(MS_VS_BIN)\rc.exe

*_CYGGCC_EBC_CC_FLAGS           = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_CYGGCC_EBC_SLINK_FLAGS        = /lib /NOLOGO /MACHINE:EBC
*_CYGGCC_EBC_DLINK_FLAGS        = "C:\Program Files\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /ALIGN:32 /DRIVER

