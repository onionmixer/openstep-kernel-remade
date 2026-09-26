0409CA38: 00ae01002080ff84         ori.l   #$1002080,-$7C(a6)
0409CA40: 082e0005ff82             btst    #5,-$7E(a6)
0409CA46: 66ff0000000e             bne.l   loc_409CA56
0409CA4C: f239d0800409c99a         fmovem.x (tbyte_409C99A).l,fp0
0409CA54: 4e75                     rts
0409CA56: 50eeffb4                 st      -$4C(a6)
0409CA5A: 4e75                     rts
