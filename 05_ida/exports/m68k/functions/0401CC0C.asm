0401CC0C: 4856                     pea     (a6)
0401CC0E: 2c4f                     movea.l sp,a6
0401CC10: 206e0008                 movea.l 8(a6),a0
0401CC14: 30280008                 move.w  8(a0),d0
0401CC18: 48c0                     ext.l   d0
0401CC1A: 4e5e                     unlk    a6
0401CC1C: 4e75                     rts
