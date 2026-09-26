F00E9910: 9de3bf90                 save    %sp, -0x70, %sp
F00E9914: 80a6a040                 cmp     %i2, 0x40 ! '@'
F00E9918: 0880000b                 bleu    locret_F00E9944
F00E991C: 90100018                 mov     %i0, %o0! id
F00E9920: 133c0504                 sethi   %hi(paName), %o1
F00E9924: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00E9928: 213c03f2                 sethi   %hi(aSInvalidArgToS), %l0! "%s: Invalid arg to setBrightness:%d\n"
F00E992C: 40001fd1                 call    _objc_msgSend
F00E9930: a0142340                 bset    %lo(aSInvalidArgToS), %l0! "%s: Invalid arg to setBrightness:%d\n"
F00E9934: 92100008                 mov     %o0, %o1
F00E9938: 90100010                 mov     %l0, %o0
F00E993C: 7fff71ee                 call    _IOLog
F00E9940: 9410001a                 mov     %i2, %o2
F00E9944: 81c7e008                 ret
F00E9948: 81e80000                 restore
