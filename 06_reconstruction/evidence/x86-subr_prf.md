# x86 `src/bsd/kern/subr_prf.c` (plan 220 (S5-P198), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 220 (S5-P198). Final run `s5p198-it2`; 07 file SHA-256 `7a8e5c059553043456eec742e2139c931398e529494c4c98e19e6434afdc9e1a`; diff `x86-subr_prf.diff`.

- Object [0x10c0d8, 0x10cca4) 3020 B, 18 functions (_printf, _uprintf, _tprintf, _sprintf, _log, _vlog, (static logpri), __printf, _prf, (static puts), (static printn), _panic_init, _panic, _tablefull, _harderr, _putchar, _logchar, (static tputchar)). Front `ec 5d c3 00`, back `55 89 e5 b8`, next symbol 0x10cca4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p198-it2-l1-subr_prf-F-20261002.json`). Grade **A**.

Object extent [0x10c0d8, 0x10cca4): linker 0x00 fill before 0x10c0d8 (after subr_log); subr_xxx starts at 0x10cca4. Diagnosis 13 failed on mach_ldebug.h, next/printf.h and mon/global.h; diagnosis build s5p198-d1 (NeXTMach text without them, not 07) clashed with the SDK stdarg prototypes and lacked struct reg_desc (found in SDK kernserv/printf.h). The codex review of plan 220 found no wrong fact; the %r recursion through _printf was confirmed from the bytes (0x10c824). Iterations: it1 all sizes match except sprintf (local copy of the target pointer, original 0x10c192); it2 all 18 functions match, extern relocation names match (relcheck 0).
