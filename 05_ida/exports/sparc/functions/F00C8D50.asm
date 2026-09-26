F00C8D50: 9de3bf90                 save    %sp, -0x70, %sp
F00C8D54: d006200c                 ld      [%i0+0xC], %o0! id
F00C8D58: 133c0504                 sethi   %hi(paConfigtable_0), %o1! SEL
F00C8D5C: 4000a2c5                 call    _objc_msgSend
F00C8D60: d2026310                 ld      [%o1+%lo(paConfigtable_0)], %o1
F00C8D64: 81c7e008                 ret
F00C8D68: 91e80008                 restore %g0, %o0, %o0
