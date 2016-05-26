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
# Intel(R) C++ Compiler Version 11.1
#
#   IA32 - Intel(R) C++ Compiler for applications running on IA32         (Version 11.1 Build 072 Package ID: w_cproc_p_11.1.072_ia32)
#   X64  - Intel(R) C++ Compiler for applications running on Intel(R) 64  (Version 11.1 Build 072 Package ID: w_cproc_p_11.1.072_intel64)
#   IPF  - Intel(R) C++ Compiler for applications running on IA-64        (Version 11.1 Build 072 Package ID: w_cproc_p_11.1.072_ia64)
#   ASL  - Microsoft ACPI Source Language Compiler
#
####################################################################################
#   ICC11xASL              - Intel C Compiler V11.1
*_ICC11xASL_*_*_FAMILY                    = INTEL

*_ICC11xASL_*_MAKE_PATH                   = DEF(MS_VS_BIN)\nmake.exe
*_ICC11xASL_*_RC_PATH                     = DEF(MS_VS_BIN)\rc.exe

*_ICC11xASL_*_MAKE_FLAGS                       = /nologo
*_ICC11xASL_*_VFRPP_FLAGS                      = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_ICC11xASL_*_APP_FLAGS                        = /nologo /E /TC
*_ICC11xASL_*_PP_FLAGS                         = /nologo /E /TC /FIAutoGen.h

*_ICC11xASL_*_ASM16_PATH      = DEF(MS_VS_BIN)\ml.exe

##################
# ASL definitions
##################
*_ICC11xASL_*_ASL_PATH        = DEF(DEFAULT_WIN_ASL_BIN)
*_ICC11xASL_*_ASL_FLAGS       = DEF(DEFAULT_WIN_ASL_FLAGS)
*_ICC11xASL_*_ASL_OUTFLAGS    = DEF(DEFAULT_WIN_ASL_OUTFLAGS)
*_ICC11xASL_*_ASLCC_FLAGS     = DEF(ICC_WIN_ASLCC_FLAGS)
*_ICC11xASL_*_ASLPP_FLAGS     = DEF(ICC_WIN_ASLPP_FLAGS)
*_ICC11xASL_*_ASLDLINK_FLAGS  = DEF(ICC_WIN_ASLDLINK_FLAGS)

##################
# IA32 definitions
##################
*_ICC11xASL_IA32_CC_PATH                  = DEF(ICC11_BIN32)\icl.exe
*_ICC11xASL_IA32_SLINK_PATH               = DEF(ICC11_BIN32)\xilib.exe
# xilib.exe needs lib.exe from Visual Studio
*_ICC11xASL_IA32_SLINK_DLL                = DEF(MS_VS_BIN)
*_ICC11xASL_IA32_DLINK_PATH               = DEF(ICC11_BIN32)\xilink.exe
*_ICC11xASL_IA32_PP_PATH                  = DEF(ICC11_BIN32)\icl.exe
*_ICC11xASL_IA32_VFRPP_PATH               = DEF(ICC11_BIN32)\icl.exe
*_ICC11xASL_IA32_APP_PATH                 = DEF(ICC11_BIN32)\icl.exe
*_ICC11xASL_IA32_ASM_PATH                 = DEF(MS_VS_BIN)\ml.exe
*_ICC11xASL_IA32_ASM_DLL                  = DEF(MS_VS_DLL)
*_ICC11xASL_IA32_ASLCC_PATH               = DEF(ICC11_BIN32)\icl.exe
*_ICC11xASL_IA32_ASLPP_PATH               = DEF(ICC11_BIN32)\icl.exe
*_ICC11xASL_IA32_ASLDLINK_PATH            = DEF(ICC11_BIN32)\xilink.exe

  DEBUG_ICC11xASL_IA32_CC_FLAGS                = /nologo /c /WX /W4 /Gy /Gs32768 /D UNICODE /O1b2 /GL /DEFI_FIRMWARE_VENDOR=L\"INTEL\" /FIAutoGen.h /EHs-c- /GF /Zi /Gm
