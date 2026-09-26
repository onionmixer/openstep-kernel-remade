04056CC4: 4856                     pea     (a6)
04056CC6: 2c4f                     movea.l sp,a6
04056CC8: 206e0008                 movea.l 8(a6),a0
04056CCC: 2050                     movea.l (a0),a0
04056CCE: 216e000c04b8             move.l  $C(a6),$4B8(a0)
04056CD4: 4280                     clr.l   d0
04056CD6: 4e5e                     unlk    a6
04056CD8: 4e75                     rts
