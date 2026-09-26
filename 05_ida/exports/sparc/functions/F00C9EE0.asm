F00C9EE0: 9de3bf90                 save    %sp, -0x70, %sp
F00C9EE4: 10800011                 ba      loc_F00C9F28
F00C9EE8: e2062004                 ld      [%i0+4], %l1
F00C9EEC: d0040000                 ld      [%l0], %o0
F00C9EF0: 80a22000                 cmp     %o0, 0
F00C9EF4: 12bffffe                 bne     loc_F00C9EEC
F00C9EF8: 01000000                 nop
F00C9EFC: 7fff33eb                 call    _simple_lock_try
F00C9F00: 90100010                 mov     %l0, %o0
F00C9F04: 80a22000                 cmp     %o0, 0
F00C9F08: 02bffff9                 be      loc_F00C9EEC
F00C9F0C: 01000000                 nop
F00C9F10: 7ffe7c49                 call    _lock_done
F00C9F14: d0046004                 ld      [%l1+4], %o0
F00C9F18: 90046008                 add     %l1, 8, %o0
F00C9F1C: d2044000                 ld      [%l1], %o1
F00C9F20: 7ffe9ca7                 call    _thread_sleep
F00C9F24: 94102000                 mov     0, %o2
F00C9F28: 7ffe7ba7                 call    _lock_write
F00C9F2C: d0046004                 ld      [%l1+4], %o0
F00C9F30: d0046008                 ld      [%l1+8], %o0
F00C9F34: 80a68008                 cmp     %i2, %o0
F00C9F38: 32bfffed                 bne,a   loc_F00C9EEC
F00C9F3C: e0044000                 ld      [%l1], %l0
F00C9F40: 81c7e008                 ret
F00C9F44: 81e80000                 restore
