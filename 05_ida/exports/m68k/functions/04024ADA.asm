04024ADA: 4856                     pea     (a6)
04024ADC: 2c4f                     movea.l sp,a6
04024ADE: 206e0008                 movea.l 8(a6),a0
04024AE2: 2068001c                 movea.l $1C(a0),a0
04024AE6: 4a88                     tst.l   a0
04024AE8: 6706                     beq.s   loc_4024AF0
04024AEA: 316800180054             move.w  $18(a0),$54(a0)
04024AF0: 4e5e                     unlk    a6
04024AF2: 4e75                     rts
