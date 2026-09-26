0405038C: 4e56fff4                 link    a6,#-$C
04050390: 48e72030                 movem.l d2/a2-a3,-(sp)
04050394: 4879040a8d8f             pea     (aWaitingForRemo).l; "Waiting for remote debugger connection."...
0405039A: 45f90404e2e4             lea     (_safe_prf).l,a2
040503A0: 4e92                     jsr     (a2)
040503A2: 4879040a8db8             pea     (aTypeCToContinu).l; "(Type 'c' to continue or 'r' to reboot)"...
040503A8: 4e92                     jsr     (a2)
040503AA: 4239040b39c6             clr.b   (byte_40B39C6).l
040503B0: 504f                     addq.w  #8,sp
040503B2: 45eefff8                 lea     var_8(a6),a2
040503B6: 47f9040b3fb2             lea     (dword_40B3FB2).l,a3
040503BC: 243c040b39c8             move.l  #$40B39C8,d2
040503C2: 6038                     bra.s   loc_40503FC
040503C4: 61ff000201b6             bsr.l   _kmtrygetc
040503CA: 7263                     moveq   #$63,d1 ; 'c'
040503CC: b280                     cmp.l   d0,d1
040503CE: 6708                     beq.s   loc_40503D8
040503D0: 7272                     moveq   #$72,d1 ; 'r'
040503D2: b280                     cmp.l   d0,d1
040503D4: 670c                     beq.s   loc_40503E2
040503D6: 601e                     bra.s   loc_40503F6
040503D8: 4879040a8de1             pea     (aContinuing_0).l; "Continuing...\n"
040503DE: 6000008c                 bra.w   loc_405046C
040503E2: 4879040a8df0             pea     (aRebooting_0).l; "Rebooting...\n"
040503E8: 61ffffffdefa             bsr.l   _safe_prf
040503EE: 61ff0004259e             bsr.l   _kdp_reboot
040503F4: 584f                     addq.w  #4,sp
040503F6: 61fffffffd8e             bsr.l   sub_4050186
040503FC: 4ab9040b3fba             tst.l   (dword_40B3FBA).l
04050402: 67c0                     beq.s   loc_40503C4
04050404: 48780008                 pea     (8).w
04050408: 2f0a                     move.l  a2,-(sp)
0405040A: 2213                     move.l  (a3),d1
0405040C: d282                     add.l   d2,d1
0405040E: 2f01                     move.l  d1,-(sp)
04050410: 61ff0004291a             bsr.l   _bcopy
04050416: 504f                     addq.w  #8,sp
04050418: 584f                     addq.w  #4,sp
0405041A: 4a12                     tst.b   (a2)
0405041C: 663a                     bne.s   loc_4050458
0405041E: 122a0001                 move.b  1(a2),d1
04050422: b239040b39c6             cmp.b   (byte_40B39C6).l,d1
04050428: 662e                     bne.s   loc_4050458
0405042A: 486efff6                 pea     var_A(a6)
0405042E: 4879040b3fb6             pea     (unk_40B3FB6).l
04050434: 2213                     move.l  (a3),d1
04050436: d282                     add.l   d2,d1
04050438: 2f01                     move.l  d1,-(sp)
0405043A: 61fffffff436             bsr.l   _kdp_packet
04050440: 504f                     addq.w  #8,sp
04050442: 584f                     addq.w  #4,sp
04050444: 4a80                     tst.l   d0
04050446: 6710                     beq.s   loc_4050458
04050448: 4280                     clr.l   d0
0405044A: 302efff6                 move.w  var_A(a6),d0
0405044E: 2f00                     move.l  d0,-(sp)
04050450: 61fffffff948             bsr.l   sub_404FD9A
04050456: 584f                     addq.w  #4,sp
04050458: 42b9040b3fba             clr.l   (dword_40B3FBA).l
0405045E: 4ab9040c259e             tst.l   (dword_40C259E).l
04050464: 6796                     beq.s   loc_40503FC
04050466: 4879040a8dfe             pea     (aConnectedToRem).l; "Connected to remote debugger.\n"
0405046C: 61ffffffde76             bsr.l   _safe_prf
04050472: 4cee0c04ffe8             movem.l var_18(a6),d2/a2-a3
04050478: 4e5e                     unlk    a6
0405047A: 4e75                     rts
