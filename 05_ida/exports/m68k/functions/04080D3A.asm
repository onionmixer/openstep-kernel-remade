04080D3A: 4856                     pea     (a6)
04080D3C: 2c4f                     movea.l sp,a6
04080D3E: 202e0008                 move.l  8(a6),d0
04080D42: 7201                     moveq   #1,d1
04080D44: b280                     cmp.l   d0,d1
04080D46: 6606                     bne.s   loc_4080D4E
04080D48: 700c                     moveq   #$C,d0
04080D4A: 4840                     swap    d0
04080D4C: 6006                     bra.s   loc_4080D54
04080D4E: 7202                     moveq   #2,d1
04080D50: 7001                     moveq   #1,d0
04080D52: 4840                     swap    d0
04080D54: 4e5e                     unlk    a6
04080D56: 4e75                     rts
