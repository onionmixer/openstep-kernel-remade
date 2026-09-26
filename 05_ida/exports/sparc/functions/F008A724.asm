F008A724: 9de3bf98                 save    %sp, -0x68, %sp
F008A728: 80a62000                 cmp     %i0, 0
F008A72C: 12800004                 bne     loc_F008A73C
F008A730: 153c04d0                 sethi   -0xFECC000, %o2
F008A734: 10800039                 ba      locret_F008A818
F008A738: b0102004                 mov     4, %i0
F008A73C: d002a0d8                 ld      [%o2+0xD8], %o0
F008A740: d2064000                 ld      [%i1], %o1
F008A744: 902a4008                 andn    %o1, %o0, %o0
F008A748: d0264000                 st      %o0, [%i1]
F008A74C: 113c04f0                 sethi   %hi(_vm_alloc_lock), %o0
F008A750: d402a0d8                 ld      [%o2+0xD8], %o2
F008A754: 90122200                 bset    %lo(_vm_alloc_lock), %o0
F008A758: 9206800a                 add     %i2, %o2, %o1
F008A75C: 7fff799a                 call    _lock_write
F008A760: b42a400a                 andn    %o1, %o2, %i2
F008A764: 7ffff2fd                 call    _vm_object_lookup
F008A768: 9010001c                 mov     %i4, %o0
F008A76C: a0100008                 mov     %o0, %l0
F008A770: 113c04f092122240         set     _vm_stat, %o1
F008A778: d002602c                 ld      [%o1+0x2C], %o0
F008A77C: 80a42000                 cmp     %l0, 0
F008A780: 90022001                 inc     %o0
F008A784: 12800010                 bne     loc_F008A7C4
F008A788: d022602c                 st      %o0, [%o1+0x2C]
F008A78C: 7ffff005                 call    _vm_object_allocate
F008A790: 9010001a                 mov     %i2, %o0
F008A794: 80a72000                 cmp     %i4, 0
F008A798: 0280000e                 be      loc_F008A7D0
F008A79C: a0100008                 mov     %o0, %l0
F008A7A0: 9210001c                 mov     %i4, %o1
F008A7A4: 94102000                 mov     0, %o2
F008A7A8: 7ffff2dc                 call    _vm_object_setpager
F008A7AC: 96102001                 mov     1, %o3
F008A7B0: 90100010                 mov     %l0, %o0
F008A7B4: 7ffff332                 call    _vm_object_enter
F008A7B8: 9210001c                 mov     %i4, %o1
F008A7BC: 10800006                 ba      loc_F008A7D4
F008A7C0: 113c04f0                 sethi   -0xFEC4000, %o0
F008A7C4: d0026030                 ld      [%o1+0x30], %o0
F008A7C8: 90022001                 inc     %o0
F008A7CC: d0226030                 st      %o0, [%o1+0x30]
F008A7D0: 113c04f0                 sethi   -0xFEC4000, %o0
F008A7D4: 7fff7a18                 call    _lock_done
F008A7D8: 90122200                 bset    0x200, %o0
F008A7DC: 90100018                 mov     %i0, %o0
F008A7E0: 92100010                 mov     %l0, %o1
F008A7E4: 9410001d                 mov     %i5, %o2
F008A7E8: d8042044                 ld      [%l0+0x44], %o4
F008A7EC: 96100019                 mov     %i1, %o3
F008A7F0: 9a10001b                 mov     %i3, %o5
F008A7F4: 980b37ff                 and     %o4, -0x801, %o4
F008A7F8: d8242044                 st      %o4, [%l0+0x44]
F008A7FC: 7fffe775                 call    _vm_map_find
F008A800: 9810001a                 mov     %i2, %o4
F008A804: b0920000                 orcc    %o0, %g0, %i0
F008A808: 02800004                 be      locret_F008A818
F008A80C: 01000000                 nop
F008A810: 7ffff02a                 call    _vm_object_deallocate
F008A814: 90100010                 mov     %l0, %o0
F008A818: 81c7e008                 ret
F008A81C: 81e80000                 restore
