040889C2: 4e56ffac                 link    a6,#-$54
040889C6: 48e72038                 movem.l d2/a2-a4,-(sp)
040889CA: 286e0008                 movea.l arg_0(a6),a4
040889CE: 266e000c                 movea.l arg_4(a6),a3
040889D2: 242e0010                 move.l  arg_8(a6),d2
040889D6: 48780052                 pea     ($52).w
040889DA: 45eeffae                 lea     var_52(a6),a2
040889DE: 2f0a                     move.l  a2,-(sp)
040889E0: 61ff0000a430             bsr.l   _bzero
040889E6: 14bc001a                 move.b  #$1A,(a2)
040889EA: 2054                     movea.l (a4),a0
040889EC: 1028001d                 move.b  $1D(a0),d0
040889F0: 02000007                 andi.b  #7,d0
040889F4: efee0003ffaf             bfins   d0,var_51(a6){0:3}
040889FA: 202b003c                 move.l  $3C(a3),d0
040889FE: 2d40ffc2                 move.l  d0,var_3E(a6)
04088A02: 1d40ffb2                 move.b  d0,var_4E(a6)
04088A06: 2d4bffbe                 move.l  a3,var_42(a6)
04088A0A: 42aeffba                 clr.l   var_46(a6)
04088A0E: 7278                     moveq   #$78,d1 ; 'x'
04088A10: 2d41ffc6                 move.l  d1,var_3A(a6)
04088A14: 2f02                     move.l  d2,-(sp)
04088A16: 2f0a                     move.l  a2,-(sp)
04088A18: 2f0c                     move.l  a4,-(sp)
04088A1A: 61ff00000b90             bsr.l   sub_40895AC
04088A20: 4cee1c04ff9c             movem.l var_64(a6),d2/a2-a4
04088A26: 4e5e                     unlk    a6
04088A28: 4e75                     rts
