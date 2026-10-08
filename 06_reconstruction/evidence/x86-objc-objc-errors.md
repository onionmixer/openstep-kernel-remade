# x86 `src/objc-runtime/objc-errors.m` (plan 356 (S5-P342), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "objc-errors.m" (objc.json module (none)). Final run `s5p356-r2err`; 07 file SHA-256 `37ec3336f27478833726b0bf28d30797ad54e71f674c8c481494823f710b9e03`; diff `x86-objc-objc-errors.diff`.

- `__text` [0x1cdd10, 0x1cde3f) 303 B, 5 functions (0 methods) (___objc_error, __NXLogError, __objc_error, __objc_fatal, __objc_inform). Front `5d c3 00 00`, back `00 1c bb 1c`, next function 0x1cde40.
- Sections: __TEXT,__text 303 B given by symbol; __TEXT,__cstring 52 B literal (references checked by content).
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p356-r2err-l1-objc_errors-F-20261002.json`). Grade **A**.

Kernel ObjC runtime module (D045, D046, D047). Diagnostics s5p356-m1/m2/m3 (optimization level), h0/h1/p* (_POSIX_SOURCE), bexcept/hexcept/jexcept (POSIX_KERN), u* (unified flags); real-machine cc -M trace s5p356-dep3 (objc-1 headers read: 15; SDK headers adopted: mach-o/ldsyms.h, mach-o/rld.h, ansi/ctype.h, bsd/syslog.h; cthreads and dyld are textual-closure rows the compile does not read). Codex reviews of plan 356 (two rounds) and plan 357 (stage_headers components fix) verified. Final s5p356-r2err from 07 after plan 357.
