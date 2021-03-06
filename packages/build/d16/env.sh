#!/bin/sh
# RDK_LINUX_MEM:
# The amount of memory allocated to linux.
# The kernel bootargs mem= parameter should match this value.
export RDK_LINUX_MEM="180M"
# The start address of kernel NOTIFY_MEM

# The kernel bootargs notifyk.vpssm3_sva= parameter should match this value.
export NOTIFYK_VPSSM3_SVA_ADDR="0xbfd00000"

# The start address of REMOTE_DEBUG_ADDR section
# The address of REMOTE_DEBUG_MEM in the slave executables should match this
export REMOTE_DEBUG_ADDR="0xbff00000"

# The start address of HDVPSS_SHARED_MEM section
# The address of HDVPSS_SHARED_MEM in the slave executables should match this
export HDVPSS_SHARED_MEM="0xbfb00000"

# The size of HDVPSS_SHARED_MEM section
export HDVPSS_SHARED_SIZE="0x200000"

# The start address of CMEM section
export CMEM_ADDR_START="0x8b400000"

# The end address of CMEM section
export CMEM_ADDR_END="0x8df00000"

