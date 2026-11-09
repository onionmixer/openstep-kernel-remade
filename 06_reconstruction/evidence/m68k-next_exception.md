# m68k `src/machdep/m68k/next_exception.c` (plans 601-602, D013, D103, D104, D135, 2026-10-30)

Original `03_original/m68k/binaries/mach_kernel`. 07 file `07_kernel/src/machdep/m68k/next_exception.c`, SHA-256 `8605f15d93e4688527e54d866a40a96a1cea152722eb309bee31b5e3099e1d0c` (54 lines): NeXTMach mk-108.1 `next/next_exception.c` (https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e, SHA-256 `24352d99…`, 47 lines; notice and HISTORY kept, D013) with one plan 602 comment block and the three include lines `<sys/boolean.h>`, `<sys/exception.h>`, `<sys/kern_return.h>` written `<mach/boolean.h>`, `<mach/exception.h>`, `<mach/kern_return.h>` (D104; the `sys/` paths are not in the stage), marked plan 602 (diff `m68k-next_exception.diff`). The function text is unchanged (user decision D135).

What the original bytes show:
- Row `m68k-301` [0x4094ab2, 0x4094afe), 76 B (exact row, kind `unassigned`), one entry `_machine_exception`: exception 2 -> signal 4, 3 -> 8, 4 -> 7 with `*unix_code = code`, return 1; otherwise return 0 — `EXC_BAD_INSTRUCTION`/`SIGILL`, `EXC_ARITHMETIC`/`SIGFPE`, `EXC_EMULATION`/`SIGEMT` (stage `mach/exception.h:72,75,78`, `bsd/sys/signal.h:41,58,62`). No data, no strings.

Validation:
- Diagnostic run `m4p601-p1` N1 (the NeXTMach text with the three include lines): exit 0, no warning, `__text` 76 only, 1/1 (`m4-m68k-funcbytes-p601-N1-20261030.json`), L1 OBJECT_MATCH without reason, full span; no local, COMMON or undefined symbol.
- Stage, M5 and x86 regression: as in `m68k-miniMonMachdep.md` (the two files were added together, plan 602).
- Run `m4p602-p1`: F (07 file) and L (N1 with alignment comment lines, `08_build/artifacts/m4p602/src/next_exception_L.c`) exit 0, no warning, OBJECT_MATCH, 1/1 (`m4-m68k-funcbytes-p602-ne-F/L-20261030.json`); F = L in canon and every `obj_sig` field (STABS 87), L = N1; F and L bytes differ only in the string table and `n_strx`.
- Final run `m4p602-a1` (`m4-m68k-p602-final-20261030.json`, shared with `miniMonMachdep`): `gate.ok`, 1/1 (`m4-m68k-funcbytes-p602-ne-a1-20261030.json`). Checks `m4-m68k-p602-checks-20261030.json`: `__text` 76 only, external definition `_machine_exception` = the original name, no local, COMMON or undefined symbol, compile command equal to the M5 line, 22 dependency files, chain without problem, no i386 header. Object SHA-256 `56b13b305c969f80df3e7049e40bc8c3c48c81a4cb1517edeaea0cef38698c9b`.
- M7 obligations: `machine_exception` is called by `uxkern/ux_exception.c` (M5); on x86 the same function is in `machdep/i386/unix_signal.c`.
