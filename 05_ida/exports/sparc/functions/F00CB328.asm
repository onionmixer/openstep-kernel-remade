F00CB328: 9de3bf78                 save    %sp, -0x88, %sp
F00CB32C: a007bfd8                 add     %fp, __b, %l0
F00CB330: 90100010                 mov     %l0, %o0! __b
F00CB334: 92102000                 mov     0, %o1! __c
F00CB338: 7ffcec11                 call    _memset
F00CB33C: 94102018                 mov     0x18, %o2
F00CB340: 94102003                 mov     3, %o2
F00CB344: d20fbfdb                 ldub    [%fp+__b+3], %o1! SEL
F00CB348: 113c0503                 sethi   %hi(paLockwhen), %o0
F00CB34C: e20223f8                 ld      [%o0+%lo(paLockwhen)], %l1
F00CB350: d227bfd8                 st      %o1, [%fp+__b]
F00CB354: d0062008                 ld      [%i0+8], %o0! id
F00CB358: 40009946                 call    _objc_msgSend
F00CB35C: 92100011                 mov     %l1, %o1
F00CB360: f426200c                 st      %i2, [%i0+0xC]
F00CB364: 90102018                 mov     0x18, %o0
F00CB368: d027bfdc                 st      %o0, [%fp+var_24]
F00CB36C: d4062004                 ld      [%i0+4], %o2
F00CB370: 113c0504                 sethi   %hi(paUnlockwith), %o0
F00CB374: d2022004                 ld      [%o0+%lo(paUnlockwith)], %o1! SEL
F00CB378: d427bfe8                 st      %o2, [%fp+var_18]
F00CB37C: 110008c890122324         set     0x232324, %o0
F00CB384: d027bfec                 st      %o0, [%fp+var_14]
F00CB388: d0062008                 ld      [%i0+8], %o0! id
F00CB38C: 40009939                 call    _objc_msgSend
F00CB390: 94102002                 mov     2, %o2
F00CB394: 90100010                 mov     %l0, %o0
F00CB398: 92102000                 mov     0, %o1
F00CB39C: 7ffe6a24                 call    _msg_send_from_kernel
F00CB3A0: 94102000                 mov     0, %o2
F00CB3A4: a0920000                 orcc    %o0, %g0, %l0
F00CB3A8: 12800007                 bne     loc_F00CB3C4
F00CB3AC: d0062008                 ld      [%i0+8], %o0! id
F00CB3B0: 92100011                 mov     %l1, %o1! SEL
F00CB3B4: 4000992f                 call    _objc_msgSend
F00CB3B8: 94102001                 mov     1, %o2
F00CB3BC: 10800005                 ba      loc_F00CB3D0
F00CB3C0: e0062010                 ld      [%i0+0x10], %l0
F00CB3C4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CB3C8: 4000992a                 call    _objc_msgSend
F00CB3CC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CB3D0: d0062008                 ld      [%i0+8], %o0! id
F00CB3D4: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CB3D8: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CB3DC: 40009925                 call    _objc_msgSend
F00CB3E0: 94102003                 mov     3, %o2
F00CB3E4: 81c7e008                 ret
F00CB3E8: 91e80010                 restore %g0, %l0, %o0
