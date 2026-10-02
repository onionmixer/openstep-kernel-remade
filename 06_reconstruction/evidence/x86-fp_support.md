# x86 `machdep/i386/fp_support.c` and `FP_EMUL=0` (S5-P51, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/fp_support.c`, unchanged (options from `07_kernel/generated`, `--nextdev`). Plan 77, 77.1,
77.2. Run IDs `s5p50-*`.

- Original `__text` [0x18a310, 0x18a902) 1522 B, 10 functions: 7 with original symbols and static `fp_save`,
  `fp_switch`, `fp_unowned` (no original symbols); ranges keyed by object symbols (10/10). Gaps: front 3 x `00`
  (confirmed `fault_copy` ends at 0x18a30d), back 2 x `00` (`_locate_gdt` 0x18a904).
- Final 07_kernel build `s5p50-build-1`: `-O3` = `-O2` = variant = `d90a0d6c22b395ea…`; both `.i` identical.
  3 MATCH (`_fp_configure`, `_fp_noextension`, `_fp_ast`), 7 MATCH_UNVERIFIED only because of `__DATA,__bss`.
- `__TEXT,__const` 4 B `18 00 20 00`: no incoming relocation (ltr/lldt selector operands) -> unverified.
- `__DATA,__bss` 4 B (static `fp_thread`, line 57): `zerofill_check.py` (known `zerofill-known-s5p50-20261002.json`)
  9 references (offset 0), one delta 0x1e7000, candidate [0x1e75f8, 0x1e75fc) directly after dma's
  [0x1e75ec, 0x1e75f8) (dma also precedes in `__text`), negative check detected -> reference-inferred
  (`09_validation/reconstruction/s5p50-zerofill-check-fp_support-20261002.json`). Grade **P**; 3 high, 7 medium.
- `FP_EMUL=0` confirmed: with 1 the source adds an `FPU_EMUL` store (line 120) and an `e80387` call (line 158);
  the functions holding them are full MATCH with 0, and the original has no `_e80387`.
- Adopted verbatim: `mach/exception.h`, `mach/i386/exception.h`, `mach/machine/exception.h`,
  `machdep/i386/configure.h`, `machdep/i386/fp_exported.h`, `machdep/i386/fp_inline.h`.
