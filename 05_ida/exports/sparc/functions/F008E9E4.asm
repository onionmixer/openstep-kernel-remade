F008E9E4: 9de3bf90                 save    %sp, -0x70, %sp
F008E9E8: d0062008                 ld      [%i0+8], %o0! id
F008E9EC: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008E9F0: 40018ba0                 call    _objc_msgSend
F008E9F4: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008E9F8: e2062004                 ld      [%i0+4], %l1
F008E9FC: 80a46000                 cmp     %l1, 0
F008EA00: 12800007                 bne     loc_F008EA1C
F008EA04: d0062008                 ld      [%i0+8], %o0! id
F008EA08: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008EA0C: 40018b99                 call    _objc_msgSend
F008EA10: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F008EA14: 1080000e                 ba      locret_F008EA4C
F008EA18: b0102000                 mov     0, %i0
F008EA1C: 133c0504                 sethi   %hi(paRelease), %o1
F008EA20: e00e2018                 ldub    [%i0+0x18], %l0
F008EA24: 94102001                 mov     1, %o2
F008EA28: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008EA2C: 40018b91                 call    _objc_msgSend
F008EA30: d42e2018                 stb     %o2, [%i0+0x18]
F008EA34: 80a42000                 cmp     %l0, 0
F008EA38: 12800005                 bne     locret_F008EA4C
F008EA3C: 113c0504                 sethi   %hi(paSuspend), %o0! id
F008EA40: d20220d4                 ld      [%o0+%lo(paSuspend)], %o1! SEL
F008EA44: 40018b8b                 call    _objc_msgSend
F008EA48: 90100011                 mov     %l1, %o0
F008EA4C: 81c7e008                 ret
F008EA50: 81e80000                 restore
