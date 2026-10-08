# x86 `src/bsd/rpc/clnt_kudp.c` (plan 191 (S5-P164), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 191 (S5-P164). Final run `s5p164-it1`; 07 file SHA-256 `c01256a2abdf7ccd42dd954a8ba6cd9f16a65916ad49a48005402b1585abf663`; diff `x86-clnt_kudp.diff`.

- Object [0x135330, 0x135dba) 2698 B, 17 functions (_clntkudp_once, _clntkudp_interruptable, _clntkudp_realloc, _clntkudp_create, _clntkudp_init, _clntkudp_freecred, _clntkudp_callit_addr, _clntkudp_callit, _ckuwakeup, _clntkudp_error, _clntkudp_freeres, _clntkudp_abort, _clntkudp_control, _clntkudp_destroy, (static bindresvport), (static noop), (static buffree)). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x135dbc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p164-it1-l1-clnt_kudp-F-20261002.json`). Grade **A**.

Object extent [0x135330, 0x135dbc) (code ends 0x135dba; the statics bindresvport, noop, buffree follow clntkudp_destroy at 0x135cb4, 0x135d8c, 0x135d94). A diagnosis build of the NeXTMach text plus the import (s5p164-d2, not 07) showed 14 functions equal in shape and the differences in create, init and the new freecred; the codex review of plan 191 found no further difference (crhold line number corrected to ucred.h:29). it1 OBJECT_MATCH 17/17 including __data. The diagnosis run s5p164-d1 failed (header not staged) and its run directory was deleted (plan 191 fact 6).
