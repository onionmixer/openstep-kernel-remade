04032B4C: 4856                     pea     (a6)
04032B4E: 2c4f                     movea.l sp,a6
04032B50: 206e0008                 movea.l 8(a6),a0
04032B54: 202e000c                 move.l  $C(a6),d0
04032B58: b0a8003e                 cmp.l   $3E(a0),d0
04032B5C: 660c                     bne.s   loc_4032B6A
04032B5E: 52b9040b35ce             addq.l  #1,(dword_40B35CE).l
04032B64: 72ff                     moveq   #$FFFFFFFF,d1
04032B66: 2141003e                 move.l  d1,$3E(a0)
04032B6A: b0a8002c                 cmp.l   $2C(a0),d0
04032B6E: 6610                     bne.s   loc_4032B80
04032B70: 52b9040b35d2             addq.l  #1,(dword_40B35D2).l
04032B76: 72ff                     moveq   #$FFFFFFFF,d1
04032B78: 2141002c                 move.l  d1,$2C(a0)
04032B7C: 42280030                 clr.b   $30(a0)
04032B80: 4e5e                     unlk    a6
04032B82: 4e75                     rts
