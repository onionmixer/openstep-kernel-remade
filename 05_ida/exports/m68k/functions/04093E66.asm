04093E66: 4856                     pea     (a6)
04093E68: 2c4f                     movea.l sp,a6
04093E6A: 2f2e0010                 move.l  $10(a6),-(sp)
04093E6E: 2f2e000c                 move.l  $C(a6),-(sp)
04093E72: 2f2e0008                 move.l  8(a6),-(sp)
04093E76: 61ff00000008             bsr.l   _callout_dispatch
04093E7C: 4e5e                     unlk    a6
04093E7E: 4e75                     rts
