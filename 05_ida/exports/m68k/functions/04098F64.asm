04098F64: 4856                     pea     (a6)
04098F66: 2c4f                     movea.l sp,a6
04098F68: 2f2e0010                 move.l  $10(a6),-(sp)
04098F6C: 2f2e000c                 move.l  $C(a6),-(sp)
04098F70: 2f2e0008                 move.l  8(a6),-(sp)
04098F74: 61fffff99a88             bsr.l   _compress_data
04098F7A: 4e5e                     unlk    a6
04098F7C: 4e75                     rts
