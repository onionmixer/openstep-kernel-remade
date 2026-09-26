040591F8: 4856                     pea     (a6)
040591FA: 2c4f                     movea.l sp,a6
040591FC: 206e0008                 movea.l 8(a6),a0
04059200: 20280014                 move.l  $14(a0),d0
04059204: 0680fffff5d8             addi.l  #-$A28,d0
0405920A: 7229                     moveq   #$29,d1 ; ')'
0405920C: b280                     cmp.l   d0,d1
0405920E: 650c                     bcs.s   loc_405921C
04059210: 41f9040b005c             lea     (unk_40B005C).l,a0
04059216: 20300c00                 move.l  (a0,d0.l*4),d0
0405921A: 6002                     bra.s   loc_405921E
0405921C: 4280                     clr.l   d0
0405921E: 4e5e                     unlk    a6
04059220: 4e75                     rts
