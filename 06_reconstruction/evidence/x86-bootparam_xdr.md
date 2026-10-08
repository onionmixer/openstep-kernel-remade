# x86 `src/bsd/rpc/bootparam_xdr.c` (plan 226 (S5-P206), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 226 (S5-P206). Final run `s5p206-bp1`; 07 file SHA-256 `0e36b8ec0d96f0b7610de38949685f2902558e823d27e32a0d31065f1f7be2ca`; diff `x86-bootparam_xdr.diff`.

- Object [0x1387e8, 0x138a8f) 679 B, 9 functions (_xdr_bp_machine_name_t, _xdr_bp_path_t, _xdr_bp_fileid_t, _xdr_ip_addr_t, _xdr_bp_address, _xdr_bp_whoami_arg, _xdr_bp_whoami_res, _xdr_bp_getfile_arg, _xdr_bp_getfile_res). Front `89 ec 5d c3`, back `00 55 89 e5`, next symbol 0x138a90.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p206-bp1-l1-bootparam_xdr-F-20261002.json`). Grade **A**.

Object extent [0x1387e8, 0x138a90): after the confirmed xdr_reference, before _xdr_fhstatus (mountxdr). Diagnosis s5p206-d1 (NeXTMach text) matched all 9 function sizes (the last differs only by 1 byte of end padding; sum 680 = extent). The codex review of plan 226 was checked against the original bytes. Build s5p206-bp1 (NeXTMach text unchanged): OBJECT_MATCH on the first build, extern relocation names match (relcheck 0).
