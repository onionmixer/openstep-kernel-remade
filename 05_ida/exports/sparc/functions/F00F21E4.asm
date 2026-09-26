F00F21E4: 9de3bf98                 save    %sp, -0x68, %sp
F00F21E8: 113c04bc                 sethi   %hi(dword_F012F14C), %o0
F00F21EC: d002214c                 ld      [%o0+%lo(dword_F012F14C)], %o0
F00F21F0: 80a22000                 cmp     %o0, 0
F00F21F4: 02800010                 be      locret_F00F2234
F00F21F8: 01000000                 nop
F00F21FC: 7ffff2c7                 call    _NXMapRemove
F00F2200: d2062008                 ld      [%i0+8], %o1
F00F2204: b0920000                 orcc    %o0, %g0, %i0
F00F2208: 0280000b                 be      locret_F00F2234
F00F220C: 01000000                 nop
F00F2210: d0062004                 ld      [%i0+4], %o0! void *
F00F2214: 7fffffb6                 call    __objc_add_category
F00F2218: d2062008                 ld      [%i0+8], %o1
F00F221C: e0060000                 ld      [%i0], %l0
F00F2220: 7ffdd838                 call    _free
F00F2224: 90100018                 mov     %i0, %o0
F00F2228: b0940000                 orcc    %l0, %g0, %i0
F00F222C: 32bffffa                 bne,a   loc_F00F2214
F00F2230: d0062004                 ld      [%i0+4], %o0
F00F2234: 81c7e008                 ret
F00F2238: 81e80000                 restore
