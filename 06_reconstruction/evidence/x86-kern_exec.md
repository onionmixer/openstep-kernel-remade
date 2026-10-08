# x86 `src/bsd/kern/kern_exec.c` (plan 291 (S5-P281), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 291 (S5-P281). Final run `s5p281-it1`; 07 file SHA-256 `ce1846035203799622ccbdbfa42ab1e257afcfbca0a29d7700b68c759461b210`; diff `x86-kern_exec.diff`.

- Object [0x104c2c, 0x105abd) 3729 B, 6 functions (_execv, _execve, _create_unix_stack, _load_init_program, _check_exec_access, (static load_return_to_errno)). Front `ec 5d c3 00`, back `00 00 00 55`, next symbol 0x105ac0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p281-it1-l1-kern_exec-F-20261002.json`). Grade **A**.

Object [0x104c2c, 0x105abd) + 00 00 00, next rexit 0x105ac0 (kern_exit). Six functions incl. the unnamed static 0x105a3c. __data [0x1da684, 0x1da847) 451 B; init_exec_args common. References by file name: NeXTMach bsd/kern_exec.c (base), Darwin 0.1 bsd/kern/kern_exec.c (code reference: 4.4BSD argument form). Earlier memo plan 210 (s5p183-d1..d3: execve 2472/2972). Diagnosis s5p281-d2..d10 (d10 OBJECT_MATCH), w11/d12 with plan markers. The codex review of plan 291 confirmed the bytes and asked for the c_utils.h source (the real-machine SDK copy, NeXT notice) and missing markers (verified, fixed). it1 (s5p281-it1) from 07 OBJECT_MATCH, relcheck 0.
