04089C56: 4e56ffe0                 link    a6,#-$20
04089C5A: 4ab9040c3628             tst.l   (_evOpenCalled).l
04089C60: 671e                     beq.s   loc_4089C80
04089C62: 4ab9040c3308             tst.l   (_autoDimmed).l
04089C68: 670e                     beq.s   loc_4089C78
04089C6A: 2039040c3620             move.l  (_dimmedBrightness).l,d0
04089C70: b0b9040c3324             cmp.l   (_curBright).l,d0
04089C76: 6d1a                     blt.s   loc_4089C92
04089C78: 2039040c3324             move.l  (_curBright).l,d0
04089C7E: 6012                     bra.s   loc_4089C92
04089C80: 486effe0                 pea     var_20(a6)
04089C84: 61ff00007b5c             bsr.l   _nvram_check
04089C8A: e9ee0106ffe1             bfextu  var_1F(a6){4:6},d0
04089C90: 584f                     addq.w  #4,sp
04089C92: 2f00                     move.l  d0,-(sp)
04089C94: 61ffffffff92             bsr.l   _vidSetBrightness
04089C9A: 4e5e                     unlk    a6
04089C9C: 4e75                     rts
