0402ECA8: 4856                     pea     (a6)
0402ECAA: 2c4f                     movea.l sp,a6
0402ECAC: 48780008                 pea     (8).w
0402ECB0: 2f2e000c                 move.l  $C(a6),-(sp)
0402ECB4: 2f2e0008                 move.l  8(a6),-(sp)
0402ECB8: 61ff0000139e             bsr.l   _xdr_opaque
0402ECBE: 4e5e                     unlk    a6
0402ECC0: 4e75                     rts
