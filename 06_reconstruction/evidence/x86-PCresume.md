# x86 `machdep/i386/pc_support/PCresume.c` (S5-P40, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/pc_support/PCresume.c`, unchanged (SHA-256 `8bdafe08213fbab2…`). Plan 66, 66.1, 66.2.
Run IDs `s5p41-*` (diagnostic `s5p39-pre-1`).

- Original `__text` [0x1a15c4, 0x1a19c7) 1027 B, 5 functions (`_PCresume`, `_PCcallMonitor`, `_PCbopFA`, `_PCbopFC`,
  `_PCbopFD`). Gaps: front 1 x `00` (`ret` 0x1a15c2), back 1 x `00` (code at 0x1a19c8 equals the first 56 B of the
  Darwin `PCtimers.c` build: statics `PCpendTimeout`, `PCpendTick`).
- Final 07_kernel build `s5p41-build-1`: `-O3` = `-O2` = variant = `0c48d41a196b2f19…` (= diagnostic); both `.i`
  identical; `__text` 1027 B, 9 external references, 5/5 MATCH, byte and reference differences 0.
- `__TEXT,__const` 4 B `18 00 20 00`: no symbol, no relocation (general or scattered) targets it; it is the
  memory operand of `TSS_SEL`/`LDT_SEL` in the unused inlines `ltr()`/`lldt()` (`cpu_inline.h:126-142`), as in
  `intr.c` (`x86-intr.md`). Unplaceable -> listed as unverified; object grade **P** (README:24), functions high.
- Adopted verbatim with this change: `machdep/i386/sel_inline.h` (named in the `.i` line markers, bytes equal to
  the staged copy).
