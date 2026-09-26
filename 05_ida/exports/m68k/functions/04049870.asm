04049870: 4856                     pea     (a6)
04049872: 2c4f                     movea.l sp,a6
04049874: 206e0008                 movea.l 8(a6),a0
04049878: 22680060                 movea.l $60(a0),a1
0404987C: b3e8005c                 cmpa.l  $5C(a0),a1
04049880: 6608                     bne.s   loc_404988A
04049882: 5291                     addq.l  #1,(a1)
04049884: 52a90018                 addq.l  #1,$18(a1)
04049888: 600a                     bra.s   loc_4049894
0404988A: 2f09                     move.l  a1,-(sp)
0404988C: 61ffffff7970             bsr.l   _ipc_port_copy_send
04049892: 2240                     movea.l d0,a1
04049894: 2009                     move.l  a1,d0
04049896: 4e5e                     unlk    a6
04049898: 4e75                     rts
