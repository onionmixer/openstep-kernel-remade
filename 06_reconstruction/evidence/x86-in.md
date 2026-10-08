# x86 `src/bsd/netinet/in.c` (plan 171 (S5-P144), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 171 (S5-P144). Final run `s5p144-it4`; 07 file SHA-256 `5ae538415f31c6194e2b9b71ed3376e3de644a217aa863d8dafeb2aeb09dbce8`; diff `x86-in.diff`.

- Object [0x123440, 0x124152) 3346 B, 15 functions (_inet_hash, _inet_netmatch, _in_makeaddr, _in_netof, _in_lnaof, _in_localaddr, _in_canforward, _in_control, _in_ifinit, _in_iaonnetof, _in_broadcast, _inet_ntoa, _inet_queue, _in_addmulti, _in_delmulti). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x124154.
- Final L1 `09_validation/reconstruction/s5p144-it4-l1-in-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (and -DMULTICAST). Iterations: it1 ICMP_MASKREQ undeclared; it2 in_addmulti store order (refcount before inm_ia); it3 one lea placement; staged variants v1 (`ifrp = (caddr_t)&ifr` before the field stores) -> __text 0 differences, v2 failed; it4 (v1 applied) __text 3346 B and __data with 0 differences, 15 functions MATCH (inet_ntoa MATCH_UNVERIFIED through __bss). Grade P: __bss reference-inferred.
