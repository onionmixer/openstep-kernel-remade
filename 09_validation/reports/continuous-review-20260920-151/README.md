# 핵심 VM entry의 preinitialized function-pointer 부재

## Scope

This addresses the static table branch of the indirect/computed-caller gap in
open item 2.  Python searched the complete original file for each target's
little-endian 32-bit virtual address, then classified each occurrence against
Mach-O file-backed sections and `LC_SYMTAB` ranges.

## Result

For all ten targets below, the complete file has exactly one matching byte
sequence.  It is the target's own `LC_SYMTAB` nlist value.  There are zero
matches in every file-backed `__TEXT`, `__DATA`, or `__OBJC` section, and zero
other matches.

| target | entry address | file occurrences | file-backed pointer occurrences | nlist occurrences |
|---|---:|---:|---:|---:|
| `_vm_fault` | `0x00172038` | 1 | 0 | 1 |
| `_vm_map_copy` | `0x00176888` | 1 | 0 | 1 |
| `_vm_map_fork` | `0x00177a74` | 1 | 0 | 1 |
| `_vm_map_deallocate` | `0x001747d8` | 1 | 0 | 1 |
| `_vm_object_shadow` | `0x001795a0` | 1 | 0 | 1 |
| `_vm_object_copy` | `0x001793b0` | 1 | 0 | 1 |
| `_vm_fault_copy_entry` | `0x0017369c` | 1 | 0 | 1 |
| `_pmap_create` | `0x0018f644` | 1 | 0 | 1 |
| `_pmap_enter` | `0x0019065c` | 1 | 0 | 1 |
| `_pmap_remove_all` | `0x0018fb0c` | 1 | 0 | 1 |

`LC_SYMTAB` starts at file offset `1015808`, has 3,751 entries of 12 bytes,
and begins its string table at file offset `1060820`; those values were parsed
from the original load command with Python.  Each matching nlist entry has
the expected function value.

## Consequence

There is no preinitialized, file-backed table or immediate-address data pointer
to these ten entry addresses.  Thus a static table selected from the original
file cannot be the source of an indirect call to them.  This strengthens the
earlier direct-caller inventories, but does not make them whole-caller proofs.

## Limit

The result cannot exclude a BSS slot initialized at runtime, arithmetic that
constructs an address without embedding its full 32-bit value, a copied code
pointer, or an indirect call reached through unexamined runtime input.  It also
does not classify every indirect call in the kernel.  Those remain distinct
from preinitialized table dispatch.
