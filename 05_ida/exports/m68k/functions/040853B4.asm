040853B4: 4856                     pea     (a6)
040853B6: 2c4f                     movea.l sp,a6
040853B8: 48780138                 pea     ($138).w
040853BC: 2f2e000c                 move.l  $C(a6),-(sp)
040853C0: 2f2e0008                 move.l  8(a6),-(sp)
040853C4: 61fffffffd48             bsr.l   sub_408510E
040853CA: 4e5e                     unlk    a6
040853CC: 4e75                     rts
