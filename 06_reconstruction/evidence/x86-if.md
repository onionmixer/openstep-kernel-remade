# x86 `src/bsd/net/if.c` (plan 172 (S5-P145), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 172 (S5-P145). Final run `s5p145-it2`; 07 file SHA-256 `932bd0cc62a4bff0dfb5db2cb84f1bb85cb67af1d5b0e3e678dce7f221e4d2dc`; diff `x86-if.diff`.

- Object [0x11edac, 0x11f43a) 1678 B, 12 functions (_ifinit, _ifa_ifwithaddr, _ifa_ifwithdstaddr, _ifa_ifwithnet, _ifb_ifwithaf, _if_down, _if_qflush, _if_down_all, _ifunit, _ifioctl, _ifconf, _address_known). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x11f43c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p145-it2-l1-if-F-20261002.json`). Grade **A**.

Built with -DPOSIX_KERN -D_POSIX_SOURCE (and -DMULTICAST). it1 11 MATCH + ifioctl case-body order; it2 (MULTI case moved after the MTU group) OBJECT_MATCH 12/12, 1678 B. Diagnostic compile without -DMULTICAST (s5p145-nomc) exits 0. 0x11f43a-0x11f43b are 00 padding.
