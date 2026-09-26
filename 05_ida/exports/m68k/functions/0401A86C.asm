0401A86C: 4856                     pea     (a6)
0401A86E: 2c4f                     movea.l sp,a6
0401A870: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A876: 48780001                 pea     (1).w
0401A87A: 2f280024                 move.l  $24(a0),-(sp)
0401A87E: 61ff00000036             bsr.l   _stat1
0401A884: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A88A: 11400064                 move.b  d0,$64(a0)
0401A88E: 4e5e                     unlk    a6
0401A890: 4e75                     rts
