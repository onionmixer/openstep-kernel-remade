040888F0: 4e56ffac                 link    a6,#-$54
040888F4: 48e73030                 movem.l d2-d3/a2-a3,-(sp)
040888F8: 266e0008                 movea.l arg_0(a6),a3
040888FC: 242e000c                 move.l  arg_4(a6),d2
04088900: 48780052                 pea     ($52).w
04088904: 45eeffae                 lea     var_52(a6),a2
04088908: 2f0a                     move.l  a2,-(sp)
0408890A: 61ff0000a506             bsr.l   _bzero
04088910: 222b0010                 move.l  $10(a3),d1
04088914: 14bc0003                 move.b  #3,(a2)
04088918: 2053                     movea.l (a3),a0
0408891A: 1028001d                 move.b  $1D(a0),d0
0408891E: 02000007                 andi.b  #7,d0
04088922: efee0003ffaf             bfins   d0,var_51(a6){0:3}
04088928: 1d7c001affb2             move.b  #$1A,var_4E(a6)
0408892E: 2d41ffbe                 move.l  d1,var_42(a6)
04088932: 761a                     moveq   #$1A,d3
04088934: 2d43ffc2                 move.l  d3,var_3E(a6)
04088938: 42aeffba                 clr.l   var_46(a6)
0408893C: 7678                     moveq   #$78,d3 ; 'x'
0408893E: 2d43ffc6                 move.l  d3,var_3A(a6)
04088942: 2f02                     move.l  d2,-(sp)
04088944: 2f0a                     move.l  a2,-(sp)
04088946: 2f0b                     move.l  a3,-(sp)
04088948: 61ff00000c62             bsr.l   sub_40895AC
0408894E: 4cee0c0cff9c             movem.l var_64(a6),d2-d3/a2-a3
04088954: 4e5e                     unlk    a6
04088956: 4e75                     rts
