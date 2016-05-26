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

#
# XCODE5 support
#

*_XCODE5_*_*_FAMILY            = GCC
*_XCODE5_*_*_BUILDRULEFAMILY   = XCODE
*_XCODE5_*_*_BUILDRULEORDER    = S s nasm

*_XCODE5_*_ASL_PATH          = /usr/bin/iasl

*_XCODE5_*_MAKE_PATH        = make
*_XCODE5_*_DSYMUTIL_PATH    = /usr/bin/dsymutil

  DEBUG_XCODE5_*_MTOC_FLAGS = -align 0x20 -d $(DEBUG_DIR)/$(MODULE_NAME).dll
  NOOPT_XCODE5_*_MTOC_FLAGS = -align 0x20 -d $(DEBUG_DIR)/$(MODULE_NAME).dll
RELEASE_XCODE5_*_MTOC_FLAGS = -align 0x20 

#
# use xcode-select to change Xcode version of command line tools
#
*_XCODE5_*_CC_PATH      = clang
*_XCODE5_*_SLINK_PATH   = libtool
*_XCODE5_*_DLINK_PATH   = ld
*_XCODE5_*_ASM_PATH     = as
*_XCODE5_*_PP_PATH      = clang
*_XCODE5_*_VFRPP_PATH   = clang
*_XCODE5_*_ASL_PATH     = iasl
*_XCODE5_*_ASLCC_PATH   = clang
*_XCODE5_*_ASLPP_PATH   = clang
*_XCODE5_*_ASLDLINK_PATH  = ld

####################
# IA-32 definitions
####################
  DEBUG_XCODE5_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
  NOOPT_XCODE5_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
RELEASE_XCODE5_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map

*_XCODE5_IA32_SLINK_FLAGS      = -static -o
  DEBUG_XCODE5_IA32_ASM_FLAGS  = -arch i386 -g
  NOOPT_XCODE5_IA32_ASM_FLAGS  = -arch i386 -g
RELEASE_XCODE5_IA32_ASM_FLAGS  = -arch i386 
      *_XCODE5_IA32_NASM_FLAGS = -f macho32


  DEBUG_XCODE5_IA32_CC_FLAGS   = -arch i386 -c -g -Os       -Wall -Werror -include AutoGen.h -funsigned-char -fno-stack-protector -fno-builtin -fshort-wchar -fasm-blocks -mdynamic-no-pic -mno-implicit-float -mms-bitfields -msoft-float -Wno-unused-parameter -Wno-missing-braces -Wno-missing-field-initializers -Wno-tautological-compare -Wno-sign-compare -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang $(PLATFORM_FLAGS)
RELEASE_XCODE5_IA32_CC_FLAGS   = -arch i386 -c    -Os       -Wall -Werror -include AutoGen.h -funsigned-char -fno-stack-protector -fno-builtin -fshort-wchar -fasm-blocks -mdynamic-no-pic -mno-implicit-float -mms-bitfields -msoft-float -Wno-unused-parameter -Wno-missing-braces -Wno-missing-field-initializers -Wno-tautological-compare -Wno-sign-compare -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang $(PLATFORM_FLAGS)
  NOOPT_XCODE5_IA32_CC_FLAGS   = -arch i386 -c -g -O0       -Wall -Werror -include AutoGen.h -funsigned-char -fno-stack-protector -fno-builtin -fshort-wchar -fasm-blocks -mdynamic-no-pic -mno-implicit-float -mms-bitfields -msoft-float -Wno-unused-parameter -Wno-missing-braces -Wno-missing-field-initializers -Wno-tautological-compare -Wno-sign-compare -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang $(PLATFORM_FLAGS)



##################
# X64 definitions
##################
  DEBUG_XCODE5_X64_DLINK_FLAGS      = -arch x86_64 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
  NOOPT_XCODE5_X64_DLINK_FLAGS      = -arch x86_64 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
RELEASE_XCODE5_X64_DLINK_FLAGS      = -arch x86_64 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map

*_XCODE5_X64_SLINK_FLAGS      = -static -o
  DEBUG_XCODE5_X64_ASM_FLAGS  = -arch x86_64 -g
  NOOPT_XCODE5_X64_ASM_FLAGS  = -arch x86_64 -g
RELEASE_XCODE5_X64_ASM_FLAGS  = -arch x86_64 
      *_XCODE5_X64_NASM_FLAGS = -f macho64
*_XCODE5_*_PP_FLAGS         = -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h 
*_XCODE5_*_VFRPP_FLAGS      = -x c -E -P -DVFRCOMPILE -include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h 


  DEBUG_XCODE5_X64_CC_FLAGS   = -target x86_64-pc-win32-macho -c -g -Os       -Wall -Werror -Wextra -include AutoGen.h -funsigned-char -fno-ms-extensions -fno-stack-protector -fno-builtin -fshort-wchar -mno-implicit-float -mms-bitfields -Wno-unused-parameter -Wno-missing-braces -Wno-missing-field-initializers -Wno-tautological-compare -Wno-sign-compare -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang $(PLATFORM_FLAGS)
  NOOPT_XCODE5_X64_CC_FLAGS   = -target x86_64-pc-win32-macho -c -g -O0       -Wall -Werror -Wextra -include AutoGen.h -funsigned-char -fno-ms-extensions -fno-stack-protector -fno-builtin -fshort-wchar -mno-implicit-float -mms-bitfields -Wno-unused-parameter -Wno-missing-braces -Wno-missing-field-initializers -Wno-tautological-compare -Wno-sign-compare -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang $(PLATFORM_FLAGS)
RELEASE_XCODE5_X64_CC_FLAGS   = -target x86_64-pc-win32-macho -c    -Os       -Wall -Werror -Wextra -include AutoGen.h -funsigned-char -fno-ms-extensions -fno-stack-protector -fno-builtin -fshort-wchar -mno-implicit-float -mms-bitfields -Wno-unused-parameter -Wno-missing-braces -Wno-missing-field-initializers -Wno-tautological-compare -Wno-sign-compare -ftrap-function=undefined_behavior_has_been_optimized_away_by_clang $(PLATFORM_FLAGS)

*_XCODE5_*_ASLCC_FLAGS      = -x c -save-temps -g -O0 -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -c -include AutoGen.h 
*_XCODE5_*_ASLDLINK_FLAGS   = -e _ReferenceAcpiTable -preload -segalign 0x20  -pie -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCODE5_*_ASLPP_FLAGS      = -x c -E 
*_XCODE5_*_ASL_FLAGS        =
*_XCODE5_*_ASL_OUTFLAGS     = DEF(IASL_OUTFLAGS)

