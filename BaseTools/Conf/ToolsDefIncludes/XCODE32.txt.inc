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
# Xcode Support for building on Mac OS X (Snow Leopard)
#
####################################################################################
#   XCODE32         - Xcode 3.2 Tools (Snow Leopard)
*_XCODE32_*_*_FAMILY            = GCC
*_XCODE32_*_*_BUILDRULEFAMILY   = XCODE
*_XCODE32_*_*_BUILDRULEORDER    = S s nasm


*_XCODE32_*_ASL_PATH          = /usr/bin/iasl

*_XCODE32_*_MAKE_PATH        = make

*_XCODE32_*_DSYMUTIL_PATH    = /usr/bin/dsymutil

# This tool needs to be installed seperatly from Xcode 3.2
*_XCODE32_*_MTOC_PATH        = /usr/local/bin/mtoc

  DEBUG_XCODE32_*_MTOC_FLAGS = -align 0x20 -d $(DEBUG_DIR)/$(MODULE_NAME).dll
RELEASE_XCODE32_*_MTOC_FLAGS = -align 0x20

##################
# IA32 definitions
##################
*_XCODE32_IA32_CC_PATH      = gcc
*_XCODE32_IA32_SLINK_PATH   = libtool
*_XCODE32_IA32_DLINK_PATH   = ld
*_XCODE32_IA32_ASM_PATH     = as
*_XCODE32_IA32_PP_PATH      = gcc
*_XCODE32_IA32_VFRPP_PATH   = gcc
*_XCODE32_IA32_ASL_PATH     = iasl
*_XCODE32_IA32_ASLCC_PATH   = gcc
*_XCODE32_IA32_ASLPP_PATH   = gcc
*_XCODE32_IA32_ASLDLINK_PATH  = ld

  DEBUG_XCODE32_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
RELEASE_XCODE32_IA32_DLINK_FLAGS      = -arch i386 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x220 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCODE32_IA32_SLINK_FLAGS      = -static -o
  DEBUG_XCODE32_IA32_ASM_FLAGS  = -arch i386 -g
RELEASE_XCODE32_IA32_ASM_FLAGS  = -arch i386
*_XCODE32_IA32_NASM_FLAGS       = -f macho32
*_XCODE32_IA32_PP_FLAGS         = -arch i386 -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
*_XCODE32_IA32_VFRPP_FLAGS      = -arch i386 -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h
  DEBUG_XCODE32_IA32_CC_FLAGS   = -arch i386 -save-temps -g -O0 -combine -mms-bitfields  -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces  -c -include AutoGen.h -mdynamic-no-pic -fno-stack-protector
RELEASE_XCODE32_IA32_CC_FLAGS   = -arch i386 -Oz -combine -mms-bitfields  -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -fomit-frame-pointer -c -include AutoGen.h -mdynamic-no-pic -fno-stack-protector

*_XCODE32_IA32_ASLCC_FLAGS      = -arch i386 -x c -save-temps -g -O0 -mms-bitfields -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -c -include AutoGen.h -mdynamic-no-pic
*_XCODE32_IA32_ASLDLINK_FLAGS   = -arch i386 -e _main -preload -segalign 0x20  -pie -seg1addr 0x220 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCODE32_IA32_ASLPP_FLAGS      = -arch i386 -x c -E
*_XCODE32_IA32_ASL_FLAGS        =

##################
# X64 definitions - still a work in progress. This tool chain does not produce
# the correct ABI, it is just used to compile the code....
##################
*_XCODE32_X64_CC_PATH       = gcc
*_XCODE32_X64_SLINK_PATH    = libtool
*_XCODE32_X64_DLINK_PATH    = ld
*_XCODE32_X64_ASM_PATH      = as
*_XCODE32_X64_PP_PATH       = gcc
*_XCODE32_X64_VFRPP_PATH    = gcc
*_XCODE32_X64_ASL_PATH     = iasl
*_XCODE32_X64_ASLCC_PATH   = gcc
*_XCODE32_X64_ASLPP_PATH   = gcc
*_XCODE32_X64_ASLDLINK_PATH  = ld

