0405FB04: 4856                     pea     (a6)
0405FB06: 2c4f                     movea.l sp,a6
0405FB08: 206e0008                 movea.l 8(a6),a0
0405FB0C: 4a88                     tst.l   a0
0405FB0E: 6704                     beq.s   loc_405FB14
0405FB10: 52680014                 addq.w  #1,$14(a0)
0405FB14: 4e5e                     unlk    a6
0405FB16: 4e75                     rts
