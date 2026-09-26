040309DC: 4856                     pea     (a6)
040309DE: 2c4f                     movea.l sp,a6
040309E0: 48780020                 pea     ($20).w
040309E4: 2f2e000c                 move.l  $C(a6),-(sp)
040309E8: 2f2e0008                 move.l  8(a6),-(sp)
040309EC: 61fffffff874             bsr.l   _xdr_string
040309F2: 2200                     move.l  d0,d1
040309F4: 4280                     clr.l   d0
040309F6: 4a81                     tst.l   d1
040309F8: 6702                     beq.s   loc_40309FC
040309FA: 7001                     moveq   #1,d0
040309FC: 4e5e                     unlk    a6
040309FE: 4e75                     rts
