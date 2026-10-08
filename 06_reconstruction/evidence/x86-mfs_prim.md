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

## plan 397·398 고침(2026-10-08)
- Darwin 0.1 kern/mapfs.c:132 `lock_data_t mfsbuf_lock;`(MACH_NBC 묶음 첫 줄)과 :1081 `int active_mfsbufs = 0;`(`extern int nmfsbuf;` 앞) 두 줄을 넣었습니다. Darwin 에서도 정의만 있고 쓰이지 않습니다. `__data` 97 → 104 B, `_active_mfsbufs` 0x1defb4(오프셋 100).
- 진단(07 손대지 않음): s6p397-mf1. 최종: 07 에서 재빌드 s6l1-g1a(행 78, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-078.json` OBJECT_MATCH, `cc -M` 의존 모두 07. 07 파일 SHA-256 `b2bce2b1a0394c52cf0c18592cc3eecede51128c110f5c59c71a0fec68603207`.
- diff `06_reconstruction/evidence/x86-mfs_prim.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: lines marked plan 397 (Darwin): Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `c7b74013bab3110d752fa5405ddd731ae1685ed8403551097e59b259d3e02518`); diff 를 다시 만들었습니다.
