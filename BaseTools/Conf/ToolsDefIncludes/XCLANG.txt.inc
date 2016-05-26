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
# Clang Support for building on Mac OS X
#
####################################################################################
#   CLANG         - clang that produce Mach-O with EFI x86_64 ABI
*_XCLANG_*_*_FAMILY            = GCC
*_XCLANG_*_*_BUILDRULEFAMILY   = XCODE
*_XCLANG_*_*_BUILDRULEORDER    = S s nasm

*_XCLANG_*_ASL_PATH          = /usr/bin/iasl

*_XCLANG_*_MAKE_PATH        = make
*_XCLANG_*_DSYMUTIL_PATH    = /usr/bin/dsymutil

      *_*_*_MTOC_PATH  = /usr/local/bin/mtoc

  DEBUG_XCLANG_*_MTOC_FLAGS = -align 0x20 -d $(DEBUG_DIR)/$(MODULE_NAME).dll
RELEASE_XCLANG_*_MTOC_FLAGS = -align 0x20


*_XCLANG_*_CC_PATH      = ENV(CLANG_BIN)clang
*_XCLANG_*_SLINK_PATH   = libtool
*_XCLANG_*_DLINK_PATH   = ld
*_XCLANG_*_ASM_PATH     = as
*_XCLANG_*_PP_PATH      = ENV(CLANG_BIN)clang
*_XCLANG_*_VFRPP_PATH   = ENV(CLANG_BIN)clang
*_XCLANG_*_ASL_PATH     = iasl
*_XCLANG_*_ASLCC_PATH   = ENV(CLANG_BIN)clang
*_XCLANG_*_ASLPP_PATH   = ENV(CLANG_BIN)clang
*_XCLANG_*_ASLDLINK_PATH  = ld

####################
# IA-32 definitions
####################
  DEBUG_XCLANG_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
RELEASE_XCLANG_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x220 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCLANG_IA32_SLINK_FLAGS      = -static -o
  DEBUG_XCLANG_IA32_ASM_FLAGS  = -arch i386 -g
RELEASE_XCLANG_IA32_ASM_FLAGS  = -arch i386 
*_XCLANG_IA32_NASM_FLAGS       = -f macho32

  DEBUG_XCLANG_IA32_CC_FLAGS   = -arch i386 -c -g -O0  -Wall -Werror -include AutoGen.h -fno-stack-protector -fno-builtin -fshort-wchar -mdynamic-no-pic -mno-sse -mno-mmx -Wno-empty-body -Wno-pointer-sign -Wno-unused-function -Wno-unused-value -Wno-missing-braces -Wno-tautological-compare -Wreturn-type -Wno-unused-variable  -fasm-blocks  -mms-bitfields -msoft-float -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang
RELEASE_XCLANG_IA32_CC_FLAGS   = -arch i386 -c    -Os  -Wall -Werror -include AutoGen.h -fno-stack-protector -fno-builtin -fshort-wchar -mdynamic-no-pic -mno-sse -mno-mmx -Wno-empty-body -Wno-pointer-sign -Wno-unused-function -Wno-unused-value -Wno-missing-braces -Wno-tautological-compare -Wreturn-type -Wno-unused-variable  -fasm-blocks  -mms-bitfields -msoft-float -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang


##################
# X64 definitions
##################
  DEBUG_XCLANG_X64_DLINK_FLAGS      = -arch x86_64 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
RELEASE_XCLANG_X64_DLINK_FLAGS      = -arch x86_64 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x220 -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCLANG_X64_SLINK_FLAGS      = -static -o
  DEBUG_XCLANG_X64_ASM_FLAGS  = -arch x86_64 -g
RELEASE_XCLANG_X64_ASM_FLAGS  = -arch x86_64 
*_XCLANG_X64_NASM_FLAGS       = -f macho64
*_XCLANG_*_PP_FLAGS         = -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h 
*_XCLANG_*_VFRPP_FLAGS      = -x c -E -P -DVFRCOMPILE -include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h 


  DEBUG_XCLANG_X64_CC_FLAGS   = -ccc-host-triple x86_64-pc-win32-macho -c -g -O0  -Wall -Werror -include AutoGen.h -fno-stack-protector -fno-builtin -fshort-wchar -mdynamic-no-pic -Wno-empty-body -Wno-pointer-sign -Wno-unused-function -Wno-unused-value -Wno-missing-braces -Wno-tautological-compare -Wreturn-type -Wno-unused-variable -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang
RELEASE_XCLANG_X64_CC_FLAGS   = -ccc-host-triple x86_64-pc-win32-macho -c    -Os  -Wall -Werror -include AutoGen.h -fno-stack-protector -fno-builtin -fshort-wchar -mdynamic-no-pic -Wno-empty-body -Wno-pointer-sign -Wno-unused-function -Wno-unused-value -Wno-missing-braces -Wno-tautological-compare -Wreturn-type -Wno-unused-variable -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang
*_XCLANG_*_ASLCC_FLAGS      = -x c -save-temps -g -O0 -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -c -include AutoGen.h -mdynamic-no-pic
*_XCLANG_*_ASLDLINK_FLAGS   = -e _main -preload -segalign 0x20  -pie -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCLANG_*_ASLPP_FLAGS      = -x c -E 
*_XCLANG_*_ASL_FLAGS        =

