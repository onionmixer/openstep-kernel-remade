0400FA20: 4856                     pea     (a6)
0400FA22: 2c4f                     movea.l sp,a6
0400FA24: 226e0008                 movea.l 8(a6),a1
0400FA28: 20690024                 movea.l $24(a1),a0
0400FA2C: 4a88                     tst.l   a0
0400FA2E: 6704                     beq.s   loc_400FA34
0400FA30: 2f09                     move.l  a1,-(sp)
0400FA32: 4e90                     jsr     (a0)
0400FA34: 4e5e                     unlk    a6
0400FA36: 4e75                     rts
