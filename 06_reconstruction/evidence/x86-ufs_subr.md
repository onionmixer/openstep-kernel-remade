# x86 `src/bsd/ufs/ufs_subr.c` (plan 207 (S5-P180), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 207 (S5-P180). Final run `s5p180-it1`; 07 file SHA-256 `d39fc68d0e93765773a1f99d10fa712a1fa32026cdddfe24ad01e8d667d4772a`; diff `x86-ufs_subr.diff`.

- Object [0x142884, 0x143021) 1949 B, 12 functions (_update, _syncip, _fragacct, _badblock, _isblock, _clrblock, _setblock, _getmp, _bufstats, _scanc, _skpc, _locc). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x1439f8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p180-it1-l1-ufs_subr-F-20261002.json`). Grade **A**.

Object extent [0x142884, 0x143024) (update .. locc; 3 bytes padding; the symbol size of _locc also covers unsymbolled code after 0x143024). Diagnosis 13 failed on NeXT_MIN_CLBYTES; a diagnosis build with the CLBYTES declaration (s5p180-d1, not 07) differed only in update. The codex review of plan 207 checked relocation target names as well. it1 OBJECT_MATCH 12/12 including __data (bname table).
