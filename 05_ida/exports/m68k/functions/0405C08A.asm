0405C08A: 4856                     pea     (a6)
0405C08C: 2c4f                     movea.l sp,a6
0405C08E: 2f0b                     move.l  a3,-(sp)
0405C090: 2f0a                     move.l  a2,-(sp)
0405C092: 266e0008                 movea.l 8(a6),a3
0405C096: 226e000c                 movea.l $C(a6),a1
0405C09A: 4280                     clr.l   d0
0405C09C: 102b0002                 move.b  2(a3),d0
0405C0A0: 2280                     move.l  d0,(a1)
0405C0A2: 7220                     moveq   #$20,d1 ; ' '
0405C0A4: 23410004                 move.l  d1,4(a1)
0405C0A8: 236b000c0008             move.l  $C(a3),8(a1)
0405C0AE: 42a9000c                 clr.l   $C(a1)
0405C0B2: 42a90010                 clr.l   $10(a1)
0405C0B6: 7264                     moveq   #$64,d1 ; 'd'
0405C0B8: d2ab0014                 add.l   $14(a3),d1
0405C0BC: 23410014                 move.l  d1,$14(a1)
0405C0C0: 2379040b06b40018         move.l  (dword_40B06B4).l,$18(a1)
0405C0C8: 246b0014                 movea.l $14(a3),a2
0405C0CC: 41eaf448                 lea     -$BB8(a2),a0
0405C0D0: 7215                     moveq   #$15,d1
0405C0D2: b288                     cmp.l   a0,d1
0405C0D4: 650e                     bcs.s   loc_405C0E4
0405C0D6: 41f9040ad77c             lea     (unk_40AD77C).l,a0
0405C0DC: 2070ac00                 movea.l (a0,a2.l*4),a0
0405C0E0: 4a88                     tst.l   a0
0405C0E2: 660c                     bne.s   loc_405C0F0
0405C0E4: 237cfffffed1001c         move.l  #$FFFFFED1,$1C(a1)
0405C0EC: 4280                     clr.l   d0
0405C0EE: 6008                     bra.s   loc_405C0F8
0405C0F0: 2f09                     move.l  a1,-(sp)
0405C0F2: 2f0b                     move.l  a3,-(sp)
0405C0F4: 4e90                     jsr     (a0)
0405C0F6: 7001                     moveq   #1,d0
0405C0F8: 246efff8                 movea.l -8(a6),a2
0405C0FC: 266efffc                 movea.l -4(a6),a3
0405C100: 4e5e                     unlk    a6
0405C102: 4e75                     rts
