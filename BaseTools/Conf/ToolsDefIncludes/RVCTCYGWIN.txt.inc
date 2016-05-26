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
# ARM RealView Tools - Cygwin
#
####################################################################################
#   ARMCYGWIN         - Tools from ARM in a Cygwin environment

*_RVCTCYGWIN_*_*_FAMILY               = RVCT
*_RVCTCYGWIN_*_*_BUILDRULEFAMILY      = RVCTCYGWIN

*_RVCTCYGWIN_ARM_CCPATH_FLAG         = ENV(RVCT_TOOLS_PATH)armcc
*_RVCTCYGWIN_ARM_SLINKPATH_FLAG      = ENV(RVCT_TOOLS_PATH)armlink
*_RVCTCYGWIN_ARM_DLINKPATH_FLAG      = ENV(RVCT_TOOLS_PATH)armlink
*_RVCTCYGWIN_ARM_ASMPATH_FLAG        = ENV(RVCT_TOOLS_PATH)armasm
*_RVCTCYGWIN_ARM_PPPATH_FLAG         = ENV(RVCT_TOOLS_PATH)armcc
*_RVCTCYGWIN_ARM_VFRPPPATH_FLAG      = ENV(RVCT_TOOLS_PATH)armcc
*_RVCTCYGWIN_ARM_FROMELFPATH_FLAG    = ENV(RVCT_TOOLS_PATH)fromelf

#
# Use default values, or override in DSC file
#
*_RVCTCYGWIN_ARM_ARCHCC_FLAGS    = --thumb --fpu=softvfp
*_RVCTCYGWIN_ARM_ARCHASM_FLAGS   =
*_RVCTCYGWIN_ARM_ARCHDLINK_FLAGS = 
*_RVCTCYGWIN_ARM_PLATFORM_FLAGS  = --cpu 7-A

  DEBUG_RVCTCYGWIN_ARM_DLINK_FLAGS     = "$(DLINKPATH_FLAG)" $(ARCHDLINK_FLAGS) DEF(RVCT_ALL_DLINK_FLAGS) --entry $(IMAGE_ENTRY_POINT) --map --list `cygpath -m $(DEST_DIR_DEBUG)/$(BASE_NAME).map` 
RELEASE_RVCTCYGWIN_ARM_DLINK_FLAGS     = "$(DLINKPATH_FLAG)" $(ARCHDLINK_FLAGS) DEF(RVCT_ALL_DLINK_FLAGS) --entry $(IMAGE_ENTRY_POINT) --map --list `cygpath -m $(DEST_DIR_DEBUG)/$(BASE_NAME).map` 
 
*_RVCTCYGWIN_ARM_ASM_FLAGS       = "$(ASMPATH_FLAG)" $(ARCHASM_FLAGS) $(PLATFORM_FLAGS) DEF(RVCT_ALL_ASM_FLAGS)
*_RVCTCYGWIN_ARM_PP_FLAGS        = "$(CCPATH_FLAG)" $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -E
*_RVCTCYGWIN_ARM_VFRPP_FLAGS     = "$(CCPATH_FLAG)" $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) -E  -DVFRCOMPILE --preinclude `cygpath -m $(DEST_DIR_DEBUG)/$(MODULE_NAME)StrDefs.h`
*_RVCTCYGWIN_ARM_MAKE_PATH       = make
*_RVCTCYGWIN_ARM_SLINK_FLAGS     = "$(SLINKPATH_FLAG)" --partial -o
  DEBUG_RVCTCYGWIN_ARM_CC_FLAGS  = "$(CCPATH_FLAG)" $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) DEF(RVCT_ALL_CC_FLAGS) -O1 -g
RELEASE_RVCTCYGWIN_ARM_CC_FLAGS  = "$(CCPATH_FLAG)" $(ARCHCC_FLAGS) $(PLATFORM_FLAGS) --diag_suppress=550 DEF(RVCT_ALL_CC_FLAGS) -O2

##################
# ARM definitions
##################
*_RVCTCYGWIN_ARM_CC_PATH         = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py
*_RVCTCYGWIN_ARM_SLINK_PATH      = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py
*_RVCTCYGWIN_ARM_DLINK_PATH      = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py
*_RVCTCYGWIN_ARM_ASM_PATH        = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py
*_RVCTCYGWIN_ARM_PP_PATH         = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py
*_RVCTCYGWIN_ARM_VFRPP_PATH      = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py
*_RVCTCYGWIN_ARM_FROMELF_PATH    = ENV(WORKSPACE)/BaseTools/Bin/CYGWIN_NT-5.1-i686/armcc_wrapper.py

