F00EA474: 9de3bf90                 save    %sp, -0x70, %sp
F00EA478: 133c0506                 sethi   %hi(paInitkeydescVal_0), %o1
F00EA47C: 90100018                 mov     %i0, %o0! id
F00EA480: d2026258                 ld      [%o1+%lo(paInitkeydescVal_0)], %o1! SEL
F00EA484: 9410001a                 mov     %i2, %o2
F00EA488: 9610001b                 mov     %i3, %o3
F00EA48C: 40001cf9                 call    _objc_msgSend
F00EA490: 98102001                 mov     1, %o4
F00EA494: 81c7e008                 ret
F00EA498: 91e80008                 restore %g0, %o0, %o0
