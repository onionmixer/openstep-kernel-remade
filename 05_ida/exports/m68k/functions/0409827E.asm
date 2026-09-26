0409827E: 4856                     pea     (a6)
04098280: 2c4f                     movea.l sp,a6
04098282: 42a7                     clr.l   -(sp)
04098284: 48780001                 pea     (1).w
04098288: 2f2e0018                 move.l  $18(a6),-(sp)
0409828C: 2f2e0014                 move.l  $14(a6),-(sp)
04098290: 2f2e0010                 move.l  $10(a6),-(sp)
04098294: 2f2e000c                 move.l  $C(a6),-(sp)
04098298: 2f2e0008                 move.l  8(a6),-(sp)
0409829C: 61ff00000008             bsr.l   _pmap_enter_mapping
040982A2: 4e5e                     unlk    a6
040982A4: 4e75                     rts