RELEASE_ICC11xASL_IA32_CC_FLAGS                = /nologo /c /WX /W4 /Gy /Gs32768 /D UNICODE /O1b2 /GL /DEFI_FIRMWARE_VENDOR=L\"INTEL\" /FIAutoGen.h /EHs-c- /GF
NOOPT_ICC11xASL_IA32_CC_FLAGS                  = /nologo /c /WX /W4 /Gy /Gs32768 /D UNICODE /DEFI_FIRMWARE_VENDOR=L\"INTEL\" /FIAutoGen.h /EHs-c- /GF /Zi /Gm /Od

  DEBUG_ICC11xASL_IA32_ASM_FLAGS               = /nologo /c /WX /W3 /Zd /Zi
RELEASE_ICC11xASL_IA32_ASM_FLAGS               = /nologo /c /WX /W3 /Zd
NOOPT_ICC11xASL_IA32_ASM_FLAGS                 = /nologo /c /WX /W3 /Zd /Zi

  DEBUG_ICC11xASL_IA32_NASM_FLAGS              = -Ox -f win32 -g
RELEASE_ICC11xASL_IA32_NASM_FLAGS              = -Ox -f win32
NOOPT_ICC11xASL_IA32_NASM_FLAGS                = -O0 -f win32 -g

      *_ICC11xASL_IA32_SLINK_FLAGS             = /nologo
  DEBUG_ICC11xASL_IA32_DLINK_FLAGS             = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_ICC11xASL_IA32_DLINK_FLAGS             = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_ICC11xASL_IA32_DLINK_FLAGS               = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:X86 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

##################
# X64 definitions
##################
*_ICC11xASL_X64_CC_PATH                   = DEF(ICC11_BINX64)\icl.exe
*_ICC11xASL_X64_SLINK_PATH                = DEF(ICC11_BINX64)\xilib.exe
# xilib.exe needs lib.exe from Visual Studio
*_ICC11xASL_X64_SLINK_DLL                 = DEF(MS_VS_BIN)
*_ICC11xASL_X64_DLINK_PATH                = DEF(ICC11_BINX64)\xilink.exe
*_ICC11xASL_X64_PP_PATH                   = DEF(ICC11_BINX64)\icl.exe
*_ICC11xASL_X64_VFRPP_PATH                = DEF(ICC11_BINX64)\icl.exe
*_ICC11xASL_X64_APP_PATH                  = DEF(ICC11_BINX64)\icl.exe
*_ICC11xASL_X64_ASM_PATH                  = DEF(WINDDK_BINX64)\ml64.exe
*_ICC11xASL_X64_ASM_DLL                   = DEF(MS_VS_DLL)
*_ICC11xASL_X64_ASLCC_PATH                = DEF(ICC11_BINX64)\icl.exe
*_ICC11xASL_X64_ASLPP_PATH                = DEF(ICC11_BINX64)\icl.exe
*_ICC11xASL_X64_ASLDLINK_PATH             = DEF(ICC11_BINX64)\xilink.exe

  DEBUG_ICC11xASL_X64_CC_FLAGS                 = /nologo /c /WX /GS- /W4 /Gs32768 /D UNICODE /O1b2s /GL /Gy /FI$(DEST_DIR_DEBUG)/AutoGen.h /Zi /Gm /EHs-c- /GF
RELEASE_ICC11xASL_X64_CC_FLAGS                 = /nologo /c /WX /GS- /W4 /Gs32768 /D UNICODE /O1b2s /GL /Gy /FI$(DEST_DIR_DEBUG)/AutoGen.h /EHs-c- /GF
NOOPT_ICC11xASL_X64_CC_FLAGS                   = /nologo /c /WX /GS- /W4 /Gs32768 /D UNICODE /Gy /FI$(DEST_DIR_DEBUG)/AutoGen.h /Zi /Gm /EHs-c- /GF /Od

  DEBUG_ICC11xASL_X64_ASM_FLAGS                = /nologo /c /WX /W3 /Cx /Zd /Zi
