04061D16: 4e56fffc                 link    a6,#-4
04061D1A: 48780004                 pea     (4).w
04061D1E: 486efffc                 pea     var_4(a6)
04061D22: 2f2e0008                 move.l  arg_0(a6),-(sp)
04061D26: 61fffff9f9a8             bsr.l   _copyinmsg
04061D2C: 2200                     move.l  d0,d1
04061D2E: 70ff                     moveq   #$FFFFFFFF,d0
04061D30: 4a81                     tst.l   d1
04061D32: 6604                     bne.s   loc_4061D38
04061D34: 202efffc                 move.l  var_4(a6),d0
04061D38: 4e5e                     unlk    a6
04061D3A: 4e75                     rts
