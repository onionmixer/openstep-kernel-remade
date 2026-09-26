F0072E5C: 9de3bf88                 save    %sp, -0x78, %sp
F0072E60: 90100018                 mov     %i0, %o0! target_task
F0072E64: 92102000                 mov     0, %o1! ledgers
F0072E68: 4000001c                 call    _task_create
F0072E6C: 9407bff4                 add     %fp, var_C, %o2
F0072E70: 4000008e                 call    _task_deallocate
F0072E74: d007bff4                 ld      [%fp+var_C], %o0
F0072E78: d007bff4                 ld      [%fp+var_C], %o0
F0072E7C: 400044e4                 call    _vm_map_deallocate
F0072E80: d002200c                 ld      [%o0+0xC], %o0
F0072E84: 80a66000                 cmp     %i1, 0
F0072E88: 12800007                 bne     loc_F0072EA4
F0072E8C: 9207bff0                 add     %fp, var_10, %o1
F0072E90: d007bff4                 ld      [%fp+var_C], %o0
F0072E94: 133c04d1                 sethi   %hi(_kernel_map), %o1
F0072E98: d2026340                 ld      [%o1+%lo(_kernel_map)], %o1
F0072E9C: 1080000a                 ba      loc_F0072EC4
F0072EA0: d222200c                 st      %o1, [%o0+0xC]
F0072EA4: 9407bfec                 add     %fp, var_14, %o2
F0072EA8: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0072EAC: 96100019                 mov     %i1, %o3
F0072EB0: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F0072EB4: 400042c7                 call    _kmem_suballoc
F0072EB8: 98102000                 mov     0, %o4
F0072EBC: d207bff4                 ld      [%fp+var_C], %o1
F0072EC0: d022600c                 st      %o0, [%o1+0xC]
F0072EC4: f007bff4                 ld      [%fp+var_C], %i0
F0072EC8: 90102001                 mov     1, %o0
F0072ECC: d0262050                 st      %o0, [%i0+0x50]
F0072ED0: 81c7e008                 ret
F0072ED4: 81e80000                 restore
