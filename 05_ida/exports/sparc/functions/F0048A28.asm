F0048A28: 9de3bf98                 save    %sp, -0x68, %sp
F0048A2C: 808e6001                 btst    1, %i1
F0048A30: 02800017                 be      loc_F0048A8C
F0048A34: 808e6002                 btst    2, %i1
F0048A38: d00620c4                 ld      [%i0+0xC4], %o0
F0048A3C: d2062060                 ld      [%i0+0x60], %o1
F0048A40: d40620cc                 ld      [%i0+0xCC], %o2
F0048A44: 912a0009                 sll     %o0, %o1, %o0
F0048A48: d2062088                 ld      [%i0+0x88], %o1
F0048A4C: 9002000a                 add     %o0, %o2, %o0
F0048A50: 80a20009                 cmp     %o0, %o1
F0048A54: 1480001f                 bg      locret_F0048AD0
F0048A58: 900620cc                 add     %i0, 0xCC, %o0! unsigned int
F0048A5C: 7fff2707                 call    _sleep
F0048A60: 9210201a                 mov     0x1A, %o1
F0048A64: d00620c4                 ld      [%i0+0xC4], %o0
F0048A68: d2062060                 ld      [%i0+0x60], %o1
F0048A6C: d40620cc                 ld      [%i0+0xCC], %o2
F0048A70: 912a0009                 sll     %o0, %o1, %o0
F0048A74: d2062088                 ld      [%i0+0x88], %o1
F0048A78: 9002000a                 add     %o0, %o2, %o0
F0048A7C: 80a20009                 cmp     %o0, %o1
F0048A80: 04bffff7                 ble     loc_F0048A5C
F0048A84: 900620cc                 add     %i0, 0xCC, %o0
F0048A88: 30800012                 ba,a    locret_F0048AD0
F0048A8C: 0280000f                 be      loc_F0048AC8
F0048A90: 113c0439                 sethi   -0xFEF1C00, %o0
F0048A94: d20620c8                 ld      [%i0+0xC8], %o1
F0048A98: d0062090                 ld      [%i0+0x90], %o0
F0048A9C: 80a24008                 cmp     %o1, %o0
F0048AA0: 1480000c                 bg      locret_F0048AD0
F0048AA4: 900620c8                 add     %i0, 0xC8, %o0! unsigned int
F0048AA8: 7fff26f4                 call    _sleep
F0048AAC: 9210201a                 mov     0x1A, %o1
F0048AB0: d20620c8                 ld      [%i0+0xC8], %o1
F0048AB4: d0062090                 ld      [%i0+0x90], %o0
F0048AB8: 80a24008                 cmp     %o1, %o0
F0048ABC: 04bffffb                 ble     loc_F0048AA8
F0048AC0: 900620c8                 add     %i0, 0xC8, %o0! char *
F0048AC4: 30800003                 ba,a    locret_F0048AD0
F0048AC8: 7fff31aa                 call    _panic
F0048ACC: 90122198                 bset    0x198, %o0
F0048AD0: 81c7e008                 ret
F0048AD4: 81e80000                 restore
