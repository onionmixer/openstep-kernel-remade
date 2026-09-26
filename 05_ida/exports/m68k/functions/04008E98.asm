04008E98: 4856                     pea     (a6)
04008E9A: 2c4f                     movea.l sp,a6
04008E9C: 2279040b57d4             movea.l (dword_40B57D4).l,a1
04008EA2: 20690024                 movea.l $24(a1),a0
04008EA6: 20280004                 move.l  4(a0),d0
04008EAA: 7220                     moveq   #$20,d1 ; ' '
04008EAC: b280                     cmp.l   d0,d1
04008EAE: 6408                     bcc.s   loc_4008EB8
04008EB0: 137c00160064             move.b  #$16,$64(a1)
04008EB6: 6016                     bra.s   loc_4008ECE
04008EB8: 42a7                     clr.l   -(sp)
04008EBA: 2f10                     move.l  (a0),-(sp)
04008EBC: 2f00                     move.l  d0,-(sp)
04008EBE: 61ff00000012             bsr.l   _killpg1
04008EC4: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04008ECA: 11400064                 move.b  d0,$64(a0)
04008ECE: 4e5e                     unlk    a6
04008ED0: 4e75                     rts
