# x86 `pc_support/PCemulateREAL.c` and `PCemulatePROT.c` (S5-P43, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Sources: Darwin 0.1
`kernel/machdep/i386/pc_support/PCemulateREAL.c`, `PCemulatePROT.c`, unchanged. Plan 69, 69.1, 69.2. Run IDs
`s5p44-*` (diagnostic `s5p44-pre-1`). Neither source reaches `machine/limits.h` (plan 40 rule).

- PCemulateREAL: `__text` [0x1a1b60, 0x1a2b3e) 4062 B, 12 functions (11 static, no original symbols;
  `_PCemulateREAL` public), 31 references. `__data` 1024 B at 0x1e4b80 (static `inst_table`, line 771): placed by
  its single incoming reference (`__text` 0xaf3), all 1024 bytes including 6 relocated function pointers equal
  (L1d). Gaps: front 3 x `00` (`ret` 0x1a1b5c), back 2 x `00`.
- PCemulatePROT: `__text` [0x1a2b40, 0x1a3d0a) 4554 B, 5 functions (4 static at 0x1a2b40, 0x1a2fc8, 0x1a3160,
  0x1a37c0; `_PCemulatePROT` 0x1a3ac4 = start + 0xf84), 33 references, no data. Gaps: front 2 x `00`, back
  2 x `00` (`_IOGetObjectForDeviceName` 0x1a3d0c).
- Final 07_kernel build `s5p44-build-1`: `-O3` = variant: REAL `c9b6238b64b3f3c5…`, PROT `5f1b78e346a9d036…`
  (= diagnostic); both `.i` identical per file; `-O2` differs. OBJECT_MATCH 12/12 and 5/5. Grade **A** for both.
- Adopted verbatim (named in the `.i` line markers): `machdep/i386/err_inline.h`,
  `machdep/i386/pc_support/PCtaskInline.h`.
