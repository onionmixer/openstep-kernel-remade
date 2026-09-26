040726D0: 4856                     pea     (a6)
040726D2: 2c4f                     movea.l sp,a6
040726D4: 2f2e0010                 move.l  $10(a6),-(sp)
040726D8: 2f2e000c                 move.l  $C(a6),-(sp)
040726DC: 61fffffffdce             bsr.l   _lpr_send
040726E2: 4e5e                     unlk    a6
040726E4: 4e75                     rts
