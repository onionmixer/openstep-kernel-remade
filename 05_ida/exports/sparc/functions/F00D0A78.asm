F00D0A78: 9de3bf90                 save    %sp, -0x70, %sp
F00D0A7C: d0062128                 ld      [%i0+0x128], %o0! id
F00D0A80: 133c0504                 sethi   %hi(paResetscsibus), %o1! SEL
F00D0A84: 4000837b                 call    _objc_msgSend
F00D0A88: d20261f4                 ld      [%o1+%lo(paResetscsibus)], %o1
F00D0A8C: 81c7e008                 ret
F00D0A90: 91e80008                 restore %g0, %o0, %o0
