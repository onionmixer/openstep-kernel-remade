# x86 `src/bsd/kern/mach_signal.c` (plan 196 (S5-P169), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 196 (S5-P169). Final run `s5p169-it1`; 07 file SHA-256 `e5d7a3364a6138f5125d5806ba7d7f408f69c5636ddf7132cf66c5c5d8dac474`; diff `x86-mach_signal.diff`.

- Object [0x10b9e8, 0x10ba5f) 119 B, 1 functions (_thread_psignal). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x10ba60.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p169-it1-l1-mach_signal-F-20261002.json`). Grade **A**.

Object extent [0x10b9e8, 0x10ba60) (_thread_psignal only). Diagnosis 13 failed on u_address; the kern/thread.h of this build declares struct uthread *_uthread (thread+0x84). The codex review of plan 196 found no other difference; strings and threadmask 0x1ef8 checked in Python. it1 OBJECT_MATCH 1/1 including __data (the two messages).
