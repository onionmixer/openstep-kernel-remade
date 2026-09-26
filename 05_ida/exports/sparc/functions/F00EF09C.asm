F00EF09C: 9de3bf98                 save    %sp, -0x68, %sp
F00EF0A0: 133c0506                 sethi   %hi(paHash), %o1! SEL
F00EF0A4: 90100019                 mov     %i1, %o0! id
F00EF0A8: 400009f2                 call    _objc_msgSend
F00EF0AC: d2026268                 ld      [%o1+%lo(paHash)], %o1
F00EF0B0: 81c7e008                 ret
F00EF0B4: 91e80008                 restore %g0, %o0, %o0
