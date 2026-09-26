04003618: 4856                     pea     (a6)
0400361A: 2c4f                     movea.l sp,a6
0400361C: 2f2e000c                 move.l  $C(a6),-(sp)
04003620: 2f2e0008                 move.l  8(a6),-(sp)
04003624: 61ff0004b03e             bsr.l   _ns_untimeout
0400362A: 4e5e                     unlk    a6
0400362C: 4e75                     rts
