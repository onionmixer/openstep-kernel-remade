F008F434: 9de3bf90                 save    %sp, -0x70, %sp
F008F438: 133c0504                 sethi   %hi(paNextstateKeyVa), %o1
F008F43C: 9410001a                 mov     %i2, %o2
F008F440: d006200c                 ld      [%i0+0xC], %o0! id
F008F444: 9610001b                 mov     %i3, %o3
F008F448: d2026108                 ld      [%o1+%lo(paNextstateKeyVa)], %o1! SEL
F008F44C: 40018909                 call    _objc_msgSend
F008F450: 9810001c                 mov     %i4, %o4
F008F454: 912a2018                 sll     %o0, 24, %o0
F008F458: b13a2018                 sra     %o0, 24, %i0
F008F45C: 81c7e008                 ret
F008F460: 81e80000                 restore
