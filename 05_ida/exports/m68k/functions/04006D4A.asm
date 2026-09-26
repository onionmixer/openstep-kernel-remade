04006D4A: 4856                     pea     (a6)
04006D4C: 2c4f                     movea.l sp,a6
04006D4E: 222e0008                 move.l  8(a6),d1
04006D52: 703f                     moveq   #$3F,d0 ; '?'
04006D54: c081                     and.l   d1,d0
04006D56: 41f9040b5e04             lea     (_pgrphash).l,a0
04006D5C: 20700c00                 movea.l (a0,d0.l*4),a0
04006D60: 4a88                     tst.l   a0
04006D62: 6710                     beq.s   loc_4006D74
04006D64: b2a8000c                 cmp.l   $C(a0),d1
04006D68: 6604                     bne.s   loc_4006D6E
04006D6A: 2008                     move.l  a0,d0
04006D6C: 6008                     bra.s   loc_4006D76
04006D6E: 2050                     movea.l (a0),a0
04006D70: 4a88                     tst.l   a0
04006D72: 66f0                     bne.s   loc_4006D64
04006D74: 4280                     clr.l   d0
04006D76: 4e5e                     unlk    a6
04006D78: 4e75                     rts
