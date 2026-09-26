F00DD818: 9de3bf78                 save    %sp, -0x88, %sp
F00DD81C: a007bfd8                 add     %fp, __b, %l0
F00DD820: 90100010                 mov     %l0, %o0! __b
F00DD824: 92102000                 mov     0, %o1! __c
F00DD828: 7ffca2d5                 call    _memset
F00DD82C: 94102018                 mov     0x18, %o2
F00DD830: 94102003                 mov     3, %o2
F00DD834: d20fbfdb                 ldub    [%fp+__b+3], %o1! SEL
F00DD838: 113c0503                 sethi   %hi(paLockwhen), %o0
F00DD83C: e20223f8                 ld      [%o0+%lo(paLockwhen)], %l1
F00DD840: d227bfd8                 st      %o1, [%fp+__b]
F00DD844: d0062008                 ld      [%i0+8], %o0! id
F00DD848: 4000500a                 call    _objc_msgSend
F00DD84C: 92100011                 mov     %l1, %o1
F00DD850: f426200c                 st      %i2, [%i0+0xC]
F00DD854: 90102018                 mov     0x18, %o0
F00DD858: d027bfdc                 st      %o0, [%fp+var_24]
F00DD85C: d4062004                 ld      [%i0+4], %o2
F00DD860: 113c0504                 sethi   %hi(paUnlockwith), %o0
F00DD864: d2022004                 ld      [%o0+%lo(paUnlockwith)], %o1! SEL
F00DD868: d427bfe8                 st      %o2, [%fp+var_18]
F00DD86C: 90102386                 mov     0x386, %o0
F00DD870: d027bfec                 st      %o0, [%fp+var_14]
F00DD874: d0062008                 ld      [%i0+8], %o0! id
F00DD878: 40004ffe                 call    _objc_msgSend
F00DD87C: 94102002                 mov     2, %o2
F00DD880: 90100010                 mov     %l0, %o0
F00DD884: 92102001                 mov     1, %o1
F00DD888: 7ffe20e9                 call    _msg_send_from_kernel
F00DD88C: 941023e8                 mov     0x3E8, %o2
F00DD890: a0920000                 orcc    %o0, %g0, %l0
F00DD894: 12800007                 bne     loc_F00DD8B0
F00DD898: d0062008                 ld      [%i0+8], %o0! id
F00DD89C: 92100011                 mov     %l1, %o1! SEL
F00DD8A0: 40004ff4                 call    _objc_msgSend
F00DD8A4: 94102001                 mov     1, %o2
F00DD8A8: 10800005                 ba      loc_F00DD8BC
F00DD8AC: e0062010                 ld      [%i0+0x10], %l0
F00DD8B0: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DD8B4: 40004fef                 call    _objc_msgSend
F00DD8B8: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DD8BC: d0062008                 ld      [%i0+8], %o0! id
F00DD8C0: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00DD8C4: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00DD8C8: 40004fea                 call    _objc_msgSend
F00DD8CC: 94102003                 mov     3, %o2
F00DD8D0: 81c7e008                 ret
F00DD8D4: 91e80010                 restore %g0, %l0, %o0
