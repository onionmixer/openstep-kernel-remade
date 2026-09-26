0409CC58: 082e0007ff34             btst    #7,-$CC(a6)
0409CC5E: 67ff0000000a             beq.l   loc_409CC6A
0409CC64: 08ee0003ff84             bset    #3,-$7C(a6)
0409CC6A: 082e0006ff38             btst    #6,-$C8(a6)
0409CC70: 67ff00000010             beq.l   loc_409CC82
0409CC76: f2019000                 fmovem.l d1,fpcr
0409CC7A: f22e4800ff34             fmove.x -$CC(a6),fp0
0409CC80: 4e75                     rts
0409CC82: 082e0006ff82             btst    #6,-$7E(a6)
0409CC88: 67ff00000024             beq.l   loc_409CCAE
0409CC8E: 08ee0006ff38             bset    #6,-$C8(a6)
0409CC94: 002e0000ff20             ori.b   #0,-$E0(a6)
0409CC9A: 002e0060ff18             ori.b   #$60,-$E8(a6) ; '`'
0409CCA0: 50eeffb4                 st      -$4C(a6)
0409CCA4: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409CCAC: 4e75                     rts
0409CCAE: 08ee0006ff38             bset    #6,-$C8(a6)
0409CCB4: f2019000                 fmovem.l d1,fpcr
0409CCB8: f22e4800ff34             fmove.x -$CC(a6),fp0
0409CCBE: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409CCC6: 4e75                     rts
