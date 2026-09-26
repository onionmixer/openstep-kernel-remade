04006730: 4856                     pea     (a6)
04006732: 2c4f                     movea.l sp,a6
04006734: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400673A: 2179040b6538005c         move.l  (_m68k_page_size).l,$5C(a0)
04006742: 4e5e                     unlk    a6
04006744: 4e75                     rts
