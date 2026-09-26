F00C55A0: 9de3bf88                 save    %sp, -0x78, %sp
F00C55A4: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C55A8: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C55AC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C55B0: 4000b0b0                 call    _objc_msgSend
F00C55B4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C55B8: 9010001a                 mov     %i2, %o0
F00C55BC: 7ffffc2a                 call    sub_F00C4664
F00C55C0: 9207bfec                 add     %fp, var_14, %o1
F00C55C4: b0100008                 mov     %o0, %i0
F00C55C8: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C55CC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C55D0: 4000b0a8                 call    _objc_msgSend
F00C55D4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C55D8: 80a62000                 cmp     %i0, 0
F00C55DC: 12800011                 bne     locret_F00C5620
F00C55E0: d007bfec                 ld      [%fp+var_14], %o0! id
F00C55E4: 133c0506                 sethi   %hi(paDevicekind_0), %o1! SEL
F00C55E8: 4000b0a2                 call    _objc_msgSend
F00C55EC: d20261d0                 ld      [%o1+%lo(paDevicekind_0)], %o1
F00C55F0: 92100008                 mov     %o0, %o1! __src
F00C55F4: 9010001b                 mov     %i3, %o0! __dst
F00C55F8: 7ffd08c9                 call    _strncpy
F00C55FC: 94102050                 mov     0x50, %o2 ! 'P'! __n
F00C5600: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5604: 133c0504                 sethi   %hi(paName), %o1! SEL
F00C5608: 4000b09a                 call    _objc_msgSend
F00C560C: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C5610: 92100008                 mov     %o0, %o1! __src
F00C5614: 9010001c                 mov     %i4, %o0! __dst
F00C5618: 7ffd08c1                 call    _strncpy
F00C561C: 94102050                 mov     0x50, %o2 ! 'P'
F00C5620: 81c7e008                 ret
F00C5624: 81e80000                 restore
