# x86 `src/bsd/rpc/auth_kern.c` (plan 158 (S5-P132), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 158 (S5-P132). Final run `s5p132-it2`; 07 file SHA-256 `f0bc3bcbf29650d0c2875ea636c8944fb84b3309e3bf1d541fede63bad5b1985`; diff `x86-auth_kern.diff`.

- Object [0x134f94, 0x1351d2) 574 B, 6 functions (_authkern_create, _authkern_nextverf, _authkern_marshal, _authkern_validate, _authkern_refresh, _authkern_destroy). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x1351d4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p132-it2-l1-auth_kern-F-20261002.json`). Grade **A**.

it1 (SDK rpc/auth.h, ah_ops at 0x18): 5 MATCH + authkern_create 1 byte (store of &auth_kern_ops to 0x18 vs original 0x20). it2 with the plan 158.1 overlay (ah_key before ah_ops for KERNEL, as NeXTMach rpc/auth.h): OBJECT_MATCH 6/6, 574 B. The other 9 rpc/auth.h users rebuilt with the overlay are identical in non-debug content to s5p129-diaga-1 (09_validation/reconstruction/s5p132-rg-compare-20261002.json). 0x1351d2-0x1351d3 are 00 inter-object padding.
