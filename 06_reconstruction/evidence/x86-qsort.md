# x86 `src/bsd/kern/qsort.c` (plan 270 (S5-P260), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 270 (S5-P260). Final run `s5p260-it1`; 07 file SHA-256 `7eaa7dfd566c9bf7d695907a3bda15c5f0a00ee5f0b6cdfea13acfeea076207a`; diff `x86-qsort.diff`.

- Object [0x10ba60, 0x10bd46) 742 B, 2 functions (_qsort, (static qst)). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x10bd48.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p260-it1-l1-qsort-F-20261002.json`). Grade **A**.

Object extent [0x10ba60, 0x10bd48) 744 B (742 B text + 00 00; front 00 after thread_psignal; back before logopen): _qsort and the unnamed static qst at 0x10bb88 (called at 0x10bab0, 0x10bd05, 0x10bd25). __DATA,__data [0x1dac04, 0x1dac14) 16 B, all zero: qcmp, qsz, thresh, mthresh -- verified by L1d (uninitialized statics go to __bss, scratch w1). References by file name: no kernel qsort of this algorithm in Mach4 or NeXTMach; Darwin 0.1 bsd/kern/qsort.c and Libc qsort.c are the later Bentley-McIlroy algorithm, not used. No direct call to qsort in the original text. Scratch builds s5p260-w1, w2 (07 untouched), w2 OBJECT_MATCH. The codex review of plan 270 confirmed the extent, algorithm and data; its note on the int vs size_t prototype is recorded (same bytes on i386). it1 (s5p260-it1) from 07 OBJECT_MATCH, relcheck 0 mismatches.
