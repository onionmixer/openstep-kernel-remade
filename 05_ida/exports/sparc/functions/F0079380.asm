F0079380: 9de3bf98                 save    %sp, -0x68, %sp
F0079384: 113c04f2a0122380         set     _all_zones_lock, %l0
F007938C: d0040000                 ld      [%l0], %o0
F0079390: 80a22000                 cmp     %o0, 0
F0079394: 12bffffe                 bne     loc_F007938C
F0079398: 01000000                 nop
F007939C: 400076c3                 call    _simple_lock_try
F00793A0: 90100010                 mov     %l0, %o0
F00793A4: 80a22000                 cmp     %o0, 0
F00793A8: 02bffff9                 be      loc_F007938C
F00793AC: 113c04f2                 sethi   %hi(_all_zones_lock), %o0
F00793B0: c0222380                 clr     [%o0+%lo(_all_zones_lock)]
F00793B4: 113c04f2a21223a8         set     _zget_space_lock, %l1
F00793BC: 113c04f2                 sethi   %hi(_num_zones), %o0
F00793C0: e8022398                 ld      [%o0+%lo(_num_zones)], %l4
F00793C4: 113c04f2                 sethi   %hi(_first_zone), %o0
F00793C8: e0022388                 ld      [%o0+%lo(_first_zone)], %l0
F00793CC: d0044000                 ld      [%l1], %o0
F00793D0: 80a22000                 cmp     %o0, 0
F00793D4: 12bffffe                 bne     loc_F00793CC
F00793D8: 01000000                 nop
F00793DC: 400076b3                 call    _simple_lock_try
F00793E0: 90100011                 mov     %l1, %o0
F00793E4: 80a22000                 cmp     %o0, 0
F00793E8: 02bffff9                 be      loc_F00793CC
F00793EC: a4102000                 mov     0, %l2
F00793F0: 80a48014                 cmp     %l2, %l4
F00793F4: 16800040                 bge     loc_F00794F4
F00793F8: 113c04f2                 sethi   %hi(__zone_default_space), %o0
F00793FC: 27200000                 sethi   0x80000000, %l3
F0079400: ac122350                 or      %o0, %lo(__zone_default_space), %l6
F0079404: 2b3c04f2                 sethi   -0xFEC3800, %l5
F0079408: d004202c                 ld      [%l0+0x2C], %o0
F007940C: 808a0013                 btst    %l3, %o0
F0079410: 02800006                 be      loc_F0079428
F0079414: 01000000                 nop
F0079418: 7fffbe6b                 call    _lock_write
F007941C: 90042030                 add     %l0, 0x30, %o0 ! '0'
F0079420: 10800010                 ba      loc_F0079460
F0079424: d004202c                 ld      [%l0+0x2C], %o0
F0079428: 400075d8                 call    _splusclock
F007942C: 01000000                 nop
F0079430: a2100008                 mov     %o0, %l1
F0079434: d0040000                 ld      [%l0], %o0
F0079438: 80a22000                 cmp     %o0, 0
F007943C: 12bffffe                 bne     loc_F0079434
F0079440: 01000000                 nop
F0079444: 40007699                 call    _simple_lock_try
F0079448: 90100010                 mov     %l0, %o0
F007944C: 80a22000                 cmp     %o0, 0
F0079450: 02bffff9                 be      loc_F0079434
F0079454: 01000000                 nop
F0079458: e2242004                 st      %l1, [%l0+4]
F007945C: d004202c                 ld      [%l0+0x2C], %o0
F0079460: 808a0013                 btst    %l3, %o0
F0079464: 3280000b                 bne,a   loc_F0079490
F0079468: d004202c                 ld      [%l0+0x2C], %o0
F007946C: d004203c                 ld      [%l0+0x3C], %o0
F0079470: 80a22000                 cmp     %o0, 0
F0079474: 02800006                 be      loc_F007948C
F0079478: 80a20016                 cmp     %o0, %l6
F007947C: 22800005                 be,a    loc_F0079490
F0079480: d004202c                 ld      [%l0+0x2C], %o0
F0079484: 7ffffbb7                 call    _zone_collect
F0079488: 90100010                 mov     %l0, %o0
F007948C: d004202c                 ld      [%l0+0x2C], %o0
F0079490: 808a0013                 btst    %l3, %o0
F0079494: 22800006                 be,a    loc_F00794AC
F0079498: d0042004                 ld      [%l0+4], %o0
F007949C: 7fffbee6                 call    _lock_done
F00794A0: 90042030                 add     %l0, 0x30, %o0 ! '0'
F00794A4: 10800005                 ba      loc_F00794B8
F00794A8: a2156380                 or      %l5, 0x380, %l1
F00794AC: c0240000                 clr     [%l0]
F00794B0: 4000761d                 call    _splx
F00794B4: a2156380                 or      %l5, 0x380, %l1
F00794B8: d0044000                 ld      [%l1], %o0
F00794BC: 80a22000                 cmp     %o0, 0
F00794C0: 12bffffe                 bne     loc_F00794B8
F00794C4: 01000000                 nop
F00794C8: 40007678                 call    _simple_lock_try
F00794CC: 90100011                 mov     %l1, %o0
F00794D0: 80a22000                 cmp     %o0, 0
F00794D4: 02bffff9                 be      loc_F00794B8
F00794D8: 01000000                 nop
F00794DC: e0042040                 ld      [%l0+0x40], %l0
F00794E0: a404a001                 inc     %l2
F00794E4: 80a48014                 cmp     %l2, %l4
F00794E8: c0256380                 clr     [%l5+0x380]
F00794EC: 26bfffc8                 bl,a    loc_F007940C
F00794F0: d004202c                 ld      [%l0+0x2C], %o0
F00794F4: 7ffffc15                 call    _zone_free_space_reclaim
F00794F8: 01000000                 nop
F00794FC: 81c7e008                 ret
F0079500: 81e80000                 restore
