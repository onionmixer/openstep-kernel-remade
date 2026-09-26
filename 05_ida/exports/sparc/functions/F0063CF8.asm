F0063CF8: 9de3bf98                 save    %sp, -0x68, %sp
F0063CFC: 80a62000                 cmp     %i0, 0
F0063D00: 133c026f                 sethi   %hi(_thread_exception_return), %o1
F0063D04: 113c04d0                 sethi   %hi(_active_threads), %o0
F0063D08: e4022260                 ld      [%o0+%lo(_active_threads)], %l2
F0063D0C: 12800005                 bne     loc_F0063D20
F0063D10: a01263e4                 or      %o1, %lo(_thread_exception_return), %l0
F0063D14: 113c043e                 sethi   %hi(aException), %o0! "exception"
F0063D18: 7ffec516                 call    _panic
F0063D1C: 901220c0                 bset    %lo(aException), %o0! "exception"
F0063D20: e024a038                 st      %l0, [%l2+0x38]
F0063D24: a004a0a8                 add     %l2, 0xA8, %l0
F0063D28: d0040000                 ld      [%l0], %o0
F0063D2C: 80a22000                 cmp     %o0, 0
F0063D30: 12bffffe                 bne     loc_F0063D28
F0063D34: 01000000                 nop
F0063D38: 4000cc5c                 call    _simple_lock_try
F0063D3C: 90100010                 mov     %l0, %o0
F0063D40: 80a22000                 cmp     %o0, 0
F0063D44: 02bffff9                 be      loc_F0063D28
F0063D48: 01000000                 nop
F0063D4C: e204a0b4                 ld      [%l2+0xB4], %l1
F0063D50: 80a46000                 cmp     %l1, 0
F0063D54: 02800004                 be      loc_F0063D64
F0063D58: 80a47fff                 cmp     %l1, -1
F0063D5C: 12800005                 bne     loc_F0063D70
F0063D60: 01000000                 nop
F0063D64: c024a0a8                 clr     [%l2+0xA8]
F0063D68: 10800012                 ba      loc_F0063DB0
F0063D6C: 90100018                 mov     %i0, %o0
F0063D70: d0044000                 ld      [%l1], %o0
F0063D74: 80a22000                 cmp     %o0, 0
F0063D78: 12bffffe                 bne     loc_F0063D70
F0063D7C: 01000000                 nop
F0063D80: 4000cc4a                 call    _simple_lock_try
F0063D84: 90100011                 mov     %l1, %o0
F0063D88: 80a22000                 cmp     %o0, 0
F0063D8C: 02bffff9                 be      loc_F0063D70
F0063D90: 01000000                 nop
F0063D94: c024a0a8                 clr     [%l2+0xA8]
F0063D98: d0046008                 ld      [%l1+8], %o0
F0063D9C: 80a22000                 cmp     %o0, 0
F0063DA0: 26800008                 bl,a    loc_F0063DC0
F0063DA4: d0046004                 ld      [%l1+4], %o0
F0063DA8: c0244000                 clr     [%l1]
F0063DAC: 90100018                 mov     %i0, %o0
F0063DB0: 92100019                 mov     %i1, %o1
F0063DB4: 4000006b                 call    _exception_try_task
F0063DB8: 9410001a                 mov     %i2, %o2
F0063DBC: 30800016                 ba,a    locret_F0063E14
F0063DC0: 90022001                 inc     %o0
F0063DC4: d0246004                 st      %o0, [%l1+4]
F0063DC8: d004601c                 ld      [%l1+0x1C], %o0
F0063DCC: 90022001                 inc     %o0
F0063DD0: d024601c                 st      %o0, [%l1+0x1C]
F0063DD4: c0244000                 clr     [%l1]
F0063DD8: f024a0c8                 st      %i0, [%l2+0xC8]
F0063DDC: f224a0cc                 st      %i1, [%l2+0xCC]
F0063DE0: f424a0d0                 st      %i2, [%l2+0xD0]
F0063DE4: 40000cb0                 call    _retrieve_thread_self_fast
F0063DE8: 90100012                 mov     %l2, %o0
F0063DEC: a0100008                 mov     %o0, %l0
F0063DF0: 40000c85                 call    _retrieve_task_self_fast
F0063DF4: d004a00c                 ld      [%l2+0xC], %o0
F0063DF8: 94100008                 mov     %o0, %o2! task
F0063DFC: 90100011                 mov     %l1, %o0! exception_port
F0063E00: 92100010                 mov     %l0, %o1! thread
F0063E04: 96100018                 mov     %i0, %o3! exception
F0063E08: 98100019                 mov     %i1, %o4! code
F0063E0C: 400000a2                 call    _exception_raise
F0063E10: 9a10001a                 mov     %i2, %o5
F0063E14: 81c7e008                 ret
F0063E18: 81e80000                 restore
