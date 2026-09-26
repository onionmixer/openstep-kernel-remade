F001D95C: 9de3bf98                 save    %sp, -0x68, %sp
F001D960: 4001e496                 call    _spltty
F001D964: a0100018                 mov     %i0, %l0
F001D968: 253c04d3                 sethi   %hi(_mfree), %l2
F001D96C: f004a168                 ld      [%l2+%lo(_mfree)], %i0
F001D970: 80a62000                 cmp     %i0, 0
F001D974: 02800019                 be      loc_F001D9D8
F001D978: a2100008                 mov     %o0, %l1
F001D97C: d056200a                 ldsh    [%i0+0xA], %o0
F001D980: 80a22000                 cmp     %o0, 0
F001D984: 02800004                 be      loc_F001D994
F001D988: 113c042e                 sethi   %hi(aMget), %o0! "mget"
F001D98C: 7fffddf9                 call    _panic
F001D990: 901222b8                 bset    %lo(aMget), %o0! "mget"
F001D994: f236200a                 sth     %i1, [%i0+0xA]
F001D998: 133c04d2921262f0         set     _mbstat, %o1
F001D9A0: d012601c                 lduh    [%o1+0x1C], %o0
F001D9A4: 952e6001                 sll     %i1, 1, %o2
F001D9A8: 90023fff                 inc     -1, %o0
F001D9AC: d032601c                 sth     %o0, [%o1+0x1C]
F001D9B0: 9202601c                 inc     0x1C, %o1
F001D9B4: d0128009                 lduh    [%o2+%o1], %o0
F001D9B8: 90022001                 inc     %o0
F001D9BC: d0328009                 sth     %o0, [%o2+%o1]
F001D9C0: 9010200c                 mov     0xC, %o0
F001D9C4: d2060000                 ld      [%i0], %o1
F001D9C8: d0262004                 st      %o0, [%i0+4]
F001D9CC: d224a168                 st      %o1, [%l2+0x168]
F001D9D0: 10800006                 ba      loc_F001D9E8
F001D9D4: c0260000                 clr     [%i0]
F001D9D8: 90100010                 mov     %l0, %o0
F001D9DC: 40000064                 call    _m_more
F001D9E0: 92100019                 mov     %i1, %o1
F001D9E4: b0100008                 mov     %o0, %i0
F001D9E8: 4001e4cf                 call    _splx
F001D9EC: 90100011                 mov     %l1, %o0
F001D9F0: 81c7e008                 ret
F001D9F4: 81e80000                 restore
