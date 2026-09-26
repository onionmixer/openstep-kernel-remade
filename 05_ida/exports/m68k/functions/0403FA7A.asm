0403FA7A: 4856                     pea     (a6)
0403FA7C: 2c4f                     movea.l sp,a6
0403FA7E: 206e0008                 movea.l 8(a6),a0
0403FA82: 7212                     moveq   #$12,d1
0403FA84: 2081                     move.l  d1,(a0)
0403FA86: 7220                     moveq   #$20,d1 ; ' '
0403FA88: 21410004                 move.l  d1,4(a0)
0403FA8C: 7201                     moveq   #1,d1
0403FA8E: 21410010                 move.l  d1,$10(a0)
0403FA92: 42a8000c                 clr.l   $C(a0)
0403FA96: 42a80008                 clr.l   8(a0)
0403FA9A: 7248                     moveq   #$48,d1 ; 'H'
0403FA9C: 21410014                 move.l  d1,$14(a0)
0403FAA0: 117c000f0018             move.b  #$F,$18(a0)
0403FAA6: 117c00200019             move.b  #$20,$19(a0) ; ' '
0403FAAC: 3028001a                 move.w  $1A(a0),d0
0403FAB0: 0240000f                 andi.w  #$F,d0
0403FAB4: 00400010                 ori.w   #$10,d0
0403FAB8: 3140001a                 move.w  d0,$1A(a0)
0403FABC: 1028001b                 move.b  $1B(a0),d0
0403FAC0: 00000008                 ori.b   #8,d0
0403FAC4: 020000f8                 andi.b  #$F8,d0
0403FAC8: 1140001b                 move.b  d0,$1B(a0)
0403FACC: 42a8001c                 clr.l   $1C(a0)
0403FAD0: 4e5e                     unlk    a6
0403FAD2: 4e75                     rts
