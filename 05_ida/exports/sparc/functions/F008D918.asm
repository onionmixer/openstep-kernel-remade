F008D918: 9de3bf90                 save    %sp, -0x70, %sp
F008D91C: 113c0506                 sethi   %hi(paKerndevicedesc), %o0
F008D920: d0022280                 ld      [%o0+%lo(paKerndevicedesc)], %o0! id
F008D924: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008D928: 40018fd2                 call    _objc_msgSend
F008D92C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008D930: 133c0504                 sethi   %hi(paInitfromconfig), %o1
F008D934: d2026070                 ld      [%o1+%lo(paInitfromconfig)], %o1! SEL
F008D938: 40018fce                 call    _objc_msgSend
F008D93C: 9410001a                 mov     %i2, %o2
F008D940: 81c7e008                 ret
F008D944: 91e80008                 restore %g0, %o0, %o0
