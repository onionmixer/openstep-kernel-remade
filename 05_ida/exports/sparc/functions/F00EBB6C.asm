F00EBB6C: 9de3bf90                 save    %sp, -0x70, %sp
F00EBB70: 213c0506                 sethi   %hi(paError), %l0
F00EBB74: 40001eda                 call    _sel_getName
F00EBB78: 9010001a                 mov     %i2, %o0
F00EBB7C: 96100008                 mov     %o0, %o3
F00EBB80: 90100018                 mov     %i0, %o0! id
F00EBB84: d2042228                 ld      [%l0+%lo(paError)], %o1! SEL
F00EBB88: 153c03e8                 sethi   %hi(aShouldHaveImpl), %o2! "should have implemented the '%s' method"...
F00EBB8C: 40001739                 call    _objc_msgSend
F00EBB90: 9412a1a8                 bset    %lo(aShouldHaveImpl), %o2! "should have implemented the '%s' method"...
F00EBB94: 81c7e008                 ret
F00EBB98: 91e80008                 restore %g0, %o0, %o0
