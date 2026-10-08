# x86 `src/bsd/rpc/mountxdr.c` (plan 226 (S5-P206), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 226 (S5-P206). Final run `s5p206-mx1`; 07 file SHA-256 `3ce6e5a4378794268d92d324ef6e200bdeac536dd961f30b225031407bbeb07c`; diff `x86-mountxdr.diff`.

- Object [0x138a90, 0x138ace) 62 B, 1 functions (_xdr_fhstatus). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x1394f0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p206-mx1-l1-mountxdr-F-20261002.json`). Grade **A**.

Object extent [0x138a90, 0x138ad0) 64 B: only _xdr_fhstatus (symbols.tsv has none of the other six mount routines; _xdr_fhandle at 0x13412c belongs to another object). Diagnosis s5p206-d2 (NeXTMach text) matched xdr_fhstatus and built six routines the original lacks; they are now user-level only (#ifndef KERNEL). Build s5p206-mx1: OBJECT_MATCH, relcheck 0.
