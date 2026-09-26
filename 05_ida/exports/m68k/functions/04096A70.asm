04096A70: 4856                     pea     (a6)
04096A72: 2c4f                     movea.l sp,a6
04096A74: 206e0008                 movea.l 8(a6),a0
04096A78: 20280024                 move.l  $24(a0),d0
04096A7C: 23c8040b5648             move.l  a0,(_active_threads).l
04096A82: 23e80028040c22dc         move.l  $28(a0),(_active_stacks).l
04096A8A: 20680028                 movea.l $28(a0),a0
04096A8E: d0fc0ff4                 adda.w  #$FF4,a0
04096A92: 23c8040b57cc             move.l  a0,(_stack_pointers).l
04096A98: 42a7                     clr.l   -(sp)
04096A9A: 2f00                     move.l  d0,-(sp)
04096A9C: 42a7                     clr.l   -(sp)
04096A9E: 61fffff6af7a             bsr.l   __switch_context0
04096AA4: 4e5e                     unlk    a6
04096AA6: 4e75                     rts
