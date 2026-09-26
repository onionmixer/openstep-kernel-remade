04043AE6: 4856                     pea     (a6)
04043AE8: 2c4f                     movea.l sp,a6
04043AEA: 202e0008                 move.l  8(a6),d0
04043AEE: 222e000c                 move.l  $C(a6),d1
04043AF2: b0b9040b06d0             cmp.l   (_page_size).l,d0
04043AF8: 640c                     bcc.s   loc_4043B06
04043AFA: 2f00                     move.l  d0,-(sp)
04043AFC: 2f01                     move.l  d1,-(sp)
04043AFE: 61ff000067c4             bsr.l   _kfree
04043B04: 6010                     bra.s   loc_4043B16
04043B06: 2f00                     move.l  d0,-(sp)
04043B08: 2f01                     move.l  d1,-(sp)
04043B0A: 2f39040c22c4             move.l  (_kalloc_map).l,-(sp)
04043B10: 61ff00019c2e             bsr.l   _kmem_free
04043B16: 4e5e                     unlk    a6
04043B18: 4e75                     rts
