F008EA54: 9de3bf90                 save    %sp, -0x70, %sp
F008EA58: d0062008                 ld      [%i0+8], %o0! id
F008EA5C: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008EA60: 40018b84                 call    _objc_msgSend
F008EA64: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008EA68: e2062004                 ld      [%i0+4], %l1
F008EA6C: 80a46000                 cmp     %l1, 0
F008EA70: 12800007                 bne     loc_F008EA8C
F008EA74: d0062008                 ld      [%i0+8], %o0! id
F008EA78: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008EA7C: 40018b7d                 call    _objc_msgSend
F008EA80: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F008EA84: 1080000d                 ba      locret_F008EAB8
F008EA88: b0102000                 mov     0, %i0
F008EA8C: e00e2018                 ldub    [%i0+0x18], %l0
F008EA90: 133c0504                 sethi   %hi(paRelease), %o1
F008EA94: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008EA98: 40018b76                 call    _objc_msgSend
F008EA9C: c02e2018                 clrb    [%i0+0x18]
F008EAA0: 80a42000                 cmp     %l0, 0
F008EAA4: 02800005                 be      locret_F008EAB8
F008EAA8: 113c0504                 sethi   %hi(paResume), %o0! id
F008EAAC: d20220d8                 ld      [%o0+%lo(paResume)], %o1! SEL
F008EAB0: 40018b70                 call    _objc_msgSend
F008EAB4: 90100011                 mov     %l1, %o0
F008EAB8: 81c7e008                 ret
F008EABC: 81e80000                 restore
