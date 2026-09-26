F008E6C4: 9de3bf90                 save    %sp, -0x70, %sp
F008E6C8: f027bff0                 st      %i0, [%fp+var_10]
F008E6CC: 133c0507                 sethi   %hi(stru_F0141C8C.super_class), %o1
F008E6D0: d4026090                 ld      [%o1+%lo(stru_F0141C8C.super_class)], %o2
F008E6D4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008E6D8: 133c0504                 sethi   %hi(paInit), %o1
F008E6DC: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008E6E0: 40018ca7                 call    _objc_msgSendSuper
F008E6E4: d427bff4                 st      %o2, [%fp+var_C]
F008E6E8: 113c0506                 sethi   %hi(paKernlock), %o0
F008E6EC: d002228c                 ld      [%o0+%lo(paKernlock)], %o0! id
F008E6F0: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008E6F4: 40018c5f                 call    _objc_msgSend
F008E6F8: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008E6FC: 133c0504                 sethi   %hi(paInitwithlevel), %o1
F008E700: d2026028                 ld      [%o1+%lo(paInitwithlevel)], %o1! SEL
F008E704: 40018c5b                 call    _objc_msgSend
F008E708: 9410200a                 mov     0xA, %o2
F008E70C: d0262008                 st      %o0, [%i0+8]
F008E710: 400000ec                 call    sub_F008EAC0
F008E714: 9010001a                 mov     %i2, %o0
F008E718: d0262014                 st      %o0, [%i0+0x14]
F008E71C: 81c7e008                 ret
F008E720: 81e80000                 restore
