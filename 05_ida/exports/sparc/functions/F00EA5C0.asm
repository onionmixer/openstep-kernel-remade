F00EA5C0: 9de3bf90                 save    %sp, -0x70, %sp
F00EA5C4: 133c0506                 sethi   %hi(paNewkeydesc), %o1
F00EA5C8: 90100018                 mov     %i0, %o0! id
F00EA5CC: d2026248                 ld      [%o1+%lo(paNewkeydesc)], %o1! SEL
F00EA5D0: 40001ca8                 call    _objc_msgSend
F00EA5D4: 94102000                 mov     0, %o2
F00EA5D8: 81c7e008                 ret
F00EA5DC: 91e80008                 restore %g0, %o0, %o0
