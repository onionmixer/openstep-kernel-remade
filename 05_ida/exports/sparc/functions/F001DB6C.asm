F001DB6C: 9de3bf98                 save    %sp, -0x68, %sp
F001DB70: 113c04d2a01222f0         set     _mbstat, %l0
F001DB78: 233c04d2                 sethi   -0xFECB800, %l1
F001DB7C: 253c04d3                 sethi   -0xFECB400, %l2
F001DB80: 7fffff45                 call    _m_expand
F001DB84: 90100018                 mov     %i0, %o0
F001DB88: 80a22000                 cmp     %o0, 0
F001DB8C: 12800012                 bne     loc_F001DBD4
F001DB90: 80a62001                 cmp     %i0, 1
F001DB94: 3280000c                 bne,a   loc_F001DBC4
F001DB98: d0042010                 ld      [%l0+0x10], %o0
F001DB9C: d4042014                 ld      [%l0+0x14], %o2
F001DBA0: 9014a168                 or      %l2, 0x168, %o0! unsigned int
F001DBA4: d20462e8                 ld      [%l1+0x2E8], %o1
F001DBA8: 9402a001                 inc     %o2
F001DBAC: d4242014                 st      %o2, [%l0+0x14]
F001DBB0: 92026001                 inc     %o1
F001DBB4: d22462e8                 st      %o1, [%l1+0x2E8]
F001DBB8: 7fffd2b0                 call    _sleep
F001DBBC: 92102018                 mov     0x18, %o1
F001DBC0: 30bffff0                 ba,a    loc_F001DB80
F001DBC4: b0102000                 mov     0, %i0
F001DBC8: 90022001                 inc     %o0
F001DBCC: 10800024                 ba      locret_F001DC5C
F001DBD0: d0242010                 st      %o0, [%l0+0x10]
F001DBD4: 4001e3f9                 call    _spltty
F001DBD8: 233c04d3                 sethi   %hi(_mfree), %l1
F001DBDC: f0046168                 ld      [%l1+%lo(_mfree)], %i0
F001DBE0: 80a62000                 cmp     %i0, 0
F001DBE4: 02800019                 be      loc_F001DC48
F001DBE8: a0100008                 mov     %o0, %l0
F001DBEC: d056200a                 ldsh    [%i0+0xA], %o0
F001DBF0: 80a22000                 cmp     %o0, 0
F001DBF4: 02800004                 be      loc_F001DC04
F001DBF8: 113c042e                 sethi   %hi(aMget_1), %o0! "mget"
F001DBFC: 7fffdd5d                 call    _panic
F001DC00: 901222d0                 bset    %lo(aMget_1), %o0! "mget"
F001DC04: f236200a                 sth     %i1, [%i0+0xA]
F001DC08: 133c04d2921262f0         set     _mbstat, %o1
F001DC10: d012601c                 lduh    [%o1+0x1C], %o0
F001DC14: 952e6001                 sll     %i1, 1, %o2
F001DC18: 90023fff                 inc     -1, %o0
F001DC1C: d032601c                 sth     %o0, [%o1+0x1C]
F001DC20: 9202601c                 inc     0x1C, %o1
F001DC24: d0128009                 lduh    [%o2+%o1], %o0
F001DC28: 90022001                 inc     %o0
F001DC2C: d0328009                 sth     %o0, [%o2+%o1]
F001DC30: 9010200c                 mov     0xC, %o0
F001DC34: d2060000                 ld      [%i0], %o1
F001DC38: d0262004                 st      %o0, [%i0+4]
F001DC3C: d2246168                 st      %o1, [%l1+0x168]
F001DC40: 10800005                 ba      loc_F001DC54
F001DC44: c0260000                 clr     [%i0]
F001DC48: 113c042e                 sethi   %hi(aMMore), %o0! "m_more"
F001DC4C: 7fffdd49                 call    _panic
F001DC50: 901222d8                 bset    %lo(aMMore), %o0! "m_more"
F001DC54: 4001e434                 call    _splx
F001DC58: 90100010                 mov     %l0, %o0
F001DC5C: 81c7e008                 ret
F001DC60: 81e80000                 restore
