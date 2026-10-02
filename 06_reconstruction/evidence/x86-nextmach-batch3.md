# x86 NeXTMach batch 3 (S5-P116, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 142. Run `s5p116-adopt-1` (files from 07 only, final template with `-DINET`). Files are NeXTMach `https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e` (D013, D020); BSD headers are the SDK set (D021).

- `nfs_export` (`mk-108.1/nfs/nfs_export.c`): object [0x12c8ec, 0x12cffc) 1808 B, 8 functions (_exportfs, _unexport, _nfs_getfh, _findexivp, _makefh, _findexport, _loadaddrs, _exportfree); front `ec 5d c3 00`, back `55 89 e5 83`, next symbol 0x12cffc. Final OBJECT_MATCH (`09_validation/reconstruction/s5p116-adopt-1-l1-nfs_export-F-20261002.json`). Grade **A**.
- `xdr_array` (`mk-108.1/rpc/xdr_array.c`): object [0x138134, 0x13822d) 249 B, 1 functions (_xdr_array); front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x138230. Final OBJECT_MATCH (`09_validation/reconstruction/s5p116-adopt-1-l1-xdr_array-F-20261002.json`). Grade **A**.
- `xdr_reference` (`mk-108.1/rpc/xdr_reference.c`): object [0x138774, 0x1387e8) 116 B, 1 functions (_xdr_reference); front `ec 5d c3 00`, back `55 89 e5 68`, next symbol 0x1387e8. Final OBJECT_MATCH (`09_validation/reconstruction/s5p116-adopt-1-l1-xdr_reference-F-20261002.json`). Grade **A**.
