# x86 `machdep/i386/catch.c` and options `PC_SUPPORT`, `FP_EMUL`, `MACH_NBC` (S5-P50, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/catch.c`, unchanged. Plan 76, 76.1, 76.2. Run IDs `s5p49-*`.

- Options added (`06_reconstruction/config_options.tsv`, generated headers `pc_support.h`, `fp_emul.h`,
  `mach_nbc.h`): `PC_SUPPORT=1` **confirmed** by this object (below); `FP_EMUL=0` hypothesis (no `.globl` of
  `machdep/i386/fp_emul/*.s` in the original, `<fp>` not in RELEASE); `MACH_NBC=1` hypothesis (`<nbc>` in RELEASE).
- Regression `s5p49-regress-1` after the `meta_features.h` change: the 60 confirmed + 7 partial objects, 67/67
  SHA-256 equal (`08_build/runs/tools/s5p49-regress-baseline.json`).
- Original `__text` [0x186fdc, 0x187108) 300 B, `_catch_interrupt`, `_catch_trap`; text only, 8 references.
  The `#if PC_SUPPORT` branches (lines 40, 52, 65) inline `threadPCInterrupt`/`threadPCException`
  (`PCmiscInline.h`), which call `_PCcallMonitor` and `_PCexception`; these references match the original, so
  `PC_SUPPORT=0` cannot give these bytes (no separate 0 build was made).
- Final 07_kernel build `s5p49-build-1`: `-O3` = `-O2` = variant = `23bd2de7b9c60217…`; both `.i` identical;
  OBJECT_MATCH 2/2. Gaps: front 1 x `00` (`ret` 0x186fda), back 0 (`__bios32` 0x187108). Grade **A**.
