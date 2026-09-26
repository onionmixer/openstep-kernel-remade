040A31AE: e9ee0183ff1c             bfextu  -$E4(a6){6:3},d0
040A31B4: 0c000003                 cmpi.b  #3,d0
040A31B8: 6fff00000016             ble.l   loc_40A31D0
040A31BE: f227e001                 fmovem.x fp0,-(sp)
040A31C2: 7207                     moveq   #7,d1
040A31C4: 9280                     sub.l   d0,d1
040A31C6: 4280                     clr.l   d0
040A31C8: 03c0                     bset    d1,d0
040A31CA: f21fd800                 fmovem.x (sp)+,d0
040A31CE: 4e75                     rts
040A31D0: 0c000000                 cmpi.b  #0,d0
040A31D4: 67ff00000030             beq.l   loc_40A3206
040A31DA: 0c000001                 cmpi.b  #1,d0
040A31DE: 67ff0000001e             beq.l   loc_40A31FE
040A31E4: 0c000002                 cmpi.b  #2,d0
040A31E8: 67ff0000000c             beq.l   loc_40A31F6
040A31EE: f22ef080ff74             fmovem.x fp0,-$8C(a6)
040A31F4: 4e75                     rts
040A31F6: f22ef080ff68             fmovem.x fp0,-$98(a6)
040A31FC: 4e75                     rts
040A31FE: f22ef080ff5c             fmovem.x fp0,-$A4(a6)
040A3204: 4e75                     rts
040A3206: f22ef080ff50             fmovem.x fp0,-$B0(a6)
040A320C: 4e75                     rts
