# x86 `src/kern/miniMon.c` (plan 239 (S5-P224), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 239 (S5-P224). Final run `s5p224-it3`; 07 file SHA-256 `0f45a11a528703fe1a9b67f4dd91ec71301ab8e02eac46e332beef7a4afb0c0e`; diff `x86-miniMon.diff`.

- Object [0x1600cc, 0x160476) 938 B, 8 functions ((static mm_parse), _miniMonInit, _miniMonLoop, (static mm_continue), (static mm_help), _safe_prf, (static mm_reset), (static mm_gdb)). Front `5d c3 00 00`, back `00 00 55 89`, next symbol 0x160478.
- Final L1 `09_validation/reconstruction/s5p224-it3-l1-miniMon-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x1600cc, 0x160478) 940 B: an unnamed parser, miniMonInit, miniMonLoop, unnamed continue and help, safe_prf, unnamed reset and gdb; 0x00 fill before and after. __DATA,__data [0x1defb8, 0x1df21c): the command table (no forcegdb) and the strings (verified by L1). The codex review of plan 239 corrected two function sizes (miniMonLoop 336, safe_prf 92; adopted) and confirmed the rest. it1 failed (panicstr redeclared); it2: data matched, miniMonLoop 4 bytes short (the original pops the first two prints' arguments before the third); variants s5p224-v1 p1/p2 (a loop construct between them) match, p1 applied. it3 (s5p224-it3): __text and __data match, relcheck 0; __bss reference-inferred.
