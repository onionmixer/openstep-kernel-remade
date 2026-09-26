F0090E14: 9de3bf98                 save    %sp, -0x68, %sp
F0090E18: f206600c                 ld      [%i1+0xC], %i1
F0090E1C: 80a66000                 cmp     %i1, 0
F0090E20: 12800004                 bne     loc_F0090E30
F0090E24: 113c04d0                 sethi   -0xFECC000, %o0
F0090E28: 1080001d                 ba      locret_F0090E9C
F0090E2C: b0103d38                 mov     -0x2C8, %i0
F0090E30: d20220d8                 ld      [%o0+0xD8], %o1
F0090E34: b0102000                 mov     0, %i0
F0090E38: 90068009                 add     %i2, %o1, %o0
F0090E3C: b42a0009                 andn    %o0, %o1, %i2
F0090E40: 80a6001a                 cmp     %i0, %i2
F0090E44: 1a80000d                 bcc     loc_F0090E78
F0090E48: d206c000                 ld      [%i3], %o1
F0090E4C: 213c0447                 sethi   -0xFEEE400, %l0
F0090E50: d0066024                 ld      [%i1+0x24], %o0
F0090E54: d404213c                 ld      [%l0+0x13C], %o2
F0090E58: 92024018                 add     %o1, %i0, %o1
F0090E5C: 400030c8                 call    _pmap_remove
F0090E60: 9402400a                 add     %o1, %o2, %o2
F0090E64: d004213c                 ld      [%l0+0x13C], %o0
F0090E68: b0060008                 add     %i0, %o0, %i0
F0090E6C: 80a6001a                 cmp     %i0, %i2
F0090E70: 0abffff8                 bcs     loc_F0090E50
F0090E74: d206c000                 ld      [%i3], %o1
F0090E78: 90100019                 mov     %i1, %o0
F0090E7C: 7fffd131                 call    _vm_map_remove
F0090E80: 9402401a                 add     %o1, %i2, %o2
F0090E84: b0920000                 orcc    %o0, %g0, %i0
F0090E88: 02800005                 be      locret_F0090E9C
F0090E8C: 113c0448                 sethi   %hi(aIounmaplockshm), %o0! "IOUnMapLockShmem: vm_map_remove() retur"...
F0090E90: 90122200                 bset    %lo(aIounmaplockshm), %o0! "IOUnMapLockShmem: vm_map_remove() retur"...
F0090E94: 4000d498                 call    _IOLog
F0090E98: 92100018                 mov     %i0, %o1
F0090E9C: 81c7e008                 ret
F0090EA0: 81e80000                 restore
