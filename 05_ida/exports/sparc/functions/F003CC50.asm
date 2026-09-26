F003CC50: 9de3bf98                 save    %sp, -0x68, %sp
F003CC54: c4062030                 ld      [%i0+0x30], %g2
F003CC58: c410a084                 lduh    [%g2+0x84], %g2
F003CC5C: 8088a400                 btst    0x400, %g2
F003CC60: 02800003                 be      locret_F003CC6C
F003CC64: b00e7bff                 and     %i1, -0x401, %i0
F003CC68: b0162400                 bset    0x400, %i0
F003CC6C: 81c7e008                 ret
F003CC70: 81e80000                 restore
