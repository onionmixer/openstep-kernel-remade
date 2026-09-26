F008D760: 9de3bf90                 save    %sp, -0x70, %sp
F008D764: b010001a                 mov     %i2, %i0
F008D768: 353c04c3                 sethi   %hi(dword_F0130FFC), %i2
F008D76C: d006a3fc                 ld      [%i2+%lo(dword_F0130FFC)], %o0! id
F008D770: 133c0504                 sethi   %hi(paValueforkey), %o1
F008D774: d202606c                 ld      [%o1+%lo(paValueforkey)], %o1! SEL
F008D778: 4001903e                 call    _objc_msgSend
F008D77C: 9410001b                 mov     %i3, %o2
F008D780: a0920000                 orcc    %o0, %g0, %l0
F008D784: 12800014                 bne     loc_F008D7D4
F008D788: 90100010                 mov     %l0, %o0
F008D78C: 113c0506                 sethi   %hi(paHashtable), %o0
F008D790: d002227c                 ld      [%o0+%lo(paHashtable)], %o0! id
F008D794: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008D798: 40019036                 call    _objc_msgSend
F008D79C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008D7A0: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F008D7A4: 153c0448                 sethi   %hi(aI_3), %o2! "i"
F008D7A8: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F008D7AC: 40019031                 call    _objc_msgSend
F008D7B0: 9412a048                 bset    %lo(aI_3), %o2! "i"
F008D7B4: a0100008                 mov     %o0, %l0
F008D7B8: 9410001b                 mov     %i3, %o2
F008D7BC: d006a3fc                 ld      [%i2+0x3FC], %o0! id
F008D7C0: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008D7C4: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008D7C8: 4001902a                 call    _objc_msgSend
F008D7CC: 96100010                 mov     %l0, %o3
F008D7D0: 90100010                 mov     %l0, %o0! id
F008D7D4: 133c0504                 sethi   %hi(paInsertkeyValue), %o1
F008D7D8: d2026068                 ld      [%o1+%lo(paInsertkeyValue)], %o1! SEL
F008D7DC: 9410001c                 mov     %i4, %o2
F008D7E0: 40019024                 call    _objc_msgSend
F008D7E4: 96100018                 mov     %i0, %o3
F008D7E8: 81c7e008                 ret
F008D7EC: 81e80000                 restore
