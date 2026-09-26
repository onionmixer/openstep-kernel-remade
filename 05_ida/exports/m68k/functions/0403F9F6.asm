0403F9F6: 4856                     pea     (a6)
0403F9F8: 2c4f                     movea.l sp,a6
0403F9FA: 206e0008                 movea.l 8(a6),a0
0403F9FE: 7212                     moveq   #$12,d1
0403FA00: 2081                     move.l  d1,(a0)
0403FA02: 7220                     moveq   #$20,d1 ; ' '
0403FA04: 21410004                 move.l  d1,4(a0)
0403FA08: 7201                     moveq   #1,d1
0403FA0A: 21410010                 move.l  d1,$10(a0)
0403FA0E: 42a8000c                 clr.l   $C(a0)
0403FA12: 42a80008                 clr.l   8(a0)
0403FA16: 7246                     moveq   #$46,d1 ; 'F'
0403FA18: 21410014                 move.l  d1,$14(a0)
0403FA1C: 117c00020018             move.b  #2,$18(a0)
0403FA22: 117c00200019             move.b  #$20,$19(a0) ; ' '
0403FA28: 3028001a                 move.w  $1A(a0),d0
0403FA2C: 0240000f                 andi.w  #$F,d0
0403FA30: 00400010                 ori.w   #$10,d0
0403FA34: 3140001a                 move.w  d0,$1A(a0)
0403FA38: 1028001b                 move.b  $1B(a0),d0
0403FA3C: 00000008                 ori.b   #8,d0
0403FA40: 020000f8                 andi.b  #$F8,d0
0403FA44: 1140001b                 move.b  d0,$1B(a0)
0403FA48: 42a8001c                 clr.l   $1C(a0)
0403FA4C: 4e5e                     unlk    a6
0403FA4E: 4e75                     rts
