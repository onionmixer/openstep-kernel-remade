# x86 `src/machdep/i386/dkbad.c` (plan 227 (S5-P207), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 227 (S5-P207). Final run `s5p207-dk1`; 07 file SHA-256 `b2fe57db68e7440703a4c146716e41d43843b0bb59af14cf40f73db178c7eb35`; diff `x86-dkbad.diff`.

- Object [0x187fec, 0x188044) 88 B, 1 functions (_isbad). Front `c3 00 00 00`, back `55 89 e5 53`, next symbol 0x188044.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p207-dk1-l1-dkbad-F-20261002.json`). Grade **A**.

Object extent [0x187fec, 0x188044): only _isbad, ending with ret at 0x188043 directly before _dma_initialize (recorded dma object). Diagnosis s5p207-d4 (NeXTMach text) matched the size. Build s5p207-dk1: OBJECT_MATCH, relcheck 0.
