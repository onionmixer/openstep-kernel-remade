F00D55CC: 9de3bf98                 save    %sp, -0x68, %sp
F00D55D0: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D55D4: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D55D8: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D55DC: 400070a5                 call    _objc_msgSend
F00D55E0: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D55E4: 133c0505                 sethi   %hi(paEvframebufferd), %o1
F00D55E8: 94100019                 mov     %i1, %o2
F00D55EC: 9610001a                 mov     %i2, %o3
F00D55F0: 9810001b                 mov     %i3, %o4
F00D55F4: d2026268                 ld      [%o1+%lo(paEvframebufferd)], %o1! SEL
F00D55F8: 4000709e                 call    _objc_msgSend
F00D55FC: 9a10001c                 mov     %i4, %o5
F00D5600: 81c7e008                 ret
F00D5604: 91e80008                 restore %g0, %o0, %o0
