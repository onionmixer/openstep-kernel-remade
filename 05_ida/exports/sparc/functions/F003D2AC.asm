F003D2AC: 9de3bf98                 save    %sp, -0x68, %sp
F003D2B0: d0062030                 ld      [%i0+0x30], %o0
F003D2B4: d4022128                 ld      [%o0+0x128], %o2
F003D2B8: d202a018                 ld      [%o2+0x18], %o1
F003D2BC: 90100018                 mov     %i0, %o0
F003D2C0: 92027fff                 inc     -1, %o1
F003D2C4: 7ffffff0                 call    _rinactive
F003D2C8: d222a018                 st      %o1, [%o2+0x18]
F003D2CC: 90100018                 mov     %i0, %o0
F003D2D0: 7fffffb7                 call    sub_F003D1AC
F003D2D4: 92102001                 mov     1, %o1
F003D2D8: 81c7e008                 ret
F003D2DC: 81e80000                 restore
