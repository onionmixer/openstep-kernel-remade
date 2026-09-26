F008E2A0: 9de3bf90                 save    %sp, -0x70, %sp
F008E2A4: d0062024                 ld      [%i0+0x24], %o0! id
F008E2A8: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008E2AC: 40018d71                 call    _objc_msgSend
F008E2B0: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008E2B4: d2062020                 ld      [%i0+0x20], %o1
F008E2B8: 90026001                 add     %o1, 1, %o0
F008E2BC: 80a22000                 cmp     %o0, 0
F008E2C0: 16800003                 bge     loc_F008E2CC
F008E2C4: d0262020                 st      %o0, [%i0+0x20]
F008E2C8: d2262020                 st      %o1, [%i0+0x20]
F008E2CC: d0062024                 ld      [%i0+0x24], %o0! id
F008E2D0: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008E2D4: 40018d67                 call    _objc_msgSend
F008E2D8: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F008E2DC: 81c7e008                 ret
F008E2E0: 81e80000                 restore
