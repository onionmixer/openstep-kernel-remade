# x86 `src/bsd/kern/tty_subr.c` (plan 183 (S5-P156), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 183 (S5-P156). Final run `s5p156-it1`; 07 file SHA-256 `0ec6ba049b5b61da290e594209f50c441e6073f32bef1e9fdfc8ea730ed8736b`; diff `x86-tty_subr.diff`.

- Object [0x112db0, 0x113746) 2454 B, 10 functions (_getc, _q_to_b, _ndqb, _ndflush, _putc, _b_to_q, _nextc, _nextc3, _unputc, _catq). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x113748.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p156-it1-l1-tty_subr-F-20261002.json`). Grade **A**.

cblock layout from the SDK sys/clist.h (c_next, c_quote[8], c_info[52]); TTY_QUOTE from sys/tty.h. it1 OBJECT_MATCH 10/10 (2454 B; catq ends at 0x113746, 2 bytes padding).
