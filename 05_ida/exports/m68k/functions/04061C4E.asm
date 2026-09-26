04061C4E: 4e56fffc                 link    a6,#-4
04061C52: 1d6e000fffff             move.b  arg_7(a6),var_1(a6)
04061C58: 48780001                 pea     (1).w
04061C5C: 2f2e0008                 move.l  arg_0(a6),-(sp)
04061C60: 486effff                 pea     var_1(a6)
04061C64: 61fffff9f9f8             bsr.l   _copyoutmsg
04061C6A: 4281                     clr.l   d1
04061C6C: 4a80                     tst.l   d0
04061C6E: 6702                     beq.s   loc_4061C72
04061C70: 72ff                     moveq   #$FFFFFFFF,d1
04061C72: 2001                     move.l  d1,d0
04061C74: 4e5e                     unlk    a6
04061C76: 4e75                     rts
