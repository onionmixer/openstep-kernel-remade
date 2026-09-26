040282C0: 4856                     pea     (a6)
040282C2: 2c4f                     movea.l sp,a6
040282C4: 206e0008                 movea.l 8(a6),a0
040282C8: 20b9040aec10             move.l  (_rfsfreesp).l,(a0)
040282CE: 23c8040aec10             move.l  a0,(_rfsfreesp).l
040282D4: 4e5e                     unlk    a6
040282D6: 4e75                     rts
