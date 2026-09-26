F006A78C: 9de3bf78                 save    %sp, -0x88, %sp
F006A790: 253c04d0                 sethi   %hi(_active_threads), %l2
F006A794: d004a260                 ld      [%l2+%lo(_active_threads)], %o0
F006A798: d002200c                 ld      [%o0+0xC], %o0
F006A79C: e202200c                 ld      [%o0+0xC], %l1
F006A7A0: e0046024                 ld      [%l1+0x24], %l0
F006A7A4: 4000c869                 call    _pmap_reference
F006A7A8: 90100010                 mov     %l0, %o0
F006A7AC: d2046014                 ld      [%l1+0x14], %o1
F006A7B0: d4046018                 ld      [%l1+0x18], %o2! __len
F006A7B4: d6046020                 ld      [%l1+0x20], %o3
F006A7B8: 4000663e                 call    _vm_map_create
F006A7BC: 90100010                 mov     %l0, %o0
F006A7C0: 80a72000                 cmp     %i4, 0
F006A7C4: 12800003                 bne     loc_F006A7D0
F006A7C8: a0100008                 mov     %o0, %l0
F006A7CC: b807bfe0                 add     %fp, var_20, %i4
F006A7D0: 9010001c                 mov     %i4, %o0! __b
F006A7D4: 92102000                 mov     0, %o1! __c
F006A7D8: 7ffe6ee9                 call    _memset
F006A7DC: 94102014                 mov     0x14, %o2
F006A7E0: c0270000                 clr     [%i4]
F006A7E4: c023a05c                 clr     [%sp+0x88+var_2C]
F006A7E8: f823a060                 st      %i4, [%sp+0x88+var_28]
F006A7EC: 90100018                 mov     %i0, %o0
F006A7F0: 92100010                 mov     %l0, %o1
F006A7F4: 94100019                 mov     %i1, %o2
F006A7F8: 9610001a                 mov     %i2, %o3
F006A7FC: 9810001b                 mov     %i3, %o4
F006A800: 4000000f                 call    sub_F006A83C
F006A804: 9a102000                 mov     0, %o5
F006A808: b0920000                 orcc    %o0, %g0, %i0
F006A80C: 12800008                 bne     loc_F006A82C
F006A810: d004a260                 ld      [%l2+0x260], %o0
F006A814: d202200c                 ld      [%o0+0xC], %o1
F006A818: 90100011                 mov     %l1, %o0
F006A81C: 4000667c                 call    _vm_map_deallocate
F006A820: e022600c                 st      %l0, [%o1+0xC]
F006A824: 10800004                 ba      locret_F006A834
F006A828: b0102000                 mov     0, %i0
F006A82C: 40006678                 call    _vm_map_deallocate
F006A830: 90100010                 mov     %l0, %o0
F006A834: 81c7e008                 ret
F006A838: 81e80000                 restore
