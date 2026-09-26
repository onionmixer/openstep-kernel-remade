0402FAAA: 4856                     pea     (a6)
0402FAAC: 2c4f                     movea.l sp,a6
0402FAAE: 206e0008                 movea.l 8(a6),a0
0402FAB2: 2010                     move.l  (a0),d0
0402FAB4: 72fe                     moveq   #$FFFFFFFE,d1
0402FAB6: c280                     and.l   d0,d1
0402FAB8: 2081                     move.l  d1,(a0)
0402FABA: 08000001                 btst    #1,d0
0402FABE: 670e                     beq.s   loc_402FACE
0402FAC0: 72fc                     moveq   #$FFFFFFFC,d1
0402FAC2: c280                     and.l   d0,d1
0402FAC4: 2081                     move.l  d1,(a0)
0402FAC6: 2f08                     move.l  a0,-(sp)
0402FAC8: 61fffffda738             bsr.l   _wakeup
0402FACE: 4e5e                     unlk    a6
0402FAD0: 4e75                     rts
