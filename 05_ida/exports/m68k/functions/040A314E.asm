040A314E: e9ee0343ff1c             bfextu  -$E4(a6){13:3},d0
040A3154: 0c000003                 cmpi.b  #3,d0
040A3158: 6fff00000016             ble.l   loc_40A3170
040A315E: f227e002                 fmovem.x fp1,-(sp)
040A3162: 7207                     moveq   #7,d1
040A3164: 9280                     sub.l   d0,d1
040A3166: 4280                     clr.l   d0
040A3168: 03c0                     bset    d1,d0
040A316A: f21fd800                 fmovem.x (sp)+,d0
040A316E: 4e75                     rts
040A3170: 0c000000                 cmpi.b  #0,d0
040A3174: 67ff00000030             beq.l   loc_40A31A6
040A317A: 0c000001                 cmpi.b  #1,d0
040A317E: 67ff0000001e             beq.l   loc_40A319E
040A3184: 0c000002                 cmpi.b  #2,d0
040A3188: 67ff0000000c             beq.l   loc_40A3196
040A318E: f22ef040ff74             fmovem.x fp1,-$8C(a6)
040A3194: 4e75                     rts
040A3196: f22ef040ff68             fmovem.x fp1,-$98(a6)
040A319C: 4e75                     rts
040A319E: f22ef040ff5c             fmovem.x fp1,-$A4(a6)
040A31A4: 4e75                     rts
040A31A6: f22ef040ff50             fmovem.x fp1,-$B0(a6)
040A31AC: 4e75                     rts
