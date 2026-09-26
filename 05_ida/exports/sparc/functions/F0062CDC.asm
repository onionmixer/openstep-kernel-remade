F0062CDC: 9de3bf90                 save    %sp, -0x70, %sp
F0062CE0: 90960000                 orcc    %i0, %g0, %o0
F0062CE4: 12800004                 bne     loc_F0062CF4
F0062CE8: 92100019                 mov     %i1, %o1
F0062CEC: 10800063                 ba      locret_F0062E78
F0062CF0: b0102010                 mov     0x10, %i0
F0062CF4: 94102001                 mov     1, %o2
F0062CF8: 7fffda79                 call    _ipc_object_translate
F0062CFC: 9607bff4                 add     %fp, var_C, %o3
F0062D00: 80a22000                 cmp     %o0, 0
F0062D04: 1280005d                 bne     locret_F0062E78
F0062D08: b0100008                 mov     %o0, %i0
F0062D0C: d007bff4                 ld      [%fp+var_C], %o0
F0062D10: d0022030                 ld      [%o0+0x30], %o0
F0062D14: 80a22000                 cmp     %o0, 0
F0062D18: 02800032                 be      loc_F0062DE0
F0062D1C: b2100008                 mov     %o0, %i1
F0062D20: d0064000                 ld      [%i1], %o0
F0062D24: 80a22000                 cmp     %o0, 0
F0062D28: 12bffffe                 bne     loc_F0062D20
F0062D2C: 01000000                 nop
F0062D30: 4000d05e                 call    _simple_lock_try
F0062D34: 90100019                 mov     %i1, %o0
F0062D38: 80a22000                 cmp     %o0, 0
F0062D3C: 02bffff9                 be      loc_F0062D20
F0062D40: 01000000                 nop
F0062D44: d0066008                 ld      [%i1+8], %o0
F0062D48: 80a22000                 cmp     %o0, 0
F0062D4C: 06800013                 bl      loc_F0062D98
F0062D50: d207bff4                 ld      [%fp+var_C], %o1
F0062D54: 7fffe27c                 call    _ipc_pset_remove
F0062D58: 90100019                 mov     %i1, %o0
F0062D5C: d0066004                 ld      [%i1+4], %o0
F0062D60: c0264000                 clr     [%i1]
F0062D64: 80a22000                 cmp     %o0, 0
F0062D68: 1280001e                 bne     loc_F0062DE0
F0062D6C: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0062D70: d0066008                 ld      [%i1+8], %o0
F0062D74: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0062D78: 912a2001                 sll     %o0, 1, %o0
F0062D7C: 91322011                 srl     %o0, 17, %o0
F0062D80: 912a2002                 sll     %o0, 2, %o0
F0062D84: d0020009                 ld      [%o0+%o1], %o0
F0062D88: 40005912                 call    _zfree
F0062D8C: 92100019                 mov     %i1, %o1
F0062D90: 10800015                 ba      loc_F0062DE4
F0062D94: d007bff4                 ld      [%fp+var_C], %o0
F0062D98: d006600c                 ld      [%i1+0xC], %o0
F0062D9C: b0066010                 add     %i1, 0x10, %i0
F0062DA0: d0268000                 st      %o0, [%i2]
F0062DA4: d0060000                 ld      [%i0], %o0
F0062DA8: 80a22000                 cmp     %o0, 0
F0062DAC: 12bffffe                 bne     loc_F0062DA4
F0062DB0: 01000000                 nop
F0062DB4: 4000d03d                 call    _simple_lock_try
F0062DB8: 90100018                 mov     %i0, %o0
F0062DBC: 80a22000                 cmp     %o0, 0
F0062DC0: 02bffff9                 be      loc_F0062DA4
F0062DC4: d007bff4                 ld      [%fp+var_C], %o0
F0062DC8: d0022034                 ld      [%o0+0x34], %o0
F0062DCC: d026a004                 st      %o0, [%i2+4]
F0062DD0: c0266010                 clr     [%i1+0x10]
F0062DD4: c0264000                 clr     [%i1]
F0062DD8: 10800012                 ba      loc_F0062E20
F0062DDC: d207bff4                 ld      [%fp+var_C], %o1
F0062DE0: d007bff4                 ld      [%fp+var_C], %o0
F0062DE4: c0268000                 clr     [%i2]
F0062DE8: b0022040                 add     %o0, 0x40, %i0 ! '@'
F0062DEC: d0060000                 ld      [%i0], %o0
F0062DF0: 80a22000                 cmp     %o0, 0
F0062DF4: 12bffffe                 bne     loc_F0062DEC
F0062DF8: 01000000                 nop
F0062DFC: 4000d02b                 call    _simple_lock_try
F0062E00: 90100018                 mov     %i0, %o0
F0062E04: 80a22000                 cmp     %o0, 0
F0062E08: 02bffff9                 be      loc_F0062DEC
F0062E0C: d207bff4                 ld      [%fp+var_C], %o1
F0062E10: d0026034                 ld      [%o1+0x34], %o0
F0062E14: d026a004                 st      %o0, [%i2+4]
F0062E18: c0226040                 clr     [%o1+0x40]
F0062E1C: d207bff4                 ld      [%fp+var_C], %o1
F0062E20: d0026018                 ld      [%o1+0x18], %o0
F0062E24: d026a008                 st      %o0, [%i2+8]
F0062E28: d002603c                 ld      [%o1+0x3C], %o0
F0062E2C: d026a00c                 st      %o0, [%i2+0xC]
F0062E30: d0026038                 ld      [%o1+0x38], %o0
F0062E34: d026a010                 st      %o0, [%i2+0x10]
F0062E38: d0026020                 ld      [%o1+0x20], %o0
F0062E3C: d026a014                 st      %o0, [%i2+0x14]
F0062E40: d002601c                 ld      [%o1+0x1C], %o0
F0062E44: 80a00008                 cmp     %g0, %o0
F0062E48: 90402000                 addc    %g0, 0, %o0
F0062E4C: d026a018                 st      %o0, [%i2+0x18]
F0062E50: d0026028                 ld      [%o1+0x28], %o0
F0062E54: 80a00008                 cmp     %g0, %o0
F0062E58: 90402000                 addc    %g0, 0, %o0
F0062E5C: d026a01c                 st      %o0, [%i2+0x1C]
F0062E60: d0026024                 ld      [%o1+0x24], %o0
F0062E64: b0102000                 mov     0, %i0
F0062E68: 80a00008                 cmp     %g0, %o0
F0062E6C: 90402000                 addc    %g0, 0, %o0
F0062E70: d026a020                 st      %o0, [%i2+0x20]
F0062E74: c0224000                 clr     [%o1]
F0062E78: 81c7e008                 ret
F0062E7C: 81e80000                 restore
