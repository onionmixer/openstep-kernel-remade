04049786: 4856                     pea     (a6)
04049788: 2c4f                     movea.l sp,a6
0404978A: 206e0008                 movea.l 8(a6),a0
0404978E: 202800a4                 move.l  $A4(a0),d0
04049792: 670c                     beq.s   loc_40497A0
04049794: 42a7                     clr.l   -(sp)
04049796: 42a7                     clr.l   -(sp)
04049798: 2f00                     move.l  d0,-(sp)
0404979A: 61fffffff070             bsr.l   _ipc_kobject_set
040497A0: 4e5e                     unlk    a6
040497A2: 4e75                     rts
