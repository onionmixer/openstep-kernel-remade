F0069D60: 9de3bf98                 save    %sp, -0x68, %sp
F0069D64: 113c04d3a01223b8         set     _all_psets_lock, %l0
F0069D6C: d0040000                 ld      [%l0], %o0
F0069D70: 80a22000                 cmp     %o0, 0
F0069D74: 12bffffe                 bne     loc_F0069D6C
F0069D78: 01000000                 nop
F0069D7C: 4000b44b                 call    _simple_lock_try
F0069D80: 90100010                 mov     %l0, %o0
F0069D84: 80a22000                 cmp     %o0, 0
F0069D88: 02bffff9                 be      loc_F0069D6C
F0069D8C: 113c04d3                 sethi   %hi(_all_psets), %o0
F0069D90: e40223b0                 ld      [%o0+%lo(_all_psets)], %l2
F0069D94: 901223b0                 bset    %lo(_all_psets), %o0
F0069D98: 80a48008                 cmp     %l2, %o0
F0069D9C: 0280007e                 be      loc_F0069F94
F0069DA0: 113c04d3                 sethi   %hi(_default_pset), %o0
F0069DA4: b61223c0                 or      %o0, %lo(_default_pset), %i3
F0069DA8: 113c043fb8122028         set     _mach_factor, %i4
F0069DB0: a004a158                 add     %l2, 0x158, %l0
F0069DB4: d0040000                 ld      [%l0], %o0
F0069DB8: 80a22000                 cmp     %o0, 0
F0069DBC: 12bffffe                 bne     loc_F0069DB4
F0069DC0: 01000000                 nop
F0069DC4: 4000b439                 call    _simple_lock_try
F0069DC8: 90100010                 mov     %l0, %o0
F0069DCC: 80a22000                 cmp     %o0, 0
F0069DD0: 02bffff9                 be      loc_F0069DB4
F0069DD4: 01000000                 nop
F0069DD8: e204a124                 ld      [%l2+0x124], %l1
F0069DDC: 80a46000                 cmp     %l1, 0
F0069DE0: 04800066                 ble     loc_F0069F78
F0069DE4: 9004a11c                 add     %l2, 0x11C, %o0
F0069DE8: d204a11c                 ld      [%l2+0x11C], %o1
F0069DEC: 80a20009                 cmp     %o0, %o1
F0069DF0: 02800008                 be      loc_F0069E10
F0069DF4: e004a108                 ld      [%l2+0x108], %l0
F0069DF8: 94100008                 mov     %o0, %o2
F0069DFC: d0026108                 ld      [%o1+0x108], %o0
F0069E00: d2026134                 ld      [%o1+0x134], %o1
F0069E04: 80a28009                 cmp     %o2, %o1
F0069E08: 12bffffd                 bne     loc_F0069DFC
F0069E0C: a0040008                 add     %l0, %o0, %l0
F0069E10: d004a114                 ld      [%l2+0x114], %o0
F0069E14: 80a4801b                 cmp     %l2, %i3
F0069E18: 90244008                 sub     %l1, %o0, %o0
F0069E1C: 12800003                 bne     loc_F0069E28
F0069E20: a0040008                 add     %l0, %o0, %l0
F0069E24: a0043fff                 inc     -1, %l0
F0069E28: 80a40011                 cmp     %l0, %l1
F0069E2C: 0480000f                 ble     loc_F0069E68
F0069E30: 92244010                 sub     %l1, %l0, %o1! int
F0069E34: 912c6005                 sll     %l1, 5, %o0
F0069E38: 90220011                 sub     %o0, %l1, %o0
F0069E3C: 912a2002                 sll     %o0, 2, %o0
F0069E40: 90020011                 add     %o0, %l1, %o0
F0069E44: 912a2003                 sll     %o0, 3, %o0! int
F0069E48: 7ffe71f0                 call    _div
F0069E4C: 92042001                 add     %l0, 1, %o1! int
F0069E50: ae100008                 mov     %o0, %l7
F0069E54: 912c2007                 sll     %l0, 7, %o0! int
F0069E58: 7ffe71ec                 call    _div
F0069E5C: 92100011                 mov     %l1, %o1
F0069E60: 10800008                 ba      loc_F0069E80
F0069E64: b4100008                 mov     %o0, %i2
F0069E68: 912a6005                 sll     %o1, 5, %o0
F0069E6C: 90220009                 sub     %o0, %o1, %o0
F0069E70: 912a2002                 sll     %o0, 2, %o0
F0069E74: 90020009                 add     %o0, %o1, %o0
F0069E78: af2a2003                 sll     %o0, 3, %l7
F0069E7C: b4102080                 mov     0x80, %i2
F0069E80: 92102005                 mov     5, %o1! int
F0069E84: 952c2005                 sll     %l0, 5, %o2
F0069E88: 94228010                 sub     %o2, %l0, %o2
F0069E8C: 952aa002                 sll     %o2, 2, %o2
F0069E90: 94028010                 add     %o2, %l0, %o2
F0069E94: d004a170                 ld      [%l2+0x170], %o0
F0069E98: b32aa003                 sll     %o2, 3, %i1
F0069E9C: 912a2002                 sll     %o0, 2, %o0! int
F0069EA0: 7ffe71da                 call    _div
F0069EA4: 90020017                 add     %o0, %l7, %o0
F0069EA8: d024a170                 st      %o0, [%l2+0x170]
F0069EAC: d004a174                 ld      [%l2+0x174], %o0
F0069EB0: 92102005                 mov     5, %o1! int
F0069EB4: 912a2002                 sll     %o0, 2, %o0! int
F0069EB8: 7ffe71d4                 call    _div
F0069EBC: 90020019                 add     %o0, %i1, %o0
F0069EC0: 80a4801b                 cmp     %l2, %i3
F0069EC4: 12800029                 bne     loc_F0069F68
F0069EC8: d024a174                 st      %o0, [%l2+0x174]
F0069ECC: ac102000                 mov     0, %l6
F0069ED0: b01023e8                 mov     0x3E8, %i0
F0069ED4: 113c043faa12201c         set     _avenrun, %l5
F0069EDC: 113c043fa8122034         set     unk_F010FC34, %l4
F0069EE4: a610001c                 mov     %i4, %l3
F0069EE8: e2050000                 ld      [%l4], %l1
F0069EEC: ac05a001                 inc     %l6
F0069EF0: d004c000                 ld      [%l3], %o0
F0069EF4: 7ffe7183                 call    _umul
F0069EF8: 92100011                 mov     %l1, %o1
F0069EFC: a0100008                 mov     %o0, %l0
F0069F00: 90100017                 mov     %l7, %o0
F0069F04: 7ffe717f                 call    _umul
F0069F08: 92260011                 sub     %i0, %l1, %o1! int
F0069F0C: a0040008                 add     %l0, %o0, %l0
F0069F10: 90100010                 mov     %l0, %o0! int
F0069F14: 7ffe71bd                 call    _div
F0069F18: 921023e8                 mov     0x3E8, %o1
F0069F1C: d024c000                 st      %o0, [%l3]
F0069F20: e2050000                 ld      [%l4], %l1
F0069F24: a604e004                 inc     4, %l3
F0069F28: d0054000                 ld      [%l5], %o0
F0069F2C: 7ffe7175                 call    _umul
F0069F30: 92100011                 mov     %l1, %o1
F0069F34: a0100008                 mov     %o0, %l0
F0069F38: 90100019                 mov     %i1, %o0
F0069F3C: 7ffe7171                 call    _umul
F0069F40: 92260011                 sub     %i0, %l1, %o1! int
F0069F44: a0040008                 add     %l0, %o0, %l0
F0069F48: 90100010                 mov     %l0, %o0! int
F0069F4C: 7ffe71af                 call    _div
F0069F50: 921023e8                 mov     0x3E8, %o1
F0069F54: d0254000                 st      %o0, [%l5]
F0069F58: aa056004                 inc     4, %l5
F0069F5C: 80a5a002                 cmp     %l6, 2
F0069F60: 04bfffe2                 ble     loc_F0069EE8
F0069F64: a8052004                 inc     4, %l4
F0069F68: d004a178                 ld      [%l2+0x178], %o0
F0069F6C: 9002001a                 add     %o0, %i2, %o0
F0069F70: 913a2001                 sra     %o0, 1, %o0
F0069F74: d024a178                 st      %o0, [%l2+0x178]
F0069F78: c024a158                 clr     [%l2+0x158]
F0069F7C: e404a14c                 ld      [%l2+0x14C], %l2
F0069F80: 113c04d3901223b0         set     _all_psets, %o0
F0069F88: 80a48008                 cmp     %l2, %o0
F0069F8C: 12bfff8a                 bne     loc_F0069DB4
F0069F90: a004a158                 add     %l2, 0x158, %l0
F0069F94: 113c04d3                 sethi   %hi(_all_psets_lock), %o0
F0069F98: c02223b8                 clr     [%o0+%lo(_all_psets_lock)]
F0069F9C: 81c7e008                 ret
F0069FA0: 81e80000                 restore
