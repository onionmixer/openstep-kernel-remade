040612D8: 4856                     pea     (a6)
040612DA: 2c4f                     movea.l sp,a6
040612DC: 48e73800                 movem.l d2-d4,-(sp)
040612E0: 242e0008                 move.l  8(a6),d2
040612E4: 282e000c                 move.l  $C(a6),d4
040612E8: 262e0010                 move.l  $10(a6),d3
040612EC: 2f02                     move.l  d2,-(sp)
040612EE: 61fffffffeea             bsr.l   _vm_page_remove
040612F4: 2f03                     move.l  d3,-(sp)
040612F6: 2f04                     move.l  d4,-(sp)
040612F8: 2f02                     move.l  d2,-(sp)
040612FA: 61fffffffe50             bsr.l   _vm_page_insert
04061300: 4cee001cfff4             movem.l -$C(a6),d2-d4
04061306: 4e5e                     unlk    a6
04061308: 4e75                     rts
