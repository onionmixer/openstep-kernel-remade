04061F6A: 4856                     pea     (a6)
04061F6C: 2c4f                     movea.l sp,a6
04061F6E: 206e0008                 movea.l 8(a6),a0
04061F72: 226e000c                 movea.l $C(a6),a1
04061F76: 4a88                     tst.l   a0
04061F78: 6708                     beq.s   loc_4061F82
04061F7A: 20680034                 movea.l $34(a0),a0
04061F7E: 4a88                     tst.l   a0
04061F80: 6608                     bne.s   loc_4061F8A
04061F82: 72ff                     moveq   #$FFFFFFFF,d1
04061F84: 2281                     move.l  d1,(a1)
04061F86: 7005                     moveq   #5,d0
04061F88: 6008                     bra.s   loc_4061F92
04061F8A: 30680030                 movea.w $30(a0),a0
04061F8E: 2288                     move.l  a0,(a1)
04061F90: 4280                     clr.l   d0
04061F92: 4e5e                     unlk    a6
04061F94: 4e75                     rts
