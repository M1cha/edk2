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
# MYTOOLS
#   IA32 - Microsoft Visual Studio 2008 Team Suite
#   X64  - Microsoft Visual Studio 2008 Team Suite
#   IPF  - Microsoft Windows DDK 3790.1830
#   EBC  - Intel EFI Byte Code Compiler
#
####################################################################################
#   MYTOOLS          - Settings compatible with previous versions of tools_def.template
*_MYTOOLS_*_*_FAMILY                = MSFT

##################
# ASL definitions
##################
*_MYTOOLS_*_ASL_PATH        = DEF(DEFAULT_WIN_ASL_BIN)
*_MYTOOLS_*_ASL_FLAGS       = DEF(DEFAULT_WIN_ASL_FLAGS)
*_MYTOOLS_*_ASL_OUTFLAGS    = DEF(DEFAULT_WIN_ASL_OUTFLAGS)
*_MYTOOLS_*_ASLCC_FLAGS     = DEF(MSFT_ASLCC_FLAGS)
*_MYTOOLS_*_ASLPP_FLAGS     = DEF(MSFT_ASLPP_FLAGS)
*_MYTOOLS_*_ASLDLINK_FLAGS  = DEF(MSFT_ASLDLINK_FLAGS)


*_MYTOOLS_*_MAKE_FLAGS                   = /nologo
*_MYTOOLS_*_VFRPP_FLAGS                  = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_MYTOOLS_*_APP_FLAGS                    = /nologo /E /TC
*_MYTOOLS_*_PP_FLAGS                     = /nologo /E /TC /FIAutoGen.h
*_MYTOOLS_*_SLINK_FLAGS                  = /nologo /LTCG

*_MYTOOLS_*_ASM16_PATH      = DEF(VS2008_BIN)\ml.exe

##################
# IA32 definitions
##################
*_MYTOOLS_IA32_*_DLL                = DEF(VS2008_DLL)

*_MYTOOLS_IA32_MAKE_PATH            = DEF(VS2008_BIN)\nmake.exe
*_MYTOOLS_IA32_CC_PATH              = DEF(VS2008_BIN)\cl.exe
*_MYTOOLS_IA32_SLINK_PATH           = DEF(VS2008_BIN)\lib.exe
*_MYTOOLS_IA32_DLINK_PATH           = DEF(VS2008_BIN)\link.exe
*_MYTOOLS_IA32_PP_PATH              = DEF(VS2008_BIN)\cl.exe
*_MYTOOLS_IA32_VFRPP_PATH           = DEF(VS2008_BIN)\cl.exe
*_MYTOOLS_IA32_APP_PATH             = DEF(VS2008_BIN)\cl.exe
*_MYTOOLS_IA32_ASM_PATH             = DEF(VS2008_BIN)\ml.exe
*_MYTOOLS_IA32_ASLCC_PATH           = DEF(VS2008_BIN)\cl.exe
*_MYTOOLS_IA32_ASLPP_PATH           = DEF(VS2008_BIN)\cl.exe
*_MYTOOLS_IA32_ASLDLINK_PATH        = DEF(VS2008_BIN)\link.exe
*_MYTOOLS_IA32_RC_PATH              = DEF(WINSDK_BIN)\rc.exe

  DEBUG_MYTOOLS_IA32_CC_FLAGS            = /nologo /c /WX /GS- /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm
RELEASE_MYTOOLS_IA32_CC_FLAGS            = /nologo /c /WX /GS- /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF
NOOPT_MYTOOLS_IA32_CC_FLAGS              = /nologo /c /WX /GS- /W4 /Gs32768 /Gy /D UNICODE /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm /Od
  DEBUG_MYTOOLS_IA32_ASM_FLAGS           = /nologo /c /WX /W3 /coff /Cx /Zd /Zi
RELEASE_MYTOOLS_IA32_ASM_FLAGS           = /nologo /c /WX /W3 /coff /Cx /Zd
NOOPT_MYTOOLS_IA32_ASM_FLAGS             = /nologo /c /WX /W3 /coff /Cx /Zd /Zi  
  DEBUG_MYTOOLS_IA32_NASM_FLAGS          = -Ox -f win32 -g
RELEASE_MYTOOLS_IA32_NASM_FLAGS          = -Ox -f win32
NOOPT_MYTOOLS_IA32_NASM_FLAGS            = -O0 -f win32 -g
  DEBUG_MYTOOLS_IA32_DLINK_FLAGS         = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG /PDB:$(DEBUG_DIR)/$(BASE_NAME).pdb
