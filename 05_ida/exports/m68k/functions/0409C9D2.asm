0409C9D2: f23c880000000000         fmovem.l #0,fpsr
0409C9DA: 082e0002ff82             btst    #2,-$7E(a6)
0409C9E0: 66ff00000036             bne.l   loc_409CA18
0409C9E6: 082e0007ff34             btst    #7,-$CC(a6)
0409C9EC: 67ff00000018             beq.l   loc_409CA06
0409C9F2: f239d0800409c982         fmovem.x (tbyte_409C982).l,fp0
0409C9FA: 08ee0003ff84             bset    #3,-$7C(a6)
0409CA00: 60ff0000000c             bra.l   loc_409CA0E
0409CA06: f239d0800409c98e         fmovem.x (tbyte_409C98E).l,fp0
0409CA0E: 00ae02000410ff84         ori.l   #$2000410,-$7C(a6)
0409CA16: 4e75                     rts
0409CA18: 082e0007ff34             btst    #7,-$CC(a6)
0409CA1E: 67ff0000000a             beq.l   loc_409CA2A
0409CA24: 08ee0003ff84             bset    #3,-$7C(a6)
0409CA2A: 00ae02000410ff84         ori.l   #$2000410,-$7C(a6)
0409CA32: 50eeffb4                 st      -$4C(a6)
0409CA36: 4e75                     rts
