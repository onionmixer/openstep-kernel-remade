F008FF98: 9de3bf90                 save    %sp, -0x70, %sp
F008FF9C: 90100018                 mov     %i0, %o0! id
F008FFA0: 133c0504                 sethi   %hi(paInitwithwhites), %o1
F008FFA4: d202613c                 ld      [%o1+%lo(paInitwithwhites)], %o1! SEL
F008FFA8: 40018632                 call    _objc_msgSend
F008FFAC: 94102000                 mov     0, %o2
F008FFB0: 81c7e008                 ret
F008FFB4: 91e80008                 restore %g0, %o0, %o0
