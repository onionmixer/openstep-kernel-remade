0401A162: 4856                     pea     (a6)
0401A164: 2c4f                     movea.l sp,a6
0401A166: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A16C: 20680024                 movea.l $24(a0),a0
0401A170: 42a7                     clr.l   -(sp)
0401A172: 2f280004                 move.l  4(a0),-(sp)
0401A176: 2f10                     move.l  (a0),-(sp)
0401A178: 61ff000013e2             bsr.l   _vn_link
0401A17E: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A184: 11400064                 move.b  d0,$64(a0)
0401A188: 4e5e                     unlk    a6
0401A18A: 4e75                     rts
