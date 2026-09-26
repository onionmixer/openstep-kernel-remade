0401CCB0: 4856                     pea     (a6)
0401CCB2: 2c4f                     movea.l sp,a6
0401CCB4: 206e0008                 movea.l 8(a6),a0
0401CCB8: 20280052                 move.l  $52(a0),d0
0401CCBC: 4e5e                     unlk    a6
0401CCBE: 4e75                     rts
