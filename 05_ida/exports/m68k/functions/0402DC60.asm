0402DC60: 4856                     pea     (a6)
0402DC62: 2c4f                     movea.l sp,a6
0402DC64: 206e0008                 movea.l 8(a6),a0
0402DC68: 2010                     move.l  (a0),d0
0402DC6A: 72f7                     moveq   #$FFFFFFF7,d1
0402DC6C: c280                     and.l   d0,d1
0402DC6E: 2081                     move.l  d1,(a0)
0402DC70: 08000004                 btst    #4,d0
0402DC74: 6710                     beq.s   loc_402DC86
0402DC76: 72e7                     moveq   #$FFFFFFE7,d1
0402DC78: c280                     and.l   d0,d1
0402DC7A: 2081                     move.l  d1,(a0)
0402DC7C: 48680068                 pea     $68(a0)
0402DC80: 61fffffdc580             bsr.l   _wakeup
0402DC86: 4e5e                     unlk    a6
0402DC88: 4e75                     rts
