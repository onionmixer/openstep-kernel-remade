0404F818: 4856                     pea     (a6)
0404F81A: 2c4f                     movea.l sp,a6
0404F81C: 206e000c                 movea.l $C(a6),a0
0404F820: 2250                     movea.l (a0),a1
0404F822: 236800040004             move.l  4(a0),4(a1)
0404F828: 22680004                 movea.l 4(a0),a1
0404F82C: 2290                     move.l  (a0),(a1)
0404F82E: 4e5e                     unlk    a6
0404F830: 4e75                     rts
