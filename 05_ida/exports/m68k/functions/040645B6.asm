040645B6: 4856                     pea     (a6)
040645B8: 2c4f                     movea.l sp,a6
040645BA: 2079040c32d4             movea.l (_slot_id).l,a0
040645C0: 227c02208020             movea.l #$2208020,a1
040645C6: d3c8                     adda.l  a0,a1
040645C8: d1fc02208000             adda.l  #$2208000,a0
040645CE: 2090                     move.l  (a0),(a0)
040645D0: 7208                     moveq   #8,d1
040645D2: 2281                     move.l  d1,(a1)
040645D4: 4aae0008                 tst.l   8(a6)
040645D8: 670c                     beq.s   loc_40645E6
040645DA: 2010                     move.l  (a0),d0
040645DC: 08000003                 btst    #3,d0
040645E0: 67f8                     beq.s   loc_40645DA
040645E2: 7208                     moveq   #8,d1
040645E4: 2081                     move.l  d1,(a0)
040645E6: 4e5e                     unlk    a6
040645E8: 4e75                     rts
