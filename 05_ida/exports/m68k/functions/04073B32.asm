04073B32: 4856                     pea     (a6)
04073B34: 2c4f                     movea.l sp,a6
04073B36: 48780001                 pea     (1).w
04073B3A: 2f2e0014                 move.l  $14(a6),-(sp)
04073B3E: 2f2e0010                 move.l  $10(a6),-(sp)
04073B42: 2f2e000c                 move.l  $C(a6),-(sp)
04073B46: 306e000a                 movea.w $A(a6),a0
04073B4A: 2f08                     move.l  a0,-(sp)
04073B4C: 61ff00000008             bsr.l   sub_4073B56
04073B52: 4e5e                     unlk    a6
04073B54: 4e75                     rts
