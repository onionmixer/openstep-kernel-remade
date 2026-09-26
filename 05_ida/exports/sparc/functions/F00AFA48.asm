F00AFA48: 9de3bf70                 save    %sp, -0x90, %sp
F00AFA4C: 80a6600a                 cmp     %i1, 0xA
F00AFA50: 12800009                 bne     loc_F00AFA74
F00AFA54: a007bfd0                 add     %fp, var_30, %l0
F00AFA58: 80a62000                 cmp     %i0, 0
F00AFA5C: 16800007                 bge     loc_F00AFA78
F00AFA60: 113c0470                 sethi   -0xFEE4000, %o0
F00AFA64: 40000026                 call    _prom_putchar
F00AFA68: 9010202d                 mov     0x2D, %o0 ! '-'
F00AFA6C: b0200018                 neg     %i0
F00AFA70: a007bfd0                 add     %fp, var_30, %l0
F00AFA74: 113c0470                 sethi   -0xFEE4000, %o0
F00AFA78: a2122308                 or      %o0, 0x308, %l1
F00AFA7C: 90100018                 mov     %i0, %o0
F00AFA80: 7ffd5b88                 call    _urem
F00AFA84: 92100019                 mov     %i1, %o1
F00AFA88: 94100008                 mov     %o0, %o2
F00AFA8C: 90100018                 mov     %i0, %o0
F00AFA90: 92100019                 mov     %i1, %o1
F00AFA94: d40a8011                 ldub    [%o2+%l1], %o2
F00AFA98: b406bfff                 inc     -1, %i2
F00AFA9C: d42c0000                 stb     %o2, [%l0]
F00AFAA0: 7ffd5ad8                 call    _udiv
F00AFAA4: a0042001                 inc     %l0
F00AFAA8: b0920000                 orcc    %o0, %g0, %i0
F00AFAAC: 12bffff5                 bne     loc_F00AFA80
F00AFAB0: 90100018                 mov     %i0, %o0
F00AFAB4: 90968000                 orcc    %i2, %g0, %o0
F00AFAB8: 04800008                 ble     loc_F00AFAD8
F00AFABC: b406bfff                 inc     -1, %i2
F00AFAC0: 92102030                 mov     0x30, %o1 ! '0'
F00AFAC4: d22c0000                 stb     %o1, [%l0]
F00AFAC8: a0042001                 inc     %l0
F00AFACC: 90968000                 orcc    %i2, %g0, %o0
F00AFAD0: 14bffffd                 bg      loc_F00AFAC4
F00AFAD4: b406bfff                 inc     -1, %i2
F00AFAD8: b007bfd0                 add     %fp, var_30, %i0
F00AFADC: a0043fff                 inc     -1, %l0
F00AFAE0: 40000007                 call    _prom_putchar
F00AFAE4: d04c0000                 ldsb    [%l0], %o0
F00AFAE8: 80a40018                 cmp     %l0, %i0
F00AFAEC: 18bffffd                 bgu     loc_F00AFAE0
F00AFAF0: a0043fff                 inc     -1, %l0
F00AFAF4: 81c7e008                 ret
F00AFAF8: 81e80000                 restore
