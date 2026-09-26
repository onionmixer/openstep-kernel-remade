0407CBA2: 4e56ffac                 link    a6,#-$54
0407CBA6: 48e73038                 movem.l d2-d3/a2-a4,-(sp)
0407CBAA: 286e0008                 movea.l arg_0(a6),a4
0407CBAE: 242e000c                 move.l  arg_4(a6),d2
0407CBB2: 45eeffae                 lea     var_52(a6),a2
0407CBB6: 2654                     movea.l (a4),a3
0407CBB8: 48780052                 pea     ($52).w
0407CBBC: 2f0a                     move.l  a2,-(sp)
0407CBBE: 61ff00016252             bsr.l   _bzero
0407CBC4: 222b00b2                 move.l  $B2(a3),d1
0407CBC8: 14bc0012                 move.b  #$12,(a2)
0407CBCC: 206b0008                 movea.l 8(a3),a0
0407CBD0: 1028001d                 move.b  $1D(a0),d0
0407CBD4: 02000007                 andi.b  #7,d0
0407CBD8: efee0003ffaf             bfins   d0,var_51(a6){0:3}
0407CBDE: 1d7c0042ffb2             move.b  #$42,var_4E(a6) ; 'B'
0407CBE4: 2d41ffbe                 move.l  d1,var_42(a6)
0407CBE8: 7642                     moveq   #$42,d3 ; 'B'
0407CBEA: 2d43ffc2                 move.l  d3,var_3E(a6)
0407CBEE: 42aeffba                 clr.l   var_46(a6)
0407CBF2: 763c                     moveq   #$3C,d3 ; '<'
0407CBF4: 2d43ffc6                 move.l  d3,var_3A(a6)
0407CBF8: 2f02                     move.l  d2,-(sp)
0407CBFA: 2f0a                     move.l  a2,-(sp)
0407CBFC: 2f0c                     move.l  a4,-(sp)
0407CBFE: 61ff00001a78             bsr.l   sub_407E678
0407CC04: 4cee1c0cff98             movem.l var_68(a6),d2-d3/a2-a4
0407CC0A: 4e5e                     unlk    a6
0407CC0C: 4e75                     rts
