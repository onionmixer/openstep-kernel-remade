F008DAA4: 9de3bf90                 save    %sp, -0x70, %sp
F008DAA8: 113c0503                 sethi   %hi(paAlloc), %o0! id
F008DAAC: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F008DAB0: 40018f70                 call    _objc_msgSend
F008DAB4: 90100018                 mov     %i0, %o0! id
F008DAB8: 133c0504                 sethi   %hi(paInit), %o1! SEL
F008DABC: 40018f6d                 call    _objc_msgSend
F008DAC0: d202602c                 ld      [%o1+%lo(paInit)], %o1
F008DAC4: 81c7e008                 ret
F008DAC8: 91e82001                 restore %g0, 1, %o0
