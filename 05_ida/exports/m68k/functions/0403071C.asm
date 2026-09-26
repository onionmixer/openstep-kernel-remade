0403071C: 4856                     pea     (a6)
0403071E: 2c4f                     movea.l sp,a6
04030720: 226e0008                 movea.l 8(a6),a1
04030724: 20690010                 movea.l $10(a1),a0
04030728: d1e80004                 adda.l  4(a0),a0
0403072C: 2029000c                 move.l  $C(a1),d0
04030730: 9088                     sub.l   a0,d0
04030732: 4e5e                     unlk    a6
04030734: 4e75                     rts
