F0085DD4: 9de3bf90                 save    %sp, -0x70, %sp
F0085DD8: ee07a05c                 ld      [%fp+arg_5C], %l7
F0085DDC: ec07a060                 ld      [%fp+arg_60], %l6
F0085DE0: e2060000                 ld      [%i0], %l1
F0085DE4: 7fff8cc4                 call    _lock_read
F0085DE8: 90100011                 mov     %l1, %o0
F0085DEC: a004603c                 add     %l1, 0x3C, %l0 ! '<'
F0085DF0: d0040000                 ld      [%l0], %o0
F0085DF4: 80a22000                 cmp     %o0, 0
F0085DF8: 12bffffe                 bne     loc_F0085DF0
F0085DFC: 01000000                 nop
F0085E00: 4000442a                 call    _simple_lock_try
F0085E04: 90100010                 mov     %l0, %o0
F0085E08: 80a22000                 cmp     %o0, 0
F0085E0C: 02bffff9                 be      loc_F0085DF0
F0085E10: 01000000                 nop
F0085E14: e0046038                 ld      [%l1+0x38], %l0
F0085E18: c024603c                 clr     [%l1+0x3C]
F0085E1C: 9004600c                 add     %l1, 0xC, %o0
F0085E20: 80a40008                 cmp     %l0, %o0
F0085E24: 0280000a                 be      loc_F0085E4C
F0085E28: e026c000                 st      %l0, [%i3]
F0085E2C: d0042008                 ld      [%l0+8], %o0
F0085E30: 80a64008                 cmp     %i1, %o0
F0085E34: 0a800007                 bcs     loc_F0085E50
F0085E38: 90100011                 mov     %l1, %o0
F0085E3C: d004200c                 ld      [%l0+0xC], %o0
F0085E40: 80a64008                 cmp     %i1, %o0
F0085E44: 2a80000b                 bcs,a   loc_F0085E70
F0085E48: d2042018                 ld      [%l0+0x18], %o1
F0085E4C: 90100011                 mov     %l1, %o0
F0085E50: 92100019                 mov     %i1, %o1
F0085E54: 7ffff995                 call    _vm_map_lookup_entry
F0085E58: 9407bff4                 add     %fp, var_C, %o2
F0085E5C: 80a22000                 cmp     %o0, 0
F0085E60: 02800033                 be      loc_F0085F2C
F0085E64: e007bff4                 ld      [%fp+var_C], %l0
F0085E68: e026c000                 st      %l0, [%i3]
F0085E6C: d2042018                 ld      [%l0+0x18], %o1
F0085E70: 11080000                 sethi   0x20000000, %o0
F0085E74: 808a4008                 btst    %o0, %o1
F0085E78: 02800006                 be      loc_F0085E90
F0085E7C: 90100011                 mov     %l1, %o0
F0085E80: e2042010                 ld      [%l0+0x10], %l1
F0085E84: 7fff8c6c                 call    _lock_done
F0085E88: e2260000                 st      %l1, [%i0]
F0085E8C: 30bfffd6                 ba,a    loc_F0085DE4
F0085E90: ea04201c                 ld      [%l0+0x1C], %l5
F0085E94: 900e8015                 and     %i2, %l5, %o0
F0085E98: 80a2001a                 cmp     %o0, %i2
F0085E9C: 22800006                 be,a    loc_F0085EB4
F0085EA0: d0142028                 lduh    [%l0+0x28], %o0
F0085EA4: 7fff8c64                 call    _lock_done
F0085EA8: 90100011                 mov     %l1, %o0
F0085EAC: 10800070                 ba      locret_F008606C
F0085EB0: b0102002                 mov     2, %i0
F0085EB4: 80a00008                 cmp     %g0, %o0
F0085EB8: 90402000                 addc    %g0, 0, %o0
F0085EBC: 80a22000                 cmp     %o0, 0
F0085EC0: 02800004                 be      loc_F0085ED0
F0085EC4: d0258000                 st      %o0, [%l6]
F0085EC8: ea04201c                 ld      [%l0+0x1C], %l5
F0085ECC: b4100015                 mov     %l5, %i2
F0085ED0: d0042018                 ld      [%l0+0x18], %o0
F0085ED4: a732201f                 srl     %o0, 31, %l3
F0085ED8: a69ce001                 xorcc   %l3, 1, %l3
F0085EDC: 02800004                 be      loc_F0085EEC
F0085EE0: a4100011                 mov     %l1, %l2
F0085EE4: 10800016                 ba      loc_F0085F3C
F0085EE8: a8100019                 mov     %i1, %l4
F0085EEC: e4042010                 ld      [%l0+0x10], %l2
F0085EF0: d0042008                 ld      [%l0+8], %o0
F0085EF4: d2042014                 ld      [%l0+0x14], %o1
F0085EF8: 90264008                 sub     %i1, %o0, %o0
F0085EFC: a8020009                 add     %o0, %o1, %l4
F0085F00: 7fff8c7d                 call    _lock_read
F0085F04: 90100012                 mov     %l2, %o0
F0085F08: 90100012                 mov     %l2, %o0
F0085F0C: 92100014                 mov     %l4, %o1
F0085F10: 7ffff966                 call    _vm_map_lookup_entry
F0085F14: 9407bff0                 add     %fp, var_10, %o2
F0085F18: 80a22000                 cmp     %o0, 0
F0085F1C: 12800008                 bne     loc_F0085F3C
F0085F20: e007bff0                 ld      [%fp+var_10], %l0
F0085F24: 7fff8c44                 call    _lock_done
F0085F28: 90100012                 mov     %l2, %o0
F0085F2C: 7fff8c42                 call    _lock_done
F0085F30: 90100011                 mov     %l1, %o0
F0085F34: 1080004e                 ba      locret_F008606C
F0085F38: b0102001                 mov     1, %i0
F0085F3C: d2042018                 ld      [%l0+0x18], %o1
F0085F40: 11008000                 sethi   0x2000000, %o0
F0085F44: 808a4008                 btst    %o0, %o1
F0085F48: 02800017                 be      loc_F0085FA4
F0085F4C: 808ea002                 btst    2, %i2
F0085F50: 22800015                 be,a    loc_F0085FA4
F0085F54: aa0d7ffd                 and     %l5, -3, %l5
F0085F58: 7fff8cbd                 call    _lock_read_to_write
F0085F5C: 90100012                 mov     %l2, %o0
F0085F60: 80a22000                 cmp     %o0, 0
F0085F64: 12800019                 bne     loc_F0085FC8
F0085F68: 80a48011                 cmp     %l2, %l1
F0085F6C: d604200c                 ld      [%l0+0xC], %o3
F0085F70: 90042010                 add     %l0, 0x10, %o0
F0085F74: d4042008                 ld      [%l0+8], %o2
F0085F78: 92042014                 add     %l0, 0x14, %o1
F0085F7C: 400004d6                 call    _vm_object_shadow
F0085F80: 9422c00a                 sub     %o3, %o2, %o2
F0085F84: 90100012                 mov     %l2, %o0
F0085F88: d4042018                 ld      [%l0+0x18], %o2
F0085F8C: 13008000                 sethi   0x2000000, %o1
F0085F90: 922a8009                 andn    %o2, %o1, %o1
F0085F94: 7fff8d20                 call    _lock_write_to_read
F0085F98: d2242018                 st      %o1, [%l0+0x18]
F0085F9C: 10800003                 ba      loc_F0085FA8
F0085FA0: d0042010                 ld      [%l0+0x10], %o0
F0085FA4: d0042010                 ld      [%l0+0x10], %o0
F0085FA8: 80a22000                 cmp     %o0, 0
F0085FAC: 32800015                 bne,a   loc_F0086000
F0085FB0: d0042008                 ld      [%l0+8], %o0
F0085FB4: 7fff8ca6                 call    _lock_read_to_write
F0085FB8: 90100012                 mov     %l2, %o0
F0085FBC: 80a22000                 cmp     %o0, 0
F0085FC0: 02800007                 be      loc_F0085FDC
F0085FC4: 80a48011                 cmp     %l2, %l1
F0085FC8: 02bfff87                 be      loc_F0085DE4
F0085FCC: 01000000                 nop
F0085FD0: 7fff8c19                 call    _lock_done
F0085FD4: 90100011                 mov     %l1, %o0
F0085FD8: 30bfff83                 ba,a    loc_F0085DE4
F0085FDC: d204200c                 ld      [%l0+0xC], %o1
F0085FE0: d0042008                 ld      [%l0+8], %o0
F0085FE4: 400001ef                 call    _vm_object_allocate
F0085FE8: 90224008                 sub     %o1, %o0, %o0
F0085FEC: d0242010                 st      %o0, [%l0+0x10]
F0085FF0: c0242014                 clr     [%l0+0x14]
F0085FF4: 7fff8d08                 call    _lock_write_to_read
F0085FF8: 90100012                 mov     %l2, %o0
F0085FFC: d0042008                 ld      [%l0+8], %o0
F0086000: d2042014                 ld      [%l0+0x14], %o1
F0086004: 90250008                 sub     %l4, %o0, %o0
F0086008: 90020009                 add     %o0, %o1, %o0
F008600C: d0274000                 st      %o0, [%i5]
F0086010: d0042010                 ld      [%l0+0x10], %o0
F0086014: 80a4e000                 cmp     %l3, 0
F0086018: 12800011                 bne     loc_F008605C
F008601C: d0270000                 st      %o0, [%i4]
F0086020: a004a034                 add     %l2, 0x34, %l0 ! '4'
F0086024: d0040000                 ld      [%l0], %o0
F0086028: 80a22000                 cmp     %o0, 0
F008602C: 12bffffe                 bne     loc_F0086024
F0086030: 01000000                 nop
F0086034: 4000439d                 call    _simple_lock_try
F0086038: 90100010                 mov     %l0, %o0
F008603C: 80a22000                 cmp     %o0, 0
F0086040: 02bffff9                 be      loc_F0086024
F0086044: 01000000                 nop
F0086048: d004a030                 ld      [%l2+0x30], %o0
F008604C: c024a034                 clr     [%l2+0x34]
F0086050: 901a2001                 btog    1, %o0
F0086054: 80a00008                 cmp     %g0, %o0
F0086058: a6603fff                 subc    %g0, -1, %l3
F008605C: ea25c000                 st      %l5, [%l7]
F0086060: d807a064                 ld      [%fp+arg_64], %o4
F0086064: b0102000                 mov     0, %i0
F0086068: e6230000                 st      %l3, [%o4]
F008606C: 81c7e008                 ret
F0086070: 81e80000                 restore
