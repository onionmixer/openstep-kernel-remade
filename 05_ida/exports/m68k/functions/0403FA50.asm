0403FA50: 4856                     pea     (a6)
0403FA52: 2c4f                     movea.l sp,a6
0403FA54: 206e0008                 movea.l 8(a6),a0
0403FA58: 7012                     moveq   #$12,d0
0403FA5A: 2080                     move.l  d0,(a0)
0403FA5C: 7018                     moveq   #$18,d0
0403FA5E: 21400004                 move.l  d0,4(a0)
0403FA62: 7001                     moveq   #1,d0
0403FA64: 21400010                 move.l  d0,$10(a0)
0403FA68: 42a8000c                 clr.l   $C(a0)
0403FA6C: 42a80008                 clr.l   8(a0)
0403FA70: 7047                     moveq   #$47,d0 ; 'G'
0403FA72: 21400014                 move.l  d0,$14(a0)
0403FA76: 4e5e                     unlk    a6
0403FA78: 4e75                     rts
