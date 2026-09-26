F00E2004: 9de3bf98                 save    %sp, -0x68, %sp
F00E2008: b406bfff                 inc     -1, %i2
F00E200C: 80a6bfff                 cmp     %i2, -1
F00E2010: 02800009                 be      locret_F00E2034
F00E2014: 01000000                 nop
F00E2018: d0560000                 ldsh    [%i0], %o0
F00E201C: b406bfff                 inc     -1, %i2
F00E2020: 400001f8                 call    _audio_shortToMulaw
F00E2024: b0062002                 inc     2, %i0
F00E2028: 80a6bfff                 cmp     %i2, -1
F00E202C: 12bffffb                 bne     loc_F00E2018
F00E2030: d02e4000                 stb     %o0, [%i1]
F00E2034: 81c7e008                 ret
F00E2038: 81e80000                 restore