RELEASE_MYTOOLS_IA32_DLINK_FLAGS         = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data /PDB:$(DEBUG_DIR)/$(BASE_NAME).pdb
NOOPT_MYTOOLS_IA32_DLINK_FLAGS           = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG /PDB:$(DEBUG_DIR)/$(BASE_NAME).pdb

##################
# x64 definitions
##################
*_MYTOOLS_X64_*_DLL                 = DEF(VS2008_DLL)

*_MYTOOLS_X64_MAKE_PATH             = DEF(VS2008_BIN)\nmake.exe
*_MYTOOLS_X64_CC_PATH               = DEF(VS2008_BINX64)\cl.exe
*_MYTOOLS_X64_SLINK_PATH            = DEF(VS2008_BINX64)\lib.exe
*_MYTOOLS_X64_DLINK_PATH            = DEF(VS2008_BINX64)\link.exe
*_MYTOOLS_X64_PP_PATH               = DEF(VS2008_BINX64)\cl.exe
*_MYTOOLS_X64_VFRPP_PATH            = DEF(VS2008_BINX64)\cl.exe
*_MYTOOLS_X64_APP_PATH              = DEF(VS2008_BINX64)\cl.exe
*_MYTOOLS_X64_ASM_PATH              = DEF(VS2008_BINX64)\ml64.exe
*_MYTOOLS_X64_ASLCC_PATH            = DEF(VS2008_BINX64)\cl.exe
*_MYTOOLS_X64_ASLPP_PATH            = DEF(VS2008_BINX64)\cl.exe
*_MYTOOLS_X64_ASLDLINK_PATH         = DEF(VS2008_BINX64)\link.exe
*_MYTOOLS_X64_RC_PATH               = DEF(WINSDK_BIN)\rc.exe

  DEBUG_MYTOOLS_X64_CC_FLAGS             = /nologo /c /WX /GS- /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm
RELEASE_MYTOOLS_X64_CC_FLAGS             = /nologo /c /WX /GS- /W4 /Gs32768 /Gy /D UNICODE /O1b2 /GL /FIAutoGen.h /EHs-c- /GR- /GF
NOOPT_MYTOOLS_X64_CC_FLAGS               = /nologo /c /WX /GS- /W4 /Gs32768 /Gy /D UNICODE /FIAutoGen.h /EHs-c- /GR- /GF /Zi /Gm /Od  
  DEBUG_MYTOOLS_X64_ASM_FLAGS            = /nologo /c /WX /W3 /Cx /Zd /Zi
RELEASE_MYTOOLS_X64_ASM_FLAGS            = /nologo /c /WX /W3 /Cx /Zd
NOOPT_MYTOOLS_X64_ASM_FLAGS              = /nologo /c /WX /W3 /Cx /Zd /Zi  
  DEBUG_MYTOOLS_X64_NASM_FLAGS           = -Ox -f win64 -g
RELEASE_MYTOOLS_X64_NASM_FLAGS           = -Ox -f win64
NOOPT_MYTOOLS_X64_NASM_FLAGS             = -O0 -f win64 -g
  DEBUG_MYTOOLS_X64_DLINK_FLAGS          = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_MYTOOLS_X64_DLINK_FLAGS          = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_MYTOOLS_X64_DLINK_FLAGS            = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

##################
# IPF definitions
##################
*_MYTOOLS_IPF_MAKE_PATH             = DEF(WINDDK_BIN32)\nmake.exe
*_MYTOOLS_IPF_CC_PATH               = DEF(WINDDK_BIN64)\cl.exe
*_MYTOOLS_IPF_SLINK_PATH            = DEF(WINDDK_BIN64)\lib.exe
*_MYTOOLS_IPF_DLINK_PATH            = DEF(WINDDK_BIN64)\link.exe
*_MYTOOLS_IPF_PP_PATH               = DEF(WINDDK_BIN64)\cl.exe
*_MYTOOLS_IPF_VFRPP_PATH            = DEF(WINDDK_BIN64)\cl.exe
*_MYTOOLS_IPF_APP_PATH              = DEF(WINDDK_BIN64)\cl.exe
*_MYTOOLS_IPF_ASM_PATH              = DEF(WINDDK_BIN64)\ias.exe
*_MYTOOLS_IPF_ASLCC_PATH            = DEF(WINDDK_BIN64)\cl.exe
*_MYTOOLS_IPF_ASLPP_PATH            = DEF(WINDDK_BIN64)\cl.exe
*_MYTOOLS_IPF_ASLDLINK_PATH         = DEF(WINDDK_BIN64)\link.exe
*_MYTOOLS_IPF_RC_PATH               = DEF(WINDDK_BIN32)\rc.exe

      *_MYTOOLS_IPF_ASM_OUTPUT           = "-o "
  DEBUG_MYTOOLS_IPF_CC_FLAGS             = /nologo /c /WX /GS- /X /W4 /Gy /Ox /GL /FIAutoGen.h /EHs-c- /GR- /GF /Zx /QIPF_fr32 /Zi
