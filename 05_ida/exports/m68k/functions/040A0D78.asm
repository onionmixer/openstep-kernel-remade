040A0D78: 2010                     move.l  (a0),d0
040A0D7A: 6dff000000a0             blt.l   loc_40A0E1C
040A0D80: 2f01                     move.l  d1,-(sp)
040A0D82: 4281                     clr.l   d1
040A0D84: 61ff000009d2             bsr.l   slogn
040A0D8A: f21f9000                 fmovem.l (sp)+,fpcr
040A0D8E: f2394823040a0d34         fmul.x  (tbyte_40A0D34).l,fp0
040A0D96: 60ffffffbe1a             bra.l   t_frcinx
