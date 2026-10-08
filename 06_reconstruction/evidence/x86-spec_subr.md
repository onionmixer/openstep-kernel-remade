# x86 `src/bsd/specfs/spec_subr.c` (plan 224 (S5-P203), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 224 (S5-P203). Final run `s5p203-it1`; 07 file SHA-256 `4dabc5445a47d9c06dd2810e384fafda12794145dad5d5d83f6ca67c7fa75701`; diff `x86-spec_subr.diff`.

- Object [0x1395d8, 0x139b13) 1339 B, 12 functions (_bdevvp, _set_blocksize, _specvp, _makespecvp, (static ssave), _sunsave, _stillopen, _isclosing, _other_specvp, _slookup, (static sfind), _smark). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x139b14.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p203-it1-l1-spec_subr-F-20261002.json`). Grade **A**.

Object extent [0x1395d8, 0x139b14): after the confirmed fifo_vnodeops, before spec_vfsops (plan 222). The earlier deferral of this object (an unnamed call target 0x1395f0) is resolved: the symbol _set_blocksize names it. Diagnosis s5p203-d1 (NeXTMach text, not 07) failed on the one-argument dbtob. The codex review of plan 224 confirmed facts 1-3. Build s5p203-it1: all 12 functions match on the first build, extern relocation names match (relcheck 0).
