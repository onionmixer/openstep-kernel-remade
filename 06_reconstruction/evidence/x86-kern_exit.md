# x86 `src/bsd/kern/kern_exit.c` (plan 213 (S5-P187), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 213 (S5-P187). Final run `s5p187-it3`; 07 file SHA-256 `1474527d0bb07b5465a7d34b9ffa1842d41d1a48580d5096132da13cf4a80c4b`; diff `x86-kern_exit.diff`.

- Object [0x105ac0, 0x106817) 3415 B, 9 functions (_rexit, _exit, _do_exit, _wait4, _wait, _wait3, _wait1, _waitpgrp, _init_process). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x106818.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p187-it3-l1-kern_exit-F-20261002.json`). Grade **A**.

Object extent [0x105ac0, 0x106818). Diagnosis 13 failed on kern/ipc_globals.h; diagnosis builds of the NeXTMach text (s5p187-d4 after header fixes, not 07) matched only rexit. The codex review of plan 213 found no wrong fact; it sharpened facts 3 (f is kept on a normal continuation wakeup) and 7 (waitpgrp has no direct p_pgrp store; leavepgrp clears it; 4-byte copyout from p_xstat). Iterations: it1 missing sys/tty.h; it2 wait1 and waitpgrp differ; variants s5p187-v1 (wait1 wait-result test, w1 chosen) and s5p187-v2..v6 (waitpgrp: non-register uap, if/else in the setjmp branch, `u.u_r.r_val1 = status = 0`, t2 chosen); it3 all 9 functions match, extern relocation names match (relcheck 0). Diagnostic compile without POSIX_KERN exit 0 (s5p187-noposix).
