04061C78: 4e56fffc                 link    a6,#-4
04061C7C: 1d6e000fffff             move.b  arg_7(a6),var_1(a6)
04061C82: 48780001                 pea     (1).w
04061C86: 2f2e0008                 move.l  arg_0(a6),-(sp)
04061C8A: 486effff                 pea     var_1(a6)
04061C8E: 61fffff9f9ce             bsr.l   _copyoutmsg
04061C94: 4281                     clr.l   d1
04061C96: 4a80                     tst.l   d0
04061C98: 6702                     beq.s   loc_4061C9C
04061C9A: 72ff                     moveq   #$FFFFFFFF,d1
04061C9C: 2001                     move.l  d1,d0
04061C9E: 4e5e                     unlk    a6
04061CA0: 4e75                     rts
