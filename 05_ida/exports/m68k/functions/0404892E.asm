0404892E: 4856                     pea     (a6)
04048930: 2c4f                     movea.l sp,a6
04048932: 206e0008                 movea.l 8(a6),a0
04048936: 4280                     clr.l   d0
04048938: 4aa800a4                 tst.l   $A4(a0)
0404893C: 6708                     beq.s   loc_4048946
0404893E: 202800b8                 move.l  $B8(a0),d0
04048942: 42a800b8                 clr.l   $B8(a0)
04048946: 4a80                     tst.l   d0
04048948: 670e                     beq.s   loc_4048958
0404894A: 2f39040c21e8             move.l  (_ipc_space_reply).l,-(sp)
04048950: 2f00                     move.l  d0,-(sp)
04048952: 61ffffff8a74             bsr.l   _ipc_port_dealloc_special
04048958: 4e5e                     unlk    a6
0404895A: 4e75                     rts
