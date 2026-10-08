# x86 `src/kern/mach_fat.c` (plan 260 (S5-P246), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 260 (S5-P246). Final run `s5p246-it2`; 07 file SHA-256 `b822e4bb0e95162d7f9249b243f6484305ed3723ce39a3ac9eefd9520504af8e`; diff `x86-mach_fat.diff`.

- Object [0x15c948, 0x15ca71) 297 B, 1 functions (_fatfile_getarch). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x15ca74.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p246-it2-l1-mach_fat-F-20261002.json`). Grade **A**.

Object extent [0x15c948, 0x15ca74) 300 B (297 B text + 00 x3; front 00 x3; back before load_machfile -- boundary inferred from padding). No data. The codex review of plan 260 found no wrong claim and added that the pager result and vm_info pointer are not checked (verified). it1 (s5p246-it1) called cpu_number(); it2 (s5p246-it2) with machine_slot[0] OBJECT_MATCH, relcheck 0.

- Plan 395 (2026-10-08): `nextdev/mach-o/fat.h` is now the adopted 07 copy `07_kernel/nextdev/mach-o/fat.h` (verbatim SDK, SHA-256 equal to the real-machine list); before, staging read the local SDK mirror. Rebuild `s6l0-p395a` (mach_fat, mach_loader, kern_exec from 07, every `cc -M` dependency from 07): L1 identical to the plan 394 baseline (`09_validation/reconstruction/s6-l0-G1-s6l0-p395a.json`).
