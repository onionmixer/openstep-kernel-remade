F00EB020: 9de3bf90                 save    %sp, -0x70, %sp
F00EB024: 133c0506                 sethi   %hi(paNewcount), %o1
F00EB028: 90100018                 mov     %i0, %o0! id
F00EB02C: d202623c                 ld      [%o1+%lo(paNewcount)], %o1! SEL
F00EB030: 40001a10                 call    _objc_msgSend
F00EB034: 94102000                 mov     0, %o2
F00EB038: 81c7e008                 ret
F00EB03C: 91e80008                 restore %g0, %o0, %o0
