# x86 `src/bsd/netinet/udp_usrreq.c` (plan 169 (S5-P142), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 169 (S5-P142). Final run `s5p142-it1`; 07 file SHA-256 `125f26f2415f22bb9a407cff33325d13948a68b5e6f88415c02d695234cd1114`; diff `x86-udp_usrreq.diff`.

- Object [0x12b2a4, 0x12bc2c) 2440 B, 6 functions (_udp_init, _udp_input, _udp_notify, _udp_ctlinput, _udp_output, _udp_usrreq). Front `5d c3 00 00`, back `55 89 e5 b8`, next symbol 0x12bc2c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p142-it1-l1-udp_usrreq-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (and -DMULTICAST). First build s5p142-it1 OBJECT_MATCH 6/6, 2440 B (object ends at the next symbol 0x12bc2c). Codex claim rejected: an extra splimp around MGET in udp_output (the SDK mbuf.h:171 MGET macro already takes splimp). Diagnostic compile without -DMULTICAST (s5p142-nomc) exits 0 with no diagnostics. icmp_error's 5th parameter is a pointer in the original callee (0x125665 dereferences it).
