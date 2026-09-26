04065F50: 4856                     pea     (a6)
04065F52: 2c4f                     movea.l sp,a6
04065F54: 2f0a                     move.l  a2,-(sp)
04065F56: e9ee0043000b             bfextu  $B(a6){1:3},d0
04065F5C: 7205                     moveq   #5,d1
04065F5E: b280                     cmp.l   d0,d1
04065F60: 6712                     beq.s   loc_4065F74
04065F62: 2f00                     move.l  d0,-(sp)
04065F64: 4879040a9e64             pea     (aIllegalPolling).l; "illegal polling ipl %d\n"
04065F6A: 61fffffa53ec             bsr.l   _printf
04065F70: 70ff                     moveq   #$FFFFFFFF,d0
04065F72: 6034                     bra.s   loc_4065FA8
04065F74: 45f9040b085c             lea     (_poll_intr).l,a2
04065F7A: 4280                     clr.l   d0
04065F7C: 4a92                     tst.l   (a2)
04065F7E: 670a                     beq.s   loc_4065F8A
04065F80: 584a                     addq.w  #4,a2
04065F82: 5280                     addq.l  #1,d0
04065F84: 7207                     moveq   #7,d1
04065F86: b280                     cmp.l   d0,d1
04065F88: 6cf2                     bge.s   loc_4065F7C
04065F8A: 7207                     moveq   #7,d1
04065F8C: b280                     cmp.l   d0,d1
04065F8E: 6c0c                     bge.s   loc_4065F9C
04065F90: 4879040a9e7c             pea     (aTooManyPolledI).l; "too many polled interupt routines"
04065F96: 61fffffa5cce             bsr.l   _panic
04065F9C: 24aafffc                 move.l  -4(a2),(a2)
04065FA0: 256e000cfffc             move.l  $C(a6),-4(a2)
04065FA6: 4280                     clr.l   d0
04065FA8: 246efffc                 movea.l -4(a6),a2
04065FAC: 4e5e                     unlk    a6
04065FAE: 4e75                     rts
