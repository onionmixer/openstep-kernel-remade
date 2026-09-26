F00C56D4: 9de3bf88                 save    %sp, -0x78, %sp
F00C56D8: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C56DC: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C56E0: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C56E4: 4000b063                 call    _objc_msgSend
F00C56E8: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C56EC: 9010001c                 mov     %i4, %o0
F00C56F0: 7ffffbdd                 call    sub_F00C4664
F00C56F4: 9207bfec                 add     %fp, var_14, %o1
F00C56F8: b0100008                 mov     %o0, %i0
F00C56FC: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5700: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C5704: 4000b05b                 call    _objc_msgSend
F00C5708: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C570C: 80a62000                 cmp     %i0, 0
F00C5710: 12800009                 bne     locret_F00C5734
F00C5714: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00C5718: 9410001a                 mov     %i2, %o2
F00C571C: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5720: 9610001b                 mov     %i3, %o3
F00C5724: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00C5728: 4000b052                 call    _objc_msgSend
F00C572C: 9810001d                 mov     %i5, %o4
F00C5730: b0100008                 mov     %o0, %i0
F00C5734: 81c7e008                 ret
F00C5738: 81e80000                 restore
