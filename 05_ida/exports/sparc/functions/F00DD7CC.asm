F00DD7CC: 9de3bf90                 save    %sp, -0x70, %sp
F00DD7D0: d0062008                 ld      [%i0+8], %o0! id
F00DD7D4: 133c0506                 sethi   %hi(paCondition), %o1! SEL
F00DD7D8: 40005026                 call    _objc_msgSend
F00DD7DC: d2026070                 ld      [%o1+%lo(paCondition)], %o1
F00DD7E0: 80a22002                 cmp     %o0, 2
F00DD7E4: 1280000b                 bne     locret_F00DD810
F00DD7E8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DD7EC: d0062008                 ld      [%i0+8], %o0! id
F00DD7F0: 40005020                 call    _objc_msgSend
F00DD7F4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DD7F8: f4262010                 st      %i2, [%i0+0x10]
F00DD7FC: d0062008                 ld      [%i0+8], %o0! id
F00DD800: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00DD804: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00DD808: 4000501a                 call    _objc_msgSend
F00DD80C: 94102001                 mov     1, %o2
F00DD810: 81c7e008                 ret
F00DD814: 81e80000                 restore
