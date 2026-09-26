04089AAC: 4856                     pea     (a6)
04089AAE: 2c4f                     movea.l sp,a6
04089AB0: 48e73030                 movem.l d2-d3/a2-a3,-(sp)
04089AB4: 7402                     moveq   #2,d2
04089AB6: 47f9040b228c             lea     (unk_40B228C).l,a3
04089ABC: 3602                     move.w  d2,d3
04089ABE: c7fc002c                 muls.w  #$2C,d3 ; ','
04089AC2: 20733800                 movea.l (a3,d3.l),a0
04089AC6: 4e90                     jsr     (a0)
04089AC8: 7201                     moveq   #1,d1
04089ACA: b280                     cmp.l   d0,d1
04089ACC: 6612                     bne.s   loc_4089AE0
04089ACE: 3442                     movea.w d2,a2
04089AD0: 23ca040b2282             move.l  a2,(dword_40B2282).l
04089AD6: 20733808                 movea.l 8(a3,d3.l),a0
04089ADA: 4e90                     jsr     (a0)
04089ADC: 200a                     move.l  a2,d0
04089ADE: 6006                     bra.s   loc_4089AE6
04089AE0: 51caffda                 dbf     d2,loc_4089ABC
04089AE4: 70ff                     moveq   #$FFFFFFFF,d0
04089AE6: 4cee0c0cfff0             movem.l -$10(a6),d2-d3/a2-a3
04089AEC: 4e5e                     unlk    a6
04089AEE: 4e75                     rts
