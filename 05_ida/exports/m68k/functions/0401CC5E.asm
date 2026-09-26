0401CC5E: 4856                     pea     (a6)
0401CC60: 2c4f                     movea.l sp,a6
0401CC62: 206e0008                 movea.l 8(a6),a0
0401CC66: 3028000c                 move.w  $C(a0),d0
0401CC6A: 48c0                     ext.l   d0
0401CC6C: 4e5e                     unlk    a6
0401CC6E: 4e75                     rts
