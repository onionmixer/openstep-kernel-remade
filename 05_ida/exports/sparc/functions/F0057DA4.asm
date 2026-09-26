F0057DA4: 9de3bf90                 save    %sp, -0x70, %sp
F0057DA8: 113c04ef                 sethi   %hi(_ipc_marequest_zone), %o0
F0057DAC: 400084c8                 call    _zalloc
F0057DB0: d0022368                 ld      [%o0+%lo(_ipc_marequest_zone)], %o0
F0057DB4: a2920000                 orcc    %o0, %g0, %l1
F0057DB8: 12800005                 bne     loc_F0057DCC
F0057DBC: a0062008                 add     %i0, 8, %l0
F0057DC0: 31040000                 sethi   0x10000000, %i0
F0057DC4: 10800069                 ba      locret_F0057F68
F0057DC8: b016200e                 bset    0xE, %i0
F0057DCC: d0040000                 ld      [%l0], %o0
F0057DD0: 80a22000                 cmp     %o0, 0
F0057DD4: 12bffffe                 bne     loc_F0057DCC
F0057DD8: 01000000                 nop
F0057DDC: 4000fc33                 call    _simple_lock_try
F0057DE0: 90100010                 mov     %l0, %o0
F0057DE4: 80a22000                 cmp     %o0, 0
F0057DE8: 02bffff9                 be      loc_F0057DCC
F0057DEC: 01000000                 nop
F0057DF0: d006200c                 ld      [%i0+0xC], %o0
F0057DF4: 80a22000                 cmp     %o0, 0
F0057DF8: 0280004b                 be      loc_F0057F24
F0057DFC: 90100018                 mov     %i0, %o0
F0057E00: 92100019                 mov     %i1, %o1
F0057E04: 9407bff4                 add     %fp, var_C, %o2
F0057E08: 40000f3b                 call    _ipc_right_reverse
F0057E0C: 9607bff0                 add     %fp, var_10, %o3
F0057E10: 80a22000                 cmp     %o0, 0
F0057E14: 0280003c                 be      loc_F0057F04
F0057E18: d007bff0                 ld      [%fp+var_10], %o0
F0057E1C: c0264000                 clr     [%i1]
F0057E20: f2020000                 ld      [%o0], %i1
F0057E24: 11000800                 sethi   0x200000, %o0
F0057E28: 808e4008                 btst    %o0, %i1
F0057E2C: 0280000a                 be      loc_F0057E54
F0057E30: 80a6a000                 cmp     %i2, 0
F0057E34: c0262008                 clr     [%i0+8]
F0057E38: 113c04ef                 sethi   %hi(_ipc_marequest_zone), %o0
F0057E3C: d0022368                 ld      [%o0+%lo(_ipc_marequest_zone)], %o0
F0057E40: 400084e4                 call    _zfree
F0057E44: 92100011                 mov     %l1, %o1
F0057E48: 31040000                 sethi   0x10000000, %i0
F0057E4C: 10800047                 ba      locret_F0057F68
F0057E50: b0162006                 bset    6, %i0
F0057E54: 02800008                 be      loc_F0057E74
F0057E58: 90100018                 mov     %i0, %o0
F0057E5C: 40000c43                 call    _ipc_port_lookup_notify
F0057E60: 9210001a                 mov     %i2, %o1
F0057E64: a0920000                 orcc    %o0, %g0, %l0
F0057E68: 12800004                 bne     loc_F0057E78
F0057E6C: 90100018                 mov     %i0, %o0
F0057E70: 3080002d                 ba,a    loc_F0057F24
F0057E74: a0102000                 mov     0, %l0
F0057E78: 13000800                 sethi   0x200000, %o1
F0057E7C: d407bff0                 ld      [%fp+var_10], %o2
F0057E80: 92164009                 bset    %i1, %o1
F0057E84: 400017e1                 call    _ipc_space_reference
F0057E88: d2228000                 st      %o1, [%o2]
F0057E8C: f0244000                 st      %i0, [%l1]
F0057E90: e0246008                 st      %l0, [%l1+8]
F0057E94: 173c04ef                 sethi   %hi(_ipc_marequest_table), %o3
F0057E98: d407bff4                 ld      [%fp+var_C], %o2
F0057E9C: 91362004                 srl     %i0, 4, %o0
F0057EA0: d4246004                 st      %o2, [%l1+4]
F0057EA4: 9332a008                 srl     %o2, 8, %o1
F0057EA8: 90020009                 add     %o0, %o1, %o0
F0057EAC: 940aa0ff                 and     %o2, 0xFF, %o2
F0057EB0: 133c04ef                 sethi   %hi(_ipc_marequest_mask), %o1
F0057EB4: d2026350                 ld      [%o1+%lo(_ipc_marequest_mask)], %o1
F0057EB8: 9002000a                 add     %o0, %o2, %o0
F0057EBC: 900a0009                 and     %o0, %o1, %o0
F0057EC0: d202e360                 ld      [%o3+%lo(_ipc_marequest_table)], %o1
F0057EC4: 912a2003                 sll     %o0, 3, %o0
F0057EC8: b2024008                 add     %o1, %o0, %i1
F0057ECC: d0064000                 ld      [%i1], %o0
F0057ED0: 80a22000                 cmp     %o0, 0
F0057ED4: 12bffffe                 bne     loc_F0057ECC
F0057ED8: 01000000                 nop
F0057EDC: 4000fbf3                 call    _simple_lock_try
F0057EE0: 90100019                 mov     %i1, %o0
F0057EE4: 80a22000                 cmp     %o0, 0
F0057EE8: 02bffff9                 be      loc_F0057ECC
F0057EEC: 01000000                 nop
F0057EF0: d0066004                 ld      [%i1+4], %o0
F0057EF4: d024600c                 st      %o0, [%l1+0xC]
F0057EF8: e2266004                 st      %l1, [%i1+4]
F0057EFC: c0264000                 clr     [%i1]
F0057F00: 30800017                 ba,a    loc_F0057F5C
F0057F04: 80a6a000                 cmp     %i2, 0
F0057F08: 0280000f                 be      loc_F0057F44
F0057F0C: 90100018                 mov     %i0, %o0
F0057F10: 40000c16                 call    _ipc_port_lookup_notify
F0057F14: 9210001a                 mov     %i2, %o1
F0057F18: a0920000                 orcc    %o0, %g0, %l0
F0057F1C: 1280000b                 bne     loc_F0057F48
F0057F20: 01000000                 nop
F0057F24: c0262008                 clr     [%i0+8]
F0057F28: 113c04ef                 sethi   %hi(_ipc_marequest_zone), %o0
F0057F2C: d0022368                 ld      [%o0+%lo(_ipc_marequest_zone)], %o0
F0057F30: 400084a8                 call    _zfree
F0057F34: 92100011                 mov     %l1, %o1
F0057F38: 31040000                 sethi   0x10000000, %i0
F0057F3C: 1080000b                 ba      locret_F0057F68
F0057F40: b016200b                 bset    0xB, %i0
F0057F44: a0102000                 mov     0, %l0
F0057F48: 400017b0                 call    _ipc_space_reference
F0057F4C: 90100018                 mov     %i0, %o0
F0057F50: f0244000                 st      %i0, [%l1]
F0057F54: c0246004                 clr     [%l1+4]
F0057F58: e0246008                 st      %l0, [%l1+8]
F0057F5C: c0262008                 clr     [%i0+8]
F0057F60: e226c000                 st      %l1, [%i3]
F0057F64: b0102000                 mov     0, %i0
F0057F68: 81c7e008                 ret
F0057F6C: 81e80000                 restore
