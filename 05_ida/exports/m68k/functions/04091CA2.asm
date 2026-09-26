04091CA2: 4856                     pea     (a6)
04091CA4: 2c4f                     movea.l sp,a6
04091CA6: 2f2e0010                 move.l  $10(a6),-(sp)
04091CAA: 2f2e000c                 move.l  $C(a6),-(sp)
04091CAE: 4280                     clr.l   d0
04091CB0: 102e000b                 move.b  $B(a6),d0
04091CB4: 2f00                     move.l  d0,-(sp)
04091CB6: 61ff00000008             bsr.l   _rtc_real_blkread
04091CBC: 4e5e                     unlk    a6
04091CBE: 4e75                     rts
