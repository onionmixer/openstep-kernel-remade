04030994: 4856                     pea     (a6)
04030996: 2c4f                     movea.l sp,a6
04030998: 487800ff                 pea     ($FF).w
0403099C: 2f2e000c                 move.l  $C(a6),-(sp)
040309A0: 2f2e0008                 move.l  8(a6),-(sp)
040309A4: 61fffffff8bc             bsr.l   _xdr_string
040309AA: 2200                     move.l  d0,d1
040309AC: 4280                     clr.l   d0
040309AE: 4a81                     tst.l   d1
040309B0: 6702                     beq.s   loc_40309B4
040309B2: 7001                     moveq   #1,d0
040309B4: 4e5e                     unlk    a6
040309B6: 4e75                     rts
