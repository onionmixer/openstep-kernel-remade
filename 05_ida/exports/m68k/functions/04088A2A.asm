04088A2A: 4856                     pea     (a6)
04088A2C: 2c4f                     movea.l sp,a6
04088A2E: 42a7                     clr.l   -(sp)
04088A30: 2f2e000c                 move.l  $C(a6),-(sp)
04088A34: 306e000a                 movea.w $A(a6),a0
04088A38: 2f08                     move.l  a0,-(sp)
04088A3A: 61ff00000024             bsr.l   sub_4088A60
04088A40: 4e5e                     unlk    a6
04088A42: 4e75                     rts
