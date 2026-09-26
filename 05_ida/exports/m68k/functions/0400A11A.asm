0400A11A: 4e56ffc8                 link    a6,#-$38
0400A11E: 2f0a                     move.l  a2,-(sp)
0400A120: 7201                     moveq   #1,d1
0400A122: 2d41ffc8                 move.l  d1,var_38(a6)
0400A126: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A12C: 1028006a                 move.b  $6A(a0),d0
0400A130: 6d2a                     blt.s   loc_400A15C
0400A132: 0000ff80                 ori.b   #$80,d0
0400A136: 1140006a                 move.b  d0,$6A(a0)
0400A13A: 2f2e0018                 move.l  arg_10(a6),-(sp)
0400A13E: 2f2e0014                 move.l  arg_C(a6),-(sp)
0400A142: 2239040b57d0             move.l  (_active_u).l,d1
0400A148: 5081                     addq.l  #8,d1
0400A14A: 2f01                     move.l  d1,-(sp)
0400A14C: 4879040a60f0             pea     (aSSSPausing).l; "[%s: %s%s, pausing ...]\r\n"
0400A152: 61ff00001230             bsr.l   _uprintf
0400A158: 504f                     addq.w  #8,sp
0400A15A: 504f                     addq.w  #8,sp
0400A15C: 48780034                 pea     ($34).w
0400A160: 486effcc                 pea     var_34(a6)
0400A164: 45f9040b57d4             lea     (dword_40B57D4).l,a2
0400A16A: 7228                     moveq   #$28,d1 ; '('
0400A16C: d292                     add.l   (a2),d1
0400A16E: 2f01                     move.l  d1,-(sp)
0400A170: 61ff00088bba             bsr.l   _bcopy
0400A176: 7228                     moveq   #$28,d1 ; '('
0400A178: d292                     add.l   (a2),d1
0400A17A: 2f01                     move.l  d1,-(sp)
0400A17C: 61ffffff76d0             bsr.l   _setjmp
0400A182: 504f                     addq.w  #8,sp
0400A184: 504f                     addq.w  #8,sp
0400A186: 4a80                     tst.l   d0
0400A188: 6612                     bne.s   loc_400A19C
0400A18A: 2f2e0010                 move.l  arg_8(a6),-(sp)
0400A18E: 2f2e000c                 move.l  arg_4(a6),-(sp)
0400A192: 206e0008                 movea.l arg_0(a6),a0
0400A196: 4e90                     jsr     (a0)
0400A198: 504f                     addq.w  #8,sp
0400A19A: 6004                     bra.s   loc_400A1A0
0400A19C: 42aeffc8                 clr.l   var_38(a6)
0400A1A0: 48780034                 pea     ($34).w
0400A1A4: 7228                     moveq   #$28,d1 ; '('
0400A1A6: d2b9040b57d4             add.l   (dword_40B57D4).l,d1
0400A1AC: 2f01                     move.l  d1,-(sp)
0400A1AE: 486effcc                 pea     var_34(a6)
0400A1B2: 61ff00088b78             bsr.l   _bcopy
0400A1B8: 2079040b57d4             movea.l (dword_40B57D4).l,a0
0400A1BE: 504f                     addq.w  #8,sp
0400A1C0: 584f                     addq.w  #4,sp
0400A1C2: 4a28006a                 tst.b   $6A(a0)
0400A1C6: 6d06                     blt.s   loc_400A1CE
0400A1C8: 61ff00000010             bsr.l   _rpcont
0400A1CE: 202effc8                 move.l  var_38(a6),d0
0400A1D2: 246effc4                 movea.l var_3C(a6),a2
0400A1D6: 4e5e                     unlk    a6
0400A1D8: 4e75                     rts
