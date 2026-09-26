04089BB6: 4856                     pea     (a6)
04089BB8: 2c4f                     movea.l sp,a6
04089BBA: 2079040b2282             movea.l (dword_40B2282).l,a0
04089BC0: 72ff                     moveq   #$FFFFFFFF,d1
04089BC2: b288                     cmp.l   a0,d1
04089BC4: 6726                     beq.s   loc_4089BEC
04089BC6: 4a39040b228a             tst.b   (byte_40B228A).l
04089BCC: 661e                     bne.s   loc_4089BEC
04089BCE: 43f08a00                 lea     (a0,a0.l*2),a1
04089BD2: 2009                     move.l  a1,d0
04089BD4: e580                     asl.l   #2,d0
04089BD6: 9088                     sub.l   a0,d0
04089BD8: 41f9040b228c             lea     ($40B228C).l,a0
04089BDE: 20700c24                 movea.l off_40B22B0-unk_40B228C(a0,d0.l*4),a0
04089BE2: 4e90                     jsr     (a0)
04089BE4: 13fc0001040b228a         move.b  #1,(byte_40B228A).l
04089BEC: 4e5e                     unlk    a6
04089BEE: 4e75                     rts
