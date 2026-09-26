0401CA52: 4856                     pea     (a6)
0401CA54: 2c4f                     movea.l sp,a6
0401CA56: 206e0008                 movea.l 8(a6),a0
0401CA5A: 202e000c                 move.l  $C(a6),d0
0401CA5E: 91680008                 sub.w   d0,8(a0)
0401CA62: d1a80004                 add.l   d0,4(a0)
0401CA66: 4280                     clr.l   d0
0401CA68: 4e5e                     unlk    a6
0401CA6A: 4e75                     rts
