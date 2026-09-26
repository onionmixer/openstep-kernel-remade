F0059CF4: 9de3bf90                 save    %sp, -0x70, %sp
F0059CF8: a2100018                 mov     %i0, %l1
F0059CFC: a0046008                 add     %l1, 8, %l0
F0059D00: d0040000                 ld      [%l0], %o0
F0059D04: 80a22000                 cmp     %o0, 0
F0059D08: 12bffffe                 bne     loc_F0059D00
F0059D0C: 01000000                 nop
F0059D10: 4000f466                 call    _simple_lock_try
F0059D14: 90100010                 mov     %l0, %o0
F0059D18: 80a22000                 cmp     %o0, 0
F0059D1C: 02bffff9                 be      loc_F0059D00
F0059D20: 01000000                 nop
F0059D24: d004600c                 ld      [%l1+0xC], %o0
F0059D28: 80a22000                 cmp     %o0, 0
F0059D2C: 12800005                 bne     loc_F0059D40
F0059D30: 80a6a012                 cmp     %i2, 0x12
F0059D34: c0246008                 clr     [%l1+8]
F0059D38: 1080003b                 ba      locret_F0059E24
F0059D3C: b0102010                 mov     0x10, %i0
F0059D40: 02800009                 be      loc_F0059D64
F0059D44: 90100011                 mov     %l1, %o0
F0059D48: 92100019                 mov     %i1, %o1
F0059D4C: 9407bff4                 add     %fp, var_C, %o2
F0059D50: 40000769                 call    _ipc_right_reverse
F0059D54: 9607bff0                 add     %fp, var_10, %o3
F0059D58: 80a22000                 cmp     %o0, 0
F0059D5C: 12800026                 bne     loc_F0059DF4
F0059D60: 90100011                 mov     %l1, %o0
F0059D64: 90100011                 mov     %l1, %o0
F0059D68: 9207bff4                 add     %fp, var_C, %o1
F0059D6C: 7fffe755                 call    _ipc_entry_get
F0059D70: 9407bff0                 add     %fp, var_10, %o2
F0059D74: 80a22000                 cmp     %o0, 0
F0059D78: 02800008                 be      loc_F0059D98
F0059D7C: 01000000                 nop
F0059D80: 7fffe8b8                 call    _ipc_entry_grow_table
F0059D84: 90100011                 mov     %l1, %o0
F0059D88: b0920000                 orcc    %o0, %g0, %i0
F0059D8C: 22bfffe7                 be,a    loc_F0059D28
F0059D90: d004600c                 ld      [%l1+0xC], %o0
F0059D94: 30800024                 ba,a    locret_F0059E24
F0059D98: d0064000                 ld      [%i1], %o0
F0059D9C: 80a22000                 cmp     %o0, 0
F0059DA0: 12bffffe                 bne     loc_F0059D98
F0059DA4: 01000000                 nop
F0059DA8: 4000f440                 call    _simple_lock_try
F0059DAC: 90100019                 mov     %i1, %o0
F0059DB0: 80a22000                 cmp     %o0, 0
F0059DB4: 02bffff9                 be      loc_F0059D98
F0059DB8: 01000000                 nop
F0059DBC: d0066008                 ld      [%i1+8], %o0
F0059DC0: 80a22000                 cmp     %o0, 0
F0059DC4: 06800009                 bl      loc_F0059DE8
F0059DC8: d207bff4                 ld      [%fp+var_C], %o1
F0059DCC: c0264000                 clr     [%i1]
F0059DD0: d407bff0                 ld      [%fp+var_10], %o2
F0059DD4: 7fffe829                 call    _ipc_entry_dealloc
F0059DD8: 90100011                 mov     %l1, %o0
F0059DDC: c0246008                 clr     [%l1+8]
F0059DE0: 10800011                 ba      locret_F0059E24
F0059DE4: b0102014                 mov     0x14, %i0
F0059DE8: d007bff0                 ld      [%fp+var_10], %o0
F0059DEC: f2222004                 st      %i1, [%o0+4]
F0059DF0: 90100011                 mov     %l1, %o0
F0059DF4: 9610001a                 mov     %i2, %o3
F0059DF8: d207bff4                 ld      [%fp+var_C], %o1
F0059DFC: 9810001b                 mov     %i3, %o4
F0059E00: d407bff0                 ld      [%fp+var_10], %o2
F0059E04: 40000dbf                 call    _ipc_right_copyout
F0059E08: 9a100019                 mov     %i1, %o5
F0059E0C: b0100008                 mov     %o0, %i0
F0059E10: c0246008                 clr     [%l1+8]
F0059E14: 80a62000                 cmp     %i0, 0
F0059E18: 12800003                 bne     locret_F0059E24
F0059E1C: d007bff4                 ld      [%fp+var_C], %o0
F0059E20: d0270000                 st      %o0, [%i4]
F0059E24: 81c7e008                 ret
F0059E28: 81e80000                 restore
