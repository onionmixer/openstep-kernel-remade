04098F30: 4856                     pea     (a6)
04098F32: 2c4f                     movea.l sp,a6
04098F34: 2f2e0010                 move.l  $10(a6),-(sp)
04098F38: 2f2e000c                 move.l  $C(a6),-(sp)
04098F3C: 2f2e0008                 move.l  8(a6),-(sp)
04098F40: 61ffffff9dea             bsr.l   _bcopy
04098F46: 4e5e                     unlk    a6
04098F48: 4e75                     rts
