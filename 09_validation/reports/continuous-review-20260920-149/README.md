# `_vm_map_copy` 13 direct caller의 post-status 전이

## Scope

This extends the 13 direct unconditional call sites recorded in reports 117
and 124.  Python/Capstone decoded original bytes from each call through its
first status branch and immediate cleanup/handoff.  “nonzero” below is the raw
`TEST`/branch condition; no error-number meaning is inferred.

## Original-byte results

| call site | immediate nonzero path | zero / unconditional path |
|---|---|---|
| `_table` `0x001024cb` | calls `0x001745b4`, then `_vm_map_deallocate` at `0x001024f7`, jumps `0x0010281c` | calls `_vm_map_deallocate` at `0x00102505`, then continues local work |
| `_smmap` `0x00107105` | pushes `ESI`, calls `_vm_map_deallocate` `0x00107114`, stores `BL` to `[global+0x68]`, jumps `0x001071c1` | calls `_vm_map_deallocate` `0x00107129`, then continues |
| `FUN_0015ce08` `0x0015cf8a` | calls `0x0017c620`, calls `_vm_map_deallocate` `0x0015cfb3`, sets `EAX=4`, jumps `0x0015d0c8` | enters the next local setup at `0x0015cfc4` |
| `FUN_0015ce08` `0x0015cffc` | after an unconditional `0x0017c620`, calls `_vm_map_deallocate` `0x0015d028`, sets `EAX=4`, jumps `0x0015d0c8` | starts the next `_vm_map_copy` setup at `0x0015d038` |
| `FUN_0015ce08` `0x0015d050` | unconditional `_vm_map_deallocate` at `0x0015d05b`, then sets `EAX=4` and jumps `0x0015d0c8` | same unconditional deallocate, then continues at `0x0015d070` |
| `FUN_0015d3fc` `0x0015d51c` | sets `EBX=5`; later calls `_vm_map_deallocate` `0x0015d55a` and returns `EBX` | may update local accounting, then the same deallocate/return tail |
| `_map_fd` `0x001658ef` | conditionally calls `0x0017c620`; both branches call `_vm_map_deallocate` `0x00165915`, then return saved `EBX` | the same deallocate; follows with the observed `+0x30` initialization/check before return |
| recursive `_vm_map_copy` `0x001778a2` | no immediate EAX test; conditionally clears recursive locks based on pointer comparisons | same pointer-comparison/recursive-clear sequence |
| `_vm_map_fork` `0x00177e1a` | calls `0x0010c0d8`, then jumps `0x00177ff0` | enters local map-fork work at `0x00177ff0` |
| `_vm_move` `0x00178778` | calls `0x0017c620`, then returns saved `EBX` | writes its output and returns saved `EBX` |
| `_vm_read` `0x0017c82d` | may call `_vm_map_remove` `0x0017c874`, then returns saved local EAX | writes two output locations and returns saved local EAX |
| `_vm_write` `0x0017c8d1` | none before epilogue | immediate epilogue retains EAX |
| `_vm_copy` `0x0017c933` | none before epilogue | immediate epilogue retains EAX |

The targets in the table are export labels only.  The direct `CALL` addresses,
tests, assignments, branch targets, and return-register moves are the actual
evidence.

## Consequence for open item 2

The direct callers do not share one rollback contract.  Several call cleanup
or deallocation helpers before a local handoff; two wrappers preserve EAX
directly; some replace the observed nonzero value with a local constant; and
the recursive internal caller handles recursive locks without an immediate EAX
test.  Any future caller-wide conclusion must retain this split.

## Limit

This report does not prove helper semantics, memory ownership, all subsequent
effects after a join target, indirect/computed callers, or transaction-wide
rollback.  It only fixes the original-byte post-call transitions listed above.
