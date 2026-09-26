0401C98C: 4856                     pea     (a6)
0401C98E: 2c4f                     movea.l sp,a6
0401C990: 2f2e0008                 move.l  8(a6),-(sp)
0401C994: 61ffffff5810             bsr.l   _m_freem
0401C99A: 4e5e                     unlk    a6
0401C99C: 4e75                     rts
