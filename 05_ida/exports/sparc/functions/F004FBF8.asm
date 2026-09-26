F004FBF8: 9de3bf98                 save    %sp, -0x68, %sp
F004FBFC: d0062004                 ld      [%i0+4], %o0
F004FC00: d4066004                 ld      [%i1+4], %o2! size_t
F004FC04: 80a2000a                 cmp     %o0, %o2
F004FC08: 32800007                 bne,a   loc_F004FC24
F004FC0C: d2062008                 ld      [%i0+8], %o1
F004FC10: d0066008                 ld      [%i1+8], %o0
F004FC14: 90022001                 inc     %o0
F004FC18: d0262004                 st      %o0, [%i0+4]
F004FC1C: 10800020                 ba      locret_F004FC9C
F004FC20: f0266014                 st      %i0, [%i1+0x14]
F004FC24: d0066008                 ld      [%i1+8], %o0
F004FC28: 80a24008                 cmp     %o1, %o0
F004FC2C: 12800006                 bne     loc_F004FC44
F004FC30: 9002bfff                 add     %o2, -1, %o0
F004FC34: d2062014                 ld      [%i0+0x14], %o1
F004FC38: d0262008                 st      %o0, [%i0+8]
F004FC3C: 10800017                 ba      loc_F004FC98
F004FC40: d2266014                 st      %o1, [%i1+0x14]
F004FC44: 4000610b                 call    _kalloc
F004FC48: 9010201c                 mov     0x1C, %o0
F004FC4C: a0100008                 mov     %o0, %l0
F004FC50: 90100018                 mov     %i0, %o0! void *
F004FC54: 92100010                 mov     %l0, %o1! void *
F004FC58: 400113ae                 call    _bcopy
F004FC5C: 9410201c                 mov     0x1C, %o2
F004FC60: d2042010                 ld      [%l0+0x10], %o1
F004FC64: d0026008                 ld      [%o1+8], %o0
F004FC68: 90022001                 inc     %o0
F004FC6C: d0226008                 st      %o0, [%o1+8]
F004FC70: d0066008                 ld      [%i1+8], %o0
F004FC74: 90022001                 inc     %o0
F004FC78: d0242004                 st      %o0, [%l0+4]
F004FC7C: c0242018                 clr     [%l0+0x18]
F004FC80: d0066004                 ld      [%i1+4], %o0
F004FC84: d2062014                 ld      [%i0+0x14], %o1
F004FC88: 90023fff                 inc     -1, %o0
F004FC8C: d0262008                 st      %o0, [%i0+8]
F004FC90: d2242014                 st      %o1, [%l0+0x14]
F004FC94: e0266014                 st      %l0, [%i1+0x14]
F004FC98: f2262014                 st      %i1, [%i0+0x14]
F004FC9C: 81c7e008                 ret
F004FCA0: 81e80000                 restore
