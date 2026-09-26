F00EC1D4: 9de3bf90                 save    %sp, -0x70, %sp
F00EC1D8: 213c0506                 sethi   %hi(paError), %l0
F00EC1DC: 40001d40                 call    _sel_getName
F00EC1E0: 9010001a                 mov     %i2, %o0
F00EC1E4: 96100008                 mov     %o0, %o3
F00EC1E8: 90100018                 mov     %i0, %o0! id
F00EC1EC: d2042228                 ld      [%l0+%lo(paError)], %o1! SEL
F00EC1F0: 153c03e8                 sethi   %hi(aShouldNotHaveI), %o2! "should NOT have implemented the '%s' me"...
F00EC1F4: 4000159f                 call    _objc_msgSend
F00EC1F8: 9412a1d8                 bset    %lo(aShouldNotHaveI), %o2! "should NOT have implemented the '%s' me"...
F00EC1FC: 81c7e008                 ret
F00EC200: 91e80008                 restore %g0, %o0, %o0
