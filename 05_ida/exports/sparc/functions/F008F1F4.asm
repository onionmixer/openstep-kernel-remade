F008F1F4: 9de3bf90                 save    %sp, -0x70, %sp
F008F1F8: d006200c                 ld      [%i0+0xC], %o0! id
F008F1FC: 133c0504                 sethi   %hi(paValueforkey), %o1
F008F200: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F008F204: 4001899b                 call    _objc_msgSend
F008F208: 9410001a                 mov     %i2, %o2
F008F20C: 81c7e008                 ret
F008F210: 91e80008                 restore %g0, %o0, %o0
