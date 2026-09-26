F0018494: 9de3bf98                 save    %sp, -0x68, %sp
F0018498: e2064000                 ld      [%i1], %l1
F001849C: e4066010                 ld      [%i1+0x10], %l2
F00184A0: 113fc000                 sethi   -0x1000000, %o0
F00184A4: 928e0008                 andcc   %i0, %o0, %o1
F00184A8: 02800038                 be      loc_F0018588
F00184AC: e604603c                 ld      [%l1+0x3C], %l3
F00184B0: b02e0008                 bclr    %o0, %i0
F00184B4: 11004000                 sethi   0x1000000, %o0
F00184B8: 808a4008                 btst    %o0, %o1
F00184BC: 02800019                 be      loc_F0018520
F00184C0: 80a62000                 cmp     %i0, 0
F00184C4: 12800018                 bne     loc_F0018524
F00184C8: 11008000                 sethi   0x2000000, %o0
F00184CC: 11000080                 sethi   0x20000, %o0
F00184D0: 808c8008                 btst    %o0, %l2
F00184D4: 12800296                 bne     loc_F0018F2C
F00184D8: 808ca010                 btst    0x10, %l2
F00184DC: 11000100                 sethi   0x40000, %o0
F00184E0: 808c8008                 btst    %o0, %l2
F00184E4: 02800009                 be      loc_F0018508
F00184E8: 90100011                 mov     %l1, %o0
F00184EC: 7ffff951                 call    _ttyflush
F00184F0: 92102003                 mov     3, %o1
F00184F4: d0546044                 ldsh    [%l1+0x44], %o0
F00184F8: 7fffe3f9                 call    _gsignal
F00184FC: 92102002                 mov     2, %o1
F0018500: 1080028b                 ba      loc_F0018F2C
F0018504: 808ca010                 btst    0x10, %l2
F0018508: 11000400                 sethi   0x100000, %o0
F001850C: 808c8008                 btst    %o0, %l2
F0018510: 12800016                 bne     loc_F0018568
F0018514: 901021ff                 mov     0x1FF, %o0
F0018518: 1080001d                 ba      loc_F001858C
F001851C: d2046040                 ld      [%l1+0x40], %o1! FILE *
F0018520: 11008000                 sethi   0x2000000, %o0
F0018524: 808a4008                 btst    %o0, %o1
F0018528: 02800005                 be      loc_F001853C
F001852C: 11000800                 sethi   0x200000, %o0
F0018530: 808c8008                 btst    %o0, %l2
F0018534: 12800006                 bne     loc_F001854C
F0018538: 11000200                 sethi   0x80000, %o0
F001853C: 11004000                 sethi   0x1000000, %o0
F0018540: 808a4008                 btst    %o0, %o1
F0018544: 02800011                 be      loc_F0018588
F0018548: 11000200                 sethi   0x80000, %o0
F001854C: 808c8008                 btst    %o0, %l2
F0018550: 12800277                 bne     loc_F0018F2C
F0018554: 808ca010                 btst    0x10, %l2
F0018558: 11000400                 sethi   0x100000, %o0
F001855C: 808c8008                 btst    %o0, %l2
F0018560: 02800009                 be      loc_F0018584
F0018564: 901021ff                 mov     0x1FF, %o0! int
F0018568: 4000117a                 call    _putc
F001856C: 92100011                 mov     %l1, %o1! FILE *
F0018570: 90102100                 mov     0x100, %o0! int
F0018574: 40001177                 call    _putc
F0018578: 92100011                 mov     %l1, %o1
F001857C: 10800003                 ba      loc_F0018588
F0018580: b0162100                 bset    0x100, %i0
F0018584: b0102100                 mov     0x100, %i0
F0018588: d2046040                 ld      [%l1+0x40], %o1
F001858C: 11000400                 sethi   0x100000, %o0
F0018590: 808a4008                 btst    %o0, %o1
F0018594: 3280000c                 bne,a   loc_F00185C4
F0018598: d2046040                 ld      [%l1+0x40], %o1
F001859C: 1102000090122020         set     0x8000020, %o0
F00185A4: 808cc008                 btst    %o0, %l3
F00185A8: 32800007                 bne,a   loc_F00185C4
F00185AC: d2046040                 ld      [%l1+0x40], %o1
F00185B0: 11001000                 sethi   0x400000, %o0
F00185B4: 808c8008                 btst    %o0, %l2
F00185B8: 32800002                 bne,a   loc_F00185C0
F00185BC: b00e3f7f                 and     %i0, -0x81, %i0
F00185C0: d2046040                 ld      [%l1+0x40], %o1
F00185C4: 11000200                 sethi   0x80000, %o0
F00185C8: 808a4008                 btst    %o0, %o1
F00185CC: 02800004                 be      loc_F00185DC
F00185D0: 902a4008                 andn    %o1, %o0, %o0
F00185D4: b0162100                 bset    0x100, %i0
F00185D8: d0246040                 st      %o0, [%l1+0x40]
F00185DC: 808e2100                 btst    0x100, %i0
F00185E0: 12800011                 bne     loc_F0018624
F00185E4: 808ce022                 btst    0x22, %l3 ! '"'
F00185E8: d2046040                 ld      [%l1+0x40], %o1
F00185EC: 11001000                 sethi   0x400000, %o0
F00185F0: 808a4008                 btst    %o0, %o1
F00185F4: 1280000c                 bne     loc_F0018624
F00185F8: 808ce022                 btst    0x22, %l3 ! '"'
F00185FC: 913e2005                 sra     %i0, 5, %o0
F0018600: 912a2002                 sll     %o0, 2, %o0
F0018604: 90020011                 add     %o0, %l1, %o0
F0018608: d0022064                 ld      [%o0+0x64], %o0
F001860C: 920e201f                 and     %i0, 0x1F, %o1
F0018610: 913a0009                 sra     %o0, %o1, %o0
F0018614: 808a2001                 btst    1, %o0
F0018618: 12800007                 bne     loc_F0018634
F001861C: 11000604                 sethi   0x181000, %o0
F0018620: 808ce022                 btst    0x22, %l3 ! '"'
F0018624: 128000e7                 bne     loc_F00189C0
F0018628: d0044000                 ld      [%l1], %o0
F001862C: 108001ca                 ba      loc_F0018D54
F0018630: d204600c                 ld      [%l1+0xC], %o1
F0018634: 900c8008                 and     %l2, %o0, %o0
F0018638: 13000404                 sethi   0x101000, %o1! FILE *
F001863C: 80a20009                 cmp     %o0, %o1
F0018640: 1280000a                 bne     loc_F0018668
F0018644: 808ca010                 btst    0x10, %l2
F0018648: 80a620ff                 cmp     %i0, 0xFF
F001864C: 12800007                 bne     loc_F0018668
F0018650: 808ca010                 btst    0x10, %l2
F0018654: 901021ff                 mov     0x1FF, %o0! int
F0018658: 4000113e                 call    _putc
F001865C: 92100011                 mov     %l1, %o1
F0018660: b01021ff                 mov     0x1FF, %i0
F0018664: 808ca010                 btst    0x10, %l2
F0018668: 02800038                 be      loc_F0018748
F001866C: 920e20ff                 and     %i0, 0xFF, %o1
F0018670: 80a260ff                 cmp     %o1, 0xFF
F0018674: 02800036                 be      loc_F001874C
F0018678: 808ca008                 btst    8, %l2
F001867C: d00c605a                 ldub    [%l1+0x5A], %o0
F0018680: 80a24008                 cmp     %o1, %o0
F0018684: 12800015                 bne     loc_F00186D8
F0018688: 80a260ff                 cmp     %o1, 0xFF
F001868C: 808ce008                 btst    8, %l3
F0018690: 0280000d                 be      loc_F00186C4
F0018694: 11000100                 sethi   0x40000, %o0
F0018698: 808cc008                 btst    %o0, %l3
F001869C: 02800007                 be      loc_F00186B8
F00186A0: 113c042e                 sethi   %hi(asc_F010B838), %o0! "^\b"
F00186A4: 90122038                 bset    %lo(asc_F010B838), %o0! "^\b"
F00186A8: 400007a1                 call    _ttyoutstr
F00186AC: 92100011                 mov     %l1, %o1
F00186B0: 10800006                 ba      loc_F00186C8
F00186B4: d0046040                 ld      [%l1+0x40], %o0
F00186B8: 90100018                 mov     %i0, %o0
F00186BC: 4000074e                 call    _ttyecho
F00186C0: 92100019                 mov     %i1, %o1
F00186C4: d0046040                 ld      [%l1+0x40], %o0
F00186C8: 13000200                 sethi   0x80000, %o1
F00186CC: 90120009                 bset    %o1, %o0
F00186D0: 10800216                 ba      loc_F0018F28
F00186D4: d0246040                 st      %o0, [%l1+0x40]
F00186D8: 0280001d                 be      loc_F001874C
F00186DC: 808ca008                 btst    8, %l2
F00186E0: d00c6058                 ldub    [%l1+0x58], %o0
F00186E4: 80a24008                 cmp     %o1, %o0
F00186E8: 12800019                 bne     loc_F001874C
F00186EC: 808ca008                 btst    8, %l2
F00186F0: 21002000                 sethi   0x800000, %l0
F00186F4: 808cc010                 btst    %l0, %l3
F00186F8: 02800004                 be      loc_F0018708
F00186FC: 90100011                 mov     %l1, %o0
F0018700: 1080021f                 ba      loc_F0018F7C
F0018704: d204603c                 ld      [%l1+0x3C], %o1
F0018708: 7ffff8ca                 call    _ttyflush
F001870C: 92102002                 mov     2, %o1
F0018710: 90100018                 mov     %i0, %o0
F0018714: 40000738                 call    _ttyecho
F0018718: 92100019                 mov     %i1, %o1
F001871C: d0044000                 ld      [%l1], %o0
F0018720: d204600c                 ld      [%l1+0xC], %o1
F0018724: 90020009                 add     %o0, %o1, %o0
F0018728: 80a22000                 cmp     %o0, 0
F001872C: 22800005                 be,a    loc_F0018740
F0018730: d004603c                 ld      [%l1+0x3C], %o0
F0018734: 400006fd                 call    _ttyretype
F0018738: 90100019                 mov     %i1, %o0
F001873C: d004603c                 ld      [%l1+0x3C], %o0
F0018740: 10800211                 ba      loc_F0018F84
F0018744: 90120010                 bset    %l0, %o0
F0018748: 808ca008                 btst    8, %l2
F001874C: 02800033                 be      loc_F0018818
F0018750: a00e20ff                 and     %i0, 0xFF, %l0
F0018754: 80a420ff                 cmp     %l0, 0xFF
F0018758: 0280001c                 be      loc_F00187C8
F001875C: 920e20ff                 and     %i0, 0xFF, %o1
F0018760: d00c604f                 ldub    [%l1+0x4F], %o0
F0018764: 80a40008                 cmp     %l0, %o0
F0018768: 02800007                 be      loc_F0018784
F001876C: 80a4e000                 cmp     %l3, 0
F0018770: d00c6050                 ldub    [%l1+0x50], %o0
F0018774: 80a40008                 cmp     %l0, %o0
F0018778: 12800015                 bne     loc_F00187CC
F001877C: 80a260ff                 cmp     %o1, 0xFF
F0018780: 80a4e000                 cmp     %l3, 0
F0018784: 06800004                 bl      loc_F0018794
F0018788: 90100011                 mov     %l1, %o0
F001878C: 7ffff8a9                 call    _ttyflush
F0018790: 92102003                 mov     3, %o1
F0018794: 90100018                 mov     %i0, %o0
F0018798: 40000717                 call    _ttyecho
F001879C: 92100019                 mov     %i1, %o1
F00187A0: d00c604f                 ldub    [%l1+0x4F], %o0
F00187A4: 92102003                 mov     3, %o1
F00187A8: 80a40008                 cmp     %l0, %o0
F00187AC: 12800003                 bne     loc_F00187B8
F00187B0: d4546044                 ldsh    [%l1+0x44], %o2
F00187B4: 92102002                 mov     2, %o1
F00187B8: 7fffe349                 call    _gsignal
F00187BC: 9010000a                 mov     %o2, %o0
F00187C0: 108001db                 ba      loc_F0018F2C
F00187C4: 808ca010                 btst    0x10, %l2
F00187C8: 80a260ff                 cmp     %o1, 0xFF
F00187CC: 02800014                 be      loc_F001881C
F00187D0: 11010000                 sethi   0x4000000, %o0
F00187D4: d00c6055                 ldub    [%l1+0x55], %o0
F00187D8: 80a24008                 cmp     %o1, %o0
F00187DC: 32800010                 bne,a   loc_F001881C
F00187E0: 11010000                 sethi   0x4000000, %o0
F00187E4: 80a4e000                 cmp     %l3, 0
F00187E8: 06800004                 bl      loc_F00187F8
F00187EC: 90100011                 mov     %l1, %o0
F00187F0: 7ffff890                 call    _ttyflush
F00187F4: 92102001                 mov     1, %o1
F00187F8: 90100018                 mov     %i0, %o0
F00187FC: 400006fe                 call    _ttyecho
F0018800: 92100019                 mov     %i1, %o1
F0018804: d0546044                 ldsh    [%l1+0x44], %o0
F0018808: 7fffe335                 call    _gsignal
F001880C: 92102012                 mov     0x12, %o1
F0018810: 108001c7                 ba      loc_F0018F2C
F0018814: 808ca010                 btst    0x10, %l2
F0018818: 11010000                 sethi   0x4000000, %o0
F001881C: 808c8008                 btst    %o0, %l2
F0018820: 02800028                 be      loc_F00188C0
F0018824: 920e20ff                 and     %i0, 0xFF, %o1
F0018828: 80a260ff                 cmp     %o1, 0xFF
F001882C: 02800026                 be      loc_F00188C4
F0018830: 80a6200d                 cmp     %i0, 0xD
F0018834: d00c6052                 ldub    [%l1+0x52], %o0
F0018838: 80a24008                 cmp     %o1, %o0
F001883C: 1280001b                 bne     loc_F00188A8
F0018840: 80a260ff                 cmp     %o1, 0xFF
F0018844: d0046040                 ld      [%l1+0x40], %o0
F0018848: 808a2100                 btst    0x100, %o0
F001884C: 32800013                 bne,a   loc_F0018898
F0018850: d00c6051                 ldub    [%l1+0x51], %o0
F0018854: 90122100                 bset    0x100, %o0
F0018858: d4146038                 lduh    [%l1+0x38], %o2
F001885C: d0246040                 st      %o0, [%l1+0x40]
F0018860: 9532a008                 srl     %o2, 8, %o2
F0018864: 932aa001                 sll     %o2, 1, %o1
F0018868: 9202400a                 add     %o1, %o2, %o1
F001886C: 932a6002                 sll     %o1, 2, %o1
F0018870: 9222400a                 sub     %o1, %o2, %o1
F0018874: 932a6002                 sll     %o1, 2, %o1
F0018878: 153c04729412a1f0         set     _cdevsw, %o2
F0018880: 9202400a                 add     %o1, %o2, %o1
F0018884: d4026014                 ld      [%o1+0x14], %o2
F0018888: 90100011                 mov     %l1, %o0
F001888C: 9fc28000                 call    %o2
F0018890: 92102000                 mov     0, %o1
F0018894: 308001bd                 ba,a    locret_F0018F88
F0018898: 80a24008                 cmp     %o1, %o0
F001889C: 128001bb                 bne     locret_F0018F88
F00188A0: 808ca010                 btst    0x10, %l2
F00188A4: 308001a2                 ba,a    loc_F0018F2C
F00188A8: 02800007                 be      loc_F00188C4
F00188AC: 80a6200d                 cmp     %i0, 0xD
F00188B0: d00c6051                 ldub    [%l1+0x51], %o0
F00188B4: 80a24008                 cmp     %o1, %o0
F00188B8: 228001ae                 be,a    loc_F0018F70
F00188BC: d0046040                 ld      [%l1+0x40], %o0
F00188C0: 80a6200d                 cmp     %i0, 0xD
F00188C4: 1280000f                 bne     loc_F0018900
F00188C8: 80a6200a                 cmp     %i0, 0xA
F00188CC: 11004000                 sethi   0x1000000, %o0
F00188D0: 808c8008                 btst    %o0, %l2
F00188D4: 12800196                 bne     loc_F0018F2C
F00188D8: 808ca010                 btst    0x10, %l2
F00188DC: 808ce010                 btst    0x10, %l3
F00188E0: 3280000e                 bne,a   loc_F0018918
F00188E4: b010200a                 mov     0xA, %i0
F00188E8: 11008000                 sethi   0x2000000, %o0
F00188EC: 808c8008                 btst    %o0, %l2
F00188F0: 0280000b                 be      loc_F001891C
F00188F4: 808ce004                 btst    4, %l3
F00188F8: 10800009                 ba      loc_F001891C
F00188FC: b010200a                 mov     0xA, %i0
F0018900: 12800007                 bne     loc_F001891C
F0018904: 808ce004                 btst    4, %l3
F0018908: 11002000                 sethi   0x800000, %o0
F001890C: 808c8008                 btst    %o0, %l2
F0018910: 32800002                 bne,a   loc_F0018918
F0018914: b010200d                 mov     0xD, %i0
F0018918: 808ce004                 btst    4, %l3
F001891C: 02800025                 be      loc_F00189B0
F0018920: 80a6207f                 cmp     %i0, 0x7F
F0018924: 14800024                 bg      loc_F00189B4
F0018928: 808ce022                 btst    0x22, %l3 ! '"'
F001892C: d2046040                 ld      [%l1+0x40], %o1
F0018930: 15000040                 sethi   0x10000, %o2
F0018934: 808a400a                 btst    %o2, %o1
F0018938: 02800015                 be      loc_F001898C
F001893C: 90063fbf                 add     %i0, -0x41, %o0
F0018940: 40001157                 call    _unputc
F0018944: 90100011                 mov     %l1, %o0
F0018948: 400005d0                 call    _ttyrub
F001894C: 92100019                 mov     %i1, %o1
F0018950: 113c042d901222a0         set     _maptab, %o0
F0018958: d04e0008                 ldsb    [%i0+%o0], %o0
F001895C: 80a22000                 cmp     %o0, 0
F0018960: 32800002                 bne,a   loc_F0018968
F0018964: b0100008                 mov     %o0, %i0
F0018968: b0162100                 bset    0x100, %i0
F001896C: 808ce022                 btst    0x22, %l3 ! '"'
F0018970: d2046040                 ld      [%l1+0x40], %o1
F0018974: 110000c0                 sethi   0x30000, %o0
F0018978: 902a4008                 andn    %o1, %o0, %o0
F001897C: 12800010                 bne     loc_F00189BC
F0018980: d0246040                 st      %o0, [%l1+0x40]
F0018984: 108000f3                 ba      loc_F0018D50
F0018988: d0044000                 ld      [%l1], %o0
F001898C: 80a22019                 cmp     %o0, 0x19
F0018990: 18800004                 bgu     loc_F00189A0
F0018994: 80a6205c                 cmp     %i0, 0x5C ! '\'
F0018998: 10800006                 ba      loc_F00189B0
F001899C: b0062020                 inc     0x20, %i0 ! ' '
F00189A0: 12800005                 bne     loc_F00189B4
F00189A4: 808ce022                 btst    0x22, %l3 ! '"'
F00189A8: 9012400a                 or      %o1, %o2, %o0
F00189AC: d0246040                 st      %o0, [%l1+0x40]
F00189B0: 808ce022                 btst    0x22, %l3 ! '"'
F00189B4: 2280002e                 be,a    loc_F0018A6C
F00189B8: d2046040                 ld      [%l1+0x40], %o1
F00189BC: d0044000                 ld      [%l1], %o0
F00189C0: 80a22400                 cmp     %o0, 0x400
F00189C4: 04800018                 ble     loc_F0018A24
F00189C8: 113c042d                 sethi   %hi(_tthiwat), %o0
F00189CC: d20c604a                 ldub    [%l1+0x4A], %o1
F00189D0: 90122320                 bset    %lo(_tthiwat), %o0
F00189D4: 920a601f                 and     %o1, 0x1F, %o1
F00189D8: 932a6001                 sll     %o1, 1, %o1
F00189DC: d2524008                 ldsh    [%o1+%o0], %o1
F00189E0: d0046018                 ld      [%l1+0x18], %o0
F00189E4: 80a20009                 cmp     %o0, %o1
F00189E8: 16800009                 bge     loc_F0018A0C
F00189EC: 90102004                 mov     4, %o0
F00189F0: 11020000                 sethi   0x8000000, %o0
F00189F4: 808c8008                 btst    %o0, %l2
F00189F8: 02800004                 be      loc_F0018A08
F00189FC: 90102007                 mov     7, %o0
F0018A00: 40000164                 call    _ttyoutput
F0018A04: 92100011                 mov     %l1, %o1
F0018A08: 90102004                 mov     4, %o0! __x
F0018A0C: d4546038                 ldsh    [%l1+0x38], %o2
F0018A10: 133c042e                 sethi   %hi(aTtyDCbreakInpu), %o1! "tty%d: cbreak input overrun\n"
F0018A14: 7fffef68                 call    _log
F0018A18: 92126040                 bset    %lo(aTtyDCbreakInpu), %o1! "tty%d: cbreak input overrun\n"
F0018A1C: 10800144                 ba      loc_F0018F2C
F0018A20: 808ca010                 btst    0x10, %l2
F0018A24: 90100018                 mov     %i0, %o0! int
F0018A28: 4000104a                 call    _putc
F0018A2C: 92100011                 mov     %l1, %o1
F0018A30: 80a22000                 cmp     %o0, 0
F0018A34: 0680013e                 bl      loc_F0018F2C
F0018A38: 808ca010                 btst    0x10, %l2
F0018A3C: 400006c9                 call    _ttcheckwakeup
F0018A40: 90100019                 mov     %i1, %o0
F0018A44: 80a22000                 cmp     %o0, 0
F0018A48: 02800005                 be      loc_F0018A5C
F0018A4C: 90100018                 mov     %i0, %o0
F0018A50: 400006d5                 call    _ttwakeup
F0018A54: 90100011                 mov     %l1, %o0
F0018A58: 90100018                 mov     %i0, %o0
F0018A5C: 40000666                 call    _ttyecho
F0018A60: 92100019                 mov     %i1, %o1
F0018A64: 10800132                 ba      loc_F0018F2C
F0018A68: 808ca010                 btst    0x10, %l2
F0018A6C: 11000080                 sethi   0x20000, %o0
F0018A70: 808a4008                 btst    %o0, %o1
F0018A74: 02800013                 be      loc_F0018AC0
F0018A78: 920e20ff                 and     %i0, 0xFF, %o1
F0018A7C: 80a260ff                 cmp     %o1, 0xFF
F0018A80: 02800035                 be      loc_F0018B54
F0018A84: 01000000                 nop
F0018A88: d00c604d                 ldub    [%l1+0x4D], %o0
F0018A8C: 80a24008                 cmp     %o1, %o0
F0018A90: 02800006                 be      loc_F0018AA8
F0018A94: 01000000                 nop
F0018A98: d00c604e                 ldub    [%l1+0x4E], %o0
F0018A9C: 80a24008                 cmp     %o1, %o0
F0018AA0: 12800009                 bne     loc_F0018AC4
F0018AA4: 80a260ff                 cmp     %o1, 0xFF
F0018AA8: 400010fd                 call    _unputc
F0018AAC: 90100011                 mov     %l1, %o0
F0018AB0: 40000576                 call    _ttyrub
F0018AB4: 92100019                 mov     %i1, %o1
F0018AB8: 108000a5                 ba      loc_F0018D4C
F0018ABC: b0162100                 bset    0x100, %i0
F0018AC0: 80a260ff                 cmp     %o1, 0xFF
F0018AC4: 22800024                 be,a    loc_F0018B54
F0018AC8: 920e20ff                 and     %i0, 0xFF, %o1
F0018ACC: d00c604d                 ldub    [%l1+0x4D], %o0
F0018AD0: 80a24008                 cmp     %o1, %o0
F0018AD4: 32800020                 bne,a   loc_F0018B54
F0018AD8: 920e20ff                 and     %i0, 0xFF, %o1
F0018ADC: d0044000                 ld      [%l1], %o0
F0018AE0: 80a22000                 cmp     %o0, 0
F0018AE4: 02800112                 be      loc_F0018F2C
F0018AE8: 808ca010                 btst    0x10, %l2
F0018AEC: 400010ec                 call    _unputc
F0018AF0: 90100011                 mov     %l1, %o0
F0018AF4: b0100008                 mov     %o0, %i0
F0018AF8: 40000564                 call    _ttyrub
F0018AFC: 92100019                 mov     %i1, %o1
F0018B00: 11000200                 sethi   0x80000, %o0
F0018B04: 808cc008                 btst    %o0, %l3
F0018B08: 02800108                 be      loc_F0018F28
F0018B0C: 808e2080                 btst    0x80, %i0
F0018B10: 02800107                 be      loc_F0018F2C
F0018B14: 808ca010                 btst    0x10, %l2
F0018B18: d0044000                 ld      [%l1], %o0
F0018B1C: 80a22000                 cmp     %o0, 0
F0018B20: 02800103                 be      loc_F0018F2C
F0018B24: 808ca010                 btst    0x10, %l2
F0018B28: 400010dd                 call    _unputc
F0018B2C: 90100011                 mov     %l1, %o0
F0018B30: b0100008                 mov     %o0, %i0
F0018B34: 900e20ff                 and     %i0, 0xFF, %o0
F0018B38: 80a2208e                 cmp     %o0, 0x8E
F0018B3C: 028000fb                 be      loc_F0018F28
F0018B40: 90100018                 mov     %i0, %o0
F0018B44: 40000551                 call    _ttyrub
F0018B48: 92100019                 mov     %i1, %o1
F0018B4C: 108000f8                 ba      loc_F0018F2C
F0018B50: 808ca010                 btst    0x10, %l2
F0018B54: 80a260ff                 cmp     %o1, 0xFF
F0018B58: 22800031                 be,a    loc_F0018C1C
F0018B5C: 920e20ff                 and     %i0, 0xFF, %o1
F0018B60: d00c604e                 ldub    [%l1+0x4E], %o0
F0018B64: 80a24008                 cmp     %o1, %o0
F0018B68: 3280002d                 bne,a   loc_F0018C1C
F0018B6C: 920e20ff                 and     %i0, 0xFF, %o1
F0018B70: 808ca004                 btst    4, %l2
F0018B74: 02800017                 be      loc_F0018BD0
F0018B78: 11010000                 sethi   0x4000000, %o0
F0018B7C: 808cc008                 btst    %o0, %l3
F0018B80: 02800015                 be      loc_F0018BD4
F0018B84: 90100018                 mov     %i0, %o0
F0018B88: d04c604b                 ldsb    [%l1+0x4B], %o0
F0018B8C: d2044000                 ld      [%l1], %o1
F0018B90: 80a24008                 cmp     %o1, %o0
F0018B94: 32800010                 bne,a   loc_F0018BD4
F0018B98: 90100018                 mov     %i0, %o0
F0018B9C: 80a26000                 cmp     %o1, 0
F0018BA0: 2280001b                 be,a    loc_F0018C0C
F0018BA4: d2046040                 ld      [%l1+0x40], %o1
F0018BA8: 400010bd                 call    _unputc
F0018BAC: 90100011                 mov     %l1, %o0
F0018BB0: 40000536                 call    _ttyrub
F0018BB4: 92100019                 mov     %i1, %o1
F0018BB8: d0044000                 ld      [%l1], %o0
F0018BBC: 80a22000                 cmp     %o0, 0
F0018BC0: 12bffffa                 bne     loc_F0018BA8
F0018BC4: 01000000                 nop
F0018BC8: 10800011                 ba      loc_F0018C0C
F0018BCC: d2046040                 ld      [%l1+0x40], %o1
F0018BD0: 90100018                 mov     %i0, %o0
F0018BD4: 40000608                 call    _ttyecho
F0018BD8: 92100019                 mov     %i1, %o1
F0018BDC: 808ca004                 btst    4, %l2
F0018BE0: 02800004                 be      loc_F0018BF0
F0018BE4: 9010200a                 mov     0xA, %o0! FILE *
F0018BE8: 40000603                 call    _ttyecho
F0018BEC: 92100019                 mov     %i1, %o1
F0018BF0: 40000eb6                 call    _getc
F0018BF4: 90100011                 mov     %l1, %o0
F0018BF8: 80a22000                 cmp     %o0, 0
F0018BFC: 14bffffd                 bg      loc_F0018BF0
F0018C00: 01000000                 nop
F0018C04: c02c604b                 clrb    [%l1+0x4B]
F0018C08: d2046040                 ld      [%l1+0x40], %o1
F0018C0C: 11000fc0                 sethi   0x3F0000, %o0
F0018C10: 902a4008                 andn    %o1, %o0, %o0
F0018C14: 108000c5                 ba      loc_F0018F28
F0018C18: d0246040                 st      %o0, [%l1+0x40]
F0018C1C: 80a260ff                 cmp     %o1, 0xFF
F0018C20: 22800040                 be,a    loc_F0018D20
F0018C24: 920e20ff                 and     %i0, 0xFF, %o1
F0018C28: d00c6059                 ldub    [%l1+0x59], %o0
F0018C2C: 80a24008                 cmp     %o1, %o0
F0018C30: 1280003c                 bne     loc_F0018D20
F0018C34: 920e20ff                 and     %i0, 0xFF, %o1
F0018C38: aa0ca020                 and     %l2, 0x20, %l5
F0018C3C: 40001098                 call    _unputc
F0018C40: 90100011                 mov     %l1, %o0
F0018C44: b0100008                 mov     %o0, %i0
F0018C48: 80a62020                 cmp     %i0, 0x20 ! ' '
F0018C4C: 02800004                 be      loc_F0018C5C
F0018C50: 80a62009                 cmp     %i0, 9
F0018C54: 12800006                 bne     loc_F0018C6C
F0018C58: 80a63fff                 cmp     %i0, -1
F0018C5C: 90100018                 mov     %i0, %o0
F0018C60: 4000050a                 call    _ttyrub
F0018C64: 92100019                 mov     %i1, %o1
F0018C68: 30bffff5                 ba,a    loc_F0018C3C
F0018C6C: 028000af                 be      loc_F0018F28
F0018C70: 90100018                 mov     %i0, %o0
F0018C74: 40000505                 call    _ttyrub
F0018C78: 92100019                 mov     %i1, %o1
F0018C7C: 40001088                 call    _unputc
F0018C80: 90100011                 mov     %l1, %o0
F0018C84: b0100008                 mov     %o0, %i0
F0018C88: 80a63fff                 cmp     %i0, -1
F0018C8C: 028000a7                 be      loc_F0018F28
F0018C90: 900e20ff                 and     %i0, 0xFF, %o0
F0018C94: 133c042d921261a0         set     _partab, %o1
F0018C9C: d00a0009                 ldub    [%o0+%o1], %o0
F0018CA0: 80a62020                 cmp     %i0, 0x20 ! ' '
F0018CA4: 0280001a                 be      loc_F0018D0C
F0018CA8: a00a2040                 and     %o0, 0x40, %l0
F0018CAC: 80a62009                 cmp     %i0, 9
F0018CB0: 02800017                 be      loc_F0018D0C
F0018CB4: a8100009                 mov     %o1, %l4
F0018CB8: 80a56000                 cmp     %l5, 0
F0018CBC: 02800008                 be      loc_F0018CDC
F0018CC0: 90100018                 mov     %i0, %o0
F0018CC4: 900e20ff                 and     %i0, 0xFF, %o0
F0018CC8: d00a0014                 ldub    [%o0+%l4], %o0
F0018CCC: 900a2040                 and     %o0, 0x40, %o0
F0018CD0: 80a20010                 cmp     %o0, %l0
F0018CD4: 1280000e                 bne     loc_F0018D0C
F0018CD8: 90100018                 mov     %i0, %o0
F0018CDC: 400004eb                 call    _ttyrub
F0018CE0: 92100019                 mov     %i1, %o1! FILE *
F0018CE4: 4000106e                 call    _unputc
F0018CE8: 90100011                 mov     %l1, %o0
F0018CEC: b0100008                 mov     %o0, %i0
F0018CF0: 80a63fff                 cmp     %i0, -1
F0018CF4: 0280008d                 be      loc_F0018F28
F0018CF8: 80a62020                 cmp     %i0, 0x20 ! ' '
F0018CFC: 02800004                 be      loc_F0018D0C
F0018D00: 80a62009                 cmp     %i0, 9
F0018D04: 12bfffee                 bne     loc_F0018CBC
F0018D08: 80a56000                 cmp     %l5, 0
F0018D0C: 90100018                 mov     %i0, %o0! int
F0018D10: 40000f90                 call    _putc
F0018D14: 92100011                 mov     %l1, %o1
F0018D18: 10800085                 ba      loc_F0018F2C
F0018D1C: 808ca010                 btst    0x10, %l2
F0018D20: 80a260ff                 cmp     %o1, 0xFF
F0018D24: 2280000b                 be,a    loc_F0018D50
F0018D28: d0044000                 ld      [%l1], %o0
F0018D2C: d00c6057                 ldub    [%l1+0x57], %o0
F0018D30: 80a24008                 cmp     %o1, %o0
F0018D34: 32800007                 bne,a   loc_F0018D50
F0018D38: d0044000                 ld      [%l1], %o0
F0018D3C: 4000057b                 call    _ttyretype
F0018D40: 90100019                 mov     %i1, %o0
F0018D44: 1080007a                 ba      loc_F0018F2C
F0018D48: 808ca010                 btst    0x10, %l2
F0018D4C: d0044000                 ld      [%l1], %o0
F0018D50: d204600c                 ld      [%l1+0xC], %o1
F0018D54: 90020009                 add     %o0, %o1, %o0
F0018D58: 80a223ff                 cmp     %o0, 0x3FF
F0018D5C: 04800018                 ble     loc_F0018DBC
F0018D60: 11020000                 sethi   0x8000000, %o0
F0018D64: 808c8008                 btst    %o0, %l2
F0018D68: 0280000e                 be      loc_F0018DA0
F0018D6C: 113c042d                 sethi   %hi(_tthiwat), %o0
F0018D70: d20c604a                 ldub    [%l1+0x4A], %o1
F0018D74: 90122320                 bset    %lo(_tthiwat), %o0
F0018D78: 920a601f                 and     %o1, 0x1F, %o1
F0018D7C: 932a6001                 sll     %o1, 1, %o1
F0018D80: d2524008                 ldsh    [%o1+%o0], %o1
F0018D84: d0046018                 ld      [%l1+0x18], %o0
F0018D88: 80a20009                 cmp     %o0, %o1
F0018D8C: 16800006                 bge     loc_F0018DA4
F0018D90: 90102004                 mov     4, %o0
F0018D94: 90102007                 mov     7, %o0
F0018D98: 4000007e                 call    _ttyoutput
F0018D9C: 92100011                 mov     %l1, %o1
F0018DA0: 90102004                 mov     4, %o0! __x
F0018DA4: d4546038                 ldsh    [%l1+0x38], %o2
F0018DA8: 133c042e                 sethi   %hi(aTtyDCanonInput), %o1! "tty%d: canon input overrun\n"
F0018DAC: 7fffee82                 call    _log
F0018DB0: 92126060                 bset    %lo(aTtyDCanonInput), %o1! "tty%d: canon input overrun\n"
F0018DB4: 1080005e                 ba      loc_F0018F2C
F0018DB8: 808ca010                 btst    0x10, %l2
F0018DBC: 90100018                 mov     %i0, %o0! int
F0018DC0: 40000f64                 call    _putc
F0018DC4: 92100011                 mov     %l1, %o1
F0018DC8: 80a22000                 cmp     %o0, 0
F0018DCC: 06800057                 bl      loc_F0018F28
F0018DD0: 80a6200a                 cmp     %i0, 0xA
F0018DD4: 2280000e                 be,a    loc_F0018E0C
F0018DD8: c02c604b                 clrb    [%l1+0x4B]
F0018DDC: d00c6053                 ldub    [%l1+0x53], %o0
F0018DE0: 80a60008                 cmp     %i0, %o0
F0018DE4: 02800007                 be      loc_F0018E00
F0018DE8: 80a620ff                 cmp     %i0, 0xFF
F0018DEC: d00c6054                 ldub    [%l1+0x54], %o0
F0018DF0: 80a60008                 cmp     %i0, %o0
F0018DF4: 3280000d                 bne,a   loc_F0018E28
F0018DF8: d20c604b                 ldub    [%l1+0x4B], %o1
F0018DFC: 80a620ff                 cmp     %i0, 0xFF
F0018E00: 2280000a                 be,a    loc_F0018E28
F0018E04: d20c604b                 ldub    [%l1+0x4B], %o1
F0018E08: c02c604b                 clrb    [%l1+0x4B]
F0018E0C: 90100011                 mov     %l1, %o0
F0018E10: 40001072                 call    _catq
F0018E14: 9204600c                 add     %l1, 0xC, %o1
F0018E18: 400005e3                 call    _ttwakeup
F0018E1C: 90100011                 mov     %l1, %o0
F0018E20: 10800009                 ba      loc_F0018E44
F0018E24: d0046040                 ld      [%l1+0x40], %o0
F0018E28: 90026001                 add     %o1, 1, %o0
F0018E2C: 80a26000                 cmp     %o1, 0
F0018E30: 12800004                 bne     loc_F0018E40
F0018E34: d02c604b                 stb     %o0, [%l1+0x4B]
F0018E38: d00c6048                 ldub    [%l1+0x48], %o0
F0018E3C: d02c604c                 stb     %o0, [%l1+0x4C]
F0018E40: d0046040                 ld      [%l1+0x40], %o0
F0018E44: 13000080                 sethi   0x20000, %o1
F0018E48: 922a0009                 andn    %o0, %o1, %o1
F0018E4C: 11001000                 sethi   0x400000, %o0
F0018E50: 808a4008                 btst    %o0, %o1
F0018E54: 12800035                 bne     loc_F0018F28
F0018E58: d2246040                 st      %o1, [%l1+0x40]
F0018E5C: 940e20ff                 and     %i0, 0xFF, %o2
F0018E60: 80a2a0ff                 cmp     %o2, 0xFF
F0018E64: 2280000a                 be,a    loc_F0018E8C
F0018E68: d2046040                 ld      [%l1+0x40], %o1
F0018E6C: d00e6014                 ldub    [%i1+0x14], %o0
F0018E70: 80a28008                 cmp     %o2, %o0
F0018E74: 32800006                 bne,a   loc_F0018E8C
F0018E78: d2046040                 ld      [%l1+0x40], %o1
F0018E7C: 1100008090124008         set     0x20000, %o0
F0018E84: d0246040                 st      %o0, [%l1+0x40]
F0018E88: d2046040                 ld      [%l1+0x40], %o1
F0018E8C: 11000100                 sethi   0x40000, %o0
F0018E90: 808a4008                 btst    %o0, %o1
F0018E94: 02800006                 be      loc_F0018EAC
F0018E98: 902a4008                 andn    %o1, %o0, %o0
F0018E9C: d0246040                 st      %o0, [%l1+0x40]
F0018EA0: 9010202f                 mov     0x2F, %o0 ! '/'
F0018EA4: 4000003b                 call    _ttyoutput
F0018EA8: 92100011                 mov     %l1, %o1
F0018EAC: e04c6048                 ldsb    [%l1+0x48], %l0
F0018EB0: 90100018                 mov     %i0, %o0
F0018EB4: 40000550                 call    _ttyecho
F0018EB8: 92100019                 mov     %i1, %o1
F0018EBC: 920e20ff                 and     %i0, 0xFF, %o1
F0018EC0: 80a260ff                 cmp     %o1, 0xFF
F0018EC4: 0280001a                 be      loc_F0018F2C
F0018EC8: 808ca010                 btst    0x10, %l2
F0018ECC: d00c6053                 ldub    [%l1+0x53], %o0
F0018ED0: 80a24008                 cmp     %o1, %o0
F0018ED4: 12800016                 bne     loc_F0018F2C
F0018ED8: 808ca010                 btst    0x10, %l2
F0018EDC: 808ce008                 btst    8, %l3
F0018EE0: 02800013                 be      loc_F0018F2C
F0018EE4: 808ca010                 btst    0x10, %l2
F0018EE8: d04c6048                 ldsb    [%l1+0x48], %o0
F0018EEC: 90220010                 sub     %o0, %l0, %o0
F0018EF0: 80a22002                 cmp     %o0, 2
F0018EF4: 14800003                 bg      loc_F0018F00
F0018EF8: 92102002                 mov     2, %o1
F0018EFC: 92100008                 mov     %o0, %o1
F0018F00: a0924000                 orcc    %o1, %g0, %l0
F0018F04: 0480000a                 ble     loc_F0018F2C
F0018F08: 808ca010                 btst    0x10, %l2
F0018F0C: 90102008                 mov     8, %o0
F0018F10: 40000020                 call    _ttyoutput
F0018F14: 92100011                 mov     %l1, %o1
F0018F18: a0043fff                 inc     -1, %l0
F0018F1C: 80a42000                 cmp     %l0, 0
F0018F20: 14bffffc                 bg      loc_F0018F10
F0018F24: 90102008                 mov     8, %o0
F0018F28: 808ca010                 btst    0x10, %l2
F0018F2C: 02800017                 be      locret_F0018F88
F0018F30: 11100000                 sethi   0x40000000, %o0
F0018F34: 808cc008                 btst    %o0, %l3
F0018F38: 0280000e                 be      loc_F0018F70
F0018F3C: d0046040                 ld      [%l1+0x40], %o0
F0018F40: 808a2100                 btst    0x100, %o0
F0018F44: 2280000c                 be,a    loc_F0018F74
F0018F48: d204603c                 ld      [%l1+0x3C], %o1
F0018F4C: d20c6052                 ldub    [%l1+0x52], %o1
F0018F50: 80a260ff                 cmp     %o1, 0xFF
F0018F54: 0280000d                 be      locret_F0018F88
F0018F58: 01000000                 nop
F0018F5C: d00c6051                 ldub    [%l1+0x51], %o0
F0018F60: 80a24008                 cmp     %o1, %o0
F0018F64: 12800009                 bne     locret_F0018F88
F0018F68: 01000000                 nop
F0018F6C: d0046040                 ld      [%l1+0x40], %o0
F0018F70: d204603c                 ld      [%l1+0x3C], %o1
F0018F74: 900a3eff                 and     %o0, -0x101, %o0
F0018F78: d0246040                 st      %o0, [%l1+0x40]
F0018F7C: 11002000                 sethi   0x800000, %o0
F0018F80: 902a4008                 andn    %o1, %o0, %o0
F0018F84: d024603c                 st      %o0, [%l1+0x3C]
F0018F88: 81c7e008                 ret
F0018F8C: 81e80000                 restore
