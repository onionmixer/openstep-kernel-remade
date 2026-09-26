F0086F18: 9de3bf98                 save    %sp, -0x68, %sp
F0086F1C: 80a62000                 cmp     %i0, 0
F0086F20: 02800024                 be      locret_F0086FB0
F0086F24: a0062010                 add     %i0, 0x10, %l0
F0086F28: d0040000                 ld      [%l0], %o0
F0086F2C: 80a22000                 cmp     %o0, 0
F0086F30: 12bffffe                 bne     loc_F0086F28
F0086F34: 01000000                 nop
F0086F38: 40003fdc                 call    _simple_lock_try
F0086F3C: 90100010                 mov     %l0, %o0
F0086F40: 80a22000                 cmp     %o0, 0
F0086F44: 02bffff9                 be      loc_F0086F28
F0086F48: 01000000                 nop
F0086F4C: e0060000                 ld      [%i0], %l0
F0086F50: 80a60010                 cmp     %i0, %l0
F0086F54: 02800016                 be      loc_F0086FAC
F0086F58: 01000000                 nop
F0086F5C: 23000800                 sethi   0x200000, %l1
F0086F60: d0042018                 ld      [%l0+0x18], %o0
F0086F64: 80a64008                 cmp     %i1, %o0
F0086F68: 1880000d                 bgu     loc_F0086F9C
F0086F6C: 80a2001a                 cmp     %o0, %i2
F0086F70: 3a80000c                 bcc,a   loc_F0086FA0
F0086F74: e0042008                 ld      [%l0+8], %l0
F0086F78: d0042020                 ld      [%l0+0x20], %o0
F0086F7C: 808a0011                 btst    %l1, %o0
F0086F80: 32800008                 bne,a   loc_F0086FA0
F0086F84: e0042008                 ld      [%l0+8], %l0
F0086F88: 40005d8c                 call    _pmap_copy_on_write
F0086F8C: d0042024                 ld      [%l0+0x24], %o0
F0086F90: d0042020                 ld      [%l0+0x20], %o0
F0086F94: 90120011                 bset    %l1, %o0
F0086F98: d0242020                 st      %o0, [%l0+0x20]
F0086F9C: e0042008                 ld      [%l0+8], %l0
F0086FA0: 80a60010                 cmp     %i0, %l0
F0086FA4: 32bffff0                 bne,a   loc_F0086F64
F0086FA8: d0042018                 ld      [%l0+0x18], %o0
F0086FAC: c0262010                 clr     [%i0+0x10]
F0086FB0: 81c7e008                 ret
F0086FB4: 81e80000                 restore
