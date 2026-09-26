04058032: 4e56ffd8                 link    a6,#-$28
04058036: 202e0010                 move.l  arg_8(a6),d0
0405803A: 2d79040ad0cafff0         move.l  (dword_40AD0CA).l,var_10(a6)
04058042: 2d79040ad0cefff4         move.l  (dword_40AD0CE).l,var_C(a6)
0405804A: 2d79040ad0d2fff8         move.l  (dword_40AD0D2).l,var_8(a6)
04058052: 2d6e000cfffc             move.l  arg_4(a6),var_4(a6)
04058058: e780                     asl.l   #3,d0
0405805A: 2d40fff8                 move.l  d0,var_8(a6)
0405805E: 422effdb                 clr.b   var_25(a6)
04058062: 7228                     moveq   #$28,d1 ; '('
04058064: 2d41ffdc                 move.l  d1,var_24(a6)
04058068: 42aeffe0                 clr.l   var_20(a6)
0405806C: 2d6e0008ffe8             move.l  arg_0(a6),var_18(a6)
04058072: 42aeffe4                 clr.l   var_1C(a6)
04058076: 2d7c000000caffec         move.l  #$CA,var_14(a6)
0405807E: 42a7                     clr.l   -(sp)
04058080: 42a7                     clr.l   -(sp)
04058082: 486effd8                 pea     var_28(a6)
04058086: 61ffffff0b32             bsr.l   _msg_send
0405808C: 4e5e                     unlk    a6
0405808E: 4e75                     rts
