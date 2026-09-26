# Scope — `_vm_page_init` complete direct-relative branch scan

Only original x86 `mach_kernel` bytes are used. Python scanned every byte
position in the complete original `__text` region for x86 direct-relative
control-transfer encodings whose decoded destination is `0x0017b134`.
All branch-target arithmetic and counts were performed in Python.

This is a negative static encoding audit. It does not cover indirect transfer,
computed addresses, loader state, non-text execution, or runtime reachability.
