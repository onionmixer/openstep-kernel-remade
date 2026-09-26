F00679F8: 9de3bf98                 save    %sp, -0x68, %sp
F00679FC: 80a62000                 cmp     %i0, 0
F0067A00: 0280001d                 be      locret_F0067A74
F0067A04: a0102000                 mov     0, %l0
F0067A08: 80a63fff                 cmp     %i0, -1
F0067A0C: 0280001a                 be      locret_F0067A74
F0067A10: 01000000                 nop
F0067A14: d0060000                 ld      [%i0], %o0
F0067A18: 80a22000                 cmp     %o0, 0
F0067A1C: 12bffffe                 bne     loc_F0067A14
F0067A20: 01000000                 nop
F0067A24: 4000bd21                 call    _simple_lock_try
F0067A28: 90100018                 mov     %i0, %o0
F0067A2C: 80a22000                 cmp     %o0, 0
F0067A30: 02bffff9                 be      loc_F0067A14
F0067A34: 01000000                 nop
F0067A38: d2062008                 ld      [%i0+8], %o1
F0067A3C: 80a26000                 cmp     %o1, 0
F0067A40: 1680000c                 bge     loc_F0067A70
F0067A44: 01000000                 nop
F0067A48: 1100003f901223ff         set     0xFFFF, %o0
F0067A50: 900a4008                 and     %o1, %o0, %o0
F0067A54: 80a22002                 cmp     %o0, 2
F0067A58: 12800006                 bne     loc_F0067A70
F0067A5C: 01000000                 nop
F0067A60: d0062014                 ld      [%i0+0x14], %o0
F0067A64: e002200c                 ld      [%o0+0xC], %l0
F0067A68: 400071d6                 call    _vm_map_reference
F0067A6C: 90100010                 mov     %l0, %o0
F0067A70: c0260000                 clr     [%i0]
F0067A74: 81c7e008                 ret
F0067A78: 91e80010                 restore %g0, %l0, %o0
