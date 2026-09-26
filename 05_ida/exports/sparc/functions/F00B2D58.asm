F00B2D58: 9de3bf98                 save    %sp, -0x68, %sp
F00B2D5C: 10800011                 ba      loc_F00B2DA0
F00B2D60: c44e0000                 ldsb    [%i0], %g2
F00B2D64: 8528e018                 sll     %g3, 24, %g2
F00B2D68: 8538a018                 sra     %g2, 24, %g2
F00B2D6C: 80a0a03a                 cmp     %g2, 0x3A ! ':'
F00B2D70: 22800010                 be,a    locret_F00B2DB0
F00B2D74: c02e4000                 clrb    [%i1]
F00B2D78: 14800003                 bg      loc_F00B2D84
F00B2D7C: 80a0a040                 cmp     %g2, 0x40 ! '@'
F00B2D80: 80a0a02f                 cmp     %g2, 0x2F ! '/'
F00B2D84: 2280000b                 be,a    locret_F00B2DB0
F00B2D88: c02e4000                 clrb    [%i1]
F00B2D8C: c40e0000                 ldub    [%i0], %g2
F00B2D90: c42e4000                 stb     %g2, [%i1]
F00B2D94: b0062001                 inc     %i0
F00B2D98: c44e0000                 ldsb    [%i0], %g2
F00B2D9C: b2066001                 inc     %i1
F00B2DA0: 80a0a000                 cmp     %g2, 0
F00B2DA4: 12bffff0                 bne     loc_F00B2D64
F00B2DA8: c60e0000                 ldub    [%i0], %g3
F00B2DAC: c02e4000                 clrb    [%i1]
F00B2DB0: 81c7e008                 ret
F00B2DB4: 81e80000                 restore
