0404840A: 4856                     pea     (a6)
0404840C: 2c4f                     movea.l sp,a6
0404840E: 2f0b                     move.l  a3,-(sp)
04048410: 2f0a                     move.l  a2,-(sp)
04048412: 266e0008                 movea.l 8(a6),a3
04048416: 2f39040c21e4             move.l  (_ipc_space_kernel).l,-(sp)
0404841C: 2f2b014c                 move.l  $14C(a3),-(sp)
04048420: 45f9040413c8             lea     (_ipc_port_dealloc_special).l,a2
04048426: 4e92                     jsr     (a2)
04048428: 2f39040c21e4             move.l  (_ipc_space_kernel).l,-(sp)
0404842E: 2f2b0150                 move.l  $150(a3),-(sp)
04048432: 4e92                     jsr     (a2)
04048434: 246efff8                 movea.l -8(a6),a2
04048438: 266efffc                 movea.l -4(a6),a3
0404843C: 4e5e                     unlk    a6
0404843E: 4e75                     rts
