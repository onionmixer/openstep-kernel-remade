0404AB6C: 4856                     pea     (a6)
0404AB6E: 2c4f                     movea.l sp,a6
0404AB70: 2f0a                     move.l  a2,-(sp)
0404AB72: 2f02                     move.l  d2,-(sp)
0404AB74: 246e0008                 movea.l 8(a6),a2
0404AB78: 242e000c                 move.l  $C(a6),d2
0404AB7C: 48780008                 pea     (8).w
0404AB80: 2f0a                     move.l  a2,-(sp)
0404AB82: 61ff0004828e             bsr.l   _bzero
0404AB88: 022a003f0006             andi.b  #$3F,6(a2) ; '?'
0404AB8E: 426a0004                 clr.w   4(a2)
0404AB92: 02020001                 andi.b  #1,d2
0404AB96: efea20c10006             bfins   d2,6(a2){3:1}
0404AB9C: 72ff                     moveq   #$FFFFFFFF,d1
0404AB9E: 2481                     move.l  d1,(a2)
0404ABA0: 026af0000006             andi.w  #$F000,6(a2)
0404ABA6: 242efff8                 move.l  -8(a6),d2
0404ABAA: 246efffc                 movea.l -4(a6),a2
0404ABAE: 4e5e                     unlk    a6
0404ABB0: 4e75                     rts
