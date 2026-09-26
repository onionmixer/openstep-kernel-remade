04088840: 4e56ffac                 link    a6,#-$54
04088844: 2f0b                     move.l  a3,-(sp)
04088846: 2f0a                     move.l  a2,-(sp)
04088848: 266e0008                 movea.l arg_0(a6),a3
0408884C: 48780052                 pea     ($52).w
04088850: 45eeffae                 lea     var_52(a6),a2
04088854: 2f0a                     move.l  a2,-(sp)
04088856: 61ff0000a5ba             bsr.l   _bzero
0408885C: 14bc0010                 move.b  #$10,(a2)
04088860: 2053                     movea.l (a3),a0
04088862: 1028001d                 move.b  $1D(a0),d0
04088866: 02000007                 andi.b  #7,d0
0408886A: efee0003ffaf             bfins   d0,var_51(a6){0:3}
04088870: 426effb0                 clr.w   var_50(a6)
04088874: 1d7c0001ffb2             move.b  #1,var_4E(a6)
0408887A: 7278                     moveq   #$78,d1 ; 'x'
0408887C: 2d41ffc6                 move.l  d1,var_3A(a6)
04088880: 42a7                     clr.l   -(sp)
04088882: 2f0a                     move.l  a2,-(sp)
04088884: 2f0b                     move.l  a3,-(sp)
04088886: 61ff00000d24             bsr.l   sub_40895AC
0408888C: 246effa4                 movea.l var_5C(a6),a2
04088890: 266effa8                 movea.l var_58(a6),a3
04088894: 4e5e                     unlk    a6
04088896: 4e75                     rts
