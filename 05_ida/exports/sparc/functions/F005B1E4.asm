F005B1E4: 9de3bf98                 save    %sp, -0x68, %sp
F005B1E8: d0060000                 ld      [%i0], %o0
F005B1EC: 80a22000                 cmp     %o0, 0
F005B1F0: 12bffffe                 bne     loc_F005B1E8
F005B1F4: 01000000                 nop
F005B1F8: 4000ef2c                 call    _simple_lock_try
F005B1FC: 90100018                 mov     %i0, %o0
F005B200: 80a22000                 cmp     %o0, 0
F005B204: 02bffff9                 be      loc_F005B1E8
F005B208: 01000000                 nop
F005B20C: d0062020                 ld      [%i0+0x20], %o0
F005B210: 90022001                 inc     %o0
F005B214: d0262020                 st      %o0, [%i0+0x20]
F005B218: d0062004                 ld      [%i0+4], %o0
F005B21C: 90022001                 inc     %o0
F005B220: d0262004                 st      %o0, [%i0+4]
F005B224: c0260000                 clr     [%i0]
F005B228: 81c7e008                 ret
F005B22C: 81e80000                 restore
