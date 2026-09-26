F008DFC0: 9de3bf90                 save    %sp, -0x70, %sp
F008DFC4: 90100018                 mov     %i0, %o0! id
F008DFC8: 133c0504                 sethi   %hi(paInitforresourc_1), %o1
F008DFCC: 9b2f2018                 sll     %i4, 24, %o5
F008DFD0: d2026094                 ld      [%o1+%lo(paInitforresourc_1)], %o1! SEL
F008DFD4: 9410001a                 mov     %i2, %o2
F008DFD8: 9610001b                 mov     %i3, %o3
F008DFDC: 98102000                 mov     0, %o4
F008DFE0: 40018e24                 call    _objc_msgSend
F008DFE4: 9b3b6018                 sra     %o5, 24, %o5
F008DFE8: 81c7e008                 ret
F008DFEC: 91e80008                 restore %g0, %o0, %o0
