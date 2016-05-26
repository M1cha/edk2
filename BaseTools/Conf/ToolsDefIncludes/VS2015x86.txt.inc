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
#   VS2015x86       - Microsoft Visual Studio 2015 (x86) professional with Intel ASL
#   ASL  - Intel ACPI Source Language Compiler (iasl.exe)
####################################################################################
#   VS2015x86           - Microsoft Visual Studio 2015 (x86) professional Edition with Intel ASL
*_VS2015x86_*_*_FAMILY        = MSFT

*_VS2015x86_*_MAKE_PATH       = DEF(VS2015x86_BIN)\nmake.exe
*_VS2015x86_*_MAKE_FLAG       = /nologo
*_VS2015x86_*_RC_PATH         = DEF(WINSDK81x86_BIN)\rc.exe

*_VS2015x86_*_MAKE_FLAGS      = /nologo
*_VS2015x86_*_SLINK_FLAGS     = /NOLOGO /LTCG
*_VS2015x86_*_APP_FLAGS       = /nologo /E /TC
*_VS2015x86_*_PP_FLAGS        = /nologo /E /TC /FIAutoGen.h
*_VS2015x86_*_VFRPP_FLAGS     = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h

*_VS2015x86_*_ASM16_PATH      = DEF(VS2015x86_BIN)\ml.exe

##################
# ASL definitions
##################
*_VS2015x86_*_ASL_PATH        = DEF(WIN_IASL_BIN)
*_VS2015x86_*_ASL_FLAGS       = DEF(DEFAULT_WIN_ASL_FLAGS)
*_VS2015x86_*_ASL_OUTFLAGS    = DEF(DEFAULT_WIN_ASL_OUTFLAGS)
*_VS2015x86_*_ASLCC_FLAGS     = DEF(MSFT_ASLCC_FLAGS)
*_VS2015x86_*_ASLPP_FLAGS     = DEF(MSFT_ASLPP_FLAGS)
*_VS2015x86_*_ASLDLINK_FLAGS  = DEF(MSFT_ASLDLINK_FLAGS)

##################
# IA32 definitions
##################
*_VS2015x86_IA32_*_DLL        = DEF(VS2015x86_DLL)

*_VS2015x86_IA32_MAKE_PATH    = DEF(VS2015x86_BIN)\nmake.exe
*_VS2015x86_IA32_CC_PATH      = DEF(VS2015x86_BIN)\cl.exe
*_VS2015x86_IA32_VFRPP_PATH   = DEF(VS2015x86_BIN)\cl.exe
*_VS2015x86_IA32_ASLCC_PATH   = DEF(VS2015x86_BIN)\cl.exe
*_VS2015x86_IA32_ASLPP_PATH   = DEF(VS2015x86_BIN)\cl.exe
*_VS2015x86_IA32_SLINK_PATH   = DEF(VS2015x86_BIN)\lib.exe
*_VS2015x86_IA32_DLINK_PATH   = DEF(VS2015x86_BIN)\link.exe
*_VS2015x86_IA32_ASLDLINK_PATH= DEF(VS2015x86_BIN)\link.exe
*_VS2015x86_IA32_APP_PATH     = DEF(VS2015x86_BIN)\cl.exe
*_VS2015x86_IA32_PP_PATH      = DEF(VS2015x86_BIN)\cl.exe
*_VS2015x86_IA32_ASM_PATH     = DEF(VS2015x86_BIN)\ml.exe

      *_VS2015x86_IA32_MAKE_FLAGS  = /nologo
  DEBUG_VS2015x86_IA32_CC_FLAGS    = /nologo /arch:IA32 /c /WX /GS- /W4 /Gs32768 /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /Gy /Zi /Gm
RELEASE_VS2015x86_IA32_CC_FLAGS    = /nologo /arch:IA32 /c /WX /GS- /W4 /Gs32768 /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF
NOOPT_VS2015x86_IA32_CC_FLAGS      = /nologo /arch:IA32 /c /WX /GS- /W4 /Gs32768 /D UNICODE /FIAutoGen.h /EHs-c- /GR- /GF /Gy /Zi /Gm /Od

  DEBUG_VS2015x86_IA32_ASM_FLAGS   = /nologo /c /WX /W3 /Cx /coff /Zd /Zi
RELEASE_VS2015x86_IA32_ASM_FLAGS   = /nologo /c /WX /W3 /Cx /coff /Zd
NOOPT_VS2015x86_IA32_ASM_FLAGS     = /nologo /c /WX /W3 /Cx /coff /Zd /Zi

  DEBUG_VS2015x86_IA32_NASM_FLAGS  = -Ox -f win32 -g
