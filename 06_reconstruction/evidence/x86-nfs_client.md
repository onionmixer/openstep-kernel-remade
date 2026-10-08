# x86 `src/bsd/nfs/nfs_client.c` (plan 199 (S5-P172), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 199 (S5-P172). Final run `s5p172-it1`; 07 file SHA-256 `26d9d69b77fa4a5e869cf02de7e02e686a844141c05ff9b680e7699b60925b2a`; diff `x86-nfs_client.diff`.

- Object [0x12c204, 0x12c807) 1539 B, 10 functions (_nfs_validate_caches, _nfs_invalidate_caches, _nfs_purge_caches, _nfs_cache_check, _nfs_attrcache, _nfs_attrcache_va, (static set_attrcache_time), _nfs_getattr_otw, _nfsgetattr, _nattr_to_vattr). Front `c3 00 00 00`, back `00 55 89 e5`, next symbol 0x12c808.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p172-it1-l1-nfs_client-F-20261002.json`). Grade **A**.

Object extent [0x12c204, 0x12c808) (unsymbolled static set_attrcache_time at 0x12c380; nfs_getattr_cache inlined into nfsgetattr). Diagnosis 13 failed on the three-argument CACHE_VALID; a diagnosis build of a patched staged copy (s5p172-d1, not 07) located the differences. The codex review of plan 199 agreed and stressed the final size store on all nfsgetattr paths. it1 OBJECT_MATCH 10/10.
