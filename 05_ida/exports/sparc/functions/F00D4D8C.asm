F00D4D8C: 9de3bf90                 save    %sp, -0x70, %sp
F00D4D90: d0062110                 ld      [%i0+0x110], %o0! id
F00D4D94: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D4D98: 400072b6                 call    _objc_msgSend
F00D4D9C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D4DA0: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4DA4: 80a22000                 cmp     %o0, 0
F00D4DA8: 02800004                 be      loc_F00D4DB8
F00D4DAC: a0102000                 mov     0, %l0
F00D4DB0: d0062168                 ld      [%i0+0x168], %o0
F00D4DB4: e002200c                 ld      [%o0+0xC], %l0
F00D4DB8: d0062110                 ld      [%i0+0x110], %o0! id
F00D4DBC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4DC0: 400072ac                 call    _objc_msgSend
F00D4DC4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D4DC8: 81c7e008                 ret
F00D4DCC: 91e80010                 restore %g0, %l0, %o0
