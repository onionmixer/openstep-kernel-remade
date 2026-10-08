# x86 `src/bsd/rpc/pmap_kgetport.c` (plan 190 (S5-P163), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 190 (S5-P163). Final run `s5p163-it1`; 07 file SHA-256 `9cdf9fe2a23aca798534e758c54ebbddb5102584da9c2b44dbfb5038fd6499ff`; diff `x86-pmap_kgetport.diff`.

- Object [0x135df4, 0x1360c0) 716 B, 2 functions (_pmap_kgetport, _getport_loop). Front `c3 00 00 00`, back `55 89 e5 56`, next symbol 0x1360c0.
- Final L1 `09_validation/reconstruction/s5p163-it1-l1-pmap_kgetport-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x135df4, 0x1360c0) (pmap_kgetport 284 B, getport_loop 432 B with pmap_kgetport inlined). Diagnosis 13 failed on struct portmap (SDK user header) and on ISSIG (struct thread incomplete); the codex review of plan 190 pointed out the ISSIG errors, verified in 66.err. With the NeXTMach kernel rpc/pmap_prot.h and the kern/thread.h import, it1 matched every function and __data (tottimeout, the three messages); only the unsymbolled __bss cred remains reference-inferred. The clntkudp_create implicit-declaration warning is kept (the call result is used as returned in eax).
