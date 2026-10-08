# x86 `src/bsd/rpc/pmap_krmt.c` (plan 236 (S5-P221), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 236 (S5-P221). Final run `s5p221-it1`; 07 file SHA-256 `919d53e9524d054fcbd515d59b02c6c4ee90112244bf9d489606b78efcfef988`; diff `x86-pmap_krmt.diff`.

- Object [0x136114, 0x13624f) 315 B, 2 functions (_xdr_rmtcall_args, _xdr_rmtcallres). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x136250.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p221-it1-l1-pmap_krmt-F-20261002.json`). Grade **A**.

Object extent [0x136114, 0x136250): _xdr_rmtcall_args and _xdr_rmtcallres; one 0x00 fill byte before (0x136113, after the confirmed pmap_prot) and one after (0x13624f, before the confirmed rpc_callmsg). The same two XDR bodies are also in NeXTMach rpc/pmap_rmt.c, so choosing the kernel file pmap_krmt.c is an inference. Diagnosis s5p221-d1 (NeXTMach text) matched both sizes; _pmap_krmtcall is not an original symbol. The codex review of plan 236 corrected the fill-byte statement (only 0x136113) and narrowed the caller claim; both adopted. Build s5p221-it1: OBJECT_MATCH on the first build, relcheck 0.
