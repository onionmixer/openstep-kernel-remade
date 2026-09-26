04049E8E: 4856                     pea     (a6)
04049E90: 2c4f                     movea.l sp,a6
04049E92: 202e0008                 move.l  8(a6),d0
04049E96: 6708                     beq.s   loc_4049EA0
04049E98: 2f00                     move.l  d0,-(sp)
04049E9A: 61ffffff9016             bsr.l   _ipc_space_release
04049EA0: 4e5e                     unlk    a6
04049EA2: 4e75                     rts
