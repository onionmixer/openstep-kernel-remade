F008F300: 9de3bf90                 save    %sp, -0x70, %sp
F008F304: d006200c                 ld      [%i0+0xC], %o0! id
F008F308: 133c0504                 sethi   %hi(paRemovekey), %o1
F008F30C: d2026080                 ld      [%o1+%lo(paRemovekey)], %o1! SEL
F008F310: 40018958                 call    _objc_msgSend
F008F314: 9410001a                 mov     %i2, %o2
F008F318: a2920000                 orcc    %o0, %g0, %l1
F008F31C: 0280001e                 be      locret_F008F394
F008F320: 01000000                 nop
F008F324: 7ffffee1                 call    sub_F008EEA8
F008F328: 9010001a                 mov     %i2, %o0
F008F32C: 912a2018                 sll     %o0, 24, %o0! id
F008F330: 80a22000                 cmp     %o0, 0
F008F334: 02800016                 be      loc_F008F38C
F008F338: b4102000                 mov     0, %i2
F008F33C: 293c0504                 sethi   %hi(paCount_0), %l4
F008F340: 273c0504                 sethi   -0xFEBF000, %l3
F008F344: 253c0504                 sethi   -0xFEBF000, %l2
F008F348: d20520b8                 ld      [%l4+%lo(paCount_0)], %o1! SEL
F008F34C: 40018949                 call    _objc_msgSend
F008F350: 90100011                 mov     %l1, %o0
F008F354: 80a68008                 cmp     %i2, %o0
F008F358: 1a80000d                 bcc     loc_F008F38C
F008F35C: 90100011                 mov     %l1, %o0! id
F008F360: d204a0c8                 ld      [%l2+0xC8], %o1! SEL
F008F364: 9410001a                 mov     %i2, %o2
F008F368: e0062014                 ld      [%i0+0x14], %l0
F008F36C: 40018941                 call    _objc_msgSend
F008F370: b406a001                 inc     %i2
F008F374: 94100008                 mov     %o0, %o2
F008F378: d204e0ac                 ld      [%l3+0xAC], %o1! SEL
F008F37C: 4001893d                 call    _objc_msgSend
F008F380: 90100010                 mov     %l0, %o0
F008F384: 10bffff2                 ba      loc_F008F34C
F008F388: d20520b8                 ld      [%l4+0xB8], %o1
F008F38C: 7ffffebc                 call    sub_F008EE7C
F008F390: 90100011                 mov     %l1, %o0
F008F394: 81c7e008                 ret
F008F398: 91e82000                 restore %g0, 0, %o0
