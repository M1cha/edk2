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
# Cygwin GCC And Microsoft ACPI Compiler
#
####################################################################################
#   CYGGCCxASL        - CygWin GCC
#   ASL           - Microsoft ACPI Source Language Compiler (asl.exe)
*_CYGGCCxASL_*_*_FAMILY              = GCC

*_CYGGCCxASL_*_*_DLL                 = DEF(CYGWIN_BIN)
*_CYGGCCxASL_*_MAKE_PATH             = DEF(MS_VS_BIN)\nmake.exe

*_CYGGCCxASL_*_MAKE_FLAGS                 = /nologo
*_CYGGCCxASL_*_PP_FLAGS                   = -E -x assembler-with-cpp -include AutoGen.h
*_CYGGCCxASL_*_DLINK_FLAGS                = -nostdlib -O2 --gc-sections --dll --export-all-symbols --entry _$(IMAGE_ENTRY_POINT) --file-alignment 0x20 --section-alignment 0x20
*_CYGGCCxASL_*_ASM_FLAGS                  = -c -x assembler -imacros AutoGen.h
*_CYGGCCxASL_*_APP_FLAGS                  = -E -x assembler
*_CYGGCCxASL_*_VFRPP_FLAGS                = -x c -E -P -DVFRCOMPILE --include $(MODULE_NAME)StrDefs.h

##################
# ASL definitions
##################
*_CYGGCCxASL_*_ASL_PATH        = DEF(WIN_ASL_BIN)
*_CYGGCCxASL_*_ASL_FLAGS       =
*_CYGGCCxASL_*_ASL_OUTFLAGS    = DEF(MS_ASL_OUTFLAGS)
*_CYGGCCxASL_*_ASLCC_FLAGS     = DEF(MSFT_ASLCC_FLAGS)
*_CYGGCCxASL_*_ASLPP_FLAGS     = DEF(MSFT_ASLPP_FLAGS)
*_CYGGCCxASL_*_ASLDLINK_FLAGS  = DEF(MSFT_ASLDLINK_FLAGS)

##################
# IA32 definitions
##################
*_CYGGCCxASL_IA32_CC_PATH            = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_SLINK_PATH         = DEF(CYGWIN_BINIA32)ar
*_CYGGCCxASL_IA32_DLINK_PATH         = DEF(CYGWIN_BINIA32)ld
*_CYGGCCxASL_IA32_ASM_PATH           = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_PP_PATH            = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_APP_PATH           = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_VFRPP_PATH         = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_ASLCC_PATH         = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_ASLPP_PATH         = DEF(CYGWIN_BINIA32)gcc
*_CYGGCCxASL_IA32_ASLDLINK_PATH      = DEF(CYGWIN_BINIA32)ld
*_CYGGCCxASL_IA32_RC_PATH            = DEF(CYGWIN_BINIA32)objcopy

*_CYGGCCxASL_IA32_CC_FLAGS           = DEF(GCC_IA32_CC_FLAGS)
*_CYGGCCxASL_IA32_RC_FLAGS           = DEF(GCC_IA32_RC_FLAGS)

##################
# X64 definitions
##################
*_CYGGCCxASL_X64_CC_PATH             = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_SLINK_PATH          = DEF(CYGWIN_BINX64)ar
*_CYGGCCxASL_X64_DLINK_PATH          = DEF(CYGWIN_BINX64)ld
*_CYGGCCxASL_X64_ASM_PATH            = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_PP_PATH             = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_APP_PATH            = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_VFRPP_PATH          = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_ASLCC_PATH          = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_ASLPP_PATH          = DEF(CYGWIN_BINX64)gcc
*_CYGGCCxASL_X64_ASLDLINK_PATH       = DEF(CYGWIN_BINX64)ld
*_CYGGCCxASL_X64_RC_PATH             = DEF(CYGWIN_BINX64)objcopy

*_CYGGCCxASL_X64_CC_FLAGS            = DEF(GCC_X64_CC_FLAGS)
*_CYGGCCxASL_X64_RC_FLAGS            = DEF(GCC_X64_RC_FLAGS)

##################
# IPF definitions
##################
*_CYGGCCxASL_IPF_CC_PATH             = DEF(CYGWIN_BINIPF)gcc
*_CYGGCCxASL_IPF_SLINK_PATH          = DEF(CYGWIN_BINIPF)ar
*_CYGGCCxASL_IPF_DLINK_PATH          = DEF(CYGWIN_BINIPF)ld
*_CYGGCCxASL_IPF_ASLDLINK_PATH       = DEF(CYGWIN_BINIPF)ld
*_CYGGCCxASL_IPF_ASM_PATH            = DEF(CYGWIN_BINIPF)gcc
*_CYGGCCxASL_IPF_PP_PATH             = DEF(CYGWIN_BINIPF)gcc
*_CYGGCCxASL_IPF_VFRPP_PATH          = DEF(CYGWIN_BINIPF)gcc
*_CYGGCCxASL_IPF_ASLCC_PATH          = DEF(CYGWIN_BINIPF)gcc
*_CYGGCCxASL_IPF_ASLPP_PATH          = DEF(CYGWIN_BINIPF)gcc
*_CYGGCCxASL_IPF_OBJCOPY_PATH        = DEF(CYGWIN_BINIPF)objcopy
*_CYGGCCxASL_IPF_SYMRENAME_PATH      = DEF(CYGWIN_BINIPF)objcopy
*_CYGGCCxASL_IPF_RC_PATH             = DEF(CYGWIN_BINIPF)objcopy

*_CYGGCCxASL_IPF_CC_FLAGS             = DEF(GCC_IPF_CC_FLAGS)
*_CYGGCCxASL_IPF_DLINK_FLAGS          = DEF(GCC_IPF_DLINK_FLAGS)
*_CYGGCCxASL_IPF_OBJCOPY_FLAGS        = DEF(GCC_IPF_OBJCOPY_FLAGS)
*_CYGGCCxASL_IPF_SYMRENAME_FLAGS      = DEF(GCC_IPF_SYMRENAME_FLAGS)
*_CYGGCCxASL_IPF_RC_FLAGS             = DEF(GCC_IPF_RC_FLAGS)

##################
# EBC definitions
##################
*_CYGGCCxASL_EBC_*_FAMILY      = INTEL

*_CYGGCCxASL_EBC_PP_PATH       = DEF(EBC_BIN)\iec.exe
*_CYGGCCxASL_EBC_CC_PATH       = DEF(EBC_BIN)\iec.exe
*_CYGGCCxASL_EBC_DLINK_PATH    = DEF(EBC_BIN)\link.exe
*_CYGGCCxASL_EBC_SLINK_PATH    = DEF(EBC_BIN)\link.exe
*_CYGGCCxASL_EBC_VFRPP_PATH    = DEF(EBC_BIN)\iec.exe
*_CYGGCCxASL_EBC_RC_PATH       = DEF(MS_VS_BIN)\rc.exe

*_CYGGCCxASL_EBC_CC_FLAGS           = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_CYGGCCxASL_EBC_SLINK_FLAGS        = /lib /NOLOGO /MACHINE:EBC
*_CYGGCCxASL_EBC_DLINK_FLAGS        = "C:\Program Files\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /ALIGN:32 /DRIVER

