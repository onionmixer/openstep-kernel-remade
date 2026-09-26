04088782: 4e56ffac                 link    a6,#-$54
04088786: 48e73030                 movem.l d2-d3/a2-a3,-(sp)
0408878A: 266e0008                 movea.l arg_0(a6),a3
0408878E: 242e000c                 move.l  arg_4(a6),d2
04088792: 48780052                 pea     ($52).w
04088796: 45eeffae                 lea     var_52(a6),a2
0408879A: 2f0a                     move.l  a2,-(sp)
0408879C: 61ff0000a674             bsr.l   _bzero
040887A2: 222b0004                 move.l  4(a3),d1
040887A6: 14bc0012                 move.b  #$12,(a2)
040887AA: 2053                     movea.l (a3),a0
040887AC: 1028001d                 move.b  $1D(a0),d0
040887B0: 02000007                 andi.b  #7,d0
040887B4: efee0003ffaf             bfins   d0,var_51(a6){0:3}
040887BA: 1d7c0042ffb2             move.b  #$42,var_4E(a6) ; 'B'
040887C0: 2d41ffbe                 move.l  d1,var_42(a6)
040887C4: 7642                     moveq   #$42,d3 ; 'B'
040887C6: 2d43ffc2                 move.l  d3,var_3E(a6)
040887CA: 42aeffba                 clr.l   var_46(a6)
040887CE: 7678                     moveq   #$78,d3 ; 'x'
040887D0: 2d43ffc6                 move.l  d3,var_3A(a6)
040887D4: 2f02                     move.l  d2,-(sp)
040887D6: 2f0a                     move.l  a2,-(sp)
040887D8: 2f0b                     move.l  a3,-(sp)
040887DA: 61ff00000dd0             bsr.l   sub_40895AC
040887E0: 4cee0c0cff9c             movem.l var_64(a6),d2-d3/a2-a3
040887E6: 4e5e                     unlk    a6
040887E8: 4e75                     rts
