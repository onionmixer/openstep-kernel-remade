F00CB2DC: 9de3bf90                 save    %sp, -0x70, %sp
F00CB2E0: d0062008                 ld      [%i0+8], %o0! id
F00CB2E4: 133c0506                 sethi   %hi(paCondition), %o1! SEL
F00CB2E8: 40009962                 call    _objc_msgSend
F00CB2EC: d2026070                 ld      [%o1+%lo(paCondition)], %o1
F00CB2F0: 80a22002                 cmp     %o0, 2
F00CB2F4: 1280000b                 bne     locret_F00CB320
F00CB2F8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CB2FC: d0062008                 ld      [%i0+8], %o0! id
F00CB300: 4000995c                 call    _objc_msgSend
F00CB304: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CB308: f4262010                 st      %i2, [%i0+0x10]
F00CB30C: d0062008                 ld      [%i0+8], %o0! id
F00CB310: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00CB314: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00CB318: 40009956                 call    _objc_msgSend
F00CB31C: 94102001                 mov     1, %o2
F00CB320: 81c7e008                 ret
F00CB324: 81e80000                 restore
