# Scope — map entry `WORD +0x28` split-copy and reset paths

Only original x86 `mach_kernel` bytes and full-pass5 instruction exports derived
from that binary are used. Python calculated all byte counts and raw file
offsets, then compared every listed instruction encoding to the original file.
Function names are export labels only; conclusions use the shown registers and
control-flow joins.

This report covers four selected local paths. It does not establish a complete
writer/alias inventory, field semantics, interprocedural call effects, runtime
execution, or lifetime.
