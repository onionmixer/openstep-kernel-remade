040A442C: 082e0001ff24             btst    #1,-$DC(a6)
040A4432: 67ff00000008             beq.l   loc_40A443C
040A4438: 4280                     clr.l   d0
040A443A: 4e75                     rts
040A443C: 202eff1c                 move.l  -$E4(a6),d0
040A4440: e9c000c3                 bfextu  d0{3:3},d0
040A4444: 0c000001                 cmpi.b  #1,d0
040A4448: 66ff00000008             bne.l   loc_40A4452
040A444E: 7001                     moveq   #1,d0
040A4450: 4e75                     rts
040A4452: 0c000005                 cmpi.b  #5,d0
040A4456: 66ff00000008             bne.l   loc_40A4460
040A445C: 7002                     moveq   #2,d0
040A445E: 4e75                     rts
040A4460: 4280                     clr.l   d0
040A4462: 4e75                     rts
