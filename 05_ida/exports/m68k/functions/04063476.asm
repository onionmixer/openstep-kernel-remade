04063476: 4856                     pea     (a6)
04063478: 2c4f                     movea.l sp,a6
0406347A: 2f02                     move.l  d2,-(sp)
0406347C: 4282                     clr.l   d2
0406347E: 61ffffffff6e             bsr.l   _vswap_allocate
04063484: 4a80                     tst.l   d0
04063486: 670e                     beq.s   loc_4063496
04063488: 2f2e0008                 move.l  8(a6),-(sp)
0406348C: 2f00                     move.l  d0,-(sp)
0406348E: 61fffffff4e6             bsr.l   _pagerfile_pager_create
04063494: 2400                     move.l  d0,d2
04063496: 2002                     move.l  d2,d0
04063498: 242efffc                 move.l  -4(a6),d2
0406349C: 4e5e                     unlk    a6
0406349E: 4e75                     rts
