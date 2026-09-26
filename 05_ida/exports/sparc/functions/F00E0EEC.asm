F00E0EEC: 9de3bf98                 save    %sp, -0x68, %sp
F00E0EF0: b4102000                 mov     0, %i2
F00E0EF4: 86066003                 add     %i1, 3, %g3
F00E0EF8: c40e0000                 ldub    [%i0], %g2
F00E0EFC: c42e4000                 stb     %g2, [%i1]
F00E0F00: c40e2001                 ldub    [%i0+1], %g2
F00E0F04: b406a001                 inc     %i2
F00E0F08: c428fffe                 stb     %g2, [%g3-2]
F00E0F0C: c40e2002                 ldub    [%i0+2], %g2
F00E0F10: 80a6a685                 cmp     %i2, 0x685
F00E0F14: c428ffff                 stb     %g2, [%g3-1]
F00E0F18: c40e2003                 ldub    [%i0+3], %g2
F00E0F1C: b2066004                 inc     4, %i1
F00E0F20: c428c000                 stb     %g2, [%g3]
F00E0F24: 8600e004                 inc     4, %g3
F00E0F28: 04bffff4                 ble     loc_F00E0EF8
F00E0F2C: b0062004                 inc     4, %i0
F00E0F30: 81c7e008                 ret
F00E0F34: 81e80000                 restore
