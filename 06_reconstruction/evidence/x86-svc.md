# x86 `src/bsd/rpc/svc.c` (plan 192 (S5-P165), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 192 (S5-P165). Final run `s5p165-it1`; 07 file SHA-256 `2ff1761393e61e26bb2903d281bbad17210635f67563da4f50c39a2dc1f9c1c3`; diff `x86-svc.diff`.

- Object [0x136ddc, 0x137340) 1380 B, 13 functions (_xprt_register, _svc_register, _svc_unregister, (static svc_find), _svc_sendreply, _svcerr_noproc, _svcerr_decode, _svcerr_auth, _svcerr_weakauth, _svcerr_noprog, _svcerr_progvers, _svc_getreq, _svc_run). Front `c3 00 00 00`, back `55 89 e5 53`, next symbol 0x137340.
- Final L1 `09_validation/reconstruction/s5p165-it1-l1-svc-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x136ddc, 0x137340) (unsymbolled static svc_find at 0x136e88 after svc_unregister). Diagnosis 13 failed at svc.c:510-511 because the SDK rpc/svc.h declares int xp_sock; stage_headers.py now takes the NeXTMach kernel header (07_kernel/nextmach/rpc/svc.h, verbatim). Regression with the new rule: nfs_export, rpc_callmsg, rpc_prot, svc_auth, svc_auth_unix, svc_kudp rebuilt as s5p165-r1..r6, all OBJECT_MATCH, each stage holding the NeXTMach svc.h. Verbatim NeXTMach svc.c: it1 matches every function; only the unsymbolled __bss svc_head is reference-inferred (xports is in the non-KERNEL branch).
