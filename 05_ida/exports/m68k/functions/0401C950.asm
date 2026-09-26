0401C950: 4856                     pea     (a6)
0401C952: 2c4f                     movea.l sp,a6
0401C954: 42a7                     clr.l   -(sp)
0401C956: 2f2e000c                 move.l  $C(a6),-(sp)
0401C95A: 2f2e0008                 move.l  8(a6),-(sp)
0401C95E: 2f2e0014                 move.l  $14(a6),-(sp)
0401C962: 2f2e0010                 move.l  $10(a6),-(sp)
0401C966: 61ffffff5d30             bsr.l   _mclgetx
0401C96C: 2200                     move.l  d0,d1
0401C96E: 4280                     clr.l   d0
0401C970: 4a81                     tst.l   d1
0401C972: 6702                     beq.s   loc_401C976
0401C974: 2001                     move.l  d1,d0
0401C976: 4e5e                     unlk    a6
0401C978: 4e75                     rts
