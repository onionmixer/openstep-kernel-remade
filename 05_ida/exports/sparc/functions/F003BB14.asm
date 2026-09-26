F003BB14: 9de3bf98                 save    %sp, -0x68, %sp
F003BB18: d4062014                 ld      [%i0+0x14], %o2
F003BB1C: 80a2a000                 cmp     %o2, 0
F003BB20: 02800007                 be      locret_F003BB3C
F003BB24: 01000000                 nop
F003BB28: d0060000                 ld      [%i0], %o0
F003BB2C: d2063ffc                 ld      [%i0-4], %o1
F003BB30: 90028008                 add     %o2, %o0, %o0
F003BB34: 4000b19b                 call    _kfree
F003BB38: 90220009                 sub     %o0, %o1, %o0
F003BB3C: 81c7e008                 ret
F003BB40: 81e80000                 restore
