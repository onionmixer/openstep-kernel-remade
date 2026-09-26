F0090FC0: 9de3bf90                 save    %sp, -0x70, %sp
F0090FC4: 80a62000                 cmp     %i0, 0
F0090FC8: 12800004                 bne     loc_F0090FD8
F0090FCC: 113c0504                 sethi   -0xFEBF000, %o0! id
F0090FD0: 10800050                 ba      locret_F0091110
F0090FD4: b0103d3f                 mov     -0x2C1, %i0
F0090FD8: d2022158                 ld      [%o0+0x158], %o1! SEL
F0090FDC: 40018225                 call    _objc_msgSend
F0090FE0: 90100018                 mov     %i0, %o0! id
F0090FE4: aa100008                 mov     %o0, %l5
F0090FE8: 133c0504                 sethi   %hi(paResourcesforke), %o1
F0090FEC: 153c0448                 sethi   %hi(aIrqLevels_2), %o2! "IRQ Levels"
F0090FF0: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F0090FF4: 4001821f                 call    _objc_msgSend
F0090FF8: 9412a230                 bset    %lo(aIrqLevels_2), %o2! "IRQ Levels"
F0090FFC: a4100008                 mov     %o0, %l2
F0091000: 113c0504                 sethi   %hi(paCount_0), %o0! id
F0091004: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F0091008: 4001821a                 call    _objc_msgSend
F009100C: 90100012                 mov     %l2, %o0
F0091010: a2100008                 mov     %o0, %l1
F0091014: 80a46080                 cmp     %l1, 0x80
F0091018: 34800002                 bg,a    loc_F0091020
F009101C: a2102080                 mov     0x80, %l1
F0091020: b0102000                 mov     0, %i0
F0091024: 80a60011                 cmp     %i0, %l1
F0091028: 36800011                 bge,a   loc_F009106C
F009102C: e2268000                 st      %l1, [%i2]
F0091030: 293c0504                 sethi   -0xFEBF000, %l4
F0091034: 273c0504                 sethi   -0xFEBF000, %l3
F0091038: a0102000                 mov     0, %l0
F009103C: 90100012                 mov     %l2, %o0! id
F0091040: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F0091044: 4001820b                 call    _objc_msgSend
F0091048: 94100018                 mov     %i0, %o2
F009104C: d204e11c                 ld      [%l3+0x11C], %o1! SEL
F0091050: 40018208                 call    _objc_msgSend
F0091054: b0062001                 inc     %i0
F0091058: d0240019                 st      %o0, [%l0+%i1]
F009105C: 80a60011                 cmp     %i0, %l1
F0091060: 06bffff7                 bl      loc_F009103C
F0091064: a0042004                 inc     4, %l0
F0091068: e2268000                 st      %l1, [%i2]
F009106C: 90100015                 mov     %l5, %o0! id
F0091070: 133c0504                 sethi   %hi(paResourcesforke), %o1
F0091074: 153c0448                 sethi   %hi(aMemoryMaps_2), %o2! "Memory Maps"
F0091078: d2026124                 ld      [%o1+%lo(paResourcesforke)], %o1! SEL
F009107C: 400181fd                 call    _objc_msgSend
F0091080: 9412a240                 bset    %lo(aMemoryMaps_2), %o2! "Memory Maps"
F0091084: a4100008                 mov     %o0, %l2
F0091088: 113c0504                 sethi   %hi(paCount_0), %o0! id
F009108C: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F0091090: 400181f8                 call    _objc_msgSend
F0091094: 90100012                 mov     %l2, %o0
F0091098: a2100008                 mov     %o0, %l1
F009109C: 80a46010                 cmp     %l1, 0x10
F00910A0: 34800002                 bg,a    loc_F00910A8
F00910A4: a2102010                 mov     0x10, %l1
F00910A8: b0102000                 mov     0, %i0
F00910AC: 80a60011                 cmp     %i0, %l1
F00910B0: 36800018                 bge,a   locret_F0091110
F00910B4: e2270000                 st      %l1, [%i4]
F00910B8: 293c0504                 sethi   -0xFEBF000, %l4
F00910BC: 273c0504                 sethi   -0xFEBF000, %l3
F00910C0: a007bff0                 add     %fp, var_10, %l0
F00910C4: 90100012                 mov     %l2, %o0! id
F00910C8: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00910CC: 400181e9                 call    _objc_msgSend
F00910D0: 94100018                 mov     %i0, %o2
F00910D4: d204e058                 ld      [%l3+0x58], %o1! SEL
F00910D8: e023a040                 st      %l0, [%sp+0x70+var_30]
F00910DC: 400181e5                 call    _objc_msgSend
F00910E0: 01000000                 nop
F00910E4: 00000008                 illtrap
F00910E8: d007bff0                 ld      [%fp+var_10], %o0
F00910EC: b0062001                 inc     %i0
F00910F0: d026c000                 st      %o0, [%i3]
F00910F4: d007bff4                 ld      [%fp+var_C], %o0
F00910F8: 80a60011                 cmp     %i0, %l1
F00910FC: d026e004                 st      %o0, [%i3+4]
F0091100: 06bffff1                 bl      loc_F00910C4
F0091104: b606e008                 inc     8, %i3
F0091108: e2270000                 st      %l1, [%i4]
F009110C: b0102000                 mov     0, %i0
F0091110: 81c7e008                 ret
F0091114: 81e80000                 restore
