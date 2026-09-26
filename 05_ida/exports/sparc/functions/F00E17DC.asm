F00E17DC: 9de3bf98                 save    %sp, -0x68, %sp
F00E17E0: b406bfff                 inc     -1, %i2
F00E17E4: 80a6bfff                 cmp     %i2, -1
F00E17E8: 0280000c                 be      locret_F00E1818
F00E17EC: 01000000                 nop
F00E17F0: b406bfff                 inc     -1, %i2
F00E17F4: c60e0000                 ldub    [%i0], %g3
F00E17F8: 80a6bfff                 cmp     %i2, -1
F00E17FC: 8418ff80                 xor     %g3, -0x80, %g2
F00E1800: 8608e07f                 and     %g3, 0x7F, %g3
F00E1804: 84108003                 bset    %g3, %g2
F00E1808: c42e4000                 stb     %g2, [%i1]
F00E180C: b2066001                 inc     %i1
F00E1810: 12bffff8                 bne     loc_F00E17F0
F00E1814: b0062001                 inc     %i0
F00E1818: 81c7e008                 ret
F00E181C: 81e80000                 restore
