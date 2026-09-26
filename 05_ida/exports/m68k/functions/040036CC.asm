040036CC: 4856                     pea     (a6)
040036CE: 2c4f                     movea.l sp,a6
040036D0: 206e000c                 movea.l $C(a6),a0
040036D4: 222e0008                 move.l  8(a6),d1
040036D8: 4c791800040af7e4         divsl.l (_hz).l,d0:d1
040036E0: 2081                     move.l  d1,(a0)
040036E2: 4c390800040af7e8         muls.l  (_tick).l,d0
040036EA: 21400004                 move.l  d0,4(a0)
040036EE: 4e5e                     unlk    a6
040036F0: 4e75                     rts
