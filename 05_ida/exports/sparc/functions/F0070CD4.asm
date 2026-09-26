F0070CD4: 9de3bf98                 save    %sp, -0x68, %sp
F0070CD8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0070CDC: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0070CE0: d204603c                 ld      [%l1+0x3C], %o1
F0070CE4: 80a26000                 cmp     %o1, 0
F0070CE8: 02800007                 be      loc_F0070D04
F0070CEC: 113c0440                 sethi   %hi(aAssertWaitAlre), %o0! "assert_wait: already asserted event 0x%"...
F0070CF0: 7ffe8e5a                 call    _printf
F0070CF4: 901223c8                 bset    %lo(aAssertWaitAlre), %o0! "assert_wait: already asserted event 0x%"...
F0070CF8: 113c0440                 sethi   %hi(aAssertWait), %o0! "assert_wait"
F0070CFC: 7ffe911d                 call    _panic
F0070D00: 901223f8                 bset    %lo(aAssertWait), %o0! "assert_wait"
F0070D04: 400097a1                 call    _splusclock
F0070D08: 01000000                 nop
F0070D0C: 80a62000                 cmp     %i0, 0
F0070D10: 02800033                 be      loc_F0070DDC
F0070D14: a8100008                 mov     %o0, %l4
F0070D18: 80a62000                 cmp     %i0, 0
F0070D1C: 16800003                 bge     loc_F0070D28
F0070D20: 90100018                 mov     %i0, %o0
F0070D24: 90380018                 xnor    %g0, %i0, %o0
F0070D28: 7ffe56e0                 call    _rem
F0070D2C: 9210203b                 mov     0x3B, %o1 ! ';'
F0070D30: 94100008                 mov     %o0, %o2
F0070D34: 932aa003                 sll     %o2, 3, %o1
F0070D38: 113c04f190122380         set     _wait_queue, %o0
F0070D40: a6024008                 add     %o1, %o0, %l3
F0070D44: 932aa002                 sll     %o2, 2, %o1
F0070D48: 113c04f190122290         set     _wait_lock, %o0
F0070D50: a4024008                 add     %o1, %o0, %l2
F0070D54: d0048000                 ld      [%l2], %o0
F0070D58: 80a22000                 cmp     %o0, 0
F0070D5C: 12bffffe                 bne     loc_F0070D54
F0070D60: 01000000                 nop
F0070D64: 40009851                 call    _simple_lock_try
F0070D68: 90100012                 mov     %l2, %o0
F0070D6C: 80a22000                 cmp     %o0, 0
F0070D70: 02bffff9                 be      loc_F0070D54
F0070D74: a0046020                 add     %l1, 0x20, %l0 ! ' '
F0070D78: d0040000                 ld      [%l0], %o0
F0070D7C: 80a22000                 cmp     %o0, 0
F0070D80: 12bffffe                 bne     loc_F0070D78
F0070D84: 01000000                 nop
F0070D88: 40009848                 call    _simple_lock_try
F0070D8C: 90100010                 mov     %l0, %o0
F0070D90: 80a22000                 cmp     %o0, 0
F0070D94: 02bffff9                 be      loc_F0070D78
F0070D98: 80a66000                 cmp     %i1, 0
F0070D9C: e6244000                 st      %l3, [%l1]
F0070DA0: d004e004                 ld      [%l3+4], %o0
F0070DA4: d0246004                 st      %o0, [%l1+4]
F0070DA8: e2220000                 st      %l1, [%o0]
F0070DAC: e224e004                 st      %l1, [%l3+4]
F0070DB0: 02800005                 be      loc_F0070DC4
F0070DB4: f024603c                 st      %i0, [%l1+0x3C]
F0070DB8: d004604c                 ld      [%l1+0x4C], %o0
F0070DBC: 10800004                 ba      loc_F0070DCC
F0070DC0: 90122001                 bset    1, %o0
F0070DC4: d004604c                 ld      [%l1+0x4C], %o0
F0070DC8: 90122009                 bset    9, %o0
F0070DCC: d024604c                 st      %o0, [%l1+0x4C]
F0070DD0: c0246020                 clr     [%l1+0x20]
F0070DD4: c0248000                 clr     [%l2]
F0070DD8: 30800012                 ba,a    loc_F0070E20
F0070DDC: a0046020                 add     %l1, 0x20, %l0 ! ' '
F0070DE0: d0040000                 ld      [%l0], %o0
F0070DE4: 80a22000                 cmp     %o0, 0
F0070DE8: 12bffffe                 bne     loc_F0070DE0
F0070DEC: 01000000                 nop
F0070DF0: 4000982e                 call    _simple_lock_try
F0070DF4: 90100010                 mov     %l0, %o0
F0070DF8: 80a22000                 cmp     %o0, 0
F0070DFC: 02bffff9                 be      loc_F0070DE0
F0070E00: 80a66000                 cmp     %i1, 0
F0070E04: 02800004                 be      loc_F0070E14
F0070E08: d004604c                 ld      [%l1+0x4C], %o0
F0070E0C: 10800003                 ba      loc_F0070E18
F0070E10: 90122001                 bset    1, %o0
F0070E14: 90122009                 bset    9, %o0
F0070E18: d024604c                 st      %o0, [%l1+0x4C]
F0070E1C: c0246020                 clr     [%l1+0x20]
F0070E20: 400097c1                 call    _splx
F0070E24: 90100014                 mov     %l4, %o0
F0070E28: 81c7e008                 ret
F0070E2C: 81e80000                 restore
