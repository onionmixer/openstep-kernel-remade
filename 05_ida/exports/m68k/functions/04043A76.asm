04043A76: 4e56fffc                 link    a6,#-4
04043A7A: 202e0008                 move.l  arg_0(a6),d0
04043A7E: b0b9040b06d0             cmp.l   (_page_size).l,d0
04043A84: 640e                     bcc.s   loc_4043A94
04043A86: 2f00                     move.l  d0,-(sp)
04043A88: 61ff00006776             bsr.l   _kalloc
04043A8E: 2d40fffc                 move.l  d0,var_4(a6)
04043A92: 601a                     bra.s   loc_4043AAE
04043A94: 2f00                     move.l  d0,-(sp)
04043A96: 486efffc                 pea     var_4(a6)
04043A9A: 2f39040c22c4             move.l  (_kalloc_map).l,-(sp)
04043AA0: 61ff00019af0             bsr.l   _kmem_alloc
04043AA6: 4a80                     tst.l   d0
04043AA8: 6704                     beq.s   loc_4043AAE
04043AAA: 42aefffc                 clr.l   var_4(a6)
04043AAE: 202efffc                 move.l  var_4(a6),d0
04043AB2: 4e5e                     unlk    a6
04043AB4: 4e75                     rts
