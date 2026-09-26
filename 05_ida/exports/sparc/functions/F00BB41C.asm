F00BB41C: 9de3bf98                 save    %sp, -0x68, %sp
F00BB420: 90102002                 mov     2, %o0
F00BB424: e0062010                 ld      [%i0+0x10], %l0
F00BB428: 92102028                 mov     0x28, %o1 ! '('
F00BB42C: d22c0000                 stb     %o1, [%l0]
F00BB430: 7fff710c                 call    _us_spin
F00BB434: 01000000                 nop
F00BB438: 90102010                 mov     0x10, %o0
F00BB43C: d02c0000                 stb     %o0, [%l0]
F00BB440: 7fff7108                 call    _us_spin
F00BB444: 90102002                 mov     2, %o0
F00BB448: d00c2002                 ldub    [%l0+2], %o0
F00BB44C: 7fff7105                 call    _us_spin
F00BB450: 90102002                 mov     2, %o0
F00BB454: 90102030                 mov     0x30, %o0 ! '0'
F00BB458: d02c0000                 stb     %o0, [%l0]
F00BB45C: 81c7e008                 ret
F00BB460: 81e80000                 restore
