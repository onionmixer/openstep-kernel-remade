0400B4C6: 4856                     pea     (a6)
0400B4C8: 2c4f                     movea.l sp,a6
0400B4CA: 42a7                     clr.l   -(sp)
0400B4CC: 48780005                 pea     (5).w
0400B4D0: 2f2e0010                 move.l  $10(a6),-(sp)
0400B4D4: 2f2e000c                 move.l  $C(a6),-(sp)
0400B4D8: 61ff00000076             bsr.l   _prf
0400B4DE: 504f                     addq.w  #8,sp
0400B4E0: 504f                     addq.w  #8,sp
0400B4E2: 4a80                     tst.l   d0
0400B4E4: 6706                     beq.s   loc_400B4EC
0400B4E6: 61fffffffd24             bsr.l   _logwakeup
0400B4EC: 4280                     clr.l   d0
0400B4EE: 4e5e                     unlk    a6
0400B4F0: 4e75                     rts