RELEASE_MYTOOLS_IPF_CC_FLAGS             = /nologo /c /WX /GS- /X /W4 /Gy /Ox /GL /FIAutoGen.h /EHs-c- /GR- /GF /Zx /QIPF_fr32
NOOPT_MYTOOLS_IPF_CC_FLAGS               = /nologo /c /WX /GS- /X /W4 /Gy /FIAutoGen.h /EHs-c- /GR- /GF /Zx /QIPF_fr32 /Zi /Od
  DEBUG_MYTOOLS_IPF_ASM_FLAGS            = -N us -X explicit -M ilp64 -N so -W4 -d debug
RELEASE_MYTOOLS_IPF_ASM_FLAGS            = -N us -X explicit -M ilp64 -N so -W4
NOOPT_MYTOOLS_IPF_ASM_FLAGS              = -N us -X explicit -M ilp64 -N so -W4 -d debug
  DEBUG_MYTOOLS_IPF_DLINK_FLAGS          = /NOLOGO /NODEFAULTLIB /LTCG /DLL /OPT:REF /OPT:ICF=10 /IGNORE:4001 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:IA64 /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MAP:$(DEST_DIR_DEBUG)/$(BASE_NAME).map /PDB:$(DEBUG_DIR)/$(BASE_NAME).pdb /DEBUG
RELEASE_MYTOOLS_IPF_DLINK_FLAGS          = /NOLOGO /NODEFAULTLIB /LTCG /DLL /OPT:REF /OPT:ICF=10 /IGNORE:4001 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:IA64 /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MAP:$(DEST_DIR_DEBUG)/$(BASE_NAME).map /PDB:$(DEBUG_DIR)/$(BASE_NAME).pdb
NOOPT_MYTOOLS_IPF_DLINK_FLAGS            = /NOLOGO /NODEFAULTLIB /LTCG /DLL /OPT:REF /OPT:ICF=10 /IGNORE:4001 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:IA64 /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MAP:$(DEST_DIR_DEBUG)/$(BASE_NAME).map /PDB:$(DEBUG_DIR)/$(BASE_NAME).pdb /DEBUG
      *_MYTOOLS_IPF_SLINK_FLAGS          = /nologo /LTCG

##################
# EBC definitions
##################
*_MYTOOLS_EBC_*_FAMILY              = INTEL

*_MYTOOLS_EBC_MAKE_PATH             = DEF(VS2005_BIN)\nmake.exe
*_MYTOOLS_EBC_PP_PATH               = DEF(EBC_BIN)\iec.exe
*_MYTOOLS_EBC_VFRPP_PATH            = DEF(EBC_BIN)\iec.exe
*_MYTOOLS_EBC_CC_PATH               = DEF(EBC_BIN)\iec.exe
*_MYTOOLS_EBC_SLINK_PATH            = DEF(EBC_BIN)\link.exe
*_MYTOOLS_EBC_DLINK_PATH            = DEF(EBC_BIN)\link.exe
*_MYTOOLS_EBC_RC_PATH               = DEF(VS2005_BIN)\rc.exe

*_MYTOOLS_EBC_MAKE_FLAGS                 = /nologo
*_MYTOOLS_EBC_PP_FLAGS                   = /nologo /E /TC /FIAutoGen.h
*_MYTOOLS_EBC_CC_FLAGS                   = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_MYTOOLS_EBC_VFRPP_FLAGS                = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_MYTOOLS_EBC_SLINK_FLAGS                = /lib /NOLOGO /MACHINE:EBC
*_MYTOOLS_EBC_DLINK_FLAGS                = "C:\Program Files\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /MAP /ALIGN:32 /DRIVER

