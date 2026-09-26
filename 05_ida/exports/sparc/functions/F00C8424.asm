F00C8424: 9de3bf98                 save    %sp, -0x68, %sp
F00C8428: 7ffff6c2                 call    _IOMalloc
F00C842C: 90102018                 mov     0x18, %o0
F00C8430: a0100008                 mov     %o0, %l0
F00C8434: f0240000                 st      %i0, [%l0]
F00C8438: f2242004                 st      %i1, [%l0+4]
F00C843C: f4242008                 st      %i2, [%l0+8]
F00C8440: f634200c                 sth     %i3, [%l0+0xC]
F00C8444: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C8448: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C844C: 133c0504                 sethi   %hi(paLock), %o1
F00C8450: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C8454: 4000a507                 call    _objc_msgSend
F00C8458: f834200e                 sth     %i4, [%l0+0xE]
F00C845C: 153c04cc                 sethi   %hi(dword_F01330A8), %o2
F00C8460: d002a0a8                 ld      [%o2+%lo(dword_F01330A8)], %o0
F00C8464: 9212a0a8                 or      %o2, %lo(dword_F01330A8), %o1
F00C8468: 80a20009                 cmp     %o0, %o1
F00C846C: 32800007                 bne,a   loc_F00C8488
F00C8470: d0026004                 ld      [%o1+4], %o0
F00C8474: e022a0a8                 st      %l0, [%o2+%lo(dword_F01330A8)]
F00C8478: e0226004                 st      %l0, [%o1+4]
F00C847C: d2242010                 st      %o1, [%l0+0x10]
F00C8480: 10800006                 ba      loc_F00C8498
F00C8484: d2242014                 st      %o1, [%l0+0x14]
F00C8488: d0242014                 st      %o0, [%l0+0x14]
F00C848C: d2242010                 st      %o1, [%l0+0x10]
F00C8490: e0226004                 st      %l0, [%o1+4]
F00C8494: e0222010                 st      %l0, [%o0+0x10]
F00C8498: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C849C: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C84A0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C84A4: 4000a4f3                 call    _objc_msgSend
F00C84A8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C84AC: 81c7e008                 ret
F00C84B0: 81e80000                 restore
