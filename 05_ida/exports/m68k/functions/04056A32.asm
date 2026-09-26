04056A32: 4856                     pea     (a6)
04056A34: 2c4f                     movea.l sp,a6
04056A36: 206e0008                 movea.l 8(a6),a0
04056A3A: 2050                     movea.l (a0),a0
04056A3C: 216e000c0010             move.l  $C(a6),$10(a0)
04056A42: 4280                     clr.l   d0
04056A44: 4e5e                     unlk    a6
04056A46: 4e75                     rts
