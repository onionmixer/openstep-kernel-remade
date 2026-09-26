F00E1C78: 9de3bf98                 save    %sp, -0x68, %sp
F00E1C7C: 9210001b                 mov     %i3, %o1
F00E1C80: 80a26001                 cmp     %o1, 1
F00E1C84: 0280001a                 be      loc_F00E1CEC
F00E1C88: b536a001                 srl     %i2, 1, %i2
F00E1C8C: 80a26001                 cmp     %o1, 1
F00E1C90: 14800007                 bg      loc_F00E1CAC
F00E1C94: 80a26003                 cmp     %o1, 3
F00E1C98: 80a26000                 cmp     %o1, 0
F00E1C9C: 02800008                 be      loc_F00E1CBC
F00E1CA0: b536a001                 srl     %i2, 1, %i2
F00E1CA4: 1080001e                 ba      loc_F00E1D1C
F00E1CA8: 113c03f2                 sethi   -0xFF03800, %o0
F00E1CAC: 02800011                 be      loc_F00E1CF0
F00E1CB0: b406bfff                 inc     -1, %i2
F00E1CB4: 1080001a                 ba      loc_F00E1D1C
F00E1CB8: 113c03f2                 sethi   -0xFF03800, %o0
F00E1CBC: b406bfff                 inc     -1, %i2
F00E1CC0: 80a6bfff                 cmp     %i2, -1
F00E1CC4: 02800018                 be      locret_F00E1D24
F00E1CC8: 01000000                 nop
F00E1CCC: b406bfff                 inc     -1, %i2
F00E1CD0: d0160000                 lduh    [%i0], %o0
F00E1CD4: 80a6bfff                 cmp     %i2, -1
F00E1CD8: d0364000                 sth     %o0, [%i1]
F00E1CDC: b2066002                 inc     2, %i1
F00E1CE0: 12bffffb                 bne     loc_F00E1CCC
F00E1CE4: b0062004                 inc     4, %i0
F00E1CE8: 3080000f                 ba,a    locret_F00E1D24
F00E1CEC: b406bfff                 inc     -1, %i2
F00E1CF0: 80a6bfff                 cmp     %i2, -1
F00E1CF4: 0280000c                 be      locret_F00E1D24
F00E1CF8: 01000000                 nop
F00E1CFC: b406bfff                 inc     -1, %i2
F00E1D00: d00e0000                 ldub    [%i0], %o0
F00E1D04: 80a6bfff                 cmp     %i2, -1
F00E1D08: d02e4000                 stb     %o0, [%i1]
F00E1D0C: b2066001                 inc     %i1
F00E1D10: 12bffffb                 bne     loc_F00E1CFC
F00E1D14: b0062002                 inc     2, %i0
F00E1D18: 30800003                 ba,a    locret_F00E1D24
F00E1D1C: 7fff90f6                 call    _IOLog
F00E1D20: 90122208                 bset    0x208, %o0
F00E1D24: 81c7e008                 ret
F00E1D28: 81e80000                 restore
