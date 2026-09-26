0401D12A: 4856                     pea     (a6)
0401D12C: 2c4f                     movea.l sp,a6
0401D12E: 2f02                     move.l  d2,-(sp)
0401D130: 2439040b5648             move.l  (_active_threads).l,d2
0401D136: 2f02                     move.l  d2,-(sp)
0401D138: 61ff00035666             bsr.l   _stack_privilege
0401D13E: 2f39040b6ddc             move.l  (_master_processor).l,-(sp)
0401D144: 2f02                     move.l  d2,-(sp)
0401D146: 61ff0003397c             bsr.l   _thread_bind
0401D14C: 48790401d0c0             pea     (_netisr_thread_continue).l
0401D152: 61ff00033ce4             bsr.l   _thread_block_with_continuation
0401D158: 242efffc                 move.l  -4(a6),d2
0401D15C: 4e5e                     unlk    a6
0401D15E: 4e75                     rts
