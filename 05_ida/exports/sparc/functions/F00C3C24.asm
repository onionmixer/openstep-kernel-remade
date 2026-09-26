F00C3C24: 9de3bf98                 save    %sp, -0x68, %sp
F00C3C28: 113c0485a4122050         set     _static_KERNBOOTSTRUCT, %l2
F00C3C30: d004a140                 ld      [%l2+0x140], %o0
F00C3C34: a0102000                 mov     0, %l0
F00C3C38: 80a40008                 cmp     %l0, %o0
F00C3C3C: 1680000a                 bge     locret_F00C3C64
F00C3C40: a2100012                 mov     %l2, %l1
F00C3C44: a0042001                 inc     %l0
F00C3C48: d0046154                 ld      [%l1+0x154], %o0
F00C3C4C: 4000b43c                 call    _objc_registerModule
F00C3C50: 92102000                 mov     0, %o1
F00C3C54: d004a140                 ld      [%l2+0x140], %o0
F00C3C58: 80a40008                 cmp     %l0, %o0
F00C3C5C: 06bffffa                 bl      loc_F00C3C44
F00C3C60: a2046008                 inc     8, %l1
F00C3C64: 81c7e008                 ret
F00C3C68: 81e80000                 restore
