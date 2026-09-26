0409CB4A: 00ae00001248ff84         ori.l   #$1248,-$7C(a6)
0409CB52: 082e0004ff82             btst    #4,-$7E(a6)
0409CB58: 67ff00000028             beq.l   loc_409CB82
0409CB5E: 42aeff8c                 clr.l   -$74(a6)
0409CB62: 42aeff90                 clr.l   -$70(a6)
0409CB66: 42aeff94                 clr.l   -$6C(a6)
0409CB6A: ecee0143ff18             bfclr   -$E8(a6){5:3}
0409CB70: 08ae0004ff21             bclr    #4,-$DF(a6)
0409CB76: 08ee0007ff19             bset    #7,-$E7(a6)
0409CB7C: 08ae0002ff24             bclr    #2,-$DC(a6)
0409CB82: 61ff00007534             bsr.l   ovf_r_k
0409CB88: ecee0008ff36             bfclr   -$CA(a6){0:8}
0409CB8E: 67ff00000010             beq.l   loc_409CBA0
0409CB94: 08ee0007ff34             bset    #7,-$CC(a6)
0409CB9A: 08ee0007ff8c             bset    #7,-$74(a6)
0409CBA0: f22ed080ff34             fmovem.x -$CC(a6),fp0
0409CBA6: 4e75                     rts
