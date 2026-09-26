0401C9BC: 4856                     pea     (a6)
0401C9BE: 2c4f                     movea.l sp,a6
0401C9C0: 206e0008                 movea.l 8(a6),a0
0401C9C4: 30280008                 move.w  8(a0),d0
0401C9C8: 48c0                     ext.l   d0
0401C9CA: 4e5e                     unlk    a6
0401C9CC: 4e75                     rts
