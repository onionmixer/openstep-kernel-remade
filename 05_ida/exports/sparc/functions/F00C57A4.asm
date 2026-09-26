F00C57A4: 9de3bf88                 save    %sp, -0x78, %sp
F00C57A8: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C57AC: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C57B0: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C57B4: 4000b02f                 call    _objc_msgSend
F00C57B8: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C57BC: 9010001c                 mov     %i4, %o0
F00C57C0: 7ffffba9                 call    sub_F00C4664
F00C57C4: 9207bfec                 add     %fp, var_14, %o1
F00C57C8: b0100008                 mov     %o0, %i0
F00C57CC: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C57D0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C57D4: 4000b027                 call    _objc_msgSend
F00C57D8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C57DC: 80a62000                 cmp     %i0, 0
F00C57E0: 12800009                 bne     locret_F00C5804
F00C57E4: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00C57E8: 9410001a                 mov     %i2, %o2
F00C57EC: d007bfec                 ld      [%fp+var_14], %o0! id
F00C57F0: 9610001b                 mov     %i3, %o3
F00C57F4: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00C57F8: 4000b01e                 call    _objc_msgSend
F00C57FC: 9810001d                 mov     %i5, %o4
F00C5800: b0100008                 mov     %o0, %i0
F00C5804: 81c7e008                 ret
F00C5808: 81e80000                 restore
