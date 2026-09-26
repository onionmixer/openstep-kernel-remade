0405917E: 4856                     pea     (a6)
04059180: 2c4f                     movea.l sp,a6
04059182: 2f0b                     move.l  a3,-(sp)
04059184: 2f0a                     move.l  a2,-(sp)
04059186: 266e0008                 movea.l 8(a6),a3
0405918A: 226e000c                 movea.l $C(a6),a1
0405918E: 4280                     clr.l   d0
04059190: 102b0002                 move.b  2(a3),d0
04059194: 2280                     move.l  d0,(a1)
04059196: 7220                     moveq   #$20,d1 ; ' '
04059198: 23410004                 move.l  d1,4(a1)
0405919C: 236b000c0008             move.l  $C(a3),8(a1)
040591A2: 42a9000c                 clr.l   $C(a1)
040591A6: 42a90010                 clr.l   $10(a1)
040591AA: 7264                     moveq   #$64,d1 ; 'd'
040591AC: d2ab0014                 add.l   $14(a3),d1
040591B0: 23410014                 move.l  d1,$14(a1)
040591B4: 2379040b01040018         move.l  (dword_40B0104).l,$18(a1)
040591BC: 246b0014                 movea.l $14(a3),a2
040591C0: 41eaf5d8                 lea     -$A28(a2),a0
040591C4: 7229                     moveq   #$29,d1 ; ')'
040591C6: b288                     cmp.l   a0,d1
040591C8: 650e                     bcs.s   loc_40591D8
040591CA: 41f9040ad7bc             lea     (unk_40AD7BC).l,a0
040591D0: 2070ac00                 movea.l (a0,a2.l*4),a0
040591D4: 4a88                     tst.l   a0
040591D6: 660c                     bne.s   loc_40591E4
040591D8: 237cfffffed1001c         move.l  #$FFFFFED1,$1C(a1)
040591E0: 4280                     clr.l   d0
040591E2: 6008                     bra.s   loc_40591EC
040591E4: 2f09                     move.l  a1,-(sp)
040591E6: 2f0b                     move.l  a3,-(sp)
040591E8: 4e90                     jsr     (a0)
040591EA: 7001                     moveq   #1,d0
040591EC: 246efff8                 movea.l -8(a6),a2
040591F0: 266efffc                 movea.l -4(a6),a3
040591F4: 4e5e                     unlk    a6
040591F6: 4e75                     rts
