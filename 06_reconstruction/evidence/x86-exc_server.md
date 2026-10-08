# x86 `src/mach/exc_server.c` (plan 348 (S5-P337), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 348 (S5-P337). Final run `s5p348-ex1`; 07 file SHA-256 `ddb3f8e33afdd54d6284d65e3ad67d1319cf037160f605431d93b058c1ca0ed4`; diff `x86-exc_server.diff`.

- Object [0x16df30, 0x16e030) 256 B, 2 functions (_exc_server, (static _Xexception_raise)). Front `5d c3 00 00`, back `55 89 e5 56`, next symbol 0x16e030.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p348-ex1-l1-exc_server-F-20261002.json`). Grade **A**.

MIG server of the 4.2 SDK mach/exc.defs. Diagnostics s5p348-migd1/2 and builds s5p348-exc1/excb1/machhost1/machport1/mach1. Codex review of plan 348 (gpt-6.1-sol) verified (mach_port -untyped and KernelServer conditions corrected). s5p348-ex1 from 07: OBJECT_MATCH, relcheck 0.
