F00E1F88: 9de3bf98                 save    %sp, -0x68, %sp
F00E1F8C: b406bfff                 inc     -1, %i2
F00E1F90: 80a6bfff                 cmp     %i2, -1
F00E1F94: 0280000b                 be      locret_F00E1FC0
F00E1F98: 01000000                 nop
F00E1F9C: d00e0000                 ldub    [%i0], %o0
F00E1FA0: b406bfff                 inc     -1, %i2
F00E1FA4: b0062001                 inc     %i0
F00E1FA8: 912a2018                 sll     %o0, 24, %o0
F00E1FAC: 40000215                 call    _audio_shortToMulaw
F00E1FB0: 913a2010                 sra     %o0, 16, %o0
F00E1FB4: 80a6bfff                 cmp     %i2, -1
F00E1FB8: 12bffff9                 bne     loc_F00E1F9C
F00E1FBC: d02e4000                 stb     %o0, [%i1]
F00E1FC0: 81c7e008                 ret
F00E1FC4: 81e80000                 restore
