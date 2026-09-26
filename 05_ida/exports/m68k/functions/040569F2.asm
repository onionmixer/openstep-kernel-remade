040569F2: 4856                     pea     (a6)
040569F4: 2c4f                     movea.l sp,a6
040569F6: 226e0008                 movea.l 8(a6),a1
040569FA: 206e000c                 movea.l $C(a6),a0
040569FE: 2091                     move.l  (a1),(a0)
04056A00: 4280                     clr.l   d0
04056A02: 4e5e                     unlk    a6
04056A04: 4e75                     rts
