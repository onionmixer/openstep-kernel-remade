0409B9DA: 082800070000             btst    #7,0(a0)
0409B9E0: 66ff00001056             bne.l   t_operr
0409B9E6: 0c683fff0000             cmpi.w  #$3FFF,0(a0)
0409B9EC: 66ff000053d2             bne.l   slog2
0409B9F2: 0ca8800000000004         cmpi.l  #$80000000,4(a0)
0409B9FA: 66ff000053c4             bne.l   slog2
0409BA00: 4aa80008                 tst.l   8(a0)
0409BA04: 66ff000053ba             bne.l   slog2
0409BA0A: f23948000409b7bc         fmove.x (tbyte_409B7BC).l,fp0
0409BA12: 4e75                     rts
