F00CAA18: 9de3bf90                 save    %sp, -0x70, %sp
F00CAA1C: 90100018                 mov     %i0, %o0! id
F00CAA20: 133c0506                 sethi   %hi(paInitwithmaxcou), %o1
F00CAA24: d2026078                 ld      [%o1+%lo(paInitwithmaxcou)], %o1! SEL
F00CAA28: 40009b92                 call    _objc_msgSend
F00CAA2C: 94102010                 mov     0x10, %o2
F00CAA30: 81c7e008                 ret
F00CAA34: 91e80008                 restore %g0, %o0, %o0
