F00C6E28: 9de3bf90                 save    %sp, -0x70, %sp
F00C6E2C: 133c0504                 sethi   %hi(paIsdiskready), %o1
F00C6E30: d0062184                 ld      [%i0+0x184], %o0! id
F00C6E34: 952ea018                 sll     %i2, 24, %o2
F00C6E38: d2026164                 ld      [%o1+%lo(paIsdiskready)], %o1! SEL
F00C6E3C: 4000aa8d                 call    _objc_msgSend
F00C6E40: 953aa018                 sra     %o2, 24, %o2
F00C6E44: 81c7e008                 ret
F00C6E48: 91e80008                 restore %g0, %o0, %o0
