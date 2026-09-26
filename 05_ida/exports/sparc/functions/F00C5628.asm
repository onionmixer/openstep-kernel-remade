F00C5628: 9de3bf90                 save    %sp, -0x70, %sp
F00C562C: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C5630: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5634: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C5638: 4000b08e                 call    _objc_msgSend
F00C563C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C5640: 9010001a                 mov     %i2, %o0
F00C5644: 7ffffc08                 call    sub_F00C4664
F00C5648: 9210001b                 mov     %i3, %o1
F00C564C: b0100008                 mov     %o0, %i0
F00C5650: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5654: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C5658: 4000b086                 call    _objc_msgSend
F00C565C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C5660: 81c7e008                 ret
F00C5664: 81e80000                 restore
