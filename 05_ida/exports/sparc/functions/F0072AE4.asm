F0072AE4: 9de3bf98                 save    %sp, -0x68, %sp
F0072AE8: 40009028                 call    _splusclock
F0072AEC: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0072AF0: a2100008                 mov     %o0, %l1
F0072AF4: d0040000                 ld      [%l0], %o0
F0072AF8: 80a22000                 cmp     %o0, 0
F0072AFC: 12bffffe                 bne     loc_F0072AF4
F0072B00: 01000000                 nop
F0072B04: 400090e9                 call    _simple_lock_try
F0072B08: 90100010                 mov     %l0, %o0
F0072B0C: 80a22000                 cmp     %o0, 0
F0072B10: 02bffff9                 be      loc_F0072AF4
F0072B14: 01000000                 nop
F0072B18: d0062064                 ld      [%i0+0x64], %o0
F0072B1C: 80a22000                 cmp     %o0, 0
F0072B20: 06800008                 bl      loc_F0072B40
F0072B24: 01000000                 nop
F0072B28: d0262050                 st      %o0, [%i0+0x50]
F0072B2C: 90103fff                 mov     -1, %o0
F0072B30: d0262064                 st      %o0, [%i0+0x64]
F0072B34: 90100018                 mov     %i0, %o0
F0072B38: 7ffffb83                 call    _compute_priority
F0072B3C: 92102000                 mov     0, %o1
F0072B40: c0262020                 clr     [%i0+0x20]
F0072B44: 40009078                 call    _splx
F0072B48: 90100011                 mov     %l1, %o0
F0072B4C: 81c7e008                 ret
F0072B50: 81e80000                 restore
