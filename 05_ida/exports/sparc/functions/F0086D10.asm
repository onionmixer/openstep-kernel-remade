F0086D10: 9de3bf98                 save    %sp, -0x68, %sp
F0086D14: e0060000                 ld      [%i0], %l0
F0086D18: 80a60010                 cmp     %i0, %l0
F0086D1C: 02800019                 be      locret_F0086D80
F0086D20: 273c04f0                 sethi   %hi(_vm_page_queue_lock), %l3
F0086D24: a214e230                 or      %l3, %lo(_vm_page_queue_lock), %l1
F0086D28: 29000020                 sethi   0x8000, %l4
F0086D2C: e4042008                 ld      [%l0+8], %l2
F0086D30: d0044000                 ld      [%l1], %o0
F0086D34: 80a22000                 cmp     %o0, 0
F0086D38: 12bffffe                 bne     loc_F0086D30
F0086D3C: 01000000                 nop
F0086D40: 4000405a                 call    _simple_lock_try
F0086D44: 90100011                 mov     %l1, %o0
F0086D48: 80a22000                 cmp     %o0, 0
F0086D4C: 02bffff9                 be      loc_F0086D30
F0086D50: 01000000                 nop
F0086D54: d004201c                 ld      [%l0+0x1C], %o0
F0086D58: 808a0014                 btst    %l4, %o0
F0086D5C: 12800004                 bne     loc_F0086D6C
F0086D60: 01000000                 nop
F0086D64: 40000a5e                 call    _vm_page_deactivate
F0086D68: 90100010                 mov     %l0, %o0
F0086D6C: c024e230                 clr     [%l3+0x230]
F0086D70: a0100012                 mov     %l2, %l0
F0086D74: 80a60010                 cmp     %i0, %l0
F0086D78: 32bfffee                 bne,a   loc_F0086D30
F0086D7C: e4042008                 ld      [%l0+8], %l2
F0086D80: 81c7e008                 ret
F0086D84: 81e80000                 restore
