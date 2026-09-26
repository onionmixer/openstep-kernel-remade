04098F7E: 4856                     pea     (a6)
04098F80: 2c4f                     movea.l sp,a6
04098F82: 2f2e0018                 move.l  $18(a6),-(sp)
04098F86: 2f2e0014                 move.l  $14(a6),-(sp)
04098F8A: 2f2e0010                 move.l  $10(a6),-(sp)
04098F8E: 2f2e000c                 move.l  $C(a6),-(sp)
04098F92: 2f2e0008                 move.l  8(a6),-(sp)
04098F96: 61fffff99ada             bsr.l   _uncompress_data
04098F9C: 4e5e                     unlk    a6
04098F9E: 4e75                     rts
