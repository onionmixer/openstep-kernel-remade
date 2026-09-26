0402E49C: 4856                     pea     (a6)
0402E49E: 2c4f                     movea.l sp,a6
0402E4A0: 206e0008                 movea.l 8(a6),a0
0402E4A4: 22680014                 movea.l $14(a0),a1
0402E4A8: 7201                     moveq   #1,d1
0402E4AA: 8390                     or.l    d1,(a0)
0402E4AC: 48690022                 pea     $22(a1)
0402E4B0: 61fffffe5ba4             bsr.l   _sbwakeup
0402E4B6: 4e5e                     unlk    a6
0402E4B8: 4e75                     rts
