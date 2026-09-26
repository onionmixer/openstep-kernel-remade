040A4B96: 0caeffffffffff2c         cmpi.l  #$FFFFFFFF,-$D4(a6)
040A4B9E: 66ff0000001c             bne.l   loc_40A4BBC
040A4BA4: 0c6ec000ff28             cmpi.w  #$C000,-$D8(a6)
040A4BAA: 67ff00000014             beq.l   loc_40A4BC0
040A4BB0: 0c6ebfffff28             cmpi.w  #$BFFF,-$D8(a6)
040A4BB6: 67ff00000008             beq.l   loc_40A4BC0
040A4BBC: 7001                     moveq   #1,d0
040A4BBE: 4e75                     rts
040A4BC0: 4280                     clr.l   d0
040A4BC2: 4e75                     rts
