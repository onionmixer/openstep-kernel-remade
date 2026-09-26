040166FC: 4856                     pea     (a6)
040166FE: 2c4f                     movea.l sp,a6
04016700: 202e0008                 move.l  8(a6),d0
04016704: 670e                     beq.s   loc_4016714
04016706: 487904016798             pea     (_unp_discard).l
0401670C: 2f00                     move.l  d0,-(sp)
0401670E: 61ff00000008             bsr.l   _unp_scan
04016714: 4e5e                     unlk    a6
04016716: 4e75                     rts