RELEASE_ICC11xASL_X64_ASM_FLAGS                = /nologo /c /WX /W3 /Cx /Zd
NOOPT_ICC11xASL_X64_ASM_FLAGS                  = /nologo /c /WX /W3 /Cx /Zd /Zi

  DEBUG_ICC11xASL_X64_NASM_FLAGS               = -Ox -f win64 -g
RELEASE_ICC11xASL_X64_NASM_FLAGS               = -Ox -f win64
NOOPT_ICC11xASL_X64_NASM_FLAGS                 = -O0 -f win64 -g

  DEBUG_ICC11xASL_X64_DLINK_FLAGS              = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:CONSOLE /SAFESEH:NO /BASE:0 /DRIVER /DEBUG
RELEASE_ICC11xASL_X64_DLINK_FLAGS              = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /IGNORE:4254 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:CONSOLE /SAFESEH:NO /BASE:0 /DRIVER /MERGE:.rdata=.data
NOOPT_ICC11xASL_X64_DLINK_FLAGS                = /NOLOGO /NODEFAULTLIB /IGNORE:4001 /OPT:REF /OPT:ICF=10 /MAP /ALIGN:32 /SECTION:.xdata,D /SECTION:.pdata,D /Machine:X64 /LTCG /DLL /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:CONSOLE /SAFESEH:NO /BASE:0 /DRIVER /DEBUG

      *_ICC11xASL_X64_SLINK_FLAGS              = /nologo /LTCG


##################
# IPF definitions
##################
*_ICC11xASL_IPF_CC_PATH                   = DEF(ICC11_BIN64)\icl.exe
# icl.exe needs cl.exe from Visual Studio
*_ICC11xASL_IPF_CC_DLL                    = DEF(MS_VS_BIN)
*_ICC11xASL_IPF_SLINK_PATH                = DEF(ICC11_BIN64)\xilib.exe
# xilib.exe needs lib.exe from Visual Studio
*_ICC11xASL_IPF_SLINK_DLL                 = DEF(MS_VS_BIN);DEF(MS_VS_DLL)
*_ICC11xASL_IPF_DLINK_PATH                = DEF(ICC11_BIN64)\xilink.exe
*_ICC11xASL_IPF_PP_PATH                   = DEF(ICC11_BIN64)\icl.exe
*_ICC11xASL_IPF_VFRPP_PATH                = DEF(ICC11_BIN64)\icl.exe
*_ICC11xASL_IPF_APP_PATH                  = DEF(ICC11_BIN64)\icl.exe
*_ICC11xASL_IPF_ASM_PATH                  = DEF(ICC11_BIN64)\ias.exe
*_ICC11xASL_IPF_ASLCC_PATH                = DEF(ICC11_BIN64)\icl.exe
*_ICC11xASL_IPF_ASLPP_PATH                = DEF(ICC11_BIN64)\icl.exe
*_ICC11xASL_IPF_ASLDLINK_PATH             = DEF(ICC11_BIN64)\xilink.exe

  DEBUG_ICC11xASL_IPF_CC_FLAGS                 = /nologo /c /WX /W4 /GX /Gy /Od /FI$(DEST_DIR_DEBUG)/AutoGen.h /QIA64_fr32 /GF /Qfreestanding /Zi
RELEASE_ICC11xASL_IPF_CC_FLAGS                 = /nologo /c /WX /W4 /GX /Gy /Od /FI$(DEST_DIR_DEBUG)/AutoGen.h /QIA64_fr32 /GF /Qfreestanding
NOOPT_ICC11xASL_IPF_CC_FLAGS                   = /nologo /c /WX /W4 /GX /Gy /Od /FI$(DEST_DIR_DEBUG)/AutoGen.h /QIA64_fr32 /GF /Qfreestanding /Zi

  DEBUG_ICC11xASL_IPF_ASM_FLAGS                = -N us -X explicit -M ilp64 -N so -W3 -d debug -F COFF32
