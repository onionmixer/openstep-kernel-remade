# x86 `src/bsd/kern/tty_tty.c` (plan 156 (S5-P130), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 156 (S5-P130). Final run `s5p130-it1`; 07 file SHA-256 `0e0464fe99a8bc4a348ed1991499f38e8c673c7eabcccc47a48202c05e503c5a`; diff `x86-tty_tty.diff`.

- Object [0x113748, 0x113912) 458 B, 5 functions (_syopen, _syread, _sywrite, _syioctl, _syselect). Front `5d c3 00 00`, back `00 00 55 89`, next symbol 0x113914.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p130-it1-l1-tty_tty-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (plan 155.1). Offsets: posix_proc p_posix_pgrp 0x10, pgrp pg_session 8, session s_leader 4 / s_ttyp 8 / s_ttyd 0xc (Python from SDK types), proc p_flag 0x28, short p_pid 0x30; utask uu_ttyp 0x168 / uu_ttyd 0x16c confirmed by the matching build. First build s5p130-it1 OBJECT_MATCH 5/5, 458 B; 0x113912-0x113913 are 00 inter-object padding.
