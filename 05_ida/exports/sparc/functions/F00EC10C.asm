F00EC10C: 9de3bf90                 save    %sp, -0x70, %sp
F00EC110: 133c0506                 sethi   %hi(paSuperclass_0), %o1! SEL
F00EC114: 90100018                 mov     %i0, %o0! id
F00EC118: 400015d6                 call    _objc_msgSend
F00EC11C: d2026214                 ld      [%o1+%lo(paSuperclass_0)], %o1
F00EC120: 81c7e008                 ret
F00EC124: 91e80008                 restore %g0, %o0, %o0
