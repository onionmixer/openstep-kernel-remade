04089BF0: 4856                     pea     (a6)
04089BF2: 2c4f                     movea.l sp,a6
04089BF4: 2079040b2282             movea.l (dword_40B2282).l,a0
04089BFA: 72ff                     moveq   #$FFFFFFFF,d1
04089BFC: b288                     cmp.l   a0,d1
04089BFE: 6724                     beq.s   loc_4089C24
04089C00: 4a39040b228a             tst.b   (byte_40B228A).l
04089C06: 671c                     beq.s   loc_4089C24
04089C08: 43f08a00                 lea     (a0,a0.l*2),a1
04089C0C: 2009                     move.l  a1,d0
04089C0E: e580                     asl.l   #2,d0
04089C10: 9088                     sub.l   a0,d0
04089C12: 41f9040b228c             lea     ($40B228C).l,a0
04089C18: 20700c28                 movea.l off_40B22B4-unk_40B228C(a0,d0.l*4),a0
04089C1C: 4e90                     jsr     (a0)
04089C1E: 4239040b228a             clr.b   (byte_40B228A).l
04089C24: 4e5e                     unlk    a6
04089C26: 4e75                     rts
