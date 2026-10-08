# x86 `src/bsd/vfs/vfs_bio.c` (plan 208 (S5-P181), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 208 (S5-P181). Final run `s5p181-it3`; 07 file SHA-256 `52eed69639cb53e930ac892a596d5ca9f3df0fb1ebdf3596771363f62ffab121`; diff `x86-vfs_bio.diff`.

- Object [0x119b8c, 0x11b28a) 5886 B, 25 functions (_bread, _breada, _vnReadAhead, _breadDirect, _bwrite, _bdwrite, _bawrite, _brelse, _incore, _getblk, _geteblk, _brealloc, _getnewbuf, _getnewbuf_count, _biowait, _biodone, _blkflush, _bflush, _brelvp_wakeup, _binvalfree, _btrash, _geterror, _binval, (static bsetvp), (static brelvp)). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x11b28c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p181-it3-l1-vfs_bio-F-20261002.json`). Grade **A**.

Object extent [0x119b8c, 0x11b28c) (unsymbolled statics bsetvp 0x11b244 and brelvp 0x11b26c at the end; vnStartRead/vnCleanBuffer inlined into breadDirect). Diagnosis 13 failed on the one-argument btodb and DEV_BSHIFT; a diagnosis build with placeholders (s5p181-d2, not 07) mapped the differences, and the codex review of plan 208 added the inlined brelse copies and the call target list. it1 compile error (btrash placed at a call of geterror; anchor fixed, file regenerated); it2 23/25 (one byte each in brealloc and blkflush: jae vs the original jge, because the SDK btodb casts to unsigned); it3 signed division in the overlap tests -> OBJECT_MATCH 25/25 including __data.
