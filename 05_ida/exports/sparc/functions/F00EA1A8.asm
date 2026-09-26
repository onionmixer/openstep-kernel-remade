F00EA1A8: 9de3bf90                 save    %sp, -0x70, %sp
F00EA1AC: 90100018                 mov     %i0, %o0! id
F00EA1B0: 133c0504                 sethi   %hi(paSelectmodeCoun_0), %o1
F00EA1B4: d2026394                 ld      [%o1+%lo(paSelectmodeCoun_0)], %o1! SEL
F00EA1B8: 9410001a                 mov     %i2, %o2
F00EA1BC: 9610001b                 mov     %i3, %o3
F00EA1C0: 40001dac                 call    _objc_msgSend
F00EA1C4: 98102000                 mov     0, %o4
F00EA1C8: 81c7e008                 ret
F00EA1CC: 91e80008                 restore %g0, %o0, %o0
