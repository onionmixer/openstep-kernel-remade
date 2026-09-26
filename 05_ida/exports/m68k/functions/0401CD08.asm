0401CD08: 4856                     pea     (a6)
0401CD0A: 2c4f                     movea.l sp,a6
0401CD0C: 206e0008                 movea.l 8(a6),a0
0401CD10: 216e000c0046             move.l  $C(a6),$46(a0)
0401CD16: 4e5e                     unlk    a6
0401CD18: 4e75                     rts
