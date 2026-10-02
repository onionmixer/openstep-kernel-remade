# x86 `src/bsd/kern/uipc_mbuf.c` (plan 162 (S5-P136), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 162 (S5-P136). Final run `s5p136-it2`; 07 file SHA-256 `eea233cfd1f959fd10b37bb75b11311310c698ccdc6dceaccc96b29802a13a4d`; diff `x86-uipc_mbuf.diff`.

- Object [0x113b5c, 0x114b8b) 4143 B, 18 functions (_mbinit, _m_clalloc, _m_pgfree, _m_expand, _m_get, _m_getclr, _m_free, _m_more, _m_freem, _m_copy, _m_cat, _m_adj, _m_pullup, _mclget, _mclgetx, _mclput, _mcldup, (static buffree)). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x114b8c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p136-it2-l1-uipc_mbuf-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. it1 failed (vm/vm_param.h not staged); it2 OBJECT_MATCH 18/18 (17 named original functions + the static buffree at 0x114b78, unnamed in the original), 4143 B. 0x114b8b is a 00 padding byte.
