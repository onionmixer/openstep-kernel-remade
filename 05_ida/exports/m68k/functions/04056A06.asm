04056A06: 4856                     pea     (a6)
04056A08: 2c4f                     movea.l sp,a6
04056A0A: 206e0008                 movea.l 8(a6),a0
04056A0E: 202e000c                 move.l  $C(a6),d0
04056A12: 2050                     movea.l (a0),a0
04056A14: 7201                     moveq   #1,d1
04056A16: b280                     cmp.l   d0,d1
04056A18: 6c08                     bge.s   loc_4056A22
04056A1A: 214004c8                 move.l  d0,$4C8(a0)
04056A1E: 4280                     clr.l   d0
04056A20: 6002                     bra.s   loc_4056A24
04056A22: 7067                     moveq   #$67,d0 ; 'g'
04056A24: 4e5e                     unlk    a6
04056A26: 4e75                     rts
