04043B1A: 4856                     pea     (a6)
04043B1C: 2c4f                     movea.l sp,a6
04043B1E: 2f0a                     move.l  a2,-(sp)
04043B20: 206e0008                 movea.l 8(a6),a0
04043B24: 246e000c                 movea.l $C(a6),a2
04043B28: 2250                     movea.l (a0),a1
04043B2A: 4a89                     tst.l   a1
04043B2C: 6604                     bne.s   loc_4043B32
04043B2E: 208a                     move.l  a2,(a0)
04043B30: 6014                     bra.s   loc_4043B46
04043B32: 20690090                 movea.l $90(a1),a0
04043B36: 2549008c                 move.l  a1,$8C(a2)
04043B3A: 25480090                 move.l  a0,$90(a2)
04043B3E: 234a0090                 move.l  a2,$90(a1)
04043B42: 214a008c                 move.l  a2,$8C(a0)
04043B46: 246efffc                 movea.l -4(a6),a2
04043B4A: 4e5e                     unlk    a6
04043B4C: 4e75                     rts
