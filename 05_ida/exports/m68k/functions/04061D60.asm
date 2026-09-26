04061D60: 4e56fffc                 link    a6,#-4
04061D64: 48780004                 pea     (4).w
04061D68: 486efffc                 pea     var_4(a6)
04061D6C: 2f2e0008                 move.l  arg_0(a6),-(sp)
04061D70: 61fffff9f95e             bsr.l   _copyinmsg
04061D76: 2200                     move.l  d0,d1
04061D78: 70ff                     moveq   #$FFFFFFFF,d0
04061D7A: 4a81                     tst.l   d1
04061D7C: 6604                     bne.s   loc_4061D82
04061D7E: 202efffc                 move.l  var_4(a6),d0
04061D82: 4e5e                     unlk    a6
04061D84: 4e75                     rts
