F00D04C4: 9de3bf90                 save    %sp, -0x70, %sp
F00D04C8: d006212c                 ld      [%i0+0x12C], %o0! id
F00D04CC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D04D0: 400084e8                 call    _objc_msgSend
F00D04D4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D04D8: d0062130                 ld      [%i0+0x130], %o0
F00D04DC: 80a68008                 cmp     %i2, %o0
F00D04E0: 0280000c                 be      loc_F00D0510
F00D04E4: 213c03ed                 sethi   %hi(aSBogusCloseCal), %l0! "%s: bogus close call\n"
F00D04E8: 90100018                 mov     %i0, %o0! id
F00D04EC: 133c0504                 sethi   %hi(paName), %o1
F00D04F0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D04F4: 400084df                 call    _objc_msgSend
F00D04F8: a0142290                 bset    %lo(aSBogusCloseCal), %l0! "%s: bogus close call\n"
F00D04FC: 92100008                 mov     %o0, %o1
F00D0500: 7fffd6fd                 call    _IOLog
F00D0504: 90100010                 mov     %l0, %o0
F00D0508: 10800008                 ba      loc_F00D0528
F00D050C: d006212c                 ld      [%i0+0x12C], %o0
F00D0510: 113c0505                 sethi   %hi(paClearreservati), %o0! id
F00D0514: d2022368                 ld      [%o0+%lo(paClearreservati)], %o1! SEL
F00D0518: 400084d6                 call    _objc_msgSend
F00D051C: 90100018                 mov     %i0, %o0
F00D0520: c0262130                 clr     [%i0+0x130]
F00D0524: d006212c                 ld      [%i0+0x12C], %o0! id
F00D0528: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D052C: 400084d1                 call    _objc_msgSend
F00D0530: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D0534: 81c7e008                 ret
F00D0538: 81e80000                 restore
