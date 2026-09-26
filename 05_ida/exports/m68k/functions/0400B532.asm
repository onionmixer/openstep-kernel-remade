0400B532: 4856                     pea     (a6)
0400B534: 2c4f                     movea.l sp,a6
0400B536: 2f2e000c                 move.l  $C(a6),-(sp)
0400B53A: 2f2e0008                 move.l  8(a6),-(sp)
0400B53E: 486e0014                 pea     $14(a6)
0400B542: 2f2e0010                 move.l  $10(a6),-(sp)
0400B546: 61ff00000008             bsr.l   _prf
0400B54C: 4e5e                     unlk    a6
0400B54E: 4e75                     rts
