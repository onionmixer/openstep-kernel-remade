# x86 `src/bsd/rpc/pmap_prot.c` (plan 190 (S5-P163), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 190 (S5-P163). Final run `s5p163-p1`; 07 file SHA-256 `eb5fab6f91c1e30c73d5a9a6433a84324de4a540bab7b41664978b7df9ae5f89`; diff `x86-pmap_prot.diff`.

- Object [0x1360c0, 0x136113) 83 B, 1 functions (_xdr_pmap). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x136114.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p163-p1-l1-pmap_prot-F-20261002.json`). Grade **A**.

Object extent [0x1360c0, 0x136114) (xdr_pmap 83 B + 1 byte padding; next _xdr_rmtcall_args belongs to pmap_rmt). Diagnosis 13 failed only on struct portmap: the SDK rpc/pmap_prot.h is the user form (struct pmap); stage_headers.py now takes the NeXTMach kernel header (07_kernel/nextmach/rpc/pmap_prot.h, verbatim). Verbatim NeXTMach source -> OBJECT_MATCH 1/1 in it1.
