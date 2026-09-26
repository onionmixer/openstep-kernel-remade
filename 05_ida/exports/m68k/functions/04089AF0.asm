04089AF0: 4856                     pea     (a6)
04089AF2: 2c4f                     movea.l sp,a6
04089AF4: 2079040b2282             movea.l (dword_40B2282).l,a0
04089AFA: 72ff                     moveq   #$FFFFFFFF,d1
04089AFC: b288                     cmp.l   a0,d1
04089AFE: 671a                     beq.s   loc_4089B1A
04089B00: 43f08a00                 lea     (a0,a0.l*2),a1
04089B04: 2009                     move.l  a1,d0
04089B06: e580                     asl.l   #2,d0
04089B08: 9088                     sub.l   a0,d0
04089B0A: 41f9040b228c             lea     (unk_40B228C).l,a0
04089B10: 2f2e0008                 move.l  8(a6),-(sp)
04089B14: 20700c04                 movea.l 4(a0,d0.l*4),a0
04089B18: 4e90                     jsr     (a0)
04089B1A: 4e5e                     unlk    a6
04089B1C: 4e75                     rts
