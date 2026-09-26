040A5024: 082e0001ff24             btst    #1,-$DC(a6)
040A502A: 67ff00000074             beq.l   loc_40A50A0
040A5030: 202eff10                 move.l  -$F0(a6),d0
040A5034: e9c00183                 bfextu  d0{6:3},d0
040A5038: 43f9040a501c             lea     (dword_40A501C).l,a1
040A503E: 10310000                 move.b  (a1,d0.w),d0
040A5042: 4a280002                 tst.b   2(a0)
040A5046: 67ff0000000a             beq.l   loc_40A5052
040A504C: 08e800070000             bset    #7,0(a0)
040A5052: f210d800                 fmovem.x (a0),d0
040A5056: 0c000080                 cmpi.b  #$80,d0
040A505A: 66ff0000000c             bne.l   loc_40A5068
040A5060: f22ef080ff50             fmovem.x fp0,-$B0(a6)
040A5066: 4e75                     rts
040A5068: 0c000040                 cmpi.b  #$40,d0 ; '@'
040A506C: 66ff0000000c             bne.l   loc_40A507A
040A5072: f22ef040ff5c             fmovem.x fp1,-$A4(a6)
040A5078: 4e75                     rts
040A507A: 0c000020                 cmpi.b  #$20,d0 ; ' '
040A507E: 66ff0000000c             bne.l   loc_40A508C
040A5084: f22ef020ff68             fmovem.x fp2,-$98(a6)
040A508A: 4e75                     rts
040A508C: 0c000010                 cmpi.b  #$10,d0
040A5090: 66ff0000000c             bne.l   locret_40A509E
040A5096: f22ef010ff74             fmovem.x fp3,-$8C(a6)
040A509C: 4e75                     rts
040A509E: 4e75                     rts
040A50A0: 61fffffff370             bsr.l   g_opcls
040A50A6: 0c000003                 cmpi.b  #3,d0
040A50AA: 67ff00000012             beq.l   loc_40A50BE
040A50B0: 202eff1c                 move.l  -$E4(a6),d0
040A50B4: e9c00183                 bfextu  d0{6:3},d0
040A50B8: 60ffffffff7e             bra.l   loc_40A5038
040A50BE: 61fffffff36c             bsr.l   g_dfmtou
040A50C4: 2248                     movea.l a0,a1
040A50C6: 206e000c                 movea.l $C(a6),a0
040A50CA: 0c8000000000             cmpi.l  #0,d0
040A50D0: 67ff0000011c             beq.l   dest_ext
040A50D6: 0c8000000001             cmpi.l  #1,d0
040A50DC: 67ff00000088             beq.l   dest_sgl
