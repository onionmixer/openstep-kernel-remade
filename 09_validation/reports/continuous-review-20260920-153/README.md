# `_vm_fault` direct caller의 nonzero 결과 전달 경계

## Scope

Reports 107, 119, and 136 established `_vm_fault` return ingress and its five
exported direct unconditional callers.  This report follows each call's raw
nonzero/zero branch beyond the first test.  It supplies the direct-caller part
of open item 2's error-propagation requirement; status names are not inferred.

## Raw caller paths

| caller / call | raw nonzero handling | raw zero handling |
|---|---|---|
| `_vm_fault_wire` `0x001735d5` | no EAX test or store | after stack cleanup it advances by `[0x001e0d0c]`, compares loop bound, and continues/retires; EAX is unused |
| `_user_trap` `0x00192000` | stores EAX to `[ebp-0x14]`, sets local `[ebp-0x1c]` from it, pushes that local and constant 1, then calls `0x001569c0` | jumps directly to `0x00192065` |
| `_kernel_trap` `0x001921e7` | stores EAX at `[ebp-0x0c]`; it first calls `0x001924a0`.  When that helper returns zero, one shown branch pushes `[ebp-0x0c]` to `0x00156aac`; other local condition branches also feed the later trap path. | jumps `0x001923d3` from the immediate comparison |
| `FUN_001923e0` `0x0019242d` | none | restores the frame and `RET`s without an EAX write, so callee EAX is preserved |
| `_PCexception` `0x001a143c` | moves EAX to EDX; stores it at `[ebx+0x54]`; pushes EDX and calls `0x001568d8`; later checks `[ebx+0x54]` before continuation/return dispatch | jumps to `0x001a14dc` |

The export labels the three helper addresses `_exception`, `_exception_from_kernel`,
and `_exception_with_continuation`.  The table's factual claim depends only on
their direct `CALL` addresses and the preceding pushed/stored value.

## Key instruction sequences

### User trap

```
0x00192000  CALL 0x00172038
0x00192005  MOV [EBP-0x14],EAX
0x00192017  CMP [EBP-0x14],0
0x0019201d  MOV ECX,1
0x00192022  MOV EDI,[EBP-0x14]
0x00192025  MOV [EBP-0x1c],EDI
0x00192057  PUSH EBX
0x0019205b  PUSH EDI
0x0019205c  PUSH ECX
0x0019205d  CALL 0x001569c0
```

### PC exception

```
0x001a143c  CALL 0x00172038
0x001a1441  MOV EDX,EAX
0x001a1451  TEST EDX,EDX
0x001a1459  MOV ECX,[ESI+0x30]
0x001a145c  MOV [EBX+0x4c],ECX
0x001a1465  MOV [EBX+0x54],EDX
0x001a146e  PUSH EDX
0x001a1471  CALL 0x001568d8
```

## Finding

The five direct callers have four distinct result contracts: ignored by the
wire loop, handed to an exception call through a local, conditionally handed
through kernel-trap helper/exception paths, returned unchanged, or retained in
a PCexception structure and handed to a continuation helper.  A single
success/failure contract cannot be assigned to `_vm_fault` callers.

## Limit

The report does not claim the semantic meaning of any numeric status, the
helper-internal fate of its arguments, dynamic/indirect callers, or runtime
reachability.  Report 151 separately rules out only preinitialized function
pointer tables for `_vm_fault`.
