040850B2: 4e56ffe8                 link    a6,#-$18
040850B6: 2d79040b21d8ffe8         move.l  (dword_40B21D8).l,var_18(a6)
040850BE: 2d79040b21dcffec         move.l  (dword_40B21DC).l,var_14(a6)
040850C6: 2d79040b21e0fff0         move.l  (dword_40B21E0).l,var_10(a6)
040850CE: 2d79040b21e4fff4         move.l  (dword_40B21E4).l,var_C(a6)
040850D6: 2d79040b21e8fff8         move.l  (dword_40B21E8).l,var_8(a6)
040850DE: 2d79040b21ecfffc         move.l  (dword_40B21EC).l,var_4(a6)
040850E6: 2d7c00000130fffc         move.l  #$130,var_4(a6)
040850EE: 2d6e000cfff4             move.l  arg_4(a6),var_C(a6)
040850F4: 2d6e0008fff8             move.l  arg_0(a6),var_8(a6)
040850FA: 42a7                     clr.l   -(sp)
040850FC: 48780001                 pea     (1).w
04085100: 486effe8                 pea     var_18(a6)
04085104: 61fffffc3ab4             bsr.l   _msg_send
0408510A: 4e5e                     unlk    a6
0408510C: 4e75                     rts
