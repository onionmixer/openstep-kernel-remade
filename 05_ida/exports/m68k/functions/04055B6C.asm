04055B6C: 4856                     pea     (a6)
04055B6E: 2c4f                     movea.l sp,a6
04055B70: 42a7                     clr.l   -(sp)
04055B72: 2f2e0008                 move.l  8(a6),-(sp)
04055B76: 61fffffffd26             bsr.l   sub_405589E
04055B7C: 4e5e                     unlk    a6
04055B7E: 4e75                     rts
