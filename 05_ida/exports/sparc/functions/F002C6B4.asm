F002C6B4: 9de3bf98                 save    %sp, -0x68, %sp
F002C6B8: 90102000                 mov     0, %o0
F002C6BC: 7fffc4a8                 call    _m_get
F002C6C0: 92102002                 mov     2, %o1
F002C6C4: a0920000                 orcc    %o0, %g0, %l0
F002C6C8: 32800005                 bne,a   loc_F002C6DC
F002C6CC: f0240000                 st      %i0, [%l0]
F002C6D0: 7fffc565                 call    _m_freem
F002C6D4: 90100018                 mov     %i0, %o0
F002C6D8: 30800049                 ba,a    locret_F002C7FC
F002C6DC: 90102024                 mov     0x24, %o0 ! '$'
F002C6E0: d4042004                 ld      [%l0+4], %o2
F002C6E4: d0342008                 sth     %o0, [%l0+8]
F002C6E8: d216c000                 lduh    [%i3], %o1
F002C6EC: 9004000a                 add     %l0, %o2, %o0
F002C6F0: d2322004                 sth     %o1, [%o0+4]
F002C6F4: d216e002                 lduh    [%i3+2], %o1
F002C6F8: d2322006                 sth     %o1, [%o0+6]
F002C6FC: d216e004                 lduh    [%i3+4], %o1
F002C700: d2322008                 sth     %o1, [%o0+8]
F002C704: d216e006                 lduh    [%i3+6], %o1
F002C708: d232200a                 sth     %o1, [%o0+0xA]
F002C70C: d216e008                 lduh    [%i3+8], %o1
F002C710: d232200c                 sth     %o1, [%o0+0xC]
F002C714: d216e00a                 lduh    [%i3+0xA], %o1
F002C718: d232200e                 sth     %o1, [%o0+0xE]
F002C71C: d216e00c                 lduh    [%i3+0xC], %o1
F002C720: d2322010                 sth     %o1, [%o0+0x10]
F002C724: d216e00e                 lduh    [%i3+0xE], %o1
F002C728: d2322012                 sth     %o1, [%o0+0x12]
F002C72C: d2168000                 lduh    [%i2], %o1
F002C730: d2322014                 sth     %o1, [%o0+0x14]
F002C734: d216a002                 lduh    [%i2+2], %o1
F002C738: d2322016                 sth     %o1, [%o0+0x16]
F002C73C: d216a004                 lduh    [%i2+4], %o1
F002C740: d2322018                 sth     %o1, [%o0+0x18]
F002C744: d216a006                 lduh    [%i2+6], %o1
F002C748: d232201a                 sth     %o1, [%o0+0x1A]
F002C74C: d216a008                 lduh    [%i2+8], %o1
F002C750: d232201c                 sth     %o1, [%o0+0x1C]
F002C754: d216a00a                 lduh    [%i2+0xA], %o1
F002C758: d232201e                 sth     %o1, [%o0+0x1E]
F002C75C: d216a00c                 lduh    [%i2+0xC], %o1
F002C760: d2322020                 sth     %o1, [%o0+0x20]
F002C764: d216a00e                 lduh    [%i2+0xE], %o1
F002C768: d2322022                 sth     %o1, [%o0+0x22]
F002C76C: d2164000                 lduh    [%i1], %o1
F002C770: d234000a                 sth     %o1, [%l0+%o2]
F002C774: d2166002                 lduh    [%i1+2], %o1
F002C778: 4001a910                 call    _spltty
F002C77C: d2322002                 sth     %o1, [%o0+2]
F002C780: 133c04d0                 sethi   %hi(dword_F0134168), %o1
F002C784: d4026168                 ld      [%o1+%lo(dword_F0134168)], %o2
F002C788: 96126168                 or      %o1, %lo(dword_F0134168), %o3
F002C78C: d202e004                 ld      [%o3+4], %o1
F002C790: 80a28009                 cmp     %o2, %o1
F002C794: 06800005                 bl      loc_F002C7A8
F002C798: b0100008                 mov     %o0, %i0
F002C79C: 7fffc532                 call    _m_freem
F002C7A0: 90100010                 mov     %l0, %o0
F002C7A4: 3080000d                 ba,a    loc_F002C7D8
F002C7A8: c024207c                 clr     [%l0+0x7C]
F002C7AC: d002fffc                 ld      [%o3-4], %o0
F002C7B0: 80a22000                 cmp     %o0, 0
F002C7B4: 32800003                 bne,a   loc_F002C7C0
F002C7B8: e022207c                 st      %l0, [%o0+0x7C]
F002C7BC: e022fff8                 st      %l0, [%o3-8]
F002C7C0: 133c04d092126160         set     _rawintrq, %o1
F002C7C8: d0026008                 ld      [%o1+8], %o0
F002C7CC: e0226004                 st      %l0, [%o1+4]
F002C7D0: 90022001                 inc     %o0
F002C7D4: d0226008                 st      %o0, [%o1+8]
F002C7D8: 4001a953                 call    _splx
F002C7DC: 90100018                 mov     %i0, %o0
F002C7E0: 133c04d8                 sethi   %hi(_netisr), %o1
F002C7E4: d40263d8                 ld      [%o1+%lo(_netisr)], %o2
F002C7E8: 113c04d8901223e0         set     _soft_net_wakeup, %o0
F002C7F0: 9412a001                 bset    1, %o2
F002C7F4: 7fff997d                 call    _wakeup
F002C7F8: d42263d8                 st      %o2, [%o1+%lo(_netisr)]
F002C7FC: 81c7e008                 ret
F002C800: 81e80000                 restore
