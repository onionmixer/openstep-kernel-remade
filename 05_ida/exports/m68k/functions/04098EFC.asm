04098EFC: 4856                     pea     (a6)
04098EFE: 2c4f                     movea.l sp,a6
04098F00: 2f39040b06d0             move.l  (_page_size).l,-(sp)
04098F06: 2f2e000c                 move.l  $C(a6),-(sp)
04098F0A: 2f2e0008                 move.l  8(a6),-(sp)
04098F0E: 61ffffff9e1c             bsr.l   _bcopy
04098F14: 4e5e                     unlk    a6
04098F16: 4e75                     rts
