04018552: 4856                     pea     (a6)
04018554: 2c4f                     movea.l sp,a6
04018556: 2f0b                     move.l  a3,-(sp)
04018558: 2f0a                     move.l  a2,-(sp)
0401855A: 266e0008                 movea.l 8(a6),a3
0401855E: 246e000c                 movea.l $C(a6),a2
04018562: 4aab0040                 tst.l   $40(a3)
04018566: 6708                     beq.s   loc_4018570
04018568: 2f0b                     move.l  a3,-(sp)
0401856A: 61ff00000018             bsr.l   sub_4018584
04018570: 526a0006                 addq.w  #1,6(a2)
04018574: 274a0040                 move.l  a2,$40(a3)
04018578: 246efff8                 movea.l -8(a6),a2
0401857C: 266efffc                 movea.l -4(a6),a3
04018580: 4e5e                     unlk    a6
04018582: 4e75                     rts
