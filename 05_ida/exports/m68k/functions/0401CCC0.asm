0401CCC0: 4856                     pea     (a6)
0401CCC2: 2c4f                     movea.l sp,a6
0401CCC4: 206e0008                 movea.l 8(a6),a0
0401CCC8: 316e000e000c             move.w  $E(a6),$C(a0)
0401CCCE: 4e5e                     unlk    a6
0401CCD0: 4e75                     rts
