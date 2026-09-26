0401CBFC: 4856                     pea     (a6)
0401CBFE: 2c4f                     movea.l sp,a6
0401CC00: 206e0008                 movea.l 8(a6),a0
0401CC04: 20280056                 move.l  $56(a0),d0
0401CC08: 4e5e                     unlk    a6
0401CC0A: 4e75                     rts
