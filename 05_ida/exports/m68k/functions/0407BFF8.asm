0407BFF8: 4856                     pea     (a6)
0407BFFA: 2c4f                     movea.l sp,a6
0407BFFC: 2f0b                     move.l  a3,-(sp)
0407BFFE: 2f0a                     move.l  a2,-(sp)
0407C000: 266e0008                 movea.l 8(a6),a3
0407C004: 246b0018                 movea.l $18(a3),a2
0407C008: 206a0010                 movea.l $10(a2),a0
0407C00C: 2268001c                 movea.l $1C(a0),a1
0407C010: 228b                     move.l  a3,(a1)
0407C012: 27490004                 move.l  a1,4(a3)
0407C016: 7218                     moveq   #$18,d1
0407C018: d2aa0010                 add.l   $10(a2),d1
0407C01C: 2681                     move.l  d1,(a3)
0407C01E: 206a0010                 movea.l $10(a2),a0
0407C022: 214b001c                 move.l  a3,$1C(a0)
0407C026: 002b00200024             ori.b   #$20,$24(a3) ; ' '
0407C02C: 4a2a005a                 tst.b   $5A(a2)
0407C030: 6704                     beq.s   loc_407C036
0407C032: 4280                     clr.l   d0
0407C034: 6008                     bra.s   loc_407C03E
0407C036: 2f0a                     move.l  a2,-(sp)
0407C038: 61ff00000010             bsr.l   sub_407C04A
0407C03E: 246efff8                 movea.l -8(a6),a2
0407C042: 266efffc                 movea.l -4(a6),a3
0407C046: 4e5e                     unlk    a6
0407C048: 4e75                     rts
