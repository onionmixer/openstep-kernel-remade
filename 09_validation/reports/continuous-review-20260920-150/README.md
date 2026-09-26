# `+0x28`/`+0x30` whole-export offset collision audit

## Scope

Open item 1 requires actual map-entry WORD `+0x28` and object `+0x30`
lifetime, not a same-offset search across unrelated structures.  This audit
decoded every recorded export body from the original x86 bytes and counted
memory operands with the exact decoded displacement and operand width.

## Python measurement

| decoded operand pattern | accesses | functions |
|---|---:|---:|
| `word ptr [reg+0x28]` | 832 | 429 |
| `dword ptr [reg+0x30]` | 628 | 324 |
| first pattern in `_vm_`/`__vm_` named functions | 87 | 31 |
| second pattern in `_vm_`/`__vm_` named functions | 40 | 18 |

The whole-export counts include clearly unrelated callers such as TCP, RPC,
filesystem, and driver functions.  A displacement and width are therefore not
enough to identify an object or map-entry alias.  This confirms that the
earlier VM-name inventories cannot be promoted to an all-binary alias-writer
claim merely by expanding the numeric offset search.

## `_map_fd` candidate kept separate

`_map_fd` contains a non-VM-name `dword [reg+0x30]` read/write sequence:

```
0x0016579f  CALL 0x00104900
0x001657af  MOV ECX,[EAX+0x18]
0x001657b2  MOV [EBP-0x0c],ECX
...
0x0016591a  MOV ECX,[EBP-0x0c]
0x0016591d  MOV EAX,[ECX]
0x0016591f  CMP [EAX+0x30],0
...
0x00165930  MOV EDX,[ECX]
0x0016593a  MOV [EDX+0x30],EAX
```

The export labels `0x00104900` `_getf`.  Its raw body reads an indexed pointer
from absolute globals at `0x001e8758+0x150`, returns that pointer in EAX when
nonzero and not `0xffff0000`, or stores byte 9 to `[0x001e875c+0x68]` and
returns zero on its shown failure paths.  This proves the dataflow above only.
It does **not** prove that `_getf`'s `+0x18`, its dereferenced first dword, or
the final `+0x30` is a VM object.  Accordingly this candidate is not added to
the object `+0x30` writer set.

## VM-name observations

The `_vm_`/`__vm_` scan does reproduce known map-entry WORD accesses in map
creation, insert/find/pageable/delete/copy/fork/lookup functions.  It also
shows that the same displacement appears as dword fields in map reference,
clip, protect, inherit, and deallocate functions.  The names and numeric
offset alone do not provide a common structure identity.

## Limit and next requirement

This is a static operand inventory, not alias provenance.  To finish the
remaining object/map alias question, a future report must show pointer origin
from a verified allocation/template/map-entry path to each candidate access,
or explicitly establish that no such path exists.  No source/reference code
or type name is used as a substitute.
