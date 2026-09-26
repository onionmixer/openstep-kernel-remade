040691DC: 4856                     pea     (a6)
040691DE: 2c4f                     movea.l sp,a6
040691E0: 2239040c3324             move.l  (_curBright).l,d1
040691E6: d2ae0008                 add.l   8(a6),d1
040691EA: 2f01                     move.l  d1,-(sp)
040691EC: 61ffffffff0a             bsr.l   _SetCurBrightness
040691F2: 23c0040c3324             move.l  d0,(_curBright).l
040691F8: 4e5e                     unlk    a6
040691FA: 4e75                     rts
