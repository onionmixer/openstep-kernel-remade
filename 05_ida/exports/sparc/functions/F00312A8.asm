F00312A8: 9de3bf90                 save    %sp, -0x70, %sp
F00312AC: d0062004                 ld      [%i0+4], %o0
F00312B0: aa060008                 add     %i0, %o0, %l5
F00312B4: e2556002                 ldsh    [%l5+2], %l1
F00312B8: d00e0008                 ldub    [%i0+%o0], %o0
F00312BC: 80a46007                 cmp     %l1, 7
F00312C0: 900a200f                 and     %o0, 0xF, %o0
F00312C4: 14800008                 bg      loc_F00312E4
F00312C8: a72a2002                 sll     %o0, 2, %l3
F00312CC: 133c04d992126160         set     _icmpstat, %o1
F00312D4: d002605c                 ld      [%o1+0x5C], %o0
F00312D8: 90022001                 inc     %o0
F00312DC: 1080016e                 ba      loc_F0031894
F00312E0: d022605c                 st      %o0, [%o1+0x5C]
F00312E4: 80a46023                 cmp     %l1, 0x23 ! '#'
F00312E8: 08800003                 bleu    loc_F00312F4
F00312EC: 9204c011                 add     %l3, %l1, %o1
F00312F0: 9204e024                 add     %l3, 0x24, %o1 ! '$'
F00312F4: d0062004                 ld      [%i0+4], %o0
F00312F8: 80a2207c                 cmp     %o0, 0x7C ! '|'
F00312FC: 18800006                 bgu     loc_F0031314
F0031300: 01000000                 nop
F0031304: d0562008                 ldsh    [%i0+8], %o0
F0031308: 80a20009                 cmp     %o0, %o1
F003130C: 1680000d                 bge     loc_F0031340
F0031310: 90100018                 mov     %i0, %o0
F0031314: 7fffb370                 call    _m_pullup
F0031318: 90100018                 mov     %i0, %o0
F003131C: b0920000                 orcc    %o0, %g0, %i0
F0031320: 12800008                 bne     loc_F0031340
F0031324: 90100018                 mov     %i0, %o0
F0031328: 133c04d992126160         set     _icmpstat, %o1
F0031330: d002605c                 ld      [%o1+0x5C], %o0
F0031334: 90022001                 inc     %o0
F0031338: 10800159                 ba      locret_F003189C
F003133C: d022605c                 st      %o0, [%o1+0x5C]
F0031340: d4062004                 ld      [%i0+4], %o2
F0031344: 92100011                 mov     %l1, %o1
F0031348: d6162008                 lduh    [%i0+8], %o3
F003134C: aa06000a                 add     %i0, %o2, %l5
F0031350: 9622c013                 sub     %o3, %l3, %o3
F0031354: d4062004                 ld      [%i0+4], %o2
F0031358: d6362008                 sth     %o3, [%i0+8]
F003135C: a0028013                 add     %o2, %l3, %l0
F0031360: 40019eca                 call    _in_cksum
F0031364: e0262004                 st      %l0, [%i0+4]
F0031368: 80a22000                 cmp     %o0, 0
F003136C: 02800008                 be      loc_F003138C
F0031370: a4060010                 add     %i0, %l0, %l2
F0031374: 133c04d992126160         set     _icmpstat, %o1
F003137C: d0026060                 ld      [%o1+0x60], %o0
F0031380: 90022001                 inc     %o0
F0031384: 10800144                 ba      loc_F0031894
F0031388: d0226060                 st      %o0, [%o1+0x60]
F003138C: d0162008                 lduh    [%i0+8], %o0
F0031390: d2062004                 ld      [%i0+4], %o1
F0031394: 90020013                 add     %o0, %l3, %o0
F0031398: d0362008                 sth     %o0, [%i0+8]
F003139C: 92224013                 sub     %o1, %l3, %o1
F00313A0: d2262004                 st      %o1, [%i0+4]
F00313A4: d40e0010                 ldub    [%i0+%l0], %o2
F00313A8: 80a2a012                 cmp     %o2, 0x12
F00313AC: 1880012d                 bgu     def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F00313B0: 113c04d9                 sethi   %hi(unk_F01365CC), %o0
F00313B4: 901221cc                 bset    %lo(unk_F01365CC), %o0
F00313B8: 952aa002                 sll     %o2, 2, %o2
F00313BC: d2028008                 ld      [%o2+%o0], %o1
F00313C0: 92026001                 inc     %o1
F00313C4: d2228008                 st      %o1, [%o2+%o0]
F00313C8: d20e0010                 ldub    [%i0+%l0], %o1
F00313CC: 80a26012                 cmp     %o1, 0x12! switch 19 cases
F00313D0: 18800124                 bgu     def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F00313D4: d60ca001                 ldub    [%l2+1], %o3
F00313D8: 113c00c4901223f0         set     jpt_F00313E8, %o0
F00313E0: 932a6002                 sll     %o1, 2, %o1
F00313E4: d0024008                 ld      [%o1+%o0], %o0
F00313E8: 81c20000                 jmp     %o0! switch jump
F00313EC: 01000000                 nop
F003143C: 80a2e005                 cmp     %o3, 5! jumptable F00313E8 case 3
F0031440: 14800039                 bg      loc_F0031524
F0031444: 133c04d9                 sethi   -0xFEC9C00, %o1
F0031448: 10800010                 ba      loc_F0031488
F003144C: 9602e008                 inc     8, %o3
F0031450: 80a2e001                 cmp     %o3, 1! jumptable F00313E8 case 11
F0031454: 14800034                 bg      loc_F0031524
F0031458: 133c04d9                 sethi   -0xFEC9C00, %o1
F003145C: 1080000b                 ba      loc_F0031488
F0031460: 9602e012                 inc     0x12, %o3
F0031464: 80a2e000                 cmp     %o3, 0! jumptable F00313E8 case 12
F0031468: 1280002f                 bne     loc_F0031524
F003146C: 133c04d9                 sethi   -0xFEC9C00, %o1
F0031470: 10800006                 ba      loc_F0031488
F0031474: 96102014                 mov     0x14, %o3
F0031478: 80a2e000                 cmp     %o3, 0! jumptable F00313E8 case 4
F003147C: 1280002a                 bne     loc_F0031524
F0031480: 133c04d9                 sethi   -0xFEC9C00, %o1
F0031484: 96102004                 mov     4, %o3
F0031488: d014a00a                 lduh    [%l2+0xA], %o0
F003148C: 80a46023                 cmp     %l1, 0x23 ! '#'
F0031490: 08800009                 bleu    loc_F00314B4
F0031494: d034a00a                 sth     %o0, [%l2+0xA]
F0031498: d00ca008                 ldub    [%l2+8], %o0
F003149C: 900a200f                 and     %o0, 0xF, %o0
F00314A0: 912a2002                 sll     %o0, 2, %o0
F00314A4: 90022010                 inc     0x10, %o0
F00314A8: 80a44008                 cmp     %l1, %o0
F00314AC: 16800008                 bge     loc_F00314CC
F00314B0: 113c0431                 sethi   -0xFEF3C00, %o0
F00314B4: 133c04d992126160         set     _icmpstat, %o1
F00314BC: d0026064                 ld      [%o1+0x64], %o0
F00314C0: 90022001                 inc     %o0
F00314C4: 108000f4                 ba      loc_F0031894
F00314C8: d0226064                 st      %o0, [%o1+0x64]
F00314CC: 94122340                 or      %o0, 0x340, %o2
F00314D0: d204a018                 ld      [%l2+0x18], %o1
F00314D4: 113c04d9                 sethi   %hi(_ip_protox), %o0
F00314D8: d222a004                 st      %o1, [%o2+4]
F00314DC: d20ca011                 ldub    [%l2+0x11], %o1
F00314E0: 90122220                 bset    %lo(_ip_protox), %o0
F00314E4: d20a4008                 ldub    [%o1+%o0], %o1
F00314E8: 912a6001                 sll     %o1, 1, %o0
F00314EC: 90020009                 add     %o0, %o1, %o0
F00314F0: 912a2004                 sll     %o0, 4, %o0
F00314F4: 133c0431921261a0         set     _inetsw, %o1
F00314FC: 90020009                 add     %o0, %o1, %o0
F0031500: d8022014                 ld      [%o0+0x14], %o4
F0031504: 80a32000                 cmp     %o4, 0
F0031508: 028000d6                 be      def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F003150C: 9010000b                 mov     %o3, %o0
F0031510: 9210000a                 mov     %o2, %o1
F0031514: 9fc30000                 call    %o4
F0031518: 9404a008                 add     %l2, 8, %o2
F003151C: 108000d2                 ba      loc_F0031864
F0031520: 90100018                 mov     %i0, %o0
F0031524: 92126160                 bset    0x160, %o1
F0031528: d0026058                 ld      [%o1+0x58], %o0
F003152C: 90022001                 inc     %o0
F0031530: 108000cc                 ba      def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F0031534: d0226058                 st      %o0, [%o1+0x58]
F0031538: 10800043                 ba      loc_F0031644! jumptable F00313E8 case 8
F003153C: c02c8000                 clrb    [%l2]
F0031540: 80a46013                 cmp     %l1, 0x13! jumptable F00313E8 case 13
F0031544: 0880005c                 bleu    loc_F00316B4
F0031548: 9010200e                 mov     0xE, %o0
F003154C: 4000014a                 call    _iptime
F0031550: d02c8000                 stb     %o0, [%l2]
F0031554: d024a00c                 st      %o0, [%l2+0xC]
F0031558: 1080003b                 ba      loc_F0031644
F003155C: d024a010                 st      %o0, [%l2+0x10]
F0031560: d205600c                 ld      [%l5+0xC], %o1! jumptable F00313E8 case 15
F0031564: 9007bff4                 add     %fp, var_C, %o0
F0031568: 7ffff47b                 call    _in_netof
F003156C: d227bff4                 st      %o1, [%fp+var_C]
F0031570: 80a22000                 cmp     %o0, 0
F0031574: 12800015                 bne     loc_F00315C8
F0031578: 90102010                 mov     0x10, %o0
F003157C: 4000010b                 call    _ifptoia
F0031580: 90100019                 mov     %i1, %o0
F0031584: a8920000                 orcc    %o0, %g0, %l4
F0031588: 0280000f                 be      loc_F00315C4
F003158C: a007bff0                 add     %fp, var_10, %l0
F0031590: d2052004                 ld      [%l4+4], %o1
F0031594: 90100010                 mov     %l0, %o0
F0031598: 7ffff46f                 call    _in_netof
F003159C: d227bff0                 st      %o1, [%fp+var_10]
F00315A0: a2100008                 mov     %o0, %l1
F00315A4: d205600c                 ld      [%l5+0xC], %o1
F00315A8: 90100010                 mov     %l0, %o0
F00315AC: 7ffff497                 call    _in_lnaof
F00315B0: d227bff0                 st      %o1, [%fp+var_10]
F00315B4: 92100008                 mov     %o0, %o1
F00315B8: 7ffff441                 call    _in_makeaddr
F00315BC: 90100011                 mov     %l1, %o0
F00315C0: d025600c                 st      %o0, [%l5+0xC]
F00315C4: 90102010                 mov     0x10, %o0
F00315C8: 1080001f                 ba      loc_F0031644
F00315CC: d02c8000                 stb     %o0, [%l2]
F00315D0: 80a4600b                 cmp     %l1, 0xB! jumptable F00313E8 case 17
F00315D4: 048000a4                 ble     loc_F0031864
F00315D8: 90100018                 mov     %i0, %o0
F00315DC: 400000f3                 call    _ifptoia
F00315E0: 90100019                 mov     %i1, %o0
F00315E4: a8920000                 orcc    %o0, %g0, %l4
F00315E8: 0280009f                 be      loc_F0031864
F00315EC: 90100018                 mov     %i0, %o0
F00315F0: d005203c                 ld      [%l4+0x3C], %o0
F00315F4: 808a2002                 btst    2, %o0
F00315F8: 0280009a                 be      def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F00315FC: 90102012                 mov     0x12, %o0
F0031600: d02c8000                 stb     %o0, [%l2]
F0031604: d0052034                 ld      [%l4+0x34], %o0
F0031608: d024a008                 st      %o0, [%l2+8]
F003160C: d005600c                 ld      [%l5+0xC], %o0
F0031610: 80a22000                 cmp     %o0, 0
F0031614: 1280000d                 bne     loc_F0031648
F0031618: 173c04d9                 sethi   -0xFEC9C00, %o3
F003161C: d0052020                 ld      [%l4+0x20], %o0
F0031620: d012200c                 lduh    [%o0+0xC], %o0
F0031624: 808a2002                 btst    2, %o0
F0031628: 32800006                 bne,a   loc_F0031640
F003162C: d0052014                 ld      [%l4+0x14], %o0
F0031630: 808a2010                 btst    0x10, %o0
F0031634: 22800006                 be,a    loc_F003164C
F0031638: d0156002                 lduh    [%l5+2], %o0
F003163C: d0052014                 ld      [%l4+0x14], %o0
F0031640: d025600c                 st      %o0, [%l5+0xC]
F0031644: 173c04d9                 sethi   -0xFEC9C00, %o3
F0031648: d0156002                 lduh    [%l5+2], %o0
F003164C: 9612e160                 bset    0x160, %o3
F0031650: 90020013                 add     %o0, %l3, %o0
F0031654: d0356002                 sth     %o0, [%l5+2]
F0031658: d202e068                 ld      [%o3+0x68], %o1
F003165C: 90100015                 mov     %l5, %o0
F0031660: 92026001                 inc     %o1
F0031664: d222e068                 st      %o1, [%o3+0x68]
F0031668: d80c8000                 ldub    [%l2], %o4
F003166C: 9602e00c                 inc     0xC, %o3
F0031670: 992b2002                 sll     %o4, 2, %o4
F0031674: d403000b                 ld      [%o4+%o3], %o2
F0031678: 92100019                 mov     %i1, %o1
F003167C: 9402a001                 inc     %o2
F0031680: 40000089                 call    _icmp_reflect
F0031684: d423000b                 st      %o2, [%o4+%o3]
F0031688: 30800085                 ba,a    locret_F003189C
F003168C: 80a46023                 cmp     %l1, 0x23 ! '#'! jumptable F00313E8 case 5
F0031690: 0880000a                 bleu    loc_F00316B8
F0031694: 133c04d9                 sethi   -0xFEC9C00, %o1
F0031698: d00ca008                 ldub    [%l2+8], %o0
F003169C: 900a200f                 and     %o0, 0xF, %o0
F00316A0: 912a2002                 sll     %o0, 2, %o0
F00316A4: 90022010                 inc     0x10, %o0
F00316A8: 80a44008                 cmp     %l1, %o0
F00316AC: 16800008                 bge     loc_F00316CC
F00316B0: 80a2e000                 cmp     %o3, 0
F00316B4: 133c04d9                 sethi   -0xFEC9C00, %o1
F00316B8: 92126160                 bset    0x160, %o1
F00316BC: d0026064                 ld      [%o1+0x64], %o0
F00316C0: 90022001                 inc     %o0
F00316C4: 10800067                 ba      def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F00316C8: d0226064                 st      %o0, [%o1+0x64]
F00316CC: 113c0431a6122360         set     unk_F010C760, %l3
F00316D4: d205600c                 ld      [%l5+0xC], %o1
F00316D8: 113c0431                 sethi   %hi(unk_F010C750), %o0
F00316DC: d224e004                 st      %o1, [%l3+4]
F00316E0: d204a004                 ld      [%l2+4], %o1
F00316E4: a2122350                 or      %o0, %lo(unk_F010C750), %l1
F00316E8: 02800005                 be      loc_F00316FC
F00316EC: d2246004                 st      %o1, [%l1+4]
F00316F0: 80a2e002                 cmp     %o3, 2
F00316F4: 12800017                 bne     loc_F0031750
F00316F8: 213c0431                 sethi   -0xFEF3C00, %l0
F00316FC: d204a018                 ld      [%l2+0x18], %o1
F0031700: 9007bff0                 add     %fp, var_10, %o0
F0031704: 7ffff414                 call    _in_netof
F0031708: d227bff0                 st      %o1, [%fp+var_10]
F003170C: 7ffff3ec                 call    _in_makeaddr
F0031710: 92102000                 mov     0, %o1
F0031714: 213c0431a0142340         set     unk_F010C740, %l0
F003171C: d0242004                 st      %o0, [%l0+4]
F0031720: 90100010                 mov     %l0, %o0
F0031724: 92100011                 mov     %l1, %o1
F0031728: 94102002                 mov     2, %o2
F003172C: 7fffedd4                 call    _rtredirect
F0031730: 96100013                 mov     %l3, %o3
F0031734: 9010200e                 mov     0xE, %o0! int
F0031738: d404a018                 ld      [%l2+0x18], %o2
F003173C: 92100010                 mov     %l0, %o1! sockaddr *
F0031740: 7fffaf6b                 call    _pfctlinput
F0031744: d4226004                 st      %o2, [%o1+4]
F0031748: 10800047                 ba      loc_F0031864
F003174C: 90100018                 mov     %i0, %o0
F0031750: a0142340                 bset    0x340, %l0
F0031754: 90100010                 mov     %l0, %o0
F0031758: 92100011                 mov     %l1, %o1! sockaddr *
F003175C: 94102006                 mov     6, %o2
F0031760: d804a018                 ld      [%l2+0x18], %o4
F0031764: 96100013                 mov     %l3, %o3
F0031768: 7fffedc5                 call    _rtredirect
F003176C: d8242004                 st      %o4, [%l0+4]
F0031770: 9010200f                 mov     0xF, %o0! int
F0031774: 7fffaf5e                 call    _pfctlinput
F0031778: 92100010                 mov     %l0, %o1
F003177C: 1080003a                 ba      loc_F0031864
F0031780: 90100018                 mov     %i0, %o0
F0031784: 40000089                 call    _ifptoia! jumptable F00313E8 case 18
F0031788: 90100019                 mov     %i1, %o0
F003178C: a8920000                 orcc    %o0, %g0, %l4
F0031790: 02800035                 be      loc_F0031864
F0031794: 90100018                 mov     %i0, %o0
F0031798: d405203c                 ld      [%l4+0x3C], %o2
F003179C: 808aa004                 btst    4, %o2
F00317A0: 02800032                 be      loc_F0031868
F00317A4: 133c0431                 sethi   -0xFEF3C00, %o1
F00317A8: d004a008                 ld      [%l2+8], %o0
F00317AC: 80a23fff                 cmp     %o0, -1
F00317B0: 0280002c                 be      def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F00317B4: 133fc000                 sethi   -0x1000000, %o1
F00317B8: 900a0009                 and     %o0, %o1, %o0
F00317BC: 80a20009                 cmp     %o0, %o1
F00317C0: 12800029                 bne     loc_F0031864
F00317C4: 90100018                 mov     %i0, %o0
F00317C8: 900abffb                 and     %o2, -5, %o0
F00317CC: d025203c                 st      %o0, [%l4+0x3C]
F00317D0: d016600c                 lduh    [%i1+0xC], %o0
F00317D4: 808a2008                 btst    8, %o0
F00317D8: 12800023                 bne     loc_F0031864
F00317DC: 90100018                 mov     %i0, %o0
F00317E0: d2052034                 ld      [%l4+0x34], %o1
F00317E4: d404a008                 ld      [%l2+8], %o2
F00317E8: 9012400a                 or      %o1, %o2, %o0
F00317EC: 80a20009                 cmp     %o0, %o1
F00317F0: 0280001c                 be      def_F00313E8! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F00317F4: 90100019                 mov     %i1, %o0
F00317F8: d4252034                 st      %o2, [%l4+0x34]
F00317FC: 92100014                 mov     %l4, %o1
F0031800: 7ffff5fa                 call    _in_ifinit
F0031804: 94100014                 mov     %l4, %o2
F0031808: 80a22000                 cmp     %o0, 0
F003180C: 02800006                 be      loc_F0031824
F0031810: 113c0431                 sethi   %hi(aIcmpInputCanTS), %o0! "icmp_input: can't set new netmask\n"
F0031814: 7fff8b91                 call    _printf
F0031818: 90122370                 bset    %lo(aIcmpInputCanTS), %o0! "icmp_input: can't set new netmask\n"
F003181C: 10800012                 ba      loc_F0031864
F0031820: 90100018                 mov     %i0, %o0
F0031824: e6064000                 ld      [%i1], %l3
F0031828: 9005600c                 add     %l5, 0xC, %o0! in_addr
F003182C: e4566008                 ldsh    [%i1+8], %l2
F0031830: 213c0431                 sethi   %hi(aSDSettingNetma), %l0! "%s%d: setting netmask to %x, received f"...
F0031834: e2052034                 ld      [%l4+0x34], %l1
F0031838: 7ffff6d7                 call    _inet_ntoa
F003183C: a0142398                 bset    %lo(aSDSettingNetma), %l0! "%s%d: setting netmask to %x, received f"...
F0031840: 98100008                 mov     %o0, %o4
F0031844: 90100010                 mov     %l0, %o0! char *
F0031848: 92100013                 mov     %l3, %o1
F003184C: 94100012                 mov     %l2, %o2
F0031850: 7fff8b82                 call    _printf
F0031854: 96100011                 mov     %l1, %o3
F0031858: 7fff8564                 call    _wakeup
F003185C: 90052034                 add     %l4, 0x34, %o0 ! '4'
F0031860: 90100018                 mov     %i0, %o0! jumptable F00313E8 default case, cases 0-2,6,7,9,10,14,16
F0031864: 133c0431                 sethi   -0xFEF3C00, %o1
F0031868: 9212633a                 bset    0x33A, %o1
F003186C: 153c0431                 sethi   %hi(unk_F010C740), %o2
F0031870: d605600c                 ld      [%l5+0xC], %o3
F0031874: 9412a340                 bset    %lo(unk_F010C740), %o2
F0031878: d622a004                 st      %o3, [%o2+4]
F003187C: 173c0431                 sethi   %hi(unk_F010C750), %o3
F0031880: d8056010                 ld      [%l5+0x10], %o4
F0031884: 9612e350                 bset    %lo(unk_F010C750), %o3
F0031888: 7fffeb8b                 call    _raw_input
F003188C: d822e004                 st      %o4, [%o3+4]
F0031890: 30800003                 ba,a    locret_F003189C
F0031894: 7fffb0f4                 call    _m_freem
F0031898: 90100018                 mov     %i0, %o0
F003189C: 81c7e008                 ret
F00318A0: 81e80000                 restore
