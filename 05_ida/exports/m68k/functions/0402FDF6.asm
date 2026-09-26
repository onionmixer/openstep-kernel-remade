0402FDF6: 4856                     pea     (a6)
0402FDF8: 2c4f                     movea.l sp,a6
0402FDFA: 2f2e000c                 move.l  $C(a6),-(sp)
0402FDFE: 2f2e0008                 move.l  8(a6),-(sp)
0402FE02: 61ff0000005e             bsr.l   _xdr_u_long
0402FE08: 4e5e                     unlk    a6
0402FE0A: 4e75                     rts
