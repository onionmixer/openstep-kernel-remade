04061CCA: 4e56fffc                 link    a6,#-4
04061CCE: 48780001                 pea     (1).w
04061CD2: 486effff                 pea     var_1(a6)
04061CD6: 2f2e0008                 move.l  arg_0(a6),-(sp)
04061CDA: 61fffff9f9f4             bsr.l   _copyinmsg
04061CE0: 4a80                     tst.l   d0
04061CE2: 6608                     bne.s   loc_4061CEC
04061CE4: 102effff                 move.b  var_1(a6),d0
04061CE8: 49c0                     extb.l  d0
04061CEA: 6002                     bra.s   loc_4061CEE
04061CEC: 70ff                     moveq   #$FFFFFFFF,d0
04061CEE: 4e5e                     unlk    a6
04061CF0: 4e75                     rts
