F0027438: 9de3bf98                 save    %sp, -0x68, %sp
F002743C: f4062008                 ld      [%i0+8], %i2
F0027440: b61020ff                 mov     0xFF, %i3
F0027444: 80a6a000                 cmp     %i2, 0
F0027448: 04800010                 ble     loc_F0027488
F002744C: c6062004                 ld      [%i0+4], %g3
F0027450: c448c000                 ldsb    [%g3], %g2
F0027454: 80a0a02f                 cmp     %g2, 0x2F ! '/'
F0027458: 2280000d                 be,a    loc_F002748C
F002745C: c6262004                 st      %g3, [%i0+4]
F0027460: b686ffff                 inccc   -1, %i3
F0027464: 1c800004                 bpos    loc_F0027474
F0027468: 8600e001                 inc     %g3
F002746C: 1080000b                 ba      locret_F0027498
F0027470: b010203f                 mov     0x3F, %i0 ! '?'
F0027474: c42e4000                 stb     %g2, [%i1]
F0027478: b406bfff                 inc     -1, %i2
F002747C: 80a6a000                 cmp     %i2, 0
F0027480: 14bffff4                 bg      loc_F0027450
F0027484: b2066001                 inc     %i1
F0027488: c6262004                 st      %g3, [%i0+4]
F002748C: f4262008                 st      %i2, [%i0+8]
F0027490: c02e4000                 clrb    [%i1]
F0027494: b0102000                 mov     0, %i0
F0027498: 81c7e008                 ret
F002749C: 81e80000                 restore
