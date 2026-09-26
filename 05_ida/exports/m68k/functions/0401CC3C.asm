0401CC3C: 4856                     pea     (a6)
0401CC3E: 2c4f                     movea.l sp,a6
0401CC40: 206e0008                 movea.l 8(a6),a0
0401CC44: 3028000a                 move.w  $A(a0),d0
0401CC48: 48c0                     ext.l   d0
0401CC4A: 4e5e                     unlk    a6
0401CC4C: 4e75                     rts
