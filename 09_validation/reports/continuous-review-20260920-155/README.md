# `_vm_object_shadow` output-pointer 수명과 두 direct caller의 lock 경계

## Scope

This extends open item 2's COW/shadow analysis.  Original x86 bytes establish
the callee's allocation/output-pointer sequence and both exported direct caller
sites; no C structure names are required for the result.

## Shadow callee

`_vm_object_shadow` at `0x001795a0` treats `[ebp+8]` and `[ebp+0xc]` as
pointers to caller-owned locations.  It loads the old first location value,
allocates through `0x0016b790` with global `[0x001f73b8]`, and passes the
returned pointer plus argument `[ebp+0x10]` to `0x00178ba8`.

If the allocation pointer is zero, `0x001795ca` pushes `0x001e0c05` and calls
`0x0010ca6c`; no ordinary alternate return is shown.  On the nonzero path the
raw writes are:

```
0x001795d4  MOV [ESI+0x20],EDI       ; saved old first-location value
0x001795da  MOV EDX,[[EBP+0x0c]]
0x001795dc  MOV [ESI+0x24],EDX
0x001795e2  MOV [[EBP+0x0c]],0
0x001795eb  MOV [[EBP+0x08]],ESI
```

The function then returns without writing EAX.  This is a direct pointer
replacement/offset-clear contract, not an allocation-error return contract.

## Direct callers

### `_vm_map_pageable` at `0x00175f7c`

After entry WORD `+0x28` changes from zero and flag conditions pass, it pushes
`EBX+0x10`, `EBX+0x14`, and `EBX+0x0c - [EBX+0x08]` to shadow.  It immediately
clears flag bit `0x40` at `0x00175f81` with `AND BYTE [EBX+0x18],0xbf`.
There is no EAX test after the call.

### `_vm_map_lookup` at `0x001782ed`

This caller first calls `0x0015b890` at `0x001782cc` and tests EAX at
`0x001782d7`; only zero reaches shadow.  It passes `EDX+0x10`, `EDX+0x14`, and
`EDX+0x0c - [EDX+0x08]`.  After shadow it clears the same flag bit at
`0x001782f5`, then calls `0x0015b9b0` at `0x001782fd` before its next entry
test.  Export labels these helpers `_lock_read_to_write` and
`_lock_write_to_read`; the direct call addresses and order are the evidence.

## Finding

Both callers receive shadow's result by the two argument locations, clear the
same entry flag afterward, and do not consume a shadow EAX return.  The lookup
caller has a raw read→write→shadow→write→read helper order around that update;
the pageable caller's shown local sequence contains the shadow call and flag
clear without a post-call EAX branch.

## Limit

No C type, lock ownership, helper-internal behavior, indirect caller, or
runtime allocation success claim is made.  The panic target's semantics are
not inferred from its export label.
