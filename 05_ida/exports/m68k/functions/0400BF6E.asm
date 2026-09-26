0400BF6E: 4e56ffe0                 link    a6,#-$20
0400BF72: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400BF78: 20680024                 movea.l $24(a0),a0
0400BF7C: 2d680004ffe2             move.l  4(a0),var_1E(a6)
0400BF82: 2d680008ffe6             move.l  8(a0),var_1A(a6)
0400BF88: 43eeffe2                 lea     var_1E(a6),a1
0400BF8C: 2d49ffea                 move.l  a1,var_16(a6)
0400BF90: 7201                     moveq   #1,d1
0400BF92: 2d41ffee                 move.l  d1,var_12(a6)
0400BF96: 42a7                     clr.l   -(sp)
0400BF98: 486effea                 pea     var_16(a6)
0400BF9C: 61ff00000118             bsr.l   _rwuio
0400BFA2: 4e5e                     unlk    a6
0400BFA4: 4e75                     rts
