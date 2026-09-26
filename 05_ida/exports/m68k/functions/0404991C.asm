0404991C: 4e56fff8                 link    a6,#-8
04049920: 486efff8                 pea     var_8(a6)
04049924: 486efffc                 pea     var_4(a6)
04049928: 2079040b5648             movea.l (_active_threads).l,a0
0404992E: 2068000c                 movea.l $C(a0),a0
04049932: 2f28007c                 move.l  $7C(a0),-(sp)
04049936: 61ffffff757e             bsr.l   _ipc_port_alloc
0404993C: 4a80                     tst.l   d0
0404993E: 6704                     beq.s   loc_4049944
04049940: 42aefffc                 clr.l   var_4(a6)
04049944: 202efffc                 move.l  var_4(a6),d0
04049948: 4e5e                     unlk    a6
0404994A: 4e75                     rts
