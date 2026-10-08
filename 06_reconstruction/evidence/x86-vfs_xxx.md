# x86 `src/bsd/kern/vfs_xxx.c` (plan 194 (S5-P167), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 194 (S5-P167). Final run `s5p167-it1`; 07 file SHA-256 `7a8bc0859e9dc4f76e8839ce66e73a121df860c4f75eceea70b0be3679aef558`; diff `x86-vfs_xxx.diff`.

- Object [0x11eaa4, 0x11eb50) 172 B, 1 functions (_ustat). Front `5d c3 00 00`, back `55 89 e5 83`, next symbol 0x11eb50.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p167-it1-l1-vfs_xxx-F-20261002.json`). Grade **A**.

Object extent [0x11eaa4, 0x11eb50) (_ustat only). Diagnosis 13 failed on DEV_BSIZE. The original divides f_bavail * f_bsize + 511 by 512 with signed arithmetic (0x11eb14-0x11eb24). The codex review of plan 194 confirmed the statement order and named STAT_BSIZE (sys/stat.h:195) as a candidate macro; vfs_xxx.c does not import sys/stat.h, so the literal is used. it1 OBJECT_MATCH 1/1.
