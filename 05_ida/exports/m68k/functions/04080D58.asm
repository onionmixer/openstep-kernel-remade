04080D58: 4856                     pea     (a6)
04080D5A: 2c4f                     movea.l sp,a6
04080D5C: 202e0008                 move.l  8(a6),d0
04080D60: 7201                     moveq   #1,d1
04080D62: b280                     cmp.l   d0,d1
04080D64: 6606                     bne.s   loc_4080D6C
04080D66: 7008                     moveq   #8,d0
04080D68: 4840                     swap    d0
04080D6A: 6008                     bra.s   loc_4080D74
04080D6C: 7202                     moveq   #2,d1
04080D6E: 203c0000c000             move.l  #$C000,d0
04080D74: 4e5e                     unlk    a6
04080D76: 4e75                     rts
