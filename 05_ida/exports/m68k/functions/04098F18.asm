04098F18: 4856                     pea     (a6)
04098F1A: 2c4f                     movea.l sp,a6
04098F1C: 2f39040b06d0             move.l  (_page_size).l,-(sp)
04098F22: 2f2e0008                 move.l  8(a6),-(sp)
04098F26: 61ffffff9eea             bsr.l   _bzero
04098F2C: 4e5e                     unlk    a6
04098F2E: 4e75                     rts
