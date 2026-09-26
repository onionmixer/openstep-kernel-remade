0408539A: 4856                     pea     (a6)
0408539C: 2c4f                     movea.l sp,a6
0408539E: 48780137                 pea     ($137).w
040853A2: 2f2e000c                 move.l  $C(a6),-(sp)
040853A6: 2f2e0008                 move.l  8(a6),-(sp)
040853AA: 61fffffffd62             bsr.l   sub_408510E
040853B0: 4e5e                     unlk    a6
040853B2: 4e75                     rts
