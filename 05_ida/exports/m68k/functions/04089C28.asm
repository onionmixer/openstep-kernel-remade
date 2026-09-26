04089C28: 4856                     pea     (a6)
04089C2A: 2c4f                     movea.l sp,a6
04089C2C: 2079040b2282             movea.l (dword_40B2282).l,a0
04089C32: 72ff                     moveq   #$FFFFFFFF,d1
04089C34: b288                     cmp.l   a0,d1
04089C36: 671a                     beq.s   loc_4089C52
04089C38: 43f08a00                 lea     (a0,a0.l*2),a1
04089C3C: 2009                     move.l  a1,d0
04089C3E: e580                     asl.l   #2,d0
04089C40: 9088                     sub.l   a0,d0
04089C42: 41f9040b228c             lea     (unk_40B228C).l,a0
04089C48: 2f2e0008                 move.l  8(a6),-(sp)
04089C4C: 20700c1c                 movea.l $1C(a0,d0.l*4),a0
04089C50: 4e90                     jsr     (a0)
04089C52: 4e5e                     unlk    a6
04089C54: 4e75                     rts
