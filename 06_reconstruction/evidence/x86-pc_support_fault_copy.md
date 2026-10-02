# x86 `machdep/i386/pc_support/PCinit.c` and `machdep/i386/fault_copy.c` (S5-P38, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Sources: Darwin 0.1
`kernel-1.tar.gz` (SHA-256 `0c19349be454d7162f497b55a7735b443f5506694215e2f3f5f026b597a54a01`), files copied
unchanged. "Verbatim" applies to these sources; the header environment includes earlier restored 07 headers.
Plan 64, 64.1, 64.2. Run IDs `s5p39-*`.

- PCinit: original [0x1a0e48, 0x1a139d) 1365 B, 7 functions, text only (59 relocations). Gaps: front 2 x `00`
  (`ret` 0x1a0e45), back 3 x `00` (`_PCexception` 0x1a13a0). The compiler prints 4 pointer/integer warnings.
- fault_copy: original [0x189a5c, 0x18a30d) 2225 B, 14 functions, text only (56 relocations). The tail
  0x18a2f8-0x18a30c (no symbol) is the `do_fault` recovery path of `_suibyte` (0x18a2da stores 0x18a2f8 as the
  recovery address). Gaps: front 0 (confirmed `dbl_fault` ends at 0x189a5c with its own `90 90`), back 3 x `00`
  (`_fp_configure` 0x18a310). L1 compares the whole `__text` section, not only the Ghidra ranges.
- Diagnostic `s5p39-pre-1` and final 07_kernel build `s5p39-build-1` give the same `-O3` objects
  (`667a6de1a60caf71…`, `024a788987295d8f…`); the variant without `-fno-common` is identical; `-O2` differs.
  OBJECT_MATCH 7/7 and 14/14. Grade **A** for both. O3 matching shows reproducibility, not that O3 was the only
  possible historical setting.
- Headers named in the line markers of the two `.i` files and adopted verbatim with this change:
  `bsd/i386/signal.h`, `bsd/sys/errno.h` (also carries a University of California notice),
  `machdep/i386/pc_support/PCmiscInline.h`, `PCprivate.h`, `PCpublic.h`. Their bytes equal the staged copies used
  by the build, so no other object is affected.
