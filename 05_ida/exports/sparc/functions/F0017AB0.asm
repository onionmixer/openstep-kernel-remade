F0017AB0: 9de3bf98                 save    %sp, -0x68, %sp
F0017AB4: 40000d8d                 call    _ttynty
F0017AB8: 90100018                 mov     %i0, %o0
F0017ABC: 4001fc3f                 call    _spltty
F0017AC0: a0100008                 mov     %o0, %l0
F0017AC4: 80a66001                 cmp     %i1, 1
F0017AC8: 02800006                 be      loc_F0017AE0
F0017ACC: a2100008                 mov     %o0, %l1
F0017AD0: 80a66002                 cmp     %i1, 2
F0017AD4: 02800018                 be      loc_F0017B34
F0017AD8: 113c042d                 sethi   -0xFEF4C00, %o0
F0017ADC: 30800027                 ba,a    loc_F0017B78
F0017AE0: 7fffffde                 call    _ttnread
F0017AE4: 90100010                 mov     %l0, %o0
F0017AE8: 80a22000                 cmp     %o0, 0
F0017AEC: 14800027                 bg      loc_F0017B88
F0017AF0: 11000020                 sethi   0x8000, %o0
F0017AF4: d2042010                 ld      [%l0+0x10], %o1
F0017AF8: 808a4008                 btst    %o0, %o1
F0017AFC: 12800006                 bne     loc_F0017B14
F0017B00: 01000000                 nop
F0017B04: d0062040                 ld      [%i0+0x40], %o0
F0017B08: 808a2010                 btst    0x10, %o0
F0017B0C: 0280001f                 be      loc_F0017B88
F0017B10: 01000000                 nop
F0017B14: 7ffff94b                 call    _selthreadcache
F0017B18: 90062028                 add     %i0, 0x28, %o0 ! '('
F0017B1C: 80a22000                 cmp     %o0, 0
F0017B20: 02800016                 be      loc_F0017B78
F0017B24: 01000000                 nop
F0017B28: d0062040                 ld      [%i0+0x40], %o0
F0017B2C: 10800012                 ba      loc_F0017B74
F0017B30: 90122800                 bset    0x800, %o0
F0017B34: d20e204a                 ldub    [%i0+0x4A], %o1
F0017B38: 90122360                 bset    0x360, %o0
F0017B3C: 920a601f                 and     %o1, 0x1F, %o1
F0017B40: 932a6001                 sll     %o1, 1, %o1
F0017B44: d2524008                 ldsh    [%o1+%o0], %o1
F0017B48: d0062018                 ld      [%i0+0x18], %o0
F0017B4C: 80a20009                 cmp     %o0, %o1
F0017B50: 0480000e                 ble     loc_F0017B88
F0017B54: 01000000                 nop
F0017B58: 7ffff93a                 call    _selthreadcache
F0017B5C: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F0017B60: 80a22000                 cmp     %o0, 0
F0017B64: 02800005                 be      loc_F0017B78
F0017B68: 13000004                 sethi   0x1000, %o1
F0017B6C: d0062040                 ld      [%i0+0x40], %o0
F0017B70: 90120009                 bset    %o1, %o0
F0017B74: d0262040                 st      %o0, [%i0+0x40]
F0017B78: 4001fc6b                 call    _splx
F0017B7C: 90100011                 mov     %l1, %o0
F0017B80: 10800005                 ba      locret_F0017B94
F0017B84: b0102000                 mov     0, %i0
F0017B88: 4001fc67                 call    _splx
F0017B8C: 90100011                 mov     %l1, %o0
F0017B90: b0102001                 mov     1, %i0
F0017B94: 81c7e008                 ret
F0017B98: 81e80000                 restore
