0406E0D2: 4e56ffa4                 link    a6,#-$5C
0406E0D6: 2f0a                     move.l  a2,-(sp)
0406E0D8: 2f02                     move.l  d2,-(sp)
0406E0DA: 242e0008                 move.l  arg_0(a6),d2
0406E0DE: 45eeffa6                 lea     var_5A(a6),a2
0406E0E2: 2f0a                     move.l  a2,-(sp)
0406E0E4: 2f02                     move.l  d2,-(sp)
0406E0E6: 61ff000000aa             bsr.l   sub_406E192
0406E0EC: 2f0a                     move.l  a2,-(sp)
0406E0EE: 2f02                     move.l  d2,-(sp)
0406E0F0: 61ffffffe39e             bsr.l   _fd_command
0406E0F6: 242eff9c                 move.l  var_64(a6),d2
0406E0FA: 246effa0                 movea.l var_60(a6),a2
0406E0FE: 4e5e                     unlk    a6
0406E100: 4e75                     rts
