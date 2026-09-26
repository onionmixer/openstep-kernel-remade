0409B942: 082800070000             btst    #7,0(a0)
0409B948: 66ff000010ee             bne.l   t_operr
0409B94E: 0c683fff0000             cmpi.w  #$3FFF,0(a0)
0409B954: 66ff00005e02             bne.l   slogn
0409B95A: 0ca8800000000004         cmpi.l  #$80000000,4(a0)
0409B962: 66ff00005df4             bne.l   slogn
0409B968: 4aa80008                 tst.l   8(a0)
0409B96C: 66ff00005dea             bne.l   slogn
0409B972: f23948000409b7bc         fmove.x (tbyte_409B7BC).l,fp0
0409B97A: 4e75                     rts
