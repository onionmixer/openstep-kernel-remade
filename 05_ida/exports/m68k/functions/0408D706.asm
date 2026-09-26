0408D706: 4856                     pea     (a6)
0408D708: 2c4f                     movea.l sp,a6
0408D70A: 202e0008                 move.l  8(a6),d0
0408D70E: 222e0010                 move.l  $10(a6),d1
0408D712: 41f9040b243a             lea     (_zs_com).l,a0
0408D718: 41f00e00                 lea     (a0,d0.l*8),a0
0408D71C: 20280004                 move.l  4(a0),d0
0408D720: 0c80040b242e             cmpi.l  #$40B242E,d0
0408D726: 6708                     beq.s   loc_408D730
0408D728: b280                     cmp.l   d0,d1
0408D72A: 6704                     beq.s   loc_408D730
0408D72C: 7010                     moveq   #$10,d0
0408D72E: 600a                     bra.s   loc_408D73A
0408D730: 20ae000c                 move.l  $C(a6),(a0)
0408D734: 21410004                 move.l  d1,4(a0)
0408D738: 4280                     clr.l   d0
0408D73A: 4e5e                     unlk    a6
0408D73C: 4e75                     rts
