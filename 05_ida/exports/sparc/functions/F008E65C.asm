F008E65C: 9de3bf90                 save    %sp, -0x70, %sp
F008E660: d0062008                 ld      [%i0+8], %o0! id
F008E664: 133c0504                 sethi   %hi(paObjectat), %o1
F008E668: d20260c8                 ld      [%o1+%lo(paObjectat)], %o1! SEL
F008E66C: 40018c81                 call    _objc_msgSend
F008E670: 9410001a                 mov     %i2, %o2
F008E674: 81c7e008                 ret
F008E678: 91e80008                 restore %g0, %o0, %o0
