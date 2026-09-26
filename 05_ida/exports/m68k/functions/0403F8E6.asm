0403F8E6: 4856                     pea     (a6)
0403F8E8: 2c4f                     movea.l sp,a6
0403F8EA: 206e0008                 movea.l 8(a6),a0
0403F8EE: 7212                     moveq   #$12,d1
0403F8F0: 2081                     move.l  d1,(a0)
0403F8F2: 7220                     moveq   #$20,d1 ; ' '
0403F8F4: 21410004                 move.l  d1,4(a0)
0403F8F8: 7201                     moveq   #1,d1
0403F8FA: 21410010                 move.l  d1,$10(a0)
0403F8FE: 42a8000c                 clr.l   $C(a0)
0403F902: 42a80008                 clr.l   8(a0)
0403F906: 7241                     moveq   #$41,d1 ; 'A'
0403F908: 21410014                 move.l  d1,$14(a0)
0403F90C: 117c000f0018             move.b  #$F,$18(a0)
0403F912: 117c00200019             move.b  #$20,$19(a0) ; ' '
0403F918: 3028001a                 move.w  $1A(a0),d0
0403F91C: 0240000f                 andi.w  #$F,d0
0403F920: 00400010                 ori.w   #$10,d0
0403F924: 3140001a                 move.w  d0,$1A(a0)
0403F928: 1028001b                 move.b  $1B(a0),d0
0403F92C: 00000008                 ori.b   #8,d0
0403F930: 020000f8                 andi.b  #$F8,d0
0403F934: 1140001b                 move.b  d0,$1B(a0)
0403F938: 42a8001c                 clr.l   $1C(a0)
0403F93C: 4e5e                     unlk    a6
0403F93E: 4e75                     rts
