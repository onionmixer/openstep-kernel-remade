0406C7EE: 4856                     pea     (a6)
0406C7F0: 2c4f                     movea.l sp,a6
0406C7F2: 202e0008                 move.l  8(a6),d0
0406C7F6: d0b9040c32f8             add.l   (_slot_id_bmap).l,d0
0406C7FC: 23c0040c376c             move.l  d0,(_fd_controller).l
0406C802: 4239040c3791             clr.b   (byte_40C3791).l
0406C808: 4e5e                     unlk    a6
0406C80A: 4e75                     rts
