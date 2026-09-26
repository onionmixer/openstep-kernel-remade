F001B9B0: 9de3bf10                 save    %sp, -0xF0, %sp
F001B9B4: a2102000                 mov     0, %l1
F001B9B8: b00e20ff                 and     %i0, 0xFF, %i0
F001B9BC: b12e2004                 sll     %i0, 4, %i0
F001B9C0: 113c04bc90122204         set     unk_F012F204, %o0
F001B9C8: b0060008                 add     %i0, %o0, %i0
F001B9CC: e0062008                 ld      [%i0+8], %l0
F001B9D0: a407bf70                 add     %fp, var_90, %l2
F001B9D4: f006200c                 ld      [%i0+0xC], %i0
F001B9D8: d0042040                 ld      [%l0+0x40], %o0
F001B9DC: 808a2004                 btst    4, %o0
F001B9E0: 0280004b                 be      loc_F001BB0C
F001B9E4: 808a2010                 btst    0x10, %o0
F001B9E8: d0060000                 ld      [%i0], %o0
F001B9EC: 808a2008                 btst    8, %o0
F001B9F0: 02800032                 be      loc_F001BAB8
F001B9F4: 808a2080                 btst    0x80, %o0
F001B9F8: d00e200c                 ldub    [%i0+0xC], %o0
F001B9FC: 80a22000                 cmp     %o0, 0
F001BA00: 2280002d                 be,a    loc_F001BAB4
F001BA04: d0060000                 ld      [%i0], %o0
F001BA08: 7fffda93                 call    _ureadc
F001BA0C: 92100019                 mov     %i1, %o1
F001BA10: a2920000                 orcc    %o0, %g0, %l1
F001BA14: 32800094                 bne,a   locret_F001BC64
F001BA18: b0100011                 mov     %l1, %i0
F001BA1C: d00e200c                 ldub    [%i0+0xC], %o0
F001BA20: 808a2040                 btst    0x40, %o0 ! '@'
F001BA24: 22800022                 be,a    loc_F001BAAC
F001BA28: c02e200c                 clrb    [%i0+0xC]
F001BA2C: d00c2049                 ldub    [%l0+0x49], %o0
F001BA30: d02fbf70                 stb     %o0, [%fp+var_90]
F001BA34: d00c204a                 ldub    [%l0+0x4A], %o0
F001BA38: d02fbf71                 stb     %o0, [%fp+var_8F]
F001BA3C: d20c204d                 ldub    [%l0+0x4D], %o1
F001BA40: 9004204f                 add     %l0, 0x4F, %o0 ! 'O'! void *
F001BA44: d22fbf72                 stb     %o1, [%fp+var_8E]
F001BA48: d40c204e                 ldub    [%l0+0x4E], %o2
F001BA4C: 9207bf76                 add     %fp, var_8A, %o1! void *
F001BA50: d42fbf73                 stb     %o2, [%fp+var_8D]
F001BA54: d604203c                 ld      [%l0+0x3C], %o3
F001BA58: 94102006                 mov     6, %o2! size_t
F001BA5C: 4001e42d                 call    _bcopy
F001BA60: d637bf74                 sth     %o3, [%fp+var_8C]
F001BA64: 90042055                 add     %l0, 0x55, %o0 ! 'U'! void *
F001BA68: 9207bf7c                 add     %fp, var_84, %o1! void *
F001BA6C: 4001e429                 call    _bcopy
F001BA70: 94102006                 mov     6, %o2
F001BA74: d0042040                 ld      [%l0+0x40], %o0
F001BA78: d027bf84                 st      %o0, [%fp+var_7C]
F001BA7C: d014203c                 lduh    [%l0+0x3C], %o0
F001BA80: d027bf88                 st      %o0, [%fp+var_78]
F001BA84: d0066014                 ld      [%i1+0x14], %o0
F001BA88: 80a2201b                 cmp     %o0, 0x1B
F001BA8C: 18800003                 bgu     loc_F001BA98
F001BA90: 9210201c                 mov     0x1C, %o1
F001BA94: 92100008                 mov     %o0, %o1
F001BA98: 90100012                 mov     %l2, %o0
F001BA9C: 94102000                 mov     0, %o2
F001BAA0: 7fffda1e                 call    _uiomove
F001BAA4: 96100019                 mov     %i1, %o3
F001BAA8: c02e200c                 clrb    [%i0+0xC]
F001BAAC: 1080006e                 ba      locret_F001BC64
F001BAB0: b0102000                 mov     0, %i0
F001BAB4: 808a2080                 btst    0x80, %o0
F001BAB8: 2280000e                 be,a    loc_F001BAF0
F001BABC: d0042018                 ld      [%l0+0x18], %o0
F001BAC0: d00e200d                 ldub    [%i0+0xD], %o0
F001BAC4: 80a22000                 cmp     %o0, 0
F001BAC8: 2280000a                 be,a    loc_F001BAF0
F001BACC: d0042018                 ld      [%l0+0x18], %o0
F001BAD0: 7fffda61                 call    _ureadc
F001BAD4: 92100019                 mov     %i1, %o1
F001BAD8: a2920000                 orcc    %o0, %g0, %l1
F001BADC: 32800062                 bne,a   locret_F001BC64
F001BAE0: b0100011                 mov     %l1, %i0
F001BAE4: c02e200d                 clrb    [%i0+0xD]
F001BAE8: 1080005f                 ba      locret_F001BC64
F001BAEC: b0102000                 mov     0, %i0
F001BAF0: 80a22000                 cmp     %o0, 0
F001BAF4: 02800005                 be      loc_F001BB08
F001BAF8: d0042040                 ld      [%l0+0x40], %o0
F001BAFC: 808a2100                 btst    0x100, %o0
F001BB00: 22800018                 be,a    loc_F001BB60
F001BB04: d0060000                 ld      [%i0], %o0
F001BB08: 808a2010                 btst    0x10, %o0
F001BB0C: 32800004                 bne,a   loc_F001BB1C
F001BB10: d0060000                 ld      [%i0], %o0
F001BB14: 10800054                 ba      locret_F001BC64
F001BB18: b0102005                 mov     5, %i0
F001BB1C: 808a2004                 btst    4, %o0
F001BB20: 0280000b                 be      loc_F001BB4C
F001BB24: 113c04cf                 sethi   %hi(_active_u), %o0
F001BB28: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001BB2C: d0020000                 ld      [%o0], %o0
F001BB30: d2022014                 ld      [%o0+0x14], %o1
F001BB34: 11000010                 sethi   0x4000, %o0
F001BB38: 808a4008                 btst    %o0, %o1
F001BB3C: 0280004a                 be      locret_F001BC64
F001BB40: b0102023                 mov     0x23, %i0 ! '#'
F001BB44: 10800048                 ba      locret_F001BC64
F001BB48: b010200b                 mov     0xB, %i0
F001BB4C: 9004201c                 add     %l0, 0x1C, %o0! unsigned int
F001BB50: 7fffdaca                 call    _sleep
F001BB54: 9210201c                 mov     0x1C, %o1
F001BB58: 10bfffa1                 ba      loc_F001B9DC
F001BB5C: d0042040                 ld      [%l0+0x40], %o0
F001BB60: 808a2088                 btst    0x88, %o0
F001BB64: 02800005                 be      loc_F001BB78
F001BB68: 90102000                 mov     0, %o0
F001BB6C: 7fffda3a                 call    _ureadc
F001BB70: 92100019                 mov     %i1, %o1
F001BB74: a2100008                 mov     %o0, %l1
F001BB78: d4066014                 ld      [%i1+0x14], %o2
F001BB7C: 80a2a000                 cmp     %o2, 0
F001BB80: 04800019                 ble     loc_F001BBE4
F001BB84: 80a46000                 cmp     %l1, 0
F001BB88: 12800018                 bne     loc_F001BBE8
F001BB8C: 113c042d                 sethi   -0xFEF4C00, %o0
F001BB90: a4042018                 add     %l0, 0x18, %l2
F001BB94: b007bf90                 add     %fp, var_70, %i0
F001BB98: 80a2a064                 cmp     %o2, 0x64 ! 'd'
F001BB9C: 34800002                 bg,a    loc_F001BBA4
F001BBA0: 94102064                 mov     0x64, %o2 ! 'd'
F001BBA4: 90100012                 mov     %l2, %o0
F001BBA8: 40000316                 call    _q_to_b
F001BBAC: 92100018                 mov     %i0, %o1
F001BBB0: 92920000                 orcc    %o0, %g0, %o1
F001BBB4: 0480000c                 ble     loc_F001BBE4
F001BBB8: 90100018                 mov     %i0, %o0
F001BBBC: 94102000                 mov     0, %o2
F001BBC0: 7fffd9d6                 call    _uiomove
F001BBC4: 96100019                 mov     %i1, %o3
F001BBC8: d4066014                 ld      [%i1+0x14], %o2
F001BBCC: 80a2a000                 cmp     %o2, 0
F001BBD0: 04800005                 ble     loc_F001BBE4
F001BBD4: a2100008                 mov     %o0, %l1
F001BBD8: 80a46000                 cmp     %l1, 0
F001BBDC: 02bffff0                 be      loc_F001BB9C
F001BBE0: 80a2a064                 cmp     %o2, 0x64 ! 'd'
F001BBE4: 113c042d                 sethi   -0xFEF4C00, %o0
F001BBE8: d20c204a                 ldub    [%l0+0x4A], %o1
F001BBEC: 90122360                 bset    0x360, %o0
F001BBF0: 920a601f                 and     %o1, 0x1F, %o1
F001BBF4: 932a6001                 sll     %o1, 1, %o1
F001BBF8: d2524008                 ldsh    [%o1+%o0], %o1
F001BBFC: d0042018                 ld      [%l0+0x18], %o0
F001BC00: 80a20009                 cmp     %o0, %o1
F001BC04: 34800018                 bg,a    locret_F001BC64
F001BC08: b0100011                 mov     %l1, %i0
F001BC0C: d0042040                 ld      [%l0+0x40], %o0
F001BC10: 808a2040                 btst    0x40, %o0 ! '@'
F001BC14: 02800005                 be      loc_F001BC28
F001BC18: 900a3fbf                 and     %o0, -0x41, %o0
F001BC1C: d0242040                 st      %o0, [%l0+0x40]
F001BC20: 7fffdc72                 call    _wakeup
F001BC24: 90042018                 add     %l0, 0x18, %o0
F001BC28: d004202c                 ld      [%l0+0x2C], %o0
F001BC2C: 80a22000                 cmp     %o0, 0
F001BC30: 0280000c                 be      loc_F001BC60
F001BC34: 13000004                 sethi   0x1000, %o1
F001BC38: d4042040                 ld      [%l0+0x40], %o2
F001BC3C: 7fffe936                 call    _selwakeup
F001BC40: 920a8009                 and     %o2, %o1, %o1
F001BC44: 400161da                 call    _thread_deallocate
F001BC48: d004202c                 ld      [%l0+0x2C], %o0
F001BC4C: c024202c                 clr     [%l0+0x2C]
F001BC50: d2042040                 ld      [%l0+0x40], %o1
F001BC54: 11000004                 sethi   0x1000, %o0
F001BC58: 902a4008                 andn    %o1, %o0, %o0
F001BC5C: d0242040                 st      %o0, [%l0+0x40]
F001BC60: b0100011                 mov     %l1, %i0
F001BC64: 81c7e008                 ret
F001BC68: 81e80000                 restore
