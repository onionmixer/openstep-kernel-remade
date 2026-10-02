# x86 `machdep/i386/miniMonMachdep.c` (S5-P42, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/miniMonMachdep.c`, unchanged. Plan 68, 68.1, 68.2. Run IDs `s5p43-*`.

- Original `__text` [0x185e04, 0x1860dc) 728 B, 8 functions: static `miniMonDump` [0x185e04, 0x185fb0) (no symbol
  in the original), `_miniMonReboot` … `_miniMonPutchar` (0x185fb0-0x18604c), static `miniMonBacktrace`
  [0x18604c, 0x1860dc). Placement by the six public symbols (one delta). `__data` 129 B at 0x1e1728
  (`_miniMonMDCommands`, 6 relocations, L1d equal). Gaps: front 1 x `00` (`ret` 0x185e02), back 0 (`_start`
  0x1860dc). objects.tsv's 0x185fb0 start was only a lower bound from named symbols.
- Final 07_kernel build `s5p43-build-1`: `-O3` = variant = `51b24681010a0673…` (= diagnostic); both `.i` identical;
  `-O2` differs. 7 MATCH, `miniMonDump` MATCH_UNVERIFIED only because of `__DATA,__bss`.
- `__DATA,__bss` 4 B (`static unsigned int *ptr`, line 103): `zerofill_check.py` with the refreshed known-range
  file `09_validation/reconstruction/zerofill-known-s5p43-20261002.json` (adds kern_notify) — 5 references, one
  delta 0x1e7244, candidate [0x1e75a0, 0x1e75a4), all checks pass, negative check detected ->
  **reference-inferred** (`09_validation/reconstruction/s5p43-zerofill-check-miniMonMachdep-20261002.json`).
  Object grade **P**; `miniMonDump` medium, the other 7 high.
- Adopted verbatim: `kern/miniMonPrivate.h` (named in the `.i` line markers).
