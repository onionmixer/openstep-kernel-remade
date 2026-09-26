04088A44: 4856                     pea     (a6)
04088A46: 2c4f                     movea.l sp,a6
04088A48: 48780001                 pea     (1).w
04088A4C: 2f2e000c                 move.l  $C(a6),-(sp)
04088A50: 306e000a                 movea.w $A(a6),a0
04088A54: 2f08                     move.l  a0,-(sp)
04088A56: 61ff00000008             bsr.l   sub_4088A60
04088A5C: 4e5e                     unlk    a6
04088A5E: 4e75                     rts
