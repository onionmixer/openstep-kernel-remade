04028EA8: 4856                     pea     (a6)
04028EAA: 2c4f                     movea.l sp,a6
04028EAC: 226e0008                 movea.l 8(a6),a1
04028EB0: 20690024                 movea.l $24(a1),a0
04028EB4: 08280004000f             btst    #4,$F(a0)
04028EBA: 661c                     bne.s   loc_4028ED8
04028EBC: 2069002e                 movea.l $2E(a1),a0
04028EC0: 082800020080             btst    #2,$80(a0)
04028EC6: 6610                     bne.s   loc_4028ED8
04028EC8: 2079040b57d0             movea.l (_active_u).l,a0
04028ECE: 2068001a                 movea.l $1A(a0),a0
04028ED2: 30280004                 move.w  4(a0),d0
04028ED6: 6008                     bra.s   loc_4028EE0
04028ED8: 2069002e                 movea.l $2E(a1),a0
04028EDC: 30280084                 move.w  $84(a0),d0
04028EE0: 48c0                     ext.l   d0
04028EE2: 4e5e                     unlk    a6
04028EE4: 4e75                     rts
