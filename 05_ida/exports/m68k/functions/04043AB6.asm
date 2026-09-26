04043AB6: 4e56fffc                 link    a6,#-4
04043ABA: 2f2e0010                 move.l  arg_8(a6),-(sp)
04043ABE: 486efffc                 pea     var_4(a6)
04043AC2: 2f2e0008                 move.l  arg_0(a6),-(sp)
04043AC6: 2f2e000c                 move.l  arg_4(a6),-(sp)
04043ACA: 2f39040c22c4             move.l  (_kalloc_map).l,-(sp)
04043AD0: 61ff00019afc             bsr.l   _kmem_realloc
04043AD6: 4a80                     tst.l   d0
04043AD8: 6704                     beq.s   loc_4043ADE
04043ADA: 42aefffc                 clr.l   var_4(a6)
04043ADE: 202efffc                 move.l  var_4(a6),d0
04043AE2: 4e5e                     unlk    a6
04043AE4: 4e75                     rts
