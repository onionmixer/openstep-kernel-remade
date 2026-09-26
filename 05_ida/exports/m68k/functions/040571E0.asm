040571E0: 4856                     pea     (a6)
040571E2: 2c4f                     movea.l sp,a6
040571E4: 206e0008                 movea.l 8(a6),a0
040571E8: 2050                     movea.l (a0),a0
040571EA: 20280020                 move.l  $20(a0),d0
040571EE: 4e5e                     unlk    a6
040571F0: 4e75                     rts
