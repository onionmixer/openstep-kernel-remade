F00834B0: 9de3bf98                 save    %sp, -0x68, %sp
F00834B4: 253c04f4                 sethi   %hi(_num_regions), %l2
F00834B8: 233c04f3a2146030         set     _mem_region, %l1
F00834C0: d204a330                 ld      [%l2+%lo(_num_regions)], %o1
F00834C4: 213c04f0                 sethi   %hi(_virtual_avail), %l0
F00834C8: d4042110                 ld      [%l0+%lo(_virtual_avail)], %o2
F00834CC: 4000150d                 call    _vm_page_startup
F00834D0: 90100011                 mov     %l1, %o0
F00834D4: 7fffd599                 call    _zone_bootstrap
F00834D8: d0242110                 st      %o0, [%l0+%lo(_virtual_avail)]
F00834DC: 40000c48                 call    _vm_object_init
F00834E0: 01000000                 nop
F00834E4: 400002c4                 call    _vm_map_init
F00834E8: 01000000                 nop
F00834EC: d0042110                 ld      [%l0+%lo(_virtual_avail)], %o0
F00834F0: 133c04f4                 sethi   %hi(_virtual_end), %o1
F00834F4: 4000016c                 call    _kmem_init
F00834F8: d2026338                 ld      [%o1+%lo(_virtual_end)], %o1
F00834FC: d204a330                 ld      [%l2+0x330], %o1
F0083500: 40006482                 call    _pmap_init
F0083504: 90100011                 mov     %l1, %o0
F0083508: 7fffd5ba                 call    _zone_init
F008350C: 01000000                 nop
F0083510: 7fff9288                 call    _kalloc_init
F0083514: 01000000                 nop
F0083518: 4000132d                 call    _vm_pager_init
F008351C: 01000000                 nop
F0083520: 40001c7a                 call    _vm_user_init
F0083524: 01000000                 nop
F0083528: 81c7e008                 ret
F008352C: 81e80000                 restore
