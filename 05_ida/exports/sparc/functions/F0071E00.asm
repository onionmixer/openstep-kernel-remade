F0071E00: 9de3bf98                 save    %sp, -0x68, %sp
F0071E04: a2100018                 mov     %i0, %l1
F0071E08: f0046008                 ld      [%l1+8], %i0
F0071E0C: 80a62000                 cmp     %i0, 0
F0071E10: 0280001d                 be      locret_F0071E84
F0071E14: a0062100                 add     %i0, 0x100, %l0
F0071E18: d0040000                 ld      [%l0], %o0
F0071E1C: 80a22000                 cmp     %o0, 0
F0071E20: 12bffffe                 bne     loc_F0071E18
F0071E24: 01000000                 nop
F0071E28: 40009420                 call    _simple_lock_try
F0071E2C: 90100010                 mov     %l0, %o0
F0071E30: 80a22000                 cmp     %o0, 0
F0071E34: 02bffff9                 be      loc_F0071E18
F0071E38: 01000000                 nop
F0071E3C: d0046008                 ld      [%l1+8], %o0
F0071E40: 80a60008                 cmp     %i0, %o0
F0071E44: 1280000e                 bne     loc_F0071E7C
F0071E48: 01000000                 nop
F0071E4C: d2044000                 ld      [%l1], %o1
F0071E50: d0046004                 ld      [%l1+4], %o0
F0071E54: d0226004                 st      %o0, [%o1+4]
F0071E58: d2046004                 ld      [%l1+4], %o1
F0071E5C: d0044000                 ld      [%l1], %o0
F0071E60: d0224000                 st      %o0, [%o1]
F0071E64: d0062108                 ld      [%i0+0x108], %o0
F0071E68: 90023fff                 inc     -1, %o0
F0071E6C: d0262108                 st      %o0, [%i0+0x108]
F0071E70: c0246008                 clr     [%l1+8]
F0071E74: c0262100                 clr     [%i0+0x100]
F0071E78: 30800003                 ba,a    locret_F0071E84
F0071E7C: c0262100                 clr     [%i0+0x100]
F0071E80: b0102000                 mov     0, %i0
F0071E84: 81c7e008                 ret
F0071E88: 81e80000                 restore
