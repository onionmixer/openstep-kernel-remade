F00EA4C0: 9de3bf90                 save    %sp, -0x70, %sp
F00EA4C4: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F00EA4C8: 90100018                 mov     %i0, %o0! id
F00EA4CC: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F00EA4D0: 40001ce8                 call    _objc_msgSend
F00EA4D4: 94102000                 mov     0, %o2
F00EA4D8: 81c7e008                 ret
F00EA4DC: 91e80008                 restore %g0, %o0, %o0
