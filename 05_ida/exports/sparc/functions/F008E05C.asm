F008E05C: 9de3bf90                 save    %sp, -0x70, %sp
F008E060: 113c0504                 sethi   %hi(paAcquire), %o0
F008E064: e0022098                 ld      [%o0+%lo(paAcquire)], %l0
F008E068: d006201c                 ld      [%i0+0x1C], %o0! id
F008E06C: 40018e01                 call    _objc_msgSend
F008E070: 92100010                 mov     %l0, %o1
F008E074: d0062018                 ld      [%i0+0x18], %o0
F008E078: 80a22000                 cmp     %o0, 0
F008E07C: 04800006                 ble     loc_F008E094
F008E080: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008E084: d006201c                 ld      [%i0+0x1C], %o0! id
F008E088: 40018dfa                 call    _objc_msgSend
F008E08C: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008E090: 30800026                 ba,a    locret_F008E128
F008E094: d0062024                 ld      [%i0+0x24], %o0! id
F008E098: 40018df6                 call    _objc_msgSend
F008E09C: 92100010                 mov     %l0, %o1
F008E0A0: d2062020                 ld      [%i0+0x20], %o1! SEL
F008E0A4: 90026001                 add     %o1, 1, %o0
F008E0A8: 80a22000                 cmp     %o0, 0
F008E0AC: 16800003                 bge     loc_F008E0B8
F008E0B0: d0262020                 st      %o0, [%i0+0x20]
F008E0B4: d2262020                 st      %o1, [%i0+0x20]
F008E0B8: 113c0504                 sethi   %hi(paRelease), %o0
F008E0BC: e002209c                 ld      [%o0+%lo(paRelease)], %l0
F008E0C0: d0062024                 ld      [%i0+0x24], %o0! id
F008E0C4: 40018deb                 call    _objc_msgSend
F008E0C8: 92100010                 mov     %l0, %o1! SEL
F008E0CC: d006201c                 ld      [%i0+0x1C], %o0! id
F008E0D0: 40018de8                 call    _objc_msgSend
F008E0D4: 92100010                 mov     %l0, %o1! SEL
F008E0D8: 113c0503                 sethi   %hi(paFree), %o0
F008E0DC: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F008E0E0: d0062014                 ld      [%i0+0x14], %o0! id
F008E0E4: 40018de3                 call    _objc_msgSend
F008E0E8: 92100010                 mov     %l0, %o1! SEL
F008E0EC: d0062024                 ld      [%i0+0x24], %o0! id
F008E0F0: 40018de0                 call    _objc_msgSend
F008E0F4: 92100010                 mov     %l0, %o1! SEL
F008E0F8: d006201c                 ld      [%i0+0x1C], %o0! id
F008E0FC: 40018ddd                 call    _objc_msgSend
F008E100: 92100010                 mov     %l0, %o1
F008E104: f027bff0                 st      %i0, [%fp+var_10]
F008E108: 133c0507                 sethi   %hi(stru_F0141C3C.ext), %o1
F008E10C: d4026068                 ld      [%o1+%lo(stru_F0141C3C.ext)], %o2
F008E110: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008E114: 133c0504                 sethi   %hi(paDealloc), %o1
F008E118: d2026048                 ld      [%o1+%lo(paDealloc)], %o1! SEL
F008E11C: 40018e18                 call    _objc_msgSendSuper
F008E120: d427bff4                 st      %o2, [%fp+var_C]
F008E124: b0100008                 mov     %o0, %i0
F008E128: 81c7e008                 ret
F008E12C: 81e80000                 restore
