0401CCA0: 4856                     pea     (a6)
0401CCA2: 2c4f                     movea.l sp,a6
0401CCA4: 206e0008                 movea.l 8(a6),a0
0401CCA8: 20280046                 move.l  $46(a0),d0
0401CCAC: 4e5e                     unlk    a6
0401CCAE: 4e75                     rts
