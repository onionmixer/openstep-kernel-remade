0406D082: 4856                     pea     (a6)
0406D084: 2c4f                     movea.l sp,a6
0406D086: 206e0008                 movea.l 8(a6),a0
0406D08A: 10280025                 move.b  $25(a0),d0
0406D08E: 802e000f                 or.b    $F(a6),d0
0406D092: 11400025                 move.b  d0,$25(a0)
0406D096: 2050                     movea.l (a0),a0
0406D098: 11400008                 move.b  d0,8(a0)
0406D09C: 4e5e                     unlk    a6
0406D09E: 4e75                     rts
