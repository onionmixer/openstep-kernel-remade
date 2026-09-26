0405DEBC: 4856                     pea     (a6)
0405DEBE: 2c4f                     movea.l sp,a6
0405DEC0: 206e0008                 movea.l 8(a6),a0
0405DEC4: 4a88                     tst.l   a0
0405DEC6: 6704                     beq.s   loc_405DECC
0405DEC8: 52a8002c                 addq.l  #1,$2C(a0)
0405DECC: 4e5e                     unlk    a6
0405DECE: 4e75                     rts
