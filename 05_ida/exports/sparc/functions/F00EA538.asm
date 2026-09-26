F00EA538: 9de3bf90                 save    %sp, -0x70, %sp
F00EA53C: 40001984                 call    _NXDefaultMallocZone
F00EA540: 213c0506                 sethi   %hi(paAllocfromzone), %l0
F00EA544: 94100008                 mov     %o0, %o2
F00EA548: 90100018                 mov     %i0, %o0! id
F00EA54C: 40001cc9                 call    _objc_msgSend
F00EA550: d2042260                 ld      [%l0+%lo(paAllocfromzone)], %o1
F00EA554: 133c0506                 sethi   %hi(paInitkeydescVal_0), %o1
F00EA558: d2026258                 ld      [%o1+%lo(paInitkeydescVal_0)], %o1! SEL
F00EA55C: 9410001a                 mov     %i2, %o2
F00EA560: 9610001b                 mov     %i3, %o3
F00EA564: 40001cc3                 call    _objc_msgSend
F00EA568: 9810001c                 mov     %i4, %o4
F00EA56C: 81c7e008                 ret
F00EA570: 91e80008                 restore %g0, %o0, %o0
