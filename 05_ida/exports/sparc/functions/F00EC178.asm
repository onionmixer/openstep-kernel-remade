F00EC178: 9de3bf90                 save    %sp, -0x70, %sp
F00EC17C: 133c0506                 sethi   %hi(paDescriptionfor_0), %o1
F00EC180: 90100018                 mov     %i0, %o0! id
F00EC184: d2026208                 ld      [%o1+%lo(paDescriptionfor_0)], %o1! SEL
F00EC188: 400015ba                 call    _objc_msgSend
F00EC18C: 9410001a                 mov     %i2, %o2
F00EC190: 81c7e008                 ret
F00EC194: 91e80008                 restore %g0, %o0, %o0
