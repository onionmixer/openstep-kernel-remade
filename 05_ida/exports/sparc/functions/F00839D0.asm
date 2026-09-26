F00839D0: 9de3bf90                 save    %sp, -0x70, %sp
F00839D4: a2100018                 mov     %i0, %l1
F00839D8: 113c04d0                 sethi   %hi(_page_mask), %o0
F00839DC: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F00839E0: 213c04f4                 sethi   %hi(_vm_submap_object), %l0
F00839E4: b606c009                 add     %i3, %o1, %i3
F00839E8: d0042350                 ld      [%l0+%lo(_vm_submap_object)], %o0
F00839EC: 40000ba0                 call    _vm_object_reference
F00839F0: b62ec009                 bclr    %o1, %i3
F00839F4: 90100011                 mov     %l1, %o0
F00839F8: 94102000                 mov     0, %o2
F00839FC: 9607bff4                 add     %fp, var_C, %o3
F0083A00: d8046014                 ld      [%l1+0x14], %o4
F0083A04: 9a102001                 mov     1, %o5
F0083A08: d2042350                 ld      [%l0+%lo(_vm_submap_object)], %o1
F0083A0C: d827bff4                 st      %o4, [%fp+var_C]
F0083A10: 400002f0                 call    _vm_map_find
F0083A14: 9810001b                 mov     %i3, %o4
F0083A18: 80a22000                 cmp     %o0, 0
F0083A1C: 02800004                 be      loc_F0083A2C
F0083A20: 113c0446                 sethi   %hi(aKmemSuballoc1), %o0! "kmem_suballoc 1"
F0083A24: 7ffe45d3                 call    _panic
F0083A28: 901221c0                 bset    %lo(aKmemSuballoc1), %o0! "kmem_suballoc 1"
F0083A2C: 400063c7                 call    _pmap_reference
F0083A30: d0046024                 ld      [%l1+0x24], %o0
F0083A34: d207bff4                 ld      [%fp+var_C], %o1
F0083A38: 9610001c                 mov     %i4, %o3
F0083A3C: d0046024                 ld      [%l1+0x24], %o0
F0083A40: 4000019c                 call    _vm_map_create
F0083A44: 9402401b                 add     %o1, %i3, %o2
F0083A48: b0920000                 orcc    %o0, %g0, %i0
F0083A4C: 32800006                 bne,a   loc_F0083A64
F0083A50: 90100011                 mov     %l1, %o0
F0083A54: 113c0446                 sethi   %hi(aKmemSuballoc2), %o0! "kmem_suballoc 2"
F0083A58: 7ffe45c6                 call    _panic
F0083A5C: 901221d0                 bset    %lo(aKmemSuballoc2), %o0! "kmem_suballoc 2"
F0083A60: 90100011                 mov     %l1, %o0
F0083A64: d207bff4                 ld      [%fp+var_C], %o1
F0083A68: 96100018                 mov     %i0, %o3
F0083A6C: 40000397                 call    _vm_map_submap
F0083A70: 9402401b                 add     %o1, %i3, %o2
F0083A74: 80a22000                 cmp     %o0, 0
F0083A78: 02800004                 be      loc_F0083A88
F0083A7C: 113c0446                 sethi   %hi(aKmemSuballoc3), %o0! "kmem_suballoc 3"
F0083A80: 7ffe45bc                 call    _panic
F0083A84: 901221e0                 bset    %lo(aKmemSuballoc3), %o0! "kmem_suballoc 3"
F0083A88: d007bff4                 ld      [%fp+var_C], %o0
F0083A8C: d0264000                 st      %o0, [%i1]
F0083A90: d007bff4                 ld      [%fp+var_C], %o0
F0083A94: 9002001b                 add     %o0, %i3, %o0
F0083A98: d0268000                 st      %o0, [%i2]
F0083A9C: 81c7e008                 ret
F0083AA0: 81e80000                 restore
