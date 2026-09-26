040309B8: 4856                     pea     (a6)
040309BA: 2c4f                     movea.l sp,a6
040309BC: 48780400                 pea     ($400).w
040309C0: 2f2e000c                 move.l  $C(a6),-(sp)
040309C4: 2f2e0008                 move.l  8(a6),-(sp)
040309C8: 61fffffff898             bsr.l   _xdr_string
040309CE: 2200                     move.l  d0,d1
040309D0: 4280                     clr.l   d0
040309D2: 4a81                     tst.l   d1
040309D4: 6702                     beq.s   loc_40309D8
040309D6: 7001                     moveq   #1,d0
040309D8: 4e5e                     unlk    a6
040309DA: 4e75                     rts
