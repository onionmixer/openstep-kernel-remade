04050AC4: 4856                     pea     (a6)
04050AC6: 2c4f                     movea.l sp,a6
04050AC8: 206e0008                 movea.l 8(a6),a0
04050ACC: 222e000c                 move.l  $C(a6),d1
04050AD0: 40c0                     move    sr,d0
04050AD2: 46fc2300                 move    #$2300,sr
04050AD6: 48c0                     ext.l   d0
04050AD8: 2141017c                 move.l  d1,$17C(a0)
04050ADC: 40c1                     move    sr,d1
04050ADE: 46c0                     move    d0,sr
04050AE0: 4e5e                     unlk    a6
04050AE2: 4e75                     rts
