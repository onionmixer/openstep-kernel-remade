0403076C: 4856                     pea     (a6)
0403076E: 2c4f                     movea.l sp,a6
04030770: 206e0008                 movea.l 8(a6),a0
04030774: 226e000c                 movea.l $C(a6),a1
04030778: 4280                     clr.l   d0
0403077A: 22280014                 move.l  $14(a0),d1
0403077E: b3c1                     cmpa.l  d1,a1
04030780: 6e10                     bgt.s   loc_4030792
04030782: 9289                     sub.l   a1,d1
04030784: 21410014                 move.l  d1,$14(a0)
04030788: 2028000c                 move.l  $C(a0),d0
0403078C: d3c0                     adda.l  d0,a1
0403078E: 2149000c                 move.l  a1,$C(a0)
04030792: 4e5e                     unlk    a6
04030794: 4e75                     rts
