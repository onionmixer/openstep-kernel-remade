0400B358: 4856                     pea     (a6)
0400B35A: 2c4f                     movea.l sp,a6
0400B35C: 42a7                     clr.l   -(sp)
0400B35E: 48780005                 pea     (5).w
0400B362: 486e000c                 pea     $C(a6)
0400B366: 2f2e0008                 move.l  8(a6),-(sp)
0400B36A: 61ff000001e4             bsr.l   _prf
0400B370: 504f                     addq.w  #8,sp
0400B372: 504f                     addq.w  #8,sp
0400B374: 4a80                     tst.l   d0
0400B376: 6706                     beq.s   loc_400B37E
0400B378: 61fffffffe92             bsr.l   _logwakeup
0400B37E: 4280                     clr.l   d0
0400B380: 4e5e                     unlk    a6
0400B382: 4e75                     rts
