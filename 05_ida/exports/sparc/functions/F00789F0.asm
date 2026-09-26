F00789F0: 9de3bf98                 save    %sp, -0x68, %sp
F00789F4: 133c04f2                 sethi   %hi(_zone_free_space_count), %o1
F00789F8: d80263d0                 ld      [%o1+%lo(_zone_free_space_count)], %o4
F00789FC: 80a32007                 cmp     %o4, 7
F0078A00: 08800004                 bleu    loc_F0078A10
F0078A04: a0100018                 mov     %i0, %l0
F0078A08: 10800029                 ba      locret_F0078AAC
F0078A0C: b0102000                 mov     0, %i0
F0078A10: 90032001                 add     %o4, 1, %o0
F0078A14: d02263d0                 st      %o0, [%o1+0x3D0]
F0078A18: 113c04f290122350         set     __zone_default_space, %o0
F0078A20: 9210201c                 mov     0x1C, %o1
F0078A24: 94102000                 mov     0, %o2
F0078A28: 992b2002                 sll     %o4, 2, %o4
F0078A2C: 173c04f29612e3b0         set     _zone_free_space, %o3
F0078A34: 7fffff6c                 call    _zget_space
F0078A38: a203000b                 add     %o4, %o3, %l1
F0078A3C: b0100008                 mov     %o0, %i0
F0078A40: e0260000                 st      %l0, [%i0]
F0078A44: f2262004                 st      %i1, [%i0+4]
F0078A48: c0262008                 clr     [%i0+8]
F0078A4C: c026200c                 clr     [%i0+0xC]
F0078A50: 808c2001                 btst    1, %l0
F0078A54: 12800008                 bne     loc_F0078A74
F0078A58: c0262010                 clr     [%i0+0x10]
F0078A5C: a1342001                 srl     %l0, 1, %l0
F0078A60: d0062010                 ld      [%i0+0x10], %o0
F0078A64: 808c2001                 btst    1, %l0
F0078A68: 90022001                 inc     %o0
F0078A6C: 02bffffc                 be      loc_F0078A5C
F0078A70: d0262010                 st      %o0, [%i0+0x10]
F0078A74: 113c04f2                 sethi   %hi(__zone_default_space), %o0
F0078A78: d2062004                 ld      [%i0+4], %o1
F0078A7C: 90122350                 bset    %lo(__zone_default_space), %o0! void *
F0078A80: d6062010                 ld      [%i0+0x10], %o3
F0078A84: 94102000                 mov     0, %o2
F0078A88: 9332400b                 srl     %o1, %o3, %o1
F0078A8C: d2262018                 st      %o1, [%i0+0x18]
F0078A90: 7fffff55                 call    _zget_space
F0078A94: 932a6004                 sll     %o1, 4, %o1
F0078A98: d2062018                 ld      [%i0+0x18], %o1! size_t
F0078A9C: d0262014                 st      %o0, [%i0+0x14]
F0078AA0: 400070ee                 call    _bzero
F0078AA4: 932a6004                 sll     %o1, 4, %o1
F0078AA8: f0244000                 st      %i0, [%l1]
F0078AAC: 81c7e008                 ret
F0078AB0: 81e80000                 restore
