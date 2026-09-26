F006CACC: 9de3bf98                 save    %sp, -0x68, %sp
F006CAD0: 253c04f0a214a210         set     _vm_info_lock_data, %l1
F006CAD8: 2b3c043f                 sethi   -0xFEF0400, %l5
F006CADC: 293c043f                 sethi   -0xFEF0400, %l4
F006CAE0: 273c04f0                 sethi   -0xFEC4000, %l3
F006CAE4: d0044000                 ld      [%l1], %o0
F006CAE8: 80a22000                 cmp     %o0, 0
F006CAEC: 12bffffe                 bne     loc_F006CAE4
F006CAF0: 01000000                 nop
F006CAF4: 4000a8ed                 call    _simple_lock_try
F006CAF8: 90100011                 mov     %l1, %o0
F006CAFC: 80a22000                 cmp     %o0, 0
F006CB00: 02bffff9                 be      loc_F006CAE4
F006CB04: d205612c                 ld      [%l5+0x12C], %o1
F006CB08: d0052128                 ld      [%l4+0x128], %o0
F006CB0C: 80a24008                 cmp     %o1, %o0
F006CB10: 04800009                 ble     loc_F006CB34
F006CB14: e004e218                 ld      [%l3+0x218], %l0
F006CB18: 7ffffdd9                 call    _vm_info_dequeue
F006CB1C: 90100010                 mov     %l0, %o0
F006CB20: c024a210                 clr     [%l2+0x210]
F006CB24: 90100010                 mov     %l0, %o0
F006CB28: 7fffffae                 call    _mfs_memfree
F006CB2C: 92102001                 mov     1, %o1
F006CB30: 30bfffed                 ba,a    loc_F006CAE4
F006CB34: 113c04f0                 sethi   %hi(_vm_info_lock_data), %o0
F006CB38: c0222210                 clr     [%o0+%lo(_vm_info_lock_data)]
F006CB3C: 81c7e008                 ret
F006CB40: 81e80000                 restore
