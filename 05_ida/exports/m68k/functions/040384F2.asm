040384F2: 4856                     pea     (a6)
040384F4: 2c4f                     movea.l sp,a6
040384F6: 206e0008                 movea.l 8(a6),a0
040384FA: 30280042                 move.w  $42(a0),d0
040384FE: 3200                     move.w  d0,d1
04038500: 0241fffe                 andi.w  #$FFFE,d1
04038504: 31410042                 move.w  d1,$42(a0)
04038508: 08000004                 btst    #4,d0
0403850C: 6710                     beq.s   loc_403851E
0403850E: 0240ffee                 andi.w  #$FFEE,d0
04038512: 31400042                 move.w  d0,$42(a0)
04038516: 2f08                     move.l  a0,-(sp)
04038518: 61fffffd1ce8             bsr.l   _wakeup
0403851E: 4e5e                     unlk    a6
04038520: 4e75                     rts
