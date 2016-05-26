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
# Microsoft Visual Studio .NET 2003 (IA-32 only, with Link Time Code Generation)
# And Intel ACPI Compiler
#
####################################################################################
#   VS2003           - Microsoft Visual Studio .NET 2003 and Intel ACPI Source Language Compiler (iasl.exe)
*_VS2003_*_*_FAMILY                 = MSFT

##################
# ASL definitions
##################
*_VS2003_*_ASL_PATH                 = DEF(DEFAULT_WIN_ASL_BIN)
*_VS2003_*_ASL_FLAGS                = DEF(DEFAULT_WIN_ASL_FLAGS)
*_VS2003_*_ASL_OUTFLAGS             = DEF(DEFAULT_WIN_ASL_OUTFLAGS)
*_VS2003_*_ASLCC_FLAGS              = DEF(MSFT_ASLCC_FLAGS)
*_VS2003_*_ASLPP_FLAGS              = DEF(MSFT_ASLPP_FLAGS)
*_VS2003_*_ASLDLINK_FLAGS           = DEF(MSFT_ASLDLINK_FLAGS)

##################
# IA32 definitions
##################
*_VS2003_IA32_*_DLL                 = DEF(VS2003_DLL)

*_VS2003_IA32_MAKE_PATH             = DEF(VS2003_BIN)\nmake.exe
*_VS2003_IA32_CC_PATH               = DEF(VS2003_BIN)\cl.exe
*_VS2003_IA32_VFRPP_PATH            = DEF(VS2003_BIN)\cl.exe
*_VS2003_IA32_SLINK_PATH            = DEF(VS2003_BIN)\lib.exe
*_VS2003_IA32_DLINK_PATH            = DEF(VS2003_BIN)\link.exe
*_VS2003_IA32_APP_PATH              = DEF(VS2003_BIN)\cl.exe
*_VS2003_IA32_PP_PATH               = DEF(VS2003_BIN)\cl.exe
*_VS2003_IA32_ASM_PATH              = DEF(VS2003_BIN)\ml.exe
*_VS2003_IA32_ASM16_PATH            = DEF(VS2003_BIN)\ml.exe
*_VS2003_IA32_ASLCC_PATH            = DEF(VS2003_BIN)\cl.exe
*_VS2003_IA32_ASLPP_PATH            = DEF(VS2003_BIN)\cl.exe
*_VS2003_IA32_ASLDLINK_PATH         = DEF(VS2003_BIN)\link.exe
*_VS2003_IA32_RC_PATH               = DEF(VS2003_BIN)\rc.exe

      *_VS2003_IA32_MAKE_FLAGS      = /nologo
      *_VS2003_IA32_APP_FLAGS       = /nologo /E /TC
      *_VS2003_IA32_PP_FLAGS        = /nologo /E /TC /FIAutoGen.h
      *_VS2003_IA32_VFRPP_FLAGS     = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
  DEBUG_VS2003_IA32_CC_FLAGS        = /nologo /c /WX /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /GX- /Zi /Gm
RELEASE_VS2003_IA32_CC_FLAGS        = /nologo /c /WX /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /GX-
NOOPT_VS2003_IA32_CC_FLAGS          = /nologo /c /WX /W4 /Gs32768 /Gy /D UNICODE /FIAutoGen.h /EHs-c- /GR- /GF /GX- /Zi /Gm /Od

  DEBUG_VS2003_IA32_ASM_FLAGS       = /nologo /c /WX /W3 /coff /Cx /Zd /Zi
RELEASE_VS2003_IA32_ASM_FLAGS       = /nologo /c /WX /W3 /coff /Cx /Zd
NOOPT_VS2003_IA32_ASM_FLAGS         = /nologo /c /WX /W3 /coff /Cx /Zd /Zi

  DEBUG_VS2003_IA32_NASM_FLAGS      = -Ox -f win32 -g
RELEASE_VS2003_IA32_NASM_FLAGS      = -Ox -f win32
NOOPT_VS2003_IA32_NASM_FLAGS        = -O0 -f win32 -g

      *_VS2003_IA32_SLINK_FLAGS     = /nologo /LTCG
  DEBUG_VS2003_IA32_DLINK_FLAGS     = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_VS2003_IA32_DLINK_FLAGS     = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4078 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_VS2003_IA32_DLINK_FLAGS       = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

##################
# EBC definitions
##################
*_VS2003_EBC_*_FAMILY               = INTEL

*_VS2003_EBC_MAKE_PATH              = DEF(VS2003_BIN)\nmake.exe
*_VS2003_EBC_PP_PATH                = DEF(EBC_BIN)\iec.exe
*_VS2003_EBC_VFRPP_PATH             = DEF(EBC_BIN)\iec.exe
*_VS2003_EBC_CC_PATH                = DEF(EBC_BIN)\iec.exe
*_VS2003_EBC_SLINK_PATH             = DEF(EBC_BIN)\link.exe
*_VS2003_EBC_DLINK_PATH             = DEF(EBC_BIN)\link.exe
*_VS2003_EBC_RC_PATH                = DEF(VS2003_BIN)\rc.exe

*_VS2003_EBC_MAKE_FLAGS             = /nologo
*_VS2003_EBC_PP_FLAGS               = /nologo /E /TC /FIAutoGen.h
*_VS2003_EBC_CC_FLAGS               = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_VS2003_EBC_VFRPP_FLAGS            = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_VS2003_EBC_SLINK_FLAGS            = /lib /NOLOGO /MACHINE:EBC
*_VS2003_EBC_DLINK_FLAGS            = "C:\Program Files\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /MAP /ALIGN:32 /DRIVER

