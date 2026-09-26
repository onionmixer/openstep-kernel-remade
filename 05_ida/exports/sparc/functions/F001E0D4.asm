F001E0D4: 9de3bf98                 save    %sp, -0x68, %sp
F001E0D8: d0062004                 ld      [%i0+4], %o0
F001E0DC: 90020019                 add     %o0, %i1, %o0
F001E0E0: 80a2207c                 cmp     %o0, 0x7C ! '|'
F001E0E4: 1880000b                 bgu     loc_F001E110
F001E0E8: 80a66070                 cmp     %i1, 0x70 ! 'p'
F001E0EC: d2060000                 ld      [%i0], %o1
F001E0F0: 80a26000                 cmp     %o1, 0
F001E0F4: 02800006                 be      loc_F001E10C
F001E0F8: a2100018                 mov     %i0, %l1
F001E0FC: d0546008                 ldsh    [%l1+8], %o0
F001E100: b0100009                 mov     %o1, %i0
F001E104: 1080002e                 ba      loc_F001E1BC
F001E108: b2264008                 sub     %i1, %o0, %i1
F001E10C: 80a66070                 cmp     %i1, 0x70 ! 'p'
F001E110: 1480005d                 bg      loc_F001E284
F001E114: 01000000                 nop
F001E118: 4001e2a8                 call    _spltty
F001E11C: 253c04d3                 sethi   %hi(_mfree), %l2
F001E120: e204a168                 ld      [%l2+%lo(_mfree)], %l1
F001E124: 80a46000                 cmp     %l1, 0
F001E128: 0280001b                 be      loc_F001E194
F001E12C: a0100008                 mov     %o0, %l0
F001E130: d054600a                 ldsh    [%l1+0xA], %o0
F001E134: 80a22000                 cmp     %o0, 0
F001E138: 02800004                 be      loc_F001E148
F001E13C: 113c042e                 sethi   %hi(aMget_3), %o0! "mget"
F001E140: 7fffdc0c                 call    _panic
F001E144: 90122308                 bset    %lo(aMget_3), %o0! "mget"
F001E148: 133c04d2                 sethi   %hi(_mbstat), %o1
F001E14C: d016200a                 lduh    [%i0+0xA], %o0
F001E150: 921262f0                 bset    %lo(_mbstat), %o1
F001E154: d034600a                 sth     %o0, [%l1+0xA]
F001E158: d012601c                 lduh    [%o1+0x1C], %o0
F001E15C: 90023fff                 inc     -1, %o0
F001E160: d032601c                 sth     %o0, [%o1+0x1C]
F001E164: d456200a                 ldsh    [%i0+0xA], %o2
F001E168: 9202601c                 inc     0x1C, %o1
F001E16C: 952aa001                 sll     %o2, 1, %o2
F001E170: d0128009                 lduh    [%o2+%o1], %o0
F001E174: 90022001                 inc     %o0
F001E178: d0328009                 sth     %o0, [%o2+%o1]
F001E17C: 9010200c                 mov     0xC, %o0
F001E180: d2044000                 ld      [%l1], %o1
F001E184: d0246004                 st      %o0, [%l1+4]
F001E188: d224a168                 st      %o1, [%l2+0x168]
F001E18C: 10800006                 ba      loc_F001E1A4
F001E190: c0244000                 clr     [%l1]
F001E194: d256200a                 ldsh    [%i0+0xA], %o1
F001E198: 7ffffe75                 call    _m_more
F001E19C: 90102000                 mov     0, %o0
F001E1A0: a2100008                 mov     %o0, %l1
F001E1A4: 4001e2e0                 call    _splx
F001E1A8: 90100010                 mov     %l0, %o0
F001E1AC: 80a46000                 cmp     %l1, 0
F001E1B0: 02800035                 be      loc_F001E284
F001E1B4: 01000000                 nop
F001E1B8: c0346008                 clrh    [%l1+8]
F001E1BC: d2046004                 ld      [%l1+4], %o1
F001E1C0: 9010207c                 mov     0x7C, %o0 ! '|'
F001E1C4: a4220009                 sub     %o0, %o1, %l2
F001E1C8: d4546008                 ldsh    [%l1+8], %o2! size_t
F001E1CC: 90066020                 add     %i1, 0x20, %o0 ! ' '
F001E1D0: a024800a                 sub     %l2, %o2, %l0
F001E1D4: 80a40008                 cmp     %l0, %o0
F001E1D8: 04800003                 ble     loc_F001E1E4
F001E1DC: d2562008                 ldsh    [%i0+8], %o1
F001E1E0: a0100008                 mov     %o0, %l0
F001E1E4: 80a40009                 cmp     %l0, %o1
F001E1E8: 34800002                 bg,a    loc_F001E1F0
F001E1EC: a0100009                 mov     %o1, %l0
F001E1F0: d0062004                 ld      [%i0+4], %o0
F001E1F4: d2046004                 ld      [%l1+4], %o1
F001E1F8: 90060008                 add     %i0, %o0, %o0! void *
F001E1FC: 92044009                 add     %l1, %o1, %o1
F001E200: 9202400a                 add     %o1, %o2, %o1! void *
F001E204: 4001da43                 call    _bcopy
F001E208: 94100010                 mov     %l0, %o2
F001E20C: d0146008                 lduh    [%l1+8], %o0
F001E210: 90020010                 add     %o0, %l0, %o0
F001E214: d0346008                 sth     %o0, [%l1+8]
F001E218: d0162008                 lduh    [%i0+8], %o0
F001E21C: 90220010                 sub     %o0, %l0, %o0
F001E220: d0362008                 sth     %o0, [%i0+8]
F001E224: 912a2010                 sll     %o0, 16, %o0
F001E228: 80a22000                 cmp     %o0, 0
F001E22C: 02800006                 be      loc_F001E244
F001E230: b2264010                 sub     %i1, %l0, %i1
F001E234: d0062004                 ld      [%i0+4], %o0
F001E238: 90020010                 add     %o0, %l0, %o0
F001E23C: 10800005                 ba      loc_F001E250
F001E240: d0262004                 st      %o0, [%i0+4]
F001E244: 7ffffe1c                 call    _m_free
F001E248: 90100018                 mov     %i0, %o0
F001E24C: b0100008                 mov     %o0, %i0
F001E250: 80a66000                 cmp     %i1, 0
F001E254: 04800004                 ble     loc_F001E264
F001E258: 80a62000                 cmp     %i0, 0
F001E25C: 32bfffdc                 bne,a   loc_F001E1CC
F001E260: d4546008                 ldsh    [%l1+8], %o2
F001E264: 80a66000                 cmp     %i1, 0
F001E268: 14800005                 bg      loc_F001E27C
F001E26C: 01000000                 nop
F001E270: f0244000                 st      %i0, [%l1]
F001E274: 10800007                 ba      locret_F001E290
F001E278: b0100011                 mov     %l1, %i0
F001E27C: 7ffffe0e                 call    _m_free
F001E280: 90100011                 mov     %l1, %o0
F001E284: 7ffffe78                 call    _m_freem
F001E288: 90100018                 mov     %i0, %o0
F001E28C: b0102000                 mov     0, %i0
F001E290: 81c7e008                 ret
F001E294: 81e80000                 restore
