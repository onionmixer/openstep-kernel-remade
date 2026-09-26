F005DE08: 9de3bf98                 save    %sp, -0x68, %sp
F005DE0C: d0060000                 ld      [%i0], %o0
F005DE10: 80a22000                 cmp     %o0, 0
F005DE14: 12bffffe                 bne     loc_F005DE0C
F005DE18: 01000000                 nop
F005DE1C: 4000e423                 call    _simple_lock_try
F005DE20: 90100018                 mov     %i0, %o0
F005DE24: 80a22000                 cmp     %o0, 0
F005DE28: 02bffff9                 be      loc_F005DE0C
F005DE2C: 01000000                 nop
F005DE30: d0062004                 ld      [%i0+4], %o0
F005DE34: c0260000                 clr     [%i0]
F005DE38: 90022001                 inc     %o0
F005DE3C: d0262004                 st      %o0, [%i0+4]
F005DE40: 81c7e008                 ret
F005DE44: 81e80000                 restore
