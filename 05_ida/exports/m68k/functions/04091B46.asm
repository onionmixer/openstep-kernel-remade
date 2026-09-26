04091B46: 4856                     pea     (a6)
04091B48: 2c4f                     movea.l sp,a6
04091B4A: 4280                     clr.l   d0
04091B4C: 102e000b                 move.b  $B(a6),d0
04091B50: 2f00                     move.l  d0,-(sp)
04091B52: 61ff0000000e             bsr.l   _rtc_real_read
04091B58: 0280000000ff             andi.l  #$FF,d0
04091B5E: 4e5e                     unlk    a6
04091B60: 4e75                     rts
