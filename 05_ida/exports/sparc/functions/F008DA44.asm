F008DA44: 9de3bf90                 save    %sp, -0x70, %sp
F008DA48: d0062004                 ld      [%i0+4], %o0! id
F008DA4C: 133c0504                 sethi   %hi(paValueforkey), %o1
F008DA50: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F008DA54: 40018f87                 call    _objc_msgSend
F008DA58: 9410001a                 mov     %i2, %o2
F008DA5C: 81c7e008                 ret
F008DA60: 91e80008                 restore %g0, %o0, %o0
