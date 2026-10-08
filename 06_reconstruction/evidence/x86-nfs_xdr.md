# x86 `src/bsd/nfs/nfs_xdr.c` (plan 185 (S5-P158), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 185 (S5-P158). Final run `s5p158-it1`; 07 file SHA-256 `1acb103c335c6612017cb7208206612345544052b1a326f6da548a1c6edf0041`; diff `x86-nfs_xdr.diff`.

- Object [0x13412c, 0x134f93) 3687 B, 25 functions (_xdr_fhandle, _xdr_writeargs, (static xdr_fattr), _xdr_readargs, _xdr_rdresult, _xdr_attrstat, _xdr_rdlnres, _xdr_rddirargs, _xdr_putrddirres, _xdr_getrddirres, _xdr_diropargs, _xdr_diropres, (static xdr_timeval), _xdr_saargs, _xdr_creatargs, _xdr_linkargs, _xdr_rnmargs, _xdr_slargs, _xdr_statfs, (static xdr_drok), (static xdr_fsok), (static xdr_rrok), (static xdr_srok), (static rrokfree), (static rrokwakeup)). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x134f94.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p158-it1-l1-nfs_xdr-F-20261002.json`). Grade **A**.

The original has 17 named functions; xdr_fattr (0x1341f8) and xdr_timeval (0x134924) stay at their definitions, xdr_sattr is inlined into saargs/creatargs/slargs, and drok, fsok, rrok, srok, rrokfree, rrokwakeup follow xdr_statfs (deferred). No calls from outside the object; function pointers only in this object's __data XDR tables (0x1dcd3c-0x1dcd7c). Staged variants s5p158-v1 (static) and s5p158-v2 (declaration order a1/a2) preceded the plan (procedure note in plan 185). it1 OBJECT_MATCH 25/25.
