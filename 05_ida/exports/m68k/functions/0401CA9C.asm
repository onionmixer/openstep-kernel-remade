0401CA9C: 4856                     pea     (a6)
0401CA9E: 2c4f                     movea.l sp,a6
0401CAA0: 206e0008                 movea.l 8(a6),a0
0401CAA4: 322e000e                 move.w  $E(a6),d1
0401CAA8: d3680008                 add.w   d1,8(a0)
0401CAAC: 4280                     clr.l   d0
0401CAAE: 4e5e                     unlk    a6
0401CAB0: 4e75                     rts
