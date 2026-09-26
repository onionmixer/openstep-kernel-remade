040526D6: 4856                     pea     (a6)
040526D8: 2c4f                     movea.l sp,a6
040526DA: 2f2e000c                 move.l  $C(a6),-(sp)
040526DE: 4879040b6648             pea     (_default_pset).l
040526E4: 2f2e0008                 move.l  8(a6),-(sp)
040526E8: 61ffffffffe2             bsr.l   _task_assign
040526EE: 4e5e                     unlk    a6
040526F0: 4e75                     rts
