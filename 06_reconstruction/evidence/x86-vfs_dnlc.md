# x86 `src/bsd/kern/vfs_dnlc.c` (plan 184 (S5-P157), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 184 (S5-P157). Final run `s5p157-it2`; 07 file SHA-256 `6e11f23732b9d453e77c7a8dbde4ead520b045ade2e492bb9c917b2d55a677d2`; diff `x86-vfs_dnlc.diff`.

- Object [0x11b28c, 0x11b982) 1782 B, 11 functions (_dnlc_init, _dnlc_enter, _dnlc_lookupSymLink, _dnlc_enterSymLink, _dnlc_lookup, _dnlc_remove, _dnlc_purge, _dnlc_purge_vp, _dnlc_purge1, (static dnlc_rm), (static dnlc_search)). Front `5d c3 00 00`, back `00 00 55 89`, next symbol 0x11b984.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p157-it2-l1-vfs_dnlc-F-20261002.json`). Grade **A**.

Object extent: the static dnlc_rm (0x11b830) and dnlc_search (0x11b8dc) follow dnlc_purge1 without symbols; next symbol _vno_rw at 0x11b984 (objects.tsv seq 55 text_end 0x11b830 is purge1's end). ncache layout from the SDK sys/dnlc.h (NC_NAMLEN 32; NeXTMach has 15). Iterations: it1 queue operations inlined, but assert() compiled as calls (no definition staged) -> import kern/assert.h; it2 OBJECT_MATCH 11/11, no helper symbols in the object.
