040854BC: 4e56ffd0                 link    a6,#-$30
040854C0: 2d79040b21d8ffd0         move.l  (dword_40B21D8).l,var_30(a6)
040854C8: 2d79040b21dcffd4         move.l  (dword_40B21DC).l,var_2C(a6)
040854D0: 2d79040b21e0ffd8         move.l  (dword_40B21E0).l,var_28(a6)
040854D8: 2d79040b21e4ffdc         move.l  (dword_40B21E4).l,var_24(a6)
040854E0: 2d79040b21e8ffe0         move.l  (dword_40B21E8).l,var_20(a6)
040854E8: 2d79040b21ecffe4         move.l  (dword_40B21EC).l,var_1C(a6)
040854F0: 2d7c00000140ffe4         move.l  #$140,var_1C(a6)
040854F8: 7230                     moveq   #$30,d1 ; '0'
040854FA: 2d41ffd4                 move.l  d1,var_2C(a6)
040854FE: 2d6e0008ffe0             move.l  arg_0(a6),var_20(a6)
04085504: 2d79040b21fcffe8         move.l  (dword_40B21FC).l,var_18(a6)
0408550C: 302effea                 move.w  var_18+2(a6),d0
04085510: 0240005f                 andi.w  #$5F,d0 ; '_'
04085514: 00400050                 ori.w   #$50,d0 ; 'P'
04085518: 3d40ffea                 move.w  d0,var_18+2(a6)
0408551C: 2d6e000cffec             move.l  arg_4(a6),var_14(a6)
04085522: 2d6e0010fff0             move.l  arg_8(a6),var_10(a6)
04085528: 2d6e0014fff4             move.l  arg_C(a6),var_C(a6)
0408552E: 2d6e0018fff8             move.l  arg_10(a6),var_8(a6)
04085534: 2d6e001cfffc             move.l  arg_14(a6),var_4(a6)
0408553A: 42a7                     clr.l   -(sp)
0408553C: 48780001                 pea     (1).w
04085540: 486effd0                 pea     var_30(a6)
04085544: 61fffffc3674             bsr.l   _msg_send
0408554A: 4e5e                     unlk    a6
0408554C: 4e75                     rts
