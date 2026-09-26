040526F2: 4856                     pea     (a6)
040526F4: 2c4f                     movea.l sp,a6
040526F6: 206e0008                 movea.l 8(a6),a0
040526FA: 226e000c                 movea.l $C(a6),a1
040526FE: 4aa80004                 tst.l   4(a0)
04052702: 6710                     beq.s   loc_4052714
04052704: 22a80024                 move.l  $24(a0),(a1)
04052708: 2f11                     move.l  (a1),-(sp)
0405270A: 61ffffffcbd8             bsr.l   _pset_reference
04052710: 4280                     clr.l   d0
04052712: 6002                     bra.s   loc_4052716
04052714: 7005                     moveq   #5,d0
04052716: 4e5e                     unlk    a6
04052718: 4e75                     rts
