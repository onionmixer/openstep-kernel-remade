04006C92: 4856                     pea     (a6)
04006C94: 2c4f                     movea.l sp,a6
04006C96: 4ab9040b61a4             tst.l   (_freeproc).l
04006C9C: 672c                     beq.s   loc_4006CCA
04006C9E: 53b9040b317c             subq.l  #1,(dword_40B317C).l
04006CA4: 2079040b61a4             movea.l (_freeproc).l,a0
04006CAA: 23e80008040b61a4         move.l  8(a0),(_freeproc).l
04006CB2: 2f08                     move.l  a0,-(sp)
04006CB4: 2f39040b653c             move.l  (_proc_zone).l,-(sp)
04006CBA: 61ff0004ef40             bsr.l   _zfree
04006CC0: 504f                     addq.w  #8,sp
04006CC2: 4ab9040b61a4             tst.l   (_freeproc).l
04006CC8: 66d4                     bne.s   loc_4006C9E
04006CCA: 4e5e                     unlk    a6
04006CCC: 4e75                     rts
