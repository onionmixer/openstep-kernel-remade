04013FF4: 4856                     pea     (a6)
04013FF6: 2c4f                     movea.l sp,a6
04013FF8: 206e0008                 movea.l 8(a6),a0
04013FFC: 006800200006             ori.w   #$20,6(a0) ; ' '
04014002: 48680022                 pea     $22(a0)
04014006: 2f08                     move.l  a0,-(sp)
04014008: 61ff000000ca             bsr.l   _sowakeup
0401400E: 4e5e                     unlk    a6
04014010: 4e75                     rts
