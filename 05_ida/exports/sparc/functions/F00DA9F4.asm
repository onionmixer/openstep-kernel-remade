F00DA9F4: 9de3bf90                 save    %sp, -0x70, %sp
F00DA9F8: d0062010                 ld      [%i0+0x10], %o0! id
F00DA9FC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DAA00: 40005b9c                 call    _objc_msgSend
F00DAA04: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DAA08: d006200c                 ld      [%i0+0xC], %o0! id
F00DAA0C: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00DAA10: 40005b98                 call    _objc_msgSend
F00DAA14: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00DAA18: a0100008                 mov     %o0, %l0
F00DAA1C: d0062010                 ld      [%i0+0x10], %o0! id
F00DAA20: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DAA24: 40005b93                 call    _objc_msgSend
F00DAA28: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DAA2C: 81c7e008                 ret
F00DAA30: 91e80010                 restore %g0, %l0, %o0
