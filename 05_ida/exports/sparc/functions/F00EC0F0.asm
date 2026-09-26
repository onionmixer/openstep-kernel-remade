F00EC0F0: 9de3bf90                 save    %sp, -0x70, %sp
F00EC0F4: 133c0506                 sethi   %hi(paSuperclass_0), %o1! SEL
F00EC0F8: 90100018                 mov     %i0, %o0! id
F00EC0FC: 400015dd                 call    _objc_msgSend
F00EC100: d2026214                 ld      [%o1+%lo(paSuperclass_0)], %o1
F00EC104: 81c7e008                 ret
F00EC108: 91e80008                 restore %g0, %o0, %o0
