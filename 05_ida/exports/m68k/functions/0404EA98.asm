0404EA98: 4856                     pea     (a6)
0404EA9A: 2c4f                     movea.l sp,a6
0404EA9C: 2f2e000c                 move.l  $C(a6),-(sp)
0404EAA0: 2f2e0008                 move.l  8(a6),-(sp)
0404EAA4: 61fffffffbbe             bsr.l   _ns_untimeout
0404EAAA: 4e5e                     unlk    a6
0404EAAC: 4e75                     rts
