04053D98: 4856                     pea     (a6)
04053D9A: 2c4f                     movea.l sp,a6
04053D9C: 41f9040c2b68             lea     (_swapin_queue).l,a0
04053DA2: 23c8040c2b6c             move.l  a0,(dword_40C2B6C).l
04053DA8: 2088                     move.l  a0,(a0)
04053DAA: 4e5e                     unlk    a6
04053DAC: 4e75                     rts
