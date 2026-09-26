F0065820: 9de3bf98                 save    %sp, -0x68, %sp
F0065824: d0060000                 ld      [%i0], %o0
F0065828: 80a22000                 cmp     %o0, 0
F006582C: 12bffffe                 bne     loc_F0065824
F0065830: 01000000                 nop
F0065834: 4000c59d                 call    _simple_lock_try
F0065838: 90100018                 mov     %i0, %o0
F006583C: 80a22000                 cmp     %o0, 0
F0065840: 02bffff9                 be      loc_F0065824
F0065844: 01000000                 nop
F0065848: f2262014                 st      %i1, [%i0+0x14]
F006584C: c0260000                 clr     [%i0]
F0065850: d0062008                 ld      [%i0+8], %o0
F0065854: 133fffc0                 sethi   -0x10000, %o1
F0065858: 900a0009                 and     %o0, %o1, %o0
F006585C: 9012001a                 bset    %i2, %o0
F0065860: d0262008                 st      %o0, [%i0+8]
F0065864: 81c7e008                 ret
F0065868: 81e80000                 restore
