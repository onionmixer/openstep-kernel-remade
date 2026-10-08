# x86 `src/objc-runtime/except.c` (plan 356 (S5-P342), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "except.c" (objc.json module (none)). Final run `s5p356-r2exc`; 07 file SHA-256 `f99d6ed5e7df0c2fd677ebc5e2a0fd84e197a3d05762bcf8af52afad06670065`; diff `x86-objc-except.diff`.

- `__text` [0x1ca960, 0x1caeb9) 1369 B, 13 functions (0 methods) ((static addme), __threadFreeExceptionStack, (static trickyRemoveHandler), __NXAddAltHandler, __NXRemoveAltHandler, __NXAddHandler, __NXRemoveHandler, _NXSetExceptionRaiser, _NXGetExceptionRaiser, __NXRaiseError, _NXDefaultExceptionRaiser, _NXAllocErrorData, _NXResetErrorData). Front `89 ec 5d c3`, back `00 00 00 55`, next function 0x1caebc.
- Sections: __TEXT,__text 1369 B given by symbol; __DATA,__data 240 B inferred, verified by L1d; __TEXT,__cstring 65 B literal (references checked by content).
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p356-r2exc-l1-except-F-20261002.json`). Grade **A**.

Kernel ObjC runtime module (D045, D046, D047). Diagnostics s5p356-m1/m2/m3 (optimization level), h0/h1/p* (_POSIX_SOURCE), bexcept/hexcept/jexcept (POSIX_KERN), u* (unified flags); real-machine cc -M trace s5p356-dep3 (objc-1 headers read: 15; SDK headers adopted: mach-o/ldsyms.h, mach-o/rld.h, ansi/ctype.h, bsd/syslog.h; cthreads and dyld are textual-closure rows the compile does not read). Codex reviews of plan 356 (two rounds) and plan 357 (stage_headers components fix) verified. Final s5p356-r2exc from 07 after plan 357.
