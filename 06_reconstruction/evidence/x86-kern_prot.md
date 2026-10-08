# x86 `src/bsd/kern/kern_prot.c` (plan 212 (S5-P186), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 212 (S5-P186). Final run `s5p186-it3`; 07 file SHA-256 `2218dd463e398ecb6298b77270324d50274de19f1df11cfb690a9a6bcdfb4472`; diff `x86-kern_prot.diff`.

- Object [0x107a24, 0x1085da) 2998 B, 27 functions (_proc_from_thread, _utask_from_thread, _uthread_from_thread, _setprivexec, _getpid, _getpgrp, _getuid, _getgid, _getposix, _setposix, _getgroups, _setpgrp, _setreuid, __setuid, __setgid, _setregid, _setgroups, _leavegroup, _entergroup, _groupmember, _suser, _crget, _crfree, _crcopy, _crdup, _setsid, _setpgid). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x1085dc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p186-it3-l1-kern_prot-F-20261002.json`). Grade **A**.

Object extent [0x107a24, 0x1085dc): 0x00 linker fill before 0x107a24 (plan 211.1) and after setpgid. A diagnosis build of the NeXTMach text (s5p186-d1, not 07) matched 14 functions. The codex review of plan 212 completed fact 12 (setpgid writes the target pid back to uap->pgid; equal pgid skips pgfind) and corrected fact 13 (_cractive is __DATA,__data 0x1da98c, as in NeXTMach). Iterations: it1 setposix, _setuid differ; variants s5p186-v1 (_setuid chained assignments, d0s1 chosen) and s5p186-v2 (setposix p4 chosen); it2/it3 all 27 functions match, extern relocation names match (relcheck 0). Diagnostic compile without POSIX_KERN exit 0 (s5p186-noposix2; first attempt s5p186-noposix failed before the POSIX_KERN guards).
