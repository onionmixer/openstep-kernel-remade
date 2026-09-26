040495F6: 4856                     pea     (a6)
040495F8: 2c4f                     movea.l sp,a6
040495FA: 206e0008                 movea.l 8(a6),a0
040495FE: 2028005c                 move.l  $5C(a0),d0
04049602: 670e                     beq.s   loc_4049612
04049604: 48780002                 pea     (2).w
04049608: 2f08                     move.l  a0,-(sp)
0404960A: 2f00                     move.l  d0,-(sp)
0404960C: 61fffffff1fe             bsr.l   _ipc_kobject_set
04049612: 4e5e                     unlk    a6
04049614: 4e75                     rts
