# `_vm_map_deallocate` direct caller lock-candidate CFG inventory

## Scope

This expands reports 116, 137, 138, and 144 for open item 2.  It decodes the
original x86 bodies of all 27 exported functions containing the 37 direct,
unconditional calls to `_vm_map_deallocate` at `0x001747d8`.  It does not
equate a memory `xchg` with a lock type without the surrounding byte sequence.

## Python raw-byte scan

The scan used each export body's recorded segments, decoded them with Python
Capstone/x86-32, deduplicated instruction heads by address, and considered
these direct lock API targets:

`_lock_write`, `_lock_done`, `_lock_read`, `_lock_read_to_write`,
`_lock_write_to_read`, `_lock_try_write`, `_lock_try_read`,
`_lock_try_read_to_write`, `_lock_set_recursive`, `_lock_clear_recursive`,
`_KernLockAcquire`, and `_KernLockRelease`.

It found zero direct calls to those 12 targets in every one of the 27 caller
bodies.  It found memory-operand `xchg` in 3 caller functions.  After building
a conservative CFG from direct intra-body branches, 35 of 37 call sites are
reachable from their function entry through resolved direct edges.  Two sites
in `_table` are not entry-reachable in that restricted graph because its export
body is fragmented; no dominance conclusion is made for them.

For the 35 resolved sites, memory `xchg` dominates only two call sites:

| caller / call | dominating raw `xchg` instructions |
|---|---|
| `_task_deallocate` `0x00165c5c` | `0x00165c07`, `0x00165c1c`, `0x00165c37`, `0x00165c4c` |
| `_task_terminate` `0x00165fe2` | `0x00165f07`, `0x00165f64`, `0x00165f83`, `0x00165f98`, `0x00165fb7`, `0x00165fd2` |

The other 33 resolved sites have neither a dominating memory `xchg` nor a
direct call to one of the listed lock APIs in their decoded caller body.  This
is an inventory fact, not proof that those paths execute without synchronization:
an unclassified helper, indirect call, caller outside the export model, or
runtime dispatch remains possible.

## Raw task-path order

`_task_deallocate` checks its argument, spins on `[ebx]`, acquires it at
`0x00165c07`, decrements `[ebx+4]`, releases `[ebx]` at `0x00165c1c`, and
returns on a nonzero decremented value.  Its zero path reads `[ebx+0x2c]`,
spins/acquires `[esi+0x158]` at `0x00165c37`, calls `0x00161504`, releases the
same offset at `0x00165c4c`, calls `0x001616f0`, then pushes `[ebx+0x0c]` and
calls `_vm_map_deallocate` at `0x00165c5c`.

`_task_terminate` reaches its deallocate call after the analogous final task
reference-zero path: acquire `[esi]` at `0x00165f83`, decrement `[esi+4]`,
release `[esi]` at `0x00165f98`, acquire `[task+0x158]` at `0x00165fb7`, call
`0x00161504`, release `[task+0x158]` at `0x00165fd2`, call `0x001616f0`, then
push `[esi+0x0c]` and calls `_vm_map_deallocate` at `0x00165fe2`.

The `xchg` instructions earlier in `_task_terminate` belong to other control
paths or loops.  Only the listed dominance result is used for this call site.

## Limit

This reduces the direct-caller lock-order gap but does not complete open item
2.  In particular it does not establish helper-internal locking, indirect or
computed callers, rollback of every caller-local side effect, or runtime path
reachability.
