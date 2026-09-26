0405B72E: 4856                     pea     (a6)
0405B730: 2c4f                     movea.l sp,a6
0405B732: 2f0b                     move.l  a3,-(sp)
0405B734: 2f0a                     move.l  a2,-(sp)
0405B736: 266e0008                 movea.l 8(a6),a3
0405B73A: 226e000c                 movea.l $C(a6),a1
0405B73E: 4280                     clr.l   d0
0405B740: 102b0002                 move.b  2(a3),d0
0405B744: 2280                     move.l  d0,(a1)
0405B746: 7220                     moveq   #$20,d1 ; ' '
0405B748: 23410004                 move.l  d1,4(a1)
0405B74C: 236b000c0008             move.l  $C(a3),8(a1)
0405B752: 42a9000c                 clr.l   $C(a1)
0405B756: 42a90010                 clr.l   $10(a1)
0405B75A: 7264                     moveq   #$64,d1 ; 'd'
0405B75C: d2ab0014                 add.l   $14(a3),d1
0405B760: 23410014                 move.l  d1,$14(a1)
0405B764: 2379040b05900018         move.l  (dword_40B0590).l,$18(a1)
0405B76C: 246b0014                 movea.l $14(a3),a2
0405B770: 41eaf830                 lea     -$7D0(a2),a0
0405B774: 7267                     moveq   #$67,d1 ; 'g'
0405B776: b288                     cmp.l   a0,d1
0405B778: 650e                     bcs.s   loc_405B788
0405B77A: 41f9040ae4b0             lea     (unk_40AE4B0).l,a0
0405B780: 2070ac00                 movea.l (a0,a2.l*4),a0
0405B784: 4a88                     tst.l   a0
0405B786: 660c                     bne.s   loc_405B794
0405B788: 237cfffffed1001c         move.l  #$FFFFFED1,$1C(a1)
0405B790: 4280                     clr.l   d0
0405B792: 6008                     bra.s   loc_405B79C
0405B794: 2f09                     move.l  a1,-(sp)
0405B796: 2f0b                     move.l  a3,-(sp)
0405B798: 4e90                     jsr     (a0)
0405B79A: 7001                     moveq   #1,d0
0405B79C: 246efff8                 movea.l -8(a6),a2
0405B7A0: 266efffc                 movea.l -4(a6),a3
0405B7A4: 4e5e                     unlk    a6
0405B7A6: 4e75                     rts
