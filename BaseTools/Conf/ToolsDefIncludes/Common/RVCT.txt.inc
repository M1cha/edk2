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
# RVCT Common
#
####################################################################################

DEFINE RVCT_ALL_ASM_FLAGS   = --diag_suppress=1786 --diag_error=warning --apcs /interwork
DEFINE RVCT_ALL_CC_FLAGS    = --c90 -c --no_autoinline --asm --gnu --apcs /interwork --signed_chars --no_unaligned_access --split_sections --enum_is_int --preinclude AutoGen.h --diag_suppress=186 --diag_warning 167 --diag_error=warning --diag_style=ide --protect_stack
DEFINE RVCT_ALL_DLINK_FLAGS = --no_scanlib --no_exceptions --datacompressor off --strict --symbols --diag_style=ide --no_legacyalign --scatter $(EDK_TOOLS_PATH)/Scripts/Rvct-Align32.sct

