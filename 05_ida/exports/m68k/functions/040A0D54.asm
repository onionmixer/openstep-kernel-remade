040A0D54: 2010                     move.l  (a0),d0
040A0D56: 6dff000000c4             blt.l   loc_40A0E1C
040A0D5C: 2f01                     move.l  d1,-(sp)
040A0D5E: 4281                     clr.l   d1
040A0D60: 61ff00000960             bsr.l   slognd
040A0D66: f21f9000                 fmovem.l (sp)+,fpcr
040A0D6A: f2394823040a0d34         fmul.x  (tbyte_40A0D34).l,fp0
040A0D72: 60ffffffbe3e             bra.l   t_frcinx
