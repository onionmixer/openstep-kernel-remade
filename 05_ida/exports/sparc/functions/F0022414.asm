F0022414: 9de3bf90                 save    %sp, -0x70, %sp
F0022418: a4102000                 mov     0, %l2
F002241C: 80a6600b                 cmp     %i1, 0xB
F0022420: 12800004                 bne     loc_F0022430
F0022424: e0062008                 ld      [%i0+8], %l0
F0022428: 10800171                 ba      locret_F00229EC! jumptable F002248C case 13
F002242C: b010202d                 mov     0x2D, %i0 ! '-'
F0022430: 80a66009                 cmp     %i1, 9
F0022434: 0280000a                 be      loc_F002245C
F0022438: 80a72000                 cmp     %i4, 0
F002243C: 02800009                 be      loc_F0022460
F0022440: 80a42000                 cmp     %l0, 0
F0022444: d0572008                 ldsh    [%i4+8], %o0
F0022448: 80a22000                 cmp     %o0, 0
F002244C: 02800005                 be      loc_F0022460
F0022450: 80a42000                 cmp     %l0, 0
F0022454: 10800160                 ba      loc_F00229D4! jumptable F002248C case 14
F0022458: a410202d                 mov     0x2D, %l2 ! '-'
F002245C: 80a42000                 cmp     %l0, 0
F0022460: 12800006                 bne     loc_F0022478
F0022464: 80a66013                 cmp     %i1, 0x13
F0022468: 80a66000                 cmp     %i1, 0
F002246C: 3280015a                 bne,a   loc_F00229D4! jumptable F002248C cases 15,19
F0022470: a4102016                 mov     0x16, %l2
F0022474: 80a66013                 cmp     %i1, 0x13! switch 20 cases
F0022478: 18800153                 bgu     def_F002248C! jumptable F002248C default case, cases 11,18
F002247C: 113c0089                 sethi   %hi(jpt_F002248C), %o0
F0022480: 90122094                 bset    %lo(jpt_F002248C), %o0
F0022484: 932e6002                 sll     %i1, 2, %o1
F0022488: d0024008                 ld      [%o1+%o0], %o0
F002248C: 81c20000                 jmp     %o0! switch jump
F0022490: 01000000                 nop
F00224E4: 80a42000                 cmp     %l0, 0! jumptable F002248C case 0
F00224E8: 1280013b                 bne     loc_F00229D4! jumptable F002248C cases 15,19
F00224EC: a4102038                 mov     0x38, %l2 ! '8'
F00224F0: 40000141                 call    _unp_attach
F00224F4: 90100018                 mov     %i0, %o0
F00224F8: 10800137                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F00224FC: a4100008                 mov     %o0, %l2
F0022500: 40000163                 call    _unp_detach! jumptable F002248C case 1
F0022504: 90100010                 mov     %l0, %o0
F0022508: 10800134                 ba      loc_F00229D8
F002250C: 80a6a000                 cmp     %i2, 0
F0022510: 90100010                 mov     %l0, %o0! jumptable F002248C case 2
F0022514: 40000187                 call    _unp_bind
F0022518: 9210001b                 mov     %i3, %o1
F002251C: 1080012e                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F0022520: a4100008                 mov     %o0, %l2
F0022524: d0042004                 ld      [%l0+4], %o0! jumptable F002248C case 3
F0022528: 80a22000                 cmp     %o0, 0
F002252C: 1280012b                 bne     loc_F00229D8
F0022530: 80a6a000                 cmp     %i2, 0
F0022534: 10800129                 ba      loc_F00229D8
F0022538: a4102016                 mov     0x16, %l2
F002253C: 90100018                 mov     %i0, %o0! jumptable F002248C case 4
F0022540: 400001aa                 call    _unp_connect
F0022544: 9210001b                 mov     %i3, %o1
F0022548: 10800123                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F002254C: a4100008                 mov     %o0, %l2
F0022550: 90100018                 mov     %i0, %o0! jumptable F002248C case 17
F0022554: 400001de                 call    _unp_connect2
F0022558: 9210001b                 mov     %i3, %o1
F002255C: 1080011e                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F0022560: a4100008                 mov     %o0, %l2
F0022564: d004200c                 ld      [%l0+0xC], %o0! jumptable F002248C case 5
F0022568: 80a22000                 cmp     %o0, 0
F002256C: 22800007                 be,a    loc_F0022588
F0022570: 90102010                 mov     0x10, %o0
F0022574: d0022018                 ld      [%o0+0x18], %o0
F0022578: 80a22000                 cmp     %o0, 0
F002257C: 32800106                 bne,a   loc_F0022994
F0022580: d4122008                 lduh    [%o0+8], %o2
F0022584: 90102010                 mov     0x10, %o0
F0022588: d036e008                 sth     %o0, [%i3+8]
F002258C: d406e004                 ld      [%i3+4], %o2
F0022590: 133c042f                 sethi   %hi(_sun_noname), %o1
F0022594: d01260f0                 lduh    [%o1+%lo(_sun_noname)], %o0
F0022598: d036c00a                 sth     %o0, [%i3+%o2]
F002259C: 921260f0                 bset    %lo(_sun_noname), %o1
F00225A0: d0126002                 lduh    [%o1+2], %o0
F00225A4: 9406c00a                 add     %i3, %o2, %o2
F00225A8: d032a002                 sth     %o0, [%o2+2]
F00225AC: d0126004                 lduh    [%o1+4], %o0
F00225B0: d032a004                 sth     %o0, [%o2+4]
F00225B4: d0126006                 lduh    [%o1+6], %o0
F00225B8: d032a006                 sth     %o0, [%o2+6]
F00225BC: d0126008                 lduh    [%o1+8], %o0
F00225C0: d032a008                 sth     %o0, [%o2+8]
F00225C4: d012600a                 lduh    [%o1+0xA], %o0
F00225C8: d032a00a                 sth     %o0, [%o2+0xA]
F00225CC: d012600c                 lduh    [%o1+0xC], %o0
F00225D0: d032a00c                 sth     %o0, [%o2+0xC]
F00225D4: d012600e                 lduh    [%o1+0xE], %o0
F00225D8: 108000ff                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F00225DC: d032a00e                 sth     %o0, [%o2+0xE]
F00225E0: 7ffff743                 call    _socantsendmore! jumptable F002248C case 7
F00225E4: 90100018                 mov     %i0, %o0
F00225E8: 4000020a                 call    _unp_usrclosed
F00225EC: 90100010                 mov     %l0, %o0
F00225F0: 108000fa                 ba      loc_F00229D8
F00225F4: 80a6a000                 cmp     %i2, 0
F00225F8: d0560000                 ldsh    [%i0], %o0! jumptable F002248C case 8
F00225FC: 80a22001                 cmp     %o0, 1
F0022600: 02800007                 be      loc_F002261C
F0022604: 80a22002                 cmp     %o0, 2
F0022608: 3280001f                 bne,a   loc_F0022684
F002260C: 113c042f                 sethi   -0xFEF4400, %o0
F0022610: 113c042f                 sethi   %hi(aUipc1), %o0! "uipc 1"
F0022614: 7fffcad7                 call    _panic
F0022618: 90122100                 bset    %lo(aUipc1), %o0! "uipc 1"
F002261C: d004200c                 ld      [%l0+0xC], %o0
F0022620: 80a22000                 cmp     %o0, 0
F0022624: 028000ed                 be      loc_F00229D8
F0022628: 80a6a000                 cmp     %i2, 0
F002262C: f2020000                 ld      [%o0], %i1
F0022630: d2042020                 ld      [%l0+0x20], %o1
F0022634: d4162028                 lduh    [%i0+0x28], %o2
F0022638: d0166042                 lduh    [%i1+0x42], %o0
F002263C: 9222400a                 sub     %o1, %o2, %o1
F0022640: 90020009                 add     %o0, %o1, %o0
F0022644: d0366042                 sth     %o0, [%i1+0x42]
F0022648: d0162028                 lduh    [%i0+0x28], %o0
F002264C: d404201c                 ld      [%l0+0x1C], %o2
F0022650: d0242020                 st      %o0, [%l0+0x20]
F0022654: d6162024                 lduh    [%i0+0x24], %o3
F0022658: 90100019                 mov     %i1, %o0
F002265C: d216603e                 lduh    [%i1+0x3E], %o1
F0022660: 9422800b                 sub     %o2, %o3, %o2
F0022664: 9202400a                 add     %o1, %o2, %o1
F0022668: d232203e                 sth     %o1, [%o0+0x3E]
F002266C: d4162024                 lduh    [%i0+0x24], %o2
F0022670: 9202203c                 add     %o0, 0x3C, %o1 ! '<'
F0022674: 7ffff766                 call    _sowakeup
F0022678: d424201c                 st      %o2, [%l0+0x1C]
F002267C: 108000d7                 ba      loc_F00229D8
F0022680: 80a6a000                 cmp     %i2, 0
F0022684: 108000d2                 ba      loc_F00229CC
F0022688: 90122108                 bset    0x108, %o0
F002268C: 80a72000                 cmp     %i4, 0! jumptable F002248C case 9
F0022690: 22800008                 be,a    loc_F00226B0
F0022694: d0560000                 ldsh    [%i0], %o0
F0022698: 40000229                 call    _unp_internalize
F002269C: 9010001c                 mov     %i4, %o0
F00226A0: a4920000                 orcc    %o0, %g0, %l2
F00226A4: 128000cd                 bne     loc_F00229D8
F00226A8: 80a6a000                 cmp     %i2, 0
F00226AC: d0560000                 ldsh    [%i0], %o0
F00226B0: 80a22001                 cmp     %o0, 1
F00226B4: 02800040                 be      loc_F00227B4
F00226B8: 80a22002                 cmp     %o0, 2
F00226BC: 32800071                 bne,a   loc_F0022880
F00226C0: 113c042f                 sethi   -0xFEF4400, %o0
F00226C4: 80a6e000                 cmp     %i3, 0
F00226C8: 0280000d                 be      loc_F00226FC
F00226CC: d004200c                 ld      [%l0+0xC], %o0
F00226D0: 80a22000                 cmp     %o0, 0
F00226D4: 128000c0                 bne     loc_F00229D4! jumptable F002248C cases 15,19
F00226D8: a4102038                 mov     0x38, %l2 ! '8'
F00226DC: 90100018                 mov     %i0, %o0
F00226E0: 40000142                 call    _unp_connect
F00226E4: 9210001b                 mov     %i3, %o1
F00226E8: a4920000                 orcc    %o0, %g0, %l2
F00226EC: 128000bb                 bne     loc_F00229D8
F00226F0: 80a6a000                 cmp     %i2, 0
F00226F4: 10800007                 ba      loc_F0022710
F00226F8: d004200c                 ld      [%l0+0xC], %o0
F00226FC: 80a22000                 cmp     %o0, 0
F0022700: 32800004                 bne,a   loc_F0022710
F0022704: d004200c                 ld      [%l0+0xC], %o0
F0022708: 108000b3                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F002270C: a4102039                 mov     0x39, %l2 ! '9'
F0022710: d2042018                 ld      [%l0+0x18], %o1
F0022714: 80a26000                 cmp     %o1, 0
F0022718: 02800005                 be      loc_F002272C
F002271C: f2020000                 ld      [%o0], %i1
F0022720: d0026004                 ld      [%o1+4], %o0
F0022724: 10800004                 ba      loc_F0022734
F0022728: 98024008                 add     %o1, %o0, %o4
F002272C: 113c042f981220f0         set     _sun_noname, %o4
F0022734: d616602a                 lduh    [%i1+0x2A], %o3
F0022738: d4166026                 lduh    [%i1+0x26], %o2
F002273C: d0166024                 lduh    [%i1+0x24], %o0
F0022740: d2166028                 lduh    [%i1+0x28], %o1
F0022744: 94228008                 sub     %o2, %o0, %o2
F0022748: 9622c009                 sub     %o3, %o1, %o3
F002274C: 80a2800b                 cmp     %o2, %o3
F0022750: 34800002                 bg,a    loc_F0022758
F0022754: 9410000b                 mov     %o3, %o2
F0022758: 80a2a000                 cmp     %o2, 0
F002275C: 0480000e                 ble     loc_F0022794
F0022760: a2066024                 add     %i1, 0x24, %l1 ! '$'
F0022764: 90100011                 mov     %l1, %o0
F0022768: 9210000c                 mov     %o4, %o1
F002276C: 9410001a                 mov     %i2, %o2
F0022770: 7ffff7b3                 call    _sbappendaddr
F0022774: 9610001c                 mov     %i4, %o3
F0022778: 80a22000                 cmp     %o0, 0
F002277C: 02800006                 be      loc_F0022794
F0022780: 90100019                 mov     %i1, %o0
F0022784: 7ffff722                 call    _sowakeup
F0022788: 92100011                 mov     %l1, %o1
F002278C: 10800003                 ba      loc_F0022798
F0022790: b4102000                 mov     0, %i2
F0022794: a4102037                 mov     0x37, %l2 ! '7'
F0022798: 80a6e000                 cmp     %i3, 0
F002279C: 0280008f                 be      loc_F00229D8
F00227A0: 80a6a000                 cmp     %i2, 0
F00227A4: 4000016d                 call    _unp_disconnect! jumptable F002248C case 6
F00227A8: 90100010                 mov     %l0, %o0
F00227AC: 1080008b                 ba      loc_F00229D8
F00227B0: 80a6a000                 cmp     %i2, 0
F00227B4: d0162006                 lduh    [%i0+6], %o0
F00227B8: 808a2010                 btst    0x10, %o0
F00227BC: 22800004                 be,a    loc_F00227CC
F00227C0: d004200c                 ld      [%l0+0xC], %o0
F00227C4: 10800084                 ba      loc_F00229D4! jumptable F002248C cases 15,19
F00227C8: a4102020                 mov     0x20, %l2 ! ' '
F00227CC: 80a22000                 cmp     %o0, 0
F00227D0: 32800006                 bne,a   loc_F00227E8
F00227D4: d004200c                 ld      [%l0+0xC], %o0
F00227D8: 113c042f                 sethi   %hi(aUipc3), %o0! "uipc 3"
F00227DC: 7fffca65                 call    _panic
F00227E0: 90122110                 bset    %lo(aUipc3), %o0! "uipc 3"
F00227E4: d004200c                 ld      [%l0+0xC], %o0
F00227E8: 80a72000                 cmp     %i4, 0
F00227EC: 02800008                 be      loc_F002280C
F00227F0: f2020000                 ld      [%o0], %i1
F00227F4: 90066024                 add     %i1, 0x24, %o0 ! '$'
F00227F8: 9210001a                 mov     %i2, %o1
F00227FC: 7ffff821                 call    _sbappendrights
F0022800: 9410001c                 mov     %i4, %o2
F0022804: 10800006                 ba      loc_F002281C
F0022808: d004200c                 ld      [%l0+0xC], %o0
F002280C: 90066024                 add     %i1, 0x24, %o0 ! '$'
F0022810: 7ffff74e                 call    _sbappend
F0022814: 9210001a                 mov     %i2, %o1
F0022818: d004200c                 ld      [%l0+0xC], %o0
F002281C: d4022020                 ld      [%o0+0x20], %o2
F0022820: d0166028                 lduh    [%i1+0x28], %o0
F0022824: d2162042                 lduh    [%i0+0x42], %o1
F0022828: 9022000a                 sub     %o0, %o2, %o0
F002282C: 92224008                 sub     %o1, %o0, %o1
F0022830: d2362042                 sth     %o1, [%i0+0x42]
F0022834: d204200c                 ld      [%l0+0xC], %o1
F0022838: d0166028                 lduh    [%i1+0x28], %o0
F002283C: d0226020                 st      %o0, [%o1+0x20]
F0022840: d004200c                 ld      [%l0+0xC], %o0
F0022844: d4166024                 lduh    [%i1+0x24], %o2
F0022848: d602201c                 ld      [%o0+0x1C], %o3
F002284C: b4102000                 mov     0, %i2
F0022850: d216203e                 lduh    [%i0+0x3E], %o1
F0022854: 9422800b                 sub     %o2, %o3, %o2
F0022858: 9222400a                 sub     %o1, %o2, %o1
F002285C: d236203e                 sth     %o1, [%i0+0x3E]
F0022860: d604200c                 ld      [%l0+0xC], %o3
F0022864: 90100019                 mov     %i1, %o0
F0022868: d4122024                 lduh    [%o0+0x24], %o2
F002286C: 92022024                 add     %o0, 0x24, %o1 ! '$'
F0022870: 7ffff6e7                 call    _sowakeup
F0022874: d422e01c                 st      %o2, [%o3+0x1C]
F0022878: 10800058                 ba      loc_F00229D8
F002287C: 80a6a000                 cmp     %i2, 0
F0022880: 10800053                 ba      loc_F00229CC
F0022884: 90122118                 bset    0x118, %o0
F0022888: 90100010                 mov     %l0, %o0! jumptable F002248C case 10
F002288C: 40000164                 call    _unp_drop
F0022890: 92102035                 mov     0x35, %o1 ! '5'
F0022894: 10800051                 ba      loc_F00229D8
F0022898: 80a6a000                 cmp     %i2, 0
F002289C: d216203e                 lduh    [%i0+0x3E], %o1! jumptable F002248C case 12
F00228A0: d226a030                 st      %o1, [%i2+0x30]
F00228A4: d0560000                 ldsh    [%i0], %o0
F00228A8: 80a22001                 cmp     %o0, 1
F00228AC: 1280000b                 bne     loc_F00228D8
F00228B0: 90103fff                 mov     -1, %o0
F00228B4: d004200c                 ld      [%l0+0xC], %o0
F00228B8: 80a22000                 cmp     %o0, 0
F00228BC: 22800007                 be,a    loc_F00228D8
F00228C0: 90103fff                 mov     -1, %o0
F00228C4: f2020000                 ld      [%o0], %i1
F00228C8: d0166024                 lduh    [%i1+0x24], %o0
F00228CC: 90024008                 add     %o1, %o0, %o0
F00228D0: d026a030                 st      %o0, [%i2+0x30]
F00228D4: 90103fff                 mov     -1, %o0
F00228D8: d0368000                 sth     %o0, [%i2]
F00228DC: d0042008                 ld      [%l0+8], %o0
F00228E0: 80a22000                 cmp     %o0, 0
F00228E4: 12800009                 bne     loc_F0022908
F00228E8: 133c04cf                 sethi   -0xFECC400, %o1
F00228EC: 113c04d4                 sethi   %hi(_unp_vno), %o0
F00228F0: d40222d8                 ld      [%o0+%lo(_unp_vno)], %o2
F00228F4: 9202a001                 add     %o2, 1, %o1
F00228F8: d22222d8                 st      %o1, [%o0+%lo(_unp_vno)]
F00228FC: d4242008                 st      %o2, [%l0+8]
F0022900: d0042008                 ld      [%l0+8], %o0
F0022904: 133c04cf                 sethi   -0xFECC400, %o1
F0022908: d026a004                 st      %o0, [%i2+4]
F002290C: 11000004901221b6         set     0x11B6, %o0
F0022914: d036a008                 sth     %o0, [%i2+8]
F0022918: 90102001                 mov     1, %o0
F002291C: d036a00a                 sth     %o0, [%i2+0xA]
F0022920: d00261d8                 ld      [%o1+0x1D8], %o0
F0022924: d002201c                 ld      [%o0+0x1C], %o0
F0022928: d0122002                 lduh    [%o0+2], %o0
F002292C: d036a00c                 sth     %o0, [%i2+0xC]
F0022930: d00261d8                 ld      [%o1+0x1D8], %o0
F0022934: d002201c                 ld      [%o0+0x1C], %o0
F0022938: d0122004                 lduh    [%o0+4], %o0
F002293C: d036a00e                 sth     %o0, [%i2+0xE]
F0022940: d2162024                 lduh    [%i0+0x24], %o1
F0022944: 9007bff0                 add     %fp, var_10, %o0
F0022948: 7fffc191                 call    _getthetime
F002294C: d226a014                 st      %o1, [%i2+0x14]
F0022950: d007bff0                 ld      [%fp+var_10], %o0
F0022954: d026a018                 st      %o0, [%i2+0x18]
F0022958: d007bff0                 ld      [%fp+var_10], %o0
F002295C: d026a020                 st      %o0, [%i2+0x20]
F0022960: d007bff0                 ld      [%fp+var_10], %o0
F0022964: b0102000                 mov     0, %i0
F0022968: 10800021                 ba      locret_F00229EC
F002296C: d026a028                 st      %o0, [%i2+0x28]
F0022970: d004200c                 ld      [%l0+0xC], %o0! jumptable F002248C case 16
F0022974: 80a22000                 cmp     %o0, 0
F0022978: 02800018                 be      loc_F00229D8
F002297C: 80a6a000                 cmp     %i2, 0
F0022980: d0022018                 ld      [%o0+0x18], %o0
F0022984: 80a22000                 cmp     %o0, 0
F0022988: 02800014                 be      loc_F00229D8
F002298C: 80a6a000                 cmp     %i2, 0
F0022990: d4122008                 lduh    [%o0+8], %o2
F0022994: d206e004                 ld      [%i3+4], %o1
F0022998: d436e008                 sth     %o2, [%i3+8]
F002299C: d004200c                 ld      [%l0+0xC], %o0
F00229A0: 9206c009                 add     %i3, %o1, %o1! void *
F00229A4: d6022018                 ld      [%o0+0x18], %o3
F00229A8: 952aa010                 sll     %o2, 16, %o2
F00229AC: d002e004                 ld      [%o3+4], %o0! void *
F00229B0: 953aa010                 sra     %o2, 16, %o2! size_t
F00229B4: 4001c857                 call    _bcopy
F00229B8: 9002c008                 add     %o3, %o0, %o0
F00229BC: 10800007                 ba      loc_F00229D8
F00229C0: 80a6a000                 cmp     %i2, 0
F00229C4: 113c042f90122120         set     aPiusrreq, %o0! jumptable F002248C default case, cases 11,18
F00229CC: 7fffc9e9                 call    _panic
F00229D0: 01000000                 nop
F00229D4: 80a6a000                 cmp     %i2, 0! jumptable F002248C cases 15,19
F00229D8: 02800005                 be      locret_F00229EC
F00229DC: b0100012                 mov     %l2, %i0
F00229E0: 7fffeca1                 call    _m_freem
F00229E4: 9010001a                 mov     %i2, %o0
F00229E8: b0100012                 mov     %l2, %i0
F00229EC: 81c7e008                 ret
F00229F0: 81e80000                 restore
