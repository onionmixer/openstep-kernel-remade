# x86 `machdep/i386/dma.c` (S5-P44, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/dma.c`, unchanged. Plan 70, 70.1, 70.2. Run IDs `s5p45-*` (diagnostic `s5p44-pre-1`).

- Original `__text` [0x188044, 0x189745) 5889 B, 22 functions; `__data` 108 B at 0x1e1842 (symbol-placed, equal).
  Gaps: front 0 (`ret` 0x188043), back 3 x `00` (confirmed `dma_buf` at 0x189748).
- Final 07_kernel build `s5p45-build-1`: `-fno-common` `-O3` `2e601aad5503badd…` (bytes/references 0
  differences, 129 references unverified), common variant `412a0bdeb5767e08…`: 7 MATCH, 15 MATCH_UNVERIFIED only
  because of `__DATA,__bss`; both `.i` identical; `-O2` differs.
- Commons (plan 36.1 relocation correspondence): `_dma_assigned_bits` 4/4, `_dma_cmd_regs` 4/16,
  `_dma_write_regs` 16/16, `_prev_tcstatus0` 4/4, `_prev_tcstatus1` 4/12 (size/gap); 425 relocation sites with
  equal width/pcrel/type (296 same kind, 123 local -> extern, 6 scattered -> extern), bytes outside relocations
  equal. 36.1's literal OBJECT_MATCH condition is not reached because `__bss` remains.
- `__DATA,__bss` 12 B: the `static int xxx` dummies of `outb`/`outw`/`outl` (`io_inline.h:108/128/148`).
  `zerofill_check.py` (known ranges `zerofill-known-s5p45-20261002.json`): 67 references, all to offset 0, one
  delta 0x1e5e7c, candidate [0x1e75ec, 0x1e75f8), checks pass, negative check detected -> reference-inferred
  (`09_validation/reconstruction/s5p45-zerofill-check-dma-20261002.json`). The other 8 B are placed only by
  section contiguity. Object grade **P**; 7 functions high, 15 medium.
- Adopted verbatim: `bsd/i386/param.h` (also UC notice), `machdep/i386/dma.h`, `dma_inline.h`, `dma_internal.h`.
