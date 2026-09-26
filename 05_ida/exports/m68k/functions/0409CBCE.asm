0409CBCE: 082e0007ff28             btst    #7,-$D8(a6)
0409CBD4: 67ff0000000a             beq.l   loc_409CBE0
0409CBDA: 08ee0003ff84             bset    #3,-$7C(a6)
0409CBE0: 082e0006ff2c             btst    #6,-$D4(a6)
0409CBE6: 67ff00000036             beq.l   loc_409CC1E
0409CBEC: f2019000                 fmovem.l d1,fpcr
0409CBF0: f22e4800ff28             fmove.x -$D8(a6),fp0
0409CBF6: 102eff18                 move.b  -$E8(a6),d0
0409CBFA: 020000e0                 andi.b  #$E0,d0
0409CBFE: 0c000060                 cmpi.b  #$60,d0 ; '`'
0409CC02: 66ff00000018             bne.l   locret_409CC1C
0409CC08: 082e0006ff38             btst    #6,-$C8(a6)
0409CC0E: 66ff0000000c             bne.l   locret_409CC1C
0409CC14: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409CC1C: 4e75                     rts
0409CC1E: 082e0006ff82             btst    #6,-$7E(a6)
0409CC24: 67ff00000018             beq.l   loc_409CC3E
0409CC2A: 002e0060ff20             ori.b   #$60,-$E0(a6) ; '`'
0409CC30: 50eeffb4                 st      -$4C(a6)
0409CC34: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409CC3C: 4e75                     rts
0409CC3E: 08ee0006ff2c             bset    #6,-$D4(a6)
0409CC44: f2019000                 fmovem.l d1,fpcr
0409CC48: f22e4800ff28             fmove.x -$D8(a6),fp0
0409CC4E: 00ae01004080ff84         ori.l   #$1004080,-$7C(a6)
0409CC56: 4e75                     rts
