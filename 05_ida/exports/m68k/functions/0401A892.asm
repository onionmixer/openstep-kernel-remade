0401A892: 4856                     pea     (a6)
0401A894: 2c4f                     movea.l sp,a6
0401A896: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A89C: 42a7                     clr.l   -(sp)
0401A89E: 2f280024                 move.l  $24(a0),-(sp)
0401A8A2: 61ff00000012             bsr.l   _stat1
0401A8A8: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A8AE: 11400064                 move.b  d0,$64(a0)
0401A8B2: 4e5e                     unlk    a6
0401A8B4: 4e75                     rts
