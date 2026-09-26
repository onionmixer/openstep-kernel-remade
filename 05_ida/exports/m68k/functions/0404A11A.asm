0404A11A: 4856                     pea     (a6)
0404A11C: 2c4f                     movea.l sp,a6
0404A11E: 48e73020                 movem.l d2-d3/a2,-(sp)
0404A122: 23f9040b5dbc040c22c4     move.l  (_kernel_map).l,(_kalloc_map).l
0404A12C: 4283                     clr.l   d3
0404A12E: 45f9040b3612             lea     (unk_40B3612).l,a2
0404A134: 41f9040af794             lea     (_k_zone_elemsize).l,a0
0404A13A: 24303c00                 move.l  (a0,d3.l*4),d2
0404A13E: b4b9040b06d0             cmp.l   (_page_size).l,d2
0404A144: 6448                     bcc.s   loc_404A18E
0404A146: 2f02                     move.l  d2,-(sp)
0404A148: 4879040a88f7             pea     (aKallocD).l; "kalloc.%d"
0404A14E: 2f0a                     move.l  a2,-(sp)
0404A150: 61fffffc12ca             bsr.l   _sprintf
0404A156: 2f0a                     move.l  a2,-(sp)
0404A158: 42a7                     clr.l   -(sp)
0404A15A: 2f39040b06d0             move.l  (_page_size).l,-(sp)
0404A160: 2f3c00100000             move.l  #$100000,-(sp)
0404A166: 2f02                     move.l  d2,-(sp)
0404A168: 61ff0000ae78             bsr.l   _zinit
0404A16E: 41f9040c22e4             lea     (_k_zone).l,a0
0404A174: 21803c00                 move.l  d0,(a0,d3.l*4)
0404A178: 23c2040c2324             move.l  d2,(_k_zone_maxsize).l
0404A17E: defc0020                 adda.w  #$20,sp ; ' '
0404A182: 504a                     addq.w  #8,a2
0404A184: 504a                     addq.w  #8,a2
0404A186: 5283                     addq.l  #1,d3
0404A188: 720f                     moveq   #$F,d1
0404A18A: b283                     cmp.l   d3,d1
0404A18C: 6ca6                     bge.s   loc_404A134
0404A18E: 4cee040cfff4             movem.l -$C(a6),d2-d3/a2
0404A194: 4e5e                     unlk    a6
0404A196: 4e75                     rts
