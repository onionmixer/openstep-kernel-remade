0402A990: 4856                     pea     (a6)
0402A992: 2c4f                     movea.l sp,a6
0402A994: 2f0b                     move.l  a3,-(sp)
0402A996: 2f0a                     move.l  a2,-(sp)
0402A998: 266e0008                 movea.l 8(a6),a3
0402A99C: 2f2e000c                 move.l  $C(a6),-(sp)
0402A9A0: 4280                     clr.l   d0
0402A9A2: 102b0004                 move.b  4(a3),d0
0402A9A6: 2f00                     move.l  d0,-(sp)
0402A9A8: 45f90402a934             lea     (sub_402A934).l,a2
0402A9AE: 4e92                     jsr     (a2)
0402A9B0: 2040                     movea.l d0,a0
0402A9B2: 10fc002e                 move.b  #$2E,(a0)+ ; '.'
0402A9B6: 2f08                     move.l  a0,-(sp)
0402A9B8: 4280                     clr.l   d0
0402A9BA: 102b0005                 move.b  5(a3),d0
0402A9BE: 2f00                     move.l  d0,-(sp)
0402A9C0: 4e92                     jsr     (a2)
0402A9C2: 2040                     movea.l d0,a0
0402A9C4: 10fc002e                 move.b  #$2E,(a0)+ ; '.'
0402A9C8: 2f08                     move.l  a0,-(sp)
0402A9CA: 4280                     clr.l   d0
0402A9CC: 102b0006                 move.b  6(a3),d0
0402A9D0: 2f00                     move.l  d0,-(sp)
0402A9D2: 4e92                     jsr     (a2)
0402A9D4: 2040                     movea.l d0,a0
0402A9D6: 10fc002e                 move.b  #$2E,(a0)+ ; '.'
0402A9DA: 2f08                     move.l  a0,-(sp)
0402A9DC: 4280                     clr.l   d0
0402A9DE: 102b0007                 move.b  7(a3),d0
0402A9E2: 2f00                     move.l  d0,-(sp)
0402A9E4: 4e92                     jsr     (a2)
0402A9E6: 2040                     movea.l d0,a0
0402A9E8: 4210                     clr.b   (a0)
0402A9EA: 246efff8                 movea.l -8(a6),a2
0402A9EE: 266efffc                 movea.l -4(a6),a3
0402A9F2: 4e5e                     unlk    a6
0402A9F4: 4e75                     rts
