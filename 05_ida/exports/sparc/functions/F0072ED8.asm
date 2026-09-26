F0072ED8: 9de3bf98                 save    %sp, -0x68, %sp
F0072EDC: 113c04f2                 sethi   %hi(_task_zone), %o0
F0072EE0: 4000187b                 call    _zalloc
F0072EE4: d0022158                 ld      [%o0+%lo(_task_zone)], %o0
F0072EE8: a0920000                 orcc    %o0, %g0, %l0
F0072EEC: 32800006                 bne,a   loc_F0072F04
F0072EF0: 113c04d3                 sethi   -0xFECB400, %o0
F0072EF4: 113c0442                 sethi   %hi(aTaskCreateNoMe), %o0! "task_create: no memory for task structu"...
F0072EF8: 7ffe889e                 call    _panic
F0072EFC: 90122260                 bset    %lo(aTaskCreateNoMe), %o0! "task_create: no memory for task structu"...
F0072F00: 113c04d3                 sethi   -0xFECB400, %o0
F0072F04: 40001872                 call    _zalloc
F0072F08: d0022288                 ld      [%o0+0x288], %o0
F0072F0C: d0242038                 st      %o0, [%l0+0x38]
F0072F10: 7ffe6bb6                 call    _utask_zero
F0072F14: 90100010                 mov     %l0, %o0
F0072F18: 90102002                 mov     2, %o0
F0072F1C: d0242004                 st      %o0, [%l0+4]
F0072F20: 113c044290122250         set     _kernel_task, %o0
F0072F28: 80a68008                 cmp     %i2, %o0
F0072F2C: 12800005                 bne     loc_F0072F40
F0072F30: 80a66000                 cmp     %i1, 0
F0072F34: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0072F38: 10800012                 ba      loc_F0072F80
F0072F3C: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0072F40: 02800006                 be      loc_F0072F58
F0072F44: 01000000                 nop
F0072F48: 40004ad0                 call    _vm_map_fork
F0072F4C: d006200c                 ld      [%i0+0xC], %o0
F0072F50: 1080000d                 ba      loc_F0072F84
F0072F54: d024200c                 st      %o0, [%l0+0xC]
F0072F58: 4000a61a                 call    _pmap_create
F0072F5C: 90102000                 mov     0, %o0
F0072F60: 133c04d0                 sethi   %hi(_page_mask), %o1
F0072F64: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F0072F68: 153c0000                 sethi   -0x10000000, %o2
F0072F6C: 96380009                 xnor    %g0, %o1, %o3
F0072F70: 920a400b                 and     %o1, %o3, %o1
F0072F74: 940ac00a                 and     %o3, %o2, %o2
F0072F78: 4000444e                 call    _vm_map_create
F0072F7C: 96102001                 mov     1, %o3
F0072F80: d024200c                 st      %o0, [%l0+0xC]
F0072F84: c0240000                 clr     [%l0]
F0072F88: 9004201c                 add     %l0, 0x1C, %o0
F0072F8C: d0242020                 st      %o0, [%l0+0x20]
F0072F90: d024201c                 st      %o0, [%l0+0x1C]
F0072F94: c0242028                 clr     [%l0+0x28]
F0072F98: c0242018                 clr     [%l0+0x18]
F0072F9C: 90102001                 mov     1, %o0
F0072FA0: d0242008                 st      %o0, [%l0+8]
F0072FA4: c0242044                 clr     [%l0+0x44]
F0072FA8: c0242024                 clr     [%l0+0x24]
F0072FAC: c0242040                 clr     [%l0+0x40]
F0072FB0: c0242050                 clr     [%l0+0x50]
F0072FB4: 90100010                 mov     %l0, %o0
F0072FB8: 7fffcebf                 call    _ipc_task_init
F0072FBC: 92100018                 mov     %i0, %o1
F0072FC0: c0242054                 clr     [%l0+0x54]
F0072FC4: c0242058                 clr     [%l0+0x58]
F0072FC8: c024205c                 clr     [%l0+0x5C]
F0072FCC: 80a62000                 cmp     %i0, 0
F0072FD0: 0280001a                 be      loc_F0073038
F0072FD4: c0242060                 clr     [%l0+0x60]
F0072FD8: d006204c                 ld      [%i0+0x4C], %o0
F0072FDC: d024204c                 st      %o0, [%l0+0x4C]
F0072FE0: d0060000                 ld      [%i0], %o0
F0072FE4: 80a22000                 cmp     %o0, 0
F0072FE8: 12bffffe                 bne     loc_F0072FE0
F0072FEC: 01000000                 nop
F0072FF0: 40008fae                 call    _simple_lock_try
F0072FF4: 90100018                 mov     %i0, %o0
F0072FF8: 80a22000                 cmp     %o0, 0
F0072FFC: 02bffff9                 be      loc_F0072FE0
F0073000: 01000000                 nop
F0073004: f206202c                 ld      [%i0+0x2C], %i1
F0073008: d0066154                 ld      [%i1+0x154], %o0
F007300C: 80a22000                 cmp     %o0, 0
F0073010: 12800003                 bne     loc_F007301C
F0073014: 113c04d3                 sethi   %hi(_default_pset), %o0
F0073018: b21223c0                 or      %o0, %lo(_default_pset), %i1
F007301C: 7ffff060                 call    _pset_reference
F0073020: 90100019                 mov     %i1, %o0
F0073024: d0062048                 ld      [%i0+0x48], %o0
F0073028: d0242048                 st      %o0, [%l0+0x48]
F007302C: c0260000                 clr     [%i0]
F0073030: 1080000a                 ba      loc_F0073058
F0073034: b0066158                 add     %i1, 0x158, %i0
F0073038: c024204c                 clr     [%l0+0x4C]
F007303C: 113c04d3b21223c0         set     _default_pset, %i1
F0073044: 7ffff056                 call    _pset_reference
F0073048: 90100019                 mov     %i1, %o0
F007304C: 9010200a                 mov     0xA, %o0
F0073050: d0242048                 st      %o0, [%l0+0x48]
F0073054: b0066158                 add     %i1, 0x158, %i0
F0073058: d0060000                 ld      [%i0], %o0
F007305C: 80a22000                 cmp     %o0, 0
F0073060: 12bffffe                 bne     loc_F0073058
F0073064: 01000000                 nop
F0073068: 40008f90                 call    _simple_lock_try
F007306C: 90100018                 mov     %i0, %o0
F0073070: 80a22000                 cmp     %o0, 0
F0073074: 02bffff9                 be      loc_F0073058
F0073078: 90100019                 mov     %i1, %o0
F007307C: 7fffefd8                 call    _pset_add_task
F0073080: 92100010                 mov     %l0, %o1
F0073084: c0266158                 clr     [%i1+0x158]
F0073088: 90102001                 mov     1, %o0
F007308C: d0242030                 st      %o0, [%l0+0x30]
F0073090: c0242034                 clr     [%l0+0x34]
F0073094: 7fffceca                 call    _ipc_task_enable
F0073098: 90100010                 mov     %l0, %o0
F007309C: e0268000                 st      %l0, [%i2]
F00730A0: 81c7e008                 ret
F00730A4: 91e82000                 restore %g0, 0, %o0
