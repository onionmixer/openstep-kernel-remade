F00BF0E4: 9de3bf98                 save    %sp, -0x68, %sp
F00BF0E8: 80a66000                 cmp     %i1, 0
F00BF0EC: 12800004                 bne     loc_F00BF0FC
F00BF0F0: 113c04d0                 sethi   -0xFECC000, %o0
F00BF0F4: 10800026                 ba      locret_F00BF18C
F00BF0F8: b0102004                 mov     4, %i0
F00BF0FC: d20220d8                 ld      [%o0+0xD8], %o1
F00BF100: b0102000                 mov     0, %i0
F00BF104: 90068009                 add     %i2, %o1, %o0
F00BF108: a02a0009                 andn    %o0, %o1, %l0
F00BF10C: 80a60010                 cmp     %i0, %l0
F00BF110: 1a80000e                 bcc     loc_F00BF148
F00BF114: 90100019                 mov     %i1, %o0
F00BF118: 353c0447                 sethi   %hi(_page_size), %i2
F00BF11C: d406a13c                 ld      [%i2+%lo(_page_size)], %o2
F00BF120: 9206c018                 add     %i3, %i0, %o1
F00BF124: d0066024                 ld      [%i1+0x24], %o0
F00BF128: 7fff7815                 call    _pmap_remove
F00BF12C: 9402400a                 add     %o1, %o2, %o2
F00BF130: d006a13c                 ld      [%i2+0x13C], %o0
F00BF134: b0060008                 add     %i0, %o0, %i0
F00BF138: 80a60010                 cmp     %i0, %l0
F00BF13C: 0abffff9                 bcs     loc_F00BF120
F00BF140: d406a13c                 ld      [%i2+0x13C], %o2
F00BF144: 90100019                 mov     %i1, %o0
F00BF148: 9210001b                 mov     %i3, %o1
F00BF14C: 7fff187d                 call    _vm_map_remove
F00BF150: 94024010                 add     %o1, %l0, %o2
F00BF154: b0920000                 orcc    %o0, %g0, %i0
F00BF158: 22800007                 be,a    loc_F00BF174
F00BF15C: 113c04d1                 sethi   -0xFECBC00, %o0
F00BF160: 113c0482901222b8         set     aDestroyeventsh, %o0! "destroyEventShmem: vm_map_remove() retu"...
F00BF168: 7ffd553c                 call    _printf
F00BF16C: 92100018                 mov     %i0, %o1
F00BF170: 113c04d1                 sethi   -0xFECBC00, %o0
F00BF174: d0022340                 ld      [%o0+0x340], %o0
F00BF178: 9210001c                 mov     %i4, %o1
F00BF17C: 7fff11c2                 call    _kmem_free
F00BF180: 94100010                 mov     %l0, %o2
F00BF184: 7fff1422                 call    _vm_map_deallocate
F00BF188: 90100019                 mov     %i1, %o0
F00BF18C: 81c7e008                 ret
F00BF190: 81e80000                 restore
