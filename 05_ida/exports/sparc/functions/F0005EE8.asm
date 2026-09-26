F0005EE8: 9de3bf98                 save    %sp, -0x68, %sp
F0005EEC: c44e0000                 ldsb    [%i0], %g2
F0005EF0: 80a0a000                 cmp     %g2, 0
F0005EF4: 02800006                 be      loc_F0005F0C
F0005EF8: 86062001                 add     %i0, 1, %g3
F0005EFC: c448c000                 ldsb    [%g3], %g2
F0005F00: 80a0a000                 cmp     %g2, 0
F0005F04: 12bffffe                 bne     loc_F0005EFC
F0005F08: 8600e001                 inc     %g3
F0005F0C: c40e4000                 ldub    [%i1], %g2
F0005F10: 10800007                 ba      loc_F0005F2C
F0005F14: 8600ffff                 inc     -1, %g3
F0005F18: b486bfff                 inccc   -1, %i2
F0005F1C: 3c800004                 bpos,a  loc_F0005F2C
F0005F20: c40e4000                 ldub    [%i1], %g2
F0005F24: 10800007                 ba      locret_F0005F40
F0005F28: c028ffff                 clrb    [%g3-1]
F0005F2C: c428c000                 stb     %g2, [%g3]
F0005F30: b2066001                 inc     %i1
F0005F34: 80a0a000                 cmp     %g2, 0
F0005F38: 12bffff8                 bne     loc_F0005F18
F0005F3C: 8600e001                 inc     %g3
F0005F40: 81c7e008                 ret
F0005F44: 81e80000                 restore
