# x86 `vm/vm_map.c` (S5-P65, S5-P100..S5-P103, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 91.2, 126-129 (126.1, 126.2, 127.1, 127.2, 128.1, 128.2, 129.1). Run IDs
`s5p65-pre-vm_map`, `s5p100-pre-vm-map`, `s5p101-probe-vm-map`, `s5p102-probe-vm-map`, `s5p103-build-1`.
07_kernel file SHA-256 `60f220c6d5b0162256c2cb7eeb97cadd4eaa8ede8126a91a5e77a6698090a1ca`; diff `x86-vm_map.diff` (probe diffs `x86-vm_map-probe1/2.diff`).

- Original `__text` [0x174600, 0x1787c1) 16833 B, 29 functions.
  - Front 0 B after `_kmem_free_wakeup` (`ret` 0x1745ff, vm_kern not adopted).
  - Back 3 x `00` (confirmed `x86-vm_mem_region` at 0x1787c4).
- Darwin additions removed:
  - `vm_map_find_entry` and `vm_map_reallocate`.
  - `host_vm_region`, under `MACH_DEBUG`, absent from the original although other MACH_DEBUG functions exist.
  - The submap recursion in `vm_region`.
- NeXTMach forms:
  - `vm_region`.
  - `vm_map_insert` locals; with them GCC inlines `vm_map_insert` into `vm_map_find` and `vm_map_copy` as the
    original does.
  - `printf` in `vm_map_fork`.
- Final build `s5p103-build-1` (s5p99 `-g` template):
  - Common variant OBJECT_MATCH 29/29 (355 references).
  - `__data` 161 B inferred at 0x1e0a73 and verified by L1d.
  - Plan 36.1 for `-O3`: 355 relocations correspond, bytes outside equal; 4 commons <= gaps.
- Grade **A**; 29 functions high. All 50 files named in `vm_map.i` exist in 07_kernel.
