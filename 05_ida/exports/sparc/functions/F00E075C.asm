F00E075C: 9de3bf98                 save    %sp, -0x68, %sp
F00E0760: b4102000                 mov     0, %i2
F00E0764: 86062003                 add     %i0, 3, %g3
F00E0768: c40e0000                 ldub    [%i0], %g2
F00E076C: c42e4000                 stb     %g2, [%i1]
F00E0770: c408fffe                 ldub    [%g3-2], %g2
F00E0774: b406a001                 inc     %i2
F00E0778: c42e6001                 stb     %g2, [%i1+1]
F00E077C: c408ffff                 ldub    [%g3-1], %g2
F00E0780: 80a6a685                 cmp     %i2, 0x685
F00E0784: c42e6002                 stb     %g2, [%i1+2]
F00E0788: c408c000                 ldub    [%g3], %g2
F00E078C: b0062004                 inc     4, %i0
F00E0790: c42e6003                 stb     %g2, [%i1+3]
F00E0794: 8600e004                 inc     4, %g3
F00E0798: 04bffff4                 ble     loc_F00E0768
F00E079C: b2066004                 inc     4, %i1
F00E07A0: 81c7e008                 ret
F00E07A4: 81e80000                 restore
