0408510E: 4e56ffe0                 link    a6,#-$20
04085112: 2d79040b21d8ffe0         move.l  (dword_40B21D8).l,var_20(a6)
0408511A: 2d79040b21dcffe4         move.l  (dword_40B21DC).l,var_1C(a6)
04085122: 2d79040b21e0ffe8         move.l  (dword_40B21E0).l,var_18(a6)
0408512A: 2d79040b21e4ffec         move.l  (dword_40B21E4).l,var_14(a6)
04085132: 2d79040b21e8fff0         move.l  (dword_40B21E8).l,var_10(a6)
0408513A: 2d79040b21ecfff4         move.l  (dword_40B21EC).l,var_C(a6)
04085142: 2d6e0010fff4             move.l  arg_8(a6),var_C(a6)
04085148: 7220                     moveq   #$20,d1 ; ' '
0408514A: 2d41ffe4                 move.l  d1,var_1C(a6)
0408514E: 2d6e0008fff0             move.l  arg_0(a6),var_10(a6)
04085154: 2d79040b21fcfff8         move.l  (dword_40B21FC).l,var_8(a6)
0408515C: 2d6e000cfffc             move.l  arg_4(a6),var_4(a6)
04085162: 42a7                     clr.l   -(sp)
04085164: 48780021                 pea     ($21).w
04085168: 486effe0                 pea     var_20(a6)
0408516C: 61fffffc3a4c             bsr.l   _msg_send
04085172: 4e5e                     unlk    a6
04085174: 4e75                     rts
