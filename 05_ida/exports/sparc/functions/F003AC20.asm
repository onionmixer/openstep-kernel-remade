F003AC20: 9de3bf98                 save    %sp, -0x68, %sp
F003AC24: d0062050                 ld      [%i0+0x50], %o0
F003AC28: 80a22000                 cmp     %o0, 0
F003AC2C: 12800008                 bne     locret_F003AC4C
F003AC30: 01000000                 nop
F003AC34: d006204c                 ld      [%i0+0x4C], %o0
F003AC38: 80a22000                 cmp     %o0, 0
F003AC3C: 02800004                 be      locret_F003AC4C
F003AC40: 01000000                 nop
F003AC44: 4000b557                 call    _kfree
F003AC48: d2063ffc                 ld      [%i0-4], %o1
F003AC4C: 81c7e008                 ret
F003AC50: 81e80000                 restore
