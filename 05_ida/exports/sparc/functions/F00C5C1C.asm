F00C5C1C: 9de3bf90                 save    %sp, -0x70, %sp
F00C5C20: 153c04cc                 sethi   %hi(dword_F0133034), %o2
F00C5C24: e002a034                 ld      [%o2+%lo(dword_F0133034)], %l0
F00C5C28: 113c0506                 sethi   %hi(paList), %o0
F00C5C2C: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00C5C30: 133c0503                 sethi   %hi(paAlloc), %o1
F00C5C34: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00C5C38: 4000af0e                 call    _objc_msgSend
F00C5C3C: a212a034                 or      %o2, %lo(dword_F0133034), %l1
F00C5C40: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00C5C44: 4000af0b                 call    _objc_msgSend
F00C5C48: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00C5C4C: b0100008                 mov     %o0, %i0
F00C5C50: 113c04cc                 sethi   %hi(dword_F013303C), %o0
F00C5C54: d002203c                 ld      [%o0+%lo(dword_F013303C)], %o0! id
F00C5C58: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C5C5C: 4000af05                 call    _objc_msgSend
F00C5C60: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C5C64: 80a40011                 cmp     %l0, %l1
F00C5C68: 02800013                 be      loc_F00C5CB4
F00C5C6C: 113c04cc                 sethi   -0xFECD000, %o0
F00C5C70: 273c0504                 sethi   -0xFEBF000, %l3
F00C5C74: 253c0504                 sethi   -0xFEBF000, %l2
F00C5C78: d0040000                 ld      [%l0], %o0! id
F00C5C7C: 4000aefd                 call    _objc_msgSend
F00C5C80: d204e014                 ld      [%l3+0x14], %o1
F00C5C84: 80a2001a                 cmp     %o0, %i2
F00C5C88: 32800007                 bne,a   loc_F00C5CA4
F00C5C8C: e0042008                 ld      [%l0+8], %l0
F00C5C90: d204a0a4                 ld      [%l2+0xA4], %o1! SEL
F00C5C94: d4040000                 ld      [%l0], %o2
F00C5C98: 4000aef6                 call    _objc_msgSend
F00C5C9C: 90100018                 mov     %i0, %o0
F00C5CA0: e0042008                 ld      [%l0+8], %l0
F00C5CA4: 80a40011                 cmp     %l0, %l1
F00C5CA8: 32bffff5                 bne,a   loc_F00C5C7C
F00C5CAC: d0040000                 ld      [%l0], %o0
F00C5CB0: 113c04cc                 sethi   -0xFECD000, %o0
F00C5CB4: d002203c                 ld      [%o0+0x3C], %o0! id
F00C5CB8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C5CBC: 4000aeed                 call    _objc_msgSend
F00C5CC0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C5CC4: 81c7e008                 ret
F00C5CC8: 81e80000                 restore
