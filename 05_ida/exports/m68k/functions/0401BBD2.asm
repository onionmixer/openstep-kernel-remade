0401BBD2: 4856                     pea     (a6)
0401BBD4: 2c4f                     movea.l sp,a6
0401BBD6: 41f9040ae866             lea     (_afswitch).l,a0
0401BBDC: 203c040ae8ee             move.l  #$40AE8EE,d0
0401BBE2: b088                     cmp.l   a0,d0
0401BBE4: 6310                     bls.s   loc_401BBF6
0401BBE6: 4a90                     tst.l   (a0)
0401BBE8: 6606                     bne.s   loc_401BBF0
0401BBEA: 20bc0401bbfa             move.l  #$401BBFA,(a0)
0401BBF0: 5048                     addq.w  #8,a0
0401BBF2: b088                     cmp.l   a0,d0
0401BBF4: 62f0                     bhi.s   loc_401BBE6
0401BBF6: 4e5e                     unlk    a6
0401BBF8: 4e75                     rts
