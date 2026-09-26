0401C99E: 4856                     pea     (a6)
0401C9A0: 2c4f                     movea.l sp,a6
0401C9A2: 206e0008                 movea.l 8(a6),a0
0401C9A6: 720c                     moveq   #$C,d1
0401C9A8: 21410004                 move.l  d1,4(a0)
0401C9AC: 42680008                 clr.w   8(a0)
0401C9B0: 2f08                     move.l  a0,-(sp)
0401C9B2: 61ffffff56ae             bsr.l   _m_free
0401C9B8: 4e5e                     unlk    a6
0401C9BA: 4e75                     rts
