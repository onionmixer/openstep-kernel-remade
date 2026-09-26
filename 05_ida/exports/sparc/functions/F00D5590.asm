F00D5590: 9de3bf98                 save    %sp, -0x68, %sp
F00D5594: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D5598: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D559C: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D55A0: 400070b4                 call    _objc_msgSend
F00D55A4: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D55A8: 133c0505                 sethi   %hi(paMapeventshmemT), %o1
F00D55AC: 94100019                 mov     %i1, %o2
F00D55B0: 9610001a                 mov     %i2, %o3
F00D55B4: 9810001b                 mov     %i3, %o4
F00D55B8: d202626c                 ld      [%o1+%lo(paMapeventshmemT)], %o1! SEL
F00D55BC: 400070ad                 call    _objc_msgSend
F00D55C0: 9a10001c                 mov     %i4, %o5
F00D55C4: 81c7e008                 ret
F00D55C8: 91e80008                 restore %g0, %o0, %o0
