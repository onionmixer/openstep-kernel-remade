0400B41C: 4e56fffc                 link    a6,#-4
0400B420: 2f02                     move.l  d2,-(sp)
0400B422: 242e0008                 move.l  arg_0(a6),d2
0400B426: 2d42fffc                 move.l  d2,var_4(a6)
0400B42A: 486efffc                 pea     var_4(a6)
0400B42E: 48780008                 pea     (8).w
0400B432: 486e0010                 pea     arg_8(a6)
0400B436: 2f2e000c                 move.l  arg_4(a6),-(sp)
0400B43A: 61ff00000114             bsr.l   _prf
0400B440: 206efffc                 movea.l var_4(a6),a0
0400B444: 4210                     clr.b   (a0)
0400B446: 52aefffc                 addq.l  #1,var_4(a6)
0400B44A: 202efffc                 move.l  var_4(a6),d0
0400B44E: 9082                     sub.l   d2,d0
0400B450: 242efff8                 move.l  var_8(a6),d2
0400B454: 4e5e                     unlk    a6
0400B456: 4e75                     rts
