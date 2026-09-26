04061CA2: 4e56fffc                 link    a6,#-4
04061CA6: 48780001                 pea     (1).w
04061CAA: 486effff                 pea     var_1(a6)
04061CAE: 2f2e0008                 move.l  arg_0(a6),-(sp)
04061CB2: 61fffff9fa1c             bsr.l   _copyinmsg
04061CB8: 4a80                     tst.l   d0
04061CBA: 6608                     bne.s   loc_4061CC4
04061CBC: 102effff                 move.b  var_1(a6),d0
04061CC0: 49c0                     extb.l  d0
04061CC2: 6002                     bra.s   loc_4061CC6
04061CC4: 70ff                     moveq   #$FFFFFFFF,d0
04061CC6: 4e5e                     unlk    a6
04061CC8: 4e75                     rts
