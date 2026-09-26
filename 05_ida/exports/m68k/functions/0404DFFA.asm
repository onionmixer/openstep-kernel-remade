0404DFFA: 4856                     pea     (a6)
0404DFFC: 2c4f                     movea.l sp,a6
0404DFFE: 206e0008                 movea.l 8(a6),a0
0404E002: 2050                     movea.l (a0),a0
0404E004: 216e000c0030             move.l  $C(a6),$30(a0)
0404E00A: 4e5e                     unlk    a6
0404E00C: 4e75                     rts
