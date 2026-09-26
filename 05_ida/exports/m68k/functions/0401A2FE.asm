0401A2FE: 4856                     pea     (a6)
0401A300: 2c4f                     movea.l sp,a6
0401A302: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A308: 20680024                 movea.l $24(a0),a0
0401A30C: 48780001                 pea     (1).w
0401A310: 42a7                     clr.l   -(sp)
0401A312: 2f10                     move.l  (a0),-(sp)
0401A314: 61ff0000145e             bsr.l   _vn_remove
0401A31A: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0401A320: 11400064                 move.b  d0,$64(a0)
0401A324: 4e5e                     unlk    a6
0401A326: 4e75                     rts
