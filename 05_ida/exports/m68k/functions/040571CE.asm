040571CE: 4856                     pea     (a6)
040571D0: 2c4f                     movea.l sp,a6
040571D2: 206e0008                 movea.l 8(a6),a0
040571D6: 2050                     movea.l (a0),a0
040571D8: 2028001c                 move.l  $1C(a0),d0
040571DC: 4e5e                     unlk    a6
040571DE: 4e75                     rts
