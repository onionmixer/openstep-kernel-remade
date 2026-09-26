040A4412: 082e0001ff24             btst    #1,-$DC(a6)
040A4418: 67ff00000008             beq.l   loc_40A4422
040A441E: 4280                     clr.l   d0
040A4420: 4e75                     rts
040A4422: 202eff1c                 move.l  -$E4(a6),d0
040A4426: e9c00003                 bfextu  d0{0:3},d0
040A442A: 4e75                     rts
