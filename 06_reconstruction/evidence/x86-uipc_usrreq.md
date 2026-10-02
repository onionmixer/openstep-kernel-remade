# x86 `src/bsd/kern/uipc_usrreq.c` (plan 161 (S5-P135), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 161 (S5-P135). Final run `s5p135-it2`; 07 file SHA-256 `8107f033ca0725876a7f74c659c8d00e615946c5bdbe91bea0d6f39a372f9163`; diff `x86-uipc_usrreq.diff`.

- Object [0x118118, 0x118d52) 3130 B, 16 functions (_uipc_usrreq, _unp_attach, _unp_detach, _unp_bind, _unp_connect, _unp_connect2, _unp_disconnect, _unp_usrclosed, _unp_drop, _unp_externalize, _unp_internalize, _unp_gc, _unp_dispose, _unp_scan, _unp_mark, _unp_discard). Front `5d c3 00 00`, back `00 00 55 89`, next symbol 0x118d54.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p135-it2-l1-uipc_usrreq-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 uipc_usrreq 1248 B matching (the PRU_ACCEPT/PRU_PEERADDR tail sharing follows once PRU_SENSE is fixed), unp_attach 128/132 with `int error = 0` (zeroing hoisted to the entry); it2 with `error = 0` inside `default:` OBJECT_MATCH 16/16, 3130 B. Differences were found with scratchpad jtdiff.py (skips the inline switch table). 0x118d52-0x118d53 are 00 inter-object padding.
