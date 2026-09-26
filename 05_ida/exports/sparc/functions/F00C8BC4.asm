F00C8BC4: 9de3bf98                 save    %sp, -0x68, %sp
F00C8BC8: 7ffff4da                 call    _IOMalloc
F00C8BCC: 90102018                 mov     0x18, %o0
F00C8BD0: 92102005                 mov     5, %o1
F00C8BD4: a0100008                 mov     %o0, %l0
F00C8BD8: d2240000                 st      %o1, [%l0]
F00C8BDC: f0242004                 st      %i0, [%l0+4]
F00C8BE0: c0242008                 clr     [%l0+8]
F00C8BE4: c034200c                 clrh    [%l0+0xC]
F00C8BE8: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C8BEC: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C8BF0: 133c0504                 sethi   %hi(paLock), %o1
F00C8BF4: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C8BF8: 4000a31e                 call    _objc_msgSend
F00C8BFC: c034200e                 clrh    [%l0+0xE]
F00C8C00: 153c04cc                 sethi   %hi(dword_F01330A8), %o2
F00C8C04: d002a0a8                 ld      [%o2+%lo(dword_F01330A8)], %o0
F00C8C08: 9212a0a8                 or      %o2, %lo(dword_F01330A8), %o1
F00C8C0C: 80a20009                 cmp     %o0, %o1
F00C8C10: 32800007                 bne,a   loc_F00C8C2C
F00C8C14: d0026004                 ld      [%o1+4], %o0
F00C8C18: e022a0a8                 st      %l0, [%o2+%lo(dword_F01330A8)]
F00C8C1C: e0226004                 st      %l0, [%o1+4]
F00C8C20: d2242010                 st      %o1, [%l0+0x10]
F00C8C24: 10800006                 ba      loc_F00C8C3C
F00C8C28: d2242014                 st      %o1, [%l0+0x14]
F00C8C2C: d0242014                 st      %o0, [%l0+0x14]
F00C8C30: d2242010                 st      %o1, [%l0+0x10]
F00C8C34: e0226004                 st      %l0, [%o1+4]
F00C8C38: e0222010                 st      %l0, [%o0+0x10]
F00C8C3C: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C8C40: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C8C44: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C8C48: 4000a30a                 call    _objc_msgSend
F00C8C4C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C8C50: 81c7e008                 ret
F00C8C54: 81e80000                 restore
