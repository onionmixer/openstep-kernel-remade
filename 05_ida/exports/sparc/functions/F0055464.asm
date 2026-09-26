F0055464: 9de3bf78                 save    %sp, -0x88, %sp
F0055468: b6100018                 mov     %i0, %i3
F005546C: b810001a                 mov     %i2, %i4
F0055470: d206c000                 ld      [%i3], %o1
F0055474: 80a72000                 cmp     %i4, 0
F0055478: ea06e008                 ld      [%i3+8], %l5
F005547C: 11100000                 sethi   0x40000000, %o0
F0055480: e806e00c                 ld      [%i3+0xC], %l4
F0055484: 128000ea                 bne     loc_F005582C
F0055488: b42a4008                 andn    %o1, %o0, %i2
F005548C: 1100003f901223ff         set     0xFFFF, %o0
F0055494: 920e8008                 and     %i2, %o0, %o1
F0055498: 80a26013                 cmp     %o1, 0x13
F005549C: 2280000f                 be,a    loc_F00554D8
F00554A0: 80a52000                 cmp     %l4, 0
F00554A4: 18800006                 bgu     loc_F00554BC
F00554A8: 80a26012                 cmp     %o1, 0x12
F00554AC: 028000a0                 be      loc_F005572C
F00554B0: 80a52000                 cmp     %l4, 0
F00554B4: 108000df                 ba      loc_F0055830
F00554B8: a60ea0ff                 and     %i2, 0xFF, %l3
F00554BC: 1100000590122113         set     0x1513, %o0
F00554C4: 80a24008                 cmp     %o1, %o0
F00554C8: 02800041                 be      loc_F00555CC
F00554CC: b0066008                 add     %i1, 8, %i0
F00554D0: 108000d8                 ba      loc_F0055830
F00554D4: a60ea0ff                 and     %i2, 0xFF, %l3
F00554D8: 128000d6                 bne     loc_F0055830
F00554DC: a60ea0ff                 and     %i2, 0xFF, %l3
F00554E0: b0066008                 add     %i1, 8, %i0
F00554E4: d0060000                 ld      [%i0], %o0
F00554E8: 80a22000                 cmp     %o0, 0
F00554EC: 12bffffe                 bne     loc_F00554E4
F00554F0: 01000000                 nop
F00554F4: 4001066d                 call    _simple_lock_try
F00554F8: 90100018                 mov     %i0, %o0
F00554FC: 80a22000                 cmp     %o0, 0
F0055500: 02bffff9                 be      loc_F00554E4
F0055504: 01000000                 nop
F0055508: d006600c                 ld      [%i1+0xC], %o0
F005550C: 80a22000                 cmp     %o0, 0
F0055510: 028000c6                 be      loc_F0055828
F0055514: 95356008                 srl     %l5, 8, %o2
F0055518: d0066018                 ld      [%i1+0x18], %o0
F005551C: 80a28008                 cmp     %o2, %o0
F0055520: 1a8000c2                 bcc     loc_F0055828
F0055524: 992d6018                 sll     %l5, 24, %o4
F0055528: d6066014                 ld      [%i1+0x14], %o3
F005552C: 952aa004                 sll     %o2, 4, %o2
F0055530: d202c00a                 ld      [%o3+%o2], %o1
F0055534: 113fc040                 sethi   -0xFF0000, %o0
F0055538: 920a4008                 and     %o1, %o0, %o1
F005553C: 1100004090130008         set     0x10000, %o0
F0055544: 80a24008                 cmp     %o1, %o0
F0055548: 128000b8                 bne     loc_F0055828
F005554C: 9002c00a                 add     %o3, %o2, %o0
F0055550: f0022004                 ld      [%o0+4], %i0
F0055554: d0060000                 ld      [%i0], %o0
F0055558: 80a22000                 cmp     %o0, 0
F005555C: 12bffffe                 bne     loc_F0055554
F0055560: 01000000                 nop
F0055564: 40010651                 call    _simple_lock_try
F0055568: 90100018                 mov     %i0, %o0
F005556C: 80a22000                 cmp     %o0, 0
F0055570: 02bffff9                 be      loc_F0055554
F0055574: 01000000                 nop
F0055578: c0266008                 clr     [%i1+8]
F005557C: d0062008                 ld      [%i0+8], %o0
F0055580: 80a22000                 cmp     %o0, 0
F0055584: 26800005                 bl,a    loc_F0055598
F0055588: d006201c                 ld      [%i0+0x1C], %o0
F005558C: c0260000                 clr     [%i0]
F0055590: 108000a8                 ba      loc_F0055830
F0055594: a60ea0ff                 and     %i2, 0xFF, %l3
F0055598: 90022001                 inc     %o0
F005559C: d026201c                 st      %o0, [%i0+0x1C]
F00555A0: d0062004                 ld      [%i0+4], %o0
F00555A4: 90022001                 inc     %o0
F00555A8: d0262004                 st      %o0, [%i0+4]
F00555AC: c0260000                 clr     [%i0]
F00555B0: 113fffc0                 sethi   -0x10000, %o0
F00555B4: 900e8008                 and     %i2, %o0, %o0
F00555B8: 90122011                 bset    0x11, %o0
F00555BC: d026c000                 st      %o0, [%i3]
F00555C0: f026e008                 st      %i0, [%i3+8]
F00555C4: 10800221                 ba      locret_F0055E48
F00555C8: b0102000                 mov     0, %i0
F00555CC: d0060000                 ld      [%i0], %o0
F00555D0: 80a22000                 cmp     %o0, 0
F00555D4: 12bffffe                 bne     loc_F00555CC
F00555D8: 01000000                 nop
F00555DC: 40010633                 call    _simple_lock_try
F00555E0: 90100018                 mov     %i0, %o0
F00555E4: 80a22000                 cmp     %o0, 0
F00555E8: 02bffff9                 be      loc_F00555CC
F00555EC: 01000000                 nop
F00555F0: d006600c                 ld      [%i1+0xC], %o0
F00555F4: 80a22000                 cmp     %o0, 0
F00555F8: 0280008c                 be      loc_F0055828
F00555FC: 91356008                 srl     %l5, 8, %o0
F0055600: da066018                 ld      [%i1+0x18], %o5
F0055604: 992d6018                 sll     %l5, 24, %o4
F0055608: 80a2000d                 cmp     %o0, %o5
F005560C: 1a800087                 bcc     loc_F0055828
F0055610: d4066014                 ld      [%i1+0x14], %o2
F0055614: 912a2004                 sll     %o0, 4, %o0
F0055618: 96028008                 add     %o2, %o0, %o3
F005561C: d0028008                 ld      [%o2+%o0], %o0
F0055620: 133fc040                 sethi   -0xFF0000, %o1
F0055624: 920a0009                 and     %o0, %o1, %o1
F0055628: 1100004090130008         set     0x10000, %o0
F0055630: 80a24008                 cmp     %o1, %o0
F0055634: 1280007d                 bne     loc_F0055828
F0055638: 91352008                 srl     %l4, 8, %o0
F005563C: 80a2000d                 cmp     %o0, %o5
F0055640: f002e004                 ld      [%o3+4], %i0
F0055644: 1a800079                 bcc     loc_F0055828
F0055648: 992d2018                 sll     %l4, 24, %o4
F005564C: 912a2004                 sll     %o0, 4, %o0
F0055650: 96028008                 add     %o2, %o0, %o3
F0055654: d0028008                 ld      [%o2+%o0], %o0
F0055658: 133fc080                 sethi   -0xFE0000, %o1
F005565C: 920a0009                 and     %o0, %o1, %o1
F0055660: 1100008090130008         set     0x20000, %o0
F0055668: 80a24008                 cmp     %o1, %o0
F005566C: 1280006f                 bne     loc_F0055828
F0055670: 01000000                 nop
F0055674: e002e004                 ld      [%o3+4], %l0
F0055678: d0060000                 ld      [%i0], %o0
F005567C: 80a22000                 cmp     %o0, 0
F0055680: 12bffffe                 bne     loc_F0055678
F0055684: 01000000                 nop
F0055688: 40010608                 call    _simple_lock_try
F005568C: 90100018                 mov     %i0, %o0
F0055690: 80a22000                 cmp     %o0, 0
F0055694: 02bffff9                 be      loc_F0055678
F0055698: 01000000                 nop
F005569C: d0062008                 ld      [%i0+8], %o0
F00556A0: 80a22000                 cmp     %o0, 0
F00556A4: 16800007                 bge     loc_F00556C0
F00556A8: 01000000                 nop
F00556AC: 400105ff                 call    _simple_lock_try
F00556B0: 90100010                 mov     %l0, %o0
F00556B4: 80a22000                 cmp     %o0, 0
F00556B8: 12800004                 bne     loc_F00556C8
F00556BC: 01000000                 nop
F00556C0: c0260000                 clr     [%i0]
F00556C4: 30800059                 ba,a    loc_F0055828
F00556C8: c0266008                 clr     [%i1+8]
F00556CC: d006201c                 ld      [%i0+0x1C], %o0
F00556D0: 90022001                 inc     %o0
F00556D4: d026201c                 st      %o0, [%i0+0x1C]
F00556D8: d0062004                 ld      [%i0+4], %o0
F00556DC: 90022001                 inc     %o0
F00556E0: d0262004                 st      %o0, [%i0+4]
F00556E4: c0260000                 clr     [%i0]
F00556E8: d0042020                 ld      [%l0+0x20], %o0
F00556EC: 90022001                 inc     %o0
F00556F0: d0242020                 st      %o0, [%l0+0x20]
F00556F4: d0042004                 ld      [%l0+4], %o0
F00556F8: 90022001                 inc     %o0
F00556FC: d0242004                 st      %o0, [%l0+4]
F0055700: c0240000                 clr     [%l0]
F0055704: 133fffc0                 sethi   -0x10000, %o1
F0055708: 920e8009                 and     %i2, %o1, %o1
F005570C: 1100000490122211         set     0x1211, %o0
F0055714: 92124008                 bset    %o0, %o1
F0055718: d226c000                 st      %o1, [%i3]
F005571C: f026e008                 st      %i0, [%i3+8]
F0055720: e026e00c                 st      %l0, [%i3+0xC]
F0055724: 108001c9                 ba      locret_F0055E48
F0055728: b0102000                 mov     0, %i0
F005572C: 12800041                 bne     loc_F0055830
F0055730: a60ea0ff                 and     %i2, 0xFF, %l3
F0055734: b0066008                 add     %i1, 8, %i0
F0055738: d0060000                 ld      [%i0], %o0
F005573C: 80a22000                 cmp     %o0, 0
F0055740: 12bffffe                 bne     loc_F0055738
F0055744: 01000000                 nop
F0055748: 400105d8                 call    _simple_lock_try
F005574C: 90100018                 mov     %i0, %o0
F0055750: 80a22000                 cmp     %o0, 0
F0055754: 02bffff9                 be      loc_F0055738
F0055758: 01000000                 nop
F005575C: d006600c                 ld      [%i1+0xC], %o0
F0055760: 80a22000                 cmp     %o0, 0
F0055764: 02800031                 be      loc_F0055828
F0055768: a7356008                 srl     %l5, 8, %l3
F005576C: d0066018                 ld      [%i1+0x18], %o0
F0055770: ad2d6018                 sll     %l5, 24, %l6
F0055774: 80a4c008                 cmp     %l3, %o0
F0055778: 1a80002c                 bcc     loc_F0055828
F005577C: e4066014                 ld      [%i1+0x14], %l2
F0055780: 952ce004                 sll     %l3, 4, %o2
F0055784: d204800a                 ld      [%l2+%o2], %o1
F0055788: 113fe100                 sethi   -0x7C0000, %o0
F005578C: 920a4008                 and     %o1, %o0, %o1
F0055790: 1100010090158008         set     0x40000, %o0
F0055798: 80a24008                 cmp     %o1, %o0
F005579C: 12800023                 bne     loc_F0055828
F00557A0: a204800a                 add     %l2, %o2, %l1
F00557A4: d0046008                 ld      [%l1+8], %o0
F00557A8: 80a22000                 cmp     %o0, 0
F00557AC: 1280001f                 bne     loc_F0055828
F00557B0: 01000000                 nop
F00557B4: e0046004                 ld      [%l1+4], %l0
F00557B8: d0040000                 ld      [%l0], %o0
F00557BC: 80a22000                 cmp     %o0, 0
F00557C0: 12bffffe                 bne     loc_F00557B8
F00557C4: 01000000                 nop
F00557C8: 400105b8                 call    _simple_lock_try
F00557CC: 90100010                 mov     %l0, %o0
F00557D0: 80a22000                 cmp     %o0, 0
F00557D4: 02bffff9                 be      loc_F00557B8
F00557D8: 01000000                 nop
F00557DC: d0042008                 ld      [%l0+8], %o0
F00557E0: 80a22000                 cmp     %o0, 0
F00557E4: 16800010                 bge     loc_F0055824
F00557E8: 01000000                 nop
F00557EC: c0240000                 clr     [%l0]
F00557F0: d004a008                 ld      [%l2+8], %o0
F00557F4: b0102000                 mov     0, %i0
F00557F8: d0246008                 st      %o0, [%l1+8]
F00557FC: e624a008                 st      %l3, [%l2+8]
F0055800: ec244000                 st      %l6, [%l1]
F0055804: c0246004                 clr     [%l1+4]
F0055808: c0266008                 clr     [%i1+8]
F005580C: 113fffc0                 sethi   -0x10000, %o0
F0055810: 900e8008                 and     %i2, %o0, %o0
F0055814: 90122012                 bset    0x12, %o0
F0055818: d026c000                 st      %o0, [%i3]
F005581C: 1080018b                 ba      locret_F0055E48
F0055820: e026e008                 st      %l0, [%i3+8]
F0055824: c0240000                 clr     [%l0]
F0055828: c0266008                 clr     [%i1+8]
F005582C: a60ea0ff                 and     %i2, 0xFF, %l3
F0055830: ba102000                 mov     0, %i5
F0055834: 9004ffef                 add     %l3, -0x11, %o0
F0055838: 80a22004                 cmp     %o0, 4
F005583C: 1100003f90122300         set     0xFF00, %o0
F0055844: 900e8008                 and     %i2, %o0, %o0
F0055848: 1880000d                 bgu     loc_F005587C
F005584C: a5322008                 srl     %o0, 8, %l2
F0055850: 80a4a000                 cmp     %l2, 0
F0055854: 32800007                 bne,a   loc_F0055870
F0055858: 9004bfef                 add     %l2, -0x11, %o0
F005585C: 80a52000                 cmp     %l4, 0
F0055860: 12800008                 bne     loc_F0055880
F0055864: 31040000                 sethi   0x10000000, %i0
F0055868: 10800008                 ba      loc_F0055888
F005586C: b0066008                 add     %i1, 8, %i0
F0055870: 80a22004                 cmp     %o0, 4
F0055874: 28800005                 bleu,a  loc_F0055888
F0055878: b0066008                 add     %i1, 8, %i0
F005587C: 31040000                 sethi   0x10000000, %i0
F0055880: 10800172                 ba      locret_F0055E48
F0055884: b0162010                 bset    0x10, %i0
F0055888: d0060000                 ld      [%i0], %o0
F005588C: 80a22000                 cmp     %o0, 0
F0055890: 12bffffe                 bne     loc_F0055888
F0055894: 01000000                 nop
F0055898: 40010584                 call    _simple_lock_try
F005589C: 90100018                 mov     %i0, %o0
F00558A0: 80a22000                 cmp     %o0, 0
F00558A4: 02bffff9                 be      loc_F0055888
F00558A8: 01000000                 nop
F00558AC: d006600c                 ld      [%i1+0xC], %o0
F00558B0: 80a22000                 cmp     %o0, 0
F00558B4: 0280015e                 be      loc_F0055E2C
F00558B8: 80a72000                 cmp     %i4, 0
F00558BC: 0280000f                 be      loc_F00558F8
F00558C0: 90100019                 mov     %i1, %o0
F00558C4: 7ffff85e                 call    _ipc_entry_lookup
F00558C8: 9210001c                 mov     %i4, %o1
F00558CC: 94920000                 orcc    %o0, %g0, %o2
F00558D0: 02800006                 be      loc_F00558E8
F00558D4: 11000080                 sethi   0x20000, %o0
F00558D8: d2028000                 ld      [%o2], %o1
F00558DC: 808a4008                 btst    %o0, %o1
F00558E0: 32800006                 bne,a   loc_F00558F8
F00558E4: fa02a004                 ld      [%o2+4], %i5
F00558E8: c0266008                 clr     [%i1+8]
F00558EC: 31040000                 sethi   0x10000000, %i0
F00558F0: 10800156                 ba      locret_F0055E48
F00558F4: b016200b                 bset    0xB, %i0
F00558F8: 80a54014                 cmp     %l5, %l4
F00558FC: 1280007f                 bne     loc_F0055AF8
F0055900: 80a52000                 cmp     %l4, 0
F0055904: 90100019                 mov     %i1, %o0
F0055908: 7ffff84d                 call    _ipc_entry_lookup
F005590C: 92100014                 mov     %l4, %o1
F0055910: a0920000                 orcc    %o0, %g0, %l0
F0055914: 02800146                 be      loc_F0055E2C
F0055918: a2100014                 mov     %l4, %l1
F005591C: 90100019                 mov     %i1, %o0
F0055920: 92100014                 mov     %l4, %o1
F0055924: 94100010                 mov     %l0, %o2
F0055928: 40001d14                 call    _ipc_right_copyin_check
F005592C: 96100012                 mov     %l2, %o3
F0055930: 80a22000                 cmp     %o0, 0
F0055934: 02800142                 be      loc_F0055E3C
F0055938: 80a4e012                 cmp     %l3, 0x12
F005593C: 0280013c                 be      loc_F0055E2C
F0055940: 80a4a012                 cmp     %l2, 0x12
F0055944: 0280013a                 be      loc_F0055E2C
F0055948: 9004ffec                 add     %l3, -0x14, %o0
F005594C: 80a22001                 cmp     %o0, 1
F0055950: 08800005                 bleu    loc_F0055964
F0055954: 9004bfec                 add     %l2, -0x14, %o0
F0055958: 80a22001                 cmp     %o0, 1
F005595C: 18800018                 bgu     loc_F00559BC
F0055960: 80a4e013                 cmp     %l3, 0x13
F0055964: 9007bff0                 add     %fp, var_10, %o0
F0055968: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F005596C: 90100019                 mov     %i1, %o0
F0055970: 92100014                 mov     %l4, %o1
F0055974: 94100010                 mov     %l0, %o2
F0055978: 96100013                 mov     %l3, %o3
F005597C: 98102000                 mov     0, %o4
F0055980: 40001d3c                 call    _ipc_right_copyin
F0055984: 9a07bff4                 add     %fp, var_C, %o5
F0055988: 80a22000                 cmp     %o0, 0
F005598C: 12800128                 bne     loc_F0055E2C
F0055990: 9007bfe8                 add     %fp, var_18, %o0
F0055994: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0055998: 90100019                 mov     %i1, %o0
F005599C: 92100014                 mov     %l4, %o1
F00559A0: 94100010                 mov     %l0, %o2
F00559A4: 96100012                 mov     %l2, %o3
F00559A8: 98102001                 mov     1, %o4
F00559AC: 40001d31                 call    _ipc_right_copyin
F00559B0: 9a07bfec                 add     %fp, var_14, %o5
F00559B4: 108000f8                 ba      loc_F0055D94
F00559B8: 80a72000                 cmp     %i4, 0
F00559BC: 12800016                 bne     loc_F0055A14
F00559C0: 80a4e011                 cmp     %l3, 0x11
F00559C4: 80a4a013                 cmp     %l2, 0x13
F00559C8: 12800013                 bne     loc_F0055A14
F00559CC: 80a4e011                 cmp     %l3, 0x11
F00559D0: 9007bff0                 add     %fp, var_10, %o0
F00559D4: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F00559D8: 90100019                 mov     %i1, %o0
F00559DC: 92100014                 mov     %l4, %o1
F00559E0: 94100010                 mov     %l0, %o2
F00559E4: 96102013                 mov     0x13, %o3
F00559E8: 98102000                 mov     0, %o4
F00559EC: 40001d21                 call    _ipc_right_copyin
F00559F0: 9a07bff4                 add     %fp, var_C, %o5
F00559F4: 80a22000                 cmp     %o0, 0
F00559F8: 1280010d                 bne     loc_F0055E2C
F00559FC: 01000000                 nop
F0055A00: 4000158f                 call    _ipc_port_copy_send
F0055A04: d007bff4                 ld      [%fp+var_C], %o0
F0055A08: d027bfec                 st      %o0, [%fp+var_14]
F0055A0C: 108000e1                 ba      loc_F0055D90
F0055A10: c027bfe8                 clr     [%fp+var_18]
F0055A14: 1280001a                 bne     loc_F0055A7C
F0055A18: 9007bfe4                 add     %fp, var_1C, %o0
F0055A1C: 80a4a011                 cmp     %l2, 0x11
F0055A20: 32800018                 bne,a   loc_F0055A80
F0055A24: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0055A28: 90100019                 mov     %i1, %o0
F0055A2C: 92100011                 mov     %l1, %o1
F0055A30: 94100010                 mov     %l0, %o2
F0055A34: 9607bff4                 add     %fp, var_C, %o3
F0055A38: 40001e5e                 call    _ipc_right_copyin_two
F0055A3C: 9807bff0                 add     %fp, var_10, %o4
F0055A40: 80a22000                 cmp     %o0, 0
F0055A44: 128000fa                 bne     loc_F0055E2C
F0055A48: 110007c0                 sethi   0x1F0000, %o0
F0055A4C: d2040000                 ld      [%l0], %o1
F0055A50: 808a4008                 btst    %o0, %o1
F0055A54: 12800007                 bne     loc_F0055A70
F0055A58: d007bff4                 ld      [%fp+var_C], %o0
F0055A5C: 90100019                 mov     %i1, %o0
F0055A60: 92100011                 mov     %l1, %o1
F0055A64: 7ffff905                 call    _ipc_entry_dealloc
F0055A68: 94100010                 mov     %l0, %o2
F0055A6C: d007bff4                 ld      [%fp+var_C], %o0
F0055A70: c027bfe8                 clr     [%fp+var_18]
F0055A74: 108000c7                 ba      loc_F0055D90
F0055A78: d027bfec                 st      %o0, [%fp+var_14]
F0055A7C: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0055A80: 90100019                 mov     %i1, %o0
F0055A84: 92100011                 mov     %l1, %o1
F0055A88: 94100010                 mov     %l0, %o2
F0055A8C: 96102011                 mov     0x11, %o3
F0055A90: 98102000                 mov     0, %o4
F0055A94: 40001cf7                 call    _ipc_right_copyin
F0055A98: 9a07bff4                 add     %fp, var_C, %o5
F0055A9C: 80a22000                 cmp     %o0, 0
F0055AA0: 128000e3                 bne     loc_F0055E2C
F0055AA4: 110007c0                 sethi   0x1F0000, %o0
F0055AA8: d2040000                 ld      [%l0], %o1
F0055AAC: 808a4008                 btst    %o0, %o1
F0055AB0: 12800005                 bne     loc_F0055AC4
F0055AB4: 90100019                 mov     %i1, %o0
F0055AB8: 92100011                 mov     %l1, %o1
F0055ABC: 7ffff8ef                 call    _ipc_entry_dealloc
F0055AC0: 94100010                 mov     %l0, %o2
F0055AC4: 4000155e                 call    _ipc_port_copy_send
F0055AC8: d007bff4                 ld      [%fp+var_C], %o0
F0055ACC: 80a4e011                 cmp     %l3, 0x11
F0055AD0: 12800006                 bne     loc_F0055AE8
F0055AD4: d027bfec                 st      %o0, [%fp+var_14]
F0055AD8: d007bfe4                 ld      [%fp+var_1C], %o0
F0055ADC: c027bfe8                 clr     [%fp+var_18]
F0055AE0: 108000ac                 ba      loc_F0055D90
F0055AE4: d027bff0                 st      %o0, [%fp+var_10]
F0055AE8: d007bfe4                 ld      [%fp+var_1C], %o0
F0055AEC: c027bff0                 clr     [%fp+var_10]
F0055AF0: 108000a8                 ba      loc_F0055D90
F0055AF4: d027bfe8                 st      %o0, [%fp+var_18]
F0055AF8: 02800004                 be      loc_F0055B08
F0055AFC: 80a53fff                 cmp     %l4, -1
F0055B00: 1280001e                 bne     loc_F0055B78
F0055B04: 90100019                 mov     %i1, %o0
F0055B08: 90100019                 mov     %i1, %o0
F0055B0C: 7ffff7cc                 call    _ipc_entry_lookup
F0055B10: 92100015                 mov     %l5, %o1
F0055B14: a0920000                 orcc    %o0, %g0, %l0
F0055B18: 028000c5                 be      loc_F0055E2C
F0055B1C: 9007bff0                 add     %fp, var_10, %o0
F0055B20: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0055B24: 90100019                 mov     %i1, %o0
F0055B28: 92100015                 mov     %l5, %o1
F0055B2C: 94100010                 mov     %l0, %o2
F0055B30: 96100013                 mov     %l3, %o3
F0055B34: 98102000                 mov     0, %o4
F0055B38: 40001cce                 call    _ipc_right_copyin
F0055B3C: 9a07bff4                 add     %fp, var_C, %o5
F0055B40: 80a22000                 cmp     %o0, 0
F0055B44: 128000ba                 bne     loc_F0055E2C
F0055B48: 110007c0                 sethi   0x1F0000, %o0
F0055B4C: d2040000                 ld      [%l0], %o1
F0055B50: 808a4008                 btst    %o0, %o1
F0055B54: 32800007                 bne,a   loc_F0055B70
F0055B58: e827bfec                 st      %l4, [%fp+var_14]
F0055B5C: 90100019                 mov     %i1, %o0
F0055B60: 92100015                 mov     %l5, %o1
F0055B64: 7ffff8c5                 call    _ipc_entry_dealloc
F0055B68: 94100010                 mov     %l0, %o2
F0055B6C: e827bfec                 st      %l4, [%fp+var_14]
F0055B70: 10800088                 ba      loc_F0055D90
F0055B74: c027bfe8                 clr     [%fp+var_18]
F0055B78: 7ffff7b1                 call    _ipc_entry_lookup
F0055B7C: 92100015                 mov     %l5, %o1
F0055B80: ac920000                 orcc    %o0, %g0, %l6
F0055B84: 028000aa                 be      loc_F0055E2C
F0055B88: 90100019                 mov     %i1, %o0
F0055B8C: 7ffff7ac                 call    _ipc_entry_lookup
F0055B90: 92100014                 mov     %l4, %o1
F0055B94: a2920000                 orcc    %o0, %g0, %l1
F0055B98: 028000a9                 be      loc_F0055E3C
F0055B9C: 90100019                 mov     %i1, %o0
F0055BA0: 92100014                 mov     %l4, %o1
F0055BA4: 94100011                 mov     %l1, %o2
F0055BA8: 40001c74                 call    _ipc_right_copyin_check
F0055BAC: 96100012                 mov     %l2, %o3
F0055BB0: 80a22000                 cmp     %o0, 0
F0055BB4: 028000a2                 be      loc_F0055E3C
F0055BB8: 9007bff0                 add     %fp, var_10, %o0
F0055BBC: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0055BC0: 90100019                 mov     %i1, %o0
F0055BC4: 92100015                 mov     %l5, %o1
F0055BC8: 94100016                 mov     %l6, %o2
F0055BCC: 96100013                 mov     %l3, %o3
F0055BD0: 98102000                 mov     0, %o4
F0055BD4: 40001ca7                 call    _ipc_right_copyin
F0055BD8: 9a07bff4                 add     %fp, var_C, %o5
F0055BDC: 80a22000                 cmp     %o0, 0
F0055BE0: 12800093                 bne     loc_F0055E2C
F0055BE4: 01000000                 nop
F0055BE8: f0046004                 ld      [%l1+4], %i0
F0055BEC: 80a62000                 cmp     %i0, 0
F0055BF0: 02800005                 be      loc_F0055C04
F0055BF4: 9007bfe8                 add     %fp, var_18, %o0
F0055BF8: 40000e8e                 call    _ipc_object_reference
F0055BFC: 90100018                 mov     %i0, %o0
F0055C00: 9007bfe8                 add     %fp, var_18, %o0
F0055C04: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0055C08: 90100019                 mov     %i1, %o0
F0055C0C: 92100014                 mov     %l4, %o1
F0055C10: 94100011                 mov     %l1, %o2
F0055C14: 96100012                 mov     %l2, %o3
F0055C18: 98102001                 mov     1, %o4
F0055C1C: 40001c95                 call    _ipc_right_copyin
F0055C20: 9a07bfec                 add     %fp, var_14, %o5
F0055C24: 80a22000                 cmp     %o0, 0
F0055C28: 02800005                 be      loc_F0055C3C
F0055C2C: 90103fff                 mov     -1, %o0
F0055C30: d027bfec                 st      %o0, [%fp+var_14]
F0055C34: 10800049                 ba      loc_F0055D58
F0055C38: c027bfe8                 clr     [%fp+var_18]
F0055C3C: 80a62000                 cmp     %i0, 0
F0055C40: 0280003d                 be      loc_F0055D34
F0055C44: d007bfec                 ld      [%fp+var_14], %o0
F0055C48: 80a23fff                 cmp     %o0, -1
F0055C4C: 3280003b                 bne,a   loc_F0055D38
F0055C50: d2044000                 ld      [%l1], %o1
F0055C54: e007bff4                 ld      [%fp+var_C], %l0
F0055C58: d0060000                 ld      [%i0], %o0
F0055C5C: 80a22000                 cmp     %o0, 0
F0055C60: 12bffffe                 bne     loc_F0055C58
F0055C64: 01000000                 nop
F0055C68: 40010490                 call    _simple_lock_try
F0055C6C: 90100018                 mov     %i0, %o0
F0055C70: 80a22000                 cmp     %o0, 0
F0055C74: 02bffff9                 be      loc_F0055C58
F0055C78: 01000000                 nop
F0055C7C: ee06200c                 ld      [%i0+0xC], %l7
F0055C80: c0260000                 clr     [%i0]
F0055C84: d0040000                 ld      [%l0], %o0
F0055C88: 80a22000                 cmp     %o0, 0
F0055C8C: 12bffffe                 bne     loc_F0055C84
F0055C90: 01000000                 nop
F0055C94: 40010485                 call    _simple_lock_try
F0055C98: 90100010                 mov     %l0, %o0
F0055C9C: 80a22000                 cmp     %o0, 0
F0055CA0: 02bffff9                 be      loc_F0055C84
F0055CA4: 01000000                 nop
F0055CA8: d0042008                 ld      [%l0+8], %o0
F0055CAC: 80a22000                 cmp     %o0, 0
F0055CB0: 06800005                 bl      loc_F0055CC4
F0055CB4: 92102000                 mov     0, %o1
F0055CB8: d004200c                 ld      [%l0+0xC], %o0
F0055CBC: 90220017                 sub     %o0, %l7, %o0
F0055CC0: 9332201f                 srl     %o0, 31, %o1
F0055CC4: c0240000                 clr     [%l0]
F0055CC8: 80a26000                 cmp     %o1, 0
F0055CCC: 0280001a                 be      loc_F0055D34
F0055CD0: 90100019                 mov     %i1, %o0
F0055CD4: 92100015                 mov     %l5, %o1
F0055CD8: d807bff4                 ld      [%fp+var_C], %o4
F0055CDC: 94100016                 mov     %l6, %o2
F0055CE0: da07bff0                 ld      [%fp+var_10], %o5
F0055CE4: 40001d89                 call    _ipc_right_copyin_undo
F0055CE8: 96100013                 mov     %l3, %o3
F0055CEC: 90100019                 mov     %i1, %o0
F0055CF0: 92100014                 mov     %l4, %o1
F0055CF4: d807bfec                 ld      [%fp+var_14], %o4
F0055CF8: 94100011                 mov     %l1, %o2
F0055CFC: da07bfe8                 ld      [%fp+var_18], %o5
F0055D00: 40001d82                 call    _ipc_right_copyin_undo
F0055D04: 96100012                 mov     %l2, %o3
F0055D08: d007bff0                 ld      [%fp+var_10], %o0
F0055D0C: c0266008                 clr     [%i1+8]
F0055D10: 80a22000                 cmp     %o0, 0
F0055D14: 02800004                 be      loc_F0055D24
F0055D18: 01000000                 nop
F0055D1C: 40000d8c                 call    _ipc_notify_dead_name
F0055D20: 92100015                 mov     %l5, %o1
F0055D24: 40000e53                 call    _ipc_object_release
F0055D28: 90100018                 mov     %i0, %o0
F0055D2C: 10800042                 ba      loc_F0055E34
F0055D30: 31040000                 sethi   0x10000000, %i0
F0055D34: d2044000                 ld      [%l1], %o1
F0055D38: 110007c0                 sethi   0x1F0000, %o0
F0055D3C: 808a4008                 btst    %o0, %o1
F0055D40: 32800008                 bne,a   loc_F0055D60
F0055D44: d2058000                 ld      [%l6], %o1
F0055D48: 90100019                 mov     %i1, %o0
F0055D4C: 92100014                 mov     %l4, %o1
F0055D50: 7ffff84a                 call    _ipc_entry_dealloc
F0055D54: 94100011                 mov     %l1, %o2
F0055D58: d2058000                 ld      [%l6], %o1
F0055D5C: 110007c0                 sethi   0x1F0000, %o0
F0055D60: 808a4008                 btst    %o0, %o1
F0055D64: 12800007                 bne     loc_F0055D80
F0055D68: 80a62000                 cmp     %i0, 0
F0055D6C: 90100019                 mov     %i1, %o0
F0055D70: 92100015                 mov     %l5, %o1
F0055D74: 7ffff841                 call    _ipc_entry_dealloc
F0055D78: 94100016                 mov     %l6, %o2
F0055D7C: 80a62000                 cmp     %i0, 0
F0055D80: 02800005                 be      loc_F0055D94
F0055D84: 80a72000                 cmp     %i4, 0
F0055D88: 40000e3a                 call    _ipc_object_release
F0055D8C: 90100018                 mov     %i0, %o0
F0055D90: 80a72000                 cmp     %i4, 0
F0055D94: 02800008                 be      loc_F0055DB4
F0055D98: d007bff0                 ld      [%fp+var_10], %o0
F0055D9C: 80a2001d                 cmp     %o0, %i5
F0055DA0: 12800006                 bne     loc_F0055DB8
F0055DA4: 01000000                 nop
F0055DA8: 40001522                 call    _ipc_port_release_sonce
F0055DAC: 01000000                 nop
F0055DB0: c027bff0                 clr     [%fp+var_10]
F0055DB4: d007bff0                 ld      [%fp+var_10], %o0
F0055DB8: c0266008                 clr     [%i1+8]
F0055DBC: 80a22000                 cmp     %o0, 0
F0055DC0: 22800005                 be,a    loc_F0055DD4
F0055DC4: d007bfe8                 ld      [%fp+var_18], %o0
F0055DC8: 40000c89                 call    _ipc_notify_port_deleted
F0055DCC: 92100015                 mov     %l5, %o1
F0055DD0: d007bfe8                 ld      [%fp+var_18], %o0
F0055DD4: 80a22000                 cmp     %o0, 0
F0055DD8: 02800004                 be      loc_F0055DE8
F0055DDC: 01000000                 nop
F0055DE0: 40000c83                 call    _ipc_notify_port_deleted
F0055DE4: 92100014                 mov     %l4, %o1
F0055DE8: 40000ef5                 call    _ipc_object_copyin_type
F0055DEC: 90100013                 mov     %l3, %o0
F0055DF0: a6100008                 mov     %o0, %l3
F0055DF4: 40000ef2                 call    _ipc_object_copyin_type
F0055DF8: 90100012                 mov     %l2, %o0
F0055DFC: 133fffc0                 sethi   -0x10000, %o1
F0055E00: 920e8009                 and     %i2, %o1, %o1
F0055E04: 912a2008                 sll     %o0, 8, %o0
F0055E08: 9014c008                 bset    %l3, %o0
F0055E0C: 92124008                 bset    %o0, %o1
F0055E10: d226c000                 st      %o1, [%i3]
F0055E14: d207bff4                 ld      [%fp+var_C], %o1
F0055E18: b0102000                 mov     0, %i0
F0055E1C: d007bfec                 ld      [%fp+var_14], %o0
F0055E20: d226e008                 st      %o1, [%i3+8]
F0055E24: 10800009                 ba      locret_F0055E48
F0055E28: d026e00c                 st      %o0, [%i3+0xC]
F0055E2C: c0266008                 clr     [%i1+8]
F0055E30: 31040000                 sethi   0x10000000, %i0
F0055E34: 10800005                 ba      locret_F0055E48
F0055E38: b0162003                 bset    3, %i0
F0055E3C: c0266008                 clr     [%i1+8]
F0055E40: 31040000b0162009         set     0x10000009, %i0
F0055E48: 81c7e008                 ret
F0055E4C: 81e80000                 restore
