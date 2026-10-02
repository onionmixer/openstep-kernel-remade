# x86 `vm/vm_mem_region.c` (S5-P19, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/vm/vm_mem_region.c`, verbatim. Plan 44, 44.1, 44.2.

- Original object `__text` [0x1787c4, 0x1789cf) 523 B: `_vm_mem_ppi`, `_vm_valid_page`, `_vm_phys_to_vm_page`,
  `_vm_region_to_vm_page` (inlines the previous function), `_vm_alloc_from_regions`; `__data` strings
  `"mem_ppi"`, `"vm_mem_alloc_from_regions"` at [0x1e0b14, 0x1e0b36) 34 B. Front 3 x `00` after
  `_vm_map_pmap_EXTERNAL` (0x1787c1), back 1 x `00`, next `_vm_object_init` 0x1789d0.
- Builds `s5p19-pre-1` (Darwin) and `s5p19-build-1` (07_kernel) identical. `-O3` = `-O4` (object SHA-256 `87f5af9877c1940779eb1c5122ee55e2c4c96d977809ddd52f0ad6bdfdbc7177`),
  `-O2` differs (435 B).
- L1 `-O3`: OBJECT_MATCH, 5/5 MATCH, 0 byte differences, 27 references; `__data` placed and verified (L1d).
- Grade **A**. 07_kernel: 48 files read, 47 present, 1 adopted.
