F001B3F4: 9de3bf98                 save    %sp, -0x68, %sp
F001B3F8: b00e20ff                 and     %i0, 0xFF, %i0
F001B3FC: b12e2004                 sll     %i0, 4, %i0
F001B400: 113c04bc90122204         set     unk_F012F204, %o0
F001B408: b0060008                 add     %i0, %o0, %i0
F001B40C: e0062008                 ld      [%i0+8], %l0
F001B410: a6102000                 mov     0, %l3
F001B414: e806200c                 ld      [%i0+0xC], %l4
F001B418: d0050000                 ld      [%l4], %o0
F001B41C: 808a2020                 btst    0x20, %o0 ! ' '
F001B420: 02800071                 be      loc_F001B5E4
F001B424: 133c04cf                 sethi   %hi(_active_u), %o1
F001B428: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F001B42C: d0022164                 ld      [%o0+0x164], %o0
F001B430: 80a40008                 cmp     %l0, %o0
F001B434: 3280003c                 bne,a   loc_F001B524
F001B438: d004200c                 ld      [%l0+0xC], %o0
F001B43C: 23000400                 sethi   0x100000, %l1
F001B440: a4100009                 mov     %o1, %l2
F001B444: d00261d8                 ld      [%o1+0x1D8], %o0
F001B448: f0020000                 ld      [%o0], %i0
F001B44C: d256202e                 ldsh    [%i0+0x2E], %o1
F001B450: d0542044                 ldsh    [%l0+0x44], %o0
F001B454: 80a24008                 cmp     %o1, %o0
F001B458: 02800032                 be      loc_F001B520
F001B45C: 11000010                 sethi   0x4000, %o0
F001B460: d2062014                 ld      [%i0+0x14], %o1
F001B464: 808a4008                 btst    %o0, %o1
F001B468: 22800013                 be,a    loc_F001B4B4
F001B46C: d0062020                 ld      [%i0+0x20], %o0
F001B470: 7fffcdac                 call    _get_posix_proc
F001B474: d0562030                 ldsh    [%i0+0x30], %o0
F001B478: d2062020                 ld      [%i0+0x20], %o1
F001B47C: 808a4011                 btst    %l1, %o1
F001B480: 12800019                 bne     loc_F001B4E4
F001B484: 92100008                 mov     %o0, %o1
F001B488: d006201c                 ld      [%i0+0x1C], %o0
F001B48C: 808a0011                 btst    %l1, %o0
F001B490: 32800068                 bne,a   locret_F001B630
F001B494: b0102005                 mov     5, %i0
F001B498: d0026010                 ld      [%o1+0x10], %o0
F001B49C: d0022010                 ld      [%o0+0x10], %o0
F001B4A0: 80a22000                 cmp     %o0, 0
F001B4A4: 12800012                 bne     loc_F001B4EC
F001B4A8: d004a1d8                 ld      [%l2+0x1D8], %o0
F001B4AC: 10800061                 ba      locret_F001B630
F001B4B0: b0102005                 mov     5, %i0
F001B4B4: 808a0011                 btst    %l1, %o0
F001B4B8: 3280005e                 bne,a   locret_F001B630
F001B4BC: b0102005                 mov     5, %i0
F001B4C0: d006201c                 ld      [%i0+0x1C], %o0
F001B4C4: 808a0011                 btst    %l1, %o0
F001B4C8: 3280005a                 bne,a   locret_F001B630
F001B4CC: b0102005                 mov     5, %i0
F001B4D0: d2062028                 ld      [%i0+0x28], %o1
F001B4D4: 11000004                 sethi   0x1000, %o0
F001B4D8: 808a4008                 btst    %o0, %o1
F001B4DC: 02800004                 be      loc_F001B4EC
F001B4E0: d004a1d8                 ld      [%l2+0x1D8], %o0
F001B4E4: 10800053                 ba      locret_F001B630
F001B4E8: b0102005                 mov     5, %i0
F001B4EC: d0020000                 ld      [%o0], %o0
F001B4F0: d052202e                 ldsh    [%o0+0x2E], %o0
F001B4F4: 7fffd7fa                 call    _gsignal
F001B4F8: 92102015                 mov     0x15, %o1
F001B4FC: 113c04d190122350         set     _lbolt, %o0! unsigned int
F001B504: 7fffdc5d                 call    _sleep
F001B508: 9210201c                 mov     0x1C, %o1
F001B50C: d004a1d8                 ld      [%l2+0x1D8], %o0
F001B510: d0022164                 ld      [%o0+0x164], %o0
F001B514: 80a40008                 cmp     %l0, %o0
F001B518: 02bfffcb                 be      loc_F001B444
F001B51C: 92100012                 mov     %l2, %o1
F001B520: d004200c                 ld      [%l0+0xC], %o0
F001B524: 80a22000                 cmp     %o0, 0
F001B528: 12800021                 bne     loc_F001B5AC
F001B52C: 80a22001                 cmp     %o0, 1
F001B530: d2042040                 ld      [%l0+0x40], %o1
F001B534: 11000008                 sethi   0x2000, %o0
F001B538: 808a4008                 btst    %o0, %o1
F001B53C: 0280000b                 be      loc_F001B568
F001B540: 113c04cf                 sethi   %hi(_active_u), %o0
F001B544: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001B548: d0020000                 ld      [%o0], %o0
F001B54C: d2022014                 ld      [%o0+0x14], %o1
F001B550: 11000010                 sethi   0x4000, %o0
F001B554: 808a4008                 btst    %o0, %o1
F001B558: 02800036                 be      locret_F001B630
F001B55C: b0102023                 mov     0x23, %i0 ! '#'
F001B560: 10800034                 ba      locret_F001B630
F001B564: b010200b                 mov     0xB, %i0
F001B568: 9004200c                 add     %l0, 0xC, %o0! unsigned int
F001B56C: 7fffdc43                 call    _sleep
F001B570: 9210201c                 mov     0x1C, %o1
F001B574: 10bfffaa                 ba      loc_F001B41C
F001B578: d0050000                 ld      [%l4], %o0
F001B57C: 80a22000                 cmp     %o0, 0
F001B580: 2480000e                 ble,a   loc_F001B5B8
F001B584: d004200c                 ld      [%l0+0xC], %o0! FILE *
F001B588: 40000450                 call    _getc
F001B58C: 9004200c                 add     %l0, 0xC, %o0
F001B590: 7fffdbb1                 call    _ureadc
F001B594: 92100019                 mov     %i1, %o1
F001B598: 80a22000                 cmp     %o0, 0
F001B59C: 26800006                 bl,a    loc_F001B5B4
F001B5A0: a610200e                 mov     0xE, %l3
F001B5A4: d004200c                 ld      [%l0+0xC], %o0
F001B5A8: 80a22001                 cmp     %o0, 1
F001B5AC: 34bffff4                 bg,a    loc_F001B57C
F001B5B0: d0066014                 ld      [%i1+0x14], %o0
F001B5B4: d004200c                 ld      [%l0+0xC], %o0
F001B5B8: 80a22001                 cmp     %o0, 1
F001B5BC: 32800005                 bne,a   loc_F001B5D0
F001B5C0: d004200c                 ld      [%l0+0xC], %o0! FILE *
F001B5C4: 40000441                 call    _getc
F001B5C8: 9004200c                 add     %l0, 0xC, %o0
F001B5CC: d004200c                 ld      [%l0+0xC], %o0
F001B5D0: 80a22000                 cmp     %o0, 0
F001B5D4: 02800014                 be      loc_F001B624
F001B5D8: 90100010                 mov     %l0, %o0
F001B5DC: 10800015                 ba      locret_F001B630
F001B5E0: b0100013                 mov     %l3, %i0
F001B5E4: d0042024                 ld      [%l0+0x24], %o0
F001B5E8: 80a22000                 cmp     %o0, 0
F001B5EC: 0280000d                 be      loc_F001B620
F001B5F0: 90100010                 mov     %l0, %o0
F001B5F4: d44c2047                 ldsb    [%l0+0x47], %o2
F001B5F8: 932aa001                 sll     %o2, 1, %o1
F001B5FC: 9202400a                 add     %o1, %o2, %o1
F001B600: 932a6004                 sll     %o1, 4, %o1
F001B604: 153c042e9412a0cc         set     _linesw, %o2
F001B60C: 9202400a                 add     %o1, %o2, %o1
F001B610: d4026008                 ld      [%o1+8], %o2
F001B614: 9fc28000                 call    %o2
F001B618: 92100019                 mov     %i1, %o1
F001B61C: a6100008                 mov     %o0, %l3
F001B620: 90100010                 mov     %l0, %o0
F001B624: 4000004c                 call    _ptcwakeup
F001B628: 92102002                 mov     2, %o1
F001B62C: b0100013                 mov     %l3, %i0
F001B630: 81c7e008                 ret
F001B634: 81e80000                 restore
