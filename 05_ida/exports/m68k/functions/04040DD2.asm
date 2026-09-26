04040DD2: 4856                     pea     (a6)
04040DD4: 2c4f                     movea.l sp,a6
04040DD6: 2f0a                     move.l  a2,-(sp)
04040DD8: 2f02                     move.l  d2,-(sp)
04040DDA: 246e0008                 movea.l 8(a6),a2
04040DDE: 242e000c                 move.l  $C(a6),d2
04040DE2: 2f0a                     move.l  a2,-(sp)
04040DE4: 61ffffffff90             bsr.l   _ipc_port_lock_mqueue
04040DEA: 25420030                 move.l  d2,$30(a2)
04040DEE: 242efff8                 move.l  -8(a6),d2
04040DF2: 246efffc                 movea.l -4(a6),a2
04040DF6: 4e5e                     unlk    a6
04040DF8: 4e75                     rts
