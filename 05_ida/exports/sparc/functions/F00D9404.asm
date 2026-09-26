F00D9404: 9de3bf90                 save    %sp, -0x70, %sp
F00D9408: 90100018                 mov     %i0, %o0! id
F00D940C: 133c0505                 sethi   %hi(paSetinputgainri), %o1! SEL
F00D9410: e0026158                 ld      [%o1+%lo(paSetinputgainri)], %l0
F00D9414: 15000010                 sethi   0x4000, %o2
F00D9418: 40006116                 call    _objc_msgSend
F00D941C: 92100010                 mov     %l0, %o1
F00D9420: 90100018                 mov     %i0, %o0! id
F00D9424: 92100010                 mov     %l0, %o1! SEL
F00D9428: 40006112                 call    _objc_msgSend
F00D942C: 15000010                 sethi   0x4000, %o2
F00D9430: 90100018                 mov     %i0, %o0! id
F00D9434: 133c0505                 sethi   %hi(paSetoutputatten_0), %o1! SEL
F00D9438: e002616c                 ld      [%o1+%lo(paSetoutputatten_0)], %l0
F00D943C: 94103fd6                 mov     -0x2A, %o2
F00D9440: 4000610c                 call    _objc_msgSend
F00D9444: 92100010                 mov     %l0, %o1
F00D9448: 90100018                 mov     %i0, %o0! id
F00D944C: 92100010                 mov     %l0, %o1! SEL
F00D9450: 40006108                 call    _objc_msgSend
F00D9454: 94103fd6                 mov     -0x2A, %o2
F00D9458: 81c7e008                 ret
F00D945C: 81e80000                 restore
