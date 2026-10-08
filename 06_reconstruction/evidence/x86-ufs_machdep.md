# x86 `src/machdep/i386/ufs_machdep.c` (plan 227 (S5-P207), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 227 (S5-P207). Final run `s5p207-um1`; 07 file SHA-256 `d0558fcb6cf811cb09180a225bbf599bc0961b3638611e3c70fac7ad39637e1f`; diff `x86-ufs_machdep.diff`.

- Object [0x19335c, 0x1934e9) 397 B, 2 functions (_allocbuf, _bfree). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x1934ec.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p207-um1-l1-ufs_machdep-F-20261002.json`). Grade **A**.

Object extent [0x19335c, 0x1934ec): _allocbuf and _bfree, then 3 bytes of 0x00 fill (0x1934e9-0x1934eb) before _sendsig (unix_signal). Diagnosis s5p207-d3 (NeXTMach text) matched both function sizes. The codex review of plan 227 was checked: extents and fill bytes confirmed from the original bytes; its note that CLBYTES must resolve to _page_size is settled by the build (relcheck 0). Build s5p207-um1: OBJECT_MATCH, relcheck 0.
