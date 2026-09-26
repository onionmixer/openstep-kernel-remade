F00EA438: 9de3bf90                 save    %sp, -0x70, %sp
F00EA43C: 400019c4                 call    _NXDefaultMallocZone
F00EA440: 213c0506                 sethi   %hi(paAllocfromzone), %l0
F00EA444: 94100008                 mov     %o0, %o2
F00EA448: 90100018                 mov     %i0, %o0! id
F00EA44C: 40001d09                 call    _objc_msgSend
F00EA450: d2042260                 ld      [%l0+%lo(paAllocfromzone)], %o1
F00EA454: 133c0506                 sethi   %hi(paInitbare), %o1
F00EA458: d202625c                 ld      [%o1+%lo(paInitbare)], %o1! SEL
F00EA45C: 9410001a                 mov     %i2, %o2
F00EA460: 9610001b                 mov     %i3, %o3
F00EA464: 40001d03                 call    _objc_msgSend
F00EA468: 9810001c                 mov     %i4, %o4
F00EA46C: 81c7e008                 ret
F00EA470: 91e80008                 restore %g0, %o0, %o0
