0401C97A: 4856                     pea     (a6)
0401C97C: 2c4f                     movea.l sp,a6
0401C97E: 206e0008                 movea.l 8(a6),a0
0401C982: 2008                     move.l  a0,d0
0401C984: d0a80004                 add.l   4(a0),d0
0401C988: 4e5e                     unlk    a6
0401C98A: 4e75                     rts
