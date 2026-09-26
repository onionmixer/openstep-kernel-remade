0401AEC4: 4856                     pea     (a6)
0401AEC6: 2c4f                     movea.l sp,a6
0401AEC8: 2f0a                     move.l  a2,-(sp)
0401AECA: 2279040b57d4             movea.l (dword_40B57D4).l,a1
0401AED0: 24690024                 movea.l $24(a1),a2
0401AED4: 2079040b57d0             movea.l (_active_u).l,a0
0401AEDA: 30680164                 movea.w $164(a0),a0
0401AEDE: 2348005c                 move.l  a0,$5C(a1)
0401AEE2: 2079040b57d0             movea.l (_active_u).l,a0
0401AEE8: 302a0002                 move.w  2(a2),d0
0401AEEC: 02400fff                 andi.w  #$FFF,d0
0401AEF0: 31400164                 move.w  d0,$164(a0)
0401AEF4: 246efffc                 movea.l -4(a6),a2
0401AEF8: 4e5e                     unlk    a6
0401AEFA: 4e75                     rts
