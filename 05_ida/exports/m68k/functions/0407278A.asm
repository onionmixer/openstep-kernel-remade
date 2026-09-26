0407278A: 4856                     pea     (a6)
0407278C: 2c4f                     movea.l sp,a6
0407278E: 206e0008                 movea.l 8(a6),a0
04072792: 42a7                     clr.l   -(sp)
04072794: 48780004                 pea     (4).w
04072798: 2f10                     move.l  (a0),-(sp)
0407279A: 61ffffffff34             bsr.l   _np_send
040727A0: 4e5e                     unlk    a6
040727A2: 4e75                     rts
