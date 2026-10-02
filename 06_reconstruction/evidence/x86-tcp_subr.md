# x86 `src/bsd/netinet/tcp_subr.c` (plan 165 (S5-P139), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 165 (S5-P139). Final run `s5p139-it1`; 07 file SHA-256 `b99b9097768f917977e255f9c766143eda176fbdae98d28943855fe604cce584`; diff `x86-tcp_subr.diff`.

- Object [0x12a434, 0x12a8c9) 1173 B, 10 functions (_tcp_init, _tcp_template, _tcp_respond, _tcp_newtcpcb, _tcp_drop, _tcp_close, _tcp_drain, _tcp_notify, _tcp_ctlinput, _tcp_quench). Front `c3 00 00 00`, back `00 00 00 55`, next symbol 0x12a8cc.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p139-it1-l1-tcp_subr-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. First build s5p139-it1 OBJECT_MATCH 10/10 (__text 1173 B, __data tcp_ttl 60 / tcp_mssdflt 512 / tcp_rttdflt 3 at 0x1dbe8c-0x1dbe97). Bytes 0x12a8c9-0x12a8cb are 00 inter-object padding.
