040416B4: 4856                     pea     (a6)
040416B6: 2c4f                     movea.l sp,a6
040416B8: 206e0008                 movea.l 8(a6),a0
040416BC: 226e000c                 movea.l $C(a6),a1
040416C0: 42a9002c                 clr.l   $2C(a1)
040416C4: 5390                     subq.l  #1,(a0)
040416C6: 2f09                     move.l  a1,-(sp)
040416C8: 4868000c                 pea     $C(a0)
040416CC: 4869003c                 pea     $3C(a1)
040416D0: 61ffffffdbc6             bsr.l   _ipc_mqueue_move
040416D6: 4e5e                     unlk    a6
040416D8: 4e75                     rts
