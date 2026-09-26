0409554A: 4e56fff4                 link    a6,#-$C
0409554E: 48e72030                 movem.l d2/a2-a3,-(sp)
04095552: 246e0008                 movea.l arg_0(a6),a2
04095556: 42a7                     clr.l   -(sp)
04095558: 61fffffcf238             bsr.l   _adb_watchdog
0409555E: 61fffff6c01e             bsr.l   _get_vbr
04095564: 2d40fff8                 move.l  d0,var_8(a6)
04095568: 584f                     addq.w  #4,sp
0409556A: 2039040c9778             move.l  (_client_running).l,d0
04095570: 4a80                     tst.l   d0
04095572: 670002fa                 beq.w   loc_409586E
04095576: 302a0046                 move.w  $46(a2),d0
0409557A: 3200                     move.w  d0,d1
0409557C: 02412000                 andi.w  #$2000,d1
04095580: 4a41                     tst.w   d1
04095582: 6664                     bne.s   loc_40955E8
04095584: ebea110c004c             bfexts  $4C(a2){4:12},d1
0409558A: 2001                     move.l  d1,d0
0409558C: e480                     asr.l   #2,d0
0409558E: 7409                     moveq   #9,d2
04095590: b480                     cmp.l   d0,d2
04095592: 671c                     beq.s   loc_40955B0
04095594: 742f                     moveq   #$2F,d2 ; '/'
04095596: b480                     cmp.l   d0,d2
04095598: 6702                     beq.s   loc_409559C
0409559A: 6028                     bra.s   loc_40955C4
0409559C: 48780001                 pea     (1).w
040955A0: 61fffffcf1f0             bsr.l   _adb_watchdog
040955A6: 2039040b5620             move.l  (dword_40B5620).l,d0
040955AC: 600002d8                 bra.w   loc_4095886
040955B0: 48780001                 pea     (1).w
040955B4: 61fffffcf1dc             bsr.l   _adb_watchdog
040955BA: 2039040b561c             move.l  (dword_40B561C).l,d0
040955C0: 600002c4                 bra.w   loc_4095886
040955C4: ebea010c004c             bfexts  $4C(a2){4:12},d0
040955CA: 2f00                     move.l  d0,-(sp)
040955CC: 4879040ac81a             pea     (aDbgTrapReturni).l; "dbg_trap returning, vecoff = %d\n"
040955D2: 61ffffffe876             bsr.l   _nmi_prf
040955D8: 4879040ac83b             pea     (aDbgTrapBadUser).l; "dbg_trap: bad user vecoff"
040955DE: 61ffffffff4a             bsr.l   _dbg_panic
040955E4: 504f                     addq.w  #8,sp
040955E6: 584f                     addq.w  #4,sp
040955E8: 42b9040c9778             clr.l   (_client_running).l
040955EE: 487800a2                 pea     ($A2).w
040955F2: 4879040c96d4             pea     (_client_pcb).l
040955F8: 2f0a                     move.l  a2,-(sp)
040955FA: 61ffffffd730             bsr.l   _bcopy
04095600: 504f                     addq.w  #8,sp
04095602: 584f                     addq.w  #4,sp
04095604: 42b9040b5634             clr.l   (dword_40B5634).l
0409560A: ebea010c004c             bfexts  $4C(a2){4:12},d0
04095610: 23c0040b5638             move.l  d0,(dword_40B5638).l
04095616: ebea0004004c             bfexts  $4C(a2){0:4},d0
0409561C: 740b                     moveq   #$B,d2
0409561E: b480                     cmp.l   d0,d2
04095620: 650000ec                 bcs.w   loc_409570E
04095624: 2200                     move.l  d0,d1
04095626: e581                     asl.l   #2,d1
04095628: 207c04095634             movea.l #$4095634,a0
0409562E: 22701800                 movea.l (a0,d1.l),a1
04095632: 4ed1                     jmp     (a1)
04095634: 04095664                 subi.b  #$64,a1 ; 'd'
04095638: 04095664                 subi.b  #$64,a1 ; 'd'
0409563C: 04095678                 subi.b  #$78,a1 ; 'x'
04095640: 0409568c                 subi.b  #$8C,a1
04095644: 0409570e                 subi.b  #$E,a1
04095648: 0409570e                 subi.b  #$E,a1
0409564C: 0409570e                 subi.b  #$E,a1
04095650: 0409569e                 subi.b  #$9E,a1
04095654: 0409570e                 subi.b  #$E,a1
04095658: 040956ba                 subi.b  #$BA,a1
0409565C: 040956d6                 subi.b  #$D6,a1
04095660: 040956f2                 subi.b  #$F2,a1
04095664: 2079040c9714             movea.l (dword_40C9714).l,a0
0409566A: 47e80008                 lea     8(a0),a3
0409566E: 23cb040c9714             move.l  a3,(dword_40C9714).l
04095674: 600000a6                 bra.w   loc_409571C
04095678: 2079040c9714             movea.l (dword_40C9714).l,a0
0409567E: 47e8000c                 lea     $C(a0),a3
04095682: 23cb040c9714             move.l  a3,(dword_40C9714).l
04095688: 60000092                 bra.w   loc_409571C
0409568C: 2079040c9714             movea.l (dword_40C9714).l,a0
04095692: 47e8000c                 lea     $C(a0),a3
04095696: 23cb040c9714             move.l  a3,(dword_40C9714).l
0409569C: 607e                     bra.s   loc_409571C
0409569E: 2079040c9714             movea.l (dword_40C9714).l,a0
040956A4: 47e8003c                 lea     $3C(a0),a3
040956A8: 23cb040c9714             move.l  a3,(dword_40C9714).l
040956AE: 23f9040c972a040b5634     move.l  (dword_40C972A).l,(dword_40B5634).l
040956B8: 6062                     bra.s   loc_409571C
040956BA: 2079040c9714             movea.l (dword_40C9714).l,a0
040956C0: 47e80014                 lea     $14(a0),a3
040956C4: 23cb040c9714             move.l  a3,(dword_40C9714).l
040956CA: 23f9040c9722040b5634     move.l  (dword_40C9722).l,(dword_40B5634).l
040956D4: 6046                     bra.s   loc_409571C
040956D6: 2079040c9714             movea.l (dword_40C9714).l,a0
040956DC: 47e80020                 lea     $20(a0),a3
040956E0: 23cb040c9714             move.l  a3,(dword_40C9714).l
040956E6: 23f9040c972a040b5634     move.l  (dword_40C972A).l,(dword_40B5634).l
040956F0: 602a                     bra.s   loc_409571C
040956F2: 2079040c9714             movea.l (dword_40C9714).l,a0
040956F8: 47e8005c                 lea     $5C(a0),a3
040956FC: 23cb040c9714             move.l  a3,(dword_40C9714).l
04095702: 23f9040c972a040b5634     move.l  (dword_40C972A).l,(dword_40B5634).l
0409570C: 600e                     bra.s   loc_409571C
0409570E: 4879040ac855             pea     (aStackFrameScre).l; "stack frame screw-up\n"
04095714: 61fffffffe14             bsr.l   _dbg_panic
0409571A: 584f                     addq.w  #4,sp
0409571C: ebf9010c040c9720         bfexts  (word_40C9720).l{4:12},d0
04095724: 2200                     move.l  d0,d1
04095726: e481                     asr.l   #2,d1
04095728: 2041                     movea.l d1,a0
0409572A: 5548                     subq.w  #2,a0
0409572C: 742d                     moveq   #$2D,d2 ; '-'
0409572E: b488                     cmp.l   a0,d2
04095730: 6500012e                 bcs.w   loc_4095860
04095734: 2008                     move.l  a0,d0
04095736: 2200                     move.l  d0,d1
04095738: e581                     asl.l   #2,d1
0409573A: 207c04095746             movea.l #$4095746,a0
04095740: 22701800                 movea.l (a0,d1.l),a1
04095744: 4ed1                     jmp     (a1)
04095746: 040957fe                 subi.b  #$FE,a1
0409574A: 040957fe                 subi.b  #$FE,a1
0409574E: 04095808                 subi.b  #8,a1
04095752: 04095860                 subi.b  #$60,a1 ; '`'
04095756: 04095860                 subi.b  #$60,a1 ; '`'
0409575A: 04095860                 subi.b  #$60,a1 ; '`'
0409575E: 04095860                 subi.b  #$60,a1 ; '`'
04095762: 04095812                 subi.b  #$12,a1
04095766: 04095860                 subi.b  #$60,a1 ; '`'
0409576A: 04095860                 subi.b  #$60,a1 ; '`'
0409576E: 04095860                 subi.b  #$60,a1 ; '`'
04095772: 04095860                 subi.b  #$60,a1 ; '`'
04095776: 04095860                 subi.b  #$60,a1 ; '`'
0409577A: 04095860                 subi.b  #$60,a1 ; '`'
0409577E: 04095860                 subi.b  #$60,a1 ; '`'
04095782: 04095860                 subi.b  #$60,a1 ; '`'
04095786: 04095860                 subi.b  #$60,a1 ; '`'
0409578A: 04095860                 subi.b  #$60,a1 ; '`'
0409578E: 04095860                 subi.b  #$60,a1 ; '`'
04095792: 04095860                 subi.b  #$60,a1 ; '`'
04095796: 04095860                 subi.b  #$60,a1 ; '`'
0409579A: 04095860                 subi.b  #$60,a1 ; '`'
0409579E: 04095860                 subi.b  #$60,a1 ; '`'
040957A2: 04095860                 subi.b  #$60,a1 ; '`'
040957A6: 04095860                 subi.b  #$60,a1 ; '`'
040957AA: 04095860                 subi.b  #$60,a1 ; '`'
040957AE: 04095860                 subi.b  #$60,a1 ; '`'
040957B2: 04095860                 subi.b  #$60,a1 ; '`'
040957B6: 04095860                 subi.b  #$60,a1 ; '`'
040957BA: 04095860                 subi.b  #$60,a1 ; '`'
040957BE: 04095860                 subi.b  #$60,a1 ; '`'
040957C2: 04095860                 subi.b  #$60,a1 ; '`'
040957C6: 04095860                 subi.b  #$60,a1 ; '`'
040957CA: 04095860                 subi.b  #$60,a1 ; '`'
040957CE: 04095860                 subi.b  #$60,a1 ; '`'
040957D2: 04095860                 subi.b  #$60,a1 ; '`'
040957D6: 04095860                 subi.b  #$60,a1 ; '`'
040957DA: 04095860                 subi.b  #$60,a1 ; '`'
040957DE: 04095860                 subi.b  #$60,a1 ; '`'
040957E2: 04095860                 subi.b  #$60,a1 ; '`'
040957E6: 04095860                 subi.b  #$60,a1 ; '`'
040957EA: 04095860                 subi.b  #$60,a1 ; '`'
040957EE: 04095860                 subi.b  #$60,a1 ; '`'
040957F2: 04095860                 subi.b  #$60,a1 ; '`'
040957F6: 04095860                 subi.b  #$60,a1 ; '`'
040957FA: 04095856                 subi.b  #$56,a1 ; 'V'
040957FE: 7401                     moveq   #1,d2
04095800: 23c2040b5630             move.l  d2,(dword_40B5630).l
04095806: 6064                     bra.s   loc_409586C
04095808: 7402                     moveq   #2,d2
0409580A: 23c2040b5630             move.l  d2,(dword_40B5630).l
04095810: 605a                     bra.s   loc_409586C
04095812: 2039040b5610             move.l  (dword_40B5610).l,d0
04095818: 4a80                     tst.l   d0
0409581A: 673a                     beq.s   loc_4095856
0409581C: 2039040b5624             move.l  (dword_40B5624).l,d0
04095822: 4a80                     tst.l   d0
04095824: 6730                     beq.s   loc_4095856
04095826: 61fffff6bd56             bsr.l   _get_vbr
0409582C: 2d40fff4                 move.l  d0,var_C(a6)
04095830: 206efff4                 movea.l var_C(a6),a0
04095834: 43e80024                 lea     $24(a0),a1
04095838: 22b9040b561c             move.l  (dword_40B561C).l,(a1)
0409583E: 3039040c971a             move.w  (word_40C971A).l,d0
04095844: 3400                     move.w  d0,d2
04095846: 02427fff                 andi.w  #$7FFF,d2
0409584A: 33c2040c971a             move.w  d2,(word_40C971A).l
04095850: 42b9040b5624             clr.l   (dword_40B5624).l
04095856: 7406                     moveq   #6,d2
04095858: 23c2040b5630             move.l  d2,(dword_40B5630).l
0409585E: 600c                     bra.s   loc_409586C
04095860: 7405                     moveq   #5,d2
04095862: 23c2040b5630             move.l  d2,(dword_40B5630).l
04095868: 60000002                 bra.w   *+4
0409586C: 6008                     bra.s   loc_4095876
0409586E: 7405                     moveq   #5,d2
04095870: 23c2040b5630             move.l  d2,(dword_40B5630).l
04095876: 48780001                 pea     (1).w
0409587A: 61fffffcef16             bsr.l   _adb_watchdog
04095880: 61ff0000000e             bsr.l   _dbg_dispatch
04095886: 4cee0c04ffe8             movem.l var_18(a6),d2/a2-a3
0409588C: 4e5e                     unlk    a6
0409588E: 4e75                     rts
