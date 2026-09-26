0401CC80: 4856                     pea     (a6)
0401CC82: 2c4f                     movea.l sp,a6
0401CC84: 206e0008                 movea.l 8(a6),a0
0401CC88: 20280042                 move.l  $42(a0),d0
0401CC8C: 4e5e                     unlk    a6
0401CC8E: 4e75                     rts
