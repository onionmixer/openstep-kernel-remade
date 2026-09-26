0406F1A8: 4856                     pea     (a6)
0406F1AA: 2c4f                     movea.l sp,a6
0406F1AC: 23f9040b6954040b68f4     move.l  (dword_40B6954).l,(dword_40B68F4).l
0406F1B6: 23f9040b6960040b68f0     move.l  (dword_40B6960).l,(dword_40B68F0).l
0406F1C0: 4279040b68da             clr.w   (word_40B68DA).l
0406F1C6: 4279040b68d8             clr.w   (word_40B68D8).l
0406F1CC: 23fc040b6900040b68fa     move.l  #$40B6900,(dword_40B68FA).l
0406F1D6: 7002                     moveq   #2,d0
0406F1D8: 41f9040b6902             lea     (unk_40B6902).l,a0
0406F1DE: 4250                     clr.w   (a0)
0406F1E0: 5548                     subq.w  #2,a0
0406F1E2: 51c8fffa                 dbf     d0,loc_406F1DE
0406F1E6: 4240                     clr.w   d0
0406F1E8: 5380                     subq.l  #1,d0
0406F1EA: 64f2                     bcc.s   loc_406F1DE
0406F1EC: 4e5e                     unlk    a6
0406F1EE: 4e75                     rts
