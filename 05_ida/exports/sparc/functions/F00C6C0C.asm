F00C6C0C: 9de3bf90                 save    %sp, -0x70, %sp
F00C6C10: d0062184                 ld      [%i0+0x184], %o0! id
F00C6C14: 133c0506                 sethi   %hi(paUpdatereadysta), %o1! SEL
F00C6C18: 4000ab16                 call    _objc_msgSend
F00C6C1C: d20261c8                 ld      [%o1+%lo(paUpdatereadysta)], %o1
F00C6C20: 81c7e008                 ret
F00C6C24: 91e80008                 restore %g0, %o0, %o0
