F00868B8: 9de3bf98                 save    %sp, -0x68, %sp
F00868BC: 80a62000                 cmp     %i0, 0
F00868C0: 02800048                 be      locret_F00869E0
F00868C4: 273c04f5                 sethi   %hi(_vm_cache_lock), %l3
F00868C8: a214e000                 or      %l3, %lo(_vm_cache_lock), %l1
F00868CC: 293c04f5aa15201c         set     unk_F013D41C, %l5
F00868D4: a4057ffc                 add     %l5, -4, %l2
F00868D8: 2d3c04f5                 sethi   -0xFEC2C00, %l6
F00868DC: 113ffffbae1223ff         set     -0x1001, %l7
F00868E4: d0044000                 ld      [%l1], %o0
F00868E8: 80a22000                 cmp     %o0, 0
F00868EC: 12bffffe                 bne     loc_F00868E4
F00868F0: 01000000                 nop
F00868F4: 4000416d                 call    _simple_lock_try
F00868F8: 90100011                 mov     %l1, %o0
F00868FC: 80a22000                 cmp     %o0, 0
F0086900: 02bffff9                 be      loc_F00868E4
F0086904: a0062010                 add     %i0, 0x10, %l0
F0086908: d0040000                 ld      [%l0], %o0
F008690C: 80a22000                 cmp     %o0, 0
F0086910: 12bffffe                 bne     loc_F0086908
F0086914: 01000000                 nop
F0086918: 40004164                 call    _simple_lock_try
F008691C: 90100010                 mov     %l0, %o0
F0086920: 80a22000                 cmp     %o0, 0
F0086924: 02bffff9                 be      loc_F0086908
F0086928: 01000000                 nop
F008692C: d0162018                 lduh    [%i0+0x18], %o0
F0086930: 90023fff                 inc     -1, %o0
F0086934: d0362018                 sth     %o0, [%i0+0x18]
F0086938: 912a2010                 sll     %o0, 16, %o0
F008693C: 80a22000                 cmp     %o0, 0
F0086940: 22800005                 be,a    loc_F0086954
F0086944: d2062044                 ld      [%i0+0x44], %o1
F0086948: c0262010                 clr     [%i0+0x10]
F008694C: c024e000                 clr     [%l3]
F0086950: 30800024                 ba,a    locret_F00869E0
F0086954: 11000004                 sethi   0x1000, %o0
F0086958: 808a4008                 btst    %o0, %o1
F008695C: 02800018                 be      loc_F00869BC
F0086960: 01000000                 nop
F0086964: d056201a                 ldsh    [%i0+0x1A], %o0
F0086968: 80a22000                 cmp     %o0, 0
F008696C: 04800013                 ble     loc_F00869B8
F0086970: 900a4017                 and     %o1, %l7, %o0
F0086974: d005201c                 ld      [%l4+0x1C], %o0
F0086978: 80a20012                 cmp     %o0, %l2
F008697C: 32800003                 bne,a   loc_F0086988
F0086980: f022204c                 st      %i0, [%o0+0x4C]
F0086984: f0257ffc                 st      %i0, [%l5-4]
F0086988: d0262050                 st      %o0, [%i0+0x50]
F008698C: e426204c                 st      %l2, [%i0+0x4C]
F0086990: f024a004                 st      %i0, [%l2+4]
F0086994: d005a010                 ld      [%l6+0x10], %o0
F0086998: 90022001                 inc     %o0
F008699C: d025a010                 st      %o0, [%l6+0x10]
F00869A0: c024e000                 clr     [%l3]
F00869A4: 400000db                 call    _vm_object_deactivate_pages
F00869A8: 90100018                 mov     %i0, %o0
F00869AC: c0262010                 clr     [%i0+0x10]
F00869B0: 400000f6                 call    _vm_object_cache_trim
F00869B4: 9e03e028                 inc     0x28, %o7 ! '('
F00869B8: d0262044                 st      %o0, [%i0+0x44]
F00869BC: 400002da                 call    _vm_object_remove
F00869C0: d0062028                 ld      [%i0+0x28], %o0
F00869C4: c024e000                 clr     [%l3]
F00869C8: e0062020                 ld      [%i0+0x20], %l0
F00869CC: 40000007                 call    _vm_object_terminate
F00869D0: 90100018                 mov     %i0, %o0
F00869D4: b0940000                 orcc    %l0, %g0, %i0
F00869D8: 12bfffc3                 bne     loc_F00868E4
F00869DC: 01000000                 nop
F00869E0: 81c7e008                 ret
F00869E4: 81e80000                 restore
