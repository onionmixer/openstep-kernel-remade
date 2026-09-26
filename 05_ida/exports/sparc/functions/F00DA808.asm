F00DA808: 9de3bf90                 save    %sp, -0x70, %sp
F00DA80C: a2102000                 mov     0, %l1
F00DA810: 2d3c0504                 sethi   -0xFEBF000, %l6
F00DA814: 113c0506                 sethi   %hi(paList), %o0
F00DA818: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00DA81C: 133c0503                 sethi   %hi(paAlloc), %o1
F00DA820: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00DA824: 40005c13                 call    _objc_msgSend
F00DA828: 2b3c0504                 sethi   -0xFEBF000, %l5
F00DA82C: 133c0504                 sethi   %hi(paInit), %o1
F00DA830: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00DA834: 40005c0f                 call    _objc_msgSend
F00DA838: 293c0505                 sethi   -0xFEBEC00, %l4
F00DA83C: a4100008                 mov     %o0, %l2
F00DA840: d0062010                 ld      [%i0+0x10], %o0! id
F00DA844: 133c0504                 sethi   %hi(paLock), %o1
F00DA848: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00DA84C: 40005c09                 call    _objc_msgSend
F00DA850: 273c0504                 sethi   -0xFEBF000, %l3
F00DA854: d006200c                 ld      [%i0+0xC], %o0! id
F00DA858: 40005c06                 call    _objc_msgSend
F00DA85C: d205a0b8                 ld      [%l6+0xB8], %o1
F00DA860: 80a44008                 cmp     %l1, %o0
F00DA864: 1a800010                 bcc     loc_F00DA8A4
F00DA868: d20560c8                 ld      [%l5+0xC8], %o1! SEL
F00DA86C: d006200c                 ld      [%i0+0xC], %o0! id
F00DA870: 40005c00                 call    _objc_msgSend
F00DA874: 94100011                 mov     %l1, %o2
F00DA878: a0100008                 mov     %o0, %l0
F00DA87C: 40005bfd                 call    _objc_msgSend
F00DA880: d2052098                 ld      [%l4+0x98], %o1
F00DA884: 80a22000                 cmp     %o0, 0
F00DA888: 02800005                 be      loc_F00DA89C
F00DA88C: 90100012                 mov     %l2, %o0! id
F00DA890: d204e0a4                 ld      [%l3+0xA4], %o1! SEL
F00DA894: 40005bf7                 call    _objc_msgSend
F00DA898: 94100010                 mov     %l0, %o2
F00DA89C: 10bfffee                 ba      loc_F00DA854
F00DA8A0: a2046001                 inc     %l1
F00DA8A4: a2102000                 mov     0, %l1
F00DA8A8: 293c0504                 sethi   %hi(paCount_0), %l4
F00DA8AC: 273c0505                 sethi   -0xFEBEC00, %l3
F00DA8B0: d0062010                 ld      [%i0+0x10], %o0! id
F00DA8B4: 133c0504                 sethi   %hi(paUnlock), %o1
F00DA8B8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00DA8BC: 40005bed                 call    _objc_msgSend
F00DA8C0: 213c0504                 sethi   -0xFEBF000, %l0
F00DA8C4: d20520b8                 ld      [%l4+%lo(paCount_0)], %o1! SEL
F00DA8C8: 40005bea                 call    _objc_msgSend
F00DA8CC: 90100012                 mov     %l2, %o0
F00DA8D0: 80a44008                 cmp     %l1, %o0
F00DA8D4: 1a80000c                 bcc     loc_F00DA904
F00DA8D8: 94100011                 mov     %l1, %o2
F00DA8DC: 90100012                 mov     %l2, %o0! id
F00DA8E0: d20420c8                 ld      [%l0+0xC8], %o1! SEL
F00DA8E4: 40005be3                 call    _objc_msgSend
F00DA8E8: a2046001                 inc     %l1
F00DA8EC: 94100008                 mov     %o0, %o2
F00DA8F0: d204e094                 ld      [%l3+0x94], %o1! SEL
F00DA8F4: 40005bdf                 call    _objc_msgSend
F00DA8F8: 90100018                 mov     %i0, %o0
F00DA8FC: 10bffff3                 ba      loc_F00DA8C8
F00DA900: d20520b8                 ld      [%l4+0xB8], %o1
F00DA904: 113c0503                 sethi   %hi(paFree), %o0! id
F00DA908: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00DA90C: 40005bd9                 call    _objc_msgSend
F00DA910: 90100012                 mov     %l2, %o0
F00DA914: 81c7e008                 ret
F00DA918: 81e80000                 restore
