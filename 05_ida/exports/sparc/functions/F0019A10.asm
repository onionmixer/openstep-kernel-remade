F0019A10: 9de3bf98                 save    %sp, -0x68, %sp
F0019A14: 133c042d                 sethi   %hi(_tthiwat), %o1
F0019A18: d00e204a                 ldub    [%i0+0x4A], %o0
F0019A1C: 92126320                 bset    %lo(_tthiwat), %o1
F0019A20: 900a201f                 and     %o0, 0x1F, %o0
F0019A24: 912a2001                 sll     %o0, 1, %o0
F0019A28: 4001f464                 call    _spltty
F0019A2C: e0520009                 ldsh    [%o0+%o1], %l0
F0019A30: 920420c8                 add     %l0, 0xC8, %o1
F0019A34: d4062018                 ld      [%i0+0x18], %o2
F0019A38: 80a28009                 cmp     %o2, %o1
F0019A3C: 04800017                 ble     loc_F0019A98
F0019A40: a2100008                 mov     %o0, %l1
F0019A44: 80a28010                 cmp     %o2, %l0
F0019A48: 04800014                 ble     loc_F0019A98
F0019A4C: 01000000                 nop
F0019A50: 7ffff44a                 call    _ttstart
F0019A54: 90100018                 mov     %i0, %o0
F0019A58: 80a66000                 cmp     %i1, 0
F0019A5C: 32800006                 bne,a   loc_F0019A74
F0019A60: d2062040                 ld      [%i0+0x40], %o1
F0019A64: 4001f4b0                 call    _splx
F0019A68: 90100011                 mov     %l1, %o0
F0019A6C: 1080000e                 ba      locret_F0019AA4
F0019A70: b0102000                 mov     0, %i0
F0019A74: 90062018                 add     %i0, 0x18, %o0! unsigned int
F0019A78: 92126040                 bset    0x40, %o1 ! '@'
F0019A7C: d2262040                 st      %o1, [%i0+0x40]
F0019A80: 7fffe2fe                 call    _sleep
F0019A84: 9210201d                 mov     0x1D, %o1
F0019A88: d0062018                 ld      [%i0+0x18], %o0
F0019A8C: 80a20010                 cmp     %o0, %l0
F0019A90: 14bffff0                 bg      loc_F0019A50
F0019A94: 01000000                 nop
F0019A98: 4001f4a3                 call    _splx
F0019A9C: 90100011                 mov     %l1, %o0
F0019AA0: b0102001                 mov     1, %i0
F0019AA4: 81c7e008                 ret
F0019AA8: 81e80000                 restore
