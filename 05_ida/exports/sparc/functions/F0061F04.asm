F0061F04: 9de3bf80                 save    %sp, -0x80, %sp
F0061F08: 80a62000                 cmp     %i0, 0
F0061F0C: 12800004                 bne     loc_F0061F1C
F0061F10: ba100019                 mov     %i1, %i5
F0061F14: 108000cb                 ba      locret_F0062240
F0061F18: b0102010                 mov     0x10, %i0
F0061F1C: a4102000                 mov     0, %l2
F0061F20: a6062008                 add     %i0, 8, %l3
F0061F24: 293c04ef                 sethi   -0xFEC4400, %l4
F0061F28: d004c000                 ld      [%l3], %o0
F0061F2C: 80a22000                 cmp     %o0, 0
F0061F30: 12bffffe                 bne     loc_F0061F28
F0061F34: 01000000                 nop
F0061F38: 4000d3dc                 call    _simple_lock_try
F0061F3C: 90100013                 mov     %l3, %o0
F0061F40: 80a22000                 cmp     %o0, 0
F0061F44: 02bffff9                 be      loc_F0061F28
F0061F48: 01000000                 nop
F0061F4C: d006200c                 ld      [%i0+0xC], %o0
F0061F50: 80a22000                 cmp     %o0, 0
F0061F54: 3280000f                 bne,a   loc_F0061F90
F0061F58: d0062018                 ld      [%i0+0x18], %o0
F0061F5C: c0262008                 clr     [%i0+8]
F0061F60: 80a4a000                 cmp     %l2, 0
F0061F64: 02bfffec                 be      loc_F0061F14
F0061F68: d00522f8                 ld      [%l4+0x2F8], %o0
F0061F6C: d207bff4                 ld      [%fp+var_C], %o1
F0061F70: 40008645                 call    _kmem_free
F0061F74: 94100012                 mov     %l2, %o2
F0061F78: d00522f8                 ld      [%l4+0x2F8], %o0
F0061F7C: d207bff0                 ld      [%fp+var_10], %o1
F0061F80: 40008641                 call    _kmem_free
F0061F84: 94100012                 mov     %l2, %o2
F0061F88: 108000ae                 ba      locret_F0062240
F0061F8C: b0102010                 mov     0x10, %i0
F0061F90: d2062038                 ld      [%i0+0x38], %o1
F0061F94: 90020009                 add     %o0, %o1, %o0
F0061F98: 133c04d0                 sethi   %hi(_page_mask), %o1
F0061F9C: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F0061FA0: 912a2002                 sll     %o0, 2, %o0
F0061FA4: 90020009                 add     %o0, %o1, %o0
F0061FA8: a22a0009                 andn    %o0, %o1, %l1
F0061FAC: 80a44012                 cmp     %l1, %l2
F0061FB0: 08800028                 bleu    loc_F0062050
F0061FB4: ec07bff4                 ld      [%fp+var_C], %l6
F0061FB8: c0262008                 clr     [%i0+8]
F0061FBC: 80a4a000                 cmp     %l2, 0
F0061FC0: 0280000a                 be      loc_F0061FE8
F0061FC4: 213c04ef                 sethi   %hi(_ipc_kernel_map), %l0
F0061FC8: d00422f8                 ld      [%l0+%lo(_ipc_kernel_map)], %o0
F0061FCC: d207bff4                 ld      [%fp+var_C], %o1
F0061FD0: 4000862d                 call    _kmem_free
F0061FD4: 94100012                 mov     %l2, %o2
F0061FD8: d00422f8                 ld      [%l0+%lo(_ipc_kernel_map)], %o0
F0061FDC: d207bff0                 ld      [%fp+var_10], %o1
F0061FE0: 40008629                 call    _kmem_free
F0061FE4: 94100012                 mov     %l2, %o2
F0061FE8: a4100011                 mov     %l1, %l2
F0061FEC: d00522f8                 ld      [%l4+0x2F8], %o0! target_task
F0061FF0: 9207bff4                 add     %fp, var_C, %o1! address
F0061FF4: 94100012                 mov     %l2, %o2! size
F0061FF8: 4000a20a                 call    _vm_allocate
F0061FFC: 96102001                 mov     1, %o3! flags
F0062000: 80a22000                 cmp     %o0, 0
F0062004: 12800058                 bne     loc_F0062164
F0062008: d00522f8                 ld      [%l4+0x2F8], %o0! target_task
F006200C: 9207bff0                 add     %fp, var_10, %o1! address
F0062010: 94100012                 mov     %l2, %o2! size
F0062014: 4000a203                 call    _vm_allocate
F0062018: 96102001                 mov     1, %o3
F006201C: 80a22000                 cmp     %o0, 0
F0062020: 1280004e                 bne     loc_F0062158
F0062024: d207bff4                 ld      [%fp+var_C], %o1
F0062028: 96102000                 mov     0, %o3
F006202C: d00522f8                 ld      [%l4+0x2F8], %o0
F0062030: 40008b6f                 call    _vm_map_pageable
F0062034: 94024012                 add     %o1, %l2, %o2
F0062038: d207bff0                 ld      [%fp+var_10], %o1
F006203C: 96102000                 mov     0, %o3
F0062040: d00522f8                 ld      [%l4+0x2F8], %o0
F0062044: 40008b6a                 call    _vm_map_pageable
F0062048: 94024012                 add     %o1, %l2, %o2
F006204C: 30bfffb7                 ba,a    loc_F0061F28
F0062050: ea07bff0                 ld      [%fp+var_10], %l5
F0062054: 7fffe11b                 call    _ipc_port_timestamp
F0062058: c027bfec                 clr     [%fp+var_14]
F006205C: a2102000                 mov     0, %l1
F0062060: e6062018                 ld      [%i0+0x18], %l3
F0062064: a8100008                 mov     %o0, %l4
F0062068: 80a44013                 cmp     %l1, %l3
F006206C: 1a800017                 bcc     loc_F00620C8
F0062070: d2062014                 ld      [%i0+0x14], %o1
F0062074: 330007c0                 sethi   0x1F0000, %i1
F0062078: 2f3fc000                 sethi   -0x1000000, %l7
F006207C: a0100009                 mov     %o1, %l0
F0062080: d4040000                 ld      [%l0], %o2
F0062084: 808a8019                 btst    %i1, %o2
F0062088: 2280000d                 be,a    loc_F00620BC
F006208C: a2046001                 inc     %l1
F0062090: 90100014                 mov     %l4, %o0
F0062094: 92100010                 mov     %l0, %o1
F0062098: 972c6008                 sll     %l1, 8, %o3
F006209C: 940a8017                 and     %o2, %l7, %o2
F00620A0: 9532a018                 srl     %o2, 24, %o2
F00620A4: 9412c00a                 bset    %o3, %o2
F00620A8: 96100016                 mov     %l6, %o3
F00620AC: 98100015                 mov     %l5, %o4
F00620B0: 7fffff59                 call    _mach_port_names_helper
F00620B4: 9a07bfec                 add     %fp, var_14, %o5
F00620B8: a2046001                 inc     %l1
F00620BC: 80a44013                 cmp     %l1, %l3
F00620C0: 0abffff0                 bcs     loc_F0062080
F00620C4: a0042010                 inc     0x10, %l0
F00620C8: 7ffff202                 call    _ipc_splay_traverse_start
F00620CC: 90062020                 add     %i0, 0x20, %o0 ! ' '
F00620D0: 1080000b                 ba      loc_F00620FC
F00620D4: 92100008                 mov     %o0, %o1
F00620D8: d4026010                 ld      [%o1+0x10], %o2
F00620DC: 96100016                 mov     %l6, %o3
F00620E0: 98100015                 mov     %l5, %o4
F00620E4: 7fffff4c                 call    _mach_port_names_helper
F00620E8: 9a07bfec                 add     %fp, var_14, %o5
F00620EC: 90062020                 add     %i0, 0x20, %o0 ! ' '
F00620F0: 7ffff213                 call    _ipc_splay_traverse_next
F00620F4: 92102000                 mov     0, %o1
F00620F8: 92100008                 mov     %o0, %o1
F00620FC: 80a26000                 cmp     %o1, 0
F0062100: 12bffff6                 bne     loc_F00620D8
F0062104: 90100014                 mov     %l4, %o0
F0062108: 7ffff28b                 call    _ipc_splay_traverse_finish
F006210C: 90062020                 add     %i0, 0x20, %o0 ! ' '
F0062110: da07bfec                 ld      [%fp+var_14], %o5
F0062114: c0262008                 clr     [%i0+8]
F0062118: 80a36000                 cmp     %o5, 0
F006211C: 12800014                 bne     loc_F006216C
F0062120: 96102001                 mov     1, %o3
F0062124: c027bfe8                 clr     [%fp+var_18]
F0062128: 80a4a000                 cmp     %l2, 0
F006212C: 0280003c                 be      loc_F006221C
F0062130: c027bfe4                 clr     [%fp+var_1C]
F0062134: 213c04ef                 sethi   %hi(_ipc_kernel_map), %l0
F0062138: d00422f8                 ld      [%l0+%lo(_ipc_kernel_map)], %o0
F006213C: d207bff4                 ld      [%fp+var_C], %o1
F0062140: 400085d1                 call    _kmem_free
F0062144: 94100012                 mov     %l2, %o2
F0062148: d00422f8                 ld      [%l0+%lo(_ipc_kernel_map)], %o0
F006214C: d207bff0                 ld      [%fp+var_10], %o1
F0062150: 10800031                 ba      loc_F0062214
F0062154: 94100012                 mov     %l2, %o2
F0062158: d00522f8                 ld      [%l4+0x2F8], %o0
F006215C: 400085ca                 call    _kmem_free
F0062160: 94100012                 mov     %l2, %o2
F0062164: 10800037                 ba      locret_F0062240
F0062168: b0102006                 mov     6, %i0
F006216C: d207bff4                 ld      [%fp+var_C], %o1
F0062170: 153c04d0                 sethi   %hi(_page_mask), %o2
F0062174: d802a0d8                 ld      [%o2+%lo(_page_mask)], %o4
F0062178: 273c04ef                 sethi   %hi(_ipc_kernel_map), %l3
F006217C: d004e2f8                 ld      [%l3+%lo(_ipc_kernel_map)], %o0
F0062180: 952b6002                 sll     %o5, 2, %o2
F0062184: 9402800c                 add     %o2, %o4, %o2
F0062188: a22a800c                 andn    %o2, %o4, %l1
F006218C: 40008b18                 call    _vm_map_pageable
F0062190: 94024011                 add     %o1, %l1, %o2
F0062194: d207bff0                 ld      [%fp+var_10], %o1
F0062198: 96102001                 mov     1, %o3
F006219C: d004e2f8                 ld      [%l3+%lo(_ipc_kernel_map)], %o0
F00621A0: 40008b13                 call    _vm_map_pageable
F00621A4: 94024011                 add     %o1, %l1, %o2
F00621A8: 96100011                 mov     %l1, %o3
F00621AC: d004e2f8                 ld      [%l3+%lo(_ipc_kernel_map)], %o0
F00621B0: 98102001                 mov     1, %o4
F00621B4: d207bff4                 ld      [%fp+var_C], %o1
F00621B8: 213c04ef                 sethi   %hi(_ipc_soft_map), %l0
F00621BC: d4042320                 ld      [%l0+%lo(_ipc_soft_map)], %o2
F00621C0: 4000902e                 call    _vm_move
F00621C4: 9a07bfe8                 add     %fp, var_18, %o5
F00621C8: d004e2f8                 ld      [%l3+0x2F8], %o0
F00621CC: 96100011                 mov     %l1, %o3
F00621D0: d207bff0                 ld      [%fp+var_10], %o1
F00621D4: 98102001                 mov     1, %o4
F00621D8: d4042320                 ld      [%l0+%lo(_ipc_soft_map)], %o2
F00621DC: 40009027                 call    _vm_move
F00621E0: 9a07bfe4                 add     %fp, var_1C, %o5
F00621E4: 80a44012                 cmp     %l1, %l2
F00621E8: 0280000d                 be      loc_F006221C
F00621EC: a0248011                 sub     %l2, %l1, %l0
F00621F0: d207bff4                 ld      [%fp+var_C], %o1
F00621F4: 94100010                 mov     %l0, %o2
F00621F8: d004e2f8                 ld      [%l3+0x2F8], %o0
F00621FC: 400085a2                 call    _kmem_free
F0062200: 92024011                 add     %o1, %l1, %o1
F0062204: d207bff0                 ld      [%fp+var_10], %o1
F0062208: 94100010                 mov     %l0, %o2
F006220C: d004e2f8                 ld      [%l3+0x2F8], %o0
F0062210: 92024011                 add     %o1, %l1, %o1
F0062214: 4000859c                 call    _kmem_free
F0062218: 01000000                 nop
F006221C: d007bfe8                 ld      [%fp+var_18], %o0
F0062220: d0274000                 st      %o0, [%i5]
F0062224: d007bfec                 ld      [%fp+var_14], %o0
F0062228: d0268000                 st      %o0, [%i2]
F006222C: d007bfe4                 ld      [%fp+var_1C], %o0
F0062230: d026c000                 st      %o0, [%i3]
F0062234: d007bfec                 ld      [%fp+var_14], %o0
F0062238: b0102000                 mov     0, %i0
F006223C: d0270000                 st      %o0, [%i4]
F0062240: 81c7e008                 ret
F0062244: 81e80000                 restore
