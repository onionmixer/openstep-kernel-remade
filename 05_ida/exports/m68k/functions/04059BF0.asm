04059BF0: 4856                     pea     (a6)
04059BF2: 2c4f                     movea.l sp,a6
04059BF4: 2f0b                     move.l  a3,-(sp)
04059BF6: 2f0a                     move.l  a2,-(sp)
04059BF8: 266e0008                 movea.l 8(a6),a3
04059BFC: 226e000c                 movea.l $C(a6),a1
04059C00: 4280                     clr.l   d0
04059C02: 102b0002                 move.b  2(a3),d0
04059C06: 2280                     move.l  d0,(a1)
04059C08: 7220                     moveq   #$20,d1 ; ' '
04059C0A: 23410004                 move.l  d1,4(a1)
04059C0E: 236b000c0008             move.l  $C(a3),8(a1)
04059C14: 42a9000c                 clr.l   $C(a1)
04059C18: 42a90010                 clr.l   $10(a1)
04059C1C: 7264                     moveq   #$64,d1 ; 'd'
04059C1E: d2ab0014                 add.l   $14(a3),d1
04059C22: 23410014                 move.l  d1,$14(a1)
04059C26: 2379040b020c0018         move.l  (dword_40B020C).l,$18(a1)
04059C2E: 246b0014                 movea.l $14(a3),a2
04059C32: 41eaf380                 lea     -$C80(a2),a0
04059C36: 7212                     moveq   #$12,d1
04059C38: b288                     cmp.l   a0,d1
04059C3A: 650e                     bcs.s   loc_4059C4A
04059C3C: 41f9040acfc0             lea     ($40ACFC0).l,a0
04059C42: 2070ac00                 movea.l (a0,a2.l*4),a0
04059C46: 4a88                     tst.l   a0
04059C48: 660c                     bne.s   loc_4059C56
04059C4A: 237cfffffed1001c         move.l  #$FFFFFED1,$1C(a1)
04059C52: 4280                     clr.l   d0
04059C54: 6008                     bra.s   loc_4059C5E
04059C56: 2f09                     move.l  a1,-(sp)
04059C58: 2f0b                     move.l  a3,-(sp)
04059C5A: 4e90                     jsr     (a0)
04059C5C: 7001                     moveq   #1,d0
04059C5E: 246efff8                 movea.l -8(a6),a2
04059C62: 266efffc                 movea.l -4(a6),a3
04059C66: 4e5e                     unlk    a6
04059C68: 4e75                     rts
