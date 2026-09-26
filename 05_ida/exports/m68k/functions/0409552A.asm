0409552A: 4856                     pea     (a6)
0409552C: 2c4f                     movea.l sp,a6
0409552E: 2f2e0008                 move.l  8(a6),-(sp)
04095532: 4879040ac80b             pea     (aDbgPanicS).l; "dbg_panic: %s\n"
04095538: 61ffffffe910             bsr.l   _nmi_prf
0409553E: 504f                     addq.w  #8,sp
04095540: 6002                     bra.s   loc_4095544
04095542: 6002                     bra.s   loc_4095546
04095544: 60fa                     bra.s   loc_4095540
04095546: 4e5e                     unlk    a6
04095548: 4e75                     rts
