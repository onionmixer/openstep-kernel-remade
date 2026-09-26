040A36AE: f2019000                 fmovem.l d1,fpcr
040A36B2: f23c44003f800000         fmove.s #1.0,fp0
040A36BA: 2010                     move.l  (a0),d0
040A36BC: 008000800001             ori.l   #$800001,d0
040A36C2: f2004422                 fadd.s  d0,fp0
040A36C6: 60ffffff94ea             bra.l   t_frcinx
