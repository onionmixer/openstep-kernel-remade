F008F054: 9de3bf90                 save    %sp, -0x70, %sp
F008F058: 90100018                 mov     %i0, %o0! id
F008F05C: 133c0504                 sethi   %hi(paInitfromconfig), %o1
F008F060: d2026070                 ld      [%o1+%lo(paInitfromconfig)], %o1! SEL
F008F064: 40018a03                 call    _objc_msgSend
F008F068: 94102000                 mov     0, %o2
F008F06C: 81c7e008                 ret
F008F070: 91e80008                 restore %g0, %o0, %o0
