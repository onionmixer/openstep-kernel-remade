0404AEA2: 4856                     pea     (a6)
0404AEA4: 2c4f                     movea.l sp,a6
0404AEA6: 206e0008                 movea.l 8(a6),a0
0404AEAA: 2210                     move.l  (a0),d1
0404AEAC: b2b9040b5648             cmp.l   (_active_threads).l,d1
0404AEB2: 6614                     bne.s   loc_404AEC8
0404AEB4: 30280006                 move.w  6(a0),d0
0404AEB8: 5240                     addq.w  #1,d0
0404AEBA: 02400fff                 andi.w  #$FFF,d0
0404AEBE: efe8010c0006             bfins   d0,6(a0){4:12}
0404AEC4: 7001                     moveq   #1,d0
0404AEC6: 6018                     bra.s   loc_404AEE0
0404AEC8: 20280004                 move.l  4(a0),d0
0404AECC: 0240c000                 andi.w  #$C000,d0
0404AED0: 4a80                     tst.l   d0
0404AED2: 660a                     bne.s   loc_404AEDE
0404AED4: 002800400006             ori.b   #$40,6(a0) ; '@'
0404AEDA: 7001                     moveq   #1,d0
0404AEDC: 6002                     bra.s   loc_404AEE0
0404AEDE: 4280                     clr.l   d0
0404AEE0: 4e5e                     unlk    a6
0404AEE2: 4e75                     rts
