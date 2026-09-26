F0064CFC: 9de3bf98                 save    %sp, -0x68, %sp
F0064D00: 80a62000                 cmp     %i0, 0
F0064D04: 02800064                 be      loc_F0064E94
F0064D08: 80a66002                 cmp     %i1, 2
F0064D0C: 2280002b                 be,a    loc_F0064DB8
F0064D10: d006c000                 ld      [%i3], %o0
F0064D14: 14800007                 bg      loc_F0064D30
F0064D18: 80a66003                 cmp     %i1, 3
F0064D1C: 80a66001                 cmp     %i1, 1
F0064D20: 2280000a                 be,a    loc_F0064D48
F0064D24: d006c000                 ld      [%i3], %o0
F0064D28: 1080005c                 ba      locret_F0064E98
F0064D2C: b0102004                 mov     4, %i0
F0064D30: 0280003c                 be      loc_F0064E20
F0064D34: 80a66004                 cmp     %i1, 4
F0064D38: 22800045                 be,a    loc_F0064E4C
F0064D3C: d006c000                 ld      [%i3], %o0
F0064D40: 10800056                 ba      locret_F0064E98
F0064D44: b0102004                 mov     4, %i0
F0064D48: 80a22004                 cmp     %o0, 4
F0064D4C: 08800043                 bleu    loc_F0064E58
F0064D50: 113c04f0                 sethi   %hi(dword_F013C048), %o0
F0064D54: d2022048                 ld      [%o0+%lo(dword_F013C048)], %o1
F0064D58: d2268000                 st      %o1, [%i2]
F0064D5C: 90122048                 bset    %lo(dword_F013C048), %o0
F0064D60: d2022004                 ld      [%o0+4], %o1
F0064D64: d226a004                 st      %o1, [%i2+4]
F0064D68: d2022008                 ld      [%o0+8], %o1
F0064D6C: 113c04d8                 sethi   %hi(_master_processor), %o0
F0064D70: d226a008                 st      %o1, [%i2+8]
F0064D74: d40223d0                 ld      [%o0+%lo(_master_processor)], %o2
F0064D78: 133c04d1                 sethi   %hi(_machine_slot), %o1
F0064D7C: d002a144                 ld      [%o2+0x144], %o0
F0064D80: 92126360                 bset    %lo(_machine_slot), %o1
F0064D84: 912a2005                 sll     %o0, 5, %o0
F0064D88: 90020009                 add     %o0, %o1, %o0
F0064D8C: d0022004                 ld      [%o0+4], %o0
F0064D90: d026a00c                 st      %o0, [%i2+0xC]
F0064D94: d002a144                 ld      [%o2+0x144], %o0
F0064D98: 912a2005                 sll     %o0, 5, %o0
F0064D9C: 90020009                 add     %o0, %o1, %o0
F0064DA0: d0022008                 ld      [%o0+8], %o0
F0064DA4: b0102000                 mov     0, %i0
F0064DA8: d026a010                 st      %o0, [%i2+0x10]
F0064DAC: 90102005                 mov     5, %o0
F0064DB0: 1080003a                 ba      locret_F0064E98
F0064DB4: d026c000                 st      %o0, [%i3]
F0064DB8: 80a22000                 cmp     %o0, 0
F0064DBC: 02800036                 be      loc_F0064E94
F0064DC0: 9210001a                 mov     %i2, %o1
F0064DC4: c026c000                 clr     [%i3]
F0064DC8: 96102000                 mov     0, %o3
F0064DCC: 113c04d194122360         set     _machine_slot, %o2
F0064DD4: d0028000                 ld      [%o2], %o0
F0064DD8: 80a22000                 cmp     %o0, 0
F0064DDC: 2280000c                 be,a    loc_F0064E0C
F0064DE0: 9602e001                 inc     %o3
F0064DE4: d002a00c                 ld      [%o2+0xC], %o0
F0064DE8: 80a22000                 cmp     %o0, 0
F0064DEC: 22800008                 be,a    loc_F0064E0C
F0064DF0: 9602e001                 inc     %o3
F0064DF4: d6224000                 st      %o3, [%o1]
F0064DF8: d006c000                 ld      [%i3], %o0
F0064DFC: 92026004                 inc     4, %o1! int
F0064E00: 90022001                 inc     %o0
F0064E04: d026c000                 st      %o0, [%i3]
F0064E08: 9602e001                 inc     %o3
F0064E0C: 80a2e000                 cmp     %o3, 0
F0064E10: 04bffff1                 ble     loc_F0064DD4
F0064E14: 9402a020                 inc     0x20, %o2 ! ' '! size_t
F0064E18: 10800020                 ba      locret_F0064E98
F0064E1C: b0102000                 mov     0, %i0
F0064E20: d006c000                 ld      [%i3], %o0
F0064E24: 80a22001                 cmp     %o0, 1
F0064E28: 0880000c                 bleu    loc_F0064E58
F0064E2C: 113c043e                 sethi   %hi(_tick), %o0
F0064E30: d00223e4                 ld      [%o0+%lo(_tick)], %o0! int
F0064E34: 7ffe85f5                 call    _div
F0064E38: 921023e8                 mov     0x3E8, %o1
F0064E3C: d0268000                 st      %o0, [%i2]
F0064E40: d026a004                 st      %o0, [%i2+4]
F0064E44: 10800011                 ba      loc_F0064E88
F0064E48: 90102002                 mov     2, %o0
F0064E4C: 80a22005                 cmp     %o0, 5
F0064E50: 18800004                 bgu     loc_F0064E60
F0064E54: 113c043f                 sethi   -0xFEF0400, %o0
F0064E58: 10800010                 ba      locret_F0064E98
F0064E5C: b0102005                 mov     5, %i0
F0064E60: 9012201c                 bset    0x1C, %o0! void *
F0064E64: 9210001a                 mov     %i2, %o1! void *
F0064E68: 4000bf2a                 call    _bcopy
F0064E6C: 9410200c                 mov     0xC, %o2! size_t
F0064E70: 113c043f90122028         set     _mach_factor, %o0! void *
F0064E78: 9206a00c                 add     %i2, 0xC, %o1! void *
F0064E7C: 4000bf25                 call    _bcopy
F0064E80: 9410200c                 mov     0xC, %o2
F0064E84: 90102006                 mov     6, %o0
F0064E88: d026c000                 st      %o0, [%i3]
F0064E8C: 10800003                 ba      locret_F0064E98
F0064E90: b0102000                 mov     0, %i0
F0064E94: b0102004                 mov     4, %i0
F0064E98: 81c7e008                 ret
F0064E9C: 81e80000                 restore
