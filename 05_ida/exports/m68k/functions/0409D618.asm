0409D618: 102eff20                 move.b  -$E0(a6),d0
0409D61C: 02000060                 andi.b  #$60,d0 ; '`'
0409D620: 0c000040                 cmpi.b  #$40,d0 ; '@'
0409D624: 67ff0000001c             beq.l   loc_409D642
0409D62A: 0c000060                 cmpi.b  #$60,d0 ; '`'
0409D62E: 67ff00000012             beq.l   loc_409D642
0409D634: 0c000020                 cmpi.b  #$20,d0 ; ' '
0409D638: 67ff00000008             beq.l   loc_409D642
0409D63E: 4280                     clr.l   d0
0409D640: 4e75                     rts
0409D642: 70ff                     moveq   #$FFFFFFFF,d0
0409D644: 4e75                     rts
