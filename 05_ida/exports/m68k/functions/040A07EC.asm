040A07EC: 30280000                 move.w  0(a0),d0
040A07F0: 0880000f                 bclr    #$F,d0
040A07F4: 04403fff                 subi.w  #$3FFF,d0
040A07F8: f2005000                 fmove.w d0,fp0
040A07FC: 4e75                     rts
