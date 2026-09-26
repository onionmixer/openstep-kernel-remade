0400C010: 4e56ffe0                 link    a6,#-$20
0400C014: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400C01A: 20680024                 movea.l $24(a0),a0
0400C01E: 43eeffe2                 lea     var_1E(a6),a1
0400C022: 2d49ffea                 move.l  a1,var_16(a6)
0400C026: 7201                     moveq   #1,d1
0400C028: 2d41ffee                 move.l  d1,var_12(a6)
0400C02C: 2d680004ffe2             move.l  4(a0),var_1E(a6)
0400C032: 2d680008ffe6             move.l  8(a0),var_1A(a6)
0400C038: 48780001                 pea     (1).w
0400C03C: 486effea                 pea     var_16(a6)
0400C040: 61ff00000074             bsr.l   _rwuio
0400C046: 4e5e                     unlk    a6
0400C048: 4e75                     rts
