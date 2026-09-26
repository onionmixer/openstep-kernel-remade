04085856: 4e56ffd8                 link    a6,#-$28
0408585A: 2f0a                     move.l  a2,-(sp)
0408585C: 2f02                     move.l  d2,-(sp)
0408585E: 206e0008                 movea.l arg_0(a6),a0
04085862: 2d79040b21d8ffd8         move.l  (dword_40B21D8).l,var_28(a6)
0408586A: 2d79040b21dcffdc         move.l  (dword_40B21DC).l,var_24(a6)
04085872: 2d79040b21e0ffe0         move.l  (dword_40B21E0).l,var_20(a6)
0408587A: 2d79040b21e4ffe4         move.l  (dword_40B21E4).l,var_1C(a6)
04085882: 2d79040b21e8ffe8         move.l  (dword_40B21E8).l,var_18(a6)
0408588A: 2d79040b21ecffec         move.l  (dword_40B21EC).l,var_14(a6)
04085892: 2d7c0000013fffec         move.l  #$13F,var_14(a6)
0408589A: 42aeffe4                 clr.l   var_1C(a6)
0408589E: 7228                     moveq   #$28,d1 ; '('
040858A0: 2d41ffdc                 move.l  d1,var_24(a6)
040858A4: 2d79040b21fcfff0         move.l  (dword_40B21FC).l,var_10(a6)
040858AC: 302efff2                 move.w  var_10+2(a6),d0
040858B0: 0240003f                 andi.w  #$3F,d0 ; '?'
040858B4: 00400030                 ori.w   #$30,d0 ; '0'
040858B8: 3d40fff2                 move.w  d0,var_10+2(a6)
040858BC: 2d680004fff4             move.l  4(a0),var_C(a6)
040858C2: 2d680008fff8             move.l  8(a0),var_8(a6)
040858C8: 2d680014fffc             move.l  $14(a0),var_4(a6)
040858CE: 45eeffd8                 lea     var_28(a6),a2
040858D2: 486effe8                 pea     var_18(a6)
040858D6: 42a7                     clr.l   -(sp)
040858D8: 48780006                 pea     (6).w
040858DC: 2f28000c                 move.l  $C(a0),-(sp)
040858E0: 2f39040c6eb8             move.l  (dword_40C6EB8).l,-(sp)
040858E6: 61fffffc4728             bsr.l   _object_copyin
040858EC: defc0014                 adda.w  #$14,sp
040858F0: 4a80                     tst.l   d0
040858F2: 671c                     beq.s   loc_4085910
040858F4: 42a7                     clr.l   -(sp)
040858F6: 48780001                 pea     (1).w
040858FA: 2f0a                     move.l  a2,-(sp)
040858FC: 61fffffc321a             bsr.l   _msg_send_from_kernel
04085902: 2400                     move.l  d0,d2
04085904: 2f2effe8                 move.l  var_18(a6),-(sp)
04085908: 61fffffc47a6             bsr.l   _port_release
0408590E: 6002                     bra.s   loc_4085912
04085910: 7405                     moveq   #5,d2
04085912: 2002                     move.l  d2,d0
04085914: 242effd0                 move.l  var_30(a6),d2
04085918: 246effd4                 movea.l var_2C(a6),a2
0408591C: 4e5e                     unlk    a6
0408591E: 4e75                     rts
