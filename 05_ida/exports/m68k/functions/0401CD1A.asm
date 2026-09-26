0401CD1A: 4856                     pea     (a6)
0401CD1C: 2c4f                     movea.l sp,a6
0401CD1E: 206e0008                 movea.l 8(a6),a0
0401CD22: 216e000c0052             move.l  $C(a6),$52(a0)
0401CD28: 4e5e                     unlk    a6
0401CD2A: 4e75                     rts
