040A02F8: 2010                     move.l  (a0),d0
040A02FA: 028080000000             andi.l  #$80000000,d0
040A0300: 008000800000             ori.l   #$800000,d0
040A0306: 2f00                     move.l  d0,-(sp)
040A0308: f23c44003f800000         fmove.s #1.0,fp0
040A0310: f2019000                 fmovem.l d1,fpcr
040A0314: f21f4422                 fadd.s  (sp)+,fp0
040A0318: 60ffffffc898             bra.l   t_frcinx
