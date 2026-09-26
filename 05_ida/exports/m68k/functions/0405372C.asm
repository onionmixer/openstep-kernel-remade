0405372C: 4856                     pea     (a6)
0405372E: 2c4f                     movea.l sp,a6
04053730: 206e0008                 movea.l 8(a6),a0
04053734: 216e000c0030             move.l  $C(a6),$30(a0)
0405373A: 4e5e                     unlk    a6
0405373C: 4e75                     rts
