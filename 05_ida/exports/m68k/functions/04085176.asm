04085176: 4e56ffdc                 link    a6,#-$24
0408517A: 2d79040b21d8ffdc         move.l  (dword_40B21D8).l,var_24(a6)
04085182: 2d79040b21dcffe0         move.l  (dword_40B21DC).l,var_20(a6)
0408518A: 2d79040b21e0ffe4         move.l  (dword_40B21E0).l,var_1C(a6)
04085192: 2d79040b21e4ffe8         move.l  (dword_40B21E4).l,var_18(a6)
0408519A: 2d79040b21e8ffec         move.l  (dword_40B21E8).l,var_14(a6)
040851A2: 2d79040b21ecfff0         move.l  (dword_40B21EC).l,var_10(a6)
040851AA: 2d7c0000013afff0         move.l  #$13A,var_10(a6)
040851B2: 7224                     moveq   #$24,d1 ; '$'
040851B4: 2d41ffe0                 move.l  d1,var_20(a6)
040851B8: 2d6e0008ffe8             move.l  arg_0(a6),var_18(a6)
040851BE: 2d6e000cffec             move.l  arg_4(a6),var_14(a6)
040851C4: 2d79040b21fcfff4         move.l  (dword_40B21FC).l,var_C(a6)
040851CC: 302efff6                 move.w  var_C+2(a6),d0
040851D0: 0240002f                 andi.w  #$2F,d0 ; '/'
040851D4: 00400020                 ori.w   #$20,d0 ; ' '
040851D8: 3d40fff6                 move.w  d0,var_C+2(a6)
040851DC: 2d6e0010fff8             move.l  arg_8(a6),var_8(a6)
040851E2: 2d6e0014fffc             move.l  arg_C(a6),var_4(a6)
040851E8: 42a7                     clr.l   -(sp)
040851EA: 48780001                 pea     (1).w
040851EE: 486effdc                 pea     var_24(a6)
040851F2: 61fffffc39c6             bsr.l   _msg_send
040851F8: 4e5e                     unlk    a6
040851FA: 4e75                     rts
