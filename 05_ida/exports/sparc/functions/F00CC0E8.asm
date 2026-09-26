F00CC0E8: 9de3bf90                 save    %sp, -0x70, %sp
F00CC0EC: e0062144                 ld      [%i0+0x144], %l0
F00CC0F0: b0062144                 inc     0x144, %i0
F00CC0F4: 80a60010                 cmp     %i0, %l0
F00CC0F8: 2280000f                 be,a    locret_F00CC134
F00CC0FC: b0102000                 mov     0, %i0
F00CC100: 90100010                 mov     %l0, %o0! __s1
F00CC104: 9210001a                 mov     %i2, %o1! __s2
F00CC108: 7ffce80c                 call    _memcmp
F00CC10C: 94102006                 mov     6, %o2
F00CC110: 80a22000                 cmp     %o0, 0
F00CC114: 32800004                 bne,a   loc_F00CC124
F00CC118: e0042008                 ld      [%l0+8], %l0
F00CC11C: 10800006                 ba      locret_F00CC134
F00CC120: b0100010                 mov     %l0, %i0
F00CC124: 80a60010                 cmp     %i0, %l0
F00CC128: 12bffff7                 bne     loc_F00CC104
F00CC12C: 90100010                 mov     %l0, %o0
F00CC130: b0102000                 mov     0, %i0
F00CC134: 81c7e008                 ret
F00CC138: 81e80000                 restore
