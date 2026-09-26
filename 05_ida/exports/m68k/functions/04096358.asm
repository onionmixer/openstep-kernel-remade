04096358: 4e56fffc                 link    a6,#-4
0409635C: 61fffff6b220             bsr.l   _get_vbr
04096362: 2d40fffc                 move.l  d0,var_4(a6)
04096366: 206efffc                 movea.l var_4(a6),a0
0409636A: 43e80008                 lea     8(a0),a1
0409636E: 22b9040b5614             move.l  (dword_40B5614).l,(a1)
04096374: 206efffc                 movea.l var_4(a6),a0
04096378: 43e8000c                 lea     $C(a0),a1
0409637C: 22b9040b5618             move.l  (dword_40B5618).l,(a1)
04096382: 4e5e                     unlk    a6
04096384: 4e75                     rts
