F008CA74: 9de3bf90                 save    %sp, -0x70, %sp
F008CA78: 90100018                 mov     %i0, %o0! id
F008CA7C: 133c0504                 sethi   %hi(paInitwithitemco_0), %o1
F008CA80: d2026030                 ld      [%o1+%lo(paInitwithitemco_0)], %o1! SEL
F008CA84: 9410001a                 mov     %i2, %o2
F008CA88: 96102000                 mov     0, %o3
F008CA8C: 9810001b                 mov     %i3, %o4
F008CA90: 40019378                 call    _objc_msgSend
F008CA94: 9a10001c                 mov     %i4, %o5
F008CA98: 81c7e008                 ret
F008CA9C: 91e80008                 restore %g0, %o0, %o0
