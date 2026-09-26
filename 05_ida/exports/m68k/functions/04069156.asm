04069156: 4856                     pea     (a6)
04069158: 2c4f                     movea.l sp,a6
0406915A: 2039040c3620             move.l  (_dimmedBrightness).l,d0
04069160: b0b9040c3324             cmp.l   (_curBright).l,d0
04069166: 6c08                     bge.s   loc_4069170
04069168: 2f00                     move.l  d0,-(sp)
0406916A: 61ffffffff8c             bsr.l   _SetCurBrightness
04069170: 7201                     moveq   #1,d1
04069172: 23c1040c3308             move.l  d1,(_autoDimmed).l
04069178: 4e5e                     unlk    a6
0406917A: 4e75                     rts
