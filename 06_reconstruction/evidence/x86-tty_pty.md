# x86 `src/bsd/kern/tty_pty.c` (plan 189 (S5-P162), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 189 (S5-P162). Final run `s5p162-it2`; 07 file SHA-256 `0e4221cc50d01f9cd569e87c260808ce7bdf04acb181d6cf2c369bd0b5a785dd`; diff `x86-tty_pty.diff`.

- Object [0x111c00, 0x112dad) 4525 B, 16 functions (_pty_init, _pty_alloc, _ptsopen, _ptsclose, _ptsread, _ptswrite, _ptsselect, _ptsstart, _ptcwakeup, _ptcopen, _ptcclose, _ptcread, _ptsstop, _ptcselect, _ptcwrite, _ptyioctl). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x112db0.
- Final L1 `09_validation/reconstruction/s5p162-it2-l1-tty_pty-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x111c00, 0x112db0) (code ends 0x112dad, 3 bytes of padding). The codex review of plan 189 found nothing new beyond the plan except the zero-extended l_rint byte; the darwin01 u_char cp = NULL declaration explains it and the dead xor edi,edi. Iterations: it1 15/16 functions equal in size, diffs in ptcclose (pti loaded from the table before psp) and ptsstop (the inlined ptcwakeup needs a separate s per direction); it2 all 16 functions MATCH_UNVERIFIED only because of the unsymbolled __bss table; ptyioctl's 1145 vs 1148 is end padding. Diagnostic compile without POSIX_KERN exit 0.
