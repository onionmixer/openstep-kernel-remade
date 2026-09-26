# `_vm_map_fork` record-field initializer paths

This static-only report finds two `_vm_map_fork` paths where the allocation
result is moved to `EBX`, followed by a zero dword store at `EBX+0x28` and a
one dword store at `EBX+0x30`. The two stores are byte-verified and occur on
the same EBX-based record in each selected path.

A separate selected copy path moves 11 dwords (44 bytes, calculated with
Python) into a fresh destination and immediately stores zero to that
destination's `WORD +0x28`. It does not write `+0x30` in the shown immediate
post-copy sequence. This distinguishes construction-time values from that
copy-path reset without assigning source-level field semantics.

The report supplies local static initializer evidence only. It does not prove
a universal writer closure, a runtime object/map-entry identity, final runtime
values, ownership, or lifetime.

