0402DE68: 4856                     pea     (a6)
0402DE6A: 2c4f                     movea.l sp,a6
0402DE6C: 2f0a                     move.l  a2,-(sp)
0402DE6E: 206e0008                 movea.l 8(a6),a0
0402DE72: 24680008                 movea.l 8(a0),a2
0402DE76: 2f2a0074                 move.l  $74(a2),-(sp)
0402DE7A: 61fffffd9dca             bsr.l   _crfree
0402DE80: 257cefefefef0074         move.l  #$EFEFEFEF,$74(a2)
0402DE88: 246efffc                 movea.l -4(a6),a2
0402DE8C: 4e5e                     unlk    a6
0402DE8E: 4e75                     rts
