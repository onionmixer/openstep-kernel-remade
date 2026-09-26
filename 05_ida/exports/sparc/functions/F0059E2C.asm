F0059E2C: 9de3bf88                 save    %sp, -0x78, %sp
F0059E30: 90100018                 mov     %i0, %o0
F0059E34: 9210001c                 mov     %i4, %o1
F0059E38: 7fffe75c                 call    _ipc_entry_alloc_name
F0059E3C: 9407bff4                 add     %fp, var_C, %o2
F0059E40: 80a22000                 cmp     %o0, 0
F0059E44: 32800042                 bne,a   locret_F0059F4C
F0059E48: b0100008                 mov     %o0, %i0
F0059E4C: 80a6a012                 cmp     %i2, 0x12
F0059E50: 02800017                 be      loc_F0059EAC
F0059E54: 90100018                 mov     %i0, %o0
F0059E58: 92100019                 mov     %i1, %o1
F0059E5C: 9407bff0                 add     %fp, var_10, %o2
F0059E60: 40000725                 call    _ipc_right_reverse
F0059E64: 9607bfec                 add     %fp, var_14, %o3
F0059E68: 80a22000                 cmp     %o0, 0
F0059E6C: 02800010                 be      loc_F0059EAC
F0059E70: d007bff0                 ld      [%fp+var_10], %o0
F0059E74: 80a70008                 cmp     %i4, %o0
F0059E78: 0280002c                 be      loc_F0059F28
F0059E7C: d407bff4                 ld      [%fp+var_C], %o2
F0059E80: c0264000                 clr     [%i1]
F0059E84: d2028000                 ld      [%o2], %o1
F0059E88: 110007c0                 sethi   0x1F0000, %o0
F0059E8C: 808a4008                 btst    %o0, %o1
F0059E90: 12800004                 bne     loc_F0059EA0
F0059E94: 90100018                 mov     %i0, %o0
F0059E98: 7fffe7f8                 call    _ipc_entry_dealloc
F0059E9C: 9210001c                 mov     %i4, %o1
F0059EA0: c0262008                 clr     [%i0+8]
F0059EA4: 1080002a                 ba      locret_F0059F4C
F0059EA8: b0102015                 mov     0x15, %i0
F0059EAC: 90100018                 mov     %i0, %o0
F0059EB0: d407bff4                 ld      [%fp+var_C], %o2
F0059EB4: 400007c0                 call    _ipc_right_inuse
F0059EB8: 9210001c                 mov     %i4, %o1
F0059EBC: 80a22000                 cmp     %o0, 0
F0059EC0: 02800004                 be      loc_F0059ED0
F0059EC4: 01000000                 nop
F0059EC8: 10800021                 ba      locret_F0059F4C
F0059ECC: b010200d                 mov     0xD, %i0
F0059ED0: d0064000                 ld      [%i1], %o0
F0059ED4: 80a22000                 cmp     %o0, 0
F0059ED8: 12bffffe                 bne     loc_F0059ED0
F0059EDC: 01000000                 nop
F0059EE0: 4000f3f2                 call    _simple_lock_try
F0059EE4: 90100019                 mov     %i1, %o0
F0059EE8: 80a22000                 cmp     %o0, 0
F0059EEC: 02bffff9                 be      loc_F0059ED0
F0059EF0: 01000000                 nop
F0059EF4: d0066008                 ld      [%i1+8], %o0
F0059EF8: 80a22000                 cmp     %o0, 0
F0059EFC: 0680000a                 bl      loc_F0059F24
F0059F00: d007bff4                 ld      [%fp+var_C], %o0
F0059F04: c0264000                 clr     [%i1]
F0059F08: 90100018                 mov     %i0, %o0
F0059F0C: d407bff4                 ld      [%fp+var_C], %o2
F0059F10: 7fffe7da                 call    _ipc_entry_dealloc
F0059F14: 9210001c                 mov     %i4, %o1
F0059F18: c0262008                 clr     [%i0+8]
F0059F1C: 1080000c                 ba      locret_F0059F4C
F0059F20: b0102014                 mov     0x14, %i0
F0059F24: f2222004                 st      %i1, [%o0+4]
F0059F28: 90100018                 mov     %i0, %o0
F0059F2C: 9210001c                 mov     %i4, %o1
F0059F30: d407bff4                 ld      [%fp+var_C], %o2
F0059F34: 9610001a                 mov     %i2, %o3
F0059F38: 9810001b                 mov     %i3, %o4
F0059F3C: 40000d71                 call    _ipc_right_copyout
F0059F40: 9a100019                 mov     %i1, %o5
F0059F44: c0262008                 clr     [%i0+8]
F0059F48: b0100008                 mov     %o0, %i0
F0059F4C: 81c7e008                 ret
F0059F50: 81e80000                 restore
