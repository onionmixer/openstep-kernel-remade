F00C4C08: 9de3bf90                 save    %sp, -0x70, %sp
F00C4C0C: 113c04cc                 sethi   %hi(dword_F013303C), %o0
F00C4C10: d002203c                 ld      [%o0+%lo(dword_F013303C)], %o0! id
F00C4C14: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C4C18: 4000b316                 call    _objc_msgSend
F00C4C1C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C4C20: 7ffffecc                 call    sub_F00C4750
F00C4C24: 90100018                 mov     %i0, %o0
F00C4C28: a0920000                 orcc    %o0, %g0, %l0
F00C4C2C: 02800019                 be      loc_F00C4C90
F00C4C30: 113c03ea                 sethi   %hi(aUnregisteringD), %o0! "Unregistering Device: %s\n"
F00C4C34: 90122078                 bset    %lo(aUnregisteringD), %o0! "Unregistering Device: %s\n"
F00C4C38: 4000052f                 call    _IOLog
F00C4C3C: 92062008                 add     %i0, 8, %o1
F00C4C40: d4042008                 ld      [%l0+8], %o2
F00C4C44: 113c04cc90122034         set     dword_F0133034, %o0
F00C4C4C: 80a28008                 cmp     %o2, %o0
F00C4C50: 02800004                 be      loc_F00C4C60
F00C4C54: d204200c                 ld      [%l0+0xC], %o1
F00C4C58: 10800003                 ba      loc_F00C4C64
F00C4C5C: 9002a008                 add     %o2, 8, %o0
F00C4C60: 9010000a                 mov     %o2, %o0
F00C4C64: d2222004                 st      %o1, [%o0+4]
F00C4C68: 113c04cc90122034         set     dword_F0133034, %o0
F00C4C70: 80a24008                 cmp     %o1, %o0
F00C4C74: 12800003                 bne     loc_F00C4C80
F00C4C78: 90026008                 add     %o1, 8, %o0
F00C4C7C: 90100009                 mov     %o1, %o0
F00C4C80: d4220000                 st      %o2, [%o0]
F00C4C84: 90100010                 mov     %l0, %o0
F00C4C88: 400004af                 call    _IOFree
F00C4C8C: 92102010                 mov     0x10, %o1
F00C4C90: 113c04cc                 sethi   %hi(dword_F013303C), %o0
F00C4C94: d002203c                 ld      [%o0+%lo(dword_F013303C)], %o0! id
F00C4C98: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C4C9C: 4000b2f5                 call    _objc_msgSend
F00C4CA0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C4CA4: 81c7e008                 ret
F00C4CA8: 81e80000                 restore
