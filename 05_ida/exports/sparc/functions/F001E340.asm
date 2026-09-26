F001E340: 9de3bf98                 save    %sp, -0x68, %sp
F001E344: 4001e21d                 call    _spltty
F001E348: a4100018                 mov     %i0, %l2
F001E34C: 233c04d3                 sethi   %hi(_mfree), %l1
F001E350: f0046168                 ld      [%l1+%lo(_mfree)], %i0
F001E354: 80a62000                 cmp     %i0, 0
F001E358: 02800018                 be      loc_F001E3B8
F001E35C: a0100008                 mov     %o0, %l0
F001E360: d056200a                 ldsh    [%i0+0xA], %o0
F001E364: 80a22000                 cmp     %o0, 0
F001E368: 02800004                 be      loc_F001E378
F001E36C: 113c042e                 sethi   %hi(aMget_4), %o0! "mget"
F001E370: 7fffdb80                 call    _panic
F001E374: 90122310                 bset    %lo(aMget_4), %o0! "mget"
F001E378: 90102001                 mov     1, %o0
F001E37C: d036200a                 sth     %o0, [%i0+0xA]
F001E380: 153c04d29412a2f0         set     _mbstat, %o2
F001E388: d012a01c                 lduh    [%o2+0x1C], %o0
F001E38C: d212a01e                 lduh    [%o2+0x1E], %o1
F001E390: 90023fff                 inc     -1, %o0
F001E394: d032a01c                 sth     %o0, [%o2+0x1C]
F001E398: 92026001                 inc     %o1
F001E39C: d232a01e                 sth     %o1, [%o2+0x1E]
F001E3A0: 9010200c                 mov     0xC, %o0
F001E3A4: d2060000                 ld      [%i0], %o1
F001E3A8: d0262004                 st      %o0, [%i0+4]
F001E3AC: d2246168                 st      %o1, [%l1+0x168]
F001E3B0: 10800006                 ba      loc_F001E3C8
F001E3B4: c0260000                 clr     [%i0]
F001E3B8: 9010001c                 mov     %i4, %o0
F001E3BC: 7ffffdec                 call    _m_more
F001E3C0: 92102001                 mov     1, %o1
F001E3C4: b0100008                 mov     %o0, %i0
F001E3C8: 4001e257                 call    _splx
F001E3CC: 90100010                 mov     %l0, %o0
F001E3D0: 80a62000                 cmp     %i0, 0
F001E3D4: 0280000a                 be      loc_F001E3FC
F001E3D8: 90268018                 sub     %i2, %i0, %o0
F001E3DC: d0262004                 st      %o0, [%i0+4]
F001E3E0: f6362008                 sth     %i3, [%i0+8]
F001E3E4: 90102002                 mov     2, %o0
F001E3E8: d036200c                 sth     %o0, [%i0+0xC]
F001E3EC: e4262010                 st      %l2, [%i0+0x10]
F001E3F0: f2262014                 st      %i1, [%i0+0x14]
F001E3F4: 10800003                 ba      locret_F001E400
F001E3F8: c0262018                 clr     [%i0+0x18]
F001E3FC: b0102000                 mov     0, %i0
F001E400: 81c7e008                 ret
F001E404: 81e80000                 restore
