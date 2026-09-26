F008C8A8: 9de3bf90                 save    %sp, -0x70, %sp
F008C8AC: 90100018                 mov     %i0, %o0! id
F008C8B0: 133c0504                 sethi   %hi(paInitwithlevel), %o1
F008C8B4: d2026028                 ld      [%o1+%lo(paInitwithlevel)], %o1! SEL
F008C8B8: 400193ee                 call    _objc_msgSend
F008C8BC: 94102000                 mov     0, %o2
F008C8C0: 81c7e008                 ret
F008C8C4: 91e80008                 restore %g0, %o0, %o0
