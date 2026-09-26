F0022F3C: 9de3bf98                 save    %sp, -0x68, %sp
F0022F40: d2062004                 ld      [%i0+4], %o1
F0022F44: a2102000                 mov     0, %l1
F0022F48: d0562008                 ldsh    [%i0+8], %o0
F0022F4C: a5322002                 srl     %o0, 2, %l2
F0022F50: 80a44012                 cmp     %l1, %l2
F0022F54: 1680000e                 bge     loc_F0022F8C
F0022F58: a0060009                 add     %i0, %o1, %l0
F0022F5C: d0040000                 ld      [%l0], %o0
F0022F60: 7fffa149                 call    _getf
F0022F64: a0042004                 inc     4, %l0
F0022F68: 80a22000                 cmp     %o0, 0
F0022F6C: 12800004                 bne     loc_F0022F7C
F0022F70: a2046001                 inc     %l1
F0022F74: 1080001c                 ba      locret_F0022FE4
F0022F78: b0102009                 mov     9, %i0
F0022F7C: 80a44012                 cmp     %l1, %l2
F0022F80: 26bffff8                 bl,a    loc_F0022F60
F0022F84: d0040000                 ld      [%l0], %o0
F0022F88: a2102000                 mov     0, %l1
F0022F8C: d0062004                 ld      [%i0+4], %o0
F0022F90: 80a44012                 cmp     %l1, %l2
F0022F94: 16800013                 bge     loc_F0022FE0
F0022F98: a0060008                 add     %i0, %o0, %l0
F0022F9C: 313c04d4                 sethi   -0xFECB000, %i0
F0022FA0: d0040000                 ld      [%l0], %o0
F0022FA4: 7fffa138                 call    _getf
F0022FA8: a2046001                 inc     %l1
F0022FAC: d0240000                 st      %o0, [%l0]
F0022FB0: a0042004                 inc     4, %l0
F0022FB4: d212200e                 lduh    [%o0+0xE], %o1
F0022FB8: 80a44012                 cmp     %l1, %l2
F0022FBC: d4122010                 lduh    [%o0+0x10], %o2
F0022FC0: 92026001                 inc     %o1
F0022FC4: d232200e                 sth     %o1, [%o0+0xE]
F0022FC8: 9402a001                 inc     %o2
F0022FCC: d20622d0                 ld      [%i0+0x2D0], %o1
F0022FD0: d4322010                 sth     %o2, [%o0+0x10]
F0022FD4: 92026001                 inc     %o1
F0022FD8: 06bffff2                 bl      loc_F0022FA0
F0022FDC: d22622d0                 st      %o1, [%i0+0x2D0]
F0022FE0: b0102000                 mov     0, %i0
F0022FE4: 81c7e008                 ret
F0022FE8: 81e80000                 restore