RELEASE_ICC11xASL_IPF_ASM_FLAGS                = -N us -X explicit -M ilp64 -N so -W3 -F COFF32
NOOPT_ICC11xASL_IPF_ASM_FLAGS                  = -N us -X explicit -M ilp64 -N so -W3 -d debug -F COFF32

  DEBUG_ICC11xASL_IPF_DLINK_FLAGS              = /NOLOGO /NODEFAULTLIB /LTCG /DLL /OPT:REF,ICF /IGNORE:4001 /MAP /ALIGN:64 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:IA64 /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MAP:$(DEST_DIR_DEBUG)/$(BASE_NAME).map /PDB:$(DEST_DIR_DEBUG)/$(BASE_NAME).pdb /DEBUG
RELEASE_ICC11xASL_IPF_DLINK_FLAGS              = /NOLOGO /NODEFAULTLIB /LTCG /DLL /OPT:REF,ICF /IGNORE:4001 /MAP /ALIGN:64 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:IA64 /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MAP:$(DEST_DIR_DEBUG)/$(BASE_NAME).map /PDB:$(DEST_DIR_DEBUG)/$(BASE_NAME).pdb
NOOPT_ICC11xASL_IPF_DLINK_FLAGS                = /NOLOGO /NODEFAULTLIB /LTCG /DLL /OPT:REF,ICF /IGNORE:4001 /MAP /ALIGN:64 /SECTION:.xdata,D /SECTION:.pdata,D /MACHINE:IA64 /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /SAFESEH:NO /BASE:0 /DRIVER /MAP:$(DEST_DIR_DEBUG)/$(BASE_NAME).map /PDB:$(DEST_DIR_DEBUG)/$(BASE_NAME).pdb /DEBUG

      *_ICC11xASL_IPF_SLINK_FLAGS              = /nologo

##################
# EBC definitions
##################
*_ICC11xASL_EBC_*_FAMILY              = INTEL

*_ICC11xASL_EBC_MAKE_PATH             = DEF(MS_VS_BIN)\nmake.exe
*_ICC11xASL_EBC_PP_PATH               = DEF(EBC_BIN)\iec.exe
*_ICC11xASL_EBC_VFRPP_PATH            = DEF(EBC_BIN)\iec.exe
*_ICC11xASL_EBC_CC_PATH               = DEF(EBC_BIN)\iec.exe
*_ICC11xASL_EBC_SLINK_PATH            = DEF(EBC_BIN)\link.exe
*_ICC11xASL_EBC_DLINK_PATH            = DEF(EBC_BIN)\link.exe

*_ICC11xASL_EBC_MAKE_FLAGS                 = /nologo
*_ICC11xASL_EBC_PP_FLAGS                   = /nologo /E /TC /FIAutoGen.h
*_ICC11xASL_EBC_CC_FLAGS                   = /nologo /c /WX /W3 /FIAutoGen.h /D$(MODULE_ENTRY_POINT)=$(ARCH_ENTRY_POINT)
*_ICC11xASL_EBC_VFRPP_FLAGS                = /nologo /E /TC /DVFRCOMPILE /FI$(MODULE_NAME)StrDefs.h
*_ICC11xASL_EBC_SLINK_FLAGS                = /lib /NOLOGO /MACHINE:EBC
*_ICC11xASL_EBC_DLINK_FLAGS                = "C:\Program Files\Intel\EBC\Lib\EbcLib.lib" /NOLOGO /NODEFAULTLIB /MACHINE:EBC /OPT:REF /ENTRY:$(IMAGE_ENTRY_POINT) /SUBSYSTEM:EFI_BOOT_SERVICE_DRIVER /MAP /ALIGN:32 /DRIVER

