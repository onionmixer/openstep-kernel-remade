F006B604: 9de3bf90                 save    %sp, -0x70, %sp
F006B608: 113c04cf                 sethi   %hi(_active_u), %o0
F006B60C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F006B610: d002201c                 ld      [%o0+0x1C], %o0
F006B614: d0522002                 ldsh    [%o0+2], %o0
F006B618: 80a22000                 cmp     %o0, 0
F006B61C: 128000a2                 bne     locret_F006B8A4
F006B620: b8062014                 add     %i0, 0x14, %i4
F006B624: d0062018                 ld      [%i0+0x18], %o0
F006B628: d2062010                 ld      [%i0+0x10], %o1
F006B62C: 92020009                 add     %o0, %o1, %o1
F006B630: d0062014                 ld      [%i0+0x14], %o0
F006B634: 80a22000                 cmp     %o0, 0
F006B638: 0680009b                 bl      locret_F006B8A4
F006B63C: d2262018                 st      %o1, [%i0+0x18]
F006B640: 80a2602b                 cmp     %o1, 0x2B ! '+'
F006B644: 08800098                 bleu    locret_F006B8A4
F006B648: 01000000                 nop
F006B64C: e456202e                 ldsh    [%i0+0x2E], %l2
F006B650: 80a4a014                 cmp     %l2, 0x14
F006B654: 08800094                 bleu    locret_F006B8A4
F006B658: 90027fe8                 add     %o1, -0x18, %o0
F006B65C: 80a48008                 cmp     %l2, %o0
F006B660: 18800091                 bgu     locret_F006B8A4
F006B664: aa07bff4                 add     %fp, var_C, %l5
F006B668: c027bff4                 clr     [%fp+var_C]
F006B66C: 80a4a000                 cmp     %l2, 0
F006B670: 0480006e                 ble     loc_F006B828
F006B674: b006202c                 inc     0x2C, %i0 ! ','
F006B678: 373c04d3                 sethi   -0xFECB400, %i3
F006B67C: b4102001                 mov     1, %i2
F006B680: 113c04d2a81222f0         set     _mbstat, %l4
F006B688: 333c0447                 sethi   -0xFEEE400, %i1
F006B68C: 2d3c04d2                 sethi   -0xFECB800, %l6
F006B690: 113c04d2ae122360         set     _mclrefcnt, %l7
F006B698: 4000ad48                 call    _spltty
F006B69C: 01000000                 nop
F006B6A0: e206e168                 ld      [%i3+0x168], %l1
F006B6A4: 80a46000                 cmp     %l1, 0
F006B6A8: 02800015                 be      loc_F006B6FC
F006B6AC: a0100008                 mov     %o0, %l0
F006B6B0: d054600a                 ldsh    [%l1+0xA], %o0
F006B6B4: 80a22000                 cmp     %o0, 0
F006B6B8: 02800004                 be      loc_F006B6C8
F006B6BC: 113c043f                 sethi   %hi(aMget_15), %o0! "mget"
F006B6C0: 7ffea6ac                 call    _panic
F006B6C4: 901220e0                 bset    %lo(aMget_15), %o0! "mget"
F006B6C8: f434600a                 sth     %i2, [%l1+0xA]
F006B6CC: d015201c                 lduh    [%l4+0x1C], %o0
F006B6D0: d215201e                 lduh    [%l4+0x1E], %o1
F006B6D4: 90023fff                 inc     -1, %o0
F006B6D8: d035201c                 sth     %o0, [%l4+0x1C]
F006B6DC: 92026001                 inc     %o1
F006B6E0: d235201e                 sth     %o1, [%l4+0x1E]
F006B6E4: 9010200c                 mov     0xC, %o0
F006B6E8: d2044000                 ld      [%l1], %o1
F006B6EC: d0246004                 st      %o0, [%l1+4]
F006B6F0: d226e168                 st      %o1, [%i3+0x168]
F006B6F4: 10800006                 ba      loc_F006B70C
F006B6F8: c0244000                 clr     [%l1]
F006B6FC: 90102001                 mov     1, %o0
F006B700: 7ffec91b                 call    _m_more
F006B704: 92102001                 mov     1, %o1
F006B708: a2100008                 mov     %o0, %l1
F006B70C: 4000ad86                 call    _splx
F006B710: 90100010                 mov     %l0, %o0
F006B714: 80a46000                 cmp     %l1, 0
F006B718: 02800057                 be      loc_F006B874
F006B71C: d006613c                 ld      [%i1+0x13C], %o0
F006B720: 91322001                 srl     %o0, 1, %o0
F006B724: 80a48008                 cmp     %l2, %o0
F006B728: 0a800031                 bcs     loc_F006B7EC
F006B72C: 80a4a070                 cmp     %l2, 0x70 ! 'p'
F006B730: 4000ad22                 call    _spltty
F006B734: 01000000                 nop
F006B738: d205a358                 ld      [%l6+0x358], %o1
F006B73C: 80a26000                 cmp     %o1, 0
F006B740: 12800006                 bne     loc_F006B758
F006B744: a6100008                 mov     %o0, %l3
F006B748: 90102001                 mov     1, %o0
F006B74C: 92102001                 mov     1, %o1
F006B750: 7ffec7f4                 call    _m_clalloc
F006B754: 94102000                 mov     0, %o2
F006B758: e005a358                 ld      [%l6+0x358], %l0
F006B75C: 80a42000                 cmp     %l0, 0
F006B760: 0280000d                 be      loc_F006B794
F006B764: 113c04d2                 sethi   %hi(_mbutl), %o0
F006B768: d2022350                 ld      [%o0+%lo(_mbutl)], %o1
F006B76C: 92240009                 sub     %l0, %o1, %o1
F006B770: 933a600a                 sra     %o1, 10, %o1
F006B774: d00a4017                 ldub    [%o1+%l7], %o0
F006B778: 90022001                 inc     %o0
F006B77C: d02a4017                 stb     %o0, [%o1+%l7]
F006B780: d005200c                 ld      [%l4+0xC], %o0
F006B784: 90023fff                 inc     -1, %o0
F006B788: d025200c                 st      %o0, [%l4+0xC]
F006B78C: d0040000                 ld      [%l0], %o0
F006B790: d025a358                 st      %o0, [%l6+0x358]
F006B794: 4000ad64                 call    _splx
F006B798: 90100013                 mov     %l3, %o0
F006B79C: 80a42000                 cmp     %l0, 0
F006B7A0: 02800007                 be      loc_F006B7BC
F006B7A4: 90240011                 sub     %l0, %l1, %o0
F006B7A8: d0246004                 st      %o0, [%l1+4]
F006B7AC: 90102400                 mov     0x400, %o0
F006B7B0: d0346008                 sth     %o0, [%l1+8]
F006B7B4: 10800004                 ba      loc_F006B7C4
F006B7B8: f434600c                 sth     %i2, [%l1+0xC]
F006B7BC: 90102070                 mov     0x70, %o0 ! 'p'
F006B7C0: d0346008                 sth     %o0, [%l1+8]
F006B7C4: d4546008                 ldsh    [%l1+8], %o2
F006B7C8: d006613c                 ld      [%i1+0x13C], %o0
F006B7CC: 80a28008                 cmp     %o2, %o0
F006B7D0: 12800007                 bne     loc_F006B7EC
F006B7D4: 80a4a070                 cmp     %l2, 0x70 ! 'p'
F006B7D8: 80a28012                 cmp     %o2, %l2
F006B7DC: 0a800007                 bcs     loc_F006B7F8
F006B7E0: a010000a                 mov     %o2, %l0
F006B7E4: 10800005                 ba      loc_F006B7F8
F006B7E8: a0100012                 mov     %l2, %l0
F006B7EC: 14800003                 bg      loc_F006B7F8
F006B7F0: a0102070                 mov     0x70, %l0 ! 'p'
F006B7F4: a0100012                 mov     %l2, %l0
F006B7F8: e0346008                 sth     %l0, [%l1+8]
F006B7FC: 90100018                 mov     %i0, %o0! void *
F006B800: 94100010                 mov     %l0, %o2! size_t
F006B804: b006000a                 add     %i0, %o2, %i0
F006B808: d2046004                 ld      [%l1+4], %o1! void *
F006B80C: a424800a                 sub     %l2, %o2, %l2
F006B810: 4000a4c0                 call    _bcopy
F006B814: 92044009                 add     %l1, %o1, %o1
F006B818: e2254000                 st      %l1, [%l5]
F006B81C: 80a4a000                 cmp     %l2, 0
F006B820: 14bfff9e                 bg      loc_F006B698
F006B824: aa100011                 mov     %l1, %l5
F006B828: 113c043f941220cc         set     unk_F010FCCC, %o2
F006B830: d202a004                 ld      [%o2+4], %o1
F006B834: d0072028                 ld      [%i4+0x28], %o0
F006B838: 80a24008                 cmp     %o1, %o0
F006B83C: 22800015                 be,a    loc_F006B890
F006B840: d007bff4                 ld      [%fp+var_C], %o0
F006B844: d202bffc                 ld      [%o2-4], %o1
F006B848: 80a26000                 cmp     %o1, 0
F006B84C: 0280000f                 be      loc_F006B888
F006B850: 113c043f                 sethi   -0xFEF0400, %o0
F006B854: d0526026                 ldsh    [%o1+0x26], %o0
F006B858: 80a22001                 cmp     %o0, 1
F006B85C: 12800009                 bne     loc_F006B880
F006B860: 90023fff                 inc     -1, %o0
F006B864: 7fff0570                 call    _rtfree
F006B868: 90100009                 mov     %o1, %o0
F006B86C: 10800007                 ba      loc_F006B888
F006B870: 113c043f                 sethi   -0xFEF0400, %o0
F006B874: 7ffec8fc                 call    _m_freem
F006B878: d007bff4                 ld      [%fp+var_C], %o0
F006B87C: 3080000a                 ba,a    locret_F006B8A4
F006B880: d0326026                 sth     %o0, [%o1+0x26]
F006B884: 113c043f                 sethi   -0xFEF0400, %o0
F006B888: c02220c8                 clr     [%o0+0xC8]
F006B88C: d007bff4                 ld      [%fp+var_C], %o0
F006B890: 92102000                 mov     0, %o1
F006B894: 153c043f9412a0c8         set     unk_F010FCC8, %o2
F006B89C: 7fff1ef9                 call    _ip_output
F006B8A0: 96102021                 mov     0x21, %o3 ! '!'
F006B8A4: 81c7e008                 ret
F006B8A8: 81e80000                 restore
