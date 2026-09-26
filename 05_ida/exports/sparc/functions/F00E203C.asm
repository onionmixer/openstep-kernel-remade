F00E203C: 9de3bf98                 save    %sp, -0x68, %sp
F00E2040: b406bfff                 inc     -1, %i2
F00E2044: 80a6bfff                 cmp     %i2, -1
F00E2048: 0280000c                 be      locret_F00E2078
F00E204C: 053c03e5                 sethi   %hi(_audio_muLaw), %g2
F00E2050: 8610a3c4                 or      %g2, %lo(_audio_muLaw), %g3
F00E2054: b406bfff                 inc     -1, %i2
F00E2058: c40e0000                 ldub    [%i0], %g2
F00E205C: 80a6bfff                 cmp     %i2, -1
F00E2060: 8528a001                 sll     %g2, 1, %g2
F00E2064: c4108003                 lduh    [%g2+%g3], %g2
F00E2068: b0062001                 inc     %i0
F00E206C: c42e4000                 stb     %g2, [%i1]
F00E2070: 12bffff9                 bne     loc_F00E2054
F00E2074: b2066001                 inc     %i1
F00E2078: 81c7e008                 ret
F00E207C: 81e80000                 restore
