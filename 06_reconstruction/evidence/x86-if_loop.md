# x86 `src/bsd/net/if_loop.c` (plan 226 (S5-P206), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 226 (S5-P206). Final run `s5p206-lo2`; 07 file SHA-256 `709e5aece0159adad55127396cdb40875d0a2620d754b6fb51e5ddd72b6b3426`; diff `x86-if_loop.diff`.

- Object [0x11f43c, 0x11f55d) 289 B, 4 functions (_logetbuf, _looutput, _locontrol, _loattach). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x11f560.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p206-lo2-l1-if_loop-F-20261002.json`). Grade **A**.

Object extent [0x11f43c, 0x11f560): before _VENIP_PRIVATE (if_venip). Diagnosis s5p206-d3 (NeXTMach text): logetbuf and looutput match; locontrol 124/64 and loattach 68/62. Original: 0x11f4c9 or al,0x41; strcmp with 0x1d1255 (add-multicast) at 0x11f4d8 and again at 0x11f4ea (rmv-multicast 0x1d1263 unused); cmp word [data+0x10],2 then EAFNOSUPPORT, else EINVAL; loattach pushes 0x808. The codex review of plan 226 was checked (its header line citation for IFF_MULTICAST was wrong: if.h:110, not :101). it1 (s5p206-lo1): register choice differed in locontrol (original keeps data in edi). Variants s5p206-lov1 v1-v6: only a function-scope `struct ifreq *ifr = data` declared before error matches (0 byte differences). it2 (s5p206-lo2): OBJECT_MATCH, relcheck 0. A compile without -DMULTICAST (s5p206-nomc) succeeds.
