# x86 `src/bsd/netinet/tcp_usrreq.c` (plan 163 (S5-P137), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 163 (S5-P137). Final run `s5p137-it1`; 07 file SHA-256 `b3b83322024b9bd9179fbdc5c1f39ccb3b8861c0b5e6a48296c900b6f6e1c992`; diff `x86-tcp_usrreq.diff`.

- Object [0x12ac0c, 0x12b2a2) 1686 B, 5 functions (_tcp_usrreq, _tcp_ctloutput, _tcp_attach, _tcp_disconnect, _tcp_usrclosed). Front `ec 5d c3 00`, back `00 00 55 89`, next symbol 0x12b2a4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p137-it1-l1-tcp_usrreq-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. First build s5p137-it1 OBJECT_MATCH 5/5, 1686 B. sb_hiwat offsets (Python from SDK socketvar.h): so_rcv 0x26, so_snd 0x3e. Bytes 0x12b2a2-0x12b2a3 are 00 inter-object padding.
