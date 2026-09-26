040852C2: 4856                     pea     (a6)
040852C4: 2c4f                     movea.l sp,a6
040852C6: 4878012d                 pea     ($12D).w
040852CA: 2f2e000c                 move.l  $C(a6),-(sp)
040852CE: 2f2e0008                 move.l  8(a6),-(sp)
040852D2: 61fffffffe3a             bsr.l   sub_408510E
040852D8: 4e5e                     unlk    a6
040852DA: 4e75                     rts
