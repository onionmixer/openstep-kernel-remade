04032B16: 4856                     pea     (a6)
04032B18: 2c4f                     movea.l sp,a6
04032B1A: 206e0008                 movea.l 8(a6),a0
04032B1E: 2068002e                 movea.l $2E(a0),a0
04032B22: 10280075                 move.b  $75(a0),d0
04032B26: 1200                     move.b  d0,d1
04032B28: 0201fffe                 andi.b  #$FE,d1
04032B2C: 11410075                 move.b  d1,$75(a0)
04032B30: 08000001                 btst    #1,d0
04032B34: 6712                     beq.s   loc_4032B48
04032B36: 020100fc                 andi.b  #$FC,d1
04032B3A: 11410075                 move.b  d1,$75(a0)
04032B3E: 48680075                 pea     $75(a0)
04032B42: 61fffffd76be             bsr.l   _wakeup
04032B48: 4e5e                     unlk    a6
04032B4A: 4e75                     rts
