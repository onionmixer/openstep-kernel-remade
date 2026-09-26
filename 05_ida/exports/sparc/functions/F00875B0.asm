F00875B0: 9de3bf98                 save    %sp, -0x68, %sp
F00875B4: 113c04f5a0122000         set     _vm_cache_lock, %l0
F00875BC: d0040000                 ld      [%l0], %o0
F00875C0: 80a22000                 cmp     %o0, 0
F00875C4: 12bffffe                 bne     loc_F00875BC
F00875C8: 01000000                 nop
F00875CC: 40003e37                 call    _simple_lock_try
F00875D0: 90100010                 mov     %l0, %o0
F00875D4: 80a22000                 cmp     %o0, 0
F00875D8: 02bffff9                 be      loc_F00875BC
F00875DC: 133c04f5                 sethi   %hi(_vm_object_cached_list), %o1
F00875E0: d0026018                 ld      [%o1+%lo(_vm_object_cached_list)], %o0
F00875E4: 94126018                 or      %o1, %lo(_vm_object_cached_list), %o2
F00875E8: 80a2000a                 cmp     %o0, %o2
F00875EC: 02800022                 be      loc_F0087674
F00875F0: 113c04f5                 sethi   -0xFEC2C00, %o0
F00875F4: 233c04f5a8146000         set     _vm_cache_lock, %l4
F00875FC: 273c0447                 sethi   -0xFEEE400, %l3
F0087600: a410000a                 mov     %o2, %l2
F0087604: e0026018                 ld      [%o1+%lo(_vm_object_cached_list)], %l0
F0087608: c0246000                 clr     [%l1]
F008760C: 7fffff53                 call    _vm_object_lookup
F0087610: d0042028                 ld      [%l0+0x28], %o0
F0087614: 80a40008                 cmp     %l0, %o0
F0087618: 02800005                 be      loc_F008762C
F008761C: 90100010                 mov     %l0, %o0! char *
F0087620: 7ffe36d4                 call    _panic
F0087624: 9014e050                 or      %l3, 0x50, %o0
F0087628: 90100010                 mov     %l0, %o0
F008762C: 7ffffe0d                 call    _vm_object_cache_object
F0087630: 92102000                 mov     0, %o1
F0087634: a0100014                 mov     %l4, %l0
F0087638: d0040000                 ld      [%l0], %o0
F008763C: 80a22000                 cmp     %o0, 0
F0087640: 12bffffe                 bne     loc_F0087638
F0087644: 01000000                 nop
F0087648: 40003e18                 call    _simple_lock_try
F008764C: 90100010                 mov     %l0, %o0
F0087650: 80a22000                 cmp     %o0, 0
F0087654: 02bffff9                 be      loc_F0087638
F0087658: 01000000                 nop
F008765C: 133c04f5                 sethi   %hi(_vm_object_cached_list), %o1
F0087660: d0026018                 ld      [%o1+%lo(_vm_object_cached_list)], %o0
F0087664: 80a20012                 cmp     %o0, %l2
F0087668: 32bfffe8                 bne,a   loc_F0087608
F008766C: e0026018                 ld      [%o1+%lo(_vm_object_cached_list)], %l0
F0087670: 113c04f5                 sethi   -0xFEC2C00, %o0
F0087674: c0222000                 clr     [%o0]
F0087678: 81c7e008                 ret
F008767C: 81e80000                 restore
