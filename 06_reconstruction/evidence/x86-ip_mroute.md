# x86 `src/bsd/netinet/ip_mroute.c` (plan 250 (S5-P235), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 250 (S5-P235). Final run `s5p235-it1`; 07 file SHA-256 `e9acb153fc4646d327206913ec5d582171081db46ad54704b3a7bb291262ba85`; diff `x86-ip_mroute.diff`.

- Object [0x12c1e0, 0x12c201) 33 B, 3 functions (_ip_mrouter_cmd, _ip_mrouter_done, _ip_mforward). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x12c204.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p235-it1-l1-ip_mroute-F-20261002.json`). Grade **A**.

Object extent [0x12c1e0, 0x12c204) 36 B (33 B text + 3 x 00; front 0x12c1de-df 00 00 after igmp_sendreport; back before nfs_client at 0x12c204). __DATA,__data [0x1dbf54, 0x1dbf5c) 8 B (_ip_mrouter, _ip_mrtproto, both 0; 0x1dbf5c belongs to _findexivp of nfs_export) -- given by symbol, L1. The codex review of plans 250/251 found no wrong claim (verified). it1 (s5p235-it1) OBJECT_MATCH, relcheck 0.
