0401A18C: 4856                     pea     (a6)
0401A18E: 2c4f                     movea.l sp,a6
0401A190: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A196: 20680024                 movea.l $24(a0),a0
0401A19A: 42a7                     clr.l   -(sp)
0401A19C: 2f280004                 move.l  4(a0),-(sp)
0401A1A0: 2f10                     move.l  (a0),-(sp)
0401A1A2: 61ff0000149a             bsr.l   _vn_rename
0401A1A8: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A1AE: 11400064                 move.b  d0,$64(a0)
0401A1B2: 4e5e                     unlk    a6
0401A1B4: 4e75                     rts
