04061CF2: 4856                     pea     (a6)
04061CF4: 2c4f                     movea.l sp,a6
04061CF6: 48780004                 pea     (4).w
04061CFA: 2f2e0008                 move.l  8(a6),-(sp)
04061CFE: 486e000c                 pea     $C(a6)
04061D02: 61fffff9f95a             bsr.l   _copyoutmsg
04061D08: 4281                     clr.l   d1
04061D0A: 4a80                     tst.l   d0
04061D0C: 6702                     beq.s   loc_4061D10
04061D0E: 72ff                     moveq   #$FFFFFFFF,d1
04061D10: 2001                     move.l  d1,d0
04061D12: 4e5e                     unlk    a6
04061D14: 4e75                     rts
