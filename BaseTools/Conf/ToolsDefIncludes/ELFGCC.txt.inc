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
# Elf GCC - This configuration is used to compile on Linux boxes to produce elf
#           binaries.
#
####################################################################################
#   ELFGCC           - Linux ELF GCC
*_ELFGCC_*_*_FAMILY                 = GCC
*_ELFGCC_*_MAKE_PATH                = make

*_ELFGCC_*_PP_FLAGS                     = -E -x assembler-with-cpp -include AutoGen.h
*_ELFGCC_*_VFRPP_FLAGS                  = -x c -E -P -DVFRCOMPILE --include $(MODULE_NAME)StrDefs.h

##################
# ASL definitions
##################
*_ELFGCC_*_ASL_PATH                     = DEF(UNIX_IASL_BIN)
*_ELFGCC_*_ASL_FLAGS                    = DEF(IASL_FLAGS)
*_ELFGCC_*_ASL_OUTFLAGS                 = DEF(IASL_OUTFLAGS)
*_ELFGCC_*_ASLPP_FLAGS                  = -x c -E -P
*_ELFGCC_*_ASLCC_FLAGS                  = -x c
*_ELFGCC_*_ASLDLINK_FLAGS               = DEF(GCC_DLINK_FLAGS_COMMON) --entry _ReferenceAcpiTable

##################
# IA32 definitions
##################
*_ELFGCC_IA32_OBJCOPY_PATH          = DEF(ELFGCC_BIN)/objcopy
*_ELFGCC_IA32_CC_PATH               = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IA32_SLINK_PATH            = DEF(ELFGCC_BIN)/ar
*_ELFGCC_IA32_DLINK_PATH            = DEF(ELFGCC_BIN)/ld
*_ELFGCC_IA32_ASM_PATH              = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IA32_PP_PATH               = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IA32_VFRPP_PATH            = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IA32_ASLCC_PATH            = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IA32_ASLPP_PATH            = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IA32_ASLDLINK_PATH         = DEF(ELFGCC_BIN)/ld
*_ELFGCC_IA32_RC_PATH               = DEF(ELFGCC_BIN)/objcopy

*_ELFGCC_IA32_CC_FLAGS              = -m32 -g -fshort-wchar -fno-strict-aliasing -Wall -malign-double -c -include $(DEST_DIR_DEBUG)/AutoGen.h -DSTRING_ARRAY_NAME=$(BASE_NAME)Strings
*_ELFGCC_IA32_SLINK_FLAGS           =
*_ELFGCC_IA32_DLINK_FLAGS           = -melf_i386 -nostdlib --shared --entry $(IMAGE_ENTRY_POINT) -u $(IMAGE_ENTRY_POINT) -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
#*_ELFGCC_IA32_DLINK_FLAGS          = -melf_i386 -nostdlib -n -q -Ttext 0x220 --entry $(IMAGE_ENTRY_POINT) -u $(IMAGE_ENTRY_POINT)
*_ELFGCC_IA32_ASM_FLAGS             = -m32 -c -x assembler -imacros $(DEST_DIR_DEBUG)/AutoGen.h
*_ELFGCC_IA32_PP_FLAGS              = -m32 -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
*_ELFGCC_IA32_VFRPP_FLAGS           = -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h
*_ELFGCC_IA32_RC_FLAGS              = DEF(GCC_IA32_RC_FLAGS)
*_ELFGCC_IA32_OBJCOPY_FLAGS         =
*_ELFGCC_IA32_NASM_FLAGS            = -f elf32

##################
# X64 definitions
##################
*_ELFGCC_X64_CC_PATH               = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_X64_ASLCC_PATH            = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_X64_SLINK_PATH            = DEF(ELFGCC_BIN)/ar
*_ELFGCC_X64_DLINK_PATH            = DEF(ELFGCC_BIN)/ld
*_ELFGCC_X64_ASLDLINK_PATH         = DEF(ELFGCC_BIN)/ld
*_ELFGCC_X64_ASM_PATH              = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_X64_PP_PATH               = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_X64_ASLPP_PATH            = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_X64_VFRPP_PATH            = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_X64_RC_PATH               = DEF(ELFGCC_BIN)/objcopy

*_ELFGCC_X64_CC_FLAGS              = -Os -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-address -Wno-array-bounds -c -include AutoGen.h -D_EFI_P64
*_ELFGCC_X64_DLINK_FLAGS           = -nostdlib --shared --entry $(IMAGE_ENTRY_POINT) -u $(IMAGE_ENTRY_POINT) -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_ELFGCC_X64_SLINK_FLAGS           =
*_ELFGCC_X64_ASM_FLAGS             = -c -x assembler -imacros $(DEST_DIR_DEBUG)/AutoGen.h
*_ELFGCC_X64_PP_FLAGS              = -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
*_ELFGCC_X64_VFRPP_FLAGS           = -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h
*_ELFGCC_X64_RC_FLAGS              = DEF(GCC_X64_RC_FLAGS)
*_ELFGCC_X64_NASM_FLAGS            = -f elf64

##################
# IPF definitions
##################
*_ELFGCC_IPF_CC_PATH              = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IPF_ASLCC_PATH           = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IPF_SLINK_PATH           = DEF(ELFGCC_BIN)/ar
*_ELFGCC_IPF_DLINK_PATH           = DEF(ELFGCC_BIN)/ld
*_ELFGCC_IPF_ASLDLINK_PATH        = DEF(ELFGCC_BIN)/ld
*_ELFGCC_IPF_ASM_PATH             = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IPF_PP_PATH              = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IPF_ASLPP_PATH           = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IPF_VFRPP_PATH           = DEF(ELFGCC_BIN)/gcc
*_ELFGCC_IPF_RC_PATH              = DEF(ELFGCC_BIN)/objcopy

*_ELFGCC_IPF_CC_FLAGS             = -Os -fshort-wchar -Wall -Werror -c -include AutoGen.h -D_EFI_P64
*_ELFGCC_IPF_DLINK_FLAGS          = -nostdlib --shared --entry $(IMAGE_ENTRY_POINT) -u $(IMAGE_ENTRY_POINT) -Map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_ELFGCC_IPF_SLINK_FLAGS          =
*_ELFGCC_IPF_ASM_FLAGS            = -c -x assembler -imacros $(DEST_DIR_DEBUG)/AutoGen.h
*_ELFGCC_IPF_PP_FLAGS             = -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
*_ELFGCC_IPF_VFRPP_FLAGS          = -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h
*_ELFGCC_IPF_RC_FLAGS             = DEF(GCC_IPF_RC_FLAGS)

