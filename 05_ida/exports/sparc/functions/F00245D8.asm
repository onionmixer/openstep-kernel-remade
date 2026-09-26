F00245D8: 9de3bf98                 save    %sp, -0x68, %sp
F00245DC: a2100018                 mov     %i0, %l1
F00245E0: b0102000                 mov     0, %i0
F00245E4: 90100011                 mov     %l1, %o0
F00245E8: 133c04d4a01263b0         set     _bstats, %l0
F00245F0: d4042008                 ld      [%l0+8], %o2
F00245F4: 92100019                 mov     %i1, %o1
F00245F8: 9402a001                 inc     %o2
F00245FC: 400000f4                 call    _incore
F0024600: d4242008                 st      %o2, [%l0+8]
F0024604: 80a22000                 cmp     %o0, 0
F0024608: 12800022                 bne     loc_F0024690
F002460C: 80a6e000                 cmp     %i3, 0
F0024610: 90100011                 mov     %l1, %o0
F0024614: 92100019                 mov     %i1, %o1
F0024618: 40000114                 call    _getblk
F002461C: 9410001a                 mov     %i2, %o2
F0024620: b0100008                 mov     %o0, %i0
F0024624: d2060000                 ld      [%i0], %o1
F0024628: 808a6002                 btst    2, %o1
F002462C: 32800016                 bne,a   loc_F0024684
F0024630: d004200c                 ld      [%l0+0xC], %o0
F0024634: d0062014                 ld      [%i0+0x14], %o0
F0024638: 92126001                 bset    1, %o1
F002463C: d4062018                 ld      [%i0+0x18], %o2
F0024640: 80a2000a                 cmp     %o0, %o2
F0024644: 04800005                 ble     loc_F0024658
F0024648: d2260000                 st      %o1, [%i0]
F002464C: 113c042f                 sethi   %hi(aBreada), %o0! "breada"
F0024650: 7fffc2c8                 call    _panic
F0024654: 901222f0                 bset    %lo(aBreada), %o0! "breada"
F0024658: d0062040                 ld      [%i0+0x40], %o0
F002465C: d002201c                 ld      [%o0+0x1C], %o0
F0024660: d2022054                 ld      [%o0+0x54], %o1
F0024664: 9fc24000                 call    %o1
F0024668: 90100018                 mov     %i0, %o0
F002466C: 113c04cf                 sethi   %hi(_active_u), %o0
F0024670: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0024674: d0026198                 ld      [%o1+0x198], %o0
F0024678: 90022001                 inc     %o0
F002467C: 10800004                 ba      loc_F002468C
F0024680: d0226198                 st      %o0, [%o1+0x198]
F0024684: 90022001                 inc     %o0
F0024688: d024200c                 st      %o0, [%l0+0xC]
F002468C: 80a6e000                 cmp     %i3, 0
F0024690: 0280002a                 be      loc_F0024738
F0024694: 90100011                 mov     %l1, %o0
F0024698: 400000cd                 call    _incore
F002469C: 9210001b                 mov     %i3, %o1
F00246A0: 80a22000                 cmp     %o0, 0
F00246A4: 12800026                 bne     loc_F002473C
F00246A8: 80a62000                 cmp     %i0, 0
F00246AC: 90100011                 mov     %l1, %o0
F00246B0: 9210001b                 mov     %i3, %o1
F00246B4: 400000ed                 call    _getblk
F00246B8: 9410001c                 mov     %i4, %o2
F00246BC: b6100008                 mov     %o0, %i3
F00246C0: d206c000                 ld      [%i3], %o1
F00246C4: 808a6002                 btst    2, %o1
F00246C8: 2280000a                 be,a    loc_F00246F0
F00246CC: d006e014                 ld      [%i3+0x14], %o0
F00246D0: 40000066                 call    _brelse
F00246D4: 01000000                 nop
F00246D8: 133c04d4921263b0         set     _bstats, %o1
F00246E0: d0026010                 ld      [%o1+0x10], %o0
F00246E4: 90022001                 inc     %o0
F00246E8: 10800014                 ba      loc_F0024738
F00246EC: d0226010                 st      %o0, [%o1+0x10]
F00246F0: 92126101                 bset    0x101, %o1
F00246F4: d406e018                 ld      [%i3+0x18], %o2
F00246F8: 80a2000a                 cmp     %o0, %o2
F00246FC: 04800005                 ble     loc_F0024710
F0024700: d226c000                 st      %o1, [%i3]
F0024704: 113c042f                 sethi   %hi(aBreadrabp), %o0! "breadrabp"
F0024708: 7fffc29a                 call    _panic
F002470C: 901222f8                 bset    %lo(aBreadrabp), %o0! "breadrabp"
F0024710: d006e040                 ld      [%i3+0x40], %o0
F0024714: d002201c                 ld      [%o0+0x1C], %o0
F0024718: d2022054                 ld      [%o0+0x54], %o1
F002471C: 9fc24000                 call    %o1
F0024720: 9010001b                 mov     %i3, %o0
F0024724: 113c04cf                 sethi   %hi(_active_u), %o0
F0024728: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F002472C: d0026198                 ld      [%o1+0x198], %o0
F0024730: 90022001                 inc     %o0
F0024734: d0226198                 st      %o0, [%o1+0x198]
F0024738: 80a62000                 cmp     %i0, 0
F002473C: 02800005                 be      loc_F0024750
F0024740: 90100011                 mov     %l1, %o0
F0024744: 40000247                 call    _biowait
F0024748: 90100018                 mov     %i0, %o0
F002474C: 30800005                 ba,a    locret_F0024760
F0024750: 92100019                 mov     %i1, %o1
F0024754: 7fffff73                 call    _bread
F0024758: 9410001a                 mov     %i2, %o2
F002475C: b0100008                 mov     %o0, %i0
F0024760: 81c7e008                 ret
F0024764: 81e80000                 restore
