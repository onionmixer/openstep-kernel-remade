04085946: 4e56fffc                 link    a6,#-4
0408594A: 2f0a                     move.l  a2,-(sp)
0408594C: 2f02                     move.l  d2,-(sp)
0408594E: 242e0008                 move.l  arg_0(a6),d2
04085952: 486efffc                 pea     var_4(a6)
04085956: 45f9040c6ec0             lea     (dword_40C6EC0).l,a2
0408595C: 2f12                     move.l  (a2),-(sp)
0408595E: 61fffffc1514             bsr.l   _port_allocate
04085964: 504f                     addq.w  #8,sp
04085966: 4a80                     tst.l   d0
04085968: 670e                     beq.s   loc_4085978
0408596A: 4879040abc98             pea     (aSoundCanTAlloc).l; "sound: can't allocate port"
04085970: 61fffff862f4             bsr.l   _panic
04085976: 584f                     addq.w  #4,sp
04085978: 202efffc                 move.l  var_4(a6),d0
0408597C: b480                     cmp.l   d0,d2
0408597E: 6722                     beq.s   loc_40859A2
04085980: 2f02                     move.l  d2,-(sp)
04085982: 2f00                     move.l  d0,-(sp)
04085984: 2f12                     move.l  (a2),-(sp)
04085986: 61fffffc14c6             bsr.l   _port_rename
0408598C: 504f                     addq.w  #8,sp
0408598E: 584f                     addq.w  #4,sp
04085990: 4a80                     tst.l   d0
04085992: 670e                     beq.s   loc_40859A2
04085994: 4879040abcb3             pea     (aSoundCanTRenam).l; "sound: can't rename port"
0408599A: 61fffff862ca             bsr.l   _panic
040859A0: 584f                     addq.w  #4,sp
040859A2: 2f02                     move.l  d2,-(sp)
040859A4: 2f39040c6ea8             move.l  (dword_40C6EA8).l,-(sp)
040859AA: 2f39040c6ec0             move.l  (dword_40C6EC0).l,-(sp)
040859B0: 61fffffc17b0             bsr.l   _port_set_add
040859B6: 504f                     addq.w  #8,sp
040859B8: 584f                     addq.w  #4,sp
040859BA: 4a80                     tst.l   d0
040859BC: 670c                     beq.s   loc_40859CA
040859BE: 4879040abccc             pea     (aSoundCanTAddPo).l; "sound: can't add port to port_set"
040859C4: 61fffff862a0             bsr.l   _panic
040859CA: 242efff4                 move.l  var_C(a6),d2
040859CE: 246efff8                 movea.l var_8(a6),a2
040859D2: 4e5e                     unlk    a6
040859D4: 4e75                     rts
