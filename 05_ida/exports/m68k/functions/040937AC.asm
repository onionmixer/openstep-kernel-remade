040937AC: 4856                     pea     (a6)
040937AE: 2c4f                     movea.l sp,a6
040937B0: 2f2e000c                 move.l  $C(a6),-(sp)
040937B4: 487904093792             pea     (sub_4093792).l
040937BA: 48780004                 pea     (4).w
040937BE: 61ff000006c0             bsr.l   _callout_dispatch
040937C4: 4e5e                     unlk    a6
040937C6: 4e75                     rts
