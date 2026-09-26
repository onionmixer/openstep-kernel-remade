F008C9C8: 9de3bf90                 save    %sp, -0x70, %sp
F008C9CC: f027bff0                 st      %i0, [%fp+var_10]
F008C9D0: 133c0506                 sethi   %hi(stru_F0141BEC.super_class), %o1
F008C9D4: d40263f0                 ld      [%o1+%lo(stru_F0141BEC.super_class)], %o2
F008C9D8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008C9DC: 133c0504                 sethi   %hi(paInit), %o1
F008C9E0: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008C9E4: 400193e6                 call    _objc_msgSendSuper
F008C9E8: d427bff4                 st      %o2, [%fp+var_C]
F008C9EC: 80a6a400                 cmp     %i2, 0x400
F008C9F0: 18800005                 bgu     loc_F008CA04
F008C9F4: 9006c01a                 add     %i3, %i2, %o0
F008C9F8: 80a2001b                 cmp     %o0, %i3
F008C9FC: 18800008                 bgu     loc_F008CA1C
F008CA00: 80a72000                 cmp     %i4, 0
F008CA04: 113c0503                 sethi   %hi(paFree), %o0! id
F008CA08: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008CA0C: 40019399                 call    _objc_msgSend
F008CA10: 90100018                 mov     %i0, %o0
F008CA14: 10800016                 ba      locret_F008CA6C
F008CA18: b0100008                 mov     %o0, %i0
F008CA1C: 02800004                 be      loc_F008CA2C
F008CA20: fa262004                 st      %i5, [%i0+4]
F008CA24: 10800008                 ba      loc_F008CA44
F008CA28: f8262010                 st      %i4, [%i0+0x10]
F008CA2C: 113c0506                 sethi   %hi(paKernbusitem), %o0
F008CA30: d0022274                 ld      [%o0+%lo(paKernbusitem)], %o0! id
F008CA34: 133c0504                 sethi   %hi(paClass), %o1! SEL
F008CA38: 4001938e                 call    _objc_msgSend
F008CA3C: d2026014                 ld      [%o1+%lo(paClass)], %o1! size_t
F008CA40: d0262010                 st      %o0, [%i0+0x10]
F008CA44: a12ea002                 sll     %i2, 2, %l0
F008CA48: 4000e53a                 call    _IOMalloc
F008CA4C: 90100010                 mov     %l0, %o0
F008CA50: d0262018                 st      %o0, [%i0+0x18]
F008CA54: c0262014                 clr     [%i0+0x14]
F008CA58: d0062018                 ld      [%i0+0x18], %o0! void *
F008CA5C: 400020ff                 call    _bzero
F008CA60: 92100010                 mov     %l0, %o1
F008CA64: f4262008                 st      %i2, [%i0+8]
F008CA68: f626200c                 st      %i3, [%i0+0xC]
F008CA6C: 81c7e008                 ret
F008CA70: 81e80000                 restore
