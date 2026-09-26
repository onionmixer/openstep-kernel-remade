F009C7C0: 9de3bf90                 save    %sp, -0x70, %sp
F009C7C4: 133c04f792126270         set     _pmap_info, %o1! size_t
F009C7CC: d002603c                 ld      [%o1+0x3C], %o0
F009C7D0: 80a62000                 cmp     %i0, 0
F009C7D4: 90022001                 inc     %o0
F009C7D8: 02800004                 be      loc_F009C7E8
F009C7DC: d022603c                 st      %o0, [%o1+0x3C]
F009C7E0: 1080002d                 ba      locret_F009C894
F009C7E4: b0102000                 mov     0, %i0
F009C7E8: 113c04f7                 sethi   %hi(_pmap_zone), %o0
F009C7EC: 7fff7238                 call    _zalloc
F009C7F0: d0022378                 ld      [%o0+%lo(_pmap_zone)], %o0
F009C7F4: b0920000                 orcc    %o0, %g0, %i0
F009C7F8: 32800006                 bne,a   loc_F009C810
F009C7FC: 90100018                 mov     %i0, %o0
F009C800: 113c045e                 sethi   %hi(aPmapCreatePmap), %o0! "pmap_create: pmap null"
F009C804: 7ffde25b                 call    _panic
F009C808: 901223a8                 bset    %lo(aPmapCreatePmap), %o0! "pmap_create: pmap null"
F009C80C: 90100018                 mov     %i0, %o0! void *
F009C810: 7fffe192                 call    _bzero
F009C814: 92102028                 mov     0x28, %o1 ! '('
F009C818: 90102fff                 mov     0xFFF, %o0
F009C81C: d0262010                 st      %o0, [%i0+0x10]
F009C820: d026200c                 st      %o0, [%i0+0xC]
F009C824: 4000160f                 call    _pmap_alloc_reg_entry
F009C828: 90100018                 mov     %i0, %o0
F009C82C: 210003c0                 sethi   0xF0000, %l0
F009C830: 29000004                 sethi   0x1000, %l4
F009C834: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F009C838: e4060000                 ld      [%i0], %l2
F009C83C: 130003ff                 sethi   0xFFC00, %o1
F009C840: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F009C844: a61263ff                 or      %o1, 0x3FF, %l3
F009C848: e2020000                 ld      [%o0], %l1
F009C84C: 932c200c                 sll     %l0, 12, %o1
F009C850: d227bff4                 st      %o1, [%fp+var_C]
F009C854: d40fbff4                 ldub    [%fp+var_C], %o2
F009C858: 90100012                 mov     %l2, %o0
F009C85C: d6044000                 ld      [%l1], %o3
F009C860: 952aa002                 sll     %o2, 2, %o2
F009C864: d402c00a                 ld      [%o3+%o2], %o2
F009C868: a0040014                 add     %l0, %l4, %l0
F009C86C: 9532a002                 srl     %o2, 2, %o2
F009C870: 400014a5                 call    _set_ptp
F009C874: 952aa006                 sll     %o2, 6, %o2
F009C878: 80a40013                 cmp     %l0, %l3
F009C87C: 08bffff5                 bleu    loc_F009C850
F009C880: 932c200c                 sll     %l0, 12, %o1
F009C884: c0262018                 clr     [%i0+0x18]
F009C888: c0262014                 clr     [%i0+0x14]
F009C88C: 90102001                 mov     1, %o0
F009C890: d026201c                 st      %o0, [%i0+0x1C]
F009C894: 81c7e008                 ret
F009C898: 81e80000                 restore
