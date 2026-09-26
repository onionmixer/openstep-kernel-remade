F00EA574: 9de3bf90                 save    %sp, -0x70, %sp
F00EA578: 133c0506                 sethi   %hi(paNewkeydescValu_0), %o1
F00EA57C: 90100018                 mov     %i0, %o0! id
F00EA580: d2026250                 ld      [%o1+%lo(paNewkeydescValu_0)], %o1! SEL
F00EA584: 9410001a                 mov     %i2, %o2
F00EA588: 9610001b                 mov     %i3, %o3
F00EA58C: 40001cb9                 call    _objc_msgSend
F00EA590: 98102001                 mov     1, %o4
F00EA594: 81c7e008                 ret
F00EA598: 91e80008                 restore %g0, %o0, %o0
