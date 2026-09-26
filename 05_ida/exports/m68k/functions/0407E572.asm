0407E572: 4e56ffac                 link    a6,#-$54
0407E576: 48e73820                 movem.l d2-d4/a2,-(sp)
0407E57A: 282e0008                 move.l  arg_0(a6),d4
0407E57E: 242e000c                 move.l  arg_4(a6),d2
0407E582: 262e0010                 move.l  arg_8(a6),d3
0407E586: 48780052                 pea     ($52).w
0407E58A: 45eeffae                 lea     var_52(a6),a2
0407E58E: 2f0a                     move.l  a2,-(sp)
0407E590: 61ff00014880             bsr.l   _bzero
0407E596: 14bc0025                 move.b  #$25,(a2) ; '%'
0407E59A: 2d42ffbe                 move.l  d2,var_42(a6)
0407E59E: 7208                     moveq   #8,d1
0407E5A0: 2d41ffc2                 move.l  d1,var_3E(a6)
0407E5A4: 42aeffba                 clr.l   var_46(a6)
0407E5A8: 723c                     moveq   #$3C,d1 ; '<'
0407E5AA: 2d41ffc6                 move.l  d1,var_3A(a6)
0407E5AE: 2f03                     move.l  d3,-(sp)
0407E5B0: 2f0a                     move.l  a2,-(sp)
0407E5B2: 2f04                     move.l  d4,-(sp)
0407E5B4: 61ff000000c2             bsr.l   sub_407E678
0407E5BA: defc0014                 adda.w  #$14,sp
0407E5BE: 4a80                     tst.l   d0
0407E5C0: 6604                     bne.s   loc_407E5C6
0407E5C2: 4280                     clr.l   d0
0407E5C4: 600e                     bra.s   loc_407E5D4
0407E5C6: 4879040ab987             pea     (aErrorCanTReadD).l; "ERROR: Can't read device capacity\n"
0407E5CC: 61fffff8cd8a             bsr.l   _printf
0407E5D2: 7001                     moveq   #1,d0
0407E5D4: 4cee041cff9c             movem.l var_64(a6),d2-d4/a2
0407E5DA: 4e5e                     unlk    a6
0407E5DC: 4e75                     rts
