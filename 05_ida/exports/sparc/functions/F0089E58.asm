F0089E58: 9de3bf98                 save    %sp, -0x68, %sp
F0089E5C: 80a6a000                 cmp     %i2, 0
F0089E60: 02800022                 be      loc_F0089EE8
F0089E64: 193c04d0                 sethi   %hi(_page_mask), %o4
F0089E68: 113c04d0                 sethi   %hi(_active_threads), %o0
F0089E6C: d20320d8                 ld      [%o4+%lo(_page_mask)], %o1
F0089E70: 96060019                 add     %i0, %i1, %o3
F0089E74: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0089E78: 94380009                 xnor    %g0, %o1, %o2
F0089E7C: b40e000a                 and     %i0, %o2, %i2
F0089E80: d002200c                 ld      [%o0+0xC], %o0
F0089E84: 9202c009                 add     %o3, %o1, %o1
F0089E88: d002200c                 ld      [%o0+0xC], %o0
F0089E8C: 920a400a                 and     %o1, %o2, %o1
F0089E90: 80a68009                 cmp     %i2, %o1
F0089E94: 1a800015                 bcc     loc_F0089EE8
F0089E98: e2022024                 ld      [%o0+0x24], %l1
F0089E9C: 273c0447                 sethi   -0xFEEE400, %l3
F0089EA0: a010000b                 mov     %o3, %l0
F0089EA4: a410000c                 mov     %o4, %l2
F0089EA8: 90100011                 mov     %l1, %o0
F0089EAC: 4000542b                 call    _pmap_extract
F0089EB0: 9210001a                 mov     %i2, %o1
F0089EB4: 7ffff166                 call    _vm_phys_to_vm_page
F0089EB8: 01000000                 nop
F0089EBC: d202201c                 ld      [%o0+0x1C], %o1
F0089EC0: d404e13c                 ld      [%l3+0x13C], %o2
F0089EC4: 920a7bff                 and     %o1, -0x401, %o1
F0089EC8: d222201c                 st      %o1, [%o0+0x1C]
F0089ECC: d204a0d8                 ld      [%l2+0xD8], %o1
F0089ED0: b406800a                 add     %i2, %o2, %i2
F0089ED4: 90040009                 add     %l0, %o1, %o0
F0089ED8: 922a0009                 andn    %o0, %o1, %o1
F0089EDC: 80a68009                 cmp     %i2, %o1
F0089EE0: 0abffff3                 bcs     loc_F0089EAC
F0089EE4: 90100011                 mov     %l1, %o0
F0089EE8: 113c04d0                 sethi   %hi(_page_mask), %o0
F0089EEC: d80220d8                 ld      [%o0+%lo(_page_mask)], %o4
F0089EF0: 94060019                 add     %i0, %i1, %o2
F0089EF4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0089EF8: 9638000c                 xnor    %g0, %o4, %o3
F0089EFC: 920e000b                 and     %i0, %o3, %o1
F0089F00: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0089F04: 9402800c                 add     %o2, %o4, %o2
F0089F08: d002200c                 ld      [%o0+0xC], %o0
F0089F0C: 940a800b                 and     %o2, %o3, %o2
F0089F10: d002200c                 ld      [%o0+0xC], %o0
F0089F14: 7fffebb6                 call    _vm_map_pageable
F0089F18: 96102001                 mov     1, %o3
F0089F1C: 81c7e008                 ret
F0089F20: 81e80000                 restore
