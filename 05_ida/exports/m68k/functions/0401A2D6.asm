0401A2D6: 4856                     pea     (a6)
0401A2D8: 2c4f                     movea.l sp,a6
0401A2DA: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A2E0: 20680024                 movea.l $24(a0),a0
0401A2E4: 42a7                     clr.l   -(sp)
0401A2E6: 42a7                     clr.l   -(sp)
0401A2E8: 2f10                     move.l  (a0),-(sp)
0401A2EA: 61ff00001488             bsr.l   _vn_remove
0401A2F0: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A2F6: 11400064                 move.b  d0,$64(a0)
0401A2FA: 4e5e                     unlk    a6
0401A2FC: 4e75                     rts
