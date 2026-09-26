04075AC0: 4856                     pea     (a6)
04075AC2: 2c4f                     movea.l sp,a6
04075AC4: 2f2e0008                 move.l  8(a6),-(sp)
04075AC8: 61ff00000008             bsr.l   _od_done
04075ACE: 4e5e                     unlk    a6
04075AD0: 4e75                     rts
