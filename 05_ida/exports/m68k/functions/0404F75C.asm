0404F75C: 4856                     pea     (a6)
0404F75E: 2c4f                     movea.l sp,a6
0404F760: 48780001                 pea     (1).w
0404F764: 2f2e0010                 move.l  $10(a6),-(sp)
0404F768: 2f2e000c                 move.l  $C(a6),-(sp)
0404F76C: 2f2e0008                 move.l  8(a6),-(sp)
0404F770: 61fffffffe26             bsr.l   _processor_set_things
0404F776: 4e5e                     unlk    a6
0404F778: 4e75                     rts
