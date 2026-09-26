F009FA5C: 9de3bf88                 save    %sp, -0x78, %sp
F009FA60: 7fffdca7                 call    _splvm
F009FA64: 01000000                 nop
F009FA68: ac100008                 mov     %o0, %l6
F009FA6C: 113c04f790122270         set     _pmap_info, %o0
F009FA74: d20220b0                 ld      [%o0+0xB0], %o1
F009FA78: 153c04f8a012a028         set     dword_F013E028, %l0
F009FA80: 92026001                 inc     %o1
F009FA84: d22220b0                 st      %o1, [%o0+0xB0]
F009FA88: d0040000                 ld      [%l0], %o0
F009FA8C: 80a22000                 cmp     %o0, 0
F009FA90: 12bffffe                 bne     loc_F009FA88
F009FA94: 01000000                 nop
F009FA98: 7fffdd04                 call    _simple_lock_try
F009FA9C: 90100010                 mov     %l0, %o0
F009FAA0: 80a22000                 cmp     %o0, 0
F009FAA4: 02bffff9                 be      loc_F009FA88
F009FAA8: 113c04f8                 sethi   %hi(dword_F013E020), %o0
F009FAAC: e6022020                 ld      [%o0+%lo(dword_F013E020)], %l3
F009FAB0: 90122020                 bset    %lo(dword_F013E020), %o0
F009FAB4: 80a6a000                 cmp     %i2, 0
F009FAB8: 02800025                 be      loc_F009FB4C
F009FABC: e2022004                 ld      [%o0+4], %l1
F009FAC0: 253c0447                 sethi   -0xFEEE400, %l2
F009FAC4: 2b3c04d0                 sethi   -0xFECC000, %l5
F009FAC8: 110003ffa81223ff         set     0xFFFFF, %l4
F009FAD0: e004a13c                 ld      [%l2+0x13C], %l0
F009FAD4: 90100018                 mov     %i0, %o0
F009FAD8: 7ffd9b72                 call    _urem
F009FADC: 92100010                 mov     %l0, %o1
F009FAE0: a0240008                 sub     %l0, %o0, %l0
F009FAE4: 80a68010                 cmp     %i2, %l0
F009FAE8: 2a800002                 bcs,a   loc_F009FAF0
F009FAEC: a010001a                 mov     %i2, %l0
F009FAF0: e627bff4                 st      %l3, [%fp+var_C]
F009FAF4: c023a05c                 clr     [%sp+0x78+var_1C]
F009FAF8: 9007bff4                 add     %fp, var_C, %o0
F009FAFC: 92100011                 mov     %l1, %o1
F009FB00: 96102007                 mov     7, %o3
F009FB04: 98102001                 mov     1, %o4
F009FB08: d40560d8                 ld      [%l5+0xD8], %o2
F009FB0C: 9a102000                 mov     0, %o5
F009FB10: 942e000a                 andn    %i0, %o2, %o2
F009FB14: 9532a00c                 srl     %o2, 12, %o2
F009FB18: 40000740                 call    _set_pte
F009FB1C: 940a8014                 and     %o2, %l4, %o2! size_t
F009FB20: 90100018                 mov     %i0, %o0
F009FB24: d204a13c                 ld      [%l2+0x13C], %o1
F009FB28: 7ffd9b5e                 call    _urem
F009FB2C: b0060010                 add     %i0, %l0, %i0
F009FB30: 90044008                 add     %l1, %o0, %o0! void *
F009FB34: 92100019                 mov     %i1, %o1! void *
F009FB38: 7fffd3f6                 call    _bcopy
F009FB3C: 94100010                 mov     %l0, %o2
F009FB40: b4a68010                 subcc   %i2, %l0, %i2
F009FB44: 12bfffe3                 bne     loc_F009FAD0
F009FB48: b2064010                 add     %i1, %l0, %i1
F009FB4C: 113c04f8                 sethi   %hi(dword_F013E028), %o0
F009FB50: c0222028                 clr     [%o0+%lo(dword_F013E028)]
F009FB54: 7fffdc74                 call    _splx
F009FB58: 90100016                 mov     %l6, %o0
F009FB5C: 81c7e008                 ret
F009FB60: 81e80000                 restore
