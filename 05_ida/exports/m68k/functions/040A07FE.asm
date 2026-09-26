040A07FE: 08a800070000             bclr    #7,0(a0)
040A0804: 61ffffffe12a             bsr.l   nrm_set
040A080A: 30280000                 move.w  0(a0),d0
040A080E: 04403fff                 subi.w  #$3FFF,d0
040A0812: f2005000                 fmove.w d0,fp0
040A0816: 4e75                     rts
