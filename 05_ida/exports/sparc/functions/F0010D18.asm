F0010D18: 9de3bf98                 save    %sp, -0x68, %sp
F0010D1C: 94063fff                 add     %i0, -1, %o2
F0010D20: 113c04cf                 sethi   %hi(_active_u), %o0
F0010D24: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0010D28: 92102001                 mov     1, %o1
F0010D2C: e2020000                 ld      [%o0], %l1
F0010D30: 40021796                 call    _splusclock
F0010D34: a52a400a                 sll     %o1, %o2, %l2
F0010D38: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F0010D3C: d0040000                 ld      [%l0], %o0
F0010D40: 80a22000                 cmp     %o0, 0
F0010D44: 12bffffe                 bne     loc_F0010D3C
F0010D48: 01000000                 nop
F0010D4C: 40021857                 call    _simple_lock_try
F0010D50: 90100010                 mov     %l0, %o0
F0010D54: 80a22000                 cmp     %o0, 0
F0010D58: 02bffff9                 be      loc_F0010D3C
F0010D5C: 153c04cf                 sethi   %hi(_active_u), %o2
F0010D60: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0010D64: 972e2002                 sll     %i0, 2, %o3
F0010D68: d2064000                 ld      [%i1], %o1
F0010D6C: 9002c008                 add     %o3, %o0, %o0
F0010D70: d2222030                 st      %o1, [%o0+0x30]
F0010D74: d402a1d8                 ld      [%o2+%lo(_active_u)], %o2
F0010D78: d0028000                 ld      [%o2], %o0
F0010D7C: d2022014                 ld      [%o0+0x14], %o1
F0010D80: 11000010                 sethi   0x4000, %o0
F0010D84: 808a4008                 btst    %o0, %o1
F0010D88: d2066004                 ld      [%i1+4], %o1
F0010D8C: 02800005                 be      loc_F0010DA0
F0010D90: 9602c00a                 add     %o3, %o2, %o3
F0010D94: 113fffbf                 sethi   -0x10400, %o0
F0010D98: 10800004                 ba      loc_F0010DA8
F0010D9C: 901222ff                 bset    0x2FF, %o0
F0010DA0: 113ffebf901222ff         set     -0x50101, %o0
F0010DA8: 900a4008                 and     %o1, %o0, %o0
F0010DAC: d022e0b4                 st      %o0, [%o3+0xB4]
F0010DB0: d0066008                 ld      [%i1+8], %o0
F0010DB4: 808a2002                 btst    2, %o0
F0010DB8: 02800006                 be      loc_F0010DD0
F0010DBC: 113c04cf                 sethi   %hi(_active_u), %o0
F0010DC0: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0010DC4: d002613c                 ld      [%o1+0x13C], %o0
F0010DC8: 10800005                 ba      loc_F0010DDC
F0010DCC: 90120012                 bset    %l2, %o0
F0010DD0: d20221d8                 ld      [%o0+0x1D8], %o1
F0010DD4: d002613c                 ld      [%o1+0x13C], %o0
F0010DD8: 902a0012                 bclr    %l2, %o0
F0010DDC: d022613c                 st      %o0, [%o1+0x13C]
F0010DE0: d0066008                 ld      [%i1+8], %o0
F0010DE4: 808a2001                 btst    1, %o0
F0010DE8: 02800006                 be      loc_F0010E00
F0010DEC: 113c04cf                 sethi   %hi(_active_u), %o0
F0010DF0: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0010DF4: d0026138                 ld      [%o1+0x138], %o0
F0010DF8: 10800005                 ba      loc_F0010E0C
F0010DFC: 90120012                 bset    %l2, %o0
F0010E00: d20221d8                 ld      [%o0+0x1D8], %o1
F0010E04: d0026138                 ld      [%o1+0x138], %o0
F0010E08: 902a0012                 bclr    %l2, %o0
F0010E0C: d0226138                 st      %o0, [%o1+0x138]
F0010E10: d4064000                 ld      [%i1], %o2
F0010E14: 80a2a001                 cmp     %o2, 1
F0010E18: 0280000b                 be      loc_F0010E44
F0010E1C: 11000010                 sethi   0x4000, %o0
F0010E20: d2046014                 ld      [%l1+0x14], %o1
F0010E24: 808a4008                 btst    %o0, %o1
F0010E28: 0280002f                 be      loc_F0010EE4
F0010E2C: 80a2a000                 cmp     %o2, 0
F0010E30: 3280002e                 bne,a   loc_F0010EE8
F0010E34: d0046020                 ld      [%l1+0x20], %o0
F0010E38: 80a62014                 cmp     %i0, 0x14
F0010E3C: 3280002b                 bne,a   loc_F0010EE8
F0010E40: d0046020                 ld      [%l1+0x20], %o0
F0010E44: d2046018                 ld      [%l1+0x18], %o1
F0010E48: 11000007901222f8         set     0x1EF8, %o0
F0010E50: 808c8008                 btst    %o0, %l2
F0010E54: 922a4012                 bclr    %l2, %o1
F0010E58: 0280001c                 be      loc_F0010EC8
F0010E5C: d2246018                 st      %o1, [%l1+0x18]
F0010E60: d0046068                 ld      [%l1+0x68], %o0
F0010E64: b002201c                 add     %o0, 0x1C, %i0
F0010E68: a0100008                 mov     %o0, %l0
F0010E6C: d0040000                 ld      [%l0], %o0
F0010E70: 80a22000                 cmp     %o0, 0
F0010E74: 12bffffe                 bne     loc_F0010E6C
F0010E78: 01000000                 nop
F0010E7C: 4002180b                 call    _simple_lock_try
F0010E80: 90100010                 mov     %l0, %o0
F0010E84: 80a22000                 cmp     %o0, 0
F0010E88: 02bffff9                 be      loc_F0010E6C
F0010E8C: 01000000                 nop
F0010E90: d4060000                 ld      [%i0], %o2
F0010E94: 80a6000a                 cmp     %i0, %o2
F0010E98: 0280000a                 be      loc_F0010EC0
F0010E9C: 96380012                 xnor    %g0, %l2, %o3
F0010EA0: d202a084                 ld      [%o2+0x84], %o1
F0010EA4: d002604c                 ld      [%o1+0x4C], %o0
F0010EA8: 900a000b                 and     %o0, %o3, %o0
F0010EAC: d022604c                 st      %o0, [%o1+0x4C]
F0010EB0: d402a010                 ld      [%o2+0x10], %o2
F0010EB4: 80a6000a                 cmp     %i0, %o2
F0010EB8: 32bffffb                 bne,a   loc_F0010EA4
F0010EBC: d202a084                 ld      [%o2+0x84], %o1
F0010EC0: d0046068                 ld      [%l1+0x68], %o0
F0010EC4: c0220000                 clr     [%o0]
F0010EC8: d0046020                 ld      [%l1+0x20], %o0
F0010ECC: d2046024                 ld      [%l1+0x24], %o1
F0010ED0: 90120012                 bset    %l2, %o0
F0010ED4: d0246020                 st      %o0, [%l1+0x20]
F0010ED8: 922a4012                 bclr    %l2, %o1
F0010EDC: 10800019                 ba      loc_F0010F40
F0010EE0: d2246024                 st      %o1, [%l1+0x24]
F0010EE4: d0046020                 ld      [%l1+0x20], %o0
F0010EE8: 94380012                 xnor    %g0, %l2, %o2
F0010EEC: 900a000a                 and     %o0, %o2, %o0
F0010EF0: d0246020                 st      %o0, [%l1+0x20]
F0010EF4: d0064000                 ld      [%i1], %o0
F0010EF8: 80a22000                 cmp     %o0, 0
F0010EFC: 3280000f                 bne,a   loc_F0010F38
F0010F00: d0046024                 ld      [%l1+0x24], %o0
F0010F04: d2046014                 ld      [%l1+0x14], %o1
F0010F08: 11000010                 sethi   0x4000, %o0
F0010F0C: 808a4008                 btst    %o0, %o1
F0010F10: 22800008                 be,a    loc_F0010F30
F0010F14: d0046024                 ld      [%l1+0x24], %o0
F0010F18: 113c04cf                 sethi   %hi(_active_u), %o0
F0010F1C: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0010F20: 912e2002                 sll     %i0, 2, %o0
F0010F24: 90020009                 add     %o0, %o1, %o0
F0010F28: c0222030                 clr     [%o0+0x30]
F0010F2C: d0046024                 ld      [%l1+0x24], %o0
F0010F30: 10800003                 ba      loc_F0010F3C
F0010F34: 900a000a                 and     %o0, %o2, %o0
F0010F38: 90120012                 bset    %l2, %o0
F0010F3C: d0246024                 st      %o0, [%l1+0x24]
F0010F40: c0246070                 clr     [%l1+0x70]
F0010F44: 40021767                 call    _spl0
F0010F48: 01000000                 nop
F0010F4C: 81c7e008                 ret
F0010F50: 81e80000                 restore
