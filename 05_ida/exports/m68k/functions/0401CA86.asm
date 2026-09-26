0401CA86: 4856                     pea     (a6)
0401CA88: 2c4f                     movea.l sp,a6
0401CA8A: 206e0008                 movea.l 8(a6),a0
0401CA8E: 322e000e                 move.w  $E(a6),d1
0401CA92: 93680008                 sub.w   d1,8(a0)
0401CA96: 4280                     clr.l   d0
0401CA98: 4e5e                     unlk    a6
0401CA9A: 4e75                     rts
