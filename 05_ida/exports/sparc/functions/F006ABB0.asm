F006ABB0: 9de3bf80                 save    %sp, -0x80, %sp
F006ABB4: d0062020                 ld      [%i0+0x20], %o0
F006ABB8: d2062024                 ld      [%i0+0x24], %o1
F006ABBC: 90020009                 add     %o0, %o1, %o0
F006ABC0: 80a2001b                 cmp     %o0, %i3
F006ABC4: 18800020                 bgu     loc_F006AC44
F006ABC8: e607a05c                 ld      [%fp+arg_5C], %l3
F006ABCC: d006201c                 ld      [%i0+0x1C], %o0
F006ABD0: 233c04d0                 sethi   %hi(_page_mask), %l1
F006ABD4: d20460d8                 ld      [%l1+%lo(_page_mask)], %o1
F006ABD8: 90020009                 add     %o0, %o1, %o0
F006ABDC: 86380009                 xnor    %g0, %o1, %g3
F006ABE0: a48a0003                 andcc   %o0, %g3, %l2
F006ABE4: 06800018                 bl      loc_F006AC44
F006ABE8: 80a4a000                 cmp     %l2, 0
F006ABEC: 02800096                 be      loc_F006AE44
F006ABF0: 9010001d                 mov     %i5, %o0
F006ABF4: 92102000                 mov     0, %o1
F006ABF8: 94102000                 mov     0, %o2
F006ABFC: 9607bff4                 add     %fp, var_C, %o3
F006AC00: 98100012                 mov     %l2, %o4
F006AC04: c4062018                 ld      [%i0+0x18], %g2
F006AC08: 9a102000                 mov     0, %o5
F006AC0C: 84088003                 and     %g2, %g3, %g2
F006AC10: 40006670                 call    _vm_map_find
F006AC14: c427bff4                 st      %g2, [%fp+var_C]
F006AC18: 80a22000                 cmp     %o0, 0
F006AC1C: 22800004                 be,a    loc_F006AC2C
F006AC20: d0062024                 ld      [%i0+0x24], %o0
F006AC24: 10800089                 ba      locret_F006AE48
F006AC28: b0102005                 mov     5, %i0
F006AC2C: d20460d8                 ld      [%l1+0xD8], %o1
F006AC30: d4062020                 ld      [%i0+0x20], %o2
F006AC34: 90020009                 add     %o0, %o1, %o0
F006AC38: b6aa0009                 andncc  %o0, %o1, %i3
F006AC3C: 16800004                 bge     loc_F006AC4C
F006AC40: b402801a                 add     %o2, %i2, %i2
F006AC44: 10800081                 ba      locret_F006AE48
F006AC48: b0102002                 mov     2, %i0
F006AC4C: 80a6e000                 cmp     %i3, 0
F006AC50: 24800068                 ble,a   loc_F006ADF0
F006AC54: d6062028                 ld      [%i0+0x28], %o3
F006AC58: 4000c6da                 call    _pmap_create
F006AC5C: 9010001b                 mov     %i3, %o0
F006AC60: 92102000                 mov     0, %o1
F006AC64: 9410001b                 mov     %i3, %o2
F006AC68: 40006512                 call    _vm_map_create
F006AC6C: 96102001                 mov     1, %o3
F006AC70: c027bff0                 clr     [%fp+var_10]
F006AC74: a0100008                 mov     %o0, %l0
F006AC78: 9207bff0                 add     %fp, var_10, %o1
F006AC7C: 9410001b                 mov     %i3, %o2
F006AC80: 96102000                 mov     0, %o3
F006AC84: 98100019                 mov     %i1, %o4
F006AC88: 40007ea7                 call    _vm_allocate_with_pager
F006AC8C: 9a10001a                 mov     %i2, %o5
F006AC90: 80a22000                 cmp     %o0, 0
F006AC94: 1280001a                 bne     loc_F006ACFC
F006AC98: 01000000                 nop
F006AC9C: c6062024                 ld      [%i0+0x24], %g3
F006ACA0: 80a6c003                 cmp     %i3, %g3
F006ACA4: 02800043                 be      loc_F006ADB0
F006ACA8: 80a72000                 cmp     %i4, 0
F006ACAC: 02800005                 be      loc_F006ACC0
F006ACB0: 90068003                 add     %i2, %g3, %o0
F006ACB4: 80a2001c                 cmp     %o0, %i4
F006ACB8: 0280003f                 be      loc_F006ADB4
F006ACBC: 9010001d                 mov     %i5, %o0
F006ACC0: c027bfec                 clr     [%fp+address]
F006ACC4: 92102000                 mov     0, %o1
F006ACC8: 94102000                 mov     0, %o2
F006ACCC: 9607bfec                 add     %fp, address, %o3
F006ACD0: 393c04d1                 sethi   %hi(_kernel_map), %i4
F006ACD4: c40460d8                 ld      [%l1+0xD8], %g2
F006ACD8: 9a102001                 mov     1, %o5
F006ACDC: d0072340                 ld      [%i4+%lo(_kernel_map)], %o0
F006ACE0: 233c0447                 sethi   %hi(_page_size), %l1
F006ACE4: d804613c                 ld      [%l1+%lo(_page_size)], %o4
F006ACE8: 4000663a                 call    _vm_map_find
F006ACEC: b428c002                 andn    %g3, %g2, %i2
F006ACF0: 80a22000                 cmp     %o0, 0
F006ACF4: 02800006                 be      loc_F006AD0C
F006ACF8: 92100010                 mov     %l0, %o1
F006ACFC: 40006544                 call    _vm_map_deallocate
F006AD00: 90100010                 mov     %l0, %o0
F006AD04: 10800051                 ba      locret_F006AE48
F006AD08: b0102005                 mov     5, %i0
F006AD0C: d407bfec                 ld      [%fp+address], %o2! size
F006AD10: 9810001a                 mov     %i2, %o4
F006AD14: d0072340                 ld      [%i4+0x340], %o0
F006AD18: 9a102000                 mov     0, %o5
F006AD1C: d604613c                 ld      [%l1+0x13C], %o3
F006AD20: 40006a44                 call    _vm_map_copy
F006AD24: c023a05c                 clr     [%sp+0x80+var_24]
F006AD28: 80a22000                 cmp     %o0, 0
F006AD2C: 02800006                 be      loc_F006AD44
F006AD30: d0072340                 ld      [%i4+0x340], %o0! target_task
F006AD34: d207bfec                 ld      [%fp+address], %o1! address
F006AD38: 40007eda                 call    _vm_deallocate
F006AD3C: d404613c                 ld      [%l1+0x13C], %o2
F006AD40: 30800018                 ba,a    loc_F006ADA0
F006AD44: d2062024                 ld      [%i0+0x24], %o1! size_t
F006AD48: d407bfec                 ld      [%fp+address], %o2
F006AD4C: 9022401a                 sub     %o1, %i2, %o0
F006AD50: 90028008                 add     %o2, %o0, %o0! void *
F006AD54: 4000a841                 call    _bzero
F006AD58: 9226c009                 sub     %i3, %o1, %o1
F006AD5C: d407bff4                 ld      [%fp+var_C], %o2
F006AD60: d807bfec                 ld      [%fp+address], %o4
F006AD64: 9010001d                 mov     %i5, %o0
F006AD68: d2072340                 ld      [%i4+0x340], %o1
F006AD6C: 9a102000                 mov     0, %o5
F006AD70: d604613c                 ld      [%l1+0x13C], %o3
F006AD74: c023a05c                 clr     [%sp+0x80+var_24]
F006AD78: 40006a2e                 call    _vm_map_copy
F006AD7C: 9402801a                 add     %o2, %i2, %o2! size
F006AD80: b2100008                 mov     %o0, %i1
F006AD84: d0072340                 ld      [%i4+0x340], %o0! target_task
F006AD88: d207bfec                 ld      [%fp+address], %o1! address
F006AD8C: 40007ec5                 call    _vm_deallocate
F006AD90: d404613c                 ld      [%l1+0x13C], %o2
F006AD94: 80a66000                 cmp     %i1, 0
F006AD98: 02800006                 be      loc_F006ADB0
F006AD9C: b610001a                 mov     %i2, %i3
F006ADA0: 4000651b                 call    _vm_map_deallocate
F006ADA4: 90100010                 mov     %l0, %o0
F006ADA8: 10800028                 ba      locret_F006AE48
F006ADAC: b0102004                 mov     4, %i0
F006ADB0: 9010001d                 mov     %i5, %o0
F006ADB4: 92100010                 mov     %l0, %o1
F006ADB8: d407bff4                 ld      [%fp+var_C], %o2
F006ADBC: 9610001b                 mov     %i3, %o3
F006ADC0: d807bff0                 ld      [%fp+var_10], %o4
F006ADC4: 9a102000                 mov     0, %o5
F006ADC8: 40006a1a                 call    _vm_map_copy
F006ADCC: c023a05c                 clr     [%sp+0x80+var_24]
F006ADD0: b2100008                 mov     %o0, %i1
F006ADD4: 4000650e                 call    _vm_map_deallocate
F006ADD8: 90100010                 mov     %l0, %o0
F006ADDC: 80a66000                 cmp     %i1, 0
F006ADE0: 22800004                 be,a    loc_F006ADF0
F006ADE4: d6062028                 ld      [%i0+0x28], %o3
F006ADE8: 10800018                 ba      locret_F006AE48
F006ADEC: b0102004                 mov     4, %i0
F006ADF0: 80a2e003                 cmp     %o3, 3
F006ADF4: 02800006                 be      loc_F006AE0C
F006ADF8: 9010001d                 mov     %i5, %o0
F006ADFC: d207bff4                 ld      [%fp+var_C], %o1
F006AE00: 98102001                 mov     1, %o4
F006AE04: 40006701                 call    _vm_map_protect
F006AE08: 94024012                 add     %o1, %l2, %o2
F006AE0C: d606202c                 ld      [%i0+0x2C], %o3
F006AE10: 80a2e003                 cmp     %o3, 3
F006AE14: 02800006                 be      loc_F006AE2C
F006AE18: 9010001d                 mov     %i5, %o0
F006AE1C: d207bff4                 ld      [%fp+var_C], %o1
F006AE20: 98102000                 mov     0, %o4
F006AE24: 400066f9                 call    _vm_map_protect
F006AE28: 94024012                 add     %o1, %l2, %o2
F006AE2C: d0062020                 ld      [%i0+0x20], %o0
F006AE30: 80a22000                 cmp     %o0, 0
F006AE34: 12800005                 bne     locret_F006AE48
F006AE38: b0102000                 mov     0, %i0
F006AE3C: d007bff4                 ld      [%fp+var_C], %o0
F006AE40: d024c000                 st      %o0, [%l3]
F006AE44: b0102000                 mov     0, %i0
F006AE48: 81c7e008                 ret
F006AE4C: 81e80000                 restore
