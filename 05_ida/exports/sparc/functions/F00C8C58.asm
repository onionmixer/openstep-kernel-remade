F00C8C58: 9de3bf90                 save    %sp, -0x70, %sp
F00C8C5C: 90100018                 mov     %i0, %o0! id
F00C8C60: 133c0504                 sethi   %hi(paInitwithdelega), %o1
F00C8C64: d202635c                 ld      [%o1+%lo(paInitwithdelega)], %o1! SEL
F00C8C68: 4000a302                 call    _objc_msgSend
F00C8C6C: 94102000                 mov     0, %o2
F00C8C70: 81c7e008                 ret
F00C8C74: 91e80008                 restore %g0, %o0, %o0
