04061D3C: 4856                     pea     (a6)
04061D3E: 2c4f                     movea.l sp,a6
04061D40: 48780004                 pea     (4).w
04061D44: 2f2e0008                 move.l  8(a6),-(sp)
04061D48: 486e000c                 pea     $C(a6)
04061D4C: 61fffff9f910             bsr.l   _copyoutmsg
04061D52: 4281                     clr.l   d1
04061D54: 4a80                     tst.l   d0
04061D56: 6702                     beq.s   loc_4061D5A
04061D58: 72ff                     moveq   #$FFFFFFFF,d1
04061D5A: 2001                     move.l  d1,d0
04061D5C: 4e5e                     unlk    a6
04061D5E: 4e75                     rts
