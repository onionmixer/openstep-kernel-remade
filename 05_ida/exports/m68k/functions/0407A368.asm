0407A368: 4e56fffc                 link    a6,#-4
0407A36C: 2f02                     move.l  d2,-(sp)
0407A36E: 2039040b06d0             move.l  (_page_size).l,d0
0407A374: d080                     add.l   d0,d0
0407A376: 2439040b06d4             move.l  (_vm_page_free_target).l,d2
0407A37C: 4c002800                 muls.l  d0,d2
0407A380: 2f02                     move.l  d2,-(sp)
0407A382: 486efffc                 pea     var_4(a6)
0407A386: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A38C: 61fffffe333e             bsr.l   _kmem_alloc_wired
0407A392: 2f02                     move.l  d2,-(sp)
0407A394: 2f2efffc                 move.l  var_4(a6),-(sp)
0407A398: 2f39040b5dbc             move.l  (_kernel_map).l,-(sp)
0407A39E: 61fffffe33a0             bsr.l   _kmem_free
0407A3A4: 242efff8                 move.l  var_8(a6),d2
0407A3A8: 4e5e                     unlk    a6
0407A3AA: 4e75                     rts
