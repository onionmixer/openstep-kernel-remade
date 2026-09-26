04096386: 4e56fff8                 link    a6,#-8
0409638A: 2d79040c8f00fffc         move.l  (dword_40C8F00).l,var_4(a6)
04096392: 206efffc                 movea.l var_4(a6),a0
04096396: 43e8002a                 lea     $2A(a0),a1
0409639A: 2d49fff8                 move.l  a1,var_8(a6)
0409639E: 206efff8                 movea.l var_8(a6),a0
040963A2: 20ae000c                 move.l  arg_4(a6),(a0)
040963A6: 48780242                 pea     ($242).w
040963AA: 2f2efffc                 move.l  var_4(a6),-(sp)
040963AE: 2f2e0008                 move.l  arg_0(a6),-(sp)
040963B2: 61ffffff9706             bsr.l   _en_send
040963B8: 4e5e                     unlk    a6
040963BA: 4e75                     rts
