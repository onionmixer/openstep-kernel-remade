F00C9C2C: 9de3bf90                 save    %sp, -0x70, %sp
F00C9C30: d0062108                 ld      [%i0+0x108], %o0! id
F00C9C34: 133c0506                 sethi   %hi(paNummemoryrange), %o1
F00C9C38: d20260b8                 ld      [%o1+%lo(paNummemoryrange)], %o1! SEL
F00C9C3C: 40009f0d                 call    _objc_msgSend
F00C9C40: e006211c                 ld      [%i0+0x11C], %l0
F00C9C44: 80a68008                 cmp     %i2, %o0
F00C9C48: 1a800011                 bcc     locret_F00C9C8C
F00C9C4C: 133c0504                 sethi   %hi(paValueforkey), %o1
F00C9C50: d0040000                 ld      [%l0], %o0! id
F00C9C54: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F00C9C58: 40009f06                 call    _objc_msgSend
F00C9C5C: 9410001b                 mov     %i3, %o2
F00C9C60: b0920000                 orcc    %o0, %g0, %i0
F00C9C64: 0280000a                 be      locret_F00C9C8C
F00C9C68: 133c0504                 sethi   %hi(paRemovekey), %o1
F00C9C6C: d0040000                 ld      [%l0], %o0! id
F00C9C70: d2026080                 ld      [%o1+%lo(paRemovekey)], %o1! SEL
F00C9C74: 40009eff                 call    _objc_msgSend
F00C9C78: 9410001b                 mov     %i3, %o2
F00C9C7C: 113c0503                 sethi   %hi(paFree), %o0! id
F00C9C80: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C9C84: 40009efb                 call    _objc_msgSend
F00C9C88: 90100018                 mov     %i0, %o0
F00C9C8C: 81c7e008                 ret
F00C9C90: 81e80000                 restore
