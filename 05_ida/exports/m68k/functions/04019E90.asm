04019E90: 4856                     pea     (a6)
04019E92: 2c4f                     movea.l sp,a6
04019E94: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04019E9A: 20680024                 movea.l $24(a0),a0
04019E9E: 2f280004                 move.l  4(a0),-(sp)
04019EA2: 48780602                 pea     ($602).w
04019EA6: 2f10                     move.l  (a0),-(sp)
04019EA8: 61ff00000012             bsr.l   _copen
04019EAE: 2079040b57d4             movea.l (dword_40B57D4).l,a0
04019EB4: 11400064                 move.b  d0,$64(a0)
04019EB8: 4e5e                     unlk    a6
04019EBA: 4e75                     rts
