F00CC3D4: 9de3bf90                 save    %sp, -0x70, %sp
F00CC3D8: d0062008                 ld      [%i0+8], %o0! id
F00CC3DC: 133c0506                 sethi   %hi(paCondition), %o1! SEL
F00CC3E0: 40009524                 call    _objc_msgSend
F00CC3E4: d2026070                 ld      [%o1+%lo(paCondition)], %o1
F00CC3E8: 80a22002                 cmp     %o0, 2
F00CC3EC: 1280000b                 bne     locret_F00CC418
F00CC3F0: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CC3F4: d0062008                 ld      [%i0+8], %o0! id
F00CC3F8: 4000951e                 call    _objc_msgSend
F00CC3FC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CC400: f4262010                 st      %i2, [%i0+0x10]
F00CC404: d0062008                 ld      [%i0+8], %o0! id
F00CC408: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CC40C: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CC410: 40009518                 call    _objc_msgSend
F00CC414: 94102001                 mov     1, %o2
F00CC418: 81c7e008                 ret
F00CC41C: 81e80000                 restore
