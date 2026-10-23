# x86 `src/bsd/ufs/ufs_subr.c` (plan 207 (S5-P180), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 207 (S5-P180). Final run `s5p180-it1`; 07 file SHA-256 `d39fc68d0e93765773a1f99d10fa712a1fa32026cdddfe24ad01e8d667d4772a`; diff `x86-ufs_subr.diff`.

- Object [0x142884, 0x143021) 1949 B, 12 functions (_update, _syncip, _fragacct, _badblock, _isblock, _clrblock, _setblock, _getmp, _bufstats, _scanc, _skpc, _locc). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x1439f8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p180-it1-l1-ufs_subr-F-20261002.json`). Grade **A**.

Object extent [0x142884, 0x143024) (update .. locc; 3 bytes padding; the symbol size of _locc also covers unsymbolled code after 0x143024). Diagnosis 13 failed on NeXT_MIN_CLBYTES; a diagnosis build with the CLBYTES declaration (s5p180-d1, not 07) differed only in update. The codex review of plan 207 checked relocation target names as well. it1 OBJECT_MATCH 12/12 including __data (bname table).

## Plan 478 (D095, 2026-10-23): constant counts on m68k

- The m68k original `_bufstats` [0x40393e8, 0x40394d0) keeps `counts` in an 8-byte frame (`linkw a6,#-8`); the 07 line `int counts[MAXBSIZE/CLBYTES+1];` gives a variable-length array on m68k too, because `CLBYTES` is `CLSIZE*NBPG` and the kernel `NBPG` is `m68k_page_size` there. NeXTMach mk-108.1 ufs/ufs_subr.c:406-410 has `#if NeXT` `int counts[MAXBSIZE/NeXT_MIN_CLBYTES+1]; /* must be constant */`; the OPENSTEP m68k headers name that macro `M68K_MIN_CLBYTES` (8192), so the array has 2 ints.
- 07 now declares `counts` under `#if m68k` with `M68K_MIN_CLBYTES` and keeps the `CLBYTES` line under `#else` (x86 original: run-time size, plan 207). Forms M, C (`counts[2]`) and MX give the same m68k object; MX was chosen (D095). The macro name is an inference.
- x86 full rebuild s6le (`s6-l2-prefixdiff-s6ld-s6le-20261023.json`: only STABS of this object differ) and link `s6-l2-link-s6p478-ln1.json` identical to the original. m68k `x86-ufs_subr` OBJECT_MATCH (`m5-m68k-p478-final-20261023.json`). Lines after 416 moved by 4; `06_reconstruction/functions.tsv` citations were moved (old and new line text equal). 07 file SHA-256 `913c6bb7da6fc25d9756aaa45e8da16dce6d645ac32510dd14581a0b9e012185`.
