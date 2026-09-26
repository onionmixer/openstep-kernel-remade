0409B98E: 082800070000             btst    #7,0(a0)
0409B994: 66ff000010a2             bne.l   t_operr
0409B99A: 0c683fff0000             cmpi.w  #$3FFF,0(a0)
0409B9A0: 66ff000053d6             bne.l   slog10
0409B9A6: 0ca8800000000004         cmpi.l  #$80000000,4(a0)
0409B9AE: 66ff000053c8             bne.l   slog10
0409B9B4: 4aa80008                 tst.l   8(a0)
0409B9B8: 66ff000053be             bne.l   slog10
0409B9BE: f23948000409b7bc         fmove.x (tbyte_409B7BC).l,fp0
0409B9C6: 4e75                     rts
