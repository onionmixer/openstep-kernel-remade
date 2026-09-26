0407A3CC: 4856                     pea     (a6)
0407A3CE: 2c4f                     movea.l sp,a6
0407A3D0: 206e0008                 movea.l 8(a6),a0
0407A3D4: 7001                     moveq   #1,d0
0407A3D6: 4840                     swap    d0
0407A3D8: 0c790139040c32d0         cmpi.w  #$139,(_dma_chip).l
0407A3E0: 6606                     bne.s   loc_407A3E8
0407A3E2: 203c00002000             move.l  #$2000,d0
0407A3E8: b0a80014                 cmp.l   $14(a0),d0
0407A3EC: 6c04                     bge.s   loc_407A3F2
0407A3EE: 21400014                 move.l  d0,$14(a0)
0407A3F2: 4e5e                     unlk    a6
0407A3F4: 4e75                     rts
