040A0818: 202eff80                 move.l  -$80(a6),d0
040A081C: 0280ffffff00             andi.l  #$FFFFFF00,d0
040A0822: f2009000                 fmovem.l d0,fpcr
040A0826: 30280000                 move.w  0(a0),d0
040A082A: 00407fff                 ori.w   #$7FFF,d0
040A082E: 0880000e                 bclr    #$E,d0
040A0832: 31400000                 move.w  d0,0(a0)
040A0836: f2104800                 fmove.x (a0),fp0
040A083A: 4e75                     rts
