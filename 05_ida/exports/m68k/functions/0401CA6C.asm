0401CA6C: 4856                     pea     (a6)
0401CA6E: 2c4f                     movea.l sp,a6
0401CA70: 206e0008                 movea.l 8(a6),a0
0401CA74: 202e000c                 move.l  $C(a6),d0
0401CA78: d1680008                 add.w   d0,8(a0)
0401CA7C: 91a80004                 sub.l   d0,4(a0)
0401CA80: 4280                     clr.l   d0
0401CA82: 4e5e                     unlk    a6
0401CA84: 4e75                     rts
