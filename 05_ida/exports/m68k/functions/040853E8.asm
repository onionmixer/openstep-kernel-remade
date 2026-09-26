040853E8: 4e56ffe0                 link    a6,#-$20
040853EC: 2d79040b21d8ffe0         move.l  (dword_40B21D8).l,var_20(a6)
040853F4: 2d79040b21dcffe4         move.l  (dword_40B21DC).l,var_1C(a6)
040853FC: 2d79040b21e0ffe8         move.l  (dword_40B21E0).l,var_18(a6)
04085404: 2d79040b21e4ffec         move.l  (dword_40B21E4).l,var_14(a6)
0408540C: 2d79040b21e8fff0         move.l  (dword_40B21E8).l,var_10(a6)
04085414: 2d79040b21ecfff4         move.l  (dword_40B21EC).l,var_C(a6)
0408541C: 2d7c00000131fff4         move.l  #$131,var_C(a6)
04085424: 7220                     moveq   #$20,d1 ; ' '
04085426: 2d41ffe4                 move.l  d1,var_1C(a6)
0408542A: 2d6e0008fff0             move.l  arg_0(a6),var_10(a6)
04085430: 2d79040b21fcfff8         move.l  (dword_40B21FC).l,var_8(a6)
04085438: 2d6e000cfffc             move.l  arg_4(a6),var_4(a6)
0408543E: 42a7                     clr.l   -(sp)
04085440: 48780001                 pea     (1).w
04085444: 486effe0                 pea     var_20(a6)
04085448: 61fffffc3770             bsr.l   _msg_send
0408544E: 4e5e                     unlk    a6
04085450: 4e75                     rts
