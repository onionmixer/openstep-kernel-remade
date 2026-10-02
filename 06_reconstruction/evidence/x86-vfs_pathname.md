# x86 `src/bsd/kern/vfs_pathname.c` (plan 157 (S5-P131), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 157 (S5-P131). Final run `s5p131-it1`; 07 file SHA-256 `a9286fa0af64b69121fff16e8bb55f99ef4f754147708e48abda6fe57ff0189b`; diff `x86-vfs_pathname.diff`.

- Object [0x11c97c, 0x11cba5) 553 B, 8 functions (_pn_alloc, _pn_get, _pn_set, _pn_combine, _pn_append, _pn_getcomponent, _pn_skipslash, _pn_free). Front `89 ec 5d c3`, back `00 00 00 55`, next symbol 0x11cba8.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p131-it1-l1-vfs_pathname-F-20261002.json`). Grade **A**.

Original pn_get tests the copy error, pn_pathlen == 0x400 and pn_path[0x3ff] != 0, then sets error 0x3f (SDK param.h:251 MAXPATHLEN 1024, errno.h:142 ENAMETOOLONG 63). First build s5p131-it1 OBJECT_MATCH 8/8, 553 B; 0x11cba5-0x11cba7 are 00 inter-object padding.
