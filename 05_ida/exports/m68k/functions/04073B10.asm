04073B10: 4856                     pea     (a6)
04073B12: 2c4f                     movea.l sp,a6
04073B14: 42a7                     clr.l   -(sp)
04073B16: 2f2e0014                 move.l  $14(a6),-(sp)
04073B1A: 2f2e0010                 move.l  $10(a6),-(sp)
04073B1E: 2f2e000c                 move.l  $C(a6),-(sp)
04073B22: 306e000a                 movea.w $A(a6),a0
04073B26: 2f08                     move.l  a0,-(sp)
04073B28: 61ff0000002c             bsr.l   sub_4073B56
04073B2E: 4e5e                     unlk    a6
04073B30: 4e75                     rts
