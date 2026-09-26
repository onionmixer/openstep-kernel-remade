04030A8C: 4856                     pea     (a6)
04030A8E: 2c4f                     movea.l sp,a6
04030A90: 2f2e000c                 move.l  $C(a6),-(sp)
04030A94: 2f2e0008                 move.l  8(a6),-(sp)
04030A98: 61ffffffffc4             bsr.l   _xdr_bp_address
04030A9E: 2200                     move.l  d0,d1
04030AA0: 4280                     clr.l   d0
04030AA2: 4a81                     tst.l   d1
04030AA4: 6702                     beq.s   loc_4030AA8
04030AA6: 7001                     moveq   #1,d0
04030AA8: 4e5e                     unlk    a6
04030AAA: 4e75                     rts
