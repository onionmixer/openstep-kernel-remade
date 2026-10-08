# x86 `src/bsd/netinet/in_pcb.c` (plan 166 (S5-P140), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 166 (S5-P140). Final run `s5p140-it2`; 07 file SHA-256 `b93bb974d658e6fb964259d051e3020f54b58dfd357e825731ff9f6e04f3fb84`; diff `x86-in_pcb.diff`.

- Object [0x124e10, 0x125553) 1859 B, 11 functions (_in_pcballoc, _in_pcbbind, _in_pcbconnect, _in_pcbdisconnect, _in_pcbdetach, _in_setsockaddr, _in_setpeeraddr, _in_pcbnotify, _in_losing, _in_rtchange, _in_pcblookup). Front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x125554.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p140-it2-l1-in_pcb-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE. it1 10 MATCH + in_pcbnotify fport/lport register swap; staged variants v1 (declaration order) and v2 (u_int args) unchanged, v3 (`fport = 0; lport = 0;`, Darwin form) and v4 (`lport = fport = 0;`) OBJECT_MATCH; v3 applied; it2 OBJECT_MATCH 11/11, 1859 B. Offsets (Python from SDK headers): inpcb inp_moptions 0x3c, socket so_proto 0xc, protosw pr_flags 0xa, in_ifaddr ia_ifp 0x20 / ia_next 0x40.
