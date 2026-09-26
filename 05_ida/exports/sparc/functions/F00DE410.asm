F00DE410: 9de3bf98                 save    %sp, -0x68, %sp
F00DE414: 80a62000                 cmp     %i0, 0
F00DE418: 12800004                 bne     loc_F00DE428
F00DE41C: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DE420: 1080003f                 ba      locret_F00DE51C
F00DE424: b01020ca                 mov     0xCA, %i0
F00DE428: d2022224                 ld      [%o0+0x224], %o1! SEL
F00DE42C: c0264000                 clr     [%i1]
F00DE430: 40004d10                 call    _objc_msgSend
F00DE434: 90100018                 mov     %i0, %o0! id
F00DE438: a2100008                 mov     %o0, %l1
F00DE43C: 94102005                 mov     5, %o2
F00DE440: 133c0505                 sethi   %hi(paIntvalueforpar), %o1! SEL
F00DE444: e00260f8                 ld      [%o1+%lo(paIntvalueforpar)], %l0
F00DE448: 96100018                 mov     %i0, %o3
F00DE44C: 40004d09                 call    _objc_msgSend
F00DE450: 92100010                 mov     %l0, %o1
F00DE454: 80a22000                 cmp     %o0, 0
F00DE458: 02800006                 be      loc_F00DE470
F00DE45C: 90100011                 mov     %l1, %o0
F00DE460: d0064000                 ld      [%i1], %o0
F00DE464: 90122001                 bset    1, %o0
F00DE468: d0264000                 st      %o0, [%i1]
F00DE46C: 90100011                 mov     %l1, %o0! id
F00DE470: 92100010                 mov     %l0, %o1! SEL
F00DE474: 94102003                 mov     3, %o2
F00DE478: 40004cfe                 call    _objc_msgSend
F00DE47C: 96100018                 mov     %i0, %o3
F00DE480: 80a22000                 cmp     %o0, 0
F00DE484: 02800006                 be      loc_F00DE49C
F00DE488: 90100011                 mov     %l1, %o0
F00DE48C: d0064000                 ld      [%i1], %o0
F00DE490: 90122002                 bset    2, %o0
F00DE494: d0264000                 st      %o0, [%i1]
F00DE498: 90100011                 mov     %l1, %o0! id
F00DE49C: 92100010                 mov     %l0, %o1! SEL
F00DE4A0: 94102004                 mov     4, %o2
F00DE4A4: 40004cf3                 call    _objc_msgSend
F00DE4A8: 96100018                 mov     %i0, %o3
F00DE4AC: 80a22000                 cmp     %o0, 0
F00DE4B0: 02800006                 be      loc_F00DE4C8
F00DE4B4: 90100011                 mov     %l1, %o0
F00DE4B8: d0064000                 ld      [%i1], %o0
F00DE4BC: 90122004                 bset    4, %o0
F00DE4C0: d0264000                 st      %o0, [%i1]
F00DE4C4: 90100011                 mov     %l1, %o0! id
F00DE4C8: 92100010                 mov     %l0, %o1! SEL
F00DE4CC: 94102006                 mov     6, %o2
F00DE4D0: 40004ce8                 call    _objc_msgSend
F00DE4D4: 96100018                 mov     %i0, %o3
F00DE4D8: 80a22000                 cmp     %o0, 0
F00DE4DC: 02800006                 be      loc_F00DE4F4
F00DE4E0: 90100011                 mov     %l1, %o0
F00DE4E4: d0064000                 ld      [%i1], %o0
F00DE4E8: 90122008                 bset    8, %o0
F00DE4EC: d0264000                 st      %o0, [%i1]
F00DE4F0: 90100011                 mov     %l1, %o0! id
F00DE4F4: 92100010                 mov     %l0, %o1! SEL
F00DE4F8: 94102007                 mov     7, %o2
F00DE4FC: 40004cdd                 call    _objc_msgSend
F00DE500: 96100018                 mov     %i0, %o3
F00DE504: 80a22000                 cmp     %o0, 0
F00DE508: 12800005                 bne     locret_F00DE51C
F00DE50C: b0102000                 mov     0, %i0
F00DE510: d0064000                 ld      [%i1], %o0
F00DE514: 90122010                 bset    0x10, %o0
F00DE518: d0264000                 st      %o0, [%i1]
F00DE51C: 81c7e008                 ret
F00DE520: 81e80000                 restore
