F0063E1C: 9de3bf98                 save    %sp, -0x68, %sp
F0063E20: 113c04d0                 sethi   %hi(_active_threads), %o0
F0063E24: e6022260                 ld      [%o0+%lo(_active_threads)], %l3
F0063E28: ea04e038                 ld      [%l3+0x38], %l5
F0063E2C: ec04e0c8                 ld      [%l3+0xC8], %l6
F0063E30: ee04e0cc                 ld      [%l3+0xCC], %l7
F0063E34: 80a62000                 cmp     %i0, 0
F0063E38: e804e0d0                 ld      [%l3+0xD0], %l4
F0063E3C: 12800005                 bne     loc_F0063E50
F0063E40: a4100013                 mov     %l3, %l2
F0063E44: 113c043e                 sethi   %hi(aException), %o0! "exception"
F0063E48: 7ffec4ca                 call    _panic
F0063E4C: 901220c0                 bset    %lo(aException), %o0! "exception"
F0063E50: c024e038                 clr     [%l3+0x38]
F0063E54: a004e0a8                 add     %l3, 0xA8, %l0
F0063E58: d0040000                 ld      [%l0], %o0
F0063E5C: 80a22000                 cmp     %o0, 0
F0063E60: 12bffffe                 bne     loc_F0063E58
F0063E64: 01000000                 nop
F0063E68: 4000cc10                 call    _simple_lock_try
F0063E6C: 90100010                 mov     %l0, %o0
F0063E70: 80a22000                 cmp     %o0, 0
F0063E74: 02bffff9                 be      loc_F0063E58
F0063E78: 01000000                 nop
F0063E7C: e204a0b4                 ld      [%l2+0xB4], %l1
F0063E80: 80a46000                 cmp     %l1, 0
F0063E84: 02800004                 be      loc_F0063E94
F0063E88: 80a47fff                 cmp     %l1, -1
F0063E8C: 12800005                 bne     loc_F0063EA0
F0063E90: 01000000                 nop
F0063E94: c024a0a8                 clr     [%l2+0xA8]
F0063E98: 10800012                 ba      loc_F0063EE0
F0063E9C: 90100018                 mov     %i0, %o0
F0063EA0: d0044000                 ld      [%l1], %o0
F0063EA4: 80a22000                 cmp     %o0, 0
F0063EA8: 12bffffe                 bne     loc_F0063EA0
F0063EAC: 01000000                 nop
F0063EB0: 4000cbfe                 call    _simple_lock_try
F0063EB4: 90100011                 mov     %l1, %o0
F0063EB8: 80a22000                 cmp     %o0, 0
F0063EBC: 02bffff9                 be      loc_F0063EA0
F0063EC0: 01000000                 nop
F0063EC4: c024a0a8                 clr     [%l2+0xA8]
F0063EC8: d0046008                 ld      [%l1+8], %o0
F0063ECC: 80a22000                 cmp     %o0, 0
F0063ED0: 26800009                 bl,a    loc_F0063EF4
F0063ED4: d0046004                 ld      [%l1+4], %o0
F0063ED8: c0244000                 clr     [%l1]
F0063EDC: 90100018                 mov     %i0, %o0
F0063EE0: 92100019                 mov     %i1, %o1
F0063EE4: 4000001f                 call    _exception_try_task
F0063EE8: 9410001a                 mov     %i2, %o2
F0063EEC: 10800018                 ba      loc_F0063F4C
F0063EF0: ea24e038                 st      %l5, [%l3+0x38]
F0063EF4: 90022001                 inc     %o0
F0063EF8: d0246004                 st      %o0, [%l1+4]
F0063EFC: d004601c                 ld      [%l1+0x1C], %o0
F0063F00: 90022001                 inc     %o0
F0063F04: d024601c                 st      %o0, [%l1+0x1C]
F0063F08: c0244000                 clr     [%l1]
F0063F0C: f024a0c8                 st      %i0, [%l2+0xC8]
F0063F10: f224a0cc                 st      %i1, [%l2+0xCC]
F0063F14: f424a0d0                 st      %i2, [%l2+0xD0]
F0063F18: 40000c63                 call    _retrieve_thread_self_fast
F0063F1C: 90100012                 mov     %l2, %o0
F0063F20: a0100008                 mov     %o0, %l0
F0063F24: 40000c38                 call    _retrieve_task_self_fast
F0063F28: d004a00c                 ld      [%l2+0xC], %o0
F0063F2C: 94100008                 mov     %o0, %o2! task
F0063F30: 90100011                 mov     %l1, %o0! exception_port
F0063F34: 92100010                 mov     %l0, %o1! thread
F0063F38: 96100018                 mov     %i0, %o3! exception
F0063F3C: 98100019                 mov     %i1, %o4! code
F0063F40: 40000055                 call    _exception_raise
F0063F44: 9a10001a                 mov     %i2, %o5
F0063F48: ea24e038                 st      %l5, [%l3+0x38]
F0063F4C: ec24e0c8                 st      %l6, [%l3+0xC8]
F0063F50: ee24e0cc                 st      %l7, [%l3+0xCC]
F0063F54: e824e0d0                 st      %l4, [%l3+0xD0]
F0063F58: 81c7e008                 ret
F0063F5C: 81e80000                 restore
