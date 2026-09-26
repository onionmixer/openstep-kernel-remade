F00EBCAC: 9de3bf90                 save    %sp, -0x70, %sp
F00EBCB0: 133c0506                 sethi   %hi(paDoesnotrecogni), %o1
F00EBCB4: 90100018                 mov     %i0, %o0! id
F00EBCB8: d2026224                 ld      [%o1+%lo(paDoesnotrecogni)], %o1! SEL
F00EBCBC: 400016ed                 call    _objc_msgSend
F00EBCC0: 9410001a                 mov     %i2, %o2
F00EBCC4: 81c7e008                 ret
F00EBCC8: 91e80008                 restore %g0, %o0, %o0
