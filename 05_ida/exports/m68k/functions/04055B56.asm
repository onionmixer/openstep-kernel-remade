04055B56: 4856                     pea     (a6)
04055B58: 2c4f                     movea.l sp,a6
04055B5A: 48780001                 pea     (1).w
04055B5E: 2f2e0008                 move.l  8(a6),-(sp)
04055B62: 61fffffffd3a             bsr.l   sub_405589E
04055B68: 4e5e                     unlk    a6
04055B6A: 4e75                     rts
