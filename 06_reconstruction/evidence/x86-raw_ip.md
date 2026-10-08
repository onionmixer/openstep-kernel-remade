# x86 `src/bsd/netinet/raw_ip.c` (plan 168 (S5-P141), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 168 (S5-P141). Final run `s5p141-it2`; 07 file SHA-256 `f625df81cfcf7eb08d28436ecf6ed770ea2036ba3609829bdee436d904107c05`; diff `x86-raw_ip.diff`.

- Object [0x128240, 0x1284bf) 639 B, 3 functions (_rip_input, _rip_output, _rip_ctloutput). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x1284c0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p141-it2-l1-raw_ip-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (and -DMULTICAST). it1 rip_output 336/308; staged variants v1-v8 (plan 168.1), v8 OBJECT_MATCH; it2 (v8 plus `m = m0` in the non-MULTICAST branch found by the codex review) OBJECT_MATCH 3/3, 639 B; diagnostic compile without -DMULTICAST (s5p141-nomc) exits 0 with no diagnostics. 0x1284bf is a 00 padding byte.
