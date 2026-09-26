F007AAB0: 9de3bf98                 save    %sp, -0x68, %sp
F007AAB4: e2060000                 ld      [%i0], %l1
F007AAB8: e807a05c                 ld      [%fp+arg_5C], %l4
F007AABC: d0046030                 ld      [%l1+0x30], %o0
F007AAC0: 80a64008                 cmp     %i1, %o0
F007AAC4: 14800031                 bg      locret_F007AB88
F007AAC8: e607a060                 ld      [%fp+arg_60], %l3
F007AACC: d0046024                 ld      [%l1+0x24], %o0
F007AAD0: 80a22000                 cmp     %o0, 0
F007AAD4: 0280002d                 be      locret_F007AB88
F007AAD8: 01000000                 nop
F007AADC: 4000702b                 call    _splusclock
F007AAE0: 01000000                 nop
F007AAE4: a4100008                 mov     %o0, %l2
F007AAE8: d0044000                 ld      [%l1], %o0
F007AAEC: 80a22000                 cmp     %o0, 0
F007AAF0: 12bffffe                 bne     loc_F007AAE8
F007AAF4: 01000000                 nop
F007AAF8: 400070ec                 call    _simple_lock_try
F007AAFC: 90100011                 mov     %l1, %o0
F007AB00: 80a22000                 cmp     %o0, 0
F007AB04: 02bffff9                 be      loc_F007AAE8
F007AB08: 01000000                 nop
F007AB0C: e0046028                 ld      [%l1+0x28], %l0
F007AB10: d204602c                 ld      [%l1+0x2C], %o1
F007AB14: 90042020                 add     %l0, 0x20, %o0 ! ' '
F007AB18: 80a20009                 cmp     %o0, %o1
F007AB1C: 12800007                 bne     loc_F007AB38
F007AB20: d0246028                 st      %o0, [%l1+0x28]
F007AB24: e0246028                 st      %l0, [%l1+0x28]
F007AB28: c0244000                 clr     [%l1]
F007AB2C: 4000707e                 call    _splx
F007AB30: 90100012                 mov     %l2, %o0
F007AB34: 30800015                 ba,a    locret_F007AB88
F007AB38: c0244000                 clr     [%l1]
F007AB3C: 4000707a                 call    _splx
F007AB40: 90100012                 mov     %l2, %o0
F007AB44: f4240000                 st      %i2, [%l0]
F007AB48: f6242004                 st      %i3, [%l0+4]
F007AB4C: f8242008                 st      %i4, [%l0+8]
F007AB50: fa24200c                 st      %i5, [%l0+0xC]
F007AB54: e8242010                 st      %l4, [%l0+0x10]
F007AB58: 40007434                 call    _event_get
F007AB5C: e6242014                 st      %l3, [%l0+0x14]
F007AB60: d0242018                 st      %o0, [%l0+0x18]
F007AB64: f224201c                 st      %i1, [%l0+0x1C]
F007AB68: d0046018                 ld      [%l1+0x18], %o0
F007AB6C: 80a22000                 cmp     %o0, 0
F007AB70: 02800006                 be      locret_F007AB88
F007AB74: 90100018                 mov     %i0, %o0
F007AB78: 133c01ea92126390         set     sub_F007AB90, %o1
F007AB80: 40000069                 call    _kern_serv_callout
F007AB84: 94100011                 mov     %l1, %o2
F007AB88: 81c7e008                 ret
F007AB8C: 81e80000                 restore
