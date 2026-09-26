04085380: 4856                     pea     (a6)
04085382: 2c4f                     movea.l sp,a6
04085384: 48780136                 pea     ($136).w
04085388: 2f2e000c                 move.l  $C(a6),-(sp)
0408538C: 2f2e0008                 move.l  8(a6),-(sp)
04085390: 61fffffffd7c             bsr.l   sub_408510E
04085396: 4e5e                     unlk    a6
04085398: 4e75                     rts
