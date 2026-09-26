F00E1D2C: 9de3bf98                 save    %sp, -0x68, %sp
F00E1D30: 9210001b                 mov     %i3, %o1
F00E1D34: 80a26001                 cmp     %o1, 1
F00E1D38: 2280001c                 be,a    loc_F00E1DA8
F00E1D3C: b406bfff                 inc     -1, %i2
F00E1D40: 14800007                 bg      loc_F00E1D5C
F00E1D44: 80a26003                 cmp     %o1, 3
F00E1D48: 80a26000                 cmp     %o1, 0
F00E1D4C: 02800008                 be      loc_F00E1D6C
F00E1D50: b536a001                 srl     %i2, 1, %i2
F00E1D54: 10800023                 ba      loc_F00E1DE0
F00E1D58: 113c03f2                 sethi   -0xFF03800, %o0
F00E1D5C: 02800013                 be      loc_F00E1DA8
F00E1D60: b406bfff                 inc     -1, %i2
F00E1D64: 1080001f                 ba      loc_F00E1DE0
F00E1D68: 113c03f2                 sethi   -0xFF03800, %o0
F00E1D6C: b406bfff                 inc     -1, %i2
F00E1D70: 80a6bfff                 cmp     %i2, -1
F00E1D74: 0280001d                 be      locret_F00E1DE8
F00E1D78: 01000000                 nop
F00E1D7C: b406bfff                 inc     -1, %i2
F00E1D80: d0160000                 lduh    [%i0], %o0
F00E1D84: 80a6bfff                 cmp     %i2, -1
F00E1D88: d0364000                 sth     %o0, [%i1]
F00E1D8C: d0160000                 lduh    [%i0], %o0
F00E1D90: b2066002                 inc     2, %i1
F00E1D94: d0364000                 sth     %o0, [%i1]
F00E1D98: b0062002                 inc     2, %i0
F00E1D9C: 12bffff8                 bne     loc_F00E1D7C
F00E1DA0: b2066002                 inc     2, %i1
F00E1DA4: 30800011                 ba,a    locret_F00E1DE8
F00E1DA8: 80a6bfff                 cmp     %i2, -1
F00E1DAC: 0280000f                 be      locret_F00E1DE8
F00E1DB0: 01000000                 nop
F00E1DB4: b406bfff                 inc     -1, %i2
F00E1DB8: d00e0000                 ldub    [%i0], %o0
F00E1DBC: 80a6bfff                 cmp     %i2, -1
F00E1DC0: d02e4000                 stb     %o0, [%i1]
F00E1DC4: d00e0000                 ldub    [%i0], %o0
F00E1DC8: b2066001                 inc     %i1
F00E1DCC: d02e4000                 stb     %o0, [%i1]
F00E1DD0: b0062001                 inc     %i0
F00E1DD4: 12bffff8                 bne     loc_F00E1DB4
F00E1DD8: b2066001                 inc     %i1
F00E1DDC: 30800003                 ba,a    locret_F00E1DE8
F00E1DE0: 7fff90c5                 call    _IOLog
F00E1DE4: 90122238                 bset    0x238, %o0
F00E1DE8: 81c7e008                 ret
F00E1DEC: 81e80000                 restore
