0409B76C: 0810001e                 btst    #$1E,(a0)
0409B770: 67ff0000000e             beq.l   loc_409B780
0409B776: f2000420                 fdiv.x  fp1,fp0
0409B77A: 60ff00000008             bra.l   loc_409B784
0409B780: f2000423                 fmul.x  fp1,fp0
0409B784: f200a800                 fmovem.l fpsr,d0
0409B788: 08800009                 bclr    #9,d0
0409B78C: f2008800                 fmovem.l d0,fpsr
0409B790: 67ff0000000c             beq.l   loc_409B79E
0409B796: 00ae00000108ff84         ori.l   #$108,-$7C(a6)
0409B79E: 4cdf003c                 movem.l (sp)+,d2-d5
0409B7A2: 4e75                     rts
