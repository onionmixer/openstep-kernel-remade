0405718E: 4856                     pea     (a6)
04057190: 2c4f                     movea.l sp,a6
04057192: 206e0008                 movea.l 8(a6),a0
04057196: 42a7                     clr.l   -(sp)
04057198: 48780042                 pea     ($42).w
0405719C: 2f28000c                 move.l  $C(a0),-(sp)
040571A0: 61ffffff2f36             bsr.l   _send_notification
040571A6: 4e5e                     unlk    a6
040571A8: 4e75                     rts
