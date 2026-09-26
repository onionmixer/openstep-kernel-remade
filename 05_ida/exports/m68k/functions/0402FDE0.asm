0402FDE0: 4856                     pea     (a6)
0402FDE2: 2c4f                     movea.l sp,a6
0402FDE4: 2f2e000c                 move.l  $C(a6),-(sp)
0402FDE8: 2f2e0008                 move.l  8(a6),-(sp)
0402FDEC: 61ff0000001e             bsr.l   _xdr_long
0402FDF2: 4e5e                     unlk    a6
0402FDF4: 4e75                     rts
