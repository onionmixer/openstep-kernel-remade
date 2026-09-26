04041678: 4856                     pea     (a6)
0404167A: 2c4f                     movea.l sp,a6
0404167C: 2f0a                     move.l  a2,-(sp)
0404167E: 206e0008                 movea.l 8(a6),a0
04041682: 246e000c                 movea.l $C(a6),a2
04041686: 2548002c                 move.l  a0,$2C(a2)
0404168A: 5290                     addq.l  #1,(a0)
0404168C: 2f0a                     move.l  a2,-(sp)
0404168E: d4fc003c                 adda.w  #$3C,a2 ; '<'
04041692: 2f0a                     move.l  a2,-(sp)
04041694: 4868000c                 pea     $C(a0)
04041698: 61ffffffdbfe             bsr.l   _ipc_mqueue_move
0404169E: 2f3c10004006             move.l  #$10004006,-(sp)
040416A4: 2f0a                     move.l  a2,-(sp)
040416A6: 61ffffffdc92             bsr.l   _ipc_mqueue_changed
040416AC: 246efffc                 movea.l -4(a6),a2
040416B0: 4e5e                     unlk    a6
040416B2: 4e75                     rts
