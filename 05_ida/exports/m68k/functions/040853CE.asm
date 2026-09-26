040853CE: 4856                     pea     (a6)
040853D0: 2c4f                     movea.l sp,a6
040853D2: 48780139                 pea     ($139).w
040853D6: 2f2e000c                 move.l  $C(a6),-(sp)
040853DA: 2f2e0008                 move.l  8(a6),-(sp)
040853DE: 61fffffffd2e             bsr.l   sub_408510E
040853E4: 4e5e                     unlk    a6
040853E6: 4e75                     rts
