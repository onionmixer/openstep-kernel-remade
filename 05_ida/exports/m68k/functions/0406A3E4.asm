0406A3E4: 4856                     pea     (a6)
0406A3E6: 2c4f                     movea.l sp,a6
0406A3E8: 2079040c3640             movea.l (_evg).l,a0
0406A3EE: 2068001c                 movea.l $1C(a0),a0
0406A3F2: 48680001                 pea     1(a0)
0406A3F6: 61ff000005dc             bsr.l   sub_406A9D4
0406A3FC: 33f9040c36e8040c36ea     move.w  (_waitFrameRate).l,(_waitFrameTime).l
0406A406: 4e5e                     unlk    a6
0406A408: 4e75                     rts
