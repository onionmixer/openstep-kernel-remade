04049616: 4856                     pea     (a6)
04049618: 2c4f                     movea.l sp,a6
0404961A: 206e0008                 movea.l 8(a6),a0
0404961E: 2028005c                 move.l  $5C(a0),d0
04049622: 670c                     beq.s   loc_4049630
04049624: 42a7                     clr.l   -(sp)
04049626: 42a7                     clr.l   -(sp)
04049628: 2f00                     move.l  d0,-(sp)
0404962A: 61fffffff1e0             bsr.l   _ipc_kobject_set
04049630: 4e5e                     unlk    a6
04049632: 4e75                     rts
