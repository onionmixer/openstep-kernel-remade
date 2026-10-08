# x86 `src/machdep/i386/unix_signal.c` (plan 258 (S5-P243), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 258 (S5-P243). Final run `s5p243-it2`; 07 file SHA-256 `0bc1224c83026f350ea399d973ccaea6a12778f26d7e7417d54e3470ea42f53b`; diff `x86-unix_signal.diff`.

- Object [0x1934ec, 0x193a98) 1452 B, 3 functions (_sendsig, _sigreturn, _machine_exception). Front `c3 00 00 00`, back `55 89 e5 57`, next symbol 0x193a98.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p243-it2-l1-unix_signal-F-20261002.json`). Grade **A**.

Object extent [0x1934ec, 0x193a98) 1452 B (front 0x1934e9-eb 00 x3 after ufs_machdep; back joins unix_startup without padding): sendsig, sigreturn, machine_exception. No data sections. Earlier diagnosis (s5p49-pre-1, Darwin text) built 1416 B. The codex review of plan 258 found no wrong claim about the bytes; it corrected my return-value wording for sigreturn and added selector and PC-path details (verified). it1 failed (EFL_USERCLR/SET: machine/psl.h); it2 (s5p243-it2) OBJECT_MATCH, relcheck 0.
