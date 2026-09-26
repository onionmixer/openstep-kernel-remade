F00EC198: 9de3bf90                 save    %sp, -0x70, %sp
F00EC19C: 133c0506                 sethi   %hi(paDescriptionfor), %o1
F00EC1A0: 90100018                 mov     %i0, %o0! id
F00EC1A4: d2026218                 ld      [%o1+%lo(paDescriptionfor)], %o1! SEL
F00EC1A8: 400015b2                 call    _objc_msgSend
F00EC1AC: 9410001a                 mov     %i2, %o2
F00EC1B0: 81c7e008                 ret
F00EC1B4: 91e80008                 restore %g0, %o0, %o0