####################################################################################
#
#   Microsoft Visual Studio .NET 2003 and Microsoft ACPI compiler
#
####################################################################################
#   VS2003xASL           - Microsoft Visual Studio .NET 2003 and Microsoft ACPI Source Language Compiler (asl.exe)
*_VS2003xASL_*_*_FAMILY                 = MSFT

##################
# ASL definitions
##################
*_VS2003xASL_*_ASL_PATH                 = DEF(WIN_ASL_BIN)
*_VS2003xASL_*_ASL_FLAGS                =
*_VS2003xASL_*_ASL_OUTFLAGS             = DEF(MS_ASL_OUTFLAGS)
*_VS2003xASL_*_ASLCC_FLAGS              = DEF(MSFT_ASLCC_FLAGS)
*_VS2003xASL_*_ASLPP_FLAGS              = DEF(MSFT_ASLPP_FLAGS)
*_VS2003xASL_*_ASLDLINK_FLAGS           = DEF(MSFT_ASLDLINK_FLAGS)

##################
# IA32 definitions
##################
*_VS2003xASL_IA32_*_DLL                 = DEF(VS2003_DLL)

*_VS2003xASL_IA32_MAKE_PATH             = DEF(VS2003_BIN)\nmake.exe
*_VS2003xASL_IA32_CC_PATH               = DEF(VS2003_BIN)\cl.exe
*_VS2003xASL_IA32_VFRPP_PATH            = DEF(VS2003_BIN)\cl.exe
*_VS2003xASL_IA32_SLINK_PATH            = DEF(VS2003_BIN)\lib.exe
*_VS2003xASL_IA32_DLINK_PATH            = DEF(VS2003_BIN)\link.exe
*_VS2003xASL_IA32_APP_PATH              = DEF(VS2003_BIN)\cl.exe
*_VS2003xASL_IA32_PP_PATH               = DEF(VS2003_BIN)\cl.exe
*_VS2003xASL_IA32_ASM_PATH              = DEF(VS2003_BIN)\ml.exe
*_VS2003xASL_IA32_ASLCC_PATH            = DEF(VS2003_BIN)\cl.exe
*_VS2003xASL_IA32_ASLPP_PATH            = DEF(VS2003_BIN)\cl.exe
*_VS2003xASL_IA32_ASLDLINK_PATH         = DEF(VS2003_BIN)\link.exe
*_VS2003xASL_IA32_RC_PATH               = DEF(VS2003_BIN)\rc.exe


      *_VS2003xASL_IA32_MAKE_FLAGS      = /nologo
      *_VS2003xASL_IA32_APP_FLAGS       = /nologo /E /TC
      *_VS2003xASL_IA32_PP_FLAGS        = /nologo /E /TC /FIAutoGen.h
      *_VS2003xASL_IA32_VFRPP_FLAGS     = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
  DEBUG_VS2003xASL_IA32_CC_FLAGS        = /nologo /c /WX /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /GX- /Zi /Gm
RELEASE_VS2003xASL_IA32_CC_FLAGS        = /nologo /c /WX /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /GX-
NOOPT_VS2003xASL_IA32_CC_FLAGS          = /nologo /c /WX /W4 /Gs32768 /Gy /D UNICODE /FIAutoGen.h /EHs-c- /GR- /GF /GX- /Zi /Gm /Od

  DEBUG_VS2003xASL_IA32_ASM_FLAGS       = /nologo /c /WX /W3 /coff /Cx /Zd /Zi
RELEASE_VS2003xASL_IA32_ASM_FLAGS       = /nologo /c /WX /W3 /coff /Cx /Zd
NOOPT_VS2003xASL_IA32_ASM_FLAGS         = /nologo /c /WX /W3 /coff /Cx /Zd /Zi

  DEBUG_VS2003xASL_IA32_NASM_FLAGS      = -Ox -f win32 -g
RELEASE_VS2003xASL_IA32_NASM_FLAGS      = -Ox -f win32
NOOPT_VS2003xASL_IA32_NASM_FLAGS        = -O0 -f win32 -g

      *_VS2003xASL_IA32_SLINK_FLAGS     = /nologo /LTCG
  DEBUG_VS2003xASL_IA32_DLINK_FLAGS     = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_VS2003xASL_IA32_DLINK_FLAGS     = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4078 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_VS2003xASL_IA32_DLINK_FLAGS       = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

##################
# EBC definitions
##################
*_VS2003xASL_EBC_*_FAMILY               = INTEL

*_VS2003xASL_EBC_MAKE_PATH              = DEF(VS2003_BIN)\nmake.exe
*_VS2003xASL_EBC_PP_PATH                = DEF(EBC_BIN)\iec.exe
*_VS2003xASL_EBC_VFRPP_PATH             = DEF(EBC_BIN)\iec.exe
*_VS2003xASL_EBC_CC_PATH                = DEF(EBC_BIN)\iec.exe
*_VS2003xASL_EBC_SLINK_PATH             = DEF(EBC_BIN)\link.exe
*_VS2003xASL_EBC_DLINK_PATH             = DEF(EBC_BIN)\link.exe
*_VS2003xASL_EBC_RC_PATH                = DEF(VS2003_BIN)\rc.exe

*_VS2003xASL_EBC_MAKE_FLAGS             = /nologo
*_VS2003xASL_EBC_PP_FLAGS               = /nologo /E /TC /FIAutoGen.h
*_VS2003xASL_EBC_CC_FLAGS               = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_VS2003xASL_EBC_VFRPP_FLAGS            = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_VS2003xASL_EBC_SLINK_FLAGS            = /lib /NOLOGO /MACHINE:EBC
*_VS2003xASL_EBC_DLINK_FLAGS            = "C:\Program Files\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /MAP /ALIGN:32 /DRIVER

