040A4346: 61ff000000ca             bsr.l   g_opcls
040A434C: 0c400003                 cmpi.w  #3,d0
040A4350: 66ff0000000c             bne.l   loc_40A435E
040A4356: 61ff000000d4             bsr.l   g_dfmtou
040A435C: 4e75                     rts
040A435E: 082e0001ff24             btst    #1,-$DC(a6)
040A4364: 67ff0000004c             beq.l   loc_40A43B2
040A436A: 202eff10                 move.l  -$F0(a6),d0
040A436E: e9c00242                 bfextu  d0{9:2},d0
040A4372: 0c8000000002             cmpi.l  #2,d0
040A4378: 67ff00000082             beq.l   loc_40A43FC
040A437E: 0c8000000003             cmpi.l  #3,d0
040A4384: 67ff0000007a             beq.l   loc_40A4400
040A438A: 302eff10                 move.w  -$F0(a6),d0
040A438E: 02800000007f             andi.l  #$7F,d0
040A4394: 0c8000000033             cmpi.l  #$33,d0 ; '3'
040A439A: 67ff00000068             beq.l   loc_40A4404
040A43A0: 0c8000000030             cmpi.l  #$30,d0 ; '0'
040A43A6: 67ff0000005c             beq.l   loc_40A4404
040A43AC: 60ff0000005a             bra.l   loc_40A4408
040A43B2: 202eff1c                 move.l  -$E4(a6),d0
040A43B6: 028000440000             andi.l  #$440000,d0
040A43BC: 0c8000400000             cmpi.l  #$400000,d0
040A43C2: 67ff00000038             beq.l   loc_40A43FC
040A43C8: 0c8000440000             cmpi.l  #$440000,d0
040A43CE: 67ff00000030             beq.l   loc_40A4400
040A43D4: 202eff1c                 move.l  -$E4(a6),d0
040A43D8: 0280007f0000             andi.l  #$7F0000,d0
040A43DE: 0c8000270000             cmpi.l  #$270000,d0
040A43E4: 67ff0000001e             beq.l   loc_40A4404
040A43EA: 0c8000240000             cmpi.l  #$240000,d0
040A43F0: 67ff00000012             beq.l   loc_40A4404
040A43F6: 60ff00000010             bra.l   loc_40A4408
040A43FC: 7001                     moveq   #1,d0
040A43FE: 4e75                     rts
040A4400: 7002                     moveq   #2,d0
040A4402: 4e75                     rts
040A4404: 7000                     moveq   #0,d0
040A4406: 4e75                     rts
040A4408: 202eff80                 move.l  -$80(a6),d0
040A440C: e9c00602                 bfextu  d0{24:2},d0
040A4410: 4e75                     rts
