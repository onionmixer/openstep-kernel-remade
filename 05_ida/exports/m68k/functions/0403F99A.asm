0403F99A: 4856                     pea     (a6)
0403F99C: 2c4f                     movea.l sp,a6
0403F99E: 206e0008                 movea.l 8(a6),a0
0403F9A2: 20bc80000012             move.l  #$80000012,(a0)
0403F9A8: 7220                     moveq   #$20,d1 ; ' '
0403F9AA: 21410004                 move.l  d1,4(a0)
0403F9AE: 7201                     moveq   #1,d1
0403F9B0: 21410010                 move.l  d1,$10(a0)
0403F9B4: 42a8000c                 clr.l   $C(a0)
0403F9B8: 42a80008                 clr.l   8(a0)
0403F9BC: 7245                     moveq   #$45,d1 ; 'E'
0403F9BE: 21410014                 move.l  d1,$14(a0)
0403F9C2: 117c00100018             move.b  #$10,$18(a0)
0403F9C8: 117c00200019             move.b  #$20,$19(a0) ; ' '
0403F9CE: 3028001a                 move.w  $1A(a0),d0
0403F9D2: 0240000f                 andi.w  #$F,d0
0403F9D6: 00400010                 ori.w   #$10,d0
0403F9DA: 3140001a                 move.w  d0,$1A(a0)
0403F9DE: 1028001b                 move.b  $1B(a0),d0
0403F9E2: 00000008                 ori.b   #8,d0
0403F9E6: 020000f8                 andi.b  #$F8,d0
0403F9EA: 1140001b                 move.b  d0,$1B(a0)
0403F9EE: 42a8001c                 clr.l   $1C(a0)
0403F9F2: 4e5e                     unlk    a6
0403F9F4: 4e75                     rts
