0407BB06: 4856                     pea     (a6)
0407BB08: 2c4f                     movea.l sp,a6
0407BB0A: 206e0008                 movea.l 8(a6),a0
0407BB0E: 7001                     moveq   #1,d0
0407BB10: 4840                     swap    d0
0407BB12: 0c790139040c32d0         cmpi.w  #$139,(_dma_chip).l
0407BB1A: 6606                     bne.s   loc_407BB22
0407BB1C: 203c00002000             move.l  #$2000,d0
0407BB22: b0a80014                 cmp.l   $14(a0),d0
0407BB26: 6c04                     bge.s   loc_407BB2C
0407BB28: 21400014                 move.l  d0,$14(a0)
0407BB2C: 4e5e                     unlk    a6
0407BB2E: 4e75                     rts
