040A37CE: f2019000                 fmovem.l d1,fpcr
040A37D2: f23c44003f800000         fmove.s #1.0,fp0
040A37DA: 2010                     move.l  (a0),d0
040A37DC: 008000800001             ori.l   #$800001,d0
040A37E2: f2004422                 fadd.s  d0,fp0
040A37E6: 60ffffff93ca             bra.l   t_frcinx
