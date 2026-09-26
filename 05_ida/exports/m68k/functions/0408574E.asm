0408574E: 4e56ffe8                 link    a6,#-$18
04085752: 2d79040b21d8ffe8         move.l  (dword_40B21D8).l,var_18(a6)
0408575A: 2d79040b21dcffec         move.l  (dword_40B21DC).l,var_14(a6)
04085762: 2d79040b21e0fff0         move.l  (dword_40B21E0).l,var_10(a6)
0408576A: 2d79040b21e4fff4         move.l  (dword_40B21E4).l,var_C(a6)
04085772: 2d79040b21e8fff8         move.l  (dword_40B21E8).l,var_8(a6)
0408577A: 2d79040b21ecfffc         move.l  (dword_40B21EC).l,var_4(a6)
04085782: 2d7c0000013dfffc         move.l  #$13D,var_4(a6)
0408578A: 2d6e0008fff4             move.l  arg_0(a6),var_C(a6)
04085790: 2d6e000cfff8             move.l  arg_4(a6),var_8(a6)
04085796: 42a7                     clr.l   -(sp)
04085798: 48780001                 pea     (1).w
0408579C: 486effe8                 pea     var_18(a6)
040857A0: 61fffffc3418             bsr.l   _msg_send
040857A6: 4e5e                     unlk    a6
040857A8: 4e75                     rts
