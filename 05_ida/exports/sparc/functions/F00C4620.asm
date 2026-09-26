F00C4620: 9de3bf90                 save    %sp, -0x70, %sp
F00C4624: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C4628: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C462C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C4630: 4000b490                 call    _objc_msgSend
F00C4634: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C4638: 90100018                 mov     %i0, %o0
F00C463C: 92100019                 mov     %i1, %o1
F00C4640: 40000025                 call    sub_F00C46D4
F00C4644: 9407bff4                 add     %fp, var_C, %o2
F00C4648: b0100008                 mov     %o0, %i0
F00C464C: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C4650: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C4654: 4000b487                 call    _objc_msgSend
F00C4658: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C465C: 81c7e008                 ret
F00C4660: 81e80000                 restore
