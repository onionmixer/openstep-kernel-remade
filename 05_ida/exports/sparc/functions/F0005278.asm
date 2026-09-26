F0005278: 9de3bf98                 save    %sp, -0x68, %sp
F000527C: c44e0000                 ldsb    [%i0], %g2
F0005280: 80a0a000                 cmp     %g2, 0
F0005284: 02800006                 be      loc_F000529C
F0005288: 86062001                 add     %i0, 1, %g3
F000528C: c448c000                 ldsb    [%g3], %g2
F0005290: 80a0a000                 cmp     %g2, 0
F0005294: 12bffffe                 bne     loc_F000528C
F0005298: 8600e001                 inc     %g3
F000529C: c40e4000                 ldub    [%i1], %g2
F00052A0: 10800003                 ba      loc_F00052AC
F00052A4: 8600ffff                 inc     -1, %g3
F00052A8: c40e4000                 ldub    [%i1], %g2
F00052AC: c428c000                 stb     %g2, [%g3]
F00052B0: b2066001                 inc     %i1
F00052B4: 80a0a000                 cmp     %g2, 0
F00052B8: 12bffffc                 bne     loc_F00052A8
F00052BC: 8600e001                 inc     %g3
F00052C0: 81c7e008                 ret
F00052C4: 81e80000                 restore
