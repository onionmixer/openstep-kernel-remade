# x86 `src/bsd/nfs/nfs_common.c` (plan 193 (S5-P166), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 193 (S5-P166). Final run `s5p166-it1`; 07 file SHA-256 `e97b644bb6b663cfef08b4bcd5fcb6a9421fc96e47ba242bed9472a6c098bc09`; diff `x86-nfs_common.diff`.

- Object [0x12c808, 0x12c8eb) 227 B, 2 functions (_nfstsize, _vattr_to_nattr). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x12c8ec.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p166-it1-l1-nfs_common-F-20261002.json`). Grade **A**.

Object extent [0x12c808, 0x12c8ec) (nfstsize 12 B, vattr_to_nattr 216 B; next _exportfs belongs to nfs_export). Diagnosis 13 failed on ECTSIZE/IETSIZE. The codex review of plan 193 added nothing that changes the source (nlink/rdev sign extension follows from the short types). it1 OBJECT_MATCH 2/2.
