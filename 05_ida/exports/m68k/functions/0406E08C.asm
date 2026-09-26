0406E08C: 4e56ffa4                 link    a6,#-$5C
0406E090: 48e72030                 movem.l d2/a2-a3,-(sp)
0406E094: 242e0008                 move.l  arg_0(a6),d2
0406E098: 266e000c                 movea.l arg_4(a6),a3
0406E09C: 4878005a                 pea     ($5A).w
0406E0A0: 45eeffa6                 lea     var_5A(a6),a2
0406E0A4: 2f0a                     move.l  a2,-(sp)
0406E0A6: 61ff00024d6a             bsr.l   _bzero
0406E0AC: 7205                     moveq   #5,d1
0406E0AE: 2d41ffac                 move.l  d1,var_54(a6)
0406E0B2: 2d7c00002710ffa8         move.l  #$2710,var_58(a6)
0406E0BA: 2f0a                     move.l  a2,-(sp)
0406E0BC: 2f02                     move.l  d2,-(sp)
0406E0BE: 61ffffffe3d0             bsr.l   _fd_command
0406E0C4: 36aefff4                 move.w  var_C(a6),(a3)
0406E0C8: 4cee0c04ff98             movem.l var_68(a6),d2/a2-a3
0406E0CE: 4e5e                     unlk    a6
0406E0D0: 4e75                     rts
