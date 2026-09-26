F002FE88: 9de3bf98                 save    %sp, -0x68, %sp
F002FE8C: d0060000                 ld      [%i0], %o0
F002FE90: c0260000                 clr     [%i0]
F002FE94: 7fffc13c                 call    _sbwakeup
F002FE98: 90022024                 inc     0x24, %o0 ! '$'
F002FE9C: 81c7e008                 ret
F002FEA0: 81e80000                 restore
