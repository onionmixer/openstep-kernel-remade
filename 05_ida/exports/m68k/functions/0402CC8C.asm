0402CC8C: 4856                     pea     (a6)
0402CC8E: 2c4f                     movea.l sp,a6
0402CC90: 48780020                 pea     ($20).w
0402CC94: 2f2e000c                 move.l  $C(a6),-(sp)
0402CC98: 2f2e0008                 move.l  8(a6),-(sp)
0402CC9C: 61ff000033ba             bsr.l   _xdr_opaque
0402CCA2: 2200                     move.l  d0,d1
0402CCA4: 7001                     moveq   #1,d0
0402CCA6: 4a81                     tst.l   d1
0402CCA8: 6602                     bne.s   loc_402CCAC
0402CCAA: 4280                     clr.l   d0
0402CCAC: 4e5e                     unlk    a6
0402CCAE: 4e75                     rts
