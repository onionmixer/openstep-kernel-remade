F008CB24: 9de3bf90                 save    %sp, -0x70, %sp
F008CB28: d206200c                 ld      [%i0+0xC], %o1
F008CB2C: 80a68009                 cmp     %i2, %o1
F008CB30: 0a80000c                 bcs     loc_F008CB60
F008CB34: e2062018                 ld      [%i0+0x18], %l1
F008CB38: d0062008                 ld      [%i0+8], %o0
F008CB3C: 90024008                 add     %o1, %o0, %o0
F008CB40: 80a68008                 cmp     %i2, %o0
F008CB44: 1a800007                 bcc     loc_F008CB60
F008CB48: 90268009                 sub     %i2, %o1, %o0
F008CB4C: a12a2002                 sll     %o0, 2, %l0
F008CB50: d0044010                 ld      [%l1+%l0], %o0
F008CB54: 80a22000                 cmp     %o0, 0
F008CB58: 02800004                 be      loc_F008CB68
F008CB5C: a4044010                 add     %l1, %l0, %l2
F008CB60: 10800019                 ba      locret_F008CBC4
F008CB64: b0102000                 mov     0, %i0
F008CB68: d0062010                 ld      [%i0+0x10], %o0! id
F008CB6C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008CB70: 40019340                 call    _objc_msgSend
F008CB74: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008CB78: 133c0504                 sethi   %hi(paInitforresourc_0), %o1
F008CB7C: 94100018                 mov     %i0, %o2
F008CB80: 9610001a                 mov     %i2, %o3
F008CB84: d2026034                 ld      [%o1+%lo(paInitforresourc_0)], %o1! SEL
F008CB88: 4001933a                 call    _objc_msgSend
F008CB8C: 98102000                 mov     0, %o4
F008CB90: 80a22000                 cmp     %o0, 0
F008CB94: 0280000b                 be      loc_F008CBC0
F008CB98: d0244010                 st      %o0, [%l1+%l0]
F008CB9C: d0062014                 ld      [%i0+0x14], %o0
F008CBA0: 90022001                 inc     %o0
F008CBA4: 80a22001                 cmp     %o0, 1
F008CBA8: 12800006                 bne     loc_F008CBC0
F008CBAC: d0262014                 st      %o0, [%i0+0x14]
F008CBB0: d0062004                 ld      [%i0+4], %o0! id
F008CBB4: 133c0504                 sethi   %hi(paResourceactive), %o1! SEL
F008CBB8: 4001932e                 call    _objc_msgSend
F008CBBC: d2026038                 ld      [%o1+%lo(paResourceactive)], %o1
F008CBC0: f0048000                 ld      [%l2], %i0
F008CBC4: 81c7e008                 ret
F008CBC8: 81e80000                 restore
