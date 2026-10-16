# x86 `src/bsd/kern/cmu_syscalls.c` (plan 203 (S5-P176), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 203 (S5-P176). Final run `s5p176-it1`; 07 file SHA-256 `ec41eb23171ef4258cbb9b881e7b90015b83d20359ece63493c34bd139f986f8`; diff `x86-cmu_syscalls.diff`.

- Object [0x1020ac, 0x102931) 2181 B, 3 functions (_rpause, _table, _table_fsparam). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x102934.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p176-it1-l1-cmu_syscalls-F-20261002.json`). Grade **A**.

Object extent [0x1020ac, 0x102934) (rpause, table with its jump table at 0x1022ac, table_fsparam; 3 bytes padding). Diagnosis 13 failed on USRSTACK; a diagnosis build of a patched staged copy (s5p176-d2, not 07) located the table() differences. The codex review of plan 203 confirmed them case by case. it1 OBJECT_MATCH 3/3.

## Plan 472 (D090, 2026-10-16): else block in table()

- The thread reference (`th = …; thread_reference(th);`) is in an else block of the `thread_count <= 0` test. The m68k original pops the `thread_reference` argument right after the call (`addqw #4,sp` at 0x40024d4, later `addaw #0x14,sp`), which the m68k compiler emits at the end of a conditional; variants C1/C2 both OBJECT_MATCH (`09_validation/reconstruction/m5-m68k-cmu-syscalls-variants-p472-20261016.json`), and x86 gives the same object (`m5-x86-cmu-syscalls-variants-p472-20261016.json`).
- x86 full rebuild s6l9 (`s6-l2-prefixdiff-s6l8-s6l9-20261016.json`: only STABS of this object differ) and link `s6-l2-link-s6p472-ln1.json` identical to the original. Diff `x86-cmu_syscalls-plan472.diff`.
