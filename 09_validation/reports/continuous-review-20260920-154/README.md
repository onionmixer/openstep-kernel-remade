# `_pmap_enter` exported direct caller 전수와 반환값 비소비

## Scope

Open item 2's PV entry side is extended from the internal retry/lifetime work
to every exported direct unconditional caller of `_pmap_enter` (`0x0019065c`).
Python decoded the original instruction window at all nine reference sites.

## Result

All nine direct callers continue their local mapping/lock/range path without
testing, storing, or otherwise consuming EAX from `_pmap_enter` before their
next local action.  Stack adjustment timing is caller-specific and is not used
as a shared contract.

| call site | caller | immediate post-call path |
|---:|---|---|
| `0x0017344c` | `_vm_fault` | obtains `[ebp-0x4c]`, then enters an `xchg` exclusion loop |
| `0x00173800` | `_vm_fault_copy_entry` | builds `[edi+0x10]`, then enters an `xchg` exclusion loop |
| `0x00173a0c` | `_vm_fault_wire_fast` | obtains `[ebp-8]`, then enters an `xchg` exclusion loop |
| `0x001744e8` | `_kmem_mb_alloc` | advances `EDI`/`ESI` by `[0x001e0d0c]` and checks range |
| `0x00190b3a` | `_pmap_enter_shared_range` | advances range cursors by page size and loops/returns |
| `0x00194d14` | `_mmrw` | computes a residual length and calls the next helper |
| `0x0019568c` | `_createEventShmem` | advances by page size, loops, then writes output and zeroes EAX locally |
| `0x001a136d` | `_PCmapBIOSRom` | advances local address/range and loops |
| `0x001a93c5` | `_IOMapPhysicalIntoIOTask` | advances/decrements range values and zeroes EAX locally on completion |

The result is a direct instruction fact.  It does not assign a C return type
to `_pmap_enter`; it only states that these caller paths do not use its EAX.

## Relation to PV lifetime

Reports 110, 114, and 145 establish the `_pmap_enter` temporary-node retry,
PV chain, and removal/reclamation boundaries.  This report adds that the nine
exported direct caller paths proceed after enter independently of EAX, so a
caller-side rollback based on an observed enter return cannot be inferred for
this inventory.

## Limit

The inventory is limited to exported direct unconditional calls.  It does not
exclude indirect/computed callers, helper-internal failure handling, or runtime
interleavings.
