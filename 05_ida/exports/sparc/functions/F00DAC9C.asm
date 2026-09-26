F00DAC9C: 9de3bf90                 save    %sp, -0x70, %sp
F00DACA0: d0062010                 ld      [%i0+0x10], %o0! id
F00DACA4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DACA8: 40005af2                 call    _objc_msgSend
F00DACAC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DACB0: d006200c                 ld      [%i0+0xC], %o0! id
F00DACB4: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00DACB8: 40005aee                 call    _objc_msgSend
F00DACBC: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00DACC0: a2920000                 orcc    %o0, %g0, %l1
F00DACC4: 22800014                 be,a    loc_F00DAD14
F00DACC8: d0062010                 ld      [%i0+0x10], %o0
F00DACCC: a0102000                 mov     0, %l0
F00DACD0: 80a40011                 cmp     %l0, %l1
F00DACD4: 36800010                 bge,a   loc_F00DAD14
F00DACD8: d0062010                 ld      [%i0+0x10], %o0
F00DACDC: 273c0504                 sethi   -0xFEBF000, %l3
F00DACE0: 253c0505                 sethi   -0xFEBEC00, %l2
F00DACE4: d006200c                 ld      [%i0+0xC], %o0! id
F00DACE8: 94100010                 mov     %l0, %o2
F00DACEC: d204e0c8                 ld      [%l3+0xC8], %o1! SEL
F00DACF0: 40005ae0                 call    _objc_msgSend
F00DACF4: a0042001                 inc     %l0
F00DACF8: d204a090                 ld      [%l2+0x90], %o1! SEL
F00DACFC: 40005add                 call    _objc_msgSend
F00DAD00: 9410001a                 mov     %i2, %o2
F00DAD04: 80a40011                 cmp     %l0, %l1
F00DAD08: 26bffff8                 bl,a    loc_F00DACE8
F00DAD0C: d006200c                 ld      [%i0+0xC], %o0
F00DAD10: d0062010                 ld      [%i0+0x10], %o0! id
F00DAD14: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DAD18: 40005ad6                 call    _objc_msgSend
F00DAD1C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DAD20: 81c7e008                 ret
F00DAD24: 81e80000                 restore
