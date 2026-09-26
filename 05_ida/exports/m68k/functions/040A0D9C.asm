040A0D9C: 2010                     move.l  (a0),d0
040A0D9E: 6dff0000007c             blt.l   loc_40A0E1C
040A0DA4: 2f01                     move.l  d1,-(sp)
040A0DA6: 4281                     clr.l   d1
040A0DA8: 61ff00000918             bsr.l   slognd
040A0DAE: f21f9000                 fmovem.l (sp)+,fpcr
040A0DB2: f2394823040a0d44         fmul.x  (tbyte_40A0D44).l,fp0
040A0DBA: 60ffffffbdf6             bra.l   t_frcinx
