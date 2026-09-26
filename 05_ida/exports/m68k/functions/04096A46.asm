04096A46: 4856                     pea     (a6)
04096A48: 2c4f                     movea.l sp,a6
04096A4A: 226e0008                 movea.l 8(a6),a1
04096A4E: 20690024                 movea.l $24(a1),a0
04096A52: 4aa8004c                 tst.l   $4C(a0)
04096A56: 6706                     beq.s   loc_4096A5E
04096A58: 20680048                 movea.l $48(a0),a0
04096A5C: 600a                     bra.s   loc_4096A68
04096A5E: 2f09                     move.l  a1,-(sp)
04096A60: 61fffffffef0             bsr.l   _thread_user_state
04096A66: 2040                     movea.l d0,a0
04096A68: 20ae000c                 move.l  $C(a6),(a0)
04096A6C: 4e5e                     unlk    a6
04096A6E: 4e75                     rts
