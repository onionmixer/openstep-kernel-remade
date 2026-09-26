040852DC: 4e56ffdc                 link    a6,#-$24
040852E0: 2d79040b21d8ffdc         move.l  (dword_40B21D8).l,var_24(a6)
040852E8: 2d79040b21dcffe0         move.l  (dword_40B21DC).l,var_20(a6)
040852F0: 2d79040b21e0ffe4         move.l  (dword_40B21E0).l,var_1C(a6)
040852F8: 2d79040b21e4ffe8         move.l  (dword_40B21E4).l,var_18(a6)
04085300: 2d79040b21e8ffec         move.l  (dword_40B21E8).l,var_14(a6)
04085308: 2d79040b21ecfff0         move.l  (dword_40B21EC).l,var_10(a6)
04085310: 7224                     moveq   #$24,d1 ; '$'
04085312: 2d41ffe0                 move.l  d1,var_20(a6)
04085316: 2d7c0000012efff0         move.l  #$12E,var_10(a6)
0408531E: 2d6e0008ffec             move.l  arg_0(a6),var_14(a6)
04085324: 2d79040b21fcfff4         move.l  (dword_40B21FC).l,var_C(a6)
0408532C: 2d6e000cfff8             move.l  arg_4(a6),var_8(a6)
04085332: 2d6e0010fffc             move.l  arg_8(a6),var_4(a6)
04085338: 42a7                     clr.l   -(sp)
0408533A: 48780021                 pea     ($21).w
0408533E: 486effdc                 pea     var_24(a6)
04085342: 61fffffc3876             bsr.l   _msg_send
04085348: 4e5e                     unlk    a6
0408534A: 4e75                     rts
