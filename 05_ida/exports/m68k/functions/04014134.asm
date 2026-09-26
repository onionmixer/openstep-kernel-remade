04014134: 4856                     pea     (a6)
04014136: 2c4f                     movea.l sp,a6
04014138: 48e70038                 movem.l a2-a4,-(sp)
0401413C: 286e0008                 movea.l 8(a6),a4
04014140: 2f2e000c                 move.l  $C(a6),-(sp)
04014144: 45ec0038                 lea     $38(a4),a2
04014148: 2f0a                     move.l  a2,-(sp)
0401414A: 47f904014180             lea     (_sbreserve).l,a3
04014150: 4e93                     jsr     (a3)
04014152: 504f                     addq.w  #8,sp
04014154: 4a80                     tst.l   d0
04014156: 671c                     beq.s   loc_4014174
04014158: 2f2e0010                 move.l  $10(a6),-(sp)
0401415C: 486c0022                 pea     $22(a4)
04014160: 4e93                     jsr     (a3)
04014162: 504f                     addq.w  #8,sp
04014164: 4a80                     tst.l   d0
04014166: 6704                     beq.s   loc_401416C
04014168: 4280                     clr.l   d0
0401416A: 600a                     bra.s   loc_4014176
0401416C: 2f0a                     move.l  a2,-(sp)
0401416E: 61ff00000044             bsr.l   _sbrelease
04014174: 7037                     moveq   #$37,d0 ; '7'
04014176: 4cee1c00fff4             movem.l -$C(a6),a2-a4
0401417C: 4e5e                     unlk    a6
0401417E: 4e75                     rts
