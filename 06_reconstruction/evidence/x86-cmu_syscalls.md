# x86 `src/bsd/kern/cmu_syscalls.c` (plan 203 (S5-P176), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 203 (S5-P176). Final run `s5p176-it1`; 07 file SHA-256 `ec41eb23171ef4258cbb9b881e7b90015b83d20359ece63493c34bd139f986f8`; diff `x86-cmu_syscalls.diff`.

- Object [0x1020ac, 0x102931) 2181 B, 3 functions (_rpause, _table, _table_fsparam). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x102934.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p176-it1-l1-cmu_syscalls-F-20261002.json`). Grade **A**.

Object extent [0x1020ac, 0x102934) (rpause, table with its jump table at 0x1022ac, table_fsparam; 3 bytes padding). Diagnosis 13 failed on USRSTACK; a diagnosis build of a patched staged copy (s5p176-d2, not 07) located the table() differences. The codex review of plan 203 confirmed them case by case. it1 OBJECT_MATCH 3/3.
