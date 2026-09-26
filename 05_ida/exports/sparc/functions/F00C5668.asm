F00C5668: 9de3bf88                 save    %sp, -0x78, %sp
F00C566C: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C5670: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5674: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C5678: 4000b07e                 call    _objc_msgSend
F00C567C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C5680: 9010001a                 mov     %i2, %o0
F00C5684: 9207bfec                 add     %fp, var_14, %o1
F00C5688: 7ffffc13                 call    sub_F00C46D4
F00C568C: 9410001b                 mov     %i3, %o2! __n
F00C5690: b0100008                 mov     %o0, %i0
F00C5694: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5698: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C569C: 4000b075                 call    _objc_msgSend
F00C56A0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C56A4: 80a62000                 cmp     %i0, 0
F00C56A8: 12800009                 bne     locret_F00C56CC
F00C56AC: d007bfec                 ld      [%fp+var_14], %o0! id
F00C56B0: 133c0506                 sethi   %hi(paDevicekind_0), %o1! SEL
F00C56B4: 4000b06f                 call    _objc_msgSend
F00C56B8: d20261d0                 ld      [%o1+%lo(paDevicekind_0)], %o1
F00C56BC: 92100008                 mov     %o0, %o1! __src
F00C56C0: 9010001c                 mov     %i4, %o0! __dst
F00C56C4: 7ffd0896                 call    _strncpy
F00C56C8: 94102050                 mov     0x50, %o2 ! 'P'
F00C56CC: 81c7e008                 ret
F00C56D0: 81e80000                 restore
