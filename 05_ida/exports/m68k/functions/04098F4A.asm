04098F4A: 4856                     pea     (a6)
04098F4C: 2c4f                     movea.l sp,a6
04098F4E: 2f2e0010                 move.l  $10(a6),-(sp)
04098F52: 2f2e000c                 move.l  $C(a6),-(sp)
04098F56: 2f2e0008                 move.l  8(a6),-(sp)
04098F5A: 61ffffff9dd0             bsr.l   _bcopy
04098F60: 4e5e                     unlk    a6
04098F62: 4e75                     rts
