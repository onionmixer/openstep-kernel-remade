# x86 `src/bsd/kern/kern_xxx.c` (plan 195 (S5-P168), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 195 (S5-P168). Final run `s5p168-it1`; 07 file SHA-256 `023f40702a2d89939a05a25c79b2f8b26a09c640f902288c369a67d24230d7db`; diff `x86-kern_xxx.diff`.

- Object [0x10b600, 0x10b7cc) 460 B, 7 functions (_gethostid, _sethostid, _gethostname, _sethostname, _getdomainname, _setdomainname, _reboot). Front `89 ec 5d c3`, back `55 89 e5 83`, next symbol 0x10b7cc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p168-it1-l1-kern_xxx-F-20261002.json`). Grade **A**.

Object extent [0x10b600, 0x10b7cc) (gethostid .. reboot; the preceding _uname at 0x10b464 is outside this range and its owner is not established; next _ptrace). Diagnosis 13 failed on RB_COMMAND: the SDK bsd/i386/reboot.h is the public empty form; the value 0x00100000 is proven by reboot at 0x10b787 and the name comes from the SDK bsd/m68k/reboot.h:23. A diagnosis build (s5p168-d1, not 07) showed the only difference, command[0] = 0 at 0x10b772; the codex review of plan 195 agreed. it1 OBJECT_MATCH 7/7.
