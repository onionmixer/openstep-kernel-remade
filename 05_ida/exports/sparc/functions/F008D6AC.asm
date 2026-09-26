F008D6AC: 9de3bf90                 save    %sp, -0x70, %sp
F008D6B0: 213c04c3                 sethi   %hi(dword_F0130FF8), %l0
F008D6B4: d00423f8                 ld      [%l0+%lo(dword_F0130FF8)], %o0
F008D6B8: 80a22000                 cmp     %o0, 0
F008D6BC: 3280000e                 bne,a   loc_F008D6F4
F008D6C0: 213c04c3                 sethi   -0xFECF400, %l0
F008D6C4: 113c0506                 sethi   %hi(paHashtable), %o0
F008D6C8: d002227c                 ld      [%o0+%lo(paHashtable)], %o0! id
F008D6CC: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008D6D0: 40019068                 call    _objc_msgSend
F008D6D4: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008D6D8: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F008D6DC: 153c0448                 sethi   %hi(asc_F0112038), %o2! "*"
F008D6E0: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F008D6E4: 40019063                 call    _objc_msgSend
F008D6E8: 9412a038                 bset    %lo(asc_F0112038), %o2! "*"
F008D6EC: d02423f8                 st      %o0, [%l0+%lo(dword_F0130FF8)]
F008D6F0: 213c04c3                 sethi   -0xFECF400, %l0
F008D6F4: d00423fc                 ld      [%l0+0x3FC], %o0
F008D6F8: 80a22000                 cmp     %o0, 0
F008D6FC: 1280000c                 bne     locret_F008D72C
F008D700: 113c0506                 sethi   %hi(paHashtable), %o0
F008D704: d002227c                 ld      [%o0+%lo(paHashtable)], %o0! id
F008D708: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008D70C: 40019059                 call    _objc_msgSend
F008D710: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008D714: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F008D718: 153c0448                 sethi   %hi(asc_F0112040), %o2! "*"
F008D71C: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F008D720: 40019054                 call    _objc_msgSend
F008D724: 9412a040                 bset    %lo(asc_F0112040), %o2! "*"
F008D728: d02423fc                 st      %o0, [%l0+0x3FC]
F008D72C: 81c7e008                 ret
F008D730: 81e80000                 restore
