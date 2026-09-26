F008D7F0: 9de3bf90                 save    %sp, -0x70, %sp
F008D7F4: 113c04c3                 sethi   %hi(dword_F0130FF8), %o0
F008D7F8: d00223f8                 ld      [%o0+%lo(dword_F0130FF8)], %o0! id
F008D7FC: 133c0504                 sethi   %hi(paValueforkey), %o1
F008D800: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F008D804: 4001901b                 call    _objc_msgSend
F008D808: 9410001a                 mov     %i2, %o2
F008D80C: 81c7e008                 ret
F008D810: 91e80008                 restore %g0, %o0, %o0
