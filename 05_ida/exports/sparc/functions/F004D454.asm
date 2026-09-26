F004D454: 9de3bf98                 save    %sp, -0x68, %sp
F004D458: e406603c                 ld      [%i1+0x3C], %l2
F004D45C: 400125d7                 call    _spltty
F004D460: a0062024                 add     %i0, 0x24, %l0 ! '$'
F004D464: a6100008                 mov     %o0, %l3
F004D468: d0040000                 ld      [%l0], %o0
F004D46C: 80a22000                 cmp     %o0, 0
F004D470: 12bffffe                 bne     loc_F004D468
F004D474: 01000000                 nop
F004D478: 4001268c                 call    _simple_lock_try
F004D47C: 90100010                 mov     %l0, %o0
F004D480: 80a22000                 cmp     %o0, 0
F004D484: 02bffff9                 be      loc_F004D468
F004D488: 92062010                 add     %i0, 0x10, %o1
F004D48C: d0062010                 ld      [%i0+0x10], %o0
F004D490: 80a24008                 cmp     %o1, %o0
F004D494: 3280000c                 bne,a   loc_F004D4C4
F004D498: a0100008                 mov     %o0, %l0
F004D49C: 90100018                 mov     %i0, %o0
F004D4A0: 7fffffa3                 call    sub_F004D32C
F004D4A4: 94100019                 mov     %i1, %o2
F004D4A8: 94100008                 mov     %o0, %o2
F004D4AC: e422a00c                 st      %l2, [%o2+0xC]
F004D4B0: d206201c                 ld      [%i0+0x1C], %o1
F004D4B4: d222a008                 st      %o1, [%o2+8]
F004D4B8: c0262024                 clr     [%i0+0x24]
F004D4BC: 10800082                 ba      loc_F004D6C4
F004D4C0: 90100013                 mov     %l3, %o0
F004D4C4: d006200c                 ld      [%i0+0xC], %o0
F004D4C8: 15040000                 sethi   0x10000000, %o2
F004D4CC: 808a000a                 btst    %o2, %o0
F004D4D0: 02800021                 be      loc_F004D554
F004D4D4: 90062010                 add     %i0, 0x10, %o0
F004D4D8: d0040000                 ld      [%l0], %o0
F004D4DC: d0022038                 ld      [%o0+0x38], %o0
F004D4E0: d0242008                 st      %o0, [%l0+8]
F004D4E4: d006200c                 ld      [%i0+0xC], %o0
F004D4E8: 808a000a                 btst    %o2, %o0
F004D4EC: 0280001a                 be      loc_F004D554
F004D4F0: 90062010                 add     %i0, 0x10, %o0
F004D4F4: d004200c                 ld      [%l0+0xC], %o0
F004D4F8: 80a20012                 cmp     %o0, %l2
F004D4FC: 16800016                 bge     loc_F004D554
F004D500: 90062010                 add     %i0, 0x10, %o0
F004D504: d0062018                 ld      [%i0+0x18], %o0
F004D508: 80a22000                 cmp     %o0, 0
F004D50C: 04800012                 ble     loc_F004D554
F004D510: 90062010                 add     %i0, 0x10, %o0
F004D514: e2040000                 ld      [%l0], %l1
F004D518: d0042004                 ld      [%l0+4], %o0
F004D51C: 80a44008                 cmp     %l1, %o0
F004D520: 0280000b                 be      loc_F004D54C
F004D524: 90100018                 mov     %i0, %o0
F004D528: d604600c                 ld      [%l1+0xC], %o3
F004D52C: 94100011                 mov     %l1, %o2
F004D530: 7fffff7f                 call    sub_F004D32C
F004D534: d6240000                 st      %o3, [%l0]
F004D538: e422200c                 st      %l2, [%o0+0xC]
F004D53C: d2046038                 ld      [%l1+0x38], %o1
F004D540: a0100008                 mov     %o0, %l0
F004D544: 10800003                 ba      loc_F004D550
F004D548: d2242008                 st      %o1, [%l0+8]
F004D54C: e424200c                 st      %l2, [%l0+0xC]
F004D550: 90062010                 add     %i0, 0x10, %o0
F004D554: 80a40008                 cmp     %l0, %o0
F004D558: 2280000c                 be,a    loc_F004D588
F004D55C: 90062010                 add     %i0, 0x10, %o0
F004D560: 92100008                 mov     %o0, %o1
F004D564: d004200c                 ld      [%l0+0xC], %o0
F004D568: 80a20012                 cmp     %o0, %l2
F004D56C: 24800007                 ble,a   loc_F004D588
F004D570: 90062010                 add     %i0, 0x10, %o0
F004D574: e0042010                 ld      [%l0+0x10], %l0
F004D578: 80a40009                 cmp     %l0, %o1
F004D57C: 32bffffb                 bne,a   loc_F004D568
F004D580: d004200c                 ld      [%l0+0xC], %o0
F004D584: 90062010                 add     %i0, 0x10, %o0
F004D588: 80a20010                 cmp     %o0, %l0
F004D58C: 1280000d                 bne     loc_F004D5C0
F004D590: d0062018                 ld      [%i0+0x18], %o0
F004D594: 80a22000                 cmp     %o0, 0
F004D598: 1280000b                 bne     loc_F004D5C4
F004D59C: 01000000                 nop
F004D5A0: 90100018                 mov     %i0, %o0
F004D5A4: d606200c                 ld      [%i0+0xC], %o3
F004D5A8: 94100019                 mov     %i1, %o2
F004D5AC: d2062014                 ld      [%i0+0x14], %o1
F004D5B0: 9732e01c                 srl     %o3, 28, %o3
F004D5B4: 7fffff3d                 call    sub_F004D2A8
F004D5B8: 960ae001                 and     %o3, 1, %o3
F004D5BC: 30800040                 ba,a    loc_F004D6BC
F004D5C0: 80a22000                 cmp     %o0, 0
F004D5C4: 0280001b                 be      loc_F004D630
F004D5C8: a2062010                 add     %i0, 0x10, %l1
F004D5CC: 80a44010                 cmp     %l1, %l0
F004D5D0: 22800002                 be,a    loc_F004D5D8
F004D5D4: e0062014                 ld      [%i0+0x14], %l0
F004D5D8: d004200c                 ld      [%l0+0xC], %o0
F004D5DC: 80a20012                 cmp     %o0, %l2
F004D5E0: 16800012                 bge     loc_F004D628
F004D5E4: 01000000                 nop
F004D5E8: 90100018                 mov     %i0, %o0
F004D5EC: d2042014                 ld      [%l0+0x14], %o1
F004D5F0: 7fffff4f                 call    sub_F004D32C
F004D5F4: 94100019                 mov     %i1, %o2
F004D5F8: 94100008                 mov     %o0, %o2
F004D5FC: e002a014                 ld      [%o2+0x14], %l0
F004D600: 80a44010                 cmp     %l1, %l0
F004D604: 12800004                 bne     loc_F004D614
F004D608: e422a00c                 st      %l2, [%o2+0xC]
F004D60C: 10800004                 ba      loc_F004D61C
F004D610: d006201c                 ld      [%i0+0x1C], %o0
F004D614: d0042004                 ld      [%l0+4], %o0
F004D618: d0022038                 ld      [%o0+0x38], %o0
F004D61C: d022a008                 st      %o0, [%o2+8]
F004D620: 10800015                 ba      loc_F004D674
F004D624: a010000a                 mov     %o2, %l0
F004D628: 1280000b                 bne     loc_F004D654
F004D62C: 90100018                 mov     %i0, %o0
F004D630: 90100018                 mov     %i0, %o0
F004D634: 92100010                 mov     %l0, %o1
F004D638: d606200c                 ld      [%i0+0xC], %o3
F004D63C: 94100019                 mov     %i1, %o2
F004D640: 9732e01c                 srl     %o3, 28, %o3
F004D644: 7fffff19                 call    sub_F004D2A8
F004D648: 960ae001                 and     %o3, 1, %o3
F004D64C: 1080000b                 ba      loc_F004D678
F004D650: 90062010                 add     %i0, 0x10, %o0
F004D654: 92100010                 mov     %l0, %o1
F004D658: 7fffff35                 call    sub_F004D32C
F004D65C: 94100019                 mov     %i1, %o2
F004D660: 94100008                 mov     %o0, %o2
F004D664: e422a00c                 st      %l2, [%o2+0xC]
F004D668: d0042004                 ld      [%l0+4], %o0
F004D66C: d0022038                 ld      [%o0+0x38], %o0
F004D670: d022a008                 st      %o0, [%o2+8]
F004D674: 90062010                 add     %i0, 0x10, %o0
F004D678: 80a20010                 cmp     %o0, %l0
F004D67C: 02800010                 be      loc_F004D6BC
F004D680: 01000000                 nop
F004D684: f2042010                 ld      [%l0+0x10], %i1
F004D688: 80a20019                 cmp     %o0, %i1
F004D68C: 0280000c                 be      loc_F004D6BC
F004D690: 01000000                 nop
F004D694: a2100008                 mov     %o0, %l1
F004D698: d2042004                 ld      [%l0+4], %o1
F004D69C: 90100019                 mov     %i1, %o0
F004D6A0: d2026038                 ld      [%o1+0x38], %o1
F004D6A4: 7fffff57                 call    sub_F004D400
F004D6A8: a0100019                 mov     %i1, %l0
F004D6AC: f2066010                 ld      [%i1+0x10], %i1
F004D6B0: 80a44019                 cmp     %l1, %i1
F004D6B4: 32bffffa                 bne,a   loc_F004D69C
F004D6B8: d2042004                 ld      [%l0+4], %o1
F004D6BC: c0262024                 clr     [%i0+0x24]
F004D6C0: 90100013                 mov     %l3, %o0
F004D6C4: 40012598                 call    _splx
F004D6C8: 01000000                 nop
F004D6CC: 81c7e008                 ret
F004D6D0: 81e80000                 restore
