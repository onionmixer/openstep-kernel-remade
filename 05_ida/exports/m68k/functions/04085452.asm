04085452: 4e56ffe0                 link    a6,#-$20
04085456: 2d79040b21d8ffe0         move.l  (dword_40B21D8).l,var_20(a6)
0408545E: 2d79040b21dcffe4         move.l  (dword_40B21DC).l,var_1C(a6)
04085466: 2d79040b21e0ffe8         move.l  (dword_40B21E0).l,var_18(a6)
0408546E: 2d79040b21e4ffec         move.l  (dword_40B21E4).l,var_14(a6)
04085476: 2d79040b21e8fff0         move.l  (dword_40B21E8).l,var_10(a6)
0408547E: 2d79040b21ecfff4         move.l  (dword_40B21EC).l,var_C(a6)
04085486: 2d7c00000132fff4         move.l  #$132,var_C(a6)
0408548E: 7220                     moveq   #$20,d1 ; ' '
04085490: 2d41ffe4                 move.l  d1,var_1C(a6)
04085494: 2d6e0008fff0             move.l  arg_0(a6),var_10(a6)
0408549A: 2d79040b21fcfff8         move.l  (dword_40B21FC).l,var_8(a6)
040854A2: 2d6e000cfffc             move.l  arg_4(a6),var_4(a6)
040854A8: 42a7                     clr.l   -(sp)
040854AA: 48780001                 pea     (1).w
040854AE: 486effe0                 pea     var_20(a6)
040854B2: 61fffffc3706             bsr.l   _msg_send
040854B8: 4e5e                     unlk    a6
040854BA: 4e75                     rts
