0409630E: 4e56fffc                 link    a6,#-4
04096312: 61fffff6b26a             bsr.l   _get_vbr
04096318: 2d40fffc                 move.l  d0,var_4(a6)
0409631C: 206efffc                 movea.l var_4(a6),a0
04096320: 43e80008                 lea     8(a0),a1
04096324: 23d1040b5614             move.l  (a1),(dword_40B5614).l
0409632A: 206efffc                 movea.l var_4(a6),a0
0409632E: 43e8000c                 lea     $C(a0),a1
04096332: 23d1040b5618             move.l  (a1),(dword_40B5618).l
04096338: 206efffc                 movea.l var_4(a6),a0
0409633C: 43e80008                 lea     8(a0),a1
04096340: 22bc04096736             move.l  #$4096736,(a1)
04096346: 206efffc                 movea.l var_4(a6),a0
0409634A: 43e8000c                 lea     $C(a0),a1
0409634E: 22bc04096736             move.l  #$4096736,(a1)
04096354: 4e5e                     unlk    a6
04096356: 4e75                     rts
