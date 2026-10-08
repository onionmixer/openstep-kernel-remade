# x86 `src/driverkit/objc_support.m` (plan 376 (S5-P357), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 376 (S5-P357). Final run `s5p376-it1`; 07 file SHA-256 `9bac03faef40666a6501edeb93e46093d16173bcd905ea44ad7d85ac678d72bd`; diff `x86-objc_support.diff`.

- Object [0x17e1e8, 0x17e231) 73 B, 3 functions (_NXFlush, _NXPrintf, _abort). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x17e234.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p376-it1-l1-objc_support-F-20261002.json`). Grade **A**.

Kernel ObjC runtime stream/abort stubs. __text [0x17e1e8, 0x17e231) 73 B + 00 x 3 (autoconfCommon 0x17e234; vnode_pager ends at 0x17e1e8 with no fill); NXFlush, NXPrintf, abort; __DATA,__data [0x1e0f36, 0x1e0f49) 19 B ("objc: fatal error\n") verified by L1d; common NXArgv 4 B = original 0x1f7484 (__common; next _IOTask 0x1f7488). Diagnostics s5p376-os1 (bsd/stdarg.h missing), s5p376-os2 OBJECT_MATCH. Codex review of plan 376 (gpt-6.1-sol) verified (Darwin comparison source and zone-name wording). Final s5p376-it1 from 07: OBJECT_MATCH (3 MATCH), relcheck 0.
