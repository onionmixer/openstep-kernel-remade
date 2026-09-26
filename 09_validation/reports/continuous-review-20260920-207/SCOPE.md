# Scope — map 44-byte copy post-transition inventory

Only original x86 `mach_kernel` bytes and full-pass5 function bodies derived
from that binary are used. Python selected `REP MOVSD` instructions preceded
by `ECX=0xb` in exact `_vm_map`/`__vm_map` labelled bodies, then checked the
post-copy explicit `+0x30` update sites and the two exceptional fork flows.
All counts, address mappings, and byte checks are calculated in Python.

The inventory identifies syntactic post-copy paths. It does not prove that
every such branch executes or establish a whole-binary object alias set.
