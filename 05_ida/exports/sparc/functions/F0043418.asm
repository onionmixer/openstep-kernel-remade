F0043418: 9de3bf98                 save    %sp, -0x68, %sp
F004341C: d2060000                 ld      [%i0], %o1
F0043420: d0062014                 ld      [%i0+0x14], %o0
F0043424: 92126001                 bset    1, %o1
F0043428: d2260000                 st      %o1, [%i0]
F004342C: 7fff73d6                 call    _sbwakeup
F0043430: 90022024                 inc     0x24, %o0 ! '$'
F0043434: 81c7e008                 ret
F0043438: 81e80000                 restore
