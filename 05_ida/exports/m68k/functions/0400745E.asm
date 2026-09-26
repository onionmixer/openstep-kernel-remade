0400745E: 4856                     pea     (a6)
04007460: 2c4f                     movea.l sp,a6
04007462: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04007468: 2279040b57d0             movea.l (_active_u).l,a1
0400746E: 2251                     movea.l (a1),a1
04007470: e9e900410016             bfextu  $16(a1){1:1},d0
04007476: 2140005c                 move.l  d0,$5C(a0)
0400747A: 4e5e                     unlk    a6
0400747C: 4e75                     rts
