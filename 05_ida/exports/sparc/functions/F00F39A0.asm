F00F39A0: 9de3bf98                 save    %sp, -0x68, %sp
F00F39A4: 80a62000                 cmp     %i0, 0
F00F39A8: 12800004                 bne     loc_F00F39B8
F00F39AC: 92100018                 mov     %i0, %o1
F00F39B0: 10800045                 ba      locret_F00F3AC4
F00F39B4: b0102000                 mov     0, %i0
F00F39B8: 94102000                 mov     0, %o2
F00F39BC: d00a4000                 ldub    [%o1], %o0
F00F39C0: 80a22000                 cmp     %o0, 0
F00F39C4: 02800016                 be      loc_F00F3A1C
F00F39C8: 92026001                 inc     %o1
F00F39CC: 941a8008                 btog    %o0, %o2
F00F39D0: d00a4000                 ldub    [%o1], %o0
F00F39D4: 80a22000                 cmp     %o0, 0
F00F39D8: 02800011                 be      loc_F00F3A1C
F00F39DC: 912a2008                 sll     %o0, 8, %o0
F00F39E0: 941a8008                 btog    %o0, %o2
F00F39E4: 92026001                 inc     %o1
F00F39E8: d00a4000                 ldub    [%o1], %o0
F00F39EC: 80a22000                 cmp     %o0, 0
F00F39F0: 0280000b                 be      loc_F00F3A1C
F00F39F4: 912a2010                 sll     %o0, 16, %o0
F00F39F8: 941a8008                 btog    %o0, %o2
F00F39FC: 92026001                 inc     %o1
F00F3A00: d00a4000                 ldub    [%o1], %o0
F00F3A04: 80a22000                 cmp     %o0, 0
F00F3A08: 02800005                 be      loc_F00F3A1C
F00F3A0C: 912a2018                 sll     %o0, 24, %o0
F00F3A10: 941a8008                 btog    %o0, %o2
F00F3A14: 10bfffea                 ba      loc_F00F39BC
F00F3A18: 92026001                 inc     %o1
F00F3A1C: 113c04bc                 sethi   %hi(off_F012F16C), %o0
F00F3A20: e202216c                 ld      [%o0+%lo(off_F012F16C)], %l1
F00F3A24: 80a46000                 cmp     %l1, 0
F00F3A28: 02800026                 be      loc_F00F3AC0
F00F3A2C: a410000a                 mov     %o2, %l2
F00F3A30: d004600c                 ld      [%l1+0xC], %o0
F00F3A34: 80a60008                 cmp     %i0, %o0
F00F3A38: 0a800006                 bcs     loc_F00F3A50
F00F3A3C: 90100012                 mov     %l2, %o0
F00F3A40: d0046010                 ld      [%l1+0x10], %o0
F00F3A44: 80a60008                 cmp     %i0, %o0
F00F3A48: 0a80001f                 bcs     locret_F00F3AC4
F00F3A4C: 90100012                 mov     %l2, %o0
F00F3A50: 7ffc4b94                 call    _urem
F00F3A54: d2046004                 ld      [%l1+4], %o1
F00F3A58: d2046014                 ld      [%l1+0x14], %o1
F00F3A5C: 912a2002                 sll     %o0, 2, %o0
F00F3A60: e0024008                 ld      [%o1+%o0], %l0
F00F3A64: 80a42000                 cmp     %l0, 0
F00F3A68: 22800013                 be,a    loc_F00F3AB4
F00F3A6C: e2046018                 ld      [%l1+0x18], %l1
F00F3A70: d4042004                 ld      [%l0+4], %o2
F00F3A74: d24e0000                 ldsb    [%i0], %o1! __s2
F00F3A78: d04a8000                 ldsb    [%o2], %o0
F00F3A7C: 80a24008                 cmp     %o1, %o0
F00F3A80: 32800009                 bne,a   loc_F00F3AA4
F00F3A84: e0040000                 ld      [%l0], %l0
F00F3A88: 90100018                 mov     %i0, %o0! __s1
F00F3A8C: 7ffc51c8                 call    _strcmp
F00F3A90: 9210000a                 mov     %o2, %o1
F00F3A94: 80a22000                 cmp     %o0, 0
F00F3A98: 2280000b                 be,a    locret_F00F3AC4
F00F3A9C: f0042004                 ld      [%l0+4], %i0
F00F3AA0: e0040000                 ld      [%l0], %l0
F00F3AA4: 80a42000                 cmp     %l0, 0
F00F3AA8: 32bffff3                 bne,a   loc_F00F3A74
F00F3AAC: d4042004                 ld      [%l0+4], %o2
F00F3AB0: e2046018                 ld      [%l1+0x18], %l1
F00F3AB4: 80a46000                 cmp     %l1, 0
F00F3AB8: 32bfffdf                 bne,a   loc_F00F3A34
F00F3ABC: d004600c                 ld      [%l1+0xC], %o0
F00F3AC0: b0102000                 mov     0, %i0
F00F3AC4: 81c7e008                 ret
F00F3AC8: 81e80000                 restore
