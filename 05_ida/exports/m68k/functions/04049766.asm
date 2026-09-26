04049766: 4856                     pea     (a6)
04049768: 2c4f                     movea.l sp,a6
0404976A: 206e0008                 movea.l 8(a6),a0
0404976E: 202800a4                 move.l  $A4(a0),d0
04049772: 670e                     beq.s   loc_4049782
04049774: 48780001                 pea     (1).w
04049778: 2f08                     move.l  a0,-(sp)
0404977A: 2f00                     move.l  d0,-(sp)
0404977C: 61fffffff08e             bsr.l   _ipc_kobject_set
04049782: 4e5e                     unlk    a6
04049784: 4e75                     rts
