04013FD6: 4856                     pea     (a6)
04013FD8: 2c4f                     movea.l sp,a6
04013FDA: 206e0008                 movea.l 8(a6),a0
04013FDE: 006800100006             ori.w   #$10,6(a0)
04013FE4: 48680038                 pea     $38(a0)
04013FE8: 2f08                     move.l  a0,-(sp)
04013FEA: 61ff000000e8             bsr.l   _sowakeup
04013FF0: 4e5e                     unlk    a6
04013FF2: 4e75                     rts
