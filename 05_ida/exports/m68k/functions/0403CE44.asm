0403CE44: 4856                     pea     (a6)
0403CE46: 2c4f                     movea.l sp,a6
0403CE48: 226e0008                 movea.l 8(a6),a1
0403CE4C: 206e000c                 movea.l $C(a6),a0
0403CE50: 2010                     move.l  (a0),d0
0403CE52: b091                     cmp.l   (a1),d0
0403CE54: 6602                     bne.s   loc_403CE58
0403CE56: 4280                     clr.l   d0
0403CE58: 4e5e                     unlk    a6
0403CE5A: 4e75                     rts
