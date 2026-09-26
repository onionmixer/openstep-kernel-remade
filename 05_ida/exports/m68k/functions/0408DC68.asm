0408DC68: 4856                     pea     (a6)
0408DC6A: 2c4f                     movea.l sp,a6
0408DC6C: 202e0008                 move.l  8(a6),d0
0408DC70: d0b9040c32f8             add.l   (_slot_id_bmap).l,d0
0408DC76: 4e5e                     unlk    a6
0408DC78: 4e75                     rts
