04001A8A: 206f0004                 movea.l arg_0(sp),a0
04001A8E: 08a800060054             bclr    #6,$54(a0)
04001A94: f328005c                 fsave   $5C(a0)
04001A98: 4a28005c                 tst.b   $5C(a0)
04001A9C: 671a                     beq.s   loc_4001AB8
04001A9E: 08e800060054             bset    #6,$54(a0)
04001AA4: f228bc000194             fmovem.l fpcr/fpsr/fpiar,$194(a0)
04001AAA: f228f0ff0134             fmovem.x fp0-fp7,$134(a0)
04001AB0: 4e71                     nop
04001AB2: f379040018d4             frestore (dword_40018D4).l
04001AB8: 206f0008                 movea.l arg_4(sp),a0
04001ABC: 4a28005c                 tst.b   $5C(a0)
04001AC0: 670c                     beq.s   loc_4001ACE
04001AC2: f2289c000194             fmovem.l $194(a0),fpcr/fpsr/fpiar
04001AC8: f228d0ff0134             fmovem.x $134(a0),fp0-fp7
04001ACE: 4e71                     nop
04001AD0: f368005c                 frestore $5C(a0)
04001AD4: 4a28005c                 tst.b   $5C(a0)
04001AD8: 6608                     bne.s   loc_4001AE2
04001ADA: f23c900000000080         fmovem.l #$80,fpcr
04001AE2: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04001AEA: 670e                     beq.s   loc_4001AFA
04001AEC: 20280058                 move.l  $58(a0),d0
04001AF0: 4e7b0005                 movec   d0,itt1
04001AF4: 4e7b0007                 movec   d0,dtt1
04001AF8: 6006                     bra.s   loc_4001B00
04001AFA: f0280c000058             pmove   $58(a0),tt1
04001B00: 0c390000040b56cc         cmpi.b  #0,(_cpu_type).l
04001B08: 660a                     bne.s   locret_4001B14
04001B0A: 2039040ad964             move.l  (_cache).l,d0
04001B10: 4e7b0002                 movec   d0,cacr
04001B14: 4e75                     rts
