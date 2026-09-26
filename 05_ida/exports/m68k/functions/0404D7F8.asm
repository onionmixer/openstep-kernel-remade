0404D7F8: 4e56ffc4                 link    a6,#-$3C
0404D7FC: 2f0a                     move.l  a2,-(sp)
0404D7FE: 226e0008                 movea.l arg_0(a6),a1
0404D802: 2469001c                 movea.l $1C(a1),a2
0404D806: 2079040b57d0             movea.l (_active_u).l,a0
0404D80C: 2f28001a                 move.l  $1A(a0),-(sp)
0404D810: 486effc6                 pea     var_3A(a6)
0404D814: 2f09                     move.l  a1,-(sp)
0404D816: 206a0014                 movea.l $14(a2),a0
0404D81A: 4e90                     jsr     (a0)
0404D81C: 202effda                 move.l  var_26(a6),d0
0404D820: 246effc0                 movea.l var_40(a6),a2
0404D824: 4e5e                     unlk    a6
0404D826: 4e75                     rts
