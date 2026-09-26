04085056: 4e56ffe8                 link    a6,#-$18
0408505A: 2d79040b21d8ffe8         move.l  (dword_40B21D8).l,var_18(a6)
04085062: 2d79040b21dcffec         move.l  (dword_40B21DC).l,var_14(a6)
0408506A: 2d79040b21e0fff0         move.l  (dword_40B21E0).l,var_10(a6)
04085072: 2d79040b21e4fff4         move.l  (dword_40B21E4).l,var_C(a6)
0408507A: 2d79040b21e8fff8         move.l  (dword_40B21E8).l,var_8(a6)
04085082: 2d79040b21ecfffc         move.l  (dword_40B21EC).l,var_4(a6)
0408508A: 2d7c0000012ffffc         move.l  #$12F,var_4(a6)
04085092: 2d6e000cfff4             move.l  arg_4(a6),var_C(a6)
04085098: 2d6e0008fff8             move.l  arg_0(a6),var_8(a6)
0408509E: 42a7                     clr.l   -(sp)
040850A0: 48780001                 pea     (1).w
040850A4: 486effe8                 pea     var_18(a6)
040850A8: 61fffffc3b10             bsr.l   _msg_send
040850AE: 4e5e                     unlk    a6
040850B0: 4e75                     rts
