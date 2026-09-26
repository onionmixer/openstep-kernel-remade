F008A604: 9de3bf98                 save    %sp, -0x68, %sp
F008A608: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F008A60C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F008A610: 7ffe14d7                 call    _suser
F008A614: e2022024                 ld      [%o0+0x24], %l1
F008A618: 80a22000                 cmp     %o0, 0
F008A61C: 02800039                 be      locret_F008A700
F008A620: 113c04f6                 sethi   %hi(_gc_lock), %o0
F008A624: a0122190                 or      %o0, %lo(_gc_lock), %l0
F008A628: d0040000                 ld      [%l0], %o0
F008A62C: 80a22000                 cmp     %o0, 0
F008A630: 12bffffe                 bne     loc_F008A628
F008A634: 01000000                 nop
F008A638: 4000321c                 call    _simple_lock_try
F008A63C: 90100010                 mov     %l0, %o0
F008A640: 80a22000                 cmp     %o0, 0
F008A644: 02bffff9                 be      loc_F008A628
F008A648: 173c04f6                 sethi   %hi(_gc_active), %o3
F008A64C: d002e188                 ld      [%o3+%lo(_gc_active)], %o0
F008A650: 80a22000                 cmp     %o0, 0
F008A654: 1280002a                 bne     loc_F008A6FC
F008A658: 113c04f6                 sethi   %hi(_gc_lock), %o0
F008A65C: c0222190                 clr     [%o0+%lo(_gc_lock)]
F008A660: 92102001                 mov     1, %o1
F008A664: d4044000                 ld      [%l1], %o2
F008A668: d222e188                 st      %o1, [%o3+%lo(_gc_active)]
F008A66C: 808aa001                 btst    1, %o2
F008A670: 0280000c                 be      loc_F008A6A0
F008A674: a0122190                 or      %o0, %lo(_gc_lock), %l0
F008A678: 7fff8933                 call    _mfs_cache_clear
F008A67C: 01000000                 nop
F008A680: 7ffff3cc                 call    _vm_object_cache_clear
F008A684: 01000000                 nop
F008A688: 7fff0d2e                 call    _inode_cache_clear
F008A68C: 01000000                 nop
F008A690: 7ffec979                 call    _rnode_cache_clear
F008A694: 01000000                 nop
F008A698: 7ffe0fba                 call    _proc_cache_clear
F008A69C: 01000000                 nop
F008A6A0: d0044000                 ld      [%l1], %o0
F008A6A4: 808a2002                 btst    2, %o0
F008A6A8: 02800006                 be      loc_F008A6C0
F008A6AC: 808a2004                 btst    4, %o0
F008A6B0: 7fffbb34                 call    _zone_gc
F008A6B4: 01000000                 nop
F008A6B8: d0044000                 ld      [%l1], %o0
F008A6BC: 808a2004                 btst    4, %o0
F008A6C0: 02800004                 be      loc_F008A6D0
F008A6C4: 01000000                 nop
F008A6C8: 7fffbba9                 call    _zone_reclaim
F008A6CC: 01000000                 nop
F008A6D0: d0040000                 ld      [%l0], %o0
F008A6D4: 80a22000                 cmp     %o0, 0
F008A6D8: 12bffffe                 bne     loc_F008A6D0
F008A6DC: 01000000                 nop
F008A6E0: 400031f2                 call    _simple_lock_try
F008A6E4: 90100010                 mov     %l0, %o0
F008A6E8: 80a22000                 cmp     %o0, 0
F008A6EC: 02bffff9                 be      loc_F008A6D0
F008A6F0: 113c04f6                 sethi   %hi(_gc_active), %o0
F008A6F4: c0222188                 clr     [%o0+%lo(_gc_active)]
F008A6F8: 113c04f6                 sethi   -0xFEC2800, %o0
F008A6FC: c0222190                 clr     [%o0+0x190]
F008A700: 81c7e008                 ret
F008A704: 81e80000                 restore
