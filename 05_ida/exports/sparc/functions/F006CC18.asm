F006CC18: 9de3bf98                 save    %sp, -0x68, %sp
F006CC1C: 80a6e000                 cmp     %i3, 0
F006CC20: 22800005                 be,a    loc_F006CC34
F006CC24: 113c04f0                 sethi   -0xFEC4000, %o0
F006CC28: 40000276                 call    _vmp_push
F006CC2C: 90100018                 mov     %i0, %o0
F006CC30: 113c04f0                 sethi   -0xFEC4000, %o0
F006CC34: b61221c0                 or      %o0, 0x1C0, %i3
F006CC38: 7ffff063                 call    _lock_write
F006CC3C: 9010001b                 mov     %i3, %o0
F006CC40: 92100019                 mov     %i1, %o1
F006CC44: 9410001a                 mov     %i2, %o2
F006CC48: 173c04f0                 sethi   %hi(_mfs_map), %o3
F006CC4C: d002e1d8                 ld      [%o3+%lo(_mfs_map)], %o0
F006CC50: 400061bc                 call    _vm_map_remove
F006CC54: b212e1d8                 or      %o3, %lo(_mfs_map), %i1
F006CC58: 133c04f0                 sethi   %hi(_mfs_alloc_wanted), %o1
F006CC5C: d00261d0                 ld      [%o1+%lo(_mfs_alloc_wanted)], %o0
F006CC60: 80a22000                 cmp     %o0, 0
F006CC64: 02800006                 be      loc_F006CC7C
F006CC68: 90100019                 mov     %i1, %o0
F006CC6C: c02261d0                 clr     [%o1+%lo(_mfs_alloc_wanted)]
F006CC70: 92102000                 mov     0, %o1
F006CC74: 400010e2                 call    _thread_wakeup_prim
F006CC78: 94102000                 mov     0, %o2
F006CC7C: 7ffff0ee                 call    _lock_done
F006CC80: 9010001b                 mov     %i3, %o0
F006CC84: f0062024                 ld      [%i0+0x24], %i0
F006CC88: 80a62000                 cmp     %i0, 0
F006CC8C: 0280000e                 be      locret_F006CCC4
F006CC90: b2062010                 add     %i0, 0x10, %i1
F006CC94: d0064000                 ld      [%i1], %o0
F006CC98: 80a22000                 cmp     %o0, 0
F006CC9C: 12bffffe                 bne     loc_F006CC94
F006CCA0: 01000000                 nop
F006CCA4: 4000a881                 call    _simple_lock_try
F006CCA8: 90100019                 mov     %i1, %o0
F006CCAC: 80a22000                 cmp     %o0, 0
F006CCB0: 02bffff9                 be      loc_F006CC94
F006CCB4: 01000000                 nop
F006CCB8: 40006816                 call    _vm_object_deactivate_pages
F006CCBC: 90100018                 mov     %i0, %o0
F006CCC0: c0262010                 clr     [%i0+0x10]
F006CCC4: 81c7e008                 ret
F006CCC8: 81e80000                 restore
