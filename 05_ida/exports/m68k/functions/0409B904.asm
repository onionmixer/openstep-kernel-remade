0409B904: f210d080                 fmovem.x (a0),fp0
0409B908: f23c5838ffff             fcmp.b  #$FF,fp0
0409B90E: f2950008                 fble    loc_409B918
0409B912: 4ef9040a1922             jmp     slognp1
0409B918: f28e0008                 fbne    loc_409B922
0409B91C: 4ef90409c9b2             jmp     t_dz2
0409B922: f23c880000000000         fmovem.l #0,fpsr
0409B92A: 60ff0000110c             bra.l   t_operr
