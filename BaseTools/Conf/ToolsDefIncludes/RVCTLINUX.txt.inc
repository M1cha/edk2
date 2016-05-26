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
# ARM RealView Tools - Linux
#
####################################################################################
#   RVCTLINUX         - Tools from ARM in a Cygwin environment
*_RVCTLINUX_*_*_FAMILY               = RVCT
*_RVCTLINUX_*_*_BUILDRULEFAMILY      = RVCTLINUX

*_RVCTLINUX_*_MAKE_PATH       = make

#
# Use default values, or override in DSC file
#
*_RVCTLINUX_ARM_ARCHCC_FLAGS    = --thumb --fpu=softvfp
*_RVCTLINUX_ARM_ARCHASM_FLAGS   = 
*_RVCTLINUX_ARM_ARCHDLINK_FLAGS = 
*_RVCTLINUX_ARM_PLATFORM_FLAGS  = --cpu 7-A

DEBUG_RVCTLINUX_ARM_DLINK_FLAGS     = $(ARCHDLINK_FLAGS) DEF(RVCT_ALL_DLINK_FLAGS) --entry $(IMAGE_ENTRY_POINT) --map --list $(DEST_DIR_DEBUG)/$(BASE_NAME).map 
RELEASE_RVCTLINUX_ARM_DLINK_FLAGS   = $(ARCHDLINK_FLAGS) DEF(RVCT_ALL_DLINK_FLAGS) --entry $(IMAGE_ENTRY_POINT) --map --list $(DEST_DIR_DEBUG)/$(BASE_NAME).map

*_RVCTLINUX_ARM_ASM_FLAGS       = $(ARCHASM_FLAGS) $(PLATFORM_FLAGS) DEF(RVCT_ALL_ASM_FLAGS)
*_RVCTLINUX_ARM_PP_FLAGS        = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -E
*_RVCTLINUX_ARM_VFRPP_FLAGS     = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -E  -DVFRCOMPILE --preinclude $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h
*_RVCTLINUX_ARM_SLINK_FLAGS     = --partial -o
  DEBUG_RVCTLINUX_ARM_CC_FLAGS  = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) DEF(RVCT_ALL_CC_FLAGS) -O1 -g
RELEASE_RVCTLINUX_ARM_CC_FLAGS  = $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) --diag_suppress=550 DEF(RVCT_ALL_CC_FLAGS) -O2

##################
# ARM definitions
##################
*_RVCTLINUX_ARM_CC_PATH         = ENV(RVCT_TOOLS_PATH)armcc
*_RVCTLINUX_ARM_SLINK_PATH      = ENV(RVCT_TOOLS_PATH)armlink
*_RVCTLINUX_ARM_DLINK_PATH      = ENV(RVCT_TOOLS_PATH)armlink
*_RVCTLINUX_ARM_ASM_PATH        = ENV(RVCT_TOOLS_PATH)armasm
*_RVCTLINUX_ARM_PP_PATH         = ENV(RVCT_TOOLS_PATH)armcc
*_RVCTLINUX_ARM_VFRPP_PATH      = ENV(RVCT_TOOLS_PATH)armcc
*_RVCTLINUX_ARM_FROMELF_PATH    = ENV(RVCT_TOOLS_PATH)fromelf

