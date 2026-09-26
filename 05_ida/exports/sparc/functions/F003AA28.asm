F003AA28: 9de3bf98                 save    %sp, -0x68, %sp
F003AA2C: d0062008                 ld      [%i0+8], %o0
F003AA30: 80a22000                 cmp     %o0, 0
F003AA34: 02800004                 be      locret_F003AA44
F003AA38: 01000000                 nop
F003AA3C: 4000b5d9                 call    _kfree
F003AA40: 92102400                 mov     0x400, %o1
F003AA44: 81c7e008                 ret
F003AA48: 81e80000                 restore
