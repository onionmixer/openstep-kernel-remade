# x86 `machdep/i386/vm_machdep.c` (S5-P49, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/vm_machdep.c`, unchanged; `--nextdev` (D018). Plan 75, 75.1, 75.2. Run IDs `s5p48-*`.

- Original `__text` [0x193e58, 0x193f31) 217 B, `_pagemove`, `_kernacc`. Gaps: front 2 x `00` (`ret` 0x193e55),
  back 3 x `00` (`_probeNativeDevices` 0x193f34).
- `__data` 9 B (`"pagemove"`) at 0x1e294a: placed by its single incoming reference (operand at 0x193e6d), all
  bytes equal (L1d).
- `__TEXT,__const` 4 B `18 00 20 00`: no incoming relocation of any kind; `TSS_SEL`/`LDT_SEL` operands of the
  unused `ltr()`/`lldt()` inlines, as in `intr.c` and `PCresume.c` -> unplaceable, grade **P**; both functions high.
- Final 07_kernel build `s5p48-build-1`: `-O3` = `-O2` = variant = `760ab32fff66370b…` (= diagnostic); both `.i`
  identical.
- Adopted verbatim: `bsd/sys/buf.h`, `bsd/sys/queue.h`, `bsd/sys/vm.h`, `bsd/sys/vmmeter.h`.
