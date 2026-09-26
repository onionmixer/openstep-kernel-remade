0404F856: 4856                     pea     (a6)
0404F858: 2c4f                     movea.l sp,a6
0404F85A: 206e0008                 movea.l 8(a6),a0
0404F85E: 2250                     movea.l (a0),a1
0404F860: 236800040004             move.l  4(a0),4(a1)
0404F866: 22680004                 movea.l 4(a0),a1
0404F86A: 2290                     move.l  (a0),(a1)
0404F86C: 2008                     move.l  a0,d0
0404F86E: 4e5e                     unlk    a6
0404F870: 4e75                     rts
