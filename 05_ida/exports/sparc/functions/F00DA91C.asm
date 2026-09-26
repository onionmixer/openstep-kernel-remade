F00DA91C: 9de3bf90                 save    %sp, -0x70, %sp
F00DA920: d0062010                 ld      [%i0+0x10], %o0! id
F00DA924: 133c0504                 sethi   %hi(paLock), %o1
F00DA928: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00DA92C: 40005bd1                 call    _objc_msgSend
F00DA930: f4262014                 st      %i2, [%i0+0x14]
F00DA934: d006200c                 ld      [%i0+0xC], %o0! id
F00DA938: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00DA93C: 40005bcd                 call    _objc_msgSend
F00DA940: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00DA944: a0920000                 orcc    %o0, %g0, %l0
F00DA948: 22800014                 be,a    loc_F00DA998
F00DA94C: d0062010                 ld      [%i0+0x10], %o0
F00DA950: b4102000                 mov     0, %i2
F00DA954: 80a68010                 cmp     %i2, %l0
F00DA958: 36800010                 bge,a   loc_F00DA998
F00DA95C: d0062010                 ld      [%i0+0x10], %o0
F00DA960: 253c0504                 sethi   -0xFEBF000, %l2
F00DA964: 233c0505                 sethi   -0xFEBEC00, %l1
F00DA968: d006200c                 ld      [%i0+0xC], %o0! id
F00DA96C: 9410001a                 mov     %i2, %o2
F00DA970: d204a0c8                 ld      [%l2+0xC8], %o1! SEL
F00DA974: 40005bbf                 call    _objc_msgSend
F00DA978: b406a001                 inc     %i2
F00DA97C: d2046090                 ld      [%l1+0x90], %o1! SEL
F00DA980: 40005bbc                 call    _objc_msgSend
F00DA984: 94102004                 mov     4, %o2
F00DA988: 80a68010                 cmp     %i2, %l0
F00DA98C: 26bffff8                 bl,a    loc_F00DA96C
F00DA990: d006200c                 ld      [%i0+0xC], %o0
F00DA994: d0062010                 ld      [%i0+0x10], %o0! id
F00DA998: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DA99C: 40005bb5                 call    _objc_msgSend
F00DA9A0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DA9A4: 81c7e008                 ret
F00DA9A8: 81e80000                 restore
