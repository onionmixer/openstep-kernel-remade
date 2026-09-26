0406A394: 4856                     pea     (a6)
0406A396: 2c4f                     movea.l sp,a6
0406A398: 2079040c3640             movea.l (_evg).l,a0
0406A39E: 7001                     moveq   #1,d0
0406A3A0: 21400040                 move.l  d0,$40(a0)
0406A3A4: 48780001                 pea     (1).w
0406A3A8: 61ff0000062a             bsr.l   sub_406A9D4
0406A3AE: 3039040c36e8             move.w  (_waitFrameRate).l,d0
0406A3B4: 5240                     addq.w  #1,d0
0406A3B6: 33c0040c36ea             move.w  d0,(_waitFrameTime).l
0406A3BC: 33f9040c36ee040c36ec     move.w  (_waitSustain).l,(_waitSusTime).l
0406A3C6: 4e5e                     unlk    a6
0406A3C8: 4e75                     rts
