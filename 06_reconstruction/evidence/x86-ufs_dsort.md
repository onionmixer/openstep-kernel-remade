# x86 `src/bsd/ufs/ufs_dsort.c` (plan 206 (S5-P179), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 206 (S5-P179). Final run `s5p179-it2`; 07 file SHA-256 `ebc672de49cb68e686938fcf1dfadb747a66457e064a159b02468db5af066e7b`; diff `x86-ufs_dsort.diff`.

- Object [0x13f90c, 0x1405eb) 3295 B, 9 functions (_disksort, (static ds_enter_common), _disksort_enter, _disksort_enter_head, _disksort_enter_tail, _disksort_first, _disksort_remove, _disksort_init, _disksort_free). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x1405ec.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p179-it2-l1-ufs_dsort-F-20261002.json`). Grade **A**.

Object extent [0x13f90c, 0x1405ec) (classic disksort 152 B, unsymbolled static ds_enter_common 1988 B, then the disksort_* functions; 1 byte padding). Diagnosis builds of staged copies (s5p179-d1..d3, not 07) found the import, the classic disksort and the disksort_enter difference; the codex review of plan 206 agreed. it1 had zero byte differences but L1 found the spl call target: spldma in the build, splbio in the original (both exist in the kernel). it2 OBJECT_MATCH 9/9.