*_XCODE32_X64_DLINK_FLAGS      = -arch x86_64 -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -seg1addr 0x240 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
*_XCODE32_X64_SLINK_FLAGS      = -static -o

  DEBUG_XCODE32_X64_ASM_FLAGS  = -arch x86_64 -g
RELEASE_XCODE32_X64_ASM_FLAGS  = -arch x86_64
*_XCODE32_X64_NASM_FLAGS       = -f macho64
*_XCODE32_X64_PP_FLAGS         = -arch x86_64 -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
*_XCODE32_X64_VFRPP_FLAGS      = -arch x86_64 -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h

  DEBUG_XCODE32_X64_CC_FLAGS   = -arch x86_64 -save-temps -g -O0 -mms-bitfields -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -Wno-address  -fomit-frame-pointer -static  -c -include AutoGen.h -fno-stack-protector
RELEASE_XCODE32_X64_CC_FLAGS   = -arch x86_64 -Oz -mms-bitfields -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -Wno-address  -fomit-frame-pointer -static  -c -include AutoGen.h -fno-stack-protector

##################
# ARM definitions - (Assumes iPhone SDK installed on Snow Leopard)
##################

*_XCODE32_ARM_ARCHCC_FLAGS    = -arch armv7 -march=armv7 -mthumb
*_XCODE32_ARM_ARCHASM_FLAGS   = -arch armv7
*_XCODE32_ARM_ARCHDLINK_FLAGS = -arch armv7
*_XCODE32_ARM_PLATFORM_FLAGS  =

*_XCODE32_ARM_CC_PATH       = DEF(IPHONE_TOOLS)/usr/bin/gcc
*_XCODE32_ARM_SLINK_PATH    = DEF(IPHONE_TOOLS)/usr/bin/libtool
*_XCODE32_ARM_DLINK_PATH    = ld
*_XCODE32_ARM_ASM_PATH      = DEF(IPHONE_TOOLS)/usr/bin/as
*_XCODE32_ARM_PP_PATH       = DEF(IPHONE_TOOLS)/usr/bin/gcc
*_XCODE32_ARM_VFRPP_PATH    = DEF(IPHONE_TOOLS)/usr/bin/gcc

  DEBUG_XCODE32_ARM_DLINK_FLAGS      = $(ARCHDLINK_FLAGS) -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x220 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map
RELEASE_XCODE32_ARM_DLINK_FLAGS      = $(ARCHDLINK_FLAGS) -u _$(IMAGE_ENTRY_POINT) -e _$(IMAGE_ENTRY_POINT) -preload -segalign 0x20  -pie -all_load -dead_strip -seg1addr 0x220 -read_only_relocs suppress -map $(DEST_DIR_DEBUG)/$(BASE_NAME).map

*_XCODE32_ARM_SLINK_FLAGS      = -static -o

  DEBUG_XCODE32_ARM_ASM_FLAGS  = $(ARCHASM_FLAGS) -g
RELEASE_XCODE32_ARM_ASM_FLAGS  = $(ARCHASM_FLAGS)
*_XCODE32_ARM_PP_FLAGS         = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -E -x assembler-with-cpp -include $(DEST_DIR_DEBUG)/AutoGen.h
*_XCODE32_ARM_VFRPP_FLAGS      = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -x c -E -P -DVFRCOMPILE --include $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h

  DEBUG_XCODE32_ARM_CC_FLAGS   = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -mthumb-interwork -g -Oz -mabi=aapcs -mapcs -fno-short-enums  -save-temps -combine -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -fomit-frame-pointer -c -include AutoGen.h
RELEASE_XCODE32_ARM_CC_FLAGS   = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -mthumb-interwork -Oz    -mabi=aapcs -mapcs -fno-short-enums  -save-temps -combine -fshort-wchar -fno-strict-aliasing -Wall -Werror -Wno-missing-braces -fomit-frame-pointer -c -include AutoGen.h