RELEASE_VS2015x86_IA32_NASM_FLAGS  = -Ox -f win32
NOOPT_VS2015x86_IA32_NASM_FLAGS    = -O0 -f win32 -g

  DEBUG_VS2015x86_IA32_DLINK_FLAGS = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_VS2015x86_IA32_DLINK_FLAGS = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_VS2015x86_IA32_DLINK_FLAGS   = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

##################
# X64 definitions
##################
*_VS2015x86_X64_*_DLL         = DEF(VS2015x86_DLL)

*_VS2015x86_X64_CC_PATH       = DEF(VS2015x86_BINX64)\cl.exe
*_VS2015x86_X64_PP_PATH       = DEF(VS2015x86_BINX64)\cl.exe
*_VS2015x86_X64_APP_PATH      = DEF(VS2015x86_BINX64)\cl.exe
*_VS2015x86_X64_VFRPP_PATH    = DEF(VS2015x86_BINX64)\cl.exe
*_VS2015x86_X64_ASLCC_PATH    = DEF(VS2015x86_BINX64)\cl.exe
*_VS2015x86_X64_ASLPP_PATH    = DEF(VS2015x86_BINX64)\cl.exe
*_VS2015x86_X64_ASM_PATH      = DEF(VS2015x86_BINX64)\ml64.exe
*_VS2015x86_X64_SLINK_PATH    = DEF(VS2015x86_BINX64)\lib.exe
*_VS2015x86_X64_DLINK_PATH    = DEF(VS2015x86_BINX64)\link.exe
*_VS2015x86_X64_ASLDLINK_PATH = DEF(VS2015x86_BINX64)\link.exe

  DEBUG_VS2015x86_X64_CC_FLAGS     = /nologo /c /WX /GS- /W4 /Gs32768 /D UNICODE /O1b2s /GL /Gy /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm
RELEASE_VS2015x86_X64_CC_FLAGS     = /nologo /c /WX /GS- /W4 /Gs32768 /D UNICODE /O1b2s /GL /Gy /FIAutoGen.h /EHs-c- /GR- /GF
NOOPT_VS2015x86_X64_CC_FLAGS       = /nologo /c /WX /GS- /W4 /Gs32768 /D UNICODE /Gy /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm /Od

  DEBUG_VS2015x86_X64_ASM_FLAGS    = /nologo /c /WX /W3 /Cx /Zd /Zi
RELEASE_VS2015x86_X64_ASM_FLAGS    = /nologo /c /WX /W3 /Cx /Zd
NOOPT_VS2015x86_X64_ASM_FLAGS      = /nologo /c /WX /W3 /Cx /Zd /Zi

  DEBUG_VS2015x86_X64_NASM_FLAGS   = -Ox -f win64 -g
RELEASE_VS2015x86_X64_NASM_FLAGS   = -Ox -f win64
NOOPT_VS2015x86_X64_NASM_FLAGS     = -O0 -f win64 -g

  DEBUG_VS2015x86_X64_DLINK_FLAGS  = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_VS2015x86_X64_DLINK_FLAGS  = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_VS2015x86_X64_DLINK_FLAGS    = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

##################
# EBC definitions
##################
*_VS2015x86_EBC_*_FAMILY            = INTEL
*_VS2015x86_EBC_*_DLL               = DEF(VS2015x86_DLL)

*_VS2015x86_EBC_MAKE_PATH           = DEF(VS2015x86_BIN)\nmake.exe
*_VS2015x86_EBC_PP_PATH             = DEF(EBC_BINx86)\iec.exe
*_VS2015x86_EBC_VFRPP_PATH          = DEF(EBC_BINx86)\iec.exe
*_VS2015x86_EBC_CC_PATH             = DEF(EBC_BINx86)\iec.exe
*_VS2015x86_EBC_SLINK_PATH          = DEF(VS2015x86_BIN)\link.exe
*_VS2015x86_EBC_DLINK_PATH          = DEF(VS2015x86_BIN)\link.exe

*_VS2015x86_EBC_MAKE_FLAGS          = /nologo
*_VS2015x86_EBC_PP_FLAGS            = /nologo /E /TC /FIAutoGen.h
*_VS2015x86_EBC_CC_FLAGS            = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_VS2015x86_EBC_VFRPP_FLAGS         = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_VS2015x86_EBC_SLINK_FLAGS         = /lib /NOLOGO /MACHINE:EBC
*_VS2015x86_EBC_DLINK_FLAGS         = "C:\Program Files (x86)\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /MAP /ALIGN:32 /DRIVER

