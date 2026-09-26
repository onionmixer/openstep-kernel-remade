040887EA: 4e56ffac                 link    a6,#-$54
040887EE: 48e72030                 movem.l d2/a2-a3,-(sp)
040887F2: 266e0008                 movea.l arg_0(a6),a3
040887F6: 242e000c                 move.l  arg_4(a6),d2
040887FA: 48780052                 pea     ($52).w
040887FE: 45eeffae                 lea     var_52(a6),a2
04088802: 2f0a                     move.l  a2,-(sp)
04088804: 61ff0000a60c             bsr.l   _bzero
0408880A: 4212                     clr.b   (a2)
0408880C: 2053                     movea.l (a3),a0
0408880E: 1028001d                 move.b  $1D(a0),d0
04088812: 02000007                 andi.b  #7,d0
04088816: efee0003ffaf             bfins   d0,var_51(a6){0:3}
0408881C: 7278                     moveq   #$78,d1 ; 'x'
0408881E: 2d41ffc6                 move.l  d1,var_3A(a6)
04088822: 42aeffbe                 clr.l   var_42(a6)
04088826: 42aeffea                 clr.l   var_16(a6)
0408882A: 2f02                     move.l  d2,-(sp)
0408882C: 2f0a                     move.l  a2,-(sp)
0408882E: 2f0b                     move.l  a3,-(sp)
04088830: 61ff00000d7a             bsr.l   sub_40895AC
04088836: 4cee0c04ffa0             movem.l var_60(a6),d2/a2-a3
0408883C: 4e5e                     unlk    a6
0408883E: 4e75                     rts
