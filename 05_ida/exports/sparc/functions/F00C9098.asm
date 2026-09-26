F00C9098: 9de3bf90                 save    %sp, -0x70, %sp
F00C909C: 113c0504                 sethi   %hi(paCount_0), %o0! id
F00C90A0: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F00C90A4: b0102000                 mov     0, %i0
F00C90A8: 4000a1f2                 call    _objc_msgSend
F00C90AC: 9010001a                 mov     %i2, %o0
F00C90B0: a4920000                 orcc    %o0, %g0, %l2
F00C90B4: 24800017                 ble,a   locret_F00C9110
F00C90B8: e426c000                 st      %l2, [%i3]
F00C90BC: 7ffff39d                 call    _IOMalloc
F00C90C0: 912ca002                 sll     %l2, 2, %o0
F00C90C4: a0102000                 mov     0, %l0
F00C90C8: 80a40012                 cmp     %l0, %l2
F00C90CC: 16800010                 bge     loc_F00C910C
F00C90D0: b0100008                 mov     %o0, %i0
F00C90D4: 293c0504                 sethi   -0xFEBF000, %l4
F00C90D8: 273c0504                 sethi   -0xFEBF000, %l3
F00C90DC: a2102000                 mov     0, %l1
F00C90E0: 9010001a                 mov     %i2, %o0! id
F00C90E4: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00C90E8: 4000a1e2                 call    _objc_msgSend
F00C90EC: 94100010                 mov     %l0, %o2
F00C90F0: d204e11c                 ld      [%l3+0x11C], %o1! SEL
F00C90F4: 4000a1df                 call    _objc_msgSend
F00C90F8: a0042001                 inc     %l0
F00C90FC: d0244018                 st      %o0, [%l1+%i0]
F00C9100: 80a40012                 cmp     %l0, %l2
F00C9104: 06bffff7                 bl      loc_F00C90E0
F00C9108: a2046004                 inc     4, %l1
F00C910C: e426c000                 st      %l2, [%i3]
F00C9110: 81c7e008                 ret
F00C9114: 81e80000                 restore
