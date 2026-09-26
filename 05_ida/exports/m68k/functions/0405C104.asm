0405C104: 4856                     pea     (a6)
0405C106: 2c4f                     movea.l sp,a6
0405C108: 206e0008                 movea.l 8(a6),a0
0405C10C: 20280014                 move.l  $14(a0),d0
0405C110: 0680fffff448             addi.l  #-$BB8,d0
0405C116: 7215                     moveq   #$15,d1
0405C118: b280                     cmp.l   d0,d1
0405C11A: 650c                     bcs.s   loc_405C128
0405C11C: 41f9040b065c             lea     (unk_40B065C).l,a0
0405C122: 20300c00                 move.l  (a0,d0.l*4),d0
0405C126: 6002                     bra.s   loc_405C12A
0405C128: 4280                     clr.l   d0
0405C12A: 4e5e                     unlk    a6
0405C12C: 4e75                     rts
