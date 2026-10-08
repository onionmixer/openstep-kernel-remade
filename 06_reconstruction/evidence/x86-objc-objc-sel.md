# x86 `src/objc-runtime/objc-sel.m` (plan 356 (S5-P342), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "objc-sel.m" (objc.json module (none)). Final run `s5p356-r2sel`; 07 file SHA-256 `0be77d5eabe73ecaa127e83428cdc8c535ca897f9e838acd3f5924ba3a197c02`; diff `x86-objc-objc-sel.diff`.

- `__text` [0x1cffec, 0x1d0440) 1108 B, 9 functions (0 methods) ((static objc_malloc), __strhash, _sel_isMapped, _sel_getName, __sel_registerName, _sel_registerName, __sel_unloadSelectors, _sel_getUid, __sel_init). Front `89 ec 5d c3`, back `55 89 e5 83`, next function 0x1d0440.
- Sections: __TEXT,__text 1108 B given by symbol; __TEXT,__const 4 B inferred, verified by L1d; __DATA,__data 44 B inferred, verified by L1d; __TEXT,__cstring 25 B literal (references checked by content).
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p356-r2sel-l1-objc_sel-F-20261002.json`). Grade **A**.

Kernel ObjC runtime module (D045, D046, D047). Diagnostics s5p356-m1/m2/m3 (optimization level), h0/h1/p* (_POSIX_SOURCE), bexcept/hexcept/jexcept (POSIX_KERN), u* (unified flags); real-machine cc -M trace s5p356-dep3 (objc-1 headers read: 15; SDK headers adopted: mach-o/ldsyms.h, mach-o/rld.h, ansi/ctype.h, bsd/syslog.h; cthreads and dyld are textual-closure rows the compile does not read). Codex reviews of plan 356 (two rounds) and plan 357 (stage_headers components fix) verified. Final s5p356-r2sel from 07 after plan 357.
