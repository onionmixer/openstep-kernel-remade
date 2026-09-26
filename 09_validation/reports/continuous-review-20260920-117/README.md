# 117차 연속 검토 — vm_map_copy return values, lock order, direct callers

## 판정

`_vm_map_copy` has a common tail that loads EAX from local `[EBP-0x24]` and returns. Raw stores
establish values 0, 1, 2, and 3 for that local. A boundary-overflow path separately puts EAX=3
and jumps directly to the return cleanup tail. These values are recorded as machine-level status
values only; semantic names are not inferred.

For unequal map arguments, the body compares the second pointer with the first before calling
`_lock_write`: one branch calls the second then first, and the other calls first then second.
Its common cleanup calls `_lock_done` on the second argument and, when distinct, on the first.
This is a direct instruction order, not proof that all called helpers preserve a global lock
discipline.

The original reference export has 13 direct unconditional call sites in 11 caller functions.
They include `_vm_map_fork`, `_vm_move`, `_vm_read`, `_vm_write`, `_vm_copy`, and the recursive
site in `_vm_map_copy`; all addresses are listed in the JSON evidence.

## 원시 검증

Python Capstone x86/32 checked 14 instructions for early EAX=3, four selected lock calls,
status stores, cleanup calls, EAX reload, and `RET`. All matched original bytes.

See [`map-copy-contract-evidence.json`](map-copy-contract-evidence.json).

## 미해결

The precise meaning of each status value, entry-level partial effects before status 1/2/3,
helper-internal locking, indirect callers, and rollback behavior in each of the 11 caller
functions remain open.
