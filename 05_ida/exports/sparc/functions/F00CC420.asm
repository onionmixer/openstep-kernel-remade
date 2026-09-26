F00CC420: 9de3bf78                 save    %sp, -0x88, %sp
F00CC424: a007bfd8                 add     %fp, __b, %l0
F00CC428: 90100010                 mov     %l0, %o0! __b
F00CC42C: 92102000                 mov     0, %o1! __c
F00CC430: 7ffce7d3                 call    _memset
F00CC434: 94102018                 mov     0x18, %o2
F00CC438: 94102003                 mov     3, %o2
F00CC43C: d20fbfdb                 ldub    [%fp+__b+3], %o1! SEL
F00CC440: 113c0503                 sethi   %hi(paLockwhen), %o0
F00CC444: e20223f8                 ld      [%o0+%lo(paLockwhen)], %l1
F00CC448: d227bfd8                 st      %o1, [%fp+__b]
F00CC44C: d0062008                 ld      [%i0+8], %o0! id
F00CC450: 40009508                 call    _objc_msgSend
F00CC454: 92100011                 mov     %l1, %o1
F00CC458: f426200c                 st      %i2, [%i0+0xC]
F00CC45C: 90102018                 mov     0x18, %o0
F00CC460: d027bfdc                 st      %o0, [%fp+var_24]
F00CC464: d4062004                 ld      [%i0+4], %o2
F00CC468: 113c0504                 sethi   %hi(paUnlockwith), %o0
F00CC46C: d2022004                 ld      [%o0+%lo(paUnlockwith)], %o1! SEL
F00CC470: d427bfe8                 st      %o2, [%fp+var_18]
F00CC474: 110008c890122324         set     0x232324, %o0
F00CC47C: d027bfec                 st      %o0, [%fp+var_14]
F00CC480: d0062008                 ld      [%i0+8], %o0! id
F00CC484: 400094fb                 call    _objc_msgSend
F00CC488: 94102002                 mov     2, %o2
F00CC48C: 90100010                 mov     %l0, %o0
F00CC490: 92102000                 mov     0, %o1
F00CC494: 7ffe65e6                 call    _msg_send_from_kernel
F00CC498: 94102000                 mov     0, %o2
F00CC49C: a0920000                 orcc    %o0, %g0, %l0
F00CC4A0: 12800007                 bne     loc_F00CC4BC
F00CC4A4: d0062008                 ld      [%i0+8], %o0! id
F00CC4A8: 92100011                 mov     %l1, %o1! SEL
F00CC4AC: 400094f1                 call    _objc_msgSend
F00CC4B0: 94102001                 mov     1, %o2
F00CC4B4: 10800005                 ba      loc_F00CC4C8
F00CC4B8: e0062010                 ld      [%i0+0x10], %l0
F00CC4BC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CC4C0: 400094ec                 call    _objc_msgSend
F00CC4C4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CC4C8: d0062008                 ld      [%i0+8], %o0! id
F00CC4CC: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CC4D0: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CC4D4: 400094e7                 call    _objc_msgSend
F00CC4D8: 94102003                 mov     3, %o2
F00CC4DC: 81c7e008                 ret
F00CC4E0: 91e80010                 restore %g0, %l0, %o0
