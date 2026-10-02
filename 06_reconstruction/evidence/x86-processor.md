# x86 `kern/processor.c` (S5-P39, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kern/processor.c`, unchanged (SHA-256 `f8c6d2a0d8e6183553825699b80002447c43e4b17fe72ae0acf2df2c768ef769`).
Plan 65, 65.1, 65.2. Run IDs `s5p40-*`. Options used: `MACH_HOST=0`, `NCPUS=1`, `MACH_FIXPRI=1` (confirmed).

- Original `__text` [0x161134, 0x161e5a) 3366 B, 27 functions; `__data` 74 B at 0x1df228. Gaps: front 2 x `00`
  (confirmed `priority` ends at 0x161132), back 2 x `00` (`_enqueue_head` 0x161e5c).
- Final 07_kernel build `s5p40-build-1` (= probe 1 = diagnostic): `-fno-common` `-O3` `7e6688b3ec11f686…`
  (bytes and references 0 differences, `__common` 732 B ambiguous), common variant `8a5034b88c52c9f9…`
  OBJECT_MATCH 27/27, 55 references; both `.i` identical; `-O2` differs.
- Plan 36.1: 55 relocation positions with equal width/pcrel/type; 8 scattered VANILLA -> extern and 16 local ->
  extern (all to common symbols), 15 external relocations differ only in symbol index (same name and addend),
  16 identical; bytes outside relocations equal. Commons (size/gap): `_all_psets` 8/8, `_all_psets_count` 4/16,
  `_all_psets_lock` 4/8, `_default_pset` 380/380, `_master_processor` 4/4, `_processor_array` 328/336,
  `_processor_ptr` 4/4 (upper-bound consistency). Grade **A**.
