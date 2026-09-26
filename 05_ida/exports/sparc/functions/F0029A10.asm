F0029A10: 9de3bf98                 save    %sp, -0x68, %sp
F0029A14: a2100018                 mov     %i0, %l1
F0029A18: d2144000                 lduh    [%l1], %o1
F0029A1C: 80a26010                 cmp     %o1, 0x10
F0029A20: 18800021                 bgu     loc_F0029AA4
F0029A24: 113c04d0                 sethi   %hi(_ifnet), %o0
F0029A28: e00220b8                 ld      [%o0+%lo(_ifnet)], %l0
F0029A2C: 932a6003                 sll     %o1, 3, %o1
F0029A30: 113c043090122150         set     _afswitch, %o0
F0029A38: 92024008                 add     %o1, %o0, %o1
F0029A3C: 80a42000                 cmp     %l0, 0
F0029A40: 02800019                 be      loc_F0029AA4
F0029A44: e4026004                 ld      [%o1+4], %l2
F0029A48: f0042018                 ld      [%l0+0x18], %i0
F0029A4C: 80a62000                 cmp     %i0, 0
F0029A50: 22800012                 be,a    loc_F0029A98
F0029A54: e004205c                 ld      [%l0+0x5C], %l0
F0029A58: d2160000                 lduh    [%i0], %o1
F0029A5C: d0144000                 lduh    [%l1], %o0
F0029A60: 80a24008                 cmp     %o1, %o0
F0029A64: 32800009                 bne,a   loc_F0029A88
F0029A68: f0062024                 ld      [%i0+0x24], %i0
F0029A6C: 90100018                 mov     %i0, %o0
F0029A70: 9fc48000                 call    %l2
F0029A74: 92100011                 mov     %l1, %o1
F0029A78: 80a22000                 cmp     %o0, 0
F0029A7C: 1280000b                 bne     locret_F0029AA8
F0029A80: 01000000                 nop
F0029A84: f0062024                 ld      [%i0+0x24], %i0
F0029A88: 80a62000                 cmp     %i0, 0
F0029A8C: 32bffff4                 bne,a   loc_F0029A5C
F0029A90: d2160000                 lduh    [%i0], %o1
F0029A94: e004205c                 ld      [%l0+0x5C], %l0
F0029A98: 80a42000                 cmp     %l0, 0
F0029A9C: 32bfffec                 bne,a   loc_F0029A4C
F0029AA0: f0042018                 ld      [%l0+0x18], %i0
F0029AA4: b0102000                 mov     0, %i0
F0029AA8: 81c7e008                 ret
F0029AAC: 81e80000                 restore
