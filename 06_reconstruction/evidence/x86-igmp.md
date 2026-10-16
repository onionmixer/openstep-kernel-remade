# x86 `src/bsd/netinet/igmp.c` (plan 251 (S5-P236), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 251 (S5-P236). Final run `s5p236-it2`; 07 file SHA-256 `dac62f4ec3ca365eba8cc7e2dce198face77663352f660ceefc28416f89d7d4b`; diff `x86-igmp.diff`.

- Object [0x12bc2c, 0x12c1de) 1458 B, 6 functions (_igmp_init, _igmp_input, _igmp_joingroup, _igmp_leavegroup, _igmp_fasttimo, _igmp_sendreport). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x12c1e0.
- Final L1 `09_validation/reconstruction/s5p236-it2-l1-igmp-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred. Grade **P**.

Object extent [0x12bc2c, 0x12c1e0) 1460 B (1458 B text + 00 00; front after udp_usrreq without padding): igmp_init, igmp_input, igmp_joingroup, igmp_leavegroup, igmp_fasttimo, igmp_sendreport. __DATA,__data [0x1dbf20, 0x1dbf52) 50 B (sockproto {2,2}, igmpsrc, igmpdst, igmp_timers_are_running = 0, two "mget") -- placement inferred, verified by L1d. __common igmpstat 0x1eee70 (36 B). The codex review of plans 250/251 found no wrong claim and added two details (the random-delay seed is the global head in_ifaddr; sendreport stores only the listed IP fields), verified. it1 (s5p236-it1): all functions except igmp_fasttimo matched; variants s5p236-v1..v3: declaration order and statement forms did not help, an addressable step (the original keeps it on the stack, sub esp 8) matched -- `(void) &step` chosen. it2 (s5p236-it2) from 07: __text 0 and __data 0 differences, relcheck 0, __bss reference-inferred.

## Plan 474 (D092, 2026-10-16): forms of the m68k original

- `IGMP_RANDOM_DELAY` adds `ipstat.ips_total` first; `igmp_fasttimo` walks the multicast list with two static helpers defined after `igmp_leavegroup` (`igmp_next_multi` = `IN_NEXT_MULTI` as a function, `igmp_first_multi` sets `in_ifaddr` and calls it), as the m68k original (0x4025f16, 0x4025f4c). x86 (-O3) inlines the helpers and gives the same object (`09_validation/reconstruction/m5-x86-igmp-variants-p474-20261016.json`).
- x86 full rebuild s6lb (`s6-l2-prefixdiff-s6la-s6lb-20261016.json`: only STABS of this object differ) and link `s6-l2-link-s6p474-ln1.json` identical to the original. m68k: text and data verified, bss [0x40b3528, 0x40b352c) reference-inferred (`m5-m68k-p474-final-20261016.json`, `m5-m68k-p474-zerofill-20261016.json`). Diff `x86-igmp-plan474.diff`.
