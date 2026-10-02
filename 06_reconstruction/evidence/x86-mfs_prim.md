# x86 `kern/mfs_prim.c` (S5-P113, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 139, 139.1, 139.2. Runs
`s5p113-diag-1` (NeXTMach as is: include failures), `s5p113-diag-2` (staged edits), `s5p113-it1` .. `s5p113-it6`
(07 file iterations), `s5p113-v1`, `s5p113-v2` (mfs_init variants). 07_kernel file SHA-256 `0fd109c115bfe5da521c815031fdecc5603fdeb048232e06f0ad46d8fd7fc88c`; diff
`x86-mfs_prim.diff` (against NeXTMach).

- Object [0x15dfe4, 0x1600ca) 8422 B, 32 functions in NeXTMach `mfs_prim.c` order with two more:
  `_mfs_fsync_invalidate` (0x15f78c) after `_mfs_fsync` and `_vmp_push_all` (0x15fe70) after `_vmp_push`.
  `objects.tsv` seq 178 (`mfs_prim.c`, ..0x15fe6e) and seq 179 (`mapfs.c`, 0x15fe70..) are one object: the fill at
  0x15fe6e is `90 90` (intra-object), at 0x1600ca `00 00`; the static at 0x1600cc belongs to miniMon.
  - Front 0 B: confirmed `x86-machine` ends at 0x15dfe4.
  - Back 2 x `00`.
- Source: NeXTMach base with restoration edits (MODIFICATIONS.md); the OPENSTEP version sits between NeXTMach and
  Darwin (`mapfs.c`, a renamed descendant): several Darwin additions are present, Darwin's later NFS/PERFMODS code is
  not, and one block (`nmfsbuf`) is in neither and was authored from the bytes.
- Iterations (sizes of differing functions, build/original): it1 `mfs_init` 212/208, `mfs_io` 972/1164; it3 `mfs_io`
  1144/1164; it4 all 30 equal; it5 32 functions, 31 MATCH, `mfs_init` register choice differs; s5p113-v1 seven
  C forms of the `mfs_map_size` clamp all differ, s5p113-v2 the Darwin `long long` expression is byte-identical.
- Final it6 (template `s5p107-build.cmd` plus `-Isrc/components/driverkit-1`): OBJECT_MATCH 32/32
  (`09_validation/reconstruction/s5p113-it6-l1-mfs_prim-F-20261002.json`); `__data` by symbol; commons
  `_mfs_alloc_lock_data` 12, `_mfs_alloc_wanted` 4, `_mfs_map` 4, `_mfs_mclean` 4, `_mfs_mdirty` 4,
  `_vm_info_lock_data` 4, `_vm_info_queue` 8, `_vm_info_zone` 4 all within the original gaps.
- Grade **A**; 32 functions high (30 NeXTMach, 2 Darwin).
