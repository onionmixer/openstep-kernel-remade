F00836C8: 9de3bf88                 save    %sp, -0x78, %sp
F00836CC: a2100018                 mov     %i0, %l1
F00836D0: 90100011                 mov     %l1, %o0
F00836D4: 92102000                 mov     0, %o1
F00836D8: 173c04d0                 sethi   %hi(_page_mask), %o3
F00836DC: da02e0d8                 ld      [%o3+%lo(_page_mask)], %o5
F00836E0: 94102000                 mov     0, %o2
F00836E4: 9607bff4                 add     %fp, var_C, %o3
F00836E8: 9838000d                 xnor    %g0, %o5, %o4
F00836EC: a00e400c                 and     %i1, %o4, %l0
F00836F0: b206401a                 add     %i1, %i2, %i1
F00836F4: b206400d                 add     %i1, %o5, %i1
F00836F8: b20e400c                 and     %i1, %o4, %i1
F00836FC: b2264010                 sub     %i1, %l0, %i1
F0083700: b807000d                 add     %i4, %o5, %i4
F0083704: b80f000c                 and     %i4, %o4, %i4
F0083708: 9810001c                 mov     %i4, %o4
F008370C: 400003b1                 call    _vm_map_find
F0083710: 9a102001                 mov     1, %o5
F0083714: 80a00008                 cmp     %g0, %o0
F0083718: b0402000                 addc    %g0, 0, %i0
F008371C: 80a62000                 cmp     %i0, 0
F0083720: 12800037                 bne     locret_F00837FC
F0083724: 90100011                 mov     %l1, %o0
F0083728: d207bff4                 ld      [%fp+var_C], %o1
F008372C: 4000035f                 call    _vm_map_lookup_entry
F0083730: 9407bff0                 add     %fp, var_10, %o2
F0083734: 90100011                 mov     %l1, %o0
F0083738: 92100010                 mov     %l0, %o1
F008373C: 4000035b                 call    _vm_map_lookup_entry
F0083740: 9407bfec                 add     %fp, var_14, %o2
F0083744: 80a22000                 cmp     %o0, 0
F0083748: 32800006                 bne,a   loc_F0083760
F008374C: d007bfec                 ld      [%fp+var_14], %o0
F0083750: 113c0446                 sethi   %hi(aKmemRealloc), %o0! "kmem_realloc"
F0083754: 7ffe4687                 call    _panic
F0083758: 901221a0                 bset    %lo(aKmemRealloc), %o0! "kmem_realloc"
F008375C: d007bfec                 ld      [%fp+var_14], %o0
F0083760: e0022010                 ld      [%o0+0x10], %l0
F0083764: 40000c42                 call    _vm_object_reference
F0083768: 90100010                 mov     %l0, %o0
F008376C: b4042010                 add     %l0, 0x10, %i2
F0083770: d0068000                 ld      [%i2], %o0
F0083774: 80a22000                 cmp     %o0, 0
F0083778: 12bffffe                 bne     loc_F0083770
F008377C: 01000000                 nop
F0083780: 40004dca                 call    _simple_lock_try
F0083784: 9010001a                 mov     %i2, %o0
F0083788: 80a22000                 cmp     %o0, 0
F008378C: 02bffff9                 be      loc_F0083770
F0083790: 01000000                 nop
F0083794: d0042014                 ld      [%l0+0x14], %o0
F0083798: 80a20019                 cmp     %o0, %i1
F008379C: 02800004                 be      loc_F00837AC
F00837A0: 113c0446                 sethi   %hi(aKmemRealloc_0), %o0! "kmem_realloc"
F00837A4: 7ffe4673                 call    _panic
F00837A8: 901221b0                 bset    %lo(aKmemRealloc_0), %o0! "kmem_realloc"
F00837AC: f8242014                 st      %i4, [%l0+0x14]
F00837B0: c0242010                 clr     [%l0+0x10]
F00837B4: d207bff0                 ld      [%fp+var_10], %o1
F00837B8: 90100011                 mov     %l1, %o0
F00837BC: e0226010                 st      %l0, [%o1+0x10]
F00837C0: 7fff961d                 call    _lock_done
F00837C4: c0226014                 clr     [%o1+0x14]
F00837C8: 90100010                 mov     %l0, %o0
F00837CC: 92100019                 mov     %i1, %o1
F00837D0: 9410001c                 mov     %i4, %o2
F00837D4: 40000038                 call    sub_F00838B4
F00837D8: 96102001                 mov     1, %o3
F00837DC: 90100011                 mov     %l1, %o0
F00837E0: d207bff4                 ld      [%fp+var_C], %o1
F00837E4: 96102000                 mov     0, %o3
F00837E8: 40000581                 call    _vm_map_pageable
F00837EC: 9402401c                 add     %o1, %i4, %o2
F00837F0: d007bff4                 ld      [%fp+var_C], %o0
F00837F4: b0102000                 mov     0, %i0
F00837F8: d026c000                 st      %o0, [%i3]
F00837FC: 81c7e008                 ret
F0083800: 81e80000                 restore
